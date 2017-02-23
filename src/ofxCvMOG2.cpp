//
//  ofxCvMOG2.h
//
//  Created by enrico<naus3a>viola on 2/23/17.
//
//

#include "ofxCvMOG2.h"

ofxCvMOG2::ofxCvMOG2(){
    bShadow = true;
    bSMask = true;
    bSLMask = true;
    nMixtures = 3;
    mog2 = new cv::BackgroundSubtractorMOG2();
    updateParams();
}

void ofxCvMOG2::enableShadowDetection(bool b){
    bShadow = b;
    if(bShadow){
        mog2->set("detectShadows",1);
    }else{
        bSMask = false;
        bSLMask= false;
    }
}

void ofxCvMOG2::setNumMixtures(int n){
    nMixtures = n;
    mog2->set("nmixtures", nMixtures);
}

void ofxCvMOG2::updateParams(){
    mog2->set("nmixtures", nMixtures);
    if(bShadow)mog2->set("detectShadows",1);
}

void ofxCvMOG2::reset(){
    destroyMog2();
    mog2 = new cv::BackgroundSubtractorMOG2();
    updateParams();
}

void ofxCvMOG2::update(cv::Mat frame){
    mog2->operator()(frame, fgMask);
    if(bShadow){
        if(bSLMask){
            ofxCv::threshold(fgMask, shadowLessMask, 254);
        }
        if(bSMask){
            cv::inRange(fgMask, cv::Scalar(1),cv::Scalar(250),shadowMask);
        }
    }
}