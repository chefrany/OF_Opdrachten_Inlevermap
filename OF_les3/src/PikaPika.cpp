#include "PikaPika.h"


vis::vis()
{}
/////////////////////////////////
void vis :: begin() // start
{
	corners = 60; 
	x = ofRandom (0 , ofGetWidth());
	y = ofRandom (0 , ofGetHeight());

	speedX = ofRandom(-5 , 5);
	speedY = ofRandom(-5 , 5);
	
	color_RandomShizz.set(ofRandom(255) , ofRandom(255) , ofRandom(255));

	radius = ofRandom(10 , 50);
	
	
}
/////////////////////////////////
void vis :: checken() //update
{  
	if( x + radius < 0 ){ // omtrek van het object inplaats van alleen het midden punt.   
		x = radius; // omtrek van object niet midden punt 
        speedX *= -1; // richting wordt omgedraaid

	} else if(x + radius > ofGetWidth()){
		x = ofGetWidth() - radius;
        speedX *= -1;
    }
	//****************************//
	if(y + radius < 0 ){ 
	    y = radius;
        speedY *= -1;
	} else if(y + radius > ofGetHeight()){
		y = ofGetHeight() - radius;
        speedY *= -1;
    }

    x+=speedX; // x positie op dat moment + beweging snelheid van het object
    y+=speedY;
}
/////////////////////////////////
void vis :: tekenen() // draw 
{
	ofSetCircleResolution(corners); 
	ofSetColor(color_RandomShizz);
    ofCircle(x, y, radius);
}
/////////////////////////////////

