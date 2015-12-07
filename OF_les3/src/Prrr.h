#pragma once //
#include "ofMain.h"


class blub
{
public:
	blub();

	void begin();
	void tekenen();
	void checken();

	float x;
    float y;
    float speedY;
    float speedX;

	int radius;
	float corners;
	

	ofColor color_RandomShizz;
};

