#include "function.h"

//����ѧ��ģ��
void student() {
	pthread_t th1;
	int tmp=1800;   //�����ʼ�����߳����ڼ�ʱ����Ϊ��Сʱ��
	pthread_create(&th1, NULL, timer, &tmp);
	system("title ����ѧ����");
	system("cls");
	system("COLOR fc");
	printf("\t\t\t\t\t\t�q  ��  ��  ��  �r\n");
	printf("\t\t\t\t\t\t   ��¼�ɹ���  \n");
	printf("\t\t\t\t\t\t�t  ��  ��  ��  �s\n");
	puts("");
	puts("");
	printf("\n\t\t*=*=*=*=*=*=         Hello��%7sͬѧ----��ӭ��������С���ϵͳ       =*=*=*=*=*\n", recentStudent->name);
	puts("");
	printf("\t\t************\t\t��������һ����������ð�գ�����ѧ�԰�[]~(�䨌`)~*\t\t**********\n");
	menuS();

}

char* password() {
	int k=0;
	char pin[20];
	while ((pin[k] = getch()) != '\r') {
		if((pin[k]=='\b')&&(k==0)) {
			//��ֹɾ��printf�����ʾ
		} else if(pin[k]=='\b') {
			putch('\b'); //������Ƶ�*֮ǰ
			putch(' '); // �ÿո񸲸�*
			putch('\b'); // ������Ƶ��ո�֮ǰ
			k--;
		} else {
			putch ('*');
			k++;
		}
	}
	pin[k] = '\0';
	return pin;

}


//��ɵ�½��ע�Ṧ��
//����ֵΪ1����ѧ��ģ��
//����ֵΪ0������ʦģ��
int login() {
	system("title ��¼ע��ҳ");

	system("cls");
	system("COLOR f5");
	int role;
	printf("\n\n\n\n\n");

	printf("\t\t\t\t      �x�x�y�z�{�|�}�~���~�}�|�{�z�y�x�x\n");


	printf("\t\t\t\t\t�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ��\n");
	printf("\t\t\t\t\t��                          ��\n");
	printf("\t\t\t\t\t��        (�š񩤡�)��       ��\n");
	printf("\t\t\t\t\t�� ����������С�������ϵͳ ��\n");
	printf("\t\t\t\t\t��                          ��\n");

	printf("\t\t\t\t\t�� \t��ѡ���������:     ��\n");
	printf("\t\t\t\t\t�� \t  1 - ѧ��\t    ��\n");
	printf("\t\t\t\t\t�� \t  2 - ��ʦ\t    ��\n");
	printf("\t\t\t\t\t��                          ��\n");
	printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n");
	printf("\t\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n");

	printf("\n");
	printf("\t\t\t\t\t��ѡ��");

	do {
		role = getch();
		role-=48;
	} while (role != 1 && role != 2);
	putch(role+=48);
	role-=48;
	puts("");//���������


	if(role==1) {

		system("cls");
		printf("\n\n\n\t������ת��ѧ��ҳ��....");
		Sleep(1200);
		system("cls");
		char id[10]="\0";
		char pin[20]="\0";
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t  ���¼\n\n");
		printf("\t\t\t\t\t  �������˺�:");
		scanf("%s",id);
		while(strlen(id)>10) {
			printf("\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������\n");
			scanf("%s",id);
		}
		printf("\n\t\t\t\t\t  ����������:");
		strcpy(pin,password());
		while((strlen(pin)<6)||(strlen(pin)>20)) {
			printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
			strcpy(pin,password());
		}
		int judge=0;//�ж��Ƿ��ҵ����˻���Ӧ�û�
		//��������Ѱ�Ҹ��û����ж��������˺��Ƿ�ƥ��
		for(PSt p=headStudent->next; p!=NULL; p=p->next) {
			if((strcmp(p->id,id)==0)&&(strcmp(p->pin,pin)==0)) {
				recentStudent = p;
				judge = 1;
				return 1;
			}
		}
		if(judge==0) {
			printf("\n\n\t\t\t\t\t  �˺Ų����ڻ����˺��������Ӧ����\n");
			sleep(1);
			login();
		}
	}//end if(role==1)
	else if(role==2) {
		system("cls");
		printf("\n\n\n\t������ת���ʦҳ��....");
		Sleep(1200);
		system("cls");


		int choice;
		printf("\n\n\n\n\n");

		printf("\t\t\t\t      �x�x�y�z�{�|�}�~���~�}�|�{�z�y�x�x\n");


		printf("\t\t\t\t\t�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ��\n");
		printf("\t\t\t\t\t��                          ��\n");
		printf("\t\t\t\t\t��        (�š񩤡�)��       ��\n");
		printf("\t\t\t\t\t�� ����������С�������ϵͳ ��\n");
		printf("\t\t\t\t\t��                          ��\n");

		printf("\t\t\t\t\t�� \t��ѡ�����Ĳ���:     ��\n");
		printf("\t\t\t\t\t�� \t  1 - ��¼\t    ��\n");
		printf("\t\t\t\t\t�� \t  2 - ע��\t    ��\n");
		printf("\t\t\t\t\t��                          ��\n");
		printf("\t\t\t\t\t��ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�ߡ�\n");
		printf("\t\t\t\t\t�x�x�x�x�x�x�x�x�x�x�x�x�x�x�x\n");

		printf("\n");
		printf("\t\t\t\t\t��ѡ��");

		do {
			choice = getch();
			choice-=48;
		} while (choice != 1 && choice != 2);
		putch(choice+=48);
		choice-=48;
		puts("");//��������������

		if(choice ==1) {
			system("cls");
			char id[10]="\0";
			char pin[20]="\0";
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t  ���¼\n");
			printf("\n\t\t\t\t\t  �������˺�:");
			scanf("%s",id);
			while(strlen(id)>10) {
				printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
				scanf("%s",id);
			}
			printf("\n\t\t\t\t\t  ����������:");
			strcpy(pin,password());
			while((strlen(pin)<6)||(strlen(pin)>20)) {
				printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
				strcpy(pin,password());
			}
			int judge=0;//�ж��Ƿ��ҵ����˻���Ӧ�û�
			//�����ṹ�������ж���ʦ���˺������Ƿ�ƥ��
			for(int i=0; strcmp(teachers[i].name,"")!=0; i++) {
				if((strcmp(teachers[i].id,id)==0)&&(strcmp(teachers[i].pin,pin)==0)) {
					tab = i;
					judge = 1;
				}
			}
			if(judge==0) {
				printf("\n\n\t\t\t\t\t  �˺Ų����ڻ����˺��������Ӧ����\n");
				login();
			}
		}//ioce1-��¼
		else if(choice==2) {
			int i;
			system("cls");
			printf("\n\n\n");
			printf("\n\n\t\t\t\t\t  ��������Կ:");
			char secret[10];
			strcpy(secret,password());
			while(strlen(secret)>6) {
				printf("\n\n\t\t\t\t\t  �����ַ����ȹ���������������:");
				strcpy(secret,password());
			}
			if(strcmp(secret,"123abc")!=0) {
				printf("\n\n\t\t\t\t\t  ��Կ��֤ʧ��\n");
				sleep(1);
				login();
			}
			system("cls");
			char id[10]="\0";
			char pin[20]="\0";
			char name[20] = "\0";
			printf("\n\n\n\t\t\t\t\t  ��ע��\n");
			printf("\n\t\t\t\t\t  �������û���:");
			scanf("%s",name);
			while(strlen(name)>20) {
				printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
				scanf("%s",name);
			}
			printf("\n\t\t\t\t\t  �������˺�:");
			scanf("%s",id);
			while(strlen(id)>10) {
				printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
				scanf("%s",id);
			}
			printf("\n\t\t\t\t\t  ����������:");
			strcpy(pin,password());
			while((strlen(pin)<6)||(strlen(pin)>20)) {
				printf("\n\n\t\t\t\t\t  �����ַ����Ȳ���ȷ������������:");
				strcpy(pin,password());
			}
			int n=0;
			while(strcmp(teachers[n].name,"")!=0) {
				n++;
			}
			strcpy(teachers[n].name,name);
			strcpy(teachers[n].id,id);
			strcpy(teachers[n].pin,pin);
			system("cls");
			printf("\n\n\n\t\t\t\t\t  ע��ɹ�!\n");
			sleep(1);
			login();

		}//end if choice==2
		return 0;
	}//end if role==2

}



//չʾѧ��ҳ��˵����������벢������Ӧ����
void menuS() {


	while(1) {

		system("COLOR fc");
		system("title ѧ�������˵�");
		//bool inputError = false;  //����û��Ƿ������˷���Ч���
		printf("\n\n\t\t\t\t       ==========�����ʹ�����¹��ܣ�==========\n\n");
		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");
		printf("\t\t\t\t\t   ��\t --1-��������\t  ��\n\n");
		printf("\t\t\t\t\t   \t --2-�ۺϲ���\n\n");
		printf("\t\t\t\t\t   ��\t --3-��Ϸģʽ	  ��\n\n");
		printf("\t\t\t\t\t   \t --4-С�� \n\n");
		printf("\t\t\t\t\t   ��\t --5-��ѯ	  ��\n\n");
		printf("\t\t\t\t\t   \t --6-�޸�����\n\n");
		printf("\t\t\t\t\t   ��\t --0-�˳�	  ��\n\n");
		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");

		printf("\t\t������ѡ��Ҫʹ���ĸ����ܰ�(*��U`*):");

		int choice = 0;
		int option1;
		do {
			option1 = getch();
			option1-=48;
		} while ( option1 != 1 && option1 != 2 &&option1!=3 && option1!=4
		          && option1!=5 &&option1!=6&&option1!=0);
		putch(option1+=48);
		option1-=48;
		puts("");
		choice = option1;//��������������


		//do { //ʹ��ѭ����Ҫ��Ϊ�˽��default�����
		switch (choice) {
			case 1:
				menuS_base();
				break;
			case 2:
				comTest();
				break;
			case 3:
				game();
				break;
			case 4:
				test();
				break;
			case 5:
				menuS_inquiry();
				break;
			case 6:
				modifyPin(1);
				break;
			case 0:
				outStudent();
				break;
		}
		//} while (inputError);
	}

}

