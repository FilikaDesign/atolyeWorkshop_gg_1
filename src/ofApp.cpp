#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // For mac OS X users
    ofSetVerticalSync(true);
    //ofEnableAntiAliasing();
    //ofEnableSmoothing();
    ofBackgroundHex(0x222222);
    
    // Set default constants
    capture = false;
    
    // gui
    guiHide = false;
    

    // GUI Rectangle
    rect_gui.setup("Rectangle Properties"); // most of the time you don't need a name but don't forget to call setup
    rect_gui.setDefaultHeight(GUI_ELEMENT_PER_HEIGHT);
    rect_gui.add(rectangle.set("Rectangle", true)); // show/hide rectangles
    rect_gui.add(rect_num.set( "Rectangle Count", 12, 1, 360 )); // number of rectangles
    rect_gui.add(rect_thickness.set( "Rectangle Thickness", 1, 1, 8 )); // thickness of rectangles
    rect_gui.add(rect_w.set( "Rectangle width", 20, 1, 700 )); // width of rects
    rect_gui.add(rect_h.set( "Rectangle height", 60, 1, 700 )); // height of rects
    rect_gui.add(rect_radius.set( "Distribution Radius", 300, 1, 1200 )); // dist radius of rects
    
    // Capture Button
    captureBtn.addListener(this,&ofApp::captureBtnPressed);
    rect_gui.add(captureBtn.setup("Capture PDF"));
    
    
    // GUI Circle
    circle_gui.setup("Circle Properties"); // most of the time you don't need a name but don't forget to call setup
    circle_gui.setDefaultHeight(GUI_ELEMENT_PER_HEIGHT);
    circle_gui.add(circle.set("Circle", true)); // show/hide circle
    circle_gui.add(circle_num.set( "Circle Count", 12, 1, 360 )); // number of circle
    circle_gui.add(circle_thickness.set( "Circle Thickness", 1, 1, 8 )); // thickness of circle
    circle_gui.add(circle_radius.set( "Circle radius", 20, 1, 700 )); // width of circle
    circle_gui.add(circle_dist_radius.set( "Distribution Radius", 300, 1, 1200 )); // dist radius of circle
    // Set Position of the circle gui
    circle_gui.setPosition(rect_gui.getPosition().x + rect_gui.getWidth() + GUI_GAP, rect_gui.getPosition().y);
    
    
    // GUI Line
    line_gui.setup("Line Properties"); // most of the time you don't need a name but don't forget to call setup
    line_gui.setDefaultHeight(GUI_ELEMENT_PER_HEIGHT);
    line_gui.add(line.set("Line", true)); // show/hide line
    line_gui.add(line_num.set( "Line Count", 12, 1, 360 )); // number of line
    line_gui.add(line_thickness.set( "Line Thickness", 1, 1, 8 )); // thickness of line
    line_gui.add(line_length.set( "Line length", 20, 1, 700 )); // width of line
    line_gui.add(line_dist_radius.set( "Distribution Radius", 300, 1, 1200 )); // dist radius of line
    // Set Position of the circle gui
    line_gui.setPosition(circle_gui.getPosition().x + circle_gui.getWidth() + GUI_GAP, circle_gui.getPosition().y);

    
    
    // Circle resolution
    ofSetCircleResolution(CIRCLE_RESOLUTION);
    
    centerX = ofGetWidth()*0.5;
    centerY = ofGetHeight()*0.5;
    
    
    // Uncomment to load the last settings
    //rect_gui.loadFromFile(RECTANGLE_DATA_FILE);
}

