#pragma once

#include "ofMain.h"
#define MESH_WIDTH 100
#define MESH_HEIGHT 100
#define MESH_SIZE 10

#define IMAGE_WIDTH 480
#define IMAGE_HEIGHT 300

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		ofMesh mesh;
		ofEasyCam cam;

		ofImage image;
};
