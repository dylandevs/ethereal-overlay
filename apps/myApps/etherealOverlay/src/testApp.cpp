#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	menu = eoIngameMenu("EO");
	menu.addButton(new eoMenuButton("Play"));
	menu.addButton(new eoMenuButton("Controls"));
	menu.addButton(new eoMenuButton("Recalibrate"));
	menu.show();
	ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackgroundGradient(ofColor::darkGray, ofColor::black);
	menu.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	switch (key){
	case OF_KEY_UP:
	case 'w':
		if (menu.visible()){
			menu.selectUp();
		}
		break;
	case OF_KEY_DOWN:
	case 's':
		if (menu.visible()){
			menu.selectDown();
		}
		break;
	case OF_KEY_RETURN:
	case ' ':
		if (menu.visible()){
			menu.go();
		}
		break;
	default:
		break;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
}
void testApp::exit(){

}
//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}