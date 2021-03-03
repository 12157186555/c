#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student    //学生信息结构体
{
	char id[15];        //学号 
	char name[20];      //姓名 
	char sex[10];       //性别 
	char date[20];      //出生日期 
	char telephone[15]; //电话 
	char major[25];     //专业 
	float score1;       //C语言成绩 
	float score2;       //高等数学成绩 
	float score3;       //大学英语成绩 
	struct student *next;
};

struct student *create(struct student *head) //输入学生信息
{
	int i,j,n; //n为学生个数
	float score1,score2,score3;
	struct student *p,*pr;

	printf("请输入你要输入的学生个数:");
	scanf("%d",&n);
	printf("\n");

	pr=head=(struct student *)malloc(sizeof(struct student));
	for(j=0;j<n;j++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		pr->next=p;
		p->next=NULL;
		for(i=0;i<36;i++) printf(" ");printf("[1] 请输入第%d位学生的学号: ",j+1);
		scanf("%s",&p->id);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[2] 请输入第%d位学生的姓名: ",j+1);
		scanf("%s",&p->name);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[3] 请输入第%d位学生的性别: ",j+1);
		scanf("%s",&p->sex);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[4] 请输入第%d位学生的出生日期: ",j+1);
		scanf("%s",&p->date);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[5] 请输入第%d位学生的电话: ",j+1);
		scanf("%s",&p->telephone);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[6] 请输入第%d位学生的专业: ",j+1);
		scanf("%s",&p->major);
		 
		do{
			for(i=0;i<36;i++) printf(" ");printf("[7] 请输入第%d位学生的C语言成绩: ",j+1);
			scanf("%f",&score1);
			if(score1>100 || score1<0) printf("输入有误! 请重新输入\n");
		}while(score1>100 || score1<0);
		p->score1=score1;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[8] 请输入第%d位学生的高等数学成绩: ",j+1);
			scanf("%f",&score2);
			if(score2>100 || score2<0) printf("输入有误! 请重新输入\n");
		}while(score2>100 || score2<0);
		p->score2=score2;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[9] 请输入第%d位学生的大学英语成绩: ",j+1);
			scanf("%f",&score3);
			if(score3>100 || score3<0) printf("输入有误! 请重新输入\n");
		}while(score3>100 || score3<0);
		p->score3=score3;

		printf("\n");
		pr=p;
	}
	p=p->next;
	free(p);
	for(i=0;i<36;i++) printf(" ");printf("输入完成!\n");
	
	return head;
}

void print(struct student *head)  //输出学生信息 
{
	struct student *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\n没有录入学生信息!\n\n\n");
	}
	else
	{
	
		if(head!=NULL)
		{
			temp=temp->next;
			while(temp!=NULL)
			{

			//printf("学号         姓名    性别  出生年月   电话         专业            C语言成绩   高等数学成绩  大学英语成绩\n");
			//printf("103902020001  张三    男    2001.1.1   18888888888  计算机科学与技术   100          100           100     \n");
			printf("%-16s",temp->id);
			printf("%-8s",temp->name);
			printf("%-6s",temp->sex);
			printf("%-10s",temp->date);
			printf("%-13s",temp->telephone);
			printf("%-18s",temp->major);
			printf("%-12.1f",temp->score1);
			printf("%-14.1f",temp->score2);
			printf("%-16.1f\n",temp->score3);
			printf("\n");
			temp=temp->next;
			}
		}		
	}
	
}

