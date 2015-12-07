#include "ofApp.h"

void ofApp::setup(){
	ofBackground(ofColor::black);
	grabber.listDevices();
	ofSetFrameRate(60);
	grabber.setDeviceID(0);
	grabber.setDesiredFrameRate(60);
	grabber.initGrabber(640,480);

	ofSetVerticalSync(true);
	video.loadMovie("lines_center_shape_refurse.mov");
	video.play();
	video.setLoopState(OF_LOOP_NORMAL);

}

void ofApp::update(){
	grabber.update();
	video.update();
	rotate++;
}

void ofApp::keyPressed(int key){
	switch(key){
        case 'q':
            video.setSpeed(1);
            break;
        case 'w':
            video.setSpeed(15);
            break;
        case 'e':
            video.setSpeed(-2);
            break;
        case 'r':
            video.firstFrame();
            break;
    }
}

void ofApp::draw(){
	//video.draw(0,0);
    ofSetColor(ofColor::white);
	ofScale(0.8,0.8);
	video.draw(ofGetScreenWidth()*0.5,ofGetScreenHeight()*0.5);


   grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::red);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::green);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::blue);

    ofScale(0.7,0.7,0.7);
    ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
    grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::deepPink);
	ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::crimson);
	ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

	ofSetColor(ofColor::orange);
	ofTranslate(400,200);
    ofRotateX(rotate);
    ofRotateY(rotate);
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));
	grabber.draw(ofRandom(0,ofGetScreenWidth()),ofRandom(0,ofGetScreenWidth()));

}
