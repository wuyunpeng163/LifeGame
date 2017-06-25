/**
生命游戏算法类头文件
**/
#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

class LifeGameAlgorithm{
public:
	LifeGameAlgorithm(int width,int height):m_LifeImage_(width+2,height+2,CV_8UC1,cv::Scalar(255)),m_life_image_width_(width),m_life_image_height_(height){
		
	};
	~LifeGameAlgorithm(){};
	inline void Run(cv::Mat init_life_model){
		//SetInitLifeModel(init_life_model,20,20);
		SetInitLifeModel(init_life_model,m_life_image_width_/2,m_life_image_height_/2);
	    //SetInitLifeModel(init_life_model,m_life_image_width_/2-20,m_life_image_height_/2-30);
		//SetInitLifeModel(init_life_model,m_life_image_width_/2+40,m_life_image_height_/2+50);
		ReFreshLife();
	}
private:
	bool IsLifeCellSafe(int life_cell_x,int life_cell_y){
		return m_LifeImage_.at<unsigned char>(life_cell_y,life_cell_x) == 0 ? true : false;
	}//判断细胞状态是"死"还是"活",0为活着，255为死去
	void ReFreshLife();//更新生命细胞函数
	void SetInitLifeModel(const cv::Mat & init_life_model,int init_x,int init_y);//设置初始生命模型
	int CountNearbyLivingCell(int life_cell_x,int life_cell_y);//计算周围活着的细胞个数
	cv::Mat m_LifeImage_;//扩充边界
	int m_life_image_width_;//生命图的宽度
	int m_life_image_height_;//生命图的高度
};