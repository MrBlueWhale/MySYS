#include "function.h"

//进入学生模块
void student() {
	pthread_t th1;
	int tmp=1800;   //定义初始化多线程用于计时，定为半小时。
	pthread_create(&th1, NULL, timer, &tmp);
	system("title 进入学生端");
	system("cls");
	system("COLOR fc");
	printf("\t\t\t\t\t\t╭  ─  ─  ─  ╮\n");
	printf("\t\t\t\t\t\t   登录成功！  \n");
	printf("\t\t\t\t\t\t╰  ━  ━  ━  ╯\n");
	puts("");
	puts("");
	printf("\n\t\t*=*=*=*=*=*=         Hello！%7s同学----欢迎来到算数小天才系统       =*=*=*=*=*\n", recentStudent->name);
	puts("");
	printf("\t\t************\t\t让我们来一场华丽丽的冒险，晋级学霸吧[]~(′▽`)~*\t\t**********\n");
	menuS();

}

char* password() {
	int k=0;
	char pin[20];
	while ((pin[k] = getch()) != '\r') {
		if((pin[k]=='\b')&&(k==0)) {
			//防止删除printf打出提示
		} else if(pin[k]=='\b') {
			putch('\b'); //光标左移到*之前
			putch(' '); // 用空格覆盖*
			putch('\b'); // 光标左移到空格之前
			k--;
		} else {
			putch ('*');
			k++;
		}
	}
	pin[k] = '\0';
	return pin;

}


