#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);

	drawGrid = true; 
	gui.setup();
	gui.add(rotationSpeedX.set("X",0,0,90.0));
	gui.add(rotationSpeedY.set("Y",0,0,90.0));
	gui.add(rotationSpeedZ.set("Z",0,0,90.0));

	gui.add(rodeKleur.set("REDSLIDER",0,0,255));
	gui.add(groeneKleur.set("GREENSLIDER",0,0,255));
	gui.add(blauweKleur.set("BLUESLIDER",0,0,255));

	rotationX = 0;
	rotationY = 0;
	rotationZ = 0;
	red = 0;
	green = 0;
	blue = 0;
}

//--------------------------------------------------------------
void ofApp::update(){

	rotationX += rotationSpeedX;
	rotationY += rotationSpeedY;
	rotationZ += rotationSpeedZ;
	red  = rodeKleur;
	green = groeneKleur;
	blue  = blauweKleur;


}

//--------------------------------------------------------------
void ofApp::draw(){

	gui.draw();
	/*if(drawGrid) ofDrawGrid(200); */
	ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

	
	ofRotateX(rotationX);
	ofRotateY(rotationY);
	ofRotateZ(rotationZ);

	

	ofSetColor(red,green,blue);
	ofSetCircleResolution(6);
	ofCircle(ofRandom(-40,40),(-40,40),60);

	ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
	ofSetCircleResolution(3);
	ofCircle(300,50,150);



	if(drawGrid) ofDrawGrid(200);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

	if (key=='g')
	{
		drawGrid = !drawGrid;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
