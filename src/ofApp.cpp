#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    gui.add(lowThresholdEdge.setup("Edge Threshold", 50, 0, 100));
    webcamGrabber.setup(640, 640);
}

//--------------------------------------------------------------
void ofApp::update(){
    webcamGrabber.update();
    
    // Edge Detection
//    if(webcamGrabber.isFrameNew()){
//        ofPixels pixs = webcamGrabber.getPixels();
//        webcamGrabberFrame.setFromPixels(pixs);
//        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
//        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
//        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
//        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*3);
//    }
    
    // Circle Detection
    if (webcamGrabber.isFrameNew()) {
        ofPixels pixs = webcamGrabber.getPixels();
        webcamGrabberFrame.setFromPixels(pixs);
        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
//        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMat, CV_BGR2GRAY);
//        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
        GaussianBlur(webcamGrabberFrameMat, webcamGrabberFrameMat, 3);
//        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*2);
        Canny(webcamGrabberFrameMat, webcamGrabberFrameMat, lowThresholdEdge, lowThresholdEdge*2);
        
        
        HoughCircles(webcamGrabberFrameMat, circles, CV_HOUGH_GRADIENT, 2, 50, lowThresholdEdge*2, 100, 30, 50);
        ofSetColor(255, 0, 0);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofSetColor(255, 255, 255);
//    webcamGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
    webcamGrabber.draw(0, 0);
    for (int i = 0; i < circles.size(); ++i) {
        ofFill();
        ofSetColor(255, 255, 255);
        ofDrawCircle(circles[i][0], circles[i][1], circles[i][2], 42);
        
        ofSetColor(0, 0, 0);
        ofDrawCircle(circles[i][0], circles[i][1], circles[i][2], 21);
        
    }
//    ofSetColor(255, 255, 255);
//    drawMat(webcamGrabberFrameMat, 0, 0, ofGetWidth(), ofGetHeight());
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
