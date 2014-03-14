#pragma once

#include "ofMain.h"
#include "ofParameter.h"
#include "ofxBaseGui.h"
#include "ofxToggle.h"
#include "ofImage.h"
#include "eoFont.h"

class eoMenuButton : public ofxToggle {
	friend class ofPanel;

	ofRectangle background;
	ofImage bgImage;
	ofImage bgImageSelected;
	string name;
	ofColor nameColour;
	eoFont nameFont;

	int xPos;
	int yPos;

public:
	static ofEvent<bool> onButtonGo;
#pragma region structors
	eoMenuButton();
	eoMenuButton(string newName);
	~eoMenuButton(){};
#pragma endregion
#pragma region visibility
	void draw();
	void drawSelected();
	void setPos(int x, int y);
#pragma endregion
#pragma region actions
	void go();
#pragma endregion
};