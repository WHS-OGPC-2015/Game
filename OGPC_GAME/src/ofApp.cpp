#include "ofApp.h"
#include "XML/src/ofxXmlSettings.h"
//--------------------------------------------------------------
void ofApp::setup(){
    viewPos = ofVec2f(0, 0);

    ofxXmlSettings tileSave;
    tileSave.addValue("mapSizeX", 100);
    tileSave.addValue("mapSizeY", 100);
    tileSave.addValue("tileSizeX", 50);
    tileSave.addValue("tileSizeY", 50);
    tileSave.addTag("tileArray");
    tileSave.pushTag("tileArray");
        for(int bb = 0; bb < 10000; bb++)
        {
            tileSave.addTag("tile");
            tileSave.pushTag("tile", bb);
            if(bb%2 == 0)
            {
                tileSave.addValue("texture", "dumbGrass");
            }
            else if(bb%3 == 0)
            {
                tileSave.addValue("texture", "dumbSnow");
            }
            else
            {
                tileSave.addValue("texture", "dumbWater");
            }

            tileSave.popTag();
        }


    tileSave.popTag();
    tileSave.saveFile("tiles.xml");
    gameEngine  = new Engine("tiles.xml", "game.xml", "objects.xml", viewPos);
}

//--------------------------------------------------------------
void ofApp::update(){
    if(dragging)
    {
        dif = mousePos - lastMousePos;
        dif/=5;

        viewPos+=dif;
        if(viewPos.x>0)
        {
            viewPos.x-=dif.x;
            dif.x = 0;
        }
        if(viewPos.y>0)
        {
            viewPos.y-=dif.y;
            dif.y = 0;
        }
    }
    else
    {
        dif = ofVec2f(0, 0);

    }



    gameEngine->update();
    lastMousePos = mousePos;
    dragging = false;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPopMatrix();
    ofTranslate(dif.x, dif.y);
    gameEngine->draw();
    ofPushMatrix();
    ofCircle(0, 0, 100);

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
