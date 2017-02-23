//
//  ofxCvMOG2.h
//
//  Created by enrico<naus3a>viola on 2/23/17.
//
//

#pragma once
#include "ofMain.h"
#include "ofxCv.h"

class ofxCvMOG2{
public:
    ofxCvMOG2();
    void reset();
    void updateParams();
    void enableShadowDetection(bool b);
    void setNumMixtures(int n);
    inline void enableShadowMask(bool b){bSMask=b;}
    inline void enableShadowLessMask(bool b){bSLMask=b;}
    void update(cv::Mat frame);
    inline cv::Mat & getForegroundMask(){return fgMask;}
    inline cv::Mat & getShadowLessMask(){return shadowLessMask;}
    inline cv::Mat & getShadowMask(){return shadowMask;}
    inline bool isDetectingShadows(){return bShadow;}
    inline bool isComputingShadowMask(){return bSMask;}
    inline bool isComputingShadowLessMask(){return bSLMask;}
    inline int getNumMixtures(){return nMixtures;}
protected:
    inline void destroyMog2(){mog2.release();}
    
    cv::Ptr<cv::BackgroundSubtractor> mog2;
    cv::Mat fgMask;
    cv::Mat shadowMask;
    cv::Mat shadowLessMask;
    
    int nMixtures;
    bool bShadow;
    bool bSMask;
    bool bSLMask;
};