//չʾ��������Ĳ˵����������벢������Ӧ����
void menuS_base() {
	system("title ѧ����---��������ҳ");
	int time = 0;

	while (1) {
		system("COLOR b0");
		system("cls");
		if (time == 0) {
			printf("\n\n\t\t\t\t\t   ��ӭ�����������԰��c(�Rv�Q)��\n");
			printf("\n\n\t\t\t\t\t����������Խ��мӼ��˳��ĵ������Ŷ��\n\n");
			time++;
		} else {
			printf("\n\n\t\t\t\t\t      ===��Ҫ������ս��===\n\n");
		}

		printf("\t\t\t\t\t    ������  ����  ����  ����  ����  ������\n\n\n");
		printf("\t\t\t\t\t    ��\t --1-�ӷ��Բ�\t   ��\n\n");
		printf("\t\t\t\t\t    \t --2-�����Բ�\n\n");
		printf("\t\t\t\t\t    ��\t --3-�˷��Բ�	   ��\n\n");
		printf("\t\t\t\t\t    \t --4-�����Բ� \n\n");
		printf("\t\t\t\t\t    ��\t --0-�������˵�	   ��\n\n");
		printf("\t\t\t\t\t    ������  ����  ����  ����  ����  ������\n\n");

		printf("\t\t����ѡ����Ҫʹ�õĹ��ܰ�(~*v*~):");
		int choice = 0;

		int option1;
		do {
			option1 = getch();
			option1-=48;
		} while ( option1 != 1 && option1 != 2 &&option1!=3 && option1!=4 &&
		          option1!=0);
		putch(option1+=48);
		option1-=48;
		puts("");
		choice = option1;//��������������


		switch (choice) {
			case 1:
				plus();
				break;
			case 2:
				minus();
				break;
			case 3:
				multiply();
				break;
			case 4:
				divide();
				break;
			case 0:
				system("cls");
				menuS();
				break;
		}


	}
}

//չʾѧ����ѯ��Ϣ�Ĳ˵����������벢������Ӧ����
void menuS_inquiry() {
	system("title ѧ����---��Ϣ��ѯҳ");
	system("cls");
	int time = 0;

	while (1) {
		system("cls");
		system("COLOR 60");
		if (time == 0) {
			printf("\n\n\t\t\t\t\t    ��ӭ������ѯ���c(�Rv�Q)��\n");
			printf("\n\n\t\t\t\t\t����������Բ鿴�Լ��ĸ��ּ�¼Ŷ��\n\n");
			time++;
		} else {
			printf("\n\n\t\t\t\t\t     ===�������������===\n\n");
		}

		printf("\t\t\t\t\t    ������  ����  ����  ����  ����  ������\n\n");
		printf("\t\t\t\t\t    ��\t --1-�鿴���Ȿ\t   ��\n\n");
		printf("\t\t\t\t\t    \t --2-�鿴�ɼ���¼\n\n");
		printf("\t\t\t\t\t    ��\t --3-�鿴��ʦ����  ��\n\n");
		printf("\t\t\t\t\t    ��\t --0-�������˵�	   ��\n\n");
		printf("\t\t\t\t\t    ������  ����  ����  ����  ����  ������\n\n");

		printf("\t\t����ѡ����Ҫʹ�õĹ��ܰ�(~*v*~):");
		int choice = 0;

		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0);
		putch(choice+=48);
		choice-=48;
		puts("");//��������������


		switch (choice) {
			case 1:
				printMistake();
				break;
			case 2:
				viewGrade();
				break;
			case 3:
				evaluation();
				break;
			case 0:
				system("cls");
				menuS();
				break;
		}


		//��ֹ��ֱ�����������
		printf("\n\t\tTip:������������ϼ��˵�Ŷ������\n\n");
		system("pause");
		printf("\n\t\tҳ����ת�ɹ�..\n");
		Sleep(800);

		//


	}
}


//�˳�ѧ��ϵͳ
void outStudent() {
	system("title ѧ����ϵͳ����");
	system("cls");
	system("COLOR 70");
	printf("\n\t\t\t\t���ҲҪ�ڷ�Ŭ�����ǵö�������ϰŶ����\(*�����*)//\n");
	Sleep(2300);
	saveStudentFile();
	printf("\n\t\t\t\tϵͳ�˳���...\n");
	Sleep(1500);
	printf("\n\t\t\t\t�˳��ɹ���\n");
	exit(0);
}

//���Բ�����������
//�����ȷ�ʸ���0.9����� �����
//�����ȷ��Ϊ0.8-0.9 ��� ������Ŷ
//�����ȷ��Ϊ0.6-0.8 ��� ������������Ŭ��Ŷ
//�����ȷ��С��0.6 ��� �������أ�Ҫ�����ϰ
void judge(double n,int right,int num) {  //nΪ��ȷ��  rightΪ��Ե�����  num���������
	system("cls");
	printf("(^v^)����һ������%d�������⣬��ȷ��%d������ȷ��Ϊ��%.2f%%\n",num,right,n*100);
	sleep(2);
	printf("\n");
	if(n>=0.9) {
		MessageBox(0, _T("�����գ���\n"), _T("����С���"), MB_OK);
	} else if(n>=0.8) {
		MessageBox(0, _T("��Ӵ~������Ŷ!\n"), _T("����С���"), MB_OK);
		//printf("��Ӵ~������Ŷ!\n");
	} else if(n>=0.6) {
		MessageBox(0, _T("�������գ�������Ŭ��Ŷ\n"), _T("����С���"), MB_OK);
		//printf("�������գ�������Ŭ��Ŷ\n");
	} else {
		MessageBox(0, _T("�������أ�Ҫ�����ϰŶ\n"), _T("����С���"), MB_OK);
		//printf("�������أ�Ҫ�����ϰŶ\n");
	}

}

//�Դ��жϵĽ�����д���
//���resultΪ 1��������ȷ��������ȷ����ʼ��һ��
//���resultΪ 0�����𰸴�����ʾ��ȷ�𰸲���ʾ�Ƿ񱣴�
void solution(int result) {
	if(result==1) {
		printf("  Ү����������\n");
		Sleep(700);
	} else {
		printf("  ��Ŷ~������~\n");
		printf("  %s\n",recentTopic);
		Sleep(700);
		printf("  Ҫ���浽���Ȿ���𣿣�1��ʾҪ��0��ʾ��Ҫ��\n");
		printf("  ѡ��:");
		int iif;
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice!=0);
		putch(choice+=48);
		choice-=48; //option1==0��option1==1
		puts("");

		if(iif==1) {
			addMistake(recentTopic);
		}

	}


}

void addMistake(char x[20]) {

	FILE* fout;
	if((fout=fopen(recentStudent->mistakeFileName,"a"))==NULL) {
		printf("�ļ���ʧ��\n");
	} else {
		fprintf(fout,"%s\n",x);//��Ӵ���
	}
	fclose(fout);
}


////////////////////////////////�������㸨������
int getMin(int a,int b) {
	if(a>=b) {
		return b;
	}
	return a;
}
int maxDivisor(int a,int b) {
	int min=getMin(a,b);
	for(int i=min; i>1; i--) {
		if((a%i==0)&&(b%i==0)) {
			return i;
		}
	}
	return 1;
}

//��������Ϊ�����ʽ
void simplify(int* up,int* down) {
	int Divisor=maxDivisor(*up,*down);
	*up=*up/Divisor;
	*down=*down/Divisor;
}


void subMultiplyForFraction(int firstUp,int firstDown,int secondUp,int secondDown,int* answerUp,int* answerDown) {
	*answerDown=firstDown*secondDown;
	*answerUp=firstUp*secondUp;
	simplify(answerUp,answerDown);
}

void subPlusForFraction(int firstUp,int firstDown,int secondUp,int secondDown,int* answerUp,int* answerDown) {
	*answerDown=firstDown*secondDown;
	*answerUp=firstUp*secondDown+firstDown*secondUp;
	simplify(answerUp,answerDown);
}

//�ڹ涨ʱ�䵽���ʱ��������Ϣ
void * timer(void *a) { //��ʱ���� ���涨ʱ���ʱ��
	int* n=(int*)a;

	while(1) {
		double startTime=clock();
		double endTime=clock();

		while((double)(endTime-startTime)/CLK_TCK<=(*n)) {
			endTime=clock();
		}

		sprintf(testTimeTips,"%d���ѵ����ۼ���ϰʱ���Ѵ�%d�룡ע������ϢŶ!",*n,(timeNum)*(*n));
		MessageBox(0, _T(testTimeTips), _T("����С���"), MB_OK);
		timeNum++;
		//printf("%d",timeNum);



	}
	//printf("10���ѵ�");
}

///////////////////////////////////////////////////


