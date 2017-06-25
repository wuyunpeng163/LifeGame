/**
������Ϸ�㷨��ͷ�ļ�
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
	}//�ж�ϸ��״̬��"��"����"��",0Ϊ���ţ�255Ϊ��ȥ
	void ReFreshLife();//��������ϸ������
	void SetInitLifeModel(const cv::Mat & init_life_model,int init_x,int init_y);//���ó�ʼ����ģ��
	int CountNearbyLivingCell(int life_cell_x,int life_cell_y);//������Χ���ŵ�ϸ������
	cv::Mat m_LifeImage_;//����߽�
	int m_life_image_width_;//����ͼ�Ŀ��
	int m_life_image_height_;//����ͼ�ĸ߶�
};