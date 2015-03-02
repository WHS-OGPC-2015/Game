#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    viewPos = ofVec2f(0, 0);
    gameEngine  = new Engine("tiles.xml", "game.xml", "objects.xml")
}

//--------------------------------------------------------------
void ofApp::update(){
    if(dragging == true)
    {
        ofVec2f dif = mousePos - lastMousePos;
        viewPos += dif;
    }
    gameEngine.update();
    lastMousePos = mousePos;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPopMatrix();
    ofTranslate(viewPos.x, viewPos.y);
    gameEngine.draw();
    ofPushMatrix():

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
  mousePos.x = x;
  mousePos.y = y;
  dragging = false;



}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    dragging = true;
    mousePos.x = x;
    mousePos.y = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    dragging = false;
    mousePos.x = x;
    mousePos.y = y;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    dragging = false;
    mousePos.x = x;
    mousePos.y = y;


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
