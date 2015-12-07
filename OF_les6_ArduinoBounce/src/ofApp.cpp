#include "ofApp.h"
#include "Ball.h"

//--------------------------------------------------------------
void ofApp::setup() {

    // set listener - call ofApp::setupArduino when arduino is ready for use
    ofAddListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // connect to the Arduino
    // use the same device name used in the Arduino IDE
    arduino.connect("COM4");
    arduino.sendFirmwareVersionRequest();

    ball.setup();
}

//--------------------------------------------------------------
void ofApp::update() {
    arduino.update();

    if (arduino.isInitialized()) {
        ball.update(&arduino);
    }
}

//--------------------------------------------------------------
void ofApp::draw() {

    ball.draw(newSize);
}

void ofApp::setupArduino(const int& version) {
    // remove listener because we don't need it anymore
    ofRemoveListener(arduino.EInitialized, this, &ofApp::setupArduino);

    // print firmware name and version to the console
    ofLogNotice() << "Arduino firmware found: " << arduino.getFirmwareName()
                  << " v" << arduino.getMajorFirmwareVersion() << "."  << arduino.getMinorFirmwareVersion();

    arduino.sendDigitalPinMode(11, ARD_OUTPUT);
    arduino.sendAnalogPinReporting(0, ARD_ANALOG);

    // set listeners for pin events
    ofAddListener(arduino.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

void ofApp::analogPinChanged(const int& pinNum) {
    int value = arduino.getAnalog(pinNum);
    // value ranges from 0-1023 - decrease the range, and set a minimum
    float newSpeed = value/4 + 5;
	float newSize = value/10;
    // or you could use this function to achieve the same
    //float newSpeed = ofMap(value, 0, 1023, 5, 255);

    ball.setSpeed(newSpeed);

}

void ofApp :: mousePressed(int x, int y, int button)
{
	
}