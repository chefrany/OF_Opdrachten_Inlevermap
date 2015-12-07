#pragma once //
#include "ofMain.h"


class kaas
{
public:
	kaas(float snelY_,float snelX_);

	void begin( float snel_);
	void tekenen();
	void checken();

	float X;
    float Y;
    float speedY;
    float speedX;

	int height;
	int width;

	

	ofColor color_RandomShizz;
};

