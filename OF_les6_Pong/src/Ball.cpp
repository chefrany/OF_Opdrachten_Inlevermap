#include "Ball.h"
#include "ofApp.h"

Ball::Ball()
{

}

void Ball::setup()
{
    x = ofGetWidth()  / 2;      // give some random positioning
    y = ofGetHeight() / 2;

    speedX = ofRandom(-0.55, 0.55);           // and random speed and direction
    if (speedX < 0.55) speedX = 4.25;
	speedY = ofRandom(-speedX * 1.75, speedX);

    radius = 10;

    //color.set(ofRandom(255),ofRandom(255),ofRandom(255)); // one way of defining digital color is by adddressing its 3 components individually (Red, Green, Blue) in a value from 0-255, in this example we're setting each to a random value
	color.set(255, 255, 255);

}

void Ball::update()
{
	//x is handled in ofApp

    if (y - radius < 0 )
	{
        y = 0 + radius;
        speedY *= -1;
    }
	else if (y + radius > ofGetHeight())
	{
        y = ofGetHeight() - radius;
        speedY *= -1;
    }
	
	xbuffered = x;
    x+=speedX;
    y+=speedY;
}

void Ball::draw()
{
    ofSetColor(color);
    //ofCircle(x, y, radius);
	ofRect(x-radius/2, y-radius/2, radius, radius);
}