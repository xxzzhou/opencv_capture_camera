//#include <stdlib.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace std;
//using namespace cv;
//
////���������ʵ������м���fps���岻�� 
////ֻ�ɴ��²��Գ�����ͷͼ�����㷨��ʱ������(ÿһ֡�Ĵ���ִ��ʱ��)
////ʹ��MFC����QT���ʱ���fps��������
////�����fps��ָ��Ϸ�е�ͼ��ˢ���� 
////�Ǻ�����Ϸ���ܵ�һ��ָ�ꡣ
//
//int main(int argc, const char** argv)
//{
//	cv::Mat frame;
//	// �ɴ�����ͷ������Ƶ����ֱ�Ӳ�����Ƶ�ļ�
//	/*cv::VideoCapture capture(0);*/
//
//	/*cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/
//	
//   VideoCapture capture;
//	 capture = VideoCapture(CV_CAP_DSHOW);	//ʹ��DirectShow
//	 capture.open(0);						//�����ҵ�USB����ͷ
//
//
//	int frameHeight =capture.get(CAP_PROP_FRAME_HEIGHT);
//	int frameWidth = capture.get(CAP_PROP_FRAME_WIDTH);
//	double frameFps = capture.get(CAP_PROP_FPS);
//	cout << "the video is:" << frameWidth <<  "*" <<  frameHeight << endl;
//	cout << "the video fps is :" << frameFps << endl;
//		
//	double fps;
//	char string[10];  // ֡���ַ���
//	cv::namedWindow("Camera FPS");
//	double t = 0;
//
//	while (1)
//	{
//		/*double start = (double)cv::getTickCount();*/
//		 double start = (double)cv::getTickCount();cout << "��ʼʱ�� " <<start << endl;
//		//if (cv::waitKey(1) == 1) { break; }
//		if (capture.isOpened())
//		{  
//			capture >> frame;
//			// getTickcount���������شӲ���ϵͳ��������ǰ�������ĺ�����
//			// getTickFrequency����������ÿ��ļ�ʱ������
//			// tΪ�ô�����ִ�����ĵ�ʱ��,��λΪ��,fpsΪ�䵹��
//			double end = (double)cv::getTickCount();
//			cout << "����ʱ��" << end << endl ;
//			t = (end - start)/ cv::getTickFrequency();
//			/*t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();*/
//		/*	cout << cv::getTickFrequency() << endl ; */
//			fps = 1.0 / t;
//			sprintf_s(string, "%.2f", fps);      // ֡�ʱ�����λС��
//			std::string fpsString("FPS:");
//			fpsString += string;                    // ��"FPS:"�����֡����ֵ�ַ���
//		/*	printf("fps: %.2f width:%d height:%d fps:%.2f\n", fps, frame.cols, frame.rows, capture.get(CV_CAP_PROP_FPS));*/
//			printf("fps: %.2f\n", fps); 
//			// ��֡����Ϣд�����֡��
//			cv::putText(frame, // ͼ�����
//				fpsString,                  // string����������
//				cv::Point(5, 20),           // �������꣬�����½�Ϊԭ��
//				cv::FONT_HERSHEY_SIMPLEX,   // ��������
//				0.5, // �����С
//				cv::Scalar(256, 0, 0));       // ������ɫ
//			cv::imshow("Camera FPS", frame);
//			char c = cv::waitKey(30);  //��ʱ30����
//									  // ע��waitKey��ʱԽ�� fpsԽ�� ������֡ ����ͷ��ʾ�俨
//			if (c == 27) //��ESC���˳�
//				break;
//		}
//		else
//		{
//			std::cout << "No Camera Input!" << std::endl;
//			break;
//		}
//	}
//}

//
////#include "opencv2/opencv.hpp"
////#include <time.h>
////
////using namespace cv;
////using namespace std;
////
////int main(int argc, char** argv)
////{
////	// Start default camera
////	VideoCapture video(0);
////
////	// With webcam get(CV_CAP_PROP_FPS) does not work.
////	// Let's see for ourselves.
////
////	double fps = video.get(CV_CAP_PROP_FPS);
////	// If you do not care about backward compatibility
////	// You can use the following instead for OpenCV 3
////	// double fps = video.get(CAP_PROP_FPS);
////	cout << "Frames per second using video.get(CV_CAP_PROP_FPS) : " << fps << endl;
////
////	// Number of frames to capture
////	int num_frames = 120;
////
////	// Start and end times
////	time_t start, end;
////
////	// Variable for storing video frames
////	Mat frame;
////
////	cout << "Capturing " << num_frames << " frames" << endl;
////
////	// Start time
////	time(&start);
////
////	// Grab a few frames
////	for (int i = 0; i < num_frames; i++)
////	{
////		video >> frame;
////	}
////
////	// End Time
////	time(&end);
////
////	// Time elapsed
////	double seconds = difftime(end, start);
////	cout << "Time taken : " << seconds << " seconds" << endl;
////
////	// Calculate frames per second
////	fps = num_frames / seconds;
////	cout << "Estimated frames per second : " << fps << endl;
////
////	// Release video
////	video.release();
////	system("pause");
////	return 0;
////}

