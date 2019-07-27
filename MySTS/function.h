

#ifndef _FUNCTION_H
#define _FUNCTION_H


#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <tchar.h>
#include <pthread.h>




typedef struct student {
	char name[20];
	char id[10];
	char pin[20];
	double plusCorrect;
	int  plusNum;
	double  minusCorrect;
	int  minusNum;
	double  multiplyCorrect;
	int   multiplyNum;
	double divideCorrect;
	int   divideNum;
	double  testGrade;
	int   testNum;
	char mistakeFileName[70];
	int   mistakeNum;
	int    gameLevel;
	int    gameNum;
	int   grade[20];
	char  comment[70];
	struct student*  next;
} St,*PSt;
typedef struct teacher {
	char name[20];
	char id[10];
	char pin[20];
} Te;





void student();
int login();
char* password();
void menuS();
////
int getMin(int a,int b);
int maxDivisor(int a,int b);
void simplify(int* up,int* down);
void * timer(void *a);
void subMultiplyForFraction(int firstUp,int firstDown,int secondUp,int secondDown,int* answerUp,int* answerDown);
void subPlusForFraction(int firstUp,int firstDown,int secondUp,int secondDown,int* answerUp,int* answerDown);

////
void plus();
int plusDemo(int difficulty);
void minus();
int minusDemo(int difficulty);
void multiply();
int multiplyDemo(int difficulty);
void divide();
int divideDemo(int difficulty);
void comTest();
void game();
void modifyPin(int role);
void test();
void printMistake();
void viewGrade();
void evaluation();
void teacher();
void menuT();
void rank();
void manage();
void checkStudent();
void addStudent();
void deleteStudent();
void modifyStudent();
void evaluate();
void readStudentFile();
void readTeacherFile();
void saveTeacherFile();
void saveStudentFile();
///////////////////void traverse(char x[10],int role);
void solution(int result);
void addMistake(char x[20]);
void judge(double n,int right,int num);
void menuS_base();
void menuS_inquiry();
PSt traverse(char id[10], PSt pHead);
void outStudent();
void outTeacher();
void menuT_manage();
void sortForArray(double a[],int n);
int sumOfStu();
void printNameAndId(double n);
int comTestDemo(int part,int difficulty);


#endif


