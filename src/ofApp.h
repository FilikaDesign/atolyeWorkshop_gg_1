#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "animConstants.h"


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
    
    // Add on Exit event handler to free up memory used by our app
    void exit();
    
    // CANVAS
    int centerX;
    int centerY;
    
    // GUI
    bool guiHide;                        // to hide/show gui
    bool capture;                       // trigger boolean to enable screen capture
    
    ofxLabel captureTxt;                // label for capture button
    ofxButton captureBtn;               // capture button
    void captureBtnPressed();           // capture button event handler
    
    
    
    // RECTANGLE
    ofxPanel rect_gui;                  // gui holder sprite for rectangle ui
    ofParameter<int> rect_radius;       // rectangle distrubution radius
    ofParameter<int> rect_num;          // number of rectangles on canvas
    ofParameter<int> rect_w;            // rect per width
    ofParameter<int> rect_h;            // rect per height
    ofParameter<int> rect_thickness;    // rectangle thickness
    ofParameter<bool> rectangle;        // boolean parameters to show/hide rectangles on canvas
    
    
    // CIRCLE
    ofxPanel circle_gui;                  // gui holder sprite for circle ui
    ofParameter<int> circle_dist_radius;  // circle distrubution radius
    ofParameter<int> circle_radius;       // circle radius
    ofParameter<int> circle_num;          // number of circle on canvas
    ofParameter<int> circle_thickness;    // circle thickness
    ofParameter<bool> circle;             // boolean parameters to show/hide circle on canvas

    
    
    // LINE
    ofxPanel line_gui;                  // gui holder sprite for line ui
    ofParameter<int> line_dist_radius;  // line distrubution radius
    ofParameter<int> line_length;       // line length
    ofParameter<int> line_num;          // number of line on canvas
    ofParameter<int> line_thickness;    // line thickness
    ofParameter<bool> line;             // boolean parameters to show/hide line on canvas
    
    
    
    
    
    
};
