#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
    // kies random start coordinaten
    x = ofRandom(0, ofGetWidth());
    y = ofRandom(0, ofGetHeight());

	x2 = ofRandom(0, ofGetWidth());
    y2 = ofRandom(0, ofGetHeight());

	x3 = ofRandom(0, ofGetWidth());
    y3 = ofRandom(0, ofGetHeight());


    // random snelheid
    speedX = ofRandom(-10, 10);
    speedY = ofRandom(-10, 10);

    speedX2 = ofRandom(-20, 20);
    speedY2 = ofRandom(-20, 20);

    speedX3 = ofRandom(-30, 30);
    speedY3 = ofRandom(-30, 30);


    // grootte van cirkel
    radius = 40;
	radius2 = 50;
	radius3 = 60;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
	color2.set(ofRandom(255),ofRandom(255),ofRandom(255));
	color3.set(ofRandom(255),ofRandom(255),ofRandom(255));

	 
}

//--------------------------------------------------------------
void ofApp::update() {

    // links/ rechts tegen de rand aan? keer om!
    if(x < 0 ) {
        x = 0;
        speedX = -speedX;
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX = -speedX;
    }

	if(x2 < 0 ) {
        x2 = 0;
        speedX2 = -speedX2;
    } else if(x2 > ofGetWidth()) {
        x2 = ofGetWidth();
        speedX2 = -speedX2;
    }


	if(x3 < 0 ) {
        x3 = 0;
        speedX3 = -speedX3;
    } else if(x3 > ofGetWidth()) {
        x3 = ofGetWidth();
        speedX3 = -speedX3;
    }


    // boven/onder tegen de rand aan? keer om!
    if(y < 0 ) {
        y = 0;
        speedY = -speedY;
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY = -speedY;
    }


	if(y2 < 0 ) {
        y2 = 0;
        speedY2 = -speedY2;
    } else if(y2 > ofGetHeight()) {
        y2 = ofGetHeight();
        speedY2 = -speedY2;
    }

	if(y3 < 0 ) {
        y3 = 0;
        speedY3 = -speedY3;
    } else if(y3 > ofGetHeight()) {
        y3 = ofGetHeight();
        speedY3 = -speedY3;
    }

    // bereken nieuwe coordinaten
    x+=speedX;
    y+=speedY;

	x2+=speedX2;
    y2+=speedY2;

    x3+=speedX3;
    y3+=speedY3;

	ofBackground(ofRandom(255),ofRandom(255),ofRandom(255),ofRandom(2)); // psy-fi effect !
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(color);
	ofSetCircleResolution(10);
    ofCircle(x, y, radius);

	ofSetColor(color2);
	ofSetCircleResolution(5);
	ofCircle(x2, y2, radius2);

	ofSetColor(color3);
	ofSetCircleResolution(3);
	ofCircle(x3, y3, radius3);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
