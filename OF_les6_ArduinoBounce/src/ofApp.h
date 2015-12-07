#pragma once

#include "ofMain.h"
#include "Ball.h"

#define MAXBALLS 15

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void setupArduino(const int& version);
        void analogPinChanged(const int& pinNum);
		void mousePressed(int x, int y, int button);


    Ball ball;
    ofArduino arduino;
};
