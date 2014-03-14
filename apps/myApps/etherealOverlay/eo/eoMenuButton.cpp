#include "eoMenuButton.h"
#pragma region structors
eoMenuButton::eoMenuButton(){
	xPos = 0;
	yPos = 0;
	name = "Button";
	bgImage.loadImage("img/menu/button.png");
	bgImageSelected.loadImage("img/menu/buttonSelected.png");
	nameColour.setHex(0x1883ac);
}
eoMenuButton::eoMenuButton(string newName){
	xPos = 0;
	yPos = 0;
	name = newName;
	bgImage.loadImage("img/menu/button.png");
	bgImageSelected.loadImage("img/menu/buttonSelected.png");
	nameColour.setHex(0x1883ac);
}
#pragma endregion
#pragma region visibility
void eoMenuButton::draw(){
	bgImage.update();
	bgImage.draw(xPos, yPos);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(nameColour);
	ofFill();
	nameFont.drawStringCentered(name, xPos + 320, yPos + 96);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(ofColor::white);
	ofFill();
}
void eoMenuButton::drawSelected(){
	bgImageSelected.update();
	bgImageSelected.draw(xPos, yPos);
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(nameColour);
	ofFill();
	nameFont.drawStringCentered(name, xPos + 320, yPos + 96);
	ofSetRectMode(OF_RECTMODE_CORNER);
	ofSetColor(ofColor::white);
	ofFill();
}
void eoMenuButton::setPos(int x, int y){
	xPos = x - 320;
	yPos = y - 96;
}
#pragma endregion
#pragma region actions
ofEvent <bool> eoMenuButton::onButtonGo;
void eoMenuButton::go(){
	static bool num = true;
	ofNotifyEvent(onButtonGo, num);
}
#pragma endregion