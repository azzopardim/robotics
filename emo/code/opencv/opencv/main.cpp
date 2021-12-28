//
//  main.cpp
//  opencv
//
//  Created by Michael Azzopardi on 8/24/14.
//  Copyright (c) 2014 Creative Innovation. All rights reserved.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

int main(int argc, const char * argv[])
{
    CvCapture *capture = cvCaptureFromCAM( CV_CAP_ANY );
    IplImage *frame;
    
    cvNamedWindow("test");
    while((frame = cvQueryFrame(capture)))
    {
        cvShowImage("test", frame);
        int key = cvWaitKey(1);
        if(key == 27)
            break; //ESC key pressed
    }
    //Memory deallocation
    cvReleaseCapture(&capture);
    cvDestroyWindow("test");
    
    return 0;
}