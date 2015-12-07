#include "ofApp.h"

void ofApp::setup() {
	ofBackground(ofColor::black);
    grabber.setDeviceID(0);
    grabber.initGrabber(CAM_WIDTH, CAM_HEIGHT);
    grabber.setDesiredFrameRate(30);

    workspace.allocate(CAM_WIDTH, CAM_HEIGHT, OF_IMAGE_COLOR);
}

void ofApp::update() {
    grabber.update();

    if (grabber.isFrameNew()) {
        ofPixels pixels = grabber.getPixelsRef();

        for (int y=0; y<pixels.getHeight(); y++) {
            for (int x=0; x<pixels.getWidth(); x++) {
                ofColor col = pixels.getColor( x, y );

		col.r = 255 - col.r;
		col.g = 155 - col.g;
		col.b = 255 - col.b;

                workspace.setColor( x, y, col );
            }
        }

        image.setFromPixels( workspace );
        image.mirror(false,true);
    }
}

void ofApp::draw() {
    ofSetColor(255, 255, 255);

    grabber.draw(0, 0);
    image.draw(CAM_WIDTH, 0);
	image.draw(CAM_WIDTH*3, 0);
	image.draw(CAM_WIDTH*2, CAM_HEIGHT);
	image.draw(CAM_WIDTH, CAM_HEIGHT*2);
}
