/**
生命游戏算法类实现
**/
#include "LifeGameAlgorithm.h"
#include <iostream>

//设置初值，并令模型中心位置到指定的位置
void LifeGameAlgorithm::SetInitLifeModel(const cv::Mat & init_life_model,int init_x,int init_y)
{   
	int top_left_x = init_x-init_life_model.cols/2;
	int top_left_y = init_y-init_life_model.rows/2;
	assert(top_left_x >= 1 && top_left_x+init_life_model.cols <= m_life_image_width_);
    assert(top_left_y >= 1 && top_left_y+init_life_model.rows <= m_life_image_height_);
	
	for (int i = 0;i < init_life_model.rows;++i)
	{
		for(int j = 0;j < init_life_model.cols;++j)
		{
			m_LifeImage_.at<unsigned char>(top_left_y+i,top_left_x+j) = init_life_model.at<unsigned char>(i,j);
		}
	}
}

//更新生命细胞函数
void LifeGameAlgorithm::ReFreshLife()
{   
	int count = 0;
	while(true)
	{   
		cv::namedWindow("LifeGame",0);
		cv::imshow("LifeGame",m_LifeImage_);
		char ch = cv::waitKey(5);
		cv::Mat next_life_image(m_LifeImage_.rows,m_LifeImage_.cols,CV_8UC1,cv::Scalar(255));
		if (ch == 'q')
			break;
		for(int i = 1;i <= m_life_image_height_;++i)
		{
			for (int j = 1;j <= m_life_image_width_;++j)
			{
				int living_cell_numbers = CountNearbyLivingCell(j,i);
				if (living_cell_numbers == 3)
				{
					next_life_image.at<unsigned char>(i,j) = 0;
				}
				else if (living_cell_numbers == 2)
				{
					next_life_image.at<unsigned char>(i,j) = m_LifeImage_.at<unsigned char>(i,j);
				}
				else
					next_life_image.at<unsigned char>(i,j) = 255;
			}
		}
		m_LifeImage_ = next_life_image;
		std::cout << "模拟第" << ++count << "回合\n";
	}
}

//计算周围活着的细胞个数
int LifeGameAlgorithm::CountNearbyLivingCell(int life_cell_x,int life_cell_y)
{
	int living_cell_numbers = 0;
	for (int i = life_cell_y-1;i <= life_cell_y+1;++i)
	{
		for (int j = life_cell_x-1;j <= life_cell_x+1;++j)
		{
			if (i == life_cell_y && j == life_cell_x)
			{  
				continue;
			}
			else
			{
				if (IsLifeCellSafe(j,i))
					living_cell_numbers++;
			}
		}
	}
	return living_cell_numbers;
}