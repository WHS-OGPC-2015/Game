#include "ofApp.h"
#include "XML/src/ofxXmlSettings.h"

//--------------------------------------------------------------
void ofApp::setup(){
    viewPos = ofVec2f(0, 0);
    first = true;
    currentState = MAINMENU;
    ofSetFrameRate(60); //set framerate
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

            resources = new ResourceManager;
            resources->loadFilesFromDirectory("C:\\OpenFrameworks\\apps\\Game\\OGPC_GAME\\bin\\data\\tiles");
            resources->addTexture("City.png", "City");

            gameEngine = new Engine;
            mapGenerator = new GameMap;
            loader = new LoadingThread(gameEngine, mapGenerator, resources);
            loader->update(viewPos);
            loading = new LoadingScreen(ofRandom(5, 25), ofVec2f(512, 512), ofRandom(2, 20), ofRandom(1, 50), ofRandom(10, 250));
            //loading = new LoadingScreen(10, ofVec2f(512, 512), 10, 1, 100);
            pause = new PauseMenu();
            loader->start();

            first = false;
        }
        loading->update();
        if(!loader->isThreadRunning())
        {

            currentState = GAME;
        }
    }
    else if(currentState == GAME)
    {
        if(first == true)
        {
            gameEngine->mainThreadFunction();   //loads textures for the menus
            std::cout << "here" << std::endl;
            first = false;
        }
        loader->update(viewPos);
        if(pause->isActive())
        {
            if(pause->update(mousePos, clicked, pressed) == 0)
            {
                currentState = MAINMENU;
            }
            dif = ofVec2f(0, 0);
        }

        else
        {
            gameEngine->update(mousePos, clicked, pressed);
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
        }



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
            ofSetColor(255, 255, 255);
            ofPopMatrix();
            ofTranslate(dif.x, dif.y);
            gameEngine->draw();
            if(pause->isActive())
            {
                pause->draw();
            }
            ofPushMatrix();
        }
        else if(currentState == MAINMENU)
        {
            startingMenu->draw();
        }
        else if(currentState == LOADING)
        {
            ofBackground(79, 67, 44);
            loading->draw();
            //ofCircle(400, 400, 200);
        }
    }





}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == OF_KEY_F1)
    {
        pause->toggleActive();
    }
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
