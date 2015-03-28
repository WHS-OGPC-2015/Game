#pragma once

#include "ofMain.h"
#include "src-Engine/EngineInclude.h"
#include "src-Game/GameMap.h"
#include "MainMenu.h"

class LoadingThread : public ofThread
{
public:
    LoadingThread(Engine* e, GameMap* m) : E(e), M(m) {}

    void threadedFunction()
    {
        if(isThreadRunning())
        {
            lock();
                std::cout << "here4" << std::endl;
                M->generateMap();
                std::cout << "here5" << std::endl;
                E->setup("tiles.xml", "game.xml", "objects.xml", viewPos);
                std::cout << "here6" << std::endl;
            unlock();
            stopThread();
        }
    }

    void start()
    {
        startThread();
    }
    void update(ofVec2f v)
    {
        viewPos = v;
    }
private:
    Engine* E;
    GameMap* M;
    ofVec2f viewPos;

};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofVec2f mousePos, lastMousePos, dif;
        bool pressed;//true if mouse button has been pressed down
        bool clicked;//true if mouse button has been pushed down then released
        bool dragging;//true if mouse button is pressed and is being moved

        Engine* gameEngine;
        GameMap* mapGenerator;
        ofVec2f viewPos;
        MainMenu* startingMenu;
        LoadingThread* loader;

        enum GameStates{MAINMENU, LOADING, GAME};
        int currentState;
        bool first;



};



