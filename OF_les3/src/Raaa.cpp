#include "Raaa.h"


kaas::kaas(float snelY_,float snelX_)
{
 speedY = snelY_;
 speedX = snelX_;

}
/////////////////////////////////
void kaas :: begin(float snel_X) // start
{
	
	X = ofRandom (0 , ofGetWidth());
	Y = ofRandom (0 , ofGetHeight());

	//speedX = ofRandom(-5 , 5);
	//speedY = ofRandom(-5 , 5);
	
	color_RandomShizz.set(ofRandom(255) , ofRandom(255) , ofRandom(255));

	
	height = ofRandom(10,100);
	width = ofRandom(10,100);
	
	
}
/////////////////////////////////
void kaas :: checken() //update
{  
	if( X + width < 0 ){ // omtrek van het object inplaats van alleen het midden punt.   
		X = width; // omtrek van object niet midden punt 
        speedX *= -1; // richting wordt omgedraaid

	} else if(X + width > ofGetWidth()){
		X = ofGetWidth() - width;
        speedX *= -1;
    }
	//****************************//
	if(Y + height < 0 ){ 
		Y = height;
        speedY *= -1;
	} else if(Y + height > ofGetHeight()){
		Y = ofGetHeight() - height;
        speedY *= -1;
    }

	X+=speedX; // x positie op dat moment + beweging snelheid van het object
    Y+=speedY;
}
/////////////////////////////////
void kaas :: tekenen() // draw 
{

	ofSetColor(color_RandomShizz);

	ofRect(X,Y,width,height);
}
/////////////////////////////////

