
#include "function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//extern char testTimeTips[50]= {0};  //全局数组，用来存放测试时间提醒语句
//extern char   recentTopic[40];
//extern int timeNum = 1;
//extern PSt headStudent = NULL,recentStudent = NULL;
//extern Te teachers[5];
//extern int tab=0; //用来记录老师的下标序号

#ifndef _MAIN_H
#define _MAIN_H
Te teachers[5];
char   recentTopic[40];
// char testTimeTips[50]= {0};  //全局数组，用来存放测试时间提醒语句
// int timeNum = 1;
//PSt headStudent = NULL,recentStudent = NULL;
// int tab=0; //用来记录老师的下标序号
#endif

int main(int argc, char *argv[]) {


	system("COLOR f5");
	MessageBox(0, _T("欢迎使用算数小天才养成系统Ｏ(≧▽≦)Ｏ！"), _T("算数小天才"), MB_OK);
	readStudentFile();//从文件中读取学生数据到链表中
	readTeacherFile();//从文件中读取数据到老师的结构体数组中
	srand((unsigned)time(NULL));

	int role = login();
	if(role==1) {
		student();
	} else {
		teacher();
	}

	return 0;
}