//��ɼӷ��Բ�ģ�����
void plus() {

	system("title �ӷ��Բ�ģʽ");
	system("cls");
	system("COLOR E0");
	printf("���ڿ�ʼ�ӷ��Բ⣬��׼��������\n");
	Sleep(1800);
	int choice;
	//�Ѷ�ѡ��
	printf("\t�����ѡ���Ѷȡ��\n");
	printf("  ��1-��\n");
	printf("  ��2-��\n");
	printf("  ��3-��(С��)\n");
	printf("  ��4-��(����)\n");
	printf("  ѡ��:");

//	while
	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48;
	puts("");//��������������


	int num;//��¼�Զ�������
	int result; //�ж�����Ĵ��Ƿ���ȷ
	int right=0;//��¼��ȷ����
	printf("  ���������������������:");
	scanf("%d",&num);
	fflush(stdin);
	while(num<=0) {
		printf("  �������������������������");
		scanf("%d",&num);
		fflush(stdin);
		puts("");
	}



	switch(choice) {
		case 1:
			for(int i=0; i<num; i++) {
				result = plusDemo(1);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
		case 2:

			for(int i=0; i<num; i++) {
				result = plusDemo(2);
				if(result==1) {
					right++;
				}
				solution(result);
			}

			break;
		case 3:
			for(int i=0; i<num; i++) {
				result = plusDemo(3);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
		case 4:
			for(int i=0; i<num; i++) {
				result = plusDemo(4);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
	}
	judge(right/(double)num,right,num);
	// ���¼ӷ���ȷ��
	recentStudent->plusCorrect=
	    ((recentStudent->plusCorrect)*(recentStudent->plusNum)
	     +right)/(recentStudent->plusNum+num);
	//���������ӷ�����
	recentStudent->plusNum+=num;

	printf("\n\no(^��^)oo��ϲ���Ѿ�����˱�����ϰ�����ػ������Բ˵���...");
	Sleep(2600);
	system("cls");
	return;

}

//��ɲ�����ʽ���ж�����
//����ֵ1��ʾ�����ȷ
//����ֵ0��ʾ�������
//������1-3��ʾ�Ѷ�����
int plusDemo(int difficulty) {
	if(difficulty==1) {
		system("cls");
		int a = rand()%100+1;
		int b = rand()%100+1;
		int c = a + b;
		char answer[10];
		char cc[10];
		itoa(c,cc,10);
		sprintf(recentTopic,"%d+%d=%d",a,b,c);
		printf("  �� %d + %d = ",a,b);
		scanf("%s",answer);
		if(strcmp(answer,cc)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==2) {
		system("cls");
		int a = rand()%100+1;
		int b = rand()%100+1;
		int c = rand()%100+1;
		int d = a + b +c;
		char answer[10];
		char dd[10];
		itoa(d,dd,10);
		sprintf(recentTopic,"%d+%d+%d=%d",a,b,c,d);
		printf("  �� %d + %d + %d = ",a,b,c);
		scanf("%s",answer);
		if(strcmp(answer,dd)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==3) {
		system("cls");
		double a = rand()%10000+1;
		double b = rand()%10000+1;
		double c = rand()%10000+1;
		a = a*0.01;
		b = b*0.01;
		c = c*0.01;
		double d = a + b +c;
		char answer[10];
		char dd[10];
		sprintf(dd, "%.2f", d);
		sprintf(recentTopic,"%.2f+%.2f+%.2f=%.2f",a,b,c,d);
		printf("  �� %.2f + %.2f + %.2f = ",a,b,c);
		scanf("%s",answer);
		if(strcmp(answer,dd)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==4) {
		system("cls");
		int a,b,c,d;

		do {
			a = rand() % 10 + 1;//��һ�������ķ���
			//a=8;
			b = rand() % 10 + 1;//��һ��������ĸ
			//b=6;
			c = rand() % 10 + 1;//�ڶ�����������
			// c=8;
			d = rand() % 10 + 1;//�ڶ���������ĸ
			// d=12;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//���еķ���
		int f=0;//���еķ�ĸ
		subPlusForFraction(a,b,c,d,&e,&f);

		char ee[10];
		itoa(e,ee,10);
		char ff[10];
		itoa(f,ff,10);

		if(b==1) {
			sprintf(recentTopic,"%d+%d/%d=%d",a,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}
			//printf("%s",recentTopic);
			printf("  �� %d + %d/%d = ", a,c,d);

		} else if(d==1) {
			sprintf(recentTopic,"%d/%d+%d=%d",a,b,c,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  �� %d/%d + %d = ", a, b,c);

		} else {
			sprintf(recentTopic,"%d/%d+%d/%d=%d",a,b,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  �� %d/%d + %d/%d = ", a, b,c,d);
		}

		scanf("%s", answerOfStu);
		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//��ɼ����Բ�ģ��
void minus() {
	system("title �����Բ�ģʽ");
	system("cls");
	system("COLOR E0");
	printf("���ڿ�ʼ�����Բ⣬��׼��������\n");
	Sleep(1800);
	int choice;
	printf("\t�����ѡ���Ѷȡ��\n");
	printf("  ��1-��\n");
	printf("  ��2-��\n");
	printf("  ��3-��(С��)\n");
	printf("  ��4-��(����)\n");
	printf("  ѡ��:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48; //option1==0��option1==1
	puts("");

	int num;//��¼�Զ�������
	int x=1;//�ж��������������Ƿ���ȷ
	int result; //�ж�����Ĵ��Ƿ���ȷ
	int right=0;//��¼��ȷ����
	printf("  ���������������������:");
	scanf("%d",&num);
	fflush(stdin);
	while(num<=0) {
		printf("  �������������������������");
		x=scanf("%d",&num);
		fflush(stdin);
		puts("");
	}

	switch(choice) {
		case 1:
			for(int i=0; i<num; i++) {
				result = minusDemo(1);

				if(result==1) {
					right++;
				}
				solution(result);

			}
			break;
		case 2:
			for(int i=0; i<num; i++) {
				result = minusDemo(2);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
		case 3:
			for(int i=0; i<num; i++) {
				result = minusDemo(3);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
		case 4:
			for(int i=0; i<num; i++) {
				result = minusDemo(4);
				if(result==1) {
					right++;
				}
				solution(result);
			}
			break;
	}
	judge(right/(double)num,right,num);
	//���¼�����ȷ��
	recentStudent->minusCorrect=
	    ((recentStudent->minusCorrect)*(recentStudent->minusNum)
	     +right)/(recentStudent->minusNum+num);
	//���¼�������
	recentStudent->minusNum+=num;

	printf("\n\no(^��^)oo��ϲ���Ѿ�����˱�����ϰ�����ػ������Բ˵���...");
	Sleep(2600);
	system("cls");
	return;

}

//��ɲ���������ʽ���жϽ������
//����ֵΪ1��ʾ�����ȷ
//����ֵΪ0��ʾ�������
//������1-3��ʾ�Ѷ�����
int minusDemo(int difficulty) {
	if(difficulty==1) {
		system("cls");
		int a = rand()%100+1;
		int b = rand()%100+1;
		a = a +b;
		int c = a - b;
		char answer[10];
		char cc[10];
		itoa(c,cc,10);
		sprintf(recentTopic,"%d-%d=%d",a,b,c);
		printf("  �� %d - %d = ",a,b);
		scanf("%s",answer);
		if(strcmp(answer,cc)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==2) {
		system("cls");
		int a = rand()%100+1;
		int b = rand()%100+1;
		int c = rand()%100+1;
		a = a+b+c;
		int d = a - b - c;
		char answer[10];
		char dd[10];
		itoa(d,dd,10);
		sprintf(recentTopic,"%d-%d-%d=%d ",a,b,c,d);
		printf("  �� %d - %d - %d = ",a,b,c);
		scanf("%s",answer);
		if(strcmp(answer,dd)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==3) {
		system("cls");
		double a = rand()%1000+1;
		double b = rand()%10000+1;
		double c = rand()%10000+1;
		a = a*0.01;
		b = b*0.01;
		c = c*0.01;
		a = a + b + c;
		double d = a - b - c;
		char answer[10];
		char dd[10];
		sprintf(dd, "%.2f", d);
		sprintf(recentTopic,"%.2f-%.2f-%.2f=%.2f",a,b,c,d);
		printf("  �� %.2f - %.2f - %.2f = ",a,b,c);
		scanf("%s",answer);
		if(strcmp(answer,dd)==0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==4) {
		system("cls");
		int a,b,c,d;
		do {
			a = rand() % 10 + 1;//��һ�������ķ���
			//a=1;
			b = rand() % 10 + 1;//��һ��������ĸ
			//b=5;
			c = rand() % 10 + 1;//�ڶ�����������
			//c=2;
			d = rand() % 10 + 1;//�ڶ���������ĸ
			//d=2;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//���еķ���
		int f=0;//���еķ�ĸ
		subPlusForFraction(a,b,c,d,&e,&f); //ϵͳ����ɼӷ�����

		char cc[10];
		itoa(c,cc,10);
		char dd[10];
		itoa(d,dd,10);

		if(f==1) {
			sprintf(recentTopic,"%d-%d/%d=%d",e,a,b,c);
			strcpy(answer, cc);
			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d - %d/%d = ", e,a,b);

		} else if(b==1) {
			sprintf(recentTopic,"%d/%d-%d=%d",e,f,a,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d/%d - %d = ", e, f,a);
		} else {
			sprintf(recentTopic,"%d/%d-%d/%d=%d",e,f,a,b,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d/%d - %d/%d = ", e, f,a,b);

		}

		scanf("%s", answerOfStu);

		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//��ɳ˷��Բ�ģ��
void multiply() {
	system("title �˷��Բ�ģʽ");
	system("cls");
	system("COLOR E0");
	printf("���ڿ�ʼ�˷��Բ⣬��׼��������\n");
	Sleep(1800);
	int choice = 0;
	printf("\t�����ѡ���Ѷȡ��\n");
	printf("  ��1-��\n");
	printf("  ��2-��\n");
	printf("  ��3-��(С��)\n");
	printf("  ��4-��(����)\n");
	printf("  ѡ��:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48; //option1==0��option1==1
	puts("");


	int num;//��¼�Զ�������
	int result; //�ж�����Ĵ��Ƿ���ȷ
	int rightNum = 0;//��¼��ȷ����
	printf("  ���������������������:");
	scanf("%d", &num);
	fflush(stdin);
	while(num <= 0) {
		printf("  ����������������Ҫ������������");
		scanf("%d", &num);
		fflush(stdin);
		puts("");
	}

	switch (choice) {
		case 1:
			for (int i = 0; i < num; i++) {
				result = multiplyDemo(1);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 2:
			for (int i = 0; i < num; i++) {
				result = multiplyDemo(2);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 3:
			system("cls");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("��Ҫ������˵���飡����\n");
			sleep(2);
			for (int i = 0; i < num; i++) {
				result = multiplyDemo(3);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 4:
			system("cls");
			sleep(2);
			for (int i = 0; i < num; i++) {
				result = multiplyDemo(4);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;

	}

	judge(rightNum / (double) num, rightNum, num);
	// ���³˷���ȷ��
	recentStudent->multiplyCorrect =
	    ((recentStudent->multiplyCorrect) * (recentStudent->multiplyNum)
	     + rightNum) / (recentStudent->multiplyNum + num);
	//���������˷�����
	recentStudent->multiplyNum += num;

	printf("\n\no(^��^)oo��ϲ���Ѿ�����˱�����ϰ�����ػ������Բ˵���...");
	Sleep(2600);
	system("cls");
	return;

}

//��ɲ����˷���ʽ���жϽ������
//����ֵΪ1��ʾ�����ȷ
//����ֵΪ0��ʾ�������
//������1-3��ʾ�Ѷ�����
int multiplyDemo(int difficulty) {
	srand((unsigned)time(NULL)) ;

	if (difficulty == 1) {
		system("cls");
		int a = rand() % 10 + 1;
		int b = rand() % 100 + 1;
		int c = a * b;
		char cc[10]="";
		sprintf(cc, "%d", c);
		char str[20] = "";
		sprintf(str,"%d��%d=%d",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %d �� %d = ", a, b);
//		gets(answer);
		scanf("%s",answer);
		if (strcmp(answer, cc) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (difficulty == 2) {
		system("cls");
		int a = rand() % 10 + 1;
		int b = rand() % 100 + 1;
		int c = rand() % 10 + 1;
		int d = a * b * c;
		char dd[10];
		sprintf(dd, "%d", d);
		char str[20] = "";
		sprintf(str,"%d��%d��%d=%d",a,b,c,d);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %d �� %d �� %d = ", a, b, c);
		scanf("%s",&answer);
		if (strcmp(answer, dd) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (difficulty == 3) {
		system("cls");
		double a = rand() % 1000 + 1;
		double b = rand() % 100 + 1;
		a = a * 0.1;
		b = b * 0.1;
		double d = a * b;
		char dd[10]="";
		sprintf(dd, "%.2lf", d);
		char str[20] = "";
		sprintf(str,"%.1lf��%.1lf=%.2f",a,b,d);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %.1lf �� %.1lf= ", a, b);
//      gets(answer);
		scanf("%s",answer);
		if (strcmp(answer, dd) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==4) {
		system("cls");
		int a,b,c,d;

		do {
			a = rand() % 10 + 1;//��һ�������ķ���
			//a=8;
			b = rand() % 10 + 1;//��һ��������ĸ
			//b=1;
			c = rand() % 10 + 1;//�ڶ�����������
			//c=8;
			d = rand() % 10 + 1;//�ڶ���������ĸ
			// d=12;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//���еķ���
		int f=0;//���еķ�ĸ
		subMultiplyForFraction(a,b,c,d,&e,&f);

		char ee[10];
		itoa(e,ee,10);
		char ff[10];
		itoa(f,ff,10);

		if(b==1) {
			sprintf(recentTopic,"%d��%d/%d=%d",a,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  �� %d �� %d/%d = ", a,c,d);

		} else if(d==1) {
			sprintf(recentTopic,"%d/%d��%d=%d",a,b,c,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  �� %d/%d �� %d = ", a, b,c);

		} else {
			sprintf(recentTopic,"%d/%d��%d/%d=%d",a,b,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  �� %d/%d �� %d/%d = ", a, b,c,d);
		}

		scanf("%s", answerOfStu);
		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//��ɳ����Բ�ģ��
void divide() {
	system("title �����Բ�ģʽ");
	system("cls");
	system("COLOR E0");
	printf("���ڿ�ʼ�����Բ⣬��׼��������\n");
	Sleep(1800);
	int choice = 0;
	printf("\t�����ѡ���Ѷȡ��\n");
	printf("  ��1-��\n");
	printf("  ��2-��\n");
	printf("  ��3-��(С��)\n");
	printf("  ��4-��(����)\n");
	printf("  ѡ��:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48;
	puts("");//��������������


	int num;//��¼�Զ�������
	int x = 1;//�ж��������������Ƿ���ȷ
	int result; //�ж�����Ĵ��Ƿ���ȷ
	int rightNum = 0;//��¼��ȷ����
	printf("  ���������������������:");
	scanf("%d", &num);
	fflush(stdin);
	while (num <= 0) {
		printf("  ����������������Ҫ������������");
		x = scanf("%d", &num);
		fflush(stdin);
		puts("");
	}


	switch (choice) {
		case 1:
			sleep(2);
			for (int i = 0; i < num; i++) {
				result = divideDemo(1);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 2:
			for (int i = 0; i < num; i++) {
				result = divideDemo(2);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 3:
			system("cls");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("С������ǵñ�����λС��Ŷ��\n");
			printf("��Ҫ������˵���飡����\n");
			sleep(2);
			for (int i = 0; i < num; i++) {
				result = divideDemo(3);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
		case 4:
			system("cls");
			sleep(2);
			for (int i = 0; i < num; i++) {
				result = divideDemo(4);
				if (result == 1) {
					rightNum++;
				}
				solution(result);
			}
			break;
	}

	judge(rightNum / (double) num, rightNum, num);
	// ���³�����ȷ��
	recentStudent->divideCorrect =
	    ((recentStudent->divideCorrect) * (recentStudent->divideNum)
	     + rightNum) / (recentStudent->divideNum + num);
	//����������������
	recentStudent->divideNum += num;

	printf("\n\no(^��^)oo��ϲ���Ѿ�����˱�����ϰ�����ػ������Բ˵���...");
	Sleep(2600);
	system("cls");
	return;
}

//��ɲ���������ʽ���жϽ������
//����ֵΪ1��ʾ�����ȷ
//����ֵΪ0��ʾ�������
//������1-3��ʾ�Ѷ�����
//��ɲ���������ʽ���жϽ������
//����ֵΪ1��ʾ�����ȷ
//����ֵΪ0��ʾ�������
//������1-3��ʾ�Ѷ�����
int divideDemo(int difficulty) {
	if (difficulty == 1) {
		system("cls");
		int a = rand() % 60 + 1;
		int b = rand() % 100 + 1;
		a = a*b;
		int c = a / b;
		char cc[10]="";
		sprintf(cc, "%d", c);
		char str[20] = "";
		sprintf(str,"%d��%d=%d",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %d �� %d = ", a, b);
//        gets(answer);
		scanf("%s",answer);
		if (strcmp(answer, cc) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (difficulty == 2) {
		system("cls");
		int a = rand() % 15 + 5;
		int b = rand() % 71 + 10;  //0~90   //���մ����������Χ
		int c = rand() % 10 + 1;
		int d = a * b * c;
		char bb[10];
		sprintf(bb, "%d", b);
		char str[20] = "";
		sprintf(str,"%d��%d��%d=%d",d,a,c,b);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %d �� %d �� %d = ", d, a, c);
		//gets(answer);
		scanf("%s",answer);
		if (strcmp(answer, bb) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if (difficulty == 3) {
		system("cls");
		double a = rand() % 10000 + 1;
		double b = rand() % 1000 + 1;
		a = a * 0.01;
		b = b * 0.1;
		double c = a / b;
		char cc[10]="";
		sprintf(cc, "%.2lf", c);
		char str[20] = "";
		sprintf(str,"%.2lf��%.1lf=%.2lf",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  �� %.2lf �� %.1lf = ", a, b);
//        gets(answer);
		scanf("%s",answer);
		if (strcmp(answer, cc) == 0) {
			return 1;
		} else {
			return 0;
		}
	} else if(difficulty==4) {
		system("cls");
		int a,b,c,d;
		do {
			a = rand() % 10 + 1;//��һ�������ķ���
			//a=5;
			b = rand() % 10 + 1;//��һ��������ĸ
			//b=1;
			c = rand() % 10 + 1;//�ڶ�����������
			//c=8;
			d = rand() % 10 + 1;//�ڶ���������ĸ
			//d=3;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//���еķ���
		int f=0;//���еķ�ĸ
		subMultiplyForFraction(a,b,c,d,&e,&f); //ϵͳ����ɳ˷�����

		char cc[10];
		itoa(c,cc,10);
		char dd[10];
		itoa(d,dd,10);

		if(f==1) {
			sprintf(recentTopic,"%d��%d/%d=%d",e,a,b,c);
			strcpy(answer, cc);
			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d �� %d/%d = ", e,a,b);

		} else if(b==1) {
			sprintf(recentTopic,"%d/%d��%d=%d",e,f,a,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d/%d �� %d = ", e, f,a);

		} else {
			sprintf(recentTopic,"%d/%d��%d/%d=%d",e,f,a,b,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  �� %d/%d �� %d/%d = ", e, f,a,b);

		}

		scanf("%s", answerOfStu);

		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//����ۺϲ���ģ��
void comTest() {
	system("title �ۺ��Բ�ģʽ");
	system("cls");
	system("COLOR E0");
	int number,part,difficulty,flag,option,count=0;
	printf("  ���ڿ�ʼ�ۺϲ��ԣ���׼��������\n");
	printf("  ����������Զ���������");
	scanf("%d",&number);
	fflush(stdin);
	while((number<=0)) {
		printf("  �������������������������");
		scanf("%d",&number);
		fflush(stdin);
		puts("");
	}


	for(int i =0; i<number; i++) { //���Զ�����������
		part = rand()%5 +1;
		difficulty = rand()%3+1;
		flag = comTestDemo(part,difficulty);//��ǵ�ǰ��Ŀ����
		if(flag==0) {
			count++; //������+1
			printf("  �� ��Ŷ(!)_(!)������\n");
			printf("  �� ��ȷ��:%s\n",recentTopic);
			printf("  �� �Ƿ񽫸��Ᵽ�������Ȿ��\n");
			printf("  1-(��ȡ����)��Ҫ���棡\n");
			printf("  0-(������)�������ˣ��������⣡\n");
			printf("  ѡ��:");
			do {
				option = getch();
				option-=48;
			} while ( option != 1 && option!=0);
			putch(option+=48);
			option-=48; //option1==0��option1==1
			puts("");


			if(option == 1) {
				addMistake(recentTopic);// ����ʵ��
			}
		}
	}
	judge((double)(number-count)/number,(number-count),number);

	printf("\n\no(^��^)oo��ϲ���Ѿ�����˱�����ϰ�����ڴ��ͻ��ϼ��˵���...");
	Sleep(2600);
	system("cls");
	return;

}

//��ɲ����ۺϳ��Ⲣ�жϽ������
//����ֵΪ1��ʾ�����ȷ
//����ֵΪ0��ʾ�������
//difficulty��1-3��ʾ�Ѷ�����
//partΪ���ⲿ�� 1--5 ����Ӽ��˳��ͻ������
int comTestDemo(int part,int difficulty) {
	int result;

	switch(part) {
		case 1:
			result = plusDemo(difficulty);
			return result;

		case 2:
			result = minusDemo(difficulty);
			return result;

		case 3:
			result = multiplyDemo(difficulty);
			return result;

		case 4:
			result = divideDemo(difficulty);
			return result;

		case 5:
			puts("");
			char str[30]="";//���浱ǰ��Ŀ

			switch(difficulty) { //���ѶȻ��ֻ����Ŀ
					srand((unsigned)time(NULL));

					int type;
					int a,b,c;
					type=rand()%3 + 1;//����Ļ����������

				case 1: {
					while(1) {

						a = rand()%100 + 1 ;
						b = rand()%100 + 1 ;
						c = rand()%100 + 1 ;

						int result;

						if((a+b-c)>0&&(a-b+c)>0) {
							if(type == 1) {

								system("cls");
								printf("  �� %d + %d - %d =",a,b,c);
								sprintf(str,"%d+%d-%d=%d",a,b,c,a+b-c);//����ǰ��Ŀ���浽str��

								scanf("%d",&result);
								if(result == a+b-c)
									return 1;  //��ȷ���� 1
								else {
									strcpy(recentTopic ,str);//���� ����ǰ��Ŀд��recentTopic������0��
									return 0;
								}

							} else if(type == 2) {

								system("cls");
								printf("  �� %d - %d + %d =",a,b,c);
								sprintf(str,"%d-%d+%d=%d",a,b,c,a-b+c);
								scanf("%d",&result);
								if(result == a-b+c)
									return 1;  //��ȷ���� 1
								else {
									strcpy(recentTopic ,str);//���� ����ǰ��Ŀд��recentTopic������0��
									return 0;
								}

							} else {

								system("cls");
								printf("  �� %d �� %d + %d =",a,b,c);
								sprintf(str,"%d*%d+%d=%d",a,b,c,a*b+c);

								scanf("%d",&result);
								if(result ==a*b+c)
									return 1;  //��ȷ���� 1
								else {
									strcpy(recentTopic ,str);//���� ����ǰ��Ŀд��recentTopic������0��
									return 0;
								}
							}

						}
					}
				}
				case 2: {

					while(1) {

						a = rand()%100 + 1 ;
						b = rand()%100 + 1 ;
						c = rand()%100 + 1 ;
						type=rand()%3 + 1;
						double result;

						if(a-b>0) {

							if(type == 1) {

								system("cls");
								printf("  �� ( %d + %d ) x %d =",a,b,c);
								sprintf(str,"(%d+%d)x%d=%d",a,b,c,(a+b)*c);
								scanf("%lf",&result);
								//printf("%lf\n",(double)(a+b)*c);

								if(fabs(result - (double)(a+b)*c)<=0.01)

									return 1;

								else  {

									strcpy(recentTopic ,str) ;
									return 0;
								}

							} else if(type == 2) {

								system("cls");
								printf("  �� ( %d - %d ) �� %d =",a,b,c);
								sprintf(str,"(%d-%d)��%d=%.1lf",a,b,c,(double)(a-b)/c);
								scanf("%lf",&result);
								//printf("%lf\n",(double)(a-b)/c);

								if(fabs(result - (double)(a-b)/c)<=0.01)

									return 1;

								else  {

									strcpy(recentTopic ,str) ;
									return 0;
								}
							} else {

								system("cls");
								printf("  �� %d x %d �� %d =",a,b,c);
								sprintf(str,"%dx%d��%d=%.1lf",a,b,c,(double)a*b/c);
								scanf("%lf",&result);
								//printf("%lf\n",(double)(a*b)/c);
								if(fabs(result - (double)(a*b)/c)<=0.01)

									return 1;

								else  {
									strcpy(recentTopic ,str) ;
									return 0;
								}
							}

						}
					}
				}
				case 3: {
					while(1) {

						double a = rand()%1000/10.0;
						double b = rand()%1000/10.0;
						double c = rand()%1000/10.0;
						type=rand()%3 + 1;
						double result;

						if(a*b-c>0) {

							if(type == 1) {

								system("cls");
								printf("  �� %.1lf x %.1lf - %.1lf =",a,b,c);
								sprintf(str,"%.1lfx%.1lf-%.1lf=%.1lf",a,b,c,a*b-c);
								scanf("%lf",&result);

								if(fabs(result - (a*b-c))<=0.01)

									return 1;
								else  {

									strcpy(recentTopic ,str) ;
									return 0;
								}
							} else if(type == 2) {
								system("cls");
								printf("  �� %.1lf �� %.1lf + %.1lf =",a,b,c);
								sprintf(str,"%.1lf��%.1lf+%.1lf=%.1lf",a,b,c,a/b+c);
								scanf("%lf",&result);

								if(fabs(result - ( a /b +c ) )<=0.01)

									return 1;
								else  {
									strcpy(recentTopic ,str) ;
									return 0;
								}
							} else {

								system("cls");
								printf("  ��%.1lf x %.1lf �� %.1lf =",a,b,c);
								sprintf(str,"%.1lfx%.1lf��%.1lf=%.1lf",a,b,c,a*b/c);
								scanf("%lf",&result);

								if(fabs(result  - (a *b)/c)<= 0.01)
									return 1;

								else  {

									strcpy(recentTopic ,str) ;
									return 0;
								}

							}
						}

					}

				}
			}
	}
}

//�����Ϸģ��
void game() {
	system("title ��Ϸģʽ");
	system("COLOR E0");
	system("cls");
	int option2,part,difficulty,flag = 1,count=0;

	printf("\n\n\t\t\t\t\t    ��ӭ������Ϸ���c(�Rv�Q)��\n");
	Sleep(2300);
	printf("\n\n\t\t\t\t\t  �������Ǿ���Ϊ��׼�����ر�ģʽ\n\n");
	Sleep(2700);
	printf("\n\t\t\t\t\t\tԤף�������죡����\n\n");
	Sleep(1700);

	printf("\n\t\t\t\t\t\t*****************\n");
	printf("\n\t\t\t\t\t\t**  1-�޾�ģʽ **\n") ;
	printf("\n\t\t\t\t\t\t**  2-����ģʽ **\n") ;
	printf("\n\t\t\t\t\t\t*****************\n");
	printf("\n\t\t\t\t\t ����ȷѡ����սģʽ��");

	int option1;
	do {
		option1 = getch();
		option1-=48;
	} while ( option1 != 1 && option1 != 2);
	putch(option1+=48);
	option1-=48;
	puts("");//��������������



	if(option1 ==1) { //ѡ���޾�ģʽ
		printf("\n\t\t\t\t\t�޾�ģʽ-����ֱ������Ϊֹ\n");
		while(1) { //һֱ�������
			part = rand()%5 +1;
			difficulty = rand()%3+1;
			flag = comTestDemo(part,difficulty);//��ǵ�ǰ��Ŀ����Դ�
			count++;//��¼��Ե���Ŀ��

			if(flag == 0) { //������Ƿ���¼�¼?,��ӡ��Ϣ��ѡ���Ƿ񱣴���⣿���˳�
				if(count > recentStudent->gameNum) {
					recentStudent->gameNum = count ;
					printf("\t\t\t\t\t�µļ�¼��\n");
				}
				printf("\n\t\t\t\t\t��ս����������˵�%d��.\n",count);
				printf("\t\t\t\t\t��ȷ��:%s\n",recentTopic);
				printf("\t\t\t\t\t�Ƿ񽫸��Ᵽ�������Ȿ��\n");
				printf("\t\t\t\t\t1-����\n");
				printf("\t\t\t\t\t2-�˳�\n");
				printf("\t\t\t\t\tѡ��:");
				do {
					option2 = getch();
					option2-=48;
				} while(option2 != 1 && option2 != 2 );
				putch(option2+48);


				if(option2 == 1) {
					addMistake(recentTopic);
					printf("\t\t\t\t\t����ɹ���\n");
					break;
				} else if(option2 == 2)
					break;
			}
		}
	} else { //ѡ�񴳹�ģʽ
		printf("\n\t\t\t\t\t����ģʽ-ʮ��ȫ�Լ�����\n");
		for(int i = 0; i<10; i++) {
			part = rand()%5 +1;
			difficulty = rand()%3+1;
			flag = comTestDemo(part,difficulty);
			count++;      //��¼�𵽵����
			if(flag == 0) { //�����
				printf("\n\t\t\t\t\t����ʧ�ܣ�\n");
				printf("\t\t\t\t\t��ս����������˵�%d��.\n",count);
				printf("\t\t\t\t\t��ȷ��:%s\n",recentTopic);
				printf("\t\t\t\t\t�Ƿ񽫸��Ᵽ�������Ȿ��\n");
				printf("\t\t\t\t\t1-����\n");
				printf("\t\t\t\t\t2-�˳�\n");
				do {
					option2 = getch();
					option2-=48;
				} while(option2 != 1 && option2 != 2 );

				if(option2 == 1) {
					addMistake(recentTopic);
					printf("����ɹ���\n");
					break;
				} else if(option2 == 2)
					break;
			}
		}
		if(count == 10&&flag == 1) { //û�г��� ����ӡ��Ϣ
			printf("���سɹ�!");
			recentStudent->gameLevel +=1; //���¹ؿ���
			printf("��ǰһ������%d��",recentStudent->gameLevel);
			sleep(1);
		}
	}
	system("cls");
	printf("�����������˵�......���Ժ�\n");
	Sleep(2500);
	system("cls");


}


//ѧ������ʦ���޸�����
void modifyPin(int role) {
	system("title �����޸�ҳ");
	char pin1[20];
	char pin2[20];
	system("cls");
	bool ifPinEqual = true;   //����������������Ƿ���ͬ
	do {
		printf("\n\n\t\t\t\t������������:");
		strcpy(pin1,password());
		puts("");
		while((strlen(pin1)<6)||(strlen(pin1)>20)) {
			printf("\t\t\t\t���볤��������λ�������ʮλ������������ȣ�");
			strcpy(pin1,password());
			puts("");
		}
		printf("\n\t\t\t\t��ȷ��������������룺");
		strcpy(pin2,password());
		puts("");
		while((strlen(pin1)<6)||(strlen(pin1)>20)) {
			printf("\t\t\t\t���볤��������λ�������ʮλ������������ȣ�");
			strcpy(pin1,password());
			puts("");
		}

		if(strcmp(pin1,pin2)!=0) {
			ifPinEqual = false;
			printf("\n\t\t\t\t������������벻һ�£�����������!\n");
			Sleep(900);
			system("cls");
		} else
			ifPinEqual = true;

	} while(!ifPinEqual);

	if(role==1) {
		strcpy(recentStudent->pin,pin1);
		system("cls");
		printf("\t\t\t\t�޸ĳɹ���������ת����ҳ��...\n");
		Sleep(1000);
		system("cls");


	} else if(role==0) {
		strcpy(teachers[tab].pin,pin1);
		system("cls");
		printf("\t\t\t\t�޸ĳɹ���������ת����ҳ��...\n");
		Sleep(1000);
		system("cls");
		menuT();
	}


}


//���С��ģ��
void test() {
	system("title С��ģʽ");
	system("cls");
	printf("\n\t\t\t\t\t�������С�⣬20���ӣ���20�⣬�ܷ�һ�ٷ֣�������������λС��\n");

	int flag = 1,
	    count = 0,
	    part,difficulty,
	    number = 0,
	    choice;//flag��¼���⺯������ֵ����ǵ�ǰ��Ŀ�Ƿ���ȷ
	int grade;
	char str[20][40] = {{0}}; //���ڴ洢����
	int scorePerQuestion = 5; //ÿ��5��
	int tmp=1200;

	printf("\t\t\t\t\t��ʼС��\n");//1200�� 20����
	int i;

	double startTime = clock();
	for(i =0; i<20; i++) { //��20����

		double endTime = clock();

		if((double)(endTime-startTime)/CLK_TCK >= tmp) {

			printf("\n\t\t\t\t\tʱ�䵽��!!!");
			Sleep(1000) ;
			break;
		}

		printf("\n");
		part = rand()%5 +1;
		difficulty = rand()%3+1;
		flag = comTestDemo(part,difficulty);

		if(flag ==0 ) { //ÿ�γ���count++�����ѵ�ǰ��Ŀд��str����

			count++;
			strcpy(str[number],recentTopic);
			number ++ ;
		}

	}
	grade = 100 - count*scorePerQuestion; //����˴β���ɼ�
	recentStudent->testNum += 1;//����С�����

	for(int j=0; j<20; j++) { //���С��ɼ��������� 0 ����ӳɼ�

		if(recentStudent->grade[j] ==0) {
			recentStudent->grade[j]= grade;
			break;
		}
	}
	int total = 0;

	for(int k=0; recentStudent->grade[k]!=0; k++) {
		total+=recentStudent->grade[k];
		recentStudent->testGrade = (double)total/(k+1);//����С�����
	}

	judge((double)(i-count)/i,i-count,i); //���۴˴�С��
	printf("\t\t\t\t\t��ĵ÷�Ϊ%d�֣�����Ŭ����\n",grade);
	printf("\t\t\t\t\t�������Ŀ���£�\n");

	for(int i = 0; i<number; i++) {
		printf("\t\t\t\t\t\t��%s\n\n",str[i]);
	}

	printf("\n");
	printf("\t\t\t\t\t�Ƿ񱣴���⣿\n");
	printf("\t\t\t\t\t1-����;");
	printf("\t\t\t\t\t2-������");
	printf("\n\t\t\t\t\tѡ��:");
	do {
		choice = getch();
		choice-=48;
	} while(choice != 1 && 	choice != 2 );
	putch(choice+=48);
	choice-=48;
	puts("");


	if(choice == 1) {
		for(int i=0; i<number; i++) {
			addMistake(str[i]);//��str�����еĴ���ȫ��������Ȿ
		}
		printf("\n\t\t\t\t\t����ɹ���\n");
	}


	printf("\n\t\t\t\t\t�����������˵�......���Ժ�");
	Sleep(2500);
	system("cls");


}


//��ѯ���Ȿ
void printMistake() {
	system("title �鿴���Ȿ");
	system("cls");
	system("COLOR c0");
	FILE* fin;
	if((fin=fopen(recentStudent->mistakeFileName,"r"))==NULL) {
		printf("�ļ���ʧ��\n");
	} else {
		char strings[500][30];

		int size=0;
		while(fscanf(fin,"%s",strings[size])==1) {
			size++;
		}
		char* s[500];

		srand((unsigned) time(NULL));
		int sentOrder = 1 + rand() % 5;
		switch (sentOrder) {
			case 1:
				printf("\n\t�d�d ǧ��֮�̣�������֮Ѩ�����ٳ�֮�ң���ͻ϶֮�̷١� �����������Ӽ�ע��־��\n\n");
				break;
			case 2:
				printf("\n\t�d�d �������󵽵��˵��������Ϊ�����˴��������⣬���ǹ����������� ������˹��\n\n");
				break;
			case 3:
				printf("\n\t�d�d ÿ���˶��д���ֻ�����߲Ż�ִ�Բ��� ����������\n\n");
				break;
			case 4:
				printf("\n\t�d�d һ����֪�����Լ��Ķ̴����ܹ��Ĺ����£������и��ġ� ����ɯʿ���ǡ��������ǡ�\n\n");
				break;
			case 5:
				printf("\n\t�d�d ����������ȡ�ý��������뽻����ѧ�ѡ� ����¬�ǲ��˹��\n\n");
				break;

		}

		printf("\t\t\t��%7sС���ѵĴ��⼯��\n\n",recentStudent->name);
		printf("\t\t   �ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n\n");

		for(int i=0; i<size; i++) {
			puts("");
			s[i]=(char*)strings[i];
			printf("\t\t\t����%-15s\n",s[i]);
		}
		puts("");
		printf("\n\t\t   �ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n\n");

	}
	fclose(fin);

}

//��ѯ�ɼ�
void viewGrade() {
	system("title ѧ����---��������");
	system("cls");
	system("COLOR c0");
	printf("\n\t\t\t����%7sС���ѵ�ǰ��ս���� ����\n\n",recentStudent->name);
	printf("\n\t\t   �ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n\n");

	printf("\t\t\t����С��ƽ���ɼ�: \t%-.2f\n",recentStudent->testGrade);
	printf("\t\t\t������Ϸ����ģʽ��ǰ�ؿ�:%-d\n",recentStudent->gameLevel);
	printf("\t\t\t������Ϸ�޾�ģʽ�������:%-d\n",recentStudent->gameNum);
	printf("\t\t\t���ؼӷ��Բ���ȷ��: \t%-.2f\n",recentStudent->plusCorrect);
	printf("\t\t\t���ؼӷ��Բ�������: \t%-d\n",recentStudent->plusNum);
	printf("\t\t\t���ؼ����Բ���ȷ��: \t%-.2f\n",recentStudent->minusCorrect);
	printf("\t\t\t���ؼ����Բ�������: \t%-d\n",recentStudent->minusNum);
	printf("\t\t\t���س˷��Բ���ȷ��: \t%-.2f\n",recentStudent->multiplyCorrect);
	printf("\t\t\t���س˷��Բ�������: \t%-d\n",recentStudent->multiplyNum);
	printf("\t\t\t���س����Բ���ȷ��: \t%-.2f\n",recentStudent->divideCorrect);
	printf("\t\t\t���س����Բ�������: \t%-d\n",recentStudent->divideNum);

	printf("\n\t\t   �ޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡޡ�\n\n");

}

//�鿴��ʦ����
void evaluation() {
	system("cls");
	system("COLOR c0");
	puts("");
	printf("\t �X ��  ��  ��  �[\n");
	printf("\t   ��ǰ����:  \n");
	printf("\t �^ ��  ��  ��  �a\n");

	printf("\t\t\t%s",recentStudent->comment);
	printf("\n");
}

//��ɽ�ʦģ��
void teacher() {
	system("title �����ʦ��");
	system("cls");
	system("COLOR fc");
	printf("\t\t\t\t\t\t�q  ��  ��  ��  �r\n");
	printf("\t\t\t\t\t\t   ��¼�ɹ���  \n");
	printf("\t\t\t\t\t\t�t  ��  ��  ��  �s\n");
	printf("\n\t\t*=*=*=*=*=*=         Hello��%7s��ʦ----��ӭʹ������С���ϵͳ       =*=*=*=*=*\n",teachers[tab].name);
	puts("");
	printf("\t\t************\t\t�����������һ���֤�����ǵĳɳ���[]~(�䨌`)~*\t\t**********\n");
	menuT();

}

//��ʾ��ʦ���˵��������û����������Ӧ����
void menuT() {
	while(1) {
		system("COLOR fc");
		system("title ��ʦ�����˵�");
		system("cls");


		printf("\n\n\t\t\t\t       ==========��ʦϵͳ������==========\n\n");
		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");
		printf("\t\t\t\t\t   ��\t --1-�鿴ѧ������ ��\n\n");
		printf("\t\t\t\t\t   \t --2-����ѧ����Ϣ\n\n");
		printf("\t\t\t\t\t   ��\t --3-�޸�����	  ��\n\n");
		printf("\t\t\t\t\t   \t --0-�˳� \n\n");
		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");

		printf("\n\t\t������ѡ��Ҫʹ�õĹ���(*��U`*):");
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0);
		putch(choice+=48);
		choice-=48; //option1==0��option1==1
		puts("");

		switch (choice) {
			case 1:
				rank();
				break;
			case 2:
				menuT_manage();
				break;
			case 3:
				modifyPin(0);
				break;
			case 0:
				outTeacher();
				break;
		}

	}
}

//�������ѧ����Ϣ���棬�������벢������Ӧ����
void menuT_manage() {
	system("title ��ʦ��---ѧ������ҳ");
	system("COLOR b0");
	system("cls");
	int time = 0;

	while (1) {
		if (time == 0) {
			printf("\n\t\t\t\t  =*=*=*=*=*��ӭ����ѧ����Ϣ������*=*=*=*=*=\n\n\n");
		} else {
			printf("\n\n\t\t\t\t\t    =*=*����ʹ�ø��๦��*=*\n\n");
		}

		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");
		printf("\t\t\t\t\t   ��\t --1-���ѧ��     ��\n\n");
		printf("\t\t\t\t\t   \t --2-�Ƴ�ѧ��\n\n");
		printf("\t\t\t\t\t   ��\t --3-�޸�ѧ����Ϣ ��\n\n");
		printf("\t\t\t\t\t   \t --4-�鿴ѧ����Ϣ\n\n");
		printf("\t\t\t\t\t   ��\t --0-�������˵�	  ��\n\n");
		printf("\t\t\t\t\t   ������  ����  ����  ����  ����  ������\n\n");

		printf("\n\t\t����ѡ��Ҫʹ�õĹ���(*��U`*):");
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0 &&choice!=4);
		putch(choice+=48);
		choice-=48; //option1==0��option1==1
		puts("");

		switch (choice) {
			case 1:
				addStudent();
				break;
			case 2:
				deleteStudent();
				break;
			case 3:
				modifyStudent();
				break;
			case 4:
				checkStudent();
				break;
			case 0:
				system("cls");
				menuT();
				break;
		}
	}
}

//�˳���ʦϵͳ
void outTeacher() {
	system("title ��ʦ��ϵͳ����");
	system("cls");
	system("COLOR 70");
	srand((unsigned) time(NULL));
	int sentOrder = 1 + rand() % 5;
	switch (sentOrder) {
		case 1:
			printf("\n\t\t\t\t���Ǳ��ҹ������ϸ������\n\n");
			break;
		case 2:
			printf("\n\t\t\t\t���߽�̨�������࣬����ʣ���ǧ���\n\n");
			break;
		case 3:
			printf("\n\t\t\t\tʮ����ľ��ʮ�ط磬ʮ���꣬ʮ������\n\n");
			break;
		case 4:
			printf("\n\t\t\t\t��֮���ڽ̣���֮����ʦ��\n\n");
			break;
		case 5:
			printf("\n\t\t\t\t�Ķȴ��ﻯ���ѣ���������ϴ�蹵��\n\n");
			break;

	}
	printf("\n\n\t\t\t\t��л����ʹ�ã�ϵͳ�˳���...\n");
	saveTeacherFile();
	saveStudentFile();
	Sleep(2500);
	printf("\n\t\t\t\t�˳��ɹ���\n");
	exit(0);
}

//�鿴ѧ������
void printNameAndId(double n) {
	system("title �鿴ѧ��С������");
	PSt pPosition=headStudent->next;
	while(pPosition!=NULL) {
		if(pPosition->testGrade==n) {
			printf("%s\t%s\t%.2f\t\t",pPosition->name,pPosition->id,pPosition->testGrade);
		}
		pPosition=pPosition->next;
	}
	printf("\n");

}


//�鿴ѧ����Ϣ������������Ϣ����ʷ�ɼ������
void checkStudent() {
	system("title ��ʦ��---��Ϣ��ѯҳ");
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool ifIdFound = true;
	int choice = 0;
	PSt pHead = headStudent;


	//��һ�����жϰ༶�ڲ��Ƿ����ѧ��
	if (!(pHead->next) ) {
		printf("\n\t����û������κ�ѧ���޷����в�ѯ!\n");
		printf("\t���ڷ�����һ���˵�...");
		Sleep(2000);
		menuT_manage();
	} else {

		do {
			//�ڶ�������ȡ�û������ѧ��id�����жϸ�ѧ���Ƿ����
			puts("");
			printf("\t����������鿴��Ϣ��ѧ��id:");
			//gets(id);
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);
			if (!p) {
				fflush(stdin);
				ifIdFound = false;
				printf("\t��ʾ��������ҵ�ѧ�������ڣ���ȷ�ϲ���������\n");
			} else {
				ifIdFound = true;
				recentStudent = p;
				//����������ӡ���ҵ���ѧ���ĸ�����Ϣ
				printf("\t���ҵ�����ѧ����Ϣ���£�\n");
				printf("\t----������%s\n", p->name);
				printf("\t----ѧ�ţ�%s\n", p->id);
				printf("\t----С���¼��----\n");
				printf("\t===============================\n");
				for (int i = 0; i < p->testNum; i++)
					printf("\t��%d��С��ɼ�\t----\t%d\n", i + 1, p->grade[i]);

				printf("\t\t\tС��ƽ��������%d\n", p->testGrade);
				printf("\t===============================\n");
				printf("\t----��ǰ���%s\n", p->comment);
				printf("\n\n");
				bool returnThisPage = true;  //Ĭ�ϲ�����ɺ��ٷ��ش�ҳ��
				do {
					ifIdFound = false;
					//�鿴��ɺ���ʾ������������
					printf("\t---1-�޸�����\n");
					printf("\t---2-�����鿴\n");
					printf("\t---0-������һ���˵�\n");
					printf("\n\t��ѡ��");

					do {
						choice = getch();
						choice-=48;
					} while (choice != 0 && choice != 1 && choice != 2);
					putch(choice+=48);
					choice-=48;
					puts("");//��������������


					if (choice == 0)
						menuT_manage();
					else if (choice == 1) {
						evaluate();
						printf("\t�޸ĳɹ���\n\n");
					} else if(choice == 2)
						returnThisPage=false;
				} while ( returnThisPage);

			}
		} while (!ifIdFound || choice == 2);


	}


}


//���ѧ��
void addStudent() {
	system("title ��ʦ��---ע��ѧ��ҳ");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	int choice = 0; //���������Ϣ��ɺ�Ĳ˵�ѡ��
	do {

		//=======================================================================//��һ�����½�ѧ����Ϣ
		printf("\n\tѧ����Ϣ�����...\n");
		PSt pNew = (PSt) malloc(sizeof(St));
		pNew->next = NULL;
		printf("\n\t�������ѧ����������");
		scanf("%s", pNew->name);
		printf("\n\t�������ѧ����ѧ�ţ�");
		scanf("%s", pNew->id);
		PSt p = traverse(pNew->id,headStudent);
		//�ڶ������жϸ�id��Ӧ��ѧ���Ƿ��Ѿ������ڰ༶�б���
		if(p!=NULL) {
			printf("\n\t��ѧ���Ѿ����������İ༶��...");
		} else {

			strcpy(pNew->comment, "��ʦ��ʱû�и��������~");

			strcpy(pNew->pin,"123456");
			pNew->plusCorrect = 0;
			pNew->plusNum = 0;
			pNew->minusCorrect = 0;
			pNew->minusNum = 0;
			pNew->multiplyCorrect = 0;
			pNew->multiplyNum = 0;
			pNew->divideCorrect = 0;
			pNew->divideNum = 0;
			pNew->testGrade = 0;
			pNew->testNum = 0;
			puts("");


			//char *initMisPath = "G://C//ʵѵ//";
			char *initMisPath = "F://University//��һ��//Сѧ��//Code//";  //���������ļ����·��
			sprintf(pNew->mistakeFileName, "%s%sС���ѵĴ��⼯.txt", initMisPath, pNew->name);
			pNew->mistakeNum = 0;
			pNew->gameLevel = 0;
			pNew->gameNum = 0;
			for(int i=0; i<20; i++)
				pNew->grade[i]=0;
			pNew->testGrade = 0;

			//�������� ��ɴ���
			if(!pHead) {
				pHead = (PSt)malloc(sizeof(St));
				pHead->next = NULL;
			}
			PSt p = pHead;
			while (p->next)
				p = p->next;
			p->next = pNew;
			printf("\n\t��ѧ����ӳɹ���\n");
			puts("");
			//=============================================================================//

		}
		//���Ĳ�����ʾ��������
		printf("\n\n\t--1-�������\n");
		printf("\t--0-���ص�����ѧ��ҳ\n");
		printf("\n\t��ѡ��");

		//////////////////////////////////��������������
		do {
			choice = getch();
			choice-=48;
		} while (choice != 0 && choice != 1);
		putch(choice+=48);
		choice-=48;
		puts("");
		//////////////////////////////////
		if (choice == 0)
			menuT_manage();

	} while (choice == 1);


}


//ɾ��ѧ��
void deleteStudent() {
	system("title �Ƴ�ѧ������");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool ifIdFound = true;  //�ٶ��ܹ��ҵ���Ӧѧ��
	int choice = 0; //�����Ƴ�ѧ����Ĳ˵�ѡ�����

	//��һ�����жϰ༶���Ƿ����ѧ��
	if (!pHead->next) {
		printf("\n\t����û������κ�ѧ���޷�����!\n");
		printf("\n\t���ڷ�����һ���˵�...");
		Sleep(2000);
		menuT_manage();
	} else {
		do {
			//�ڶ�������ʾ����Ҫ�Ƴ���ѧ��
			printf("\n\n\t����������Ҫ�Ƴ���ѧ��id:");
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);

			//���������жϸ����Ƿ����
			if (!p) {
				fflush(stdin);
				ifIdFound = false;
				printf("\n\t����Ҫ�Ƴ���ѧ���������ڰ༶�����У���ȷ�ϲ��������룺");
			} else {
				//���Ĳ�����ӡѧ����Ϣ��ȷ���Ƿ�ɾ��
				ifIdFound = true;
				printf("\n\t���ҵ���ѧ����\n");
				printf("\t----������%s\n", p->name);
				printf("\t----ѧ�ţ�%s\n", p->id);
				puts("");


				printf("\n\t��ȷ��Ҫ�Ƴ���ѧ����\n");
				int ifConfirm = 0;
				printf("\t---1-ȷ��\n");
				printf("\t---0-ȡ����������һ���˵�\n");
				printf("\t-----ѡ��");

				//��������������
				do {
					ifConfirm = getch();
					ifConfirm-=48;
				} while (ifConfirm != 0 && ifConfirm != 1);
				putch(ifConfirm+=48);
				ifConfirm-=48;
				puts("");

				if (ifConfirm == 0) {
					printf("\n\t���ڷ���...");
					Sleep(1600);
					menuT_manage();
				} else {
					//���岽���Ƴ�ѧ������---ɾ���ڵ�
					PSt pFront = pHead;
					PSt pTmp;

					while (pFront->next && strcmp(pFront->id, id) != 0) {
						pTmp = pFront;
						pFront = pFront->next;
					}

					if (strcmp(pFront->id, id) == 0) {
						pTmp->next = pFront->next;
						free(pFront);
					}
				}
				//������������Ƴ�����ʾ��������
				printf("===============================\n");
				printf("\n\t�Ƴ��ɹ�����ѡ��\n");
				puts("");

				printf("\n\t---1-�����Ƴ�\n");
				printf("\t---0-������һ���˵�\n");
				printf("\t-----ѡ��");


				do {
					choice = getch();
					choice-=48;
				} while (choice != 0 && choice != 1);
				putch(choice+=48);
				choice-=48;
				puts("");//��������������

				if (choice == 0) {
					printf("\n\t���ڷ���...");
					Sleep(1600);
					menuT_manage();
				}
				//���߲����������Ƴ������ж��Ƿ�༶�ڲ�����ѧ������
				else {
					if(!pHead->next) {
						system("cls");
						printf("�༶���Ѿ�û��ѧ����������\n");
						printf("���ڷ���ѧ������˵�...");
						Sleep(2000);

						menuT_manage();
					}
				}


			}

		} while (!ifIdFound || choice == 1);
	}


}

//�޸�ѧ����Ϣ
void modifyStudent() {
	system("title ��ʦ��---ѧ����Ϣ�޸�ҳ");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool idNotFoundError = false;
	int choice = 0;

	//��һ�����жϰ༶���Ƿ����ѧ��
	if (!pHead->next ) {
		printf("\n\t����û������κ�ѧ���޷������޸�!\n");
		printf("\t���ڷ�����һ���˵�...");
		Sleep(2000);
		menuT_manage();
	} else {
		do {

			//�ڶ����������������ѧ��
			printf("\n\t�����������޸���Ϣ��ѧ��id:");
			//gets(id);
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);
			if (!p) {
				fflush(stdin);
				idNotFoundError = true;
				printf("\t������ҵ�ѧ�������ڣ���ȷ��!\n");
			} else {
				idNotFoundError = false;
				recentStudent = p;
				printf("\t���ҵ�����ѧ����ǰ������Ϣ���£�\n");
				printf("\t----������\t\t%s\n", p->name);
				printf("\t----ѧ�ţ�\t\t%s\n", p->id);
				printf("\t----С��ƽ���֣�\t\t%.2f\n", p->testGrade);
				printf("\t----��ǰ���\t\t%s\n", p->comment);

				//�������������û���Ҫ�޸ĵ�����
				printf("\n\t===============================\n");
				printf("\t��ѡ����Ҫ�޸ĵ���Ϣ��\n");
				bool ifContinueFixing = true;  //�����ж��Ƿ�Ҫ��Ϣ,Ĭ��Ϊ���ǡ�
				do {
					puts("");

					printf("\t---1-����\n");
					printf("\t---2-ѧ��\n");
					printf("\t---3-����\n");
					printf("\t---0-ȡ����������һ���˵�\n");
					printf("\tѡ��");

					do {
						choice = getch();
						choice-=48;
					} while (choice != 0 && choice != 1 && choice != 2 && choice != 3);
					putch(choice+=48);
					choice-=48;
					puts("");//��������������

					//���Ĳ�����ȡѡ��ʼ�޸ģ������޸���ɺ���ʾ�Ƿ����
					if (choice == 0)
						menuT_manage();
					else if (choice == 1) {
						puts("");
						char newName[20] = "";
						printf("\t�������ѧ���޸ĺ��������");
						scanf("%s", newName);
						strcpy(p->name, newName);
						printf("\n\t�����޸ĳɹ���\n");
						printf("\n\t��ѡ���Ƿ�����޸ģ�\n");
					} else if (choice == 2) {
						puts("");
						char newId[20] = "";
						printf("\t�������ѧ���޸ĺ��ѧ�ţ�");
						bool idHasExisted = false;   //�����ж�ѧ���Ƿ��Ѿ�����
						do {
							scanf("%s", newId);   //��ʱδ����id�ַ������з����ֵ����
							puts("");
							PSt pCheck = traverse(newId, pHead);
							if (pCheck != NULL) {
								printf("\n\t��ѧ���Ѿ���������\n");
								idHasExisted = true;
								printf("\t������Ϣ���£�\n");
								printf("\t----������%s\n", pCheck->name);
								printf("\t----ѧ�ţ�%s\n", pCheck->id);
								printf("\n\t����������ɣ�");
							} else
								idHasExisted = false;
						} while (idHasExisted);

						strcpy(p->id, newId);
						printf("\n\tѧ���޸ĳɹ���\n");
						printf("\n\t��ѡ���Ƿ�����޸ģ�\n");
					} else if (choice == 3) {
						evaluate();
						printf("\n\t�����޸ĳɹ���\n");
						printf("\n\t��ѡ���Ƿ�����޸ģ�\n");
					}
				} while (ifContinueFixing);

			}
		} while (idNotFoundError);

	}

}

//��ѧ����������
void evaluate() {
	char review[20];
	printf("\n\t���������Ը�ѧ�������");
	scanf("%s",review);
	strcpy(recentStudent->comment,review);

}

//���ļ��ж�ȡ���ݲ�д��������
void readStudentFile() {
	PSt pointer,q;//headָ��Ϊ�����ͷ��㣬���ҵ������Ψһ���ݣ����headָ�붪ʧ����ô����������Ҳ�����;
	//pָ������ָ��������Ľ��;qָ������ָ��β�ڵ�
	St temp;//����ṹ�����
	FILE *fp;
	pointer=(struct student *)malloc(sizeof(struct student ));  // pָ���¿��ٵĽڵ��ڴ�
	headStudent = pointer;    //����ͷ����ڴ�      ͷ�����û��ѧ���ɼ���Ϣ
	q = pointer;       //����β�ڵ��ڴ�   qָ������ָ��β�ڵ�
	q->next = NULL; // //��־����Ľ��� β�ڵ���ص���next��Ա��ֵΪNULL���������һ���ڵ㣬��Ϊ��������ı�־��NULL��һ�����ų�����ʾֵΪ0�ĵ�ַ
//	fp=fopen("G://C//ʵѵ//a.txt","r");
	fp=fopen("F://University//��һ��//Сѧ��//Code//student.txt","r");



	if(fp ==NULL) {
		printf("cannot open the file");
	}


	while(fscanf(fp,"%s  %s %s  %lf  %d %lf %d %lf %d %lf %d %lf %d  %s %d %d  %d",
	             temp.name,temp.id,temp.pin,&temp.plusCorrect,&temp.plusNum,&temp.minusCorrect,&temp.minusNum,
	             &temp.multiplyCorrect,&temp.multiplyNum,&temp.divideCorrect,&temp.divideNum,&temp.testGrade,
	             &temp.testNum,temp.mistakeFileName,&temp.mistakeNum,&temp.gameLevel,&temp.gameNum)==17) { //���ļ��ж��ṹ���
		for(int i=0; i<20; i++) {
			fscanf(fp,"%d",&temp.grade[i]);
		}
		fscanf(fp,"%s",temp.comment);
		pointer=(struct student*)malloc(sizeof(struct student)); // pָ���¿��ٵĽڵ��ڴ�
		strcpy(pointer->name,temp.name);
		strcpy(pointer->id,temp.id);
		strcpy(pointer->pin,temp.pin);
		pointer->plusCorrect = temp.plusCorrect;
		pointer->plusNum = temp.plusNum;
		pointer->minusCorrect = temp.minusCorrect;
		pointer->minusNum = temp.minusNum;
		pointer->multiplyCorrect = temp.multiplyCorrect;
		pointer->multiplyNum = temp.multiplyNum;
		pointer->divideCorrect = temp.divideCorrect;
		pointer->divideNum = temp.divideNum;
		pointer->testGrade = temp.testGrade;
		pointer->testNum = temp.testNum;
		strcpy(pointer->mistakeFileName,temp.mistakeFileName);
		pointer->mistakeNum = temp.mistakeNum;
		pointer->gameLevel = temp.gameLevel;
		pointer->gameNum = temp.gameNum;
		for(int i=0; i<20; i++) {
			pointer->grade[i] =temp.grade[i];
		}
		strcpy(pointer->comment,temp.comment);


		q->next=pointer;  //���½ڵ�ҵ�ԭβ�ڵ�֮��
		q=q->next;  //qָ��ָ���µ�β�ڵ�
	}
	q->next=NULL;//��־����Ľ���
	fclose(fp);
}

void readTeacherFile() {
//	FILE *fp = fopen("G://C//ʵѵ//b.txt","r");
	FILE *fp = fopen("F://University//��һ��//Сѧ��//Code//teacher.txt","r");
	if(fp==NULL) {
		printf("cannot open this file");
	}
	int i=0;
	while(fscanf(fp,"%s %s %s",teachers[i].name,teachers[i].id,teachers[i].pin)==3) {
		i++;
	}
	fclose(fp);

}

PSt traverse(char id[10], PSt pHead) {

	if (pHead->next == NULL)
		return NULL;
	else {
		PSt p = pHead->next;
		while (p->next && strcmp(p->id, id) != 0)
			p = p->next;
		if (strcmp(p->id, id) == 0)
			return p;
		else
			return NULL;
	}
}

void sortForArray(double a[],int n) {  //��a��������������
	for(int i=0; i<n-1; i++) {
		for(int j=i+1; j<n; j++) {
			if(a[i]<a[j]) {
				double tmp;
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}

int sumOfStu() {    //�ú���ʵ���˼������������ѧ��������
	int sum=0;
	PSt pPosition=headStudent;
	while(pPosition!=NULL) {
		sum++;
		pPosition=pPosition->next;
	}
	return sum-1;
}

void rank() {//��ѧ��������������ĺ���
	system("COLOR b0");
	system("cls");
	if(!headStudent->next) {
		printf("\n\n\t\t����û�����ѧ������༶���޷��鿴����-_^~\n");
		printf("\n\t\t���ڷ������˵�...\n\n");
		Sleep(1000);
		system("cls");
		menuT();
	}
	double scores[500];
	PSt position=headStudent->next;
	int i=0;
	while(position!=NULL) {
		scores[i]=position->testGrade;
		i++;
		position=position->next;
	}
	int SumNumberForStu=sumOfStu( );
	printf("SumNumberForStu:%d \n",SumNumberForStu);
	sortForArray(scores,SumNumberForStu);


	printf("\n\t\t����\t����\tID\tС��ƽ������\n\n");
	int j=1;//��������
	for(int i=0; i<SumNumberForStu; i++) {
		printf("\t\t%d\t",j);
		printNameAndId(scores[i]);
		printf("\n");
		j++;
	}
	int choice;
	system("pause");


	system("cls");
	printf("���ڷ������˵������Ժ󡭡�\n");
	Sleep(1600);
	menuT();
}


void saveStudentFile() {
	FILE *fp;
//	fp=fopen("G://C//ʵѵ//a.txt","w");
	fp=fopen("F://University//��һ��//Сѧ��//Code//student.txt","w");

	if(fp ==NULL) {
		printf("cannot open the file");
	}
	for(PSt p=headStudent->next; p!=NULL; p=p->next) {
		fprintf(fp,"%s  %s %s  %.2f  %d %.2f %d %.2f %d %.2f %d %.2f %d  %s %d %d  %d ",
		        p->name,p->id,p->pin,p->plusCorrect,p->plusNum,p->minusCorrect,p->minusNum,
		        p->multiplyCorrect,p->multiplyNum,p->divideCorrect,p->divideNum,p->testGrade,
		        p->testNum,p->mistakeFileName,p->mistakeNum,p->gameLevel,p->gameNum);
		for(int i=0; i<20; i++) {
			fprintf(fp,"%d ",p->grade[i]);
		}
		fprintf(fp,"%s\n",p->comment);
	}
	fclose(fp);

}


void saveTeacherFile() {
//	FILE *fp = fopen("G://C//ʵѵ//b.txt","w");
	FILE *fp = fopen("F://University//��һ��//Сѧ��//Code//teacher.txt","w");

	if(fp==NULL) {
		printf("cannot open this file");
	} else {
		for(int i=0; strcmp(teachers[i].name,"")!=0; i++)
			fprintf(fp,"%s %s %s\n",teachers[i].name,teachers[i].id,teachers[i].pin);
	}
	fclose(fp);
}


