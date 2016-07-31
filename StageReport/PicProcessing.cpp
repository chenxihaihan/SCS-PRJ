#include "functions.h" 

void PicProcessing()
{
	cout << "\nͼƬ������ʴ��ģ������Ե���\n" << endl;
	system("pause");
	Mat srcImage = imread("pic1.JPG");
	imshow("ͼ����ԭͼ��", srcImage);
	/*-----------------��ʴ����-------------------*/
	//����ָ����״�ͳߴ���ں˾���

	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
	Mat dsfImage;
	erode(srcImage, dsfImage, element);
	//��ʾ��ʴЧ��
	imshow("��ʴ��Ч��ͼ��", dsfImage);

	/*-----------------ģ������-------------------*/
	Mat dslImage;
	//���о�ֵ�˲�
	blur(srcImage, dslImage, Size(7, 7));
	//��ʾģ��Ч��
	imshow("ģ����Ч��ͼ��", dslImage);

	/*-----------------ģ������-------------------*/
	Mat dsbImage, edge, grayImge;
	dsbImage.create(srcImage.size(), srcImage.type());
	//ԭͼת�Ҷ�ͼ��
	cvtColor(srcImage, grayImge, CV_BGR2GRAY);
	//�����
	blur(grayImge, edge, Size(3, 3));
	//����Canny����
	Canny(edge, edge, 3, 9, 3);
	imshow("��Ե��⡾Ч��ͼ��", edge);
	while (char(waitKey(0) != 27))
	{
	}
	destroyAllWindows();
}