//完成登陆，注册功能
//返回值为1进入学生模块
//返回值为0进入老师模块
int login() {
	system("title 登录注册页");

	system("cls");
	system("COLOR f5");
	int role;
	printf("\n\n\n\n\n");

	printf("\t\t\t\t      ▁▁▂▃▄▅▆▇█▇▆▅▄▃▂▁▁\n");


	printf("\t\t\t\t\t∵∴∵∴∵∴∵∴∵∴∵∴∵∴∵\n");
	printf("\t\t\t\t\t※                          ※\n");
	printf("\t\t\t\t\t※        (づ●─●)づ       ※\n");
	printf("\t\t\t\t\t※ 这里是算数小天才养成系统 ※\n");
	printf("\t\t\t\t\t※                          ※\n");

	printf("\t\t\t\t\t※ \t请选择您的身份:     ※\n");
	printf("\t\t\t\t\t※ \t  1 - 学生\t    ※\n");
	printf("\t\t\t\t\t※ \t  2 - 老师\t    ※\n");
	printf("\t\t\t\t\t※                          ※\n");
	printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
	printf("\t\t\t\t\t▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");

	printf("\n");
	printf("\t\t\t\t\t请选择：");

	do {
		role = getch();
		role-=48;
	} while (role != 1 && role != 2);
	putch(role+=48);
	role-=48;
	puts("");//输入防错处理


	if(role==1) {

		system("cls");
		printf("\n\n\n\t正在跳转入学生页面....");
		Sleep(1200);
		system("cls");
		char id[10]="\0";
		char pin[20]="\0";
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t  请登录\n\n");
		printf("\t\t\t\t\t  请输入账号:");
		scanf("%s",id);
		while(strlen(id)>10) {
			printf("\n\t\t\t\t\t  输入字符长度不正确，请重新输入\n");
			scanf("%s",id);
		}
		printf("\n\t\t\t\t\t  请输入密码:");
		strcpy(pin,password());
		while((strlen(pin)<6)||(strlen(pin)>20)) {
			printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
			strcpy(pin,password());
		}
		int judge=0;//判断是否找到该账户对应用户
		//遍历链表寻找该用户并判断密码与账号是否匹配
		for(PSt p=headStudent->next; p!=NULL; p=p->next) {
			if((strcmp(p->id,id)==0)&&(strcmp(p->pin,pin)==0)) {
				recentStudent = p;
				judge = 1;
				return 1;
			}
		}
		if(judge==0) {
			printf("\n\n\t\t\t\t\t  账号不存在或者账号与密码对应错误\n");
			sleep(1);
			login();
		}
	}//end if(role==1)
	else if(role==2) {
		system("cls");
		printf("\n\n\n\t正在跳转入教师页面....");
		Sleep(1200);
		system("cls");


		int choice;
		printf("\n\n\n\n\n");

		printf("\t\t\t\t      ▁▁▂▃▄▅▆▇█▇▆▅▄▃▂▁▁\n");


		printf("\t\t\t\t\t∵∴∵∴∵∴∵∴∵∴∵∴∵∴∵\n");
		printf("\t\t\t\t\t※                          ※\n");
		printf("\t\t\t\t\t※        (づ●─●)づ       ※\n");
		printf("\t\t\t\t\t※ 这里是算数小天才养成系统 ※\n");
		printf("\t\t\t\t\t※                          ※\n");

		printf("\t\t\t\t\t※ \t请选择您的操作:     ※\n");
		printf("\t\t\t\t\t※ \t  1 - 登录\t    ※\n");
		printf("\t\t\t\t\t※ \t  2 - 注册\t    ※\n");
		printf("\t\t\t\t\t※                          ※\n");
		printf("\t\t\t\t\t∴∵∴∵∴∵∴∵∴∵∴∵∴∵∴\n");
		printf("\t\t\t\t\t▁▁▁▁▁▁▁▁▁▁▁▁▁▁▁\n");

		printf("\n");
		printf("\t\t\t\t\t请选择：");

		do {
			choice = getch();
			choice-=48;
		} while (choice != 1 && choice != 2);
		putch(choice+=48);
		choice-=48;
		puts("");//对输入做防错处理

		if(choice ==1) {
			system("cls");
			char id[10]="\0";
			char pin[20]="\0";
			printf("\n\n\n\n\n");
			printf("\t\t\t\t\t  请登录\n");
			printf("\n\t\t\t\t\t  请输入账号:");
			scanf("%s",id);
			while(strlen(id)>10) {
				printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
				scanf("%s",id);
			}
			printf("\n\t\t\t\t\t  请输入密码:");
			strcpy(pin,password());
			while((strlen(pin)<6)||(strlen(pin)>20)) {
				printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
				strcpy(pin,password());
			}
			int judge=0;//判断是否找到该账户对应用户
			//遍历结构体数组判断老师的账号密码是否匹配
			for(int i=0; strcmp(teachers[i].name,"")!=0; i++) {
				if((strcmp(teachers[i].id,id)==0)&&(strcmp(teachers[i].pin,pin)==0)) {
					tab = i;
					judge = 1;
				}
			}
			if(judge==0) {
				printf("\n\n\t\t\t\t\t  账号不存在或者账号与密码对应错误\n");
				login();
			}
		}//ioce1-登录
		else if(choice==2) {
			int i;
			system("cls");
			printf("\n\n\n");
			printf("\n\n\t\t\t\t\t  请输入密钥:");
			char secret[10];
			strcpy(secret,password());
			while(strlen(secret)>6) {
				printf("\n\n\t\t\t\t\t  输入字符长度过长，请重新输入:");
				strcpy(secret,password());
			}
			if(strcmp(secret,"123abc")!=0) {
				printf("\n\n\t\t\t\t\t  密钥验证失败\n");
				sleep(1);
				login();
			}
			system("cls");
			char id[10]="\0";
			char pin[20]="\0";
			char name[20] = "\0";
			printf("\n\n\n\t\t\t\t\t  请注册\n");
			printf("\n\t\t\t\t\t  请输入用户名:");
			scanf("%s",name);
			while(strlen(name)>20) {
				printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
				scanf("%s",name);
			}
			printf("\n\t\t\t\t\t  请输入账号:");
			scanf("%s",id);
			while(strlen(id)>10) {
				printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
				scanf("%s",id);
			}
			printf("\n\t\t\t\t\t  请输入密码:");
			strcpy(pin,password());
			while((strlen(pin)<6)||(strlen(pin)>20)) {
				printf("\n\n\t\t\t\t\t  输入字符长度不正确，请重新输入:");
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
			printf("\n\n\n\t\t\t\t\t  注册成功!\n");
			sleep(1);
			login();

		}//end if choice==2
		return 0;
	}//end if role==2

}



//展示学生页面菜单，接受输入并进行相应操作
void menuS() {


	while(1) {

		system("COLOR fc");
		system("title 学生端主菜单");
		//bool inputError = false;  //标记用户是否输入了非有效序号
		printf("\n\n\t\t\t\t       ==========你可以使用以下功能：==========\n\n");
		printf("\t\t\t\t\t   ┍──  ──  ──  ──  ──  ──┑\n\n");
		printf("\t\t\t\t\t   ┃\t --1-基础测试\t  ┃\n\n");
		printf("\t\t\t\t\t   \t --2-综合测试\n\n");
		printf("\t\t\t\t\t   ┃\t --3-游戏模式	  ┃\n\n");
		printf("\t\t\t\t\t   \t --4-小测 \n\n");
		printf("\t\t\t\t\t   ┃\t --5-查询	  ┃\n\n");
		printf("\t\t\t\t\t   \t --6-修改密码\n\n");
		printf("\t\t\t\t\t   ┃\t --0-退出	  ┃\n\n");
		printf("\t\t\t\t\t   ┕──  ──  ──  ──  ──  ──┙\n\n");

		printf("\t\t★请你选择要使用哪个功能叭(*’U`*):");

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
		choice = option1;//对输入做防错处理


		//do { //使用循环主要是为了解决default的情况
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

//展示基础测验的菜单，接受输入并进行相应操作
void menuS_base() {
	system("title 学生端---基础测试页");
	int time = 0;

	while (1) {
		system("COLOR b0");
		system("cls");
		if (time == 0) {
			printf("\n\n\t\t\t\t\t   欢迎来到基础测试板块ヽ(≧v≦)ｄ\n");
			printf("\n\n\t\t\t\t\t在这里你可以进行加减乘除的单项测试哦！\n\n");
			time++;
		} else {
			printf("\n\n\t\t\t\t\t      ===想要继续挑战吗？===\n\n");
		}

		printf("\t\t\t\t\t    ┍──  ──  ──  ──  ──  ──┑\n\n\n");
		printf("\t\t\t\t\t    ┃\t --1-加法自测\t   ┃\n\n");
		printf("\t\t\t\t\t    \t --2-减法自测\n\n");
		printf("\t\t\t\t\t    ┃\t --3-乘法自测	   ┃\n\n");
		printf("\t\t\t\t\t    \t --4-除法自测 \n\n");
		printf("\t\t\t\t\t    ┃\t --0-返回主菜单	   ┃\n\n");
		printf("\t\t\t\t\t    ┕──  ──  ──  ──  ──  ──┙\n\n");

		printf("\t\t★请选择你要使用的功能叭(~*v*~):");
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
		choice = option1;//对输入做防错处理


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

//展示学生查询信息的菜单，接受输入并进行相应操作
void menuS_inquiry() {
	system("title 学生端---信息查询页");
	system("cls");
	int time = 0;

	while (1) {
		system("cls");
		system("COLOR 60");
		if (time == 0) {
			printf("\n\n\t\t\t\t\t    欢迎来到查询板块ヽ(≧v≦)ｄ\n");
			printf("\n\n\t\t\t\t\t在这里你可以查看自己的各种记录哦！\n\n");
			time++;
		} else {
			printf("\n\n\t\t\t\t\t     ===想瞅瞅更多内容吗？===\n\n");
		}

		printf("\t\t\t\t\t    ┍──  ──  ──  ──  ──  ──┑\n\n");
		printf("\t\t\t\t\t    ┃\t --1-查看错题本\t   ┃\n\n");
		printf("\t\t\t\t\t    \t --2-查看成绩记录\n\n");
		printf("\t\t\t\t\t    ┃\t --3-查看老师评语  ┃\n\n");
		printf("\t\t\t\t\t    ┃\t --0-返回主菜单	   ┃\n\n");
		printf("\t\t\t\t\t    ┕──  ──  ──  ──  ──  ──┙\n\n");

		printf("\t\t★请选择你要使用的功能叭(~*v*~):");
		int choice = 0;

		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0);
		putch(choice+=48);
		choice-=48;
		puts("");//对输入做防错处理


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


		//防止被直接清屏代码块
		printf("\n\t\tTip:按任意键返回上级菜单哦！！！\n\n");
		system("pause");
		printf("\n\t\t页面跳转成功..\n");
		Sleep(800);

		//


	}
}


//退出学生系统
void outStudent() {
	system("title 学生端系统出口");
	system("cls");
	system("COLOR 70");
	printf("\n\t\t\t\t天才也要勤奋努力，记得多多回来练习哦！＼\(*◎ｖ◎*)//\n");
	Sleep(2300);
	saveStudentFile();
	printf("\n\t\t\t\t系统退出中...\n");
	Sleep(1500);
	printf("\n\t\t\t\t退出成功！\n");
	exit(0);
}

//对自测结果进行评价
//如果正确率高于0.9，输出 你真棒
//如果正确率为0.8-0.9 输出 还不错哦
//如果正确率为0.6-0.8 输出 还不错，但还需努力哦
//如果正确率小于0.6 输出 不及格呢，要多加练习
void judge(double n,int right,int num) {  //n为正确率  right为答对的题数  num大的总题数
	system("cls");
	printf("(^v^)☆你一共做了%d道算数题，正确了%d道，正确率为：%.2f%%\n",num,right,n*100);
	sleep(2);
	printf("\n");
	if(n>=0.9) {
		MessageBox(0, _T("棒棒哒！！\n"), _T("算数小天才"), MB_OK);
	} else if(n>=0.8) {
		MessageBox(0, _T("哎哟~还不错哦!\n"), _T("算数小天才"), MB_OK);
		//printf("哎哟~还不错哦!\n");
	} else if(n>=0.6) {
		MessageBox(0, _T("还不错哒，但还需努力哦\n"), _T("算数小天才"), MB_OK);
		//printf("还不错哒，但还需努力哦\n");
	} else {
		MessageBox(0, _T("不及格呢，要多加练习哦\n"), _T("算数小天才"), MB_OK);
		//printf("不及格呢，要多加练习哦\n");
	}

}

//对答案判断的结果进行处理
//如果result为 1，即答案正确，提醒正确并开始下一题
//如果result为 0，即答案错误，提示正确答案并提示是否保存
void solution(int result) {
	if(result==1) {
		printf("  耶！做对啦！\n");
		Sleep(700);
	} else {
		printf("  啊哦~做错啦~\n");
		printf("  %s\n",recentTopic);
		Sleep(700);
		printf("  要保存到错题本中吗？（1表示要，0表示不要）\n");
		printf("  选择:");
		int iif;
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice!=0);
		putch(choice+=48);
		choice-=48; //option1==0或option1==1
		puts("");

		if(iif==1) {
			addMistake(recentTopic);
		}

	}


}

void addMistake(char x[20]) {

	FILE* fout;
	if((fout=fopen(recentStudent->mistakeFileName,"a"))==NULL) {
		printf("文件打开失败\n");
	} else {
		fprintf(fout,"%s\n",x);//添加错题
	}
	fclose(fout);
}


////////////////////////////////分数运算辅助函数
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

//将分数化为最简形式
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

//在规定时间到达的时候，提醒休息
void * timer(void *a) { //计时函数 （规定时间计时）
	int* n=(int*)a;

	while(1) {
		double startTime=clock();
		double endTime=clock();

		while((double)(endTime-startTime)/CLK_TCK<=(*n)) {
			endTime=clock();
		}

		sprintf(testTimeTips,"%d秒已到，累计练习时间已达%d秒！注意多加休息哦!",*n,(timeNum)*(*n));
		MessageBox(0, _T(testTimeTips), _T("算数小天才"), MB_OK);
		timeNum++;
		//printf("%d",timeNum);



	}
	//printf("10秒已到");
}

///////////////////////////////////////////////////


//完成加法自测模块操作
void plus() {

	system("title 加法自测模式");
	system("cls");
	system("COLOR E0");
	printf("现在开始加法自测，你准备好了吗？\n");
	Sleep(1800);
	int choice;
	//难度选择
	printf("\t☆☆请选择难度☆☆\n");
	printf("  ●1-易\n");
	printf("  ●2-中\n");
	printf("  ●3-难(小数)\n");
	printf("  ●4-难(分数)\n");
	printf("  选择:");

//	while
	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48;
	puts("");//对输入做防错处理


	int num;//记录自定义题量
	int result; //判断输入的答案是否正确
	int right=0;//记录正确题数
	printf("  ☆☆请输入你想做的题量:");
	scanf("%d",&num);
	fflush(stdin);
	while(num<=0) {
		printf("  ☆☆输入有误，请输入正整数：");
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
	// 更新加法正确率
	recentStudent->plusCorrect=
	    ((recentStudent->plusCorrect)*(recentStudent->plusNum)
	     +right)/(recentStudent->plusNum+num);
	//更新所做加法题数
	recentStudent->plusNum+=num;

	printf("\n\no(^▽^)oo恭喜你已经完成了本次练习，返回基础测试菜单中...");
	Sleep(2600);
	system("cls");
	return;

}

//完成产生算式并判断正误
//返回值1表示结果正确
//返回值0表示结果错误
//参数由1-3表示难度增加
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
		printf("  ⊙ %d + %d = ",a,b);
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
		printf("  ⊙ %d + %d + %d = ",a,b,c);
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
		printf("  ⊙ %.2f + %.2f + %.2f = ",a,b,c);
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
			a = rand() % 10 + 1;//第一个分数的分子
			//a=8;
			b = rand() % 10 + 1;//第一个分数分母
			//b=6;
			c = rand() % 10 + 1;//第二个分数分子
			// c=8;
			d = rand() % 10 + 1;//第二个分数分母
			// d=12;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//答案中的分子
		int f=0;//答案中的分母
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
			printf("  ⊙ %d + %d/%d = ", a,c,d);

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
			printf("  ⊙ %d/%d + %d = ", a, b,c);

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
			printf("  ⊙ %d/%d + %d/%d = ", a, b,c,d);
		}

		scanf("%s", answerOfStu);
		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//完成减法自测模块
void minus() {
	system("title 减法自测模式");
	system("cls");
	system("COLOR E0");
	printf("现在开始减法自测，你准备好了吗？\n");
	Sleep(1800);
	int choice;
	printf("\t☆☆请选择难度☆☆\n");
	printf("  ●1-易\n");
	printf("  ●2-中\n");
	printf("  ●3-难(小数)\n");
	printf("  ●4-难(分数)\n");
	printf("  选择:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48; //option1==0或option1==1
	puts("");

	int num;//记录自定义题量
	int x=1;//判断输入数据类型是否正确
	int result; //判断输入的答案是否正确
	int right=0;//记录正确题数
	printf("  ☆☆请输入你想做的题量:");
	scanf("%d",&num);
	fflush(stdin);
	while(num<=0) {
		printf("  ☆☆输入有误，请输入正整数：");
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
	//更新减法正确率
	recentStudent->minusCorrect=
	    ((recentStudent->minusCorrect)*(recentStudent->minusNum)
	     +right)/(recentStudent->minusNum+num);
	//更新减法题数
	recentStudent->minusNum+=num;

	printf("\n\no(^▽^)oo恭喜你已经完成了本次练习，返回基础测试菜单中...");
	Sleep(2600);
	system("cls");
	return;

}

//完成产生减法算式并判断结果正误
//返回值为1表示结果正确
//返回值为0表示结果错误
//参数由1-3表示难度增加
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
		printf("  ⊙ %d - %d = ",a,b);
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
		printf("  ⊙ %d - %d - %d = ",a,b,c);
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
		printf("  ⊙ %.2f - %.2f - %.2f = ",a,b,c);
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
			a = rand() % 10 + 1;//第一个分数的分子
			//a=1;
			b = rand() % 10 + 1;//第一个分数分母
			//b=5;
			c = rand() % 10 + 1;//第二个分数分子
			//c=2;
			d = rand() % 10 + 1;//第二个分数分母
			//d=2;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//答案中的分子
		int f=0;//答案中的分母
		subPlusForFraction(a,b,c,d,&e,&f); //系统先完成加法分数

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
			printf("  ⊙ %d - %d/%d = ", e,a,b);

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
			printf("  ⊙ %d/%d - %d = ", e, f,a);
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
			printf("  ⊙ %d/%d - %d/%d = ", e, f,a,b);

		}

		scanf("%s", answerOfStu);

		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//完成乘法自测模块
void multiply() {
	system("title 乘法自测模式");
	system("cls");
	system("COLOR E0");
	printf("现在开始乘法自测，你准备好了吗？\n");
	Sleep(1800);
	int choice = 0;
	printf("\t☆☆请选择难度☆☆\n");
	printf("  ●1-易\n");
	printf("  ●2-中\n");
	printf("  ●3-难(小数)\n");
	printf("  ●4-难(分数)\n");
	printf("  选择:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48; //option1==0或option1==1
	puts("");


	int num;//记录自定义题量
	int result; //判断输入的答案是否正确
	int rightNum = 0;//记录正确题数
	printf("  ☆☆请输入你想做的题量:");
	scanf("%d", &num);
	fflush(stdin);
	while(num <= 0) {
		printf("  ☆☆错啦错啦，题量要输入正整数：");
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
			printf("小数结果记得保留两位小数哦！\n");
			printf("小数结果记得保留两位小数哦！\n");
			printf("小数结果记得保留两位小数哦！\n");
			printf("重要的事情说三遍！！！\n");
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
	// 更新乘法正确率
	recentStudent->multiplyCorrect =
	    ((recentStudent->multiplyCorrect) * (recentStudent->multiplyNum)
	     + rightNum) / (recentStudent->multiplyNum + num);
	//更新所做乘法题数
	recentStudent->multiplyNum += num;

	printf("\n\no(^▽^)oo恭喜你已经完成了本次练习，返回基础测试菜单中...");
	Sleep(2600);
	system("cls");
	return;

}

//完成产生乘法算式并判断结果正误
//返回值为1表示结果正确
//返回值为0表示结果错误
//参数由1-3表示难度增加
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
		sprintf(str,"%d×%d=%d",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %d × %d = ", a, b);
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
		sprintf(str,"%d×%d×%d=%d",a,b,c,d);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %d × %d × %d = ", a, b, c);
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
		sprintf(str,"%.1lf×%.1lf=%.2f",a,b,d);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %.1lf × %.1lf= ", a, b);
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
			a = rand() % 10 + 1;//第一个分数的分子
			//a=8;
			b = rand() % 10 + 1;//第一个分数分母
			//b=1;
			c = rand() % 10 + 1;//第二个分数分子
			//c=8;
			d = rand() % 10 + 1;//第二个分数分母
			// d=12;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//答案中的分子
		int f=0;//答案中的分母
		subMultiplyForFraction(a,b,c,d,&e,&f);

		char ee[10];
		itoa(e,ee,10);
		char ff[10];
		itoa(f,ff,10);

		if(b==1) {
			sprintf(recentTopic,"%d×%d/%d=%d",a,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  ⊙ %d × %d/%d = ", a,c,d);

		} else if(d==1) {
			sprintf(recentTopic,"%d/%d×%d=%d",a,b,c,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  ⊙ %d/%d × %d = ", a, b,c);

		} else {
			sprintf(recentTopic,"%d/%d×%d/%d=%d",a,b,c,d,e);
			strcpy(answer, ee);

			if(f==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, ff);
				strcat(answer, "/");
				strcat(answer, ff);
			}

			//printf("%s",recentTopic);
			printf("  ⊙ %d/%d × %d/%d = ", a, b,c,d);
		}

		scanf("%s", answerOfStu);
		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//完成除法自测模块
void divide() {
	system("title 除法自测模式");
	system("cls");
	system("COLOR E0");
	printf("现在开始除法自测，你准备好了吗？\n");
	Sleep(1800);
	int choice = 0;
	printf("\t☆☆请选择难度☆☆\n");
	printf("  ●1-易\n");
	printf("  ●2-中\n");
	printf("  ●3-难(小数)\n");
	printf("  ●4-难(分数)\n");
	printf("  选择:");

	do {
		choice = getch();
		choice-=48;
	} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=4);
	putch(choice+=48);
	choice-=48;
	puts("");//对输入做防错处理


	int num;//记录自定义题量
	int x = 1;//判断输入数据类型是否正确
	int result; //判断输入的答案是否正确
	int rightNum = 0;//记录正确题数
	printf("  ☆☆请输入你想做的题量:");
	scanf("%d", &num);
	fflush(stdin);
	while (num <= 0) {
		printf("  ☆☆错啦错啦，题量要输入正整数：");
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
			printf("小数结果记得保留两位小数哦！\n");
			printf("小数结果记得保留两位小数哦！\n");
			printf("小数结果记得保留两位小数哦！\n");
			printf("重要的事情说三遍！！！\n");
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
	// 更新除法正确率
	recentStudent->divideCorrect =
	    ((recentStudent->divideCorrect) * (recentStudent->divideNum)
	     + rightNum) / (recentStudent->divideNum + num);
	//更新所做除法题数
	recentStudent->divideNum += num;

	printf("\n\no(^▽^)oo恭喜你已经完成了本次练习，返回基础测试菜单中...");
	Sleep(2600);
	system("cls");
	return;
}

//完成产生除法算式并判断结果正误
//返回值为1表示结果正确
//返回值为0表示结果错误
//参数由1-3表示难度增加
//完成产生除法算式并判断结果正误
//返回值为1表示结果正确
//返回值为0表示结果错误
//参数由1-3表示难度增加
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
		sprintf(str,"%d÷%d=%d",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %d ÷ %d = ", a, b);
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
		int b = rand() % 71 + 10;  //0~90   //最终答案落在这个范围
		int c = rand() % 10 + 1;
		int d = a * b * c;
		char bb[10];
		sprintf(bb, "%d", b);
		char str[20] = "";
		sprintf(str,"%d÷%d÷%d=%d",d,a,c,b);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %d ÷ %d ÷ %d = ", d, a, c);
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
		sprintf(str,"%.2lf÷%.1lf=%.2lf",a,b,c);
		strcpy(recentTopic,str);
		char answer[10];
		printf("  ⊙ %.2lf ÷ %.1lf = ", a, b);
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
			a = rand() % 10 + 1;//第一个分数的分子
			//a=5;
			b = rand() % 10 + 1;//第一个分数分母
			//b=1;
			c = rand() % 10 + 1;//第二个分数分子
			//c=8;
			d = rand() % 10 + 1;//第二个分数分母
			//d=3;
			simplify(&a,&b);
			simplify(&c,&d);
		} while(d==1&&b==1);

		char answerOfStu[10]="";
		char answer[10]="";

		int e=0;//答案中的分子
		int f=0;//答案中的分母
		subMultiplyForFraction(a,b,c,d,&e,&f); //系统先完成乘法分数

		char cc[10];
		itoa(c,cc,10);
		char dd[10];
		itoa(d,dd,10);

		if(f==1) {
			sprintf(recentTopic,"%d÷%d/%d=%d",e,a,b,c);
			strcpy(answer, cc);
			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  ⊙ %d ÷ %d/%d = ", e,a,b);

		} else if(b==1) {
			sprintf(recentTopic,"%d/%d÷%d=%d",e,f,a,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  ⊙ %d/%d ÷ %d = ", e, f,a);

		} else {
			sprintf(recentTopic,"%d/%d÷%d/%d=%d",e,f,a,b,c);
			strcpy(answer, cc);

			if(d==1) {

			} else {
				strcat(recentTopic, "/");
				strcat(recentTopic, dd);
				strcat(answer, "/");
				strcat(answer, dd);
			}
			printf("  ⊙ %d/%d ÷ %d/%d = ", e, f,a,b);

		}

		scanf("%s", answerOfStu);

		if (strcmp(answerOfStu,answer) == 0) {
			return 1;
		} else {
			return 0;
		}
	}
}

//完成综合测试模块
void comTest() {
	system("title 综合自测模式");
	system("cls");
	system("COLOR E0");
	int number,part,difficulty,flag,option,count=0;
	printf("  现在开始综合测试，你准备好了吗？\n");
	printf("  ☆☆请输入自定义题量：");
	scanf("%d",&number);
	fflush(stdin);
	while((number<=0)) {
		printf("  ☆☆输入有误，请输入正整数：");
		scanf("%d",&number);
		fflush(stdin);
		puts("");
	}


	for(int i =0; i<number; i++) { //按自定义题量出题
		part = rand()%5 +1;
		difficulty = rand()%3+1;
		flag = comTestDemo(part,difficulty);//标记当前题目正误
		if(flag==0) {
			count++; //错题数+1
			printf("  ⊙ 啊哦(!)_(!)错啦！\n");
			printf("  ⊙ 正确答案:%s\n",recentTopic);
			printf("  ⊙ 是否将该题保存至错题本？\n");
			printf("  1-(提取题型)我要保存！\n");
			printf("  0-(纯粹马虎)不保存了，继续做题！\n");
			printf("  选择:");
			do {
				option = getch();
				option-=48;
			} while ( option != 1 && option!=0);
			putch(option+=48);
			option-=48; //option1==0或option1==1
			puts("");


			if(option == 1) {
				addMistake(recentTopic);// 梁堉实现
			}
		}
	}
	judge((double)(number-count)/number,(number-count),number);

	printf("\n\no(^▽^)oo恭喜你已经完成了本次练习，正在传送回上级菜单中...");
	Sleep(2600);
	system("cls");
	return;

}

//完成产生综合出题并判断结果正误
//返回值为1表示结果正确
//返回值为0表示结果错误
//difficulty，1-3表示难度增加
//part为出题部分 1--5 代表加减乘除和混合运算
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
			char str[30]="";//保存当前题目

			switch(difficulty) { //按难度划分混合题目
					srand((unsigned)time(NULL));

					int type;
					int a,b,c;
					type=rand()%3 + 1;//随机的混合运算类型

				case 1: {
					while(1) {

						a = rand()%100 + 1 ;
						b = rand()%100 + 1 ;
						c = rand()%100 + 1 ;

						int result;

						if((a+b-c)>0&&(a-b+c)>0) {
							if(type == 1) {

								system("cls");
								printf("  ⊙ %d + %d - %d =",a,b,c);
								sprintf(str,"%d+%d-%d=%d",a,b,c,a+b-c);//将当前题目保存到str中

								scanf("%d",&result);
								if(result == a+b-c)
									return 1;  //正确返回 1
								else {
									strcpy(recentTopic ,str);//错误， 将当前题目写入recentTopic，返回0；
									return 0;
								}

							} else if(type == 2) {

								system("cls");
								printf("  ⊙ %d - %d + %d =",a,b,c);
								sprintf(str,"%d-%d+%d=%d",a,b,c,a-b+c);
								scanf("%d",&result);
								if(result == a-b+c)
									return 1;  //正确返回 1
								else {
									strcpy(recentTopic ,str);//错误， 将当前题目写入recentTopic，返回0；
									return 0;
								}

							} else {

								system("cls");
								printf("  ⊙ %d × %d + %d =",a,b,c);
								sprintf(str,"%d*%d+%d=%d",a,b,c,a*b+c);

								scanf("%d",&result);
								if(result ==a*b+c)
									return 1;  //正确返回 1
								else {
									strcpy(recentTopic ,str);//错误， 将当前题目写入recentTopic，返回0；
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
								printf("  ⊙ ( %d + %d ) x %d =",a,b,c);
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
								printf("  ⊙ ( %d - %d ) ÷ %d =",a,b,c);
								sprintf(str,"(%d-%d)÷%d=%.1lf",a,b,c,(double)(a-b)/c);
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
								printf("  ⊙ %d x %d ÷ %d =",a,b,c);
								sprintf(str,"%dx%d÷%d=%.1lf",a,b,c,(double)a*b/c);
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
								printf("  ⊙ %.1lf x %.1lf - %.1lf =",a,b,c);
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
								printf("  ⊙ %.1lf ÷ %.1lf + %.1lf =",a,b,c);
								sprintf(str,"%.1lf÷%.1lf+%.1lf=%.1lf",a,b,c,a/b+c);
								scanf("%lf",&result);

								if(fabs(result - ( a /b +c ) )<=0.01)

									return 1;
								else  {
									strcpy(recentTopic ,str) ;
									return 0;
								}
							} else {

								system("cls");
								printf("  ⊙%.1lf x %.1lf ÷ %.1lf =",a,b,c);
								sprintf(str,"%.1lfx%.1lf÷%.1lf=%.1lf",a,b,c,a*b/c);
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

//完成游戏模块
void game() {
	system("title 游戏模式");
	system("COLOR E0");
	system("cls");
	int option2,part,difficulty,flag = 1,count=0;

	printf("\n\n\t\t\t\t\t    欢迎来到游戏板块ヽ(≧v≦)ｄ\n");
	Sleep(2300);
	printf("\n\n\t\t\t\t\t  这是我们精心为你准备的特别模式\n\n");
	Sleep(2700);
	printf("\n\t\t\t\t\t\t预祝你玩的愉快！！！\n\n");
	Sleep(1700);

	printf("\n\t\t\t\t\t\t*****************\n");
	printf("\n\t\t\t\t\t\t**  1-无尽模式 **\n") ;
	printf("\n\t\t\t\t\t\t**  2-闯关模式 **\n") ;
	printf("\n\t\t\t\t\t\t*****************\n");
	printf("\n\t\t\t\t\t 请正确选择挑战模式：");

	int option1;
	do {
		option1 = getch();
		option1-=48;
	} while ( option1 != 1 && option1 != 2);
	putch(option1+=48);
	option1-=48;
	puts("");//对输入做防错处理



	if(option1 ==1) { //选择无尽模式
		printf("\n\t\t\t\t\t无尽模式-答题直到出错为止\n");
		while(1) { //一直随机出题
			part = rand()%5 +1;
			difficulty = rand()%3+1;
			flag = comTestDemo(part,difficulty);//标记当前题目作答对错
			count++;//记录答对的题目数

			if(flag == 0) { //出错后，是否更新记录?,打印信息，选择是否保存错题？，退出
				if(count > recentStudent->gameNum) {
					recentStudent->gameNum = count ;
					printf("\t\t\t\t\t新的记录！\n");
				}
				printf("\n\t\t\t\t\t挑战结束，你答到了第%d题.\n",count);
				printf("\t\t\t\t\t正确答案:%s\n",recentTopic);
				printf("\t\t\t\t\t是否将该题保存至错题本？\n");
				printf("\t\t\t\t\t1-保存\n");
				printf("\t\t\t\t\t2-退出\n");
				printf("\t\t\t\t\t选择:");
				do {
					option2 = getch();
					option2-=48;
				} while(option2 != 1 && option2 != 2 );
				putch(option2+48);


				if(option2 == 1) {
					addMistake(recentTopic);
					printf("\t\t\t\t\t保存成功！\n");
					break;
				} else if(option2 == 2)
					break;
			}
		}
	} else { //选择闯关模式
		printf("\n\t\t\t\t\t闯关模式-十题全对即过关\n");
		for(int i = 0; i<10; i++) {
			part = rand()%5 +1;
			difficulty = rand()%3+1;
			flag = comTestDemo(part,difficulty);
			count++;      //记录答到的题号
			if(flag == 0) { //答错了
				printf("\n\t\t\t\t\t闯关失败！\n");
				printf("\t\t\t\t\t挑战结束，你答到了第%d题.\n",count);
				printf("\t\t\t\t\t正确答案:%s\n",recentTopic);
				printf("\t\t\t\t\t是否将该题保存至错题本？\n");
				printf("\t\t\t\t\t1-保存\n");
				printf("\t\t\t\t\t2-退出\n");
				do {
					option2 = getch();
					option2-=48;
				} while(option2 != 1 && option2 != 2 );

				if(option2 == 1) {
					addMistake(recentTopic);
					printf("保存成功！\n");
					break;
				} else if(option2 == 2)
					break;
			}
		}
		if(count == 10&&flag == 1) { //没有出错 ，打印信息
			printf("闯关成功!");
			recentStudent->gameLevel +=1; //更新关卡数
			printf("当前一共闯了%d关",recentStudent->gameLevel);
			sleep(1);
		}
	}
	system("cls");
	printf("即将返回主菜单......请稍后\n");
	Sleep(2500);
	system("cls");


}


//学生和老师可修改密码
void modifyPin(int role) {
	system("title 密码修改页");
	char pin1[20];
	char pin2[20];
	system("cls");
	bool ifPinEqual = true;   //用来标记两次密码是否相同
	do {
		printf("\n\n\t\t\t\t请输入新密码:");
		strcpy(pin1,password());
		puts("");
		while((strlen(pin1)<6)||(strlen(pin1)>20)) {
			printf("\t\t\t\t密码长度至少六位，至多二十位，请重新输入叭：");
			strcpy(pin1,password());
			puts("");
		}
		printf("\n\t\t\t\t请确认你输入的新密码：");
		strcpy(pin2,password());
		puts("");
		while((strlen(pin1)<6)||(strlen(pin1)>20)) {
			printf("\t\t\t\t密码长度至少六位，至多二十位，请重新输入叭：");
			strcpy(pin1,password());
			puts("");
		}

		if(strcmp(pin1,pin2)!=0) {
			ifPinEqual = false;
			printf("\n\t\t\t\t两次输入的密码不一致，请重新输入!\n");
			Sleep(900);
			system("cls");
		} else
			ifPinEqual = true;

	} while(!ifPinEqual);

	if(role==1) {
		strcpy(recentStudent->pin,pin1);
		system("cls");
		printf("\t\t\t\t修改成功！正在跳转回主页面...\n");
		Sleep(1000);
		system("cls");


	} else if(role==0) {
		strcpy(teachers[tab].pin,pin1);
		system("cls");
		printf("\t\t\t\t修改成功！正在跳转回主页面...\n");
		Sleep(1000);
		system("cls");
		menuT();
	}


}


//完成小测模块
void test() {
	system("title 小测模式");
	system("cls");
	printf("\n\t\t\t\t\t下面进行小测，20分钟，共20题，总分一百分，计算结果保留两位小数\n");

	int flag = 1,
	    count = 0,
	    part,difficulty,
	    number = 0,
	    choice;//flag记录出题函数返回值，标记当前题目是否正确
	int grade;
	char str[20][40] = {{0}}; //用于存储错题
	int scorePerQuestion = 5; //每题5分
	int tmp=1200;

	printf("\t\t\t\t\t开始小测\n");//1200秒 20分钟
	int i;

	double startTime = clock();
	for(i =0; i<20; i++) { //出20道题

		double endTime = clock();

		if((double)(endTime-startTime)/CLK_TCK >= tmp) {

			printf("\n\t\t\t\t\t时间到了!!!");
			Sleep(1000) ;
			break;
		}

		printf("\n");
		part = rand()%5 +1;
		difficulty = rand()%3+1;
		flag = comTestDemo(part,difficulty);

		if(flag ==0 ) { //每次出错count++，并把当前题目写入str数组

			count++;
			strcpy(str[number],recentTopic);
			number ++ ;
		}

	}
	grade = 100 - count*scorePerQuestion; //计算此次测验成绩
	recentStudent->testNum += 1;//更新小测次数

	for(int j=0; j<20; j++) { //添加小测成绩，遍历到 0 则添加成绩

		if(recentStudent->grade[j] ==0) {
			recentStudent->grade[j]= grade;
			break;
		}
	}
	int total = 0;

	for(int k=0; recentStudent->grade[k]!=0; k++) {
		total+=recentStudent->grade[k];
		recentStudent->testGrade = (double)total/(k+1);//更新小测均分
	}

	judge((double)(i-count)/i,i-count,i); //评价此次小测
	printf("\t\t\t\t\t你的得分为%d分，继续努力！\n",grade);
	printf("\t\t\t\t\t出错的题目如下：\n");

	for(int i = 0; i<number; i++) {
		printf("\t\t\t\t\t\t●%s\n\n",str[i]);
	}

	printf("\n");
	printf("\t\t\t\t\t是否保存错题？\n");
	printf("\t\t\t\t\t1-保存;");
	printf("\t\t\t\t\t2-不保存");
	printf("\n\t\t\t\t\t选择:");
	do {
		choice = getch();
		choice-=48;
	} while(choice != 1 && 	choice != 2 );
	putch(choice+=48);
	choice-=48;
	puts("");


	if(choice == 1) {
		for(int i=0; i<number; i++) {
			addMistake(str[i]);//将str数组中的错题全部加入错题本
		}
		printf("\n\t\t\t\t\t保存成功！\n");
	}


	printf("\n\t\t\t\t\t即将返回主菜单......请稍后");
	Sleep(2500);
	system("cls");


}


//查询错题本
void printMistake() {
	system("title 查看错题本");
	system("cls");
	system("COLOR c0");
	FILE* fin;
	if((fin=fopen(recentStudent->mistakeFileName,"r"))==NULL) {
		printf("文件打开失败\n");
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
				printf("\n\tヾヾ 千里之堤，以蝼蚁之穴溃；百尺之室，以突隙之烟焚。 ——《韩非子集注喻志》\n\n");
				break;
			case 2:
				printf("\n\tヾヾ 我能想象到的人的最高尚行为，除了传播真理外，就是公开放弃错误。 ——利斯特\n\n");
				break;
			case 3:
				printf("\n\tヾヾ 每个人都有错，但只有愚者才会执迷不悟。 ——西塞罗\n\n");
				break;
			case 4:
				printf("\n\tヾヾ 一个人知道了自己的短处，能够改过自新，就是有福的。 ——莎士比亚《无事生非》\n\n");
				break;
			case 5:
				printf("\n\tヾヾ 犯错误乃是取得进步所必须交付的学费。 ——卢那察尔斯基\n\n");
				break;

		}

		printf("\t\t\t《%7s小盆友的错题集》\n\n",recentStudent->name);
		printf("\t\t   ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n\n");

		for(int i=0; i<size; i++) {
			puts("");
			s[i]=(char*)strings[i];
			printf("\t\t\t▼ヘ%-15s\n",s[i]);
		}
		puts("");
		printf("\n\t\t   ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n\n");

	}
	fclose(fin);

}

//查询成绩
void viewGrade() {
	system("title 学生端---个人生涯");
	system("cls");
	system("COLOR c0");
	printf("\n\t\t\t〒〒%7s小盆友当前的战绩榜 〒〒\n\n",recentStudent->name);
	printf("\n\t\t   ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n\n");

	printf("\t\t\t▼ヘ小测平均成绩: \t%-.2f\n",recentStudent->testGrade);
	printf("\t\t\t▼ヘ游戏闯关模式当前关卡:%-d\n",recentStudent->gameLevel);
	printf("\t\t\t▼ヘ游戏无尽模式最大题数:%-d\n",recentStudent->gameNum);
	printf("\t\t\t▼ヘ加法自测正确率: \t%-.2f\n",recentStudent->plusCorrect);
	printf("\t\t\t▼ヘ加法自测做题数: \t%-d\n",recentStudent->plusNum);
	printf("\t\t\t▼ヘ减法自测正确率: \t%-.2f\n",recentStudent->minusCorrect);
	printf("\t\t\t▼ヘ减法自测做题数: \t%-d\n",recentStudent->minusNum);
	printf("\t\t\t▼ヘ乘法自测正确率: \t%-.2f\n",recentStudent->multiplyCorrect);
	printf("\t\t\t▼ヘ乘法自测做题数: \t%-d\n",recentStudent->multiplyNum);
	printf("\t\t\t▼ヘ除法自测正确率: \t%-.2f\n",recentStudent->divideCorrect);
	printf("\t\t\t▼ヘ除法自测做题数: \t%-d\n",recentStudent->divideNum);

	printf("\n\t\t   ∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞∞\n\n");

}

//查看教师评价
void evaluation() {
	system("cls");
	system("COLOR c0");
	puts("");
	printf("\t ╔ ─  ─  ─  ╗\n");
	printf("\t   当前评价:  \n");
	printf("\t ╚ ━  ━  ━  ╝\n");

	printf("\t\t\t%s",recentStudent->comment);
	printf("\n");
}

//完成教师模块
void teacher() {
	system("title 进入教师端");
	system("cls");
	system("COLOR fc");
	printf("\t\t\t\t\t\t╭  ─  ─  ─  ╮\n");
	printf("\t\t\t\t\t\t   登录成功！  \n");
	printf("\t\t\t\t\t\t╰  ━  ━  ━  ╯\n");
	printf("\n\t\t*=*=*=*=*=*=         Hello！%7s老师----欢迎使用算数小天才系统       =*=*=*=*=*\n",teachers[tab].name);
	puts("");
	printf("\t\t************\t\t在这里，让我们一起见证孩子们的成长吧[]~(′▽`)~*\t\t**********\n");
	menuT();

}

//显示教师主菜单并接受用户输入进行相应操作
void menuT() {
	while(1) {
		system("COLOR fc");
		system("title 教师端主菜单");
		system("cls");


		printf("\n\n\t\t\t\t       ==========教师系统主界面==========\n\n");
		printf("\t\t\t\t\t   ┍──  ──  ──  ──  ──  ──┑\n\n");
		printf("\t\t\t\t\t   ┃\t --1-查看学生排名 ┃\n\n");
		printf("\t\t\t\t\t   \t --2-管理学生信息\n\n");
		printf("\t\t\t\t\t   ┃\t --3-修改密码	  ┃\n\n");
		printf("\t\t\t\t\t   \t --0-退出 \n\n");
		printf("\t\t\t\t\t   ┕──  ──  ──  ──  ──  ──┙\n\n");

		printf("\n\t\t★请您选择要使用的功能(*’U`*):");
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0);
		putch(choice+=48);
		choice-=48; //option1==0或option1==1
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

//进入管理学生信息界面，接受输入并进行相应操作
void menuT_manage() {
	system("title 教师端---学生管理页");
	system("COLOR b0");
	system("cls");
	int time = 0;

	while (1) {
		if (time == 0) {
			printf("\n\t\t\t\t  =*=*=*=*=*欢迎来到学生信息管理板块*=*=*=*=*=\n\n\n");
		} else {
			printf("\n\n\t\t\t\t\t    =*=*继续使用更多功能*=*\n\n");
		}

		printf("\t\t\t\t\t   ┍──  ──  ──  ──  ──  ──┑\n\n");
		printf("\t\t\t\t\t   ┃\t --1-添加学生     ┃\n\n");
		printf("\t\t\t\t\t   \t --2-移除学生\n\n");
		printf("\t\t\t\t\t   ┃\t --3-修改学生信息 ┃\n\n");
		printf("\t\t\t\t\t   \t --4-查看学生信息\n\n");
		printf("\t\t\t\t\t   ┃\t --0-返回主菜单	  ┃\n\n");
		printf("\t\t\t\t\t   ┕──  ──  ──  ──  ──  ──┙\n\n");

		printf("\n\t\t请您选择要使用的功能(*’U`*):");
		int choice;
		do {
			choice = getch();
			choice-=48;
		} while ( choice != 1 && choice != 2 &&choice!=3 && choice!=0 &&choice!=4);
		putch(choice+=48);
		choice-=48; //option1==0或option1==1
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

//退出教师系统
void outTeacher() {
	system("title 教师端系统出口");
	system("cls");
	system("COLOR 70");
	srand((unsigned) time(NULL));
	int sentOrder = 1 + rand() % 5;
	switch (sentOrder) {
		case 1:
			printf("\n\t\t\t\t随风潜入夜，润物细无声。\n\n");
			break;
		case 2:
			printf("\n\t\t\t\t三尺讲台，三寸舌，三寸笔，三千桃李。\n\n");
			break;
		case 3:
			printf("\n\t\t\t\t十年树木，十载风，十载雨，十万栋梁。\n\n");
			break;
		case 4:
			printf("\n\t\t\t\t善之本在教，教之本在师。\n\n");
			break;
		case 5:
			printf("\n\t\t\t\t四度春凤化绸缪，几番风雨洗鸿沟。\n\n");
			break;

	}
	printf("\n\n\t\t\t\t感谢您的使用，系统退出中...\n");
	saveTeacherFile();
	saveStudentFile();
	Sleep(2500);
	printf("\n\t\t\t\t退出成功！\n");
	exit(0);
}

//查看学生排名
void printNameAndId(double n) {
	system("title 查看学生小测排名");
	PSt pPosition=headStudent->next;
	while(pPosition!=NULL) {
		if(pPosition->testGrade==n) {
			printf("%s\t%s\t%.2f\t\t",pPosition->name,pPosition->id,pPosition->testGrade);
		}
		pPosition=pPosition->next;
	}
	printf("\n");

}


//查看学生信息（包括基本信息，历史成绩和评语）
void checkStudent() {
	system("title 教师端---信息查询页");
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool ifIdFound = true;
	int choice = 0;
	PSt pHead = headStudent;


	//第一步：判断班级内部是否存在学生
	if (!(pHead->next) ) {
		printf("\n\t您还没有添加任何学生无法进行查询!\n");
		printf("\t正在返回上一级菜单...");
		Sleep(2000);
		menuT_manage();
	} else {

		do {
			//第二步：获取用户输入的学生id，并判断该学生是否存在
			puts("");
			printf("\t请输入您想查看信息的学生id:");
			//gets(id);
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);
			if (!p) {
				fflush(stdin);
				ifIdFound = false;
				printf("\t提示：您想查找的学生不存在，请确认并重新输入\n");
			} else {
				ifIdFound = true;
				recentStudent = p;
				//第三步：打印已找到的学生的各项信息
				printf("\t已找到！该学生信息如下：\n");
				printf("\t----姓名：%s\n", p->name);
				printf("\t----学号：%s\n", p->id);
				printf("\t----小测记录：----\n");
				printf("\t===============================\n");
				for (int i = 0; i < p->testNum; i++)
					printf("\t第%d次小测成绩\t----\t%d\n", i + 1, p->grade[i]);

				printf("\t\t\t小测平均分数：%d\n", p->testGrade);
				printf("\t===============================\n");
				printf("\t----当前评语：%s\n", p->comment);
				printf("\n\n");
				bool returnThisPage = true;  //默认操作完成后再返回此页面
				do {
					ifIdFound = false;
					//查看完成后提示进行下续操作
					printf("\t---1-修改评语\n");
					printf("\t---2-继续查看\n");
					printf("\t---0-返回上一级菜单\n");
					printf("\n\t请选择：");

					do {
						choice = getch();
						choice-=48;
					} while (choice != 0 && choice != 1 && choice != 2);
					putch(choice+=48);
					choice-=48;
					puts("");//对输入做防错处理


					if (choice == 0)
						menuT_manage();
					else if (choice == 1) {
						evaluate();
						printf("\t修改成功！\n\n");
					} else if(choice == 2)
						returnThisPage=false;
				} while ( returnThisPage);

			}
		} while (!ifIdFound || choice == 2);


	}


}


//添加学生
void addStudent() {
	system("title 教师端---注册学生页");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	int choice = 0; //用于添加信息完成后的菜单选择
	do {

		//=======================================================================//第一步：新建学生信息
		printf("\n\t学生信息添加中...\n");
		PSt pNew = (PSt) malloc(sizeof(St));
		pNew->next = NULL;
		printf("\n\t请输入该学生的姓名：");
		scanf("%s", pNew->name);
		printf("\n\t请输入该学生的学号：");
		scanf("%s", pNew->id);
		PSt p = traverse(pNew->id,headStudent);
		//第二步：判断该id对应的学生是否已经存在于班级列表中
		if(p!=NULL) {
			printf("\n\t该学生已经存在于您的班级中...");
		} else {

			strcpy(pNew->comment, "老师暂时没有给你评价喔~");

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


			//char *initMisPath = "G://C//实训//";
			char *initMisPath = "F://University//大一下//小学期//Code//";  //用来更改文件存放路径
			sprintf(pNew->mistakeFileName, "%s%s小盆友的错题集.txt", initMisPath, pNew->name);
			pNew->mistakeNum = 0;
			pNew->gameLevel = 0;
			pNew->gameNum = 0;
			for(int i=0; i<20; i++)
				pNew->grade[i]=0;
			pNew->testGrade = 0;

			//第三步： 完成创建
			if(!pHead) {
				pHead = (PSt)malloc(sizeof(St));
				pHead->next = NULL;
			}
			PSt p = pHead;
			while (p->next)
				p = p->next;
			p->next = pNew;
			printf("\n\t该学生添加成功！\n");
			puts("");
			//=============================================================================//

		}
		//第四步：提示后续操作
		printf("\n\n\t--1-继续添加\n");
		printf("\t--0-返回到管理学生页\n");
		printf("\n\t请选择：");

		//////////////////////////////////对输入做防错处理
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


//删除学生
void deleteStudent() {
	system("title 移除学生界面");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool ifIdFound = true;  //假定能够找到对应学生
	int choice = 0; //用于移除学生后的菜单选择操作

	//第一步：判断班级内是否存在学生
	if (!pHead->next) {
		printf("\n\t您还没有添加任何学生无法进行!\n");
		printf("\n\t正在返回上一级菜单...");
		Sleep(2000);
		menuT_manage();
	} else {
		do {
			//第二步：提示输入要移除的学生
			printf("\n\n\t请输入您想要移除的学生id:");
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);

			//第三步：判断该生是否存在
			if (!p) {
				fflush(stdin);
				ifIdFound = false;
				printf("\n\t您想要移除的学生不存在于班级名单中，请确认并重新输入：");
			} else {
				//第四步：打印学生信息并确认是否删除
				ifIdFound = true;
				printf("\n\t已找到该学生：\n");
				printf("\t----姓名：%s\n", p->name);
				printf("\t----学号：%s\n", p->id);
				puts("");


				printf("\n\t您确定要移除该学生？\n");
				int ifConfirm = 0;
				printf("\t---1-确定\n");
				printf("\t---0-取消并返回上一级菜单\n");
				printf("\t-----选择：");

				//对输入做防错处理
				do {
					ifConfirm = getch();
					ifConfirm-=48;
				} while (ifConfirm != 0 && ifConfirm != 1);
				putch(ifConfirm+=48);
				ifConfirm-=48;
				puts("");

				if (ifConfirm == 0) {
					printf("\n\t正在返回...");
					Sleep(1600);
					menuT_manage();
				} else {
					//第五步：移除学生操作---删除节点
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
				//第六步：完成移除后提示下续操作
				printf("===============================\n");
				printf("\n\t移除成功，请选择：\n");
				puts("");

				printf("\n\t---1-继续移除\n");
				printf("\t---0-返回上一级菜单\n");
				printf("\t-----选择：");


				do {
					choice = getch();
					choice-=48;
				} while (choice != 0 && choice != 1);
				putch(choice+=48);
				choice-=48;
				puts("");//对输入做防错处理

				if (choice == 0) {
					printf("\n\t正在返回...");
					Sleep(1600);
					menuT_manage();
				}
				//第七步：若继续移除，需判断是否班级内部还有学生存在
				else {
					if(!pHead->next) {
						system("cls");
						printf("班级内已经没有学生啦！！！\n");
						printf("正在返回学生管理菜单...");
						Sleep(2000);

						menuT_manage();
					}
				}


			}

		} while (!ifIdFound || choice == 1);
	}


}

//修改学生信息
void modifyStudent() {
	system("title 教师端---学生信息修改页");
	PSt pHead = headStudent;
	system("cls");
	system("COLOR E0");
	char id[20] = "";
	bool idNotFoundError = false;
	int choice = 0;

	//第一步：判断班级内是否存在学生
	if (!pHead->next ) {
		printf("\n\t您还没有添加任何学生无法进行修改!\n");
		printf("\t正在返回上一级菜单...");
		Sleep(2000);
		menuT_manage();
	} else {
		do {

			//第二步：根据输入查找学生
			printf("\n\t请输入您想修改信息的学生id:");
			//gets(id);
			scanf("%s", id);
			puts("");
			PSt p = traverse(id, pHead);
			if (!p) {
				fflush(stdin);
				idNotFoundError = true;
				printf("\t您想查找的学生不存在，请确认!\n");
			} else {
				idNotFoundError = false;
				recentStudent = p;
				printf("\t已找到！该学生当前基本信息如下：\n");
				printf("\t----姓名：\t\t%s\n", p->name);
				printf("\t----学号：\t\t%s\n", p->id);
				printf("\t----小测平均分：\t\t%.2f\n", p->testGrade);
				printf("\t----当前评语：\t\t%s\n", p->comment);

				//第三步：请求用户需要修改的数据
				printf("\n\t===============================\n");
				printf("\t请选择你要修改的信息：\n");
				bool ifContinueFixing = true;  //用于判断是否还要信息,默认为“是”
				do {
					puts("");

					printf("\t---1-姓名\n");
					printf("\t---2-学号\n");
					printf("\t---3-评语\n");
					printf("\t---0-取消并返回上一级菜单\n");
					printf("\t选择：");

					do {
						choice = getch();
						choice-=48;
					} while (choice != 0 && choice != 1 && choice != 2 && choice != 3);
					putch(choice+=48);
					choice-=48;
					puts("");//对输入做防错处理

					//第四步：获取选择开始修改，单项修改完成后提示是否继续
					if (choice == 0)
						menuT_manage();
					else if (choice == 1) {
						puts("");
						char newName[20] = "";
						printf("\t请输入该学生修改后的姓名：");
						scanf("%s", newName);
						strcpy(p->name, newName);
						printf("\n\t姓名修改成功！\n");
						printf("\n\t请选择是否继续修改：\n");
					} else if (choice == 2) {
						puts("");
						char newId[20] = "";
						printf("\t请输入该学生修改后的学号：");
						bool idHasExisted = false;   //用于判断学号是否已经存在
						do {
							scanf("%s", newId);   //暂时未考虑id字符串含有非数字的情况
							puts("");
							PSt pCheck = traverse(newId, pHead);
							if (pCheck != NULL) {
								printf("\n\t该学号已经存在啦！\n");
								idHasExisted = true;
								printf("\t基本信息如下：\n");
								printf("\t----姓名：%s\n", pCheck->name);
								printf("\t----学号：%s\n", pCheck->id);
								printf("\n\t请重新输入吧：");
							} else
								idHasExisted = false;
						} while (idHasExisted);

						strcpy(p->id, newId);
						printf("\n\t学号修改成功！\n");
						printf("\n\t请选择是否继续修改：\n");
					} else if (choice == 3) {
						evaluate();
						printf("\n\t评语修改成功！\n");
						printf("\n\t请选择是否继续修改：\n");
					}
				} while (ifContinueFixing);

			}
		} while (idNotFoundError);

	}

}

//对学生进行评价
void evaluate() {
	char review[20];
	printf("\n\t请输入您对该学生的评语：");
	scanf("%s",review);
	strcpy(recentStudent->comment,review);

}

//从文件中读取数据并写入链表当中
void readStudentFile() {
	PSt pointer,q;//head指针为链表的头结点，是找到链表的唯一依据，如果head指针丢失，那么整个链表就找不到了;
	//p指针总是指向新申请的结点;q指针总是指向尾节点
	St temp;//定义结构体别名
	FILE *fp;
	pointer=(struct student *)malloc(sizeof(struct student ));  // p指向新开辟的节点内存
	headStudent = pointer;    //开辟头结点内存      头结点中没有学生成绩信息
	q = pointer;       //开辟尾节点内存   q指针总是指向尾节点
	q->next = NULL; // //标志链表的结束 尾节点的特点是next成员的值为NULL，它是最后一个节点，作为链表结束的标志，NULL是一个符号常量表示值为0的地址
//	fp=fopen("G://C//实训//a.txt","r");
	fp=fopen("F://University//大一下//小学期//Code//student.txt","r");



	if(fp ==NULL) {
		printf("cannot open the file");
	}


	while(fscanf(fp,"%s  %s %s  %lf  %d %lf %d %lf %d %lf %d %lf %d  %s %d %d  %d",
	             temp.name,temp.id,temp.pin,&temp.plusCorrect,&temp.plusNum,&temp.minusCorrect,&temp.minusNum,
	             &temp.multiplyCorrect,&temp.multiplyNum,&temp.divideCorrect,&temp.divideNum,&temp.testGrade,
	             &temp.testNum,temp.mistakeFileName,&temp.mistakeNum,&temp.gameLevel,&temp.gameNum)==17) { //从文件中读结构体块
		for(int i=0; i<20; i++) {
			fscanf(fp,"%d",&temp.grade[i]);
		}
		fscanf(fp,"%s",temp.comment);
		pointer=(struct student*)malloc(sizeof(struct student)); // p指向新开辟的节点内存
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


		q->next=pointer;  //把新节点挂到原尾节点之后
		q=q->next;  //q指针指向新的尾节点
	}
	q->next=NULL;//标志链表的结束
	fclose(fp);
}

void readTeacherFile() {
//	FILE *fp = fopen("G://C//实训//b.txt","r");
	FILE *fp = fopen("F://University//大一下//小学期//Code//teacher.txt","r");
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

void sortForArray(double a[],int n) {  //对a这个数组进行排序
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

int sumOfStu() {    //该函数实现了计算整个链表的学生总人数
	int sum=0;
	PSt pPosition=headStudent;
	while(pPosition!=NULL) {
		sum++;
		pPosition=pPosition->next;
	}
	return sum-1;
}

void rank() {//对学生分数进行排序的函数
	system("COLOR b0");
	system("cls");
	if(!headStudent->next) {
		printf("\n\n\t\t您还没有添加学生进入班级，无法查看排名-_^~\n");
		printf("\n\t\t正在返回主菜单...\n\n");
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


	printf("\n\t\t名次\t姓名\tID\t小测平均分数\n\n");
	int j=1;//代表名次
	for(int i=0; i<SumNumberForStu; i++) {
		printf("\t\t%d\t",j);
		printNameAndId(scores[i]);
		printf("\n");
		j++;
	}
	int choice;
	system("pause");


	system("cls");
	printf("正在返回主菜单，请稍后……\n");
	Sleep(1600);
	menuT();
}


void saveStudentFile() {
	FILE *fp;
//	fp=fopen("G://C//实训//a.txt","w");
	fp=fopen("F://University//大一下//小学期//Code//student.txt","w");

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
//	FILE *fp = fopen("G://C//实训//b.txt","w");
	FILE *fp = fopen("F://University//大一下//小学期//Code//teacher.txt","w");

	if(fp==NULL) {
		printf("cannot open this file");
	} else {
		for(int i=0; strcmp(teachers[i].name,"")!=0; i++)
			fprintf(fp,"%s %s %s\n",teachers[i].name,teachers[i].id,teachers[i].pin);
	}
	fclose(fp);
}


