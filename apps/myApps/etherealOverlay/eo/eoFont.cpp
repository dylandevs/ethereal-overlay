#include "eoFont.h"

#pragma region structors
eoFont::eoFont()
{
	loadFont("trench100free.otf", 60);
}


eoFont::~eoFont()
{
}
#pragma endregion
#pragma region text centering
//sourced from https://github.com/armadillu/ofxCenteredTrueTypeFont
ofVec2f eoFont::getOffset(string s){
	ofRectangle r = getStringBoundingBox(s, 0, 0);
	return ofVec2f(floor(-r.x - r.width * 0.5f), floor(-r.y - r.height * 0.5f));
}
void eoFont::drawStringCentered(string s, float x, float y, bool asVector){
	ofVec2f offset = getOffset(s);
	if (!asVector)
		drawString(s, x + offset.x, y + offset.y);
	else
		drawStringAsShapes(s, x + offset.x, y + offset.y);
}
#pragma endregion