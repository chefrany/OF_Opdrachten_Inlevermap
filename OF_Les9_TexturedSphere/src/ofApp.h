#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    ofLight light;
	ofLight light2;
	ofLight areaLight;
    ofEasyCam cam;
    ofImage image;

};
