#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student    //ѧ����Ϣ�ṹ��
{
	char id[15];        //ѧ�� 
	char name[20];      //���� 
	char sex[10];       //�Ա� 
	char date[20];      //�������� 
	char telephone[15]; //�绰 
	char major[25];     //רҵ 
	float score1;       //C���Գɼ� 
	float score2;       //�ߵ���ѧ�ɼ� 
	float score3;       //��ѧӢ��ɼ� 
	struct student *next;
};

struct student *create(struct student *head) //����ѧ����Ϣ
{
	int i,j,n; //nΪѧ������
	float score1,score2,score3;
	struct student *p,*pr;

	printf("��������Ҫ�����ѧ������:");
	scanf("%d",&n);
	printf("\n");

	pr=head=(struct student *)malloc(sizeof(struct student));
	for(j=0;j<n;j++)
	{
		p=(struct student *)malloc(sizeof(struct student));
		pr->next=p;
		p->next=NULL;
		for(i=0;i<36;i++) printf(" ");printf("[1] �������%dλѧ����ѧ��: ",j+1);
		scanf("%s",&p->id);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[2] �������%dλѧ��������: ",j+1);
		scanf("%s",&p->name);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[3] �������%dλѧ�����Ա�: ",j+1);
		scanf("%s",&p->sex);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[4] �������%dλѧ���ĳ�������: ",j+1);
		scanf("%s",&p->date);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[5] �������%dλѧ���ĵ绰: ",j+1);
		scanf("%s",&p->telephone);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[6] �������%dλѧ����רҵ: ",j+1);
		scanf("%s",&p->major);
		 
		do{
			for(i=0;i<36;i++) printf(" ");printf("[7] �������%dλѧ����C���Գɼ�: ",j+1);
			scanf("%f",&score1);
			if(score1>100 || score1<0) printf("��������! ����������\n");
		}while(score1>100 || score1<0);
		p->score1=score1;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[8] �������%dλѧ���ĸߵ���ѧ�ɼ�: ",j+1);
			scanf("%f",&score2);
			if(score2>100 || score2<0) printf("��������! ����������\n");
		}while(score2>100 || score2<0);
		p->score2=score2;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[9] �������%dλѧ���Ĵ�ѧӢ��ɼ�: ",j+1);
			scanf("%f",&score3);
			if(score3>100 || score3<0) printf("��������! ����������\n");
		}while(score3>100 || score3<0);
		p->score3=score3;

		printf("\n");
		pr=p;
	}
	p=p->next;
	free(p);
	for(i=0;i<36;i++) printf(" ");printf("�������!\n");
	
	return head;
}

