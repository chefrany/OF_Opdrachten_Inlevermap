#pragma once

#include "ofMain.h"

class Paddle {

public:

    Paddle();

    void draw();
	void update();

	//locatie van de paddle op het scherm
	enum Location
	{
		LEFT,
		RIGHT
	};

	//welke kant je de paddle op beweegt
	enum Direction
	{
		UP,
		DOWN
	};

	Location l;

	void move(Direction d);

    // variables
	float x;
    float y;
    float speedY;
	float width;
	float height;
	float edgeDistance;
	ofColor color;

private:


};