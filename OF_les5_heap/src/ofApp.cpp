#include "ofApp.h"
#include "Ball.h"

void ofApp::setup() {
    ball = new Ball();
    ball->setup();
}

void ofApp::update() {
    ball->update();
}

void ofApp::draw() {
    ball->draw();
}

void ofApp::exit() {
    delete ball;
}
