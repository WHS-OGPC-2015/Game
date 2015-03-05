#include "ofApp.h"
#include "XML/src/ofxXmlSettings.h"
//--------------------------------------------------------------
void ofApp::setup(){
    viewPos = ofVec2f(0, 0);
    ofVec2f& v = viewPos;
    ofxXmlSettings tiles;
    tiles.addValue("mapSizeX", 5);
    tiles.addValue("mapSizeY", 3);
    tiles.addValue("tileSizeX", 50);
    tiles.addValue("tileSizeY", 50);
    tiles.addTag("TILES");
    tiles.pushTag("TILES");
    for(int ii = 0; ii<15; ii++)
    {
        tiles.addTag("tile");
        tiles.pushTag("tile");

        if(ii>5)
        {
            tiles.addValue("texture", "water");
        }
        else{ tiles.addValue("texture", "grass");}

        tiles.popTag();


    }
    tiles.popTag();
    tiles.saveFile("tiles.xml");
    gameEngine  = new Engine("tiles.xml", "game.xml", "objects.xml", v);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(dragging == true)
    {
        dif = mousePos - lastMousePos;
        viewPos += dif;
    }
    gameEngine->update();
    lastMousePos = mousePos;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPopMatrix();
    ofTranslate(viewPos.x, viewPos.y);
    gameEngine->draw();
    ofPushMatrix();

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
