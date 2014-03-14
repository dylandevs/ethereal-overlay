#include "eoIngameMenu.h"

#pragma region structors
eoIngameMenu::eoIngameMenu()
{
	ofSetVerticalSync(true);
	name = "Menu";
	showing = false;
	menuBg.loadImage("img/menu/menu.png");
	selectedButton = 0;
}
eoIngameMenu::eoIngameMenu(string menuName)
{
	ofSetVerticalSync(true);
	name = menuName;
	if (name == "EO"){
		titleImage.loadImage("img/menu/EOlogo.png");
	}
	showing = false;
	menuBg.loadImage("img/menu/menu.png");
	selectedButton = 0;
}
eoIngameMenu::~eoIngameMenu()
{}
#pragma endregion
#pragma region visibility
void eoIngameMenu::show(){
	showing = true;
}
void eoIngameMenu::hide(){
	showing = false;
}
void eoIngameMenu::draw(){
	if (showing){
		menuBg.draw(ofGetScreenWidth() / 2 - 640, ofGetScreenHeight() / 2 - 640);
		if (name == "EO"){
			titleImage.draw(ofGetScreenWidth() / 2 - 132, ofGetScreenHeight() / 2 - 403);
		}
		else{
			titleFont.drawStringCentered(name, ofGetScreenWidth() / 2, ofGetScreenHeight() / 2 - 337);
		}
		for (int i = 0; i < buttons.size(); i++){
			if (i == selectedButton){
				buttons[i]->drawSelected();
			}
			else {
				buttons[i]->draw();
			}
		}
	}
}
bool eoIngameMenu::visible(){
	return showing;
}
#pragma endregion
#pragma region button stuff
void eoIngameMenu::addButton(eoMenuButton * newButton){
	newButton->setPos(ofGetScreenWidth() / 2, (ofGetScreenHeight() / 2) - 172 + (192 * buttons.size()));
	ofAddListener(eoMenuButton::onButtonGo, this, &eoIngameMenu::onButtonGo);
	buttons.push_back(newButton);
}
void eoIngameMenu::selectUp(){
	if (--selectedButton < 0){
		selectedButton = buttons.size() - 1;
	}
}
void eoIngameMenu::selectDown(){
	if (++selectedButton >= buttons.size()){
		selectedButton = 0;
	}
}
void eoIngameMenu::go(){
	buttons[selectedButton]->go();
}
void eoIngameMenu::onButtonGo(bool& state){
	showing = false;
}
#pragma endregion