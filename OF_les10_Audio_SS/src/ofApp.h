#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		ofSoundStream soundStream;
		void audioOut(float * output, int bufferSize, int nChannels);
		
		float phase;
		//ofSoundStream soundStream;
};
