////#include <cv.h>
////#include <highgui.h>  
////#include <stdio.h>
////#include <tchar.h>
////#include <windows.h>
////#include <iostream> 
////#include <istream> 
////#include <string>
////#include <opencv2/core/core.hpp>
////#include <opencv2/imgproc/imgproc.hpp>
////#include <opencv2/highgui/highgui.hpp>
////
////#pragma comment( lib, "opencv_core245d.lib ")
////#pragma comment( lib, "opencv_highgui245d.lib" )
////
////
////using namespace cv;
////
////void afficherText(){
////	
////	cvNamedWindow( "My Window", 1 );
////	IplImage *img = cvCreateImage( cvSize( 240, 120 ), IPL_DEPTH_8U, 1 );
////	CvFont font;
////	double hScale = 1.0;
////	double vScale = 1.0;
////	int lineWidth = 3;
////	cvInitFont( &font, CV_FONT_HERSHEY_SIMPLEX | CV_FONT_ITALIC,
////		hScale, vScale, 0, lineWidth );
////	cvPutText( img, "Hello World!", cvPoint( 20, 40 ), &font,
////		cvScalar( 255, 255, 0 ) );
////	cvShowImage( "My Window", img );
////	cvWaitKey();
////}
////
////void afficherImage(){
////	namedWindow( "show_image", WINDOW_AUTOSIZE );
////	Mat src = imread( "logo.png" );
////	imshow( "show_image", src );
////	char c = waitKey(0);
////}
////
////void afficherImage2(){
////	IplImage* img1 = cvLoadImage("logo.png");
////	cvNamedWindow( "Example2", CV_WINDOW_AUTOSIZE);
////	//namedWindow( "show_image", WINDOW_AUTOSIZE );
////	cvShowImage("Example2", img1);
////	cvWaitKey(0);
////	cvReleaseImage(&img1);
////	cvDestroyWindow("Example2");
////}
////
////void afficherAVI(){
////	char* avi = "demo.avi";
////	//char* avi = "C:\\Users\CMWT420-VM\Documents\Visual Studio 2012\Project1\Project1\demo.avi";
////	cvNamedWindow ("Example3", CV_WINDOW_AUTOSIZE);
////	CvCapture* capture = cvCreateFileCapture(avi);
////	IplImage* frame ;
////	while(1) {
////		frame = cvQueryFrame(capture);
////		if(!frame) break;
////		cvShowImage("Example3", frame);
////		char c = cvWaitKey(33);
////		if(c==27) break;
////	}
////	cvReleaseCapture(&capture);
////	cvDestroyWindow("Example3");
////}
////
////void afficherFlower(){
////	IplImage* image = cvLoadImage("flower.jpg");
////	cvNamedWindow("window-in");
////	cvShowImage("window-in", image);
////	cvNamedWindow("window-out");
////	IplImage* out = cvCreateImage(cvGetSize(image), IPL_DEPTH_8U, 3);
////	cvSmooth(image, out, CV_GAUSSIAN, 15, 15);
////	cvShowImage("window-out", out);
////
////	cvWaitKey(0);
////	cvReleaseImage(&out);
////	cvReleaseImage(&image);
////	cvDestroyWindow("window-in");
////	cvDestroyWindow("window-out");
////}
////
////void camera() {
////	cvNamedWindow("win");
////
////	CvCapture* capture = cvCreateCameraCapture(0);
////	IplImage* frame;
////
////	if(capture!=NULL){
////		while(1) {
////			frame = cvQueryFrame(capture);
////			if(!frame) break;
////			cvShowImage("win", frame);
////			char c = cvWaitKey(50);
////			if(c==27) break;
////		}
////
////	}
////	cvReleaseCapture(&capture);
////	cvDestroyWindow("win");
////}
////
////void camera2() {
////	cvNamedWindow("win");
////
////	CvCapture* capture = cvCreateCameraCapture(0);
////	IplImage* frame;
////
////	if(capture!=NULL){
////		while(1) {
////			frame = cvQueryFrame(capture);
////			if(!frame) break;
////
////			IplImage* out = cvCreateImage(cvGetSize(frame), frame->depth, 1);
////			cvCanny(frame, out, 10, 100, 3);
////			cvShowImage("win", out);
////			cvReleaseImage(&out);
////
////			char c = cvWaitKey(50);
////			if(c==27) break;
////		}
////
////	}
////	cvReleaseCapture(&capture);
////	cvDestroyWindow("win");
////}
////
////static CvHaarClassifierCascade* cascade = 0;
////static CvMemStorage* storage = 0;
////const char* cascade_name ="haarcascade_frontalface_alt.xml";
////
////void detect_and_draw( IplImage* img )
////{
////    static CvScalar colors[] = 
////    {
////        {{0,0,255}},
////        {{0,128,255}},
////        {{0,255,255}},
////        {{0,255,0}},
////        {{255,128,0}},
////        {{255,255,0}},
////        {{255,0,0}},
////        {{255,0,255}}
////    };
//// 
////    double scale = 1.3;
////    IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
////    IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
////                         cvRound (img->height/scale)), 8, 1 );
//// 
////    cvCvtColor( img, gray, CV_BGR2GRAY );
////    cvResize( gray, small_img, CV_INTER_LINEAR );
////    cvEqualizeHist( small_img, small_img );
////    cvClearMemStorage( storage );
//// 
////    if( cascade )
////    {
////        /* function cvHaarDetectObjects( included in OpenCV) detects human face */
////        CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage, 1.1, 2, 0 ,
////                                            cvSize(30, 30) );
////        for( int i = 0; i < (faces ? faces->total : 0); i++ )
////        {
////            CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
////            CvPoint center;
////            int radius;
////            center.x = cvRound((r->x + r->width*0.5)*scale);
////            center.y = cvRound((r->y + r->height*0.5)*scale);
////            radius = cvRound((r->width + r->height)*0.25*scale);
////            cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
////        }
////    }
//// 
////    cvShowImage( "result", img );
////    cvReleaseImage( &gray );
////    cvReleaseImage( &small_img );
////}
////
////void detectFace(const char* filename)
////{
////     cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );   //Load Classifier
////     if( !cascade )
////     {
////        fprintf( stderr, "ERROR: Could not load classifier cascade\n" );
////		exit(-1);
////     }
////     storage = cvCreateMemStorage(0);                                       //Dynamic storage structure which stores the position of human face in picture
////     cvNamedWindow( "result", 1 );
////     IplImage* image = cvLoadImage( filename, 1 );                          //load image
////     detect_and_draw( image );                                              //process
////     cvWaitKey(0);
////     cvReleaseImage( &image );
////     cvDestroyWindow("result");
////}
////
////
////void detectFaceCamera() {
////	cvNamedWindow("win");
////
////	CvCapture* capture = cvCreateCameraCapture(0);
////	IplImage* frame;
////
////	if(capture!=NULL){
////		while(1) {
////			frame = cvQueryFrame(capture);
////			if(!frame) break;
////			detect_and_draw( frame ); 
////			char c = cvWaitKey(50);
////			if(c==27) break;
////		}
////
////	}
////	cvReleaseCapture(&capture);
////	cvDestroyWindow("win");
////}
////
////int main(int argc, char** argv) {
////	//afficherText();
////	//afficherImage();
////	//afficherImage2();
////	//afficherAVI();
////	////afficherFlower();
////	//camera();
////	//camera2();
////	//detectFace("face2.jpg");
////	////detectFaceCamera();
////}
//
//
//
//
//
//
//#include "cv.h"
//#include "highgui.h"
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/core/core.hpp>
//#include <opencv2/gpu/gpu.hpp>
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//using namespace cv;
//
//static CvMemStorage* storage = 0;
//static CvHaarClassifierCascade* cascade = 0;
//
//void detect_and_draw( IplImage* image );
//
//const char* cascade_name = "D:\\DEV\\lib\\opencv\\data\\haarcascades\\haarcascade_frontalface_alt.xml";
//
//int main( int argc, char** argv )
//{
//	CvCapture* capture = 0;
//	IplImage *frame, *frame_copy = 0;
//
//	cascade = (CvHaarClassifierCascade*)cvLoad( cascade_name, 0, 0, 0 );
//
//	if( !cascade )
//	{
//		fprintf( stderr, "ERROR: Could not load classifier cascade\n" );
//		//return -1;
//	}
//	storage = cvCreateMemStorage(0);
//
//	capture = cvCaptureFromCAM(0);
//	cvNamedWindow( "result", 1 );
//	for(;;)
//	{
//		if( !cvGrabFrame( capture ))
//			break;
//		frame = cvRetrieveFrame( capture );
//		if( !frame )
//			break;
//		if( !frame_copy )
//			frame_copy = cvCreateImage( cvSize(frame->width,frame->height),
//			IPL_DEPTH_8U, frame->nChannels );
//		if( frame->origin == IPL_ORIGIN_TL )
//			cvCopy( frame, frame_copy, 0 );
//		else
//			cvFlip( frame, frame_copy, 0 );
//
//		detect_and_draw( frame_copy );
//
//		if( cvWaitKey( 10 ) >= 0 )
//			break;
//	}
//	cvReleaseImage( &frame_copy );
//	cvReleaseCapture( &capture );
//
//	/* For a file .avi*/
//	/*capture = cvCaptureFromAVI( "demo.avi" ); 
//	cvNamedWindow( "result", 1 );
//	for(;;)
//	{
//		if( !cvGrabFrame( capture ))
//			break;
//		frame = cvRetrieveFrame( capture );
//		if( !frame )
//			break;
//		if( !frame_copy )
//			frame_copy = cvCreateImage( cvSize(frame->width,frame->height),
//			IPL_DEPTH_8U, frame->nChannels );
//		if( frame->origin == IPL_ORIGIN_TL )
//			cvCopy( frame, frame_copy, 0 );
//		else
//			cvFlip( frame, frame_copy, 0 );
//
//		detect_and_draw( frame_copy );
//
//		if( cvWaitKey( 10 ) >= 0 )
//			break;
//	}
//	cvReleaseImage( &frame_copy );
//	cvReleaseCapture( &capture );*/
//
//	
//	cvReleaseHaarClassifierCascade( &cascade );
//	cvDestroyWindow("result");
//
//return 0;
//}
//
//void detect_and_draw( IplImage* img )
//{
//	static CvScalar colors[] = 
//	{
//		{{0,0,255}},
//		{{0,128,255}},
//		{{0,255,255}},
//		{{0,255,0}},
//		{{255,128,0}},
//		{{255,255,0}},
//		{{255,0,0}},
//		{{255,0,255}}
//	};
//
//	double scale = 1.3;
//	IplImage* gray = cvCreateImage( cvSize(img->width,img->height), 8, 1 );
//	IplImage* small_img = cvCreateImage( cvSize( cvRound (img->width/scale),
//		cvRound (img->height/scale)),
//		8, 1 );
//	int i;
//
//	cvCvtColor( img, gray, CV_BGR2GRAY );
//	cvResize( gray, small_img, CV_INTER_LINEAR );
//	cvEqualizeHist( small_img, small_img );
//	cvClearMemStorage( storage );
//
//	if( cascade )
//	{
//		double t = (double)cvGetTickCount();
//		CvSeq* faces = cvHaarDetectObjects( small_img, cascade, storage,
//			1.1, 2, 0/*CV_HAAR_DO_CANNY_PRUNING*/,
//			cvSize(30, 30) );
//		t = (double)cvGetTickCount() - t;
//		printf( "detection time = %gms\n", t/((double)cvGetTickFrequency()*1000.) );
//		for( i = 0; i < (faces ? faces->total : 0); i++ )
//		{
//			CvRect* r = (CvRect*)cvGetSeqElem( faces, i );
//			CvPoint center;
//			int radius;
//			center.x = cvRound((r->x + r->width*0.5)*scale);
//			center.y = cvRound((r->y + r->height*0.5)*scale);
//			radius = cvRound((r->width + r->height)*0.25*scale);
//			cvCircle( img, center, radius, colors[i%8], 3, 8, 0 );
//		}
//	}
//
//	cvShowImage( "result", img );
//	cvReleaseImage( &gray );
//	cvReleaseImage( &small_img );
//}