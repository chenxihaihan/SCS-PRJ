//ͼƬ����
#include "functions.h"

//ROI����ͼ�����
void MixPics() 
{
	cout << "\nͼƬ����\n" << endl;
	system("pause");
	//��ȡͼ��pic1��pic2;
	Mat Pic_01 = imread("pic1.jpg");
	Mat Pic_02 = imread("pic2.jpg");
	//�ж϶�ȡͼƬ�Ƿ�ɹ�;
	if (!Pic_01.data) { printf("��ȡͼ��pic1ʧ��"); return; }
	if (!Pic_02.data) { printf("��ȡͼ��pic2ʧ��"); return; }
	//����һ��Mat���͸����趨ROI����;
	//poc2���ӵ�pic1��λ�ÿ�ͨ������Rect()�����еĲ�����������;
	Mat dstROI = Pic_01(Rect(10, 10, Pic_02.cols, Pic_02.rows));
	//������Ĥ
	Mat mask = imread("pic2.png", 0);
	//����Ĥ���Ƶ�dstROI;
	Pic_02.copyTo(dstROI, mask);
	//��ʾ���Ӻ��ͼ��;
	namedWindow("pic1��pic2��Ϻ��ͼ��");
	imshow("pic1��pic2��Ϻ��ͼ��", Pic_01);
	//������Ӻ��ͼƬ����Ϊpic.jpg
	imwrite("pic.jpg", Pic_01);
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}


