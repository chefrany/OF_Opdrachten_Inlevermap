#pragma once
#include "ofMain.h"
#include "ofxGui.h"
class ofApp : public ofBaseApp{

	public:
		//voids
		void setup();
		void update();
		void draw();
		void keyPressed(int key);
		void exit();
		void stripePattern();
		void matrixPattern();
		//music
		ofSoundPlayer music;
		bool musicPaused;
		//gui
		ofxPanel gui;  // Main ---> vullen met
		ofxIntSlider countX;
		ofxFloatSlider stepX;
		ofxFloatSlider twistX;

		ofxGuiGroup globalGroup;  //Main ---> vullen met
		ofxFloatSlider Scale;
		ofxFloatSlider Rotate;
		ofxColorSlider Background;
		ofxFloatSlider musicSpeed;

		ofxGuiGroup primGroup; // Main ---> vullen met
		ofxFloatSlider shiftY , rotate;
		ofxVec2Slider size;
		ofxFloatSlider lineWidth;
		ofxColorSlider color;
		ofxToggle filled , type;
		
		ofxIntSlider countY;
		ofxFloatSlider stepY, twistY, pinchY;
	    bool showGui;
		//arduino
		ofSerial serial;
		string str;



};