void print(struct student *head)  //���ѧ����Ϣ 
{
	struct student *temp;
	temp=head;
	if(head==NULL)
	{
		printf("\nû��¼��ѧ����Ϣ!\n\n\n");
	}
	else
	{
	
		if(head!=NULL)
		{
			temp=temp->next;
			while(temp!=NULL)
			{

			//printf("ѧ��         ����    �Ա�  ��������   �绰         רҵ            C���Գɼ�   �ߵ���ѧ�ɼ�  ��ѧӢ��ɼ�\n");
			//printf("103902020001  ����    ��    2001.1.1   18888888888  �������ѧ�뼼��   100          100           100     \n");
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

void lookup_id(struct student *head)  //����ѧ����Ϣ (��ѧ�Ų���)
{
	int i;
	char num[15];
	struct student *p,*temp;
	for(i=0;i<36;i++) printf(" ");printf("[1]������Ҫ���ҵ�ѧ��ѧ��:");
	scanf("%s",num);
	if(head==NULL)
	{
		printf("\n");
		for(i=0;i<36;i++) printf(" ");printf("û��¼��ѧ����Ϣ(����Ϊ��)\n");
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
		//printf("���ҳɹ�!\n");
			printf("\nѧ��            ����    �Ա�  ��������  �绰         רҵ              C���Գɼ�   �ߵ���ѧ�ɼ�  ��ѧӢ��ɼ�\n");
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
			printf("\nû���ҵ�ѧ��Ϊ %s ��ѧ��!\n",num);
	}
}

void lookup_name(struct student *head)  //����ѧ����Ϣ (����������)
{
	int i;
	char name[15];
	struct student *p,*temp;
	for(i=0;i<36;i++) printf(" ");printf("[2]������Ҫ���ҵ�ѧ������:");
	scanf("%s",name);
	//char num[12];
	if(head==NULL)
	{
		printf("\n");
		for(i=0;i<36;i++) printf(" ");printf("û��¼��ѧ����Ϣ(����Ϊ��)\n");
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
		//printf("���ҳɹ�!\n");
			printf("\nѧ��         ����    �Ա�  ��������   �绰         רҵ            C���Գɼ�   �ߵ���ѧ�ɼ�  ��ѧӢ��ɼ�\n");
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
			printf("\nû���ҵ�����Ϊ %s ��ѧ��!\n",name);
	}
}
struct student *del(struct student *head,char num[]) //ɾ��ѧ����Ϣ 
{
	int i;
	struct student *pr,*p;
	if(head==NULL)
	{
		for(i=0;i<36;i++) printf(" ");
		printf("û��¼��ѧ����Ϣ!\n");
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
			printf("%s--- ��ѧ����Ϣ�ɹ�ɾ��!\n",num);
		}
		else 
		{
			for(i=0;i<36;i++) printf(" ");
			printf("û���ҵ�ѧ��Ϊ%s��ѧ��!\n",num);
		}	
	}
		return head;
}
struct student *insert(struct student *head )  //���ѧ����Ϣ 
{
	int i;
	struct student *p,*pr,*stud; 
	stud=(struct student *)malloc(sizeof(struct student)); 
	
		for(i=0;i<36;i++) printf(" ");printf("[1] ������ѧ����ѧ��: ");
		scanf("%s",&stud->id);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[2] ������ѧ��������: ");
		scanf("%s",&stud->name);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[3] ������ѧ�����Ա�: ");
		scanf("%s",&stud->sex);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[4] ������ѧ���ĳ�������: ");
		scanf("%s",&stud->date);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[5] ������ѧ���ĵ绰: ");
		scanf("%s",&stud->telephone);

		getchar();
		for(i=0;i<36;i++) printf(" ");printf("[6] ������ѧ����רҵ: ");
		scanf("%s",&stud->major);
				
		for(i=0;i<36;i++) printf(" ");printf("[7] ������ѧ����C���Գɼ�: ");
		scanf("%f",&stud->score1);

		for(i=0;i<36;i++) printf(" ");printf("[8] ������ѧ���ĸߵ���ѧ�ɼ�: ");
		scanf("%f",&stud->score2);

		for(i=0;i<36;i++) printf(" ");printf("[9] ������ѧ���Ĵ�ѧӢ��ɼ�: ");
		scanf("%f",&stud->score3);
		stud->next=NULL;
		
	
	if(head==NULL)
	{
		pr=head=(struct student *)malloc(sizeof(struct student));
		pr->next=stud; 
		for(i=0;i<36;i++) printf(" ");printf("��ӳɹ�!\n");
	}
	else
	{
		p=head;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=stud;
			
		for(i=0;i<36;i++) printf(" ");printf("��ӳɹ�!\n");
	}		
	return head;
}
struct student *modify(struct student *head,char num[]) //�޸�ѧ����Ϣ 
{
	int i;
	float score1,score2,score3;
	struct student *p;
	if(head==NULL)
	{
		for(i=0;i<36;i++) printf(" ");
		printf("û��¼��ѧ����Ϣ!\n");
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
			for(i=0;i<36;i++) printf(" ");printf("[1] ������ѧ����ѧ��: ");
			scanf("%s",&p->id);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[2] ������ѧ��������: ");
			scanf("%s",&p->name);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[3] ������ѧ�����Ա�: ");
			scanf("%s",&p->sex);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[4] ������ѧ���ĳ�������: ");
			scanf("%s",&p->date);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[5] ������ѧ���ĵ绰: ");
			scanf("%s",&p->telephone);

			getchar();
			for(i=0;i<36;i++) printf(" ");printf("[6] ������ѧ����רҵ: ");
			scanf("%s",&p->major);
			
		do{
			for(i=0;i<36;i++) printf(" ");printf("[7] �������%dλѧ����C���Գɼ�: ");
			scanf("%f",&score1);
			if(score1>100 || score1<0) printf("��������! ����������\n");
		}while(score1>100 || score1<0);
		p->score1=score1;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[8] �������%dλѧ���ĸߵ���ѧ�ɼ�: ");
			scanf("%f",&score2);
			if(score2>100 || score2<0) printf("��������! ����������\n");
		}while(score2>100 || score2<0);
		p->score2=score2;

		do{
			for(i=0;i<36;i++) printf(" ");printf("[9] �������%dλѧ���Ĵ�ѧӢ��ɼ�: ");
			scanf("%f",&score3);
			if(score3>100 || score3<0) printf("��������! ����������\n");
		}while(score3>100 || score3<0);
		p->score3=score3;
			
			for(i=0;i<36;i++) printf(" ");printf("�޸ĳɹ�!");
		}
		else
		{
			for(i=0;i<36;i++) printf(" ");
			printf("û���ҵ���ѧ��!");
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
		fprintf(fp,"û��¼��ѧ����Ϣ!\n\n\n");
	}
	else
	{
	fprintf(fp,"ѧ��                  ����    �Ա� ��������   �绰                 רҵ               C���Գɼ�   �ߵ���ѧ�ɼ�  ��ѧӢ��ɼ�\n");
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

void menu()  //���˵�
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("     ��ӭ����ѧ����Ϣ����ϵͳ!    \n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	for(i=0;i<36;i++) printf(" ");printf("|                               |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        1.����ѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        2.��ѯѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        3.�޸�ѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        4.���ѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        5.ɾ��ѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        6.��ʾ��ǰѧ����Ϣ     |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        7.����ѧ����Ϣ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|        8.�˳�ϵͳ             |\n");
	for(i=0;i<36;i++) printf(" ");printf("|_______________________________|\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("   �Ӽ����������������Ӧ����\n");
	printf("\n");
}

struct student *menu_1(struct student *head)   //�˵�1(����ѧ����Ϣ)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           ����ѧ����Ϣ\n");
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
void menu_2(struct student *head)  //�˵�2(��ѯѧ����Ϣ)
{
	int i,choose=0;
	char num[15];
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("          ��ѯѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	for(i=0;i<36;i++) printf(" ");printf("|                               |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          1.��ѧ�Ų�ѯ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          2.��������ѯ         |\n");
	for(i=0;i<36;i++) printf(" ");printf("|          3.�˳���ѯ           |\n");
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
					printf("            �˳���ѯ!");break;
				}
				default:{printf("�����������������!\n"); system("pause");break;} 
			}
			
	}
	
	printf("\n");
}
struct student * menu_3(struct student *head)  //�˵�3(�޸�ѧ����Ϣ)
{
	char num[15];
	int i; 
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           �޸�ѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("������Ҫ�޸ĵ�ѧ��ѧ��:");
	scanf("%s",num);
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("������޸�:\n");
	printf("\n\n");
	
	head=modify(head,num);
	printf("\n\n\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	return head;
}
struct student * menu_4(struct student *head)   //�˵�4(���ѧ����Ϣ)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           ���ѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	head=insert(head);
	
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	return head;
}
struct student * menu_5(struct student *head)   //�˵�5(ɾ��ѧ����Ϣ)
{
	int i;
	char num[15];
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("           ɾ��ѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("������Ҫɾ����ѧ��ѧ��:");
	scanf("%s",num);
	for(i=0;i<36;i++) printf(" ");printf("__________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("ɾ�����Ϊ:\n\n\n");
	
	head=del(head,num);
	printf("\n\n\n\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	return head;
}
void menu_6(struct student *head)  //�˵�6(��ʾ��ǰѧ����Ϣ)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("          ��ʾ��ǰѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("_________________________________________________________________________________________________________\n");
	printf("\n");
	
	printf("ѧ��            ����    �Ա�  ��������  �绰         רҵ              C���Գɼ�   �ߵ���ѧ�ɼ�  ��ѧӢ��ɼ�\n");
	print(head);
	
	for(i=0;i<36;i++) printf("_");printf("_________________________________");for(i=0;i<36;i++) printf("_");
	printf("\n");
}

void menu_7(struct student *head)     //�˵�7(����ѧ����Ϣ)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            ����ѧ����Ϣ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	save(head);
	for(i=0;i<36;i++) printf(" ");printf("            ����ɹ�!\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
}
void menu_8()     //�˵�8(�˳�)
{
	int i;
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            �˳�ϵͳ\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("**********************************\n");
	printf("                                       \n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
	for(i=0;i<36;i++) printf(" ");printf("            ллʹ��!\n");
	for(i=0;i<36;i++) printf(" ");printf("_________________________________\n");
	printf("\n");
}
int main()     //������
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
				default: {printf("�����������������!\n"); system("pause");system("cls");break;} 
			}
	}
	return 0;
}
