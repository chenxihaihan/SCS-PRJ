#include "functions.h"

//��������ͷ���ղ�����pic1.jpg
void PicShot()
{
	cout << "\n��������ͷ,���ղ��洢�����أ�pic1.jpg)\n" << endl;
	system("pause");
	VideoCapture capture(0);     //��������ͷ
	char key = 0;               //��������
	while (key != 27)
	{
		Mat frame;          
		capture >> frame;           //��¼ÿһ֡
		imshow("����ͷ����", frame);       //��ʾÿһ֡
		key = waitKey(1);
		if (key == 115)                   //��s���ղ�����
		{
			imwrite("pic1.jpg", frame);
			imshow("pic1.jpg", frame);
//			MessageBoxA(NULL, "pic1.jpg�ѱ���", "����ɹ�", MB_OK);
		}
	}
	destroyAllWindows();
}