#include "Ball.h"

#define PIN_LED 11

Ball::Ball() {
}

void Ball::setup() {
    x = ofRandom(0, ofGetWidth());      // give some random positioning
    y = ofRandom(0, ofGetHeight());

    speedX = ofRandom(-10, 10);           // and random speed and direction
    speedY = ofRandom(-10, 10);

    radius = 50;

    color.set(ofRandom(255),ofRandom(255),ofRandom(255));
}


void Ball::update(ofArduino* arduino) {
    if(x < 0 ) {
        x = 0;
        speedX *= -1;
        arduino->sendDigital(PIN_LED, ARD_HIGH);
    } else if(x > ofGetWidth()) {
        x = ofGetWidth();
        speedX *= -1;
        arduino->sendDigital(PIN_LED, ARD_LOW);
    }

    if(y < 0 ) {
        y = 0;
        speedY *= -1;
        arduino->sendDigital(PIN_LED, ARD_HIGH);
    } else if(y > ofGetHeight()) {
        y = ofGetHeight();
        speedY *= -1;
        arduino->sendDigital(PIN_LED, ARD_LOW);
    }

    x += speedX;
    y += speedY;
}

void Ball::setSpeed(float newSpeed) {
    // make sure the ball keeps moving in the same direction: same sign
    if (speedX>0) {
        speedX = newSpeed;
    } else {
        speedX = -newSpeed;
    }
    if (speedY>0) {
        speedY = newSpeed;
    } else {
        speedY = -newSpeed;
    }
}

void Ball::draw(float newSize) {
    ofSetColor(color);
	ofCircle(x, y, newSize);
}
