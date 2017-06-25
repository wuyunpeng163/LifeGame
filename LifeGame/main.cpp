/**
生命游戏测试源文件
**/
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "LifeGameAlgorithm.h"
int main()
{ 
	//测试使用的初值是"高斯帕滑翔机枪模板
	cv::Mat init_model(9,36,CV_8UC1,cv::Scalar(255));
	init_model.at<unsigned char>(0,24) = 0;

    init_model.at<unsigned char>(1,24) = 0;
	init_model.at<unsigned char>(1,22) = 0;
	
	init_model.at<unsigned char>(2,12) = 0;
	init_model.at<unsigned char>(2,13) = 0;
	init_model.at<unsigned char>(2,20) = 0;
	init_model.at<unsigned char>(2,21) = 0;
	init_model.at<unsigned char>(2,35) = 0;
	init_model.at<unsigned char>(2,34) = 0;

	init_model.at<unsigned char>(3,11) = 0;
	init_model.at<unsigned char>(3,15) = 0;
	init_model.at<unsigned char>(3,20) = 0;
	init_model.at<unsigned char>(3,21) = 0;
	init_model.at<unsigned char>(3,35) = 0;
	init_model.at<unsigned char>(3,34) = 0;

	init_model.at<unsigned char>(4,0) = 0;
	init_model.at<unsigned char>(4,1) = 0;
	init_model.at<unsigned char>(4,10) = 0;
	init_model.at<unsigned char>(4,16) = 0;
	init_model.at<unsigned char>(4,20) = 0;
	init_model.at<unsigned char>(4,21) = 0;

	init_model.at<unsigned char>(5,0) = 0;
	init_model.at<unsigned char>(5,1) = 0;
	init_model.at<unsigned char>(5,10) = 0;
	init_model.at<unsigned char>(5,14) = 0;
	init_model.at<unsigned char>(5,16) = 0;
	init_model.at<unsigned char>(5,17) = 0;
	init_model.at<unsigned char>(5,22) = 0;
	init_model.at<unsigned char>(5,24) = 0;

	init_model.at<unsigned char>(6,10) = 0;
	init_model.at<unsigned char>(6,16) = 0;
	init_model.at<unsigned char>(6,24) = 0;

	init_model.at<unsigned char>(7,11) = 0;
	init_model.at<unsigned char>(7,15) = 0;

	init_model.at<unsigned char>(8,12) = 0;
	init_model.at<unsigned char>(8,13) = 0;
	LifeGameAlgorithm LifeGame(221,221);
	LifeGame.Run(init_model);
	
}