/*
By longxiaoyue wunnnn@hotmail.com
ʹ��directshow�����Զ�ȡ100fps640*480��MJPGѹ����Ƶ,���ǲ��ܼ�����ʾ������ֻ�ܵ�60֡
����Ҫ�����Լ�������ͷ����Ч
�ŵ㣺�����������࣬���ϰ汾���㡣
���Ի���  i7 5557u vs2017  DebugX64 OpenCV3.3
*/


//#include <stdlib.h>
//#include <iostream>
//#include <opencv2/opencv.hpp> 
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace std;
//using namespace cv;
//
//
//int main()
//{
//	VideoCapture cap;
//	cap = VideoCapture(CV_CAP_DSHOW);	//ʹ��DirectShow
//	cap.open(1);						//�����ҵ�USB����ͷ
//	if (!cap.isOpened())
//		return -1;
//	cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));//����ΪMJPG��ʽ
//	cap.set(CV_CAP_PROP_FRAME_HEIGHT, 640);
//	cap.set(CV_CAP_PROP_FRAME_WIDTH, 480);
//	cv::TickMeter tm;
//	
//
//	while (1)
//	{
//
//		tm.reset();
//		tm.start();
//		Mat frame;
//		for (int i = 0; i < 100; i++)//Is not accuracy when I count once.
//		{
//			cap >> frame;
//			imshow("frame", frame);
//			if (waitKey(1) == 27);//ESC for quit
//		}
//		tm.stop();
//		cout << 100 / tm.getTimeSec() << "fps" << endl;//���֡��
//	}
//	return 0;
//}


#include <stdlib.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"

using namespace std;
using namespace cv;

//���������ʵ������м���fps���岻�� 
//ֻ�ɴ��²��Գ�����ͷͼ�����㷨��ʱ������(ÿһ֡�Ĵ���ִ��ʱ��)
//ʹ��MFC����QT���ʱ���fps��������
//�����fps��ָ��Ϸ�е�ͼ��ˢ���� 
//�Ǻ�����Ϸ���ܵ�һ��ָ�ꡣ


//���²��Գ���Ƶ�����㷨��ʱ������
//getTickCount()������CPU��ĳ��ʱ�䣨���������ԣ������߹���ʱ����������
//
//getTickFrequency()������CPUһ�������ߵ�ʱ�������������Կ�������Ϊ��λ��ĳ����ʱ���ʱ��

int main(int argc, const char** argv)
{       
	 cv::Mat frame;
	// �ɴ�����ͷ������Ƶ����ֱ�Ӳ�����Ƶ�ļ�
	/*cv::VideoCapture capture(0);*/
	/*cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/
	
	 VideoCapture capture;
	 capture = VideoCapture(CV_CAP_DSHOW);	//ʹ��DirectShow
	 capture.open(0);						//�����ҵ�USB����ͷ
     
	/* cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/

	int frameHeight =capture.get(CAP_PROP_FRAME_HEIGHT);
	int frameWidth = capture.get(CAP_PROP_FRAME_WIDTH);
	double frameFps = capture.get(CAP_PROP_FPS);
	cout << "the video is:" << frameWidth <<  "*" <<  frameHeight << endl;
	cout << "the video fps is :" << frameFps << endl;
		
	double fps = 0;
	char string[10];  // ֡���ַ���
	double t = 0;

	cv::namedWindow("Camera FPS");
	
	while (1)
	{   std::string fpsString("FPS:");
	     sprintf_s(string, "%.2f", fps);      // ֡�ʱ�����λС��
	     /*  std::string fpsString("FPS:");*/
		 fpsString += string;      
	    double start = (double)cv::getTickCount();    /*cout << "��ʼʱ�� " <<start << endl;*/
		for (int i = 0; i < 10; i++) //Is not accuracy when I count once.
		{
			    capture >> frame;
				
				
				cv::flip(frame, frame, 1);
				cv::putText( frame, // ͼ�����
					  fpsString,                  // string����������
					  cv::Point(5, 20),           // �������꣬�����½�Ϊԭ��
					  cv::FONT_HERSHEY_SIMPLEX,   // ��������
					  0.5, // �����С
					  cv::Scalar(0, 0, 0));       // ������ɫ              // ��"FPS:"�����֡����ֵ�ַ���
				imshow("Camera FPS", frame);
			    if (waitKey(5) == 27);//ESC for quit
		}
        double end = (double)cv::getTickCount();    /*cout << "����ʱ��" << end << endl;*/
		t = (end - start) / cv::getTickFrequency();
		t = t/10;     //һ֡�����ʱ��
		fps = 1.0 / t;
		cout << fps << endl;
		
	    /*printf("fps: %.2f\n", fps); 		*/
	}	
}

