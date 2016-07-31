//�����˲��������˲�����ֵ�˲�����˹�˲�
#include "functions.h"


Mat g_srcImage, g_dstImage1, g_dstImage2, g_dstImage3;   //�洢������
int g_nBoxFilterValue = 6;    //�����˲�Ĭ�ϲ���
int g_nMeanBlurValue = 6;    //��ֵ�˲�Ĭ�ϲ���
int g_nGaussianBlurValue = 6;    // ��˹�˲�Ĭ�ϲ���

//�����˲�
static void on_BoxFilter(int, void *)
{
	boxFilter(g_srcImage, g_dstImage1, -1, Size(g_nBoxFilterValue + 1, g_nBoxFilterValue + 1));
	imshow("��<1>�����˲���", g_dstImage1);
}

//��ֵ�˲�
static void on_MeanBlur(int, void *)
{
	blur(g_srcImage, g_dstImage2, Size(g_nMeanBlurValue + 1, g_nMeanBlurValue + 1), Point(-1, -1));
	imshow("��<2>��ֵ�˲���", g_dstImage2);
}

//��˹�˲�
static void on_GaussianBlur(int, void *)
{
	GaussianBlur(g_srcImage, g_dstImage3, Size(g_nGaussianBlurValue * 2 + 1, g_nGaussianBlurValue * 2 + 1), 0, 0);
	imshow("��<3>��˹�˲���", g_dstImage3);
}

//�����ܺ���
void LinearFilter()
{
	cout << "\n���������˲�����������pic.jpg\n" << endl;
	system("pause");
	//����ͼƬ
	g_srcImage = imread("pic.jpg", 1);
	if (!g_srcImage.data)       //��ȡ�ж�
	{
		cout << "��ȡ����\n";
		return;
	}
	//��������ԭͼ�������ַ�ʽ�Ĵ���
	g_dstImage1 = g_srcImage.clone();
	g_dstImage2 = g_srcImage.clone();
	g_dstImage3 = g_srcImage.clone();
	namedWindow("��<0>ԭͼ���ڡ�", 1);    //��������
	imshow("��<0>ԭͼ���ڡ�", g_srcImage);    //��ʾͼƬ

	namedWindow("��<1>�����˲���", 1);
	//�����켣��
	createTrackbar("�ں�ֵ��", "��<1>�����˲���", &g_nBoxFilterValue, 40, on_BoxFilter);
	on_MeanBlur(g_nBoxFilterValue, 0);

	namedWindow("��<2>��ֵ�˲���", 1);
	createTrackbar("�ں�ֵ��", "��<2>��ֵ�˲���", &g_nMeanBlurValue, 40, on_MeanBlur);
	on_MeanBlur(g_nMeanBlurValue, 0);

	namedWindow("��<3>��˹�˲���", 1);
	createTrackbar("�ں�ֵ��", "��<3>��˹�˲���", &g_nGaussianBlurValue, 40, on_GaussianBlur);
	on_GaussianBlur(g_nBoxFilterValue, 0);
	//esc�˳�
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}