void lookup_id(struct student *head)  //查找学生信息 (按学号查找)
{
	int i;
	char num[15];
	struct student *p,*temp;
	for(i=0;i<36;i++) printf(" ");printf("[1]请输入要查找的学生学号:");
	scanf("%s",num);
	if(head==NULL)
	{
		printf("\n");
		for(i=0;i<36;i++) printf(" ");printf("没有录入学生信息(链表为空)\n");
	}
	else 
	{
		p=head;
		while(strcmp(num,p->id)!=0 && p->next!=NULL)
		{
			p=p->next;
		}
		if(strcmp(num,p->id)==0)
		{
			temp=p;
		//printf("查找成功!\n");
			printf("\n学号            姓名    性别  出生年月  电话         专业              C语言成绩   高等数学成绩  大学英语成绩\n");
			printf("%-16s",temp->id);
			printf("%-8s",temp->name);
			printf("%-6s",temp->sex);
			printf("%-10s",temp->date);
			printf("%-13s",temp->telephone);
			printf("%-18s",temp->major);
			printf("%-12.1f",temp->score1);
			printf("%-14.1f",temp->score2);
			printf("%-16.1f\n",temp->score3);
			printf("\n");
		}
		else
			printf("\n没有找到学号为 %s 的学生!\n",num);
	}
}

void lookup_name(struct student *head)  //查找学生信息 (按姓名查找)
{
	int i;
	char name[15];
	struct student *p,*temp;
	for(i=0;i<36;i++) printf(" ");printf("[2]请输入要查找的学生姓名:");
	scanf("%s",name);
	//char num[12];
	if(head==NULL)
	{
		printf("\n");
		for(i=0;i<36;i++) printf(" ");printf("没有录入学生信息(链表为空)\n");
	}
	else 
	{
		p=head;
		while(strcmp(name,p->name)!=0 && p->next!=NULL)
		{
			p=p->next;
		}
		if(strcmp(name,p->name)==0)
		{
			temp=p;
		//printf("查找成功!\n");
			printf("\n学号         姓名    性别  出生年月   电话         专业            C语言成绩   高等数学成绩  大学英语成绩\n");
			printf("%-16s",temp->id);
			printf("%-8s",temp->name);
			printf("%-6s",temp->sex);
			printf("%-10s",temp->date);
			printf("%-13s",temp->telephone);
			printf("%-18s",temp->major);
			printf("%-12.1f",temp->score1);
			printf("%-14.1f",temp->score2);
			printf("%-16.1f\n",temp->score3);
			printf("\n");
		}
		else
			printf("\n没有找到姓名为 %s 的学生!\n",name);
	}
}
struct student *del(struct student *head,char num[]) //删除学生信息 
{
	int i;
	struct student *pr,*p;
	if(head==NULL)
	{
		for(i=0;i<36;i++) printf(" ");
		printf("没有录入学生信息!\n");
	}	
	else 
	
	{
		p=head;
		while(strcmp(num,p->id)!=0 && p->next!=NULL)
		{
			pr=p;
			p=p->next;
		}
		if(strcmp(num,p->id)==0)
		{
			if(p==head) head=p->next;
			else pr->next=p->next;
			free(p);
			for(i=0;i<36;i++) printf(" ");
			printf("%s--- 该学生信息成功删除!\n",num);
		}
		else 
		{
			for(i=0;i<36;i++) printf(" ");
			printf("没有找到学号为%s的学生!\n",num);
		}	
	}
		return head;
}
struct student *insert(struct student *head )  //添加学生信息 
{
	int i;
	struct student *p,*pr,*stud; 
	stud=(struct student *)malloc(sizeof(struct student)); 
	
		for(i=0;i<36;i++) printf(" ");printf("[1] 请输入学生的学号: ");
		scanf("%s",&stud->id);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[2] 请输入学生的姓名: ");
		scanf("%s",&stud->name);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[3] 请输入学生的性别: ");
		scanf("%s",&stud->sex);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[4] 请输入学生的出生日期: ");
		scanf("%s",&stud->date);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[5] 请输入学生的电话: ");
		scanf("%s",&stud->telephone);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[6] 请输入学生的专业: ");
		scanf("%s",&stud->major);
				
		for(i=0;i<36;i++) printf(" ");printf("[7] 请输入学生的C语言成绩: ");
		scanf("%f",&stud->score1);

		for(i=0;i<36;i++) printf(" ");printf("[8] 请输入学生的高等数学成绩: ");
		scanf("%f",&stud->score2);

