#include "Paddle.h"

Paddle::Paddle()
{
	speedY = 5;
	y = ofGetHeight() / 2;
	width = 10;
	height = 150;
	color.set(255, 255, 255);
}

void Paddle::update()
{
	//zorgt dat de paddles altijd aan de rand van het scherm staan
	if (l == LEFT)
		x = edgeDistance;
	else if (l == RIGHT)
		x = ofGetWidth() - edgeDistance;

	//als het scherm te groot of te klein wordt, worden de paddles binnen het scherm gezet
	if (y < (height / 2))
		y = 0;
	else if (y > (ofGetHeight() - (height / 2)))
		y = ofGetHeight() - (height / 2);
}

void Paddle::draw()
{
	ofSetColor(color);
	ofRect(x-(width/2), y-(height/2), width, height);
}

void Paddle::move(Direction d)
{
	if (d == UP)
	{
		if (y - speedY > (height / 2))
			y -= speedY;
	}
	else if (d == DOWN)
	{
		if (y + speedY < (ofGetHeight() - (height / 2)))
			y += speedY;
	}
}