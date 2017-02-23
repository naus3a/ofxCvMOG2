#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    cam.initGrabber(320,240);
    
    bDoIt = false;
    
    cout << "OpenCV version : " << CV_VERSION << endl;
    cout << "Major version : " << CV_MAJOR_VERSION << endl;
    cout << "Minor version : " << CV_MINOR_VERSION << endl;
    cout << "Subminor version : " << CV_SUBMINOR_VERSION << endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.update();
    if(bDoIt){
        mog2.update(ofxCv::toCv(cam));
        ofxCv::toOf(mog2.getForegroundMask(), imgFg);
        ofxCv::toOf(mog2.getShadowLessMask(), imgShadowLess);
        ofxCv::toOf(mog2.getShadowMask(), imgShadow);
        imgFg.update();
        imgShadowLess.update();
        imgShadow.update();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.draw(0, 0);
    if(bDoIt){
        imgFg.draw(320, 0);
        imgShadowLess.draw(0, 240);
        imgShadow.draw(320, 240);
    }
    ofPushStyle();
    ofSetColor(ofColor::red);
    ofDrawBitmapString("camera", 20, 20);
    ofDrawBitmapString("complete foreground", 340, 20);
    ofDrawBitmapString("shadowless", 20, 260);
    ofDrawBitmapString("shadows", 340, 260);
    ofDrawBitmapString("hit space to start/restart", 20, ofGetHeight()-30);
    ofPopStyle();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' '){
        if(bDoIt){
            mog2.reset();
        }
        bDoIt = true;
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
