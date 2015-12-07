#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

        float x;
        float y;
        float speedY;
        float speedX;
        int radius;

		float x2;
        float y2;
        float speedY2;
        float speedX2;
        int radius2;

		float x3;
        float y3;
        float speedY3;
        float speedX3;
        int radius3;

        ofColor color;
		ofColor color2;
		ofColor color3;
		
};
