#pragma once

#include "ofMain.h"

class Ball {

public:

    Ball();

    void setup();
    void update();
    void draw();

    // variables
    float x;
    float y;
	float xbuffered;
    float speedY;
    float speedX;
	float edgeDistance;
    int radius;
    ofColor color;
private:

};