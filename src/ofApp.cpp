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
    if(webcamGrabber.isFrameNew()){
        ofPixels pixs = webcamGrabber.getPixels();
        webcamGrabberFrame.setFromPixels(pixs);
        webcamGrabberFrameMat = toCv(webcamGrabberFrame);
        cvtColor(webcamGrabberFrameMat, webcamGrabberFrameMatGray, CV_BGR2GRAY);
        GaussianBlur(webcamGrabberFrameMatGray, webcamGrabberFrameMatGray, 3);
        Canny(webcamGrabberFrameMatGray, webcamGrabberFrameMatEdge, lowThresholdEdge, lowThresholdEdge*3);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    webcamGrabber.draw(0, 0, ofGetWidth(), ofGetHeight());
//    ofSetColor(255, 255, 255);
    drawMat(webcamGrabberFrameMatEdge, 0, 0, ofGetWidth(), ofGetHeight());
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
