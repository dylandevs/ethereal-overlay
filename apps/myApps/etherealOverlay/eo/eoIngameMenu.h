#pragma once

#include "ofxToggle.h"
#include "ofParameter.h"
#include "eoMenuButton.h"
class eoIngameMenu : public ofxToggle{
	friend class ofPanel;

#pragma region variables
	string name;
	ofImage menuBg;
	eoFont titleFont;
	ofImage titleImage;
	vector<eoMenuButton*> buttons;
	int selectedButton;
	bool showing;
#pragma endregion

public:
#pragma region structors
	eoIngameMenu();
	eoIngameMenu(string menuName);
	~eoIngameMenu();
#pragma endregion
#pragma region event stuff
	/*
	virtual bool mouseReleased(ofMouseEventArgs & args);
	virtual bool mouseMoved(ofMouseEventArgs & args);
	virtual bool mousePressed(ofMouseEventArgs & args);
	virtual bool mouseDragged(ofMouseEventArgs & args);*/
	template<class ListenerClass, typename ListenerMethod>
	void addListener(ListenerClass * listener, ListenerMethod method){
		ofAddListener(triggerEvent, listener, method);
	}

	template<class ListenerClass, typename ListenerMethod>
	void removeListener(ListenerClass * listener, ListenerMethod method){
		ofRemoveListener(triggerEvent, listener, method);
	}
#pragma endregion
#pragma region visibility
	void show();
	void hide();
	void draw();
	bool visible();
#pragma endregion
#pragma region button stuff
	void addButton(eoMenuButton* newButton);
	void selectUp();
	void selectDown();
	void go();
	void onButtonGo(bool& state);
#pragma endregion

private:
	ofEvent<void> triggerEvent;
	void valueChanged(bool & v);

};


