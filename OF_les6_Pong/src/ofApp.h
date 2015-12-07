#pragma once //header files moet je maar één keer door laten spitten, als meerdere cpp files dezelfde includen, dan zeg je de compiler dat er hetzelfde bestand bedoeld wordt.

#include "ofMain.h"

#include "Ball.h"
#include "Paddle.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void collisiondetection();

		void keyPressed(int key);
		void keyReleased(int key);
		

		float edgeDistance;
		bool keyw;
		bool keys;
		bool keyup;
		bool keydown;

		bool player2AI;

		Ball b;
		Paddle player1;
		Paddle player2;
		int score1;
		int score2;
		
		ofTrueTypeFont myfont;

		/*
		0 = Titlescreen
		1 = Game waiting for start
		2 = Ingame
		*/
		int gameMode;

		ofSoundPlayer sndHit;
		ofSoundPlayer sndKill;
};
