
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//extern char testTimeTips[50]= {0};  //ȫ�����飬������Ų���ʱ���������
//extern char   recentTopic[40];
//extern int timeNum = 1;
//extern PSt headStudent = NULL,recentStudent = NULL;
//extern Te teachers[5];
//extern int tab=0; //������¼��ʦ���±����

#ifndef _MAIN_H
#define _MAIN_H
Te teachers[5];
char   recentTopic[40];
// char testTimeTips[50]= {0};  //ȫ�����飬������Ų���ʱ���������
// int timeNum = 1;
//PSt headStudent = NULL,recentStudent = NULL;
// int tab=0; //������¼��ʦ���±����
#endif

int main(int argc, char *argv[]) {


	system("COLOR f5");
	MessageBox(0, _T("��ӭʹ������С�������ϵͳ��(�R���Q)�ϣ�"), _T("����С���"), MB_OK);
	readStudentFile();//���ļ��ж�ȡѧ�����ݵ�������
	readTeacherFile();//���ļ��ж�ȡ���ݵ���ʦ�Ľṹ��������
	srand((unsigned)time(NULL));

	int role = login();
	if(role==1) {
		student();
	} else {
		teacher();
	}

	return 0;
}
