#pragma once

#include "ofMain.h"

class Ball {

public:

    Ball();

    void setup();
    void update(ofArduino* arduino);
	void draw(float newSize);
    void setSpeed(float newSpeed);
	//void setSize(float newSize);

    // variables
    float x;
    float y;
    float speedY;
    float speedX;
    int radius;
    ofColor color;

};
