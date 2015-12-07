#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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

		bool drawGrid;

		float rotationX;
		float rotationY;
		float rotationZ;

		int red;
		int green;
		int blue;

		ofxPanel gui;
		ofParameter<float> rotationSpeedX;
		ofParameter<float> rotationSpeedY;
		ofParameter<float> rotationSpeedZ;

		ofParameter<int> rodeKleur;
		ofParameter<int> groeneKleur;
		ofParameter<int> blauweKleur;
		
};
