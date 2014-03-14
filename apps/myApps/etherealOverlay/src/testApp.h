#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "eoMenuButton.h"
#include "eoIngameMenu.h"

class testApp : public ofBaseApp{
	ofEvent<int> onButtonGo;
public:
	void setup();
	void update();
	void draw();

	void exit();
#pragma region event stuff
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	void circleResolutionChanged(int & circleResolution);
	void ringButtonPressed();
#pragma endregion
	bool bHide;

	eoIngameMenu menu;


	ofSoundPlayer ring;
};