#pragma once
#include "windows.h"
#include "opencv.hpp"
#include "core.hpp"
#include "imgproc.hpp"
#include "highgui.hpp"
#include "iostream"
using namespace std;
using namespace cv;

//��������ͷ���ղ�����pic1.jpg
void PicShot();
void PicAdj();
void PicProcessing();
void Painting();
void MixPics();
//�����˲�
void LinearFilter();