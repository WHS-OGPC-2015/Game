#include "ofApp.h"
#include "XML/src/ofxXmlSettings.h"

//--------------------------------------------------------------
void ofApp::setup(){
    viewPos = ofVec2f(0, 0);
    first = true;
    gameEngine = new Engine();
    mapGenerator = new GameMap;
//
//    ofxXmlSettings tileSave;
//    tileSave.addValue("mapSizeX", 100);
//    tileSave.addValue("mapSizeY", 100);
//    tileSave.addValue("tileSizeX", 50);
//    tileSave.addValue("tileSizeY", 50);
//    tileSave.addTag("tileArray");
//    tileSave.pushTag("tileArray");
//        for(int bb = 0; bb < 10000; bb++)
//        {
//            tileSave.addTag("tile");
//            tileSave.pushTag("tile", bb);
//            if(bb%2 == 0)
//            {
//                tileSave.addValue("texture", "dumbGrass");
//            }
//            else if(bb%3 == 0)
//            {
//                tileSave.addValue("texture", "dumbSnow");
//            }
//            else
//            {
//                tileSave.addValue("texture", "dumbWater");
//            }
//
//            tileSave.popTag();
//        }
//
//
//    tileSave.popTag();
//    tileSave.saveFile("tiles.xml");


}

//--------------------------------------------------------------
void ofApp::update(){

    if(currentState == MAINMENU)
    {
        if(first == true)
        {
            first = false;
            startingMenu = new MainMenu;
        }
        if(startingMenu->update(mousePos, clicked, pressed))
        {
            currentState = LOADING;
            first = true;
            delete startingMenu;
        }
    }
    else if(currentState == LOADING)
    {
        if(first == true)
        {
            loader = new LoadingThread(gameEngine, mapGenerator);
            loader->update(viewPos);
            std::cout << "here" << std::endl;
            loader->start();
            std::cout << "here1" << std::endl;
            first = false;
        }
        if(!loader->isThreadRunning())
        {
            std::cout << "here2" << std::endl;
            currentState = GAME;
        }
    }
    else if(currentState == GAME)
    {
        if(first == true)
        {
//            std::cout << "here1" << std::endl;
//            mapGenerator = new GameMap;
//            std::cout << "here" << std::endl;
//            gameEngine  = new Engine("tiles.xml", "game.xml", "objects.xml", viewPos);

            first = false;
        }
            loader->update(viewPos);
        gameEngine->update();

    }

    if(dragging)
    {
        dif = mousePos - lastMousePos;
        dif/=2; //scales the drag (2 would be half the distance the mouse was moved"

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



    if(pressed != true)
    {
        clicked = false;
    }
    lastMousePos = mousePos;
    dragging = false;

}

//--------------------------------------------------------------
void ofApp::draw(){
    if(first != true)//only update once the object has been initialized
    {
        if(currentState == GAME)
        {
            ofPopMatrix();
            ofTranslate(dif.x, dif.y);
            gameEngine->draw();
            ofPushMatrix();
        }
        else if(currentState == MAINMENU)
        {
            startingMenu->draw();
        }
        else if(currentState == LOADING)
        {
            ofCircle(400, 400, 200);
        }
    }





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
    pressed = true;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(pressed == true)
    {
        pressed = false;
        clicked = true;
    }
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

//void ofApp::exit()
//{
//    delete gameEngine;
//    delete mapGenerator;
//    delete startingMenu;
//    delete loader;
//}