//--------------------------------------------------------------
// Capture Button pressed
void ofApp::captureBtnPressed() {
    capture = true;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    // Draw reference circle
    // do not fill inside
    ofNoFill();
    // set line thinckness
    ofSetLineWidth(0.5);
    // set color of the circle
    ofSetHexColor(0xff0000);
    // draw circle at center of the canvas x pos,y pos, radius
    ofCircle(centerX, centerY, rect_radius);

    
    
    
    
    
    
    
    
    
    
    //-------------------------
    //-------------------------
    // START capture!
    //
    if(capture){
        ofBeginSaveScreenAsPDF("screenshot-"+ofGetTimestampString()+".ai", false);
    }
    //
    // START capture!
    //-------------------------
    //-------------------------

    
    
    
    // turn color to the old state
    ofSetHexColor(LINE_COLOR);
    
    
    
    
    // RECTANGLE PROPERTIES
    float x,y;
    
    // to make equal space around 360 degree of circle
    float anglePerRect = 360.0f / rect_num;
    
    for(int num=0; num < rect_num; num+= 1) {
        
        float rad = num * anglePerRect * (PI / 180);
        
        x = centerX + (rect_radius * cos(rad));
        y = centerY + (rect_radius * sin(rad));
        
        //ofFill();
        ofPushMatrix();
            ofSetRectMode(OF_RECTMODE_CENTER);
            ofTranslate(x, y);
            ofRotate(num * anglePerRect);
            ofSetLineWidth(rect_thickness);
            if(rectangle)
                ofRect(0, 0, rect_w, rect_h);
            ofSetRectMode(OF_RECTMODE_CORNER);
        ofPopMatrix();
    }
    // RECTANGLE END
    
    
    
    // CIRCLE PROPERTIES
    float x_circle,y_circle;
    
    // to make equal space around 360 degree of circle
    float anglePerCircle = 360.0f / circle_num;
    
    for(int ang=0; ang < circle_num; ang+= 1) {
        
        float rad = ang * anglePerCircle * (PI / 180);
        
        x_circle = centerX + (circle_dist_radius * cos(rad));
        y_circle = centerY + (circle_dist_radius * sin(rad));
        
        //ofFill();
        ofPushMatrix();
        ofTranslate(x_circle, y_circle);
        ofRotate(ang * anglePerCircle);
        ofSetLineWidth(circle_thickness);
        if(circle)
            ofCircle(0, 0, circle_radius);
        ofPopMatrix();
    }
    // CIRCLE END
    
    
    
    
    // LINE PROPERTIES
    float x_line,y_line;
    
    // to make equal space around 360 degree of circle
    float anglePerLine = 360.0f / line_num;
    
    for(int ang=0; ang < line_num; ang+= 1) {
        
        float rad = ang * anglePerLine * (PI / 180);
        
        x_line = centerX + (line_dist_radius * cos(rad));
        y_line = centerY + (line_dist_radius * sin(rad));
        
        //ofFill();
        ofPushMatrix();
        ofTranslate(x_line, y_line);
        ofRotate(ang * anglePerLine);
        ofSetLineWidth(line_thickness);
        if(line)
            ofLine(0,0,line_length,0);
        ofPopMatrix();
    }
    // LINE END
    
    
    
    
    
    
    
    
    //-------------------------
    //-------------------------
    // End capture!
    //
    
    //once we have done all our drawing
    //we end the ouput which saves the file
    //and then we stop capturing
    if(capture){
        ofEndSaveScreenAsPDF();
        capture = false;
    }
    
    //
    // End capture!
    //-------------------------
    //-------------------------

    
    
    
    
    
    
    
    // Draw gui on to canvas when guiHide is set to false and there is no capture event
    if( !guiHide && !capture){
        rect_gui.draw();
        circle_gui.draw();
        line_gui.draw();
    }
    
    // Draw FPS on to screen
    ofDrawBitmapStringHighlight(ofToString(ofGetFrameRate()), ofGetWidth() - 100, 20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g') {
        guiHide = !guiHide;
    }
    
     if(key == 'c') {
        capture = true;
    }
    
     if(key == 's') {
        rect_gui.saveToFile(RECTANGLE_DATA_FILE);
        circle_gui.saveToFile(CIRCLE_DATA_FILE);
        line_gui.saveToFile(LINE_DATA_FILE);
    }
    
     if(key == 'l') {
        rect_gui.loadFromFile(RECTANGLE_DATA_FILE);
        circle_gui.loadFromFile(CIRCLE_DATA_FILE);
        line_gui.loadFromFile(LINE_DATA_FILE);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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

void ofApp::exit() {
    captureBtn.removeListener(this,&ofApp::captureBtnPressed);
}