		for(i=0;i<36;i++) printf(" ");printf("[9] 请输入学生的大学英语成绩: ");
		scanf("%f",&stud->score3);
		stud->next=NULL;
		
	
	if(head==NULL)
	{
		pr=head=(struct student *)malloc(sizeof(struct student));
		pr->next=stud; 
		for(i=0;i<36;i++) printf(" ");printf("添加成功!\n");
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=stud;
			
		for(i=0;i<36;i++) printf(" ");printf("添加成功!\n");
	}		
	return head;
}
struct student *modify(struct student *head,char num[]) //修改学生信息 
{
	int i;
	float score1,score2,score3;
	struct student *p;
	if(head==NULL)
	{
		for(i=0;i<36;i++) printf(" ");
		printf("没有录入学生信息!\n");
	}	
	else 
	{
		p=head;
		while(strcmp(num,p->id)!=0 && p->next!=NULL)
		{
			p=p->next;
		}
		if(strcmp(num,p->id)==0)
		{
			for(i=0;i<36;i++) printf(" ");printf("[1] 请输入学生的学号: ");
			scanf("%s",&p->id);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[2] 请输入学生的姓名: ");
			scanf("%s",&p->name);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[3] 请输入学生的性别: ");
			scanf("%s",&p->sex);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[4] 请输入学生的出生日期: ");
			scanf("%s",&p->date);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[5] 请输入学生的电话: ");
			scanf("%s",&p->telephone);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[6] 请输入学生的专业: ");
			scanf("%s",&p->major);
			
		do{
			for(i=0;i<36;i++) printf(" ");printf("[7] 请输入第%d位学生的C语言成绩: ");
			scanf("%f",&score1);
			if(score1>100 || score1<0) printf("输入有误! 请重新输入\n");
		}while(score1>100 || score1<0);
		p->score1=score1;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[8] 请输入第%d位学生的高等数学成绩: ");
			scanf("%f",&score2);
			if(score2>100 || score2<0) printf("输入有误! 请重新输入\n");
		}while(score2>100 || score2<0);
		p->score2=score2;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[9] 请输入第%d位学生的大学英语成绩: ");
			scanf("%f",&score3);
			if(score3>100 || score3<0) printf("输入有误! 请重新输入\n");
		}while(score3>100 || score3<0);
		p->score3=score3;
			
			for(i=0;i<36;i++) printf(" ");printf("修改成功!");
		}
		else
		{
			for(i=0;i<36;i++) printf(" ");
			printf("没有找到该学生!");
		}	
	}
	return head;
}
void save(struct student *head)
{
	FILE *fp;
	struct student *temp;
	temp=head;
	if((fp=fopen("student.txt","w"))==NULL)
	{
		printf("cannot open file\n");
		exit(0);
	}
	if(head==NULL)
	{
		fprintf(fp,"没有录入学生信息!\n\n\n");
	}
	else
	{
	fprintf(fp,"学号                  姓名    性别 出生年月   电话                 专业               C语言成绩   高等数学成绩  大学英语成绩\n");
		if(head!=NULL)
		{
			temp=temp->next;
			while(temp!=NULL)
			{
			fprintf(fp,"%-16s",temp->id);
			fprintf(fp,"%-8s",temp->name);
			fprintf(fp,"%-6s",temp->sex);
			fprintf(fp,"%-10s",temp->date);
			fprintf(fp,"%-13s",temp->telephone);
			fprintf(fp,"%-18s",temp->major);
			fprintf(fp,"%-12.1f",temp->score1);
			fprintf(fp,"%-14.1f",temp->score2);
			fprintf(fp,"%-16.1f\n",temp->score3);
			fprintf(fp,"\n");
			temp=temp->next;
			}
		}		
	}
	fclose(fp);
}

