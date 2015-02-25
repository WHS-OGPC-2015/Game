#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){
//startingMenu.update(mousePos, clicked);
//if(pressed != true)
//    {
//            clicked = false;
//
//    }
}

//--------------------------------------------------------------
void ofApp::draw(){

//startingMenu.draw();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    mousePos = ofVec2f(x, y);


}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    mousePos = ofVec2f(x, y);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
            pressed =true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
            if(pressed == true)
            {
                pressed = false;
                clicked = true;
            }


}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
