#pragma once

#include "ofMain.h"
#define VOICES 6

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);

		ofSoundPlayer voicePlayer[VOICES];
		bool voicePaused[VOICES];
		float playingSpeed;
		float pan;
		
};