void menu()  //主菜单
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("     欢迎来到学生信息管理系统!    \n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	for(i=0;i<36;i++) printf(" ");printf("|                               |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        1.输入学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        2.查询学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        3.修改学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        4.添加学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        5.删除学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        6.显示当前学生信息     |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        7.保存学生信息         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        8.退出系统             |\n");
	for(i=0;i<36;i++) printf(" ");printf("|_______________________________|\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("   从键盘输入数字完成相应功能\n");
	printf("\n");
}

struct student *menu_1(struct student *head)   //菜单1(输入学生信息)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           输入学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");

	head=create(head);
	
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	
	return head;
}
void menu_2(struct student *head)  //菜单2(查询学生信息)
{
	int i,choose=0;
	char num[15];
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("          查询学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	for(i=0;i<36;i++) printf(" ");printf("|                               |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          1.按学号查询         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          2.按姓名查询         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          3.退出查询           |\n");
	for(i=0;i<36;i++) printf(" ");printf("|_______________________________|\n");
	
	while(choose!=3)
	{
		scanf("%d",&choose);
		getchar();
			switch(choose)
			{
				case 1:
				{
					lookup_id(head);
					printf("\n\n\n");
					for(i=0;i<36;i++) printf("_");printf("_________________________________");for(i=0;i<36;i++) printf("_");
					printf("\n");
					system("pause");break;
				}
				case 2:
				{
					lookup_name(head);
					printf("\n\n\n");
					for(i=0;i<36;i++) printf("_");printf("_________________________________");for(i=0;i<36;i++) printf("_");
					printf("\n");
					system("pause");break;
				}
				case 3:
				{
					for(i=0;i<36;i++) printf(" ");
					printf("            退出查询!");break;
				}
				default:{printf("输入错误，请重新输入!\n"); system("pause");break;} 
			}
			
	}
	
	printf("\n");
}
struct student * menu_3(struct student *head)  //菜单3(修改学生信息)
{
	char num[15];
	int i; 
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           修改学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("请输入要修改的学生学号:");
	scanf("%s",num);
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("请进行修改:\n");
	printf("\n\n");
	
	head=modify(head,num);
	printf("\n\n\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	return head;
}
struct student * menu_4(struct student *head)   //菜单4(添加学生信息)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           添加学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	head=insert(head);
	
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	return head;
}
struct student * menu_5(struct student *head)   //菜单5(删除学生信息)
{
	int i;
	char num[15];
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           删除学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("请输入要删除的学生学号:");
	scanf("%s",num);
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("删除结果为:\n\n\n");
	
	head=del(head,num);
	printf("\n\n\n\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	return head;
}
void menu_6(struct student *head)  //菜单6(显示当前学生信息)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("          显示当前学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("_________________________________________________________________________________________________________\n");
	printf("\n");
	
	printf("学号            姓名    性别  出生年月  电话         专业              C语言成绩   高等数学成绩  大学英语成绩\n");
	print(head);
	
	for(i=0;i<36;i++) printf("_");printf("_________________________________");for(i=0;i<36;i++) printf("_");
	printf("\n");
}

void menu_7(struct student *head)     //菜单7(保存学生信息)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            保存学生信息\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	save(head);
	for(i=0;i<36;i++) printf(" ");printf("            保存成功!\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
}
void menu_8()     //菜单8(退出)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            退出系统\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            谢谢使用!\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
}
int main()     //主函数
{
	struct student *head=NULL;
	int choose=0;
	while(choose!=8)
	{
		menu();
		scanf("%d",&choose);
		getchar();
			switch(choose)
			{
				case 1: {system("cls");head=menu_1(head);system("pause");system("cls");break;}
				case 2: {system("cls");menu_2(head);system("pause");system("cls");break;}
				case 3: {system("cls");head=menu_3(head);system("pause");system("cls");break;}
				case 4: {system("cls");head=menu_4(head);system("pause");system("cls");break;}
				case 5: {system("cls");head=menu_5(head);system("pause");system("cls");break;}
				case 6: {system("cls");menu_6(head);system("pause");system("cls");break;}
				case 7: {system("cls");menu_7(head);system("pause");system("cls");break;}
				case 8: {system("cls");menu_8();system("pause");system("cls");break;}
				default: {printf("输入错误，请重新输入!\n"); system("pause");system("cls");break;} 
			}
	}
	return 0;
}
