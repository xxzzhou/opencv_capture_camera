//#include <stdlib.h>
//#include <iostream>
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include "opencv2/imgproc/imgproc.hpp"
//
//using namespace std;
//using namespace cv;
//
////在下面给的实验代码中计算fps意义不大 
////只可大致测试出摄像头图像处理算法的时间消耗(每一帧的处理执行时间)
////使用MFC或者QT这个时候的fps才有意义
////这里的fps是指游戏中的图像刷新率 
////是衡量游戏性能的一个指标。
//
//int main(int argc, const char** argv)
//{
//	cv::Mat frame;
//	// 可从摄像头输入视频流或直接播放视频文件
//	/*cv::VideoCapture capture(0);*/
//
//	/*cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/
//	
//   VideoCapture capture;
//	 capture = VideoCapture(CV_CAP_DSHOW);	//使用DirectShow
//	 capture.open(0);						//这是我的USB摄像头
//
//
//	int frameHeight =capture.get(CAP_PROP_FRAME_HEIGHT);
//	int frameWidth = capture.get(CAP_PROP_FRAME_WIDTH);
//	double frameFps = capture.get(CAP_PROP_FPS);
//	cout << "the video is:" << frameWidth <<  "*" <<  frameHeight << endl;
//	cout << "the video fps is :" << frameFps << endl;
//		
//	double fps;
//	char string[10];  // 帧率字符串
//	cv::namedWindow("Camera FPS");
//	double t = 0;
//
//	while (1)
//	{
//		/*double start = (double)cv::getTickCount();*/
//		 double start = (double)cv::getTickCount();cout << "开始时间 " <<start << endl;
//		//if (cv::waitKey(1) == 1) { break; }
//		if (capture.isOpened())
//		{  
//			capture >> frame;
//			// getTickcount函数：返回从操作系统启动到当前所经过的毫秒数
//			// getTickFrequency函数：返回每秒的计时周期数
//			// t为该处代码执行所耗的时间,单位为秒,fps为其倒数
//			double end = (double)cv::getTickCount();
//			cout << "结束时间" << end << endl ;
//			t = (end - start)/ cv::getTickFrequency();
//			/*t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();*/
//		/*	cout << cv::getTickFrequency() << endl ; */
//			fps = 1.0 / t;
//			sprintf_s(string, "%.2f", fps);      // 帧率保留两位小数
//			std::string fpsString("FPS:");
//			fpsString += string;                    // 在"FPS:"后加入帧率数值字符串
//		/*	printf("fps: %.2f width:%d height:%d fps:%.2f\n", fps, frame.cols, frame.rows, capture.get(CV_CAP_PROP_FPS));*/
//			printf("fps: %.2f\n", fps); 
//			// 将帧率信息写在输出帧上
//			cv::putText(frame, // 图像矩阵
//				fpsString,                  // string型文字内容
//				cv::Point(5, 20),           // 文字坐标，以左下角为原点
//				cv::FONT_HERSHEY_SIMPLEX,   // 字体类型
//				0.5, // 字体大小
//				cv::Scalar(256, 0, 0));       // 字体颜色
//			cv::imshow("Camera FPS", frame);
//			char c = cv::waitKey(30);  //延时30毫秒
//									  // 注：waitKey延时越长 fps越大 出现跳帧 摄像头显示变卡
//			if (c == 27) //按ESC键退出
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
使用directshow，可以读取100fps640*480，MJPG压缩视频,但是不能加上显示，否则只能到60帧
设置要符合自己的摄像头才有效
优点：读出来的是类，比老版本方便。
测试环境  i7 5557u vs2017  DebugX64 OpenCV3.3
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
//	cap = VideoCapture(CV_CAP_DSHOW);	//使用DirectShow
//	cap.open(1);						//这是我的USB摄像头
//	if (!cap.isOpened())
//		return -1;
//	cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));//设置为MJPG格式
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
//		cout << 100 / tm.getTimeSec() << "fps" << endl;//输出帧率
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

//在下面给的实验代码中计算fps意义不大 
//只可大致测试出摄像头图像处理算法的时间消耗(每一帧的处理执行时间)
//使用MFC或者QT这个时候的fps才有意义
//这里的fps是指游戏中的图像刷新率 
//是衡量游戏性能的一个指标。


//大致测试出视频处理算法的时间消耗
//getTickCount()：返回CPU自某个时间（如启动电脑）以来走过的时钟周期数。
//
//getTickFrequency()：返回CPU一秒中所走的时钟周期数。所以可以以秒为单位对某运算时间计时。

int main(int argc, const char** argv)
{       
	 cv::Mat frame;
	// 可从摄像头输入视频流或直接播放视频文件
	/*cv::VideoCapture capture(0);*/
	/*cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/
	
	 VideoCapture capture;
	 capture = VideoCapture(CV_CAP_DSHOW);	//使用DirectShow
	 capture.open(0);						//这是我的USB摄像头
     
	/* cv::VideoCapture capture("C:/Users/16702/Desktop/WIN_20190926_09_37_13_Pro.avi");*/

	int frameHeight =capture.get(CAP_PROP_FRAME_HEIGHT);
	int frameWidth = capture.get(CAP_PROP_FRAME_WIDTH);
	double frameFps = capture.get(CAP_PROP_FPS);
	cout << "the video is:" << frameWidth <<  "*" <<  frameHeight << endl;
	cout << "the video fps is :" << frameFps << endl;
		
	double fps = 0;
	char string[10];  // 帧率字符串
	double t = 0;

	cv::namedWindow("Camera FPS");
	
	while (1)
	{   std::string fpsString("FPS:");
	     sprintf_s(string, "%.2f", fps);      // 帧率保留两位小数
	     /*  std::string fpsString("FPS:");*/
		 fpsString += string;      
	    double start = (double)cv::getTickCount();    /*cout << "开始时间 " <<start << endl;*/
		for (int i = 0; i < 10; i++) //Is not accuracy when I count once.
		{
			    capture >> frame;
				
				
				cv::flip(frame, frame, 1);
				cv::putText( frame, // 图像矩阵
					  fpsString,                  // string型文字内容
					  cv::Point(5, 20),           // 文字坐标，以左下角为原点
					  cv::FONT_HERSHEY_SIMPLEX,   // 字体类型
					  0.5, // 字体大小
					  cv::Scalar(0, 0, 0));       // 字体颜色              // 在"FPS:"后加入帧率数值字符串
				imshow("Camera FPS", frame);
			    if (waitKey(5) == 27);//ESC for quit
		}
        double end = (double)cv::getTickCount();    /*cout << "结束时间" << end << endl;*/
		t = (end - start) / cv::getTickFrequency();
		t = t/10;     //一帧所需的时间
		fps = 1.0 / t;
		cout << fps << endl;
		
	    /*printf("fps: %.2f\n", fps); 		*/
	}	
}

