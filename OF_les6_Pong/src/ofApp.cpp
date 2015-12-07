/* code van Ignaz Kevenaar 
   Ik kwam er zelf echt helemaal niet uit dus heb ik aan ignaz gevraagd of ik zijn code mocht inzien
   Dit is dan ook zijn code en niet de mijne dit omdat ik het uiteindelijk gewoon toch niet zelf kon maken.
   Zelf heb ik de code mininmaal aangepast maar ik snap de code nu wel als ik het lees maar ik kon er nooit zelf op komen. 
*/     
#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	
	gameMode = 1;
	player2AI = true;

	keyw = false;
	keys = false;
	keyup = false;
	keydown = false;

	b.setup();
	b.edgeDistance = 50;

	player1.l = Paddle::LEFT;
	player1.edgeDistance = 50;
	player2.l = Paddle::RIGHT;
	player2.edgeDistance = 50;

	player1.x = edgeDistance;
	player2.x = ofGetWidth() - edgeDistance;

	score1 = 0;
	score2 = 0;
}

//--------------------------------------------------------------
void ofApp::update() {
	if (gameMode > 0)
	{
		//paddles
		if (keyw)
			player1.move(Paddle::Direction::UP);
		else if (keys)
			player1.move(Paddle::Direction::DOWN);
		
		if (!player2AI)
		{
			if (keyup)
				player2.move(Paddle::Direction::UP);
			else if (keydown)
				player2.move(Paddle::Direction::DOWN);
		}
		else
		{
			if (b.y < player2.y)
				player2.move(Paddle::Direction::UP);
			else
				player2.move(Paddle::Direction::DOWN);
		}

		player1.update();
		player2.update();
	}

	if (gameMode == 2)
	{
		//ball
		b.update();

		//collision
		collisiondetection();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (gameMode > 0)
	{
		player1.draw();
		player2.draw();

		myfont.drawString(std::to_string(score1), ((ofGetWidth() / 2) - 150), 50);
		myfont.drawString(std::to_string(score2), ((ofGetWidth() / 2) + 150), 50);

		for (int i = 0; i < ofGetHeight(); i+=20)
		{
			int stripSize = 10;
			ofRect((ofGetWidth() / 2) - (stripSize/2), i, stripSize, stripSize);
		}

	}

	if (gameMode == 2)
		b.draw();
}

void ofApp::collisiondetection()
{
	/*
	these two if statements compare the buffered and the new x coordinate of the ball.
	It checks if the ball has passed the threshold set by the "edgeDistance" variables.
	This way, once the ball has passed your paddle, you can't win anymore.
	*/

	//player1
	if (b.xbuffered - b.radius > player1.edgeDistance + (player1.width / 2) &&
		b.x - b.radius <= player1.edgeDistance + (player1.width / 2)) //x
	{
		if (b.y + b.radius > (player1.y - (player1.height / 2)) && b.y - b.radius < (player1.y + (player1.height / 2))) //y
		{
			//player 1 raak
			//ofBackground(255, 0, 0);
			b.speedX *= -1.25;
			b.speedY *= 1.25;
			if (keyw || keys) b.speedY *= -1; //effectbal!
			sndHit.play();
		}
	}
	//player 2
	else if (b.xbuffered + b.radius < (ofGetWidth() - player2.edgeDistance) - (player2.width / 2) &&
		b.x + b.radius >= (ofGetWidth() - player2.edgeDistance) - (player2.width / 2))
	{
		if (b.y + b.radius > (player2.y - (player2.height / 2)) && b.y - b.radius < (player2.y + (player2.height / 2)))
		{
			//player 2 raak
			//ofBackground(0, 0, 255);
			b.speedX *= -1.25;
			b.speedY *= 1.25;
			if (keyup || keydown) b.speedY *= -1; //effectbal!
			sndHit.play();
		}
	}

	if (b.x - b.radius < 0 ) //player 1 loss
	{
		score2++;
		gameMode = 1;
        //b.x = 0 + b.radius;
        //b.speedX *= -1;
		sndKill.play();
	}
	else if (b.x + b.radius > ofGetWidth()) //player 2 loss
	{
		score1++;
		gameMode = 1.1;
        //b.x = ofGetWidth() - b.radius;
        //b.speedX *= -1;
		sndKill.play();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	
	if (gameMode > 0)
	{
		//player 1
		if (key == 'w')
			keyw = true;
		else if (key == 's')
			keys = true;

		//player2
		if (!player2AI)
		{
			if (key == OF_KEY_UP)
				keyup = true;
			else if (key == OF_KEY_DOWN)
				keydown = true;
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	
	if (gameMode > 0)
	{
		//player 1
		if (key == 'w')
			keyw = false;
		else if (key == 's')
			keys = false;

		//player 2
		if (!player2AI)
		{
			if (key == OF_KEY_UP)
				keyup = false;
			else if (key == OF_KEY_DOWN)
				keydown = false;
		}
	}

	//start spel na gameover
	if (gameMode == 1 && key == OF_KEY_RETURN)
	{
		b.setup();
		b.edgeDistance = 50;
		gameMode = 2;
	}
}

//--------------------------------------------------------------
