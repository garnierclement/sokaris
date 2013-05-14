//#include <cv.h>
//#include <highgui.h>  
//#include <stdio.h>
//#include <tchar.h>
//#include <windows.h>
//#include <iostream> 
//#include <istream> 
//#include <string>
//#include <opencv2/core/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <opencv2/highgui/highgui.hpp>
//
//#pragma comment( lib, "opencv_core245d.lib ")
//#pragma comment( lib, "opencv_highgui245d.lib" )
//
//
//using namespace cv;
//
//
//
//static CvHaarClassifierCascade* cascade = 0;
//static CvMemStorage* storage = 0;
//const char* cascade_name ="haarcascade_frontalface_alt.xml";
//void detect_and_draw( IplImage* img );
//void camera();
//void detectFaceCamera();
//
//
//
//int main(int argc, char** argv) {
//	camera();
//	detectFaceCamera();
//}
//
//void camera() {
//	cvNamedWindow("win");
//
//	CvCapture* capture = cvCreateCameraCapture(0);
//	IplImage* frame;
//
//	if(capture!=NULL){
//		while(1) {
//			frame = cvQueryFrame(capture);
//			if(!frame) break;
//
//			IplImage* out = cvCreateImage(cvGetSize(frame), frame->depth, 1);
//			cvCanny(frame, out, 10, 100, 3);
//			cvShowImage("win", out);
//			cvReleaseImage(&out);
//
//			char c = cvWaitKey(50);
//			if(c==27) break;
//		}
//
//	}
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("win");
//}
//
//void detect_and_draw( IplImage* img )
//{
//    static CvScalar colors[] = 
//    {
//        {{0,0,255}},
//        {{0,128,255}},
//        {{0,255,255}},
//        {{0,255,0}},
//        {{255,128,0}},
//        {{255,255,0}},
//        {{255,0,0}},
//        {{255,0,255}}
//    };
// 
//    double scale = 1.3;
//    IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
//    IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
//                         cvRound (img->height/scale)), 8, 1 );
// 
//    cvCvtColor( img, gray, CV_BGR2GRAY );
//    cvResize( gray, small_img, CV_INTER_LINEAR );
//    cvEqualizeHist( small_img, small_img );
//    cvClearMemStorage( storage );
// 
//    if( cascade )
//    {
//        /* function cvHaarDetectObjects( included in OpenCV) detects human face */
//        CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage, 1.1, 2, 0 ,
//                                            cvSize(30, 30) );
//        for( int i = 0; i < (faces ? faces->total : 0); i++ )
//        {
//            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
//            CvPoint center;
//            int radius;
//            center.x = cvRound((r->x + r->width*0.5)*scale);
//            center.y = cvRound((r->y + r->height*0.5)*scale);
//            radius = cvRound((r->width + r->height)*0.25*scale);
//            cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
//        }
//    }
// 
//    cvShowImage( "result", img );
//    cvReleaseImage( &gray );
//    cvReleaseImage( &small_img );
//}
//
//void detectFaceCamera() {
//	cvNamedWindow("win");
//
//	CvCapture* capture = cvCreateCameraCapture(0);
//	IplImage* frame;
//
//	if(capture!=NULL){
//		while(1) {
//			frame = cvQueryFrame(capture);
//			if(!frame) break;
//			detect_and_draw( frame ); 
//			char c = cvWaitKey(50);
//			if(c==27) break;
//		}
//
//	}
//	cvReleaseCapture(&capture);
//	cvDestroyWindow("win");
//}