#include "ofTrueTypeFont.h"
#pragma once
class eoFont : public ofTrueTypeFont
{
public:
#pragma region structors
	eoFont();
	~eoFont();
#pragma endregion
#pragma region text centering
	//sourced from https://github.com/armadillu/ofxCenteredTrueTypeFont
	ofVec2f getOffset(string s);
	void drawStringCentered(string s, float x, float y, bool asVector = false);
#pragma endregion
};

