#include<stdlib.h>
#include<stdio.h>
#include<malloc.h>
#include<windows.h>
typedef struct stu
{
	int num;
	char name[20];
	float score;
	struct stu *pnext;
}ints;
ints *pHead=NULL;
int n=0;
int Repeat(ints *pnew)
{
	ints *phead=pHead;
	if (pHead==NULL)
		return 1;
	while(1)
	{
		if(phead->num==pnew->num)
		{
			printf("学号已存在,请检查后重新输入!\n");
			return 0;
		}
		if(phead->pnext!=NULL)
		{
			phead=phead->pnext;
		}
		else
			break;
	}
	return 1;
}
void create()
{
	ints *phead=NULL;
	ints *pnew=NULL;
	ints *ptail=NULL;
	ptail=phead;
	printf("请根据提示输入成员相关信息:\n");
	while(1)
	{
		pnew=(ints *)malloc(sizeof(ints));
		pnew->pnext=NULL;
		printf("请输入第%d位成员的学号：若输入完毕则输入0完成录入\n",n+1);
		scanf("%d",&pnew->num);
		if (pnew->num==0)
		{
			free(pnew);
			break;
		}
		if (Repeat(pnew)==0)
			continue;
		printf("请输入第%d位成员的姓名：\n",n+1);
		scanf("%s",pnew->name);
		printf("请输入第%d位成员的成绩：\n",n+1);
		scanf("%f",&pnew->score);
		if(phead==NULL)
		{
			phead=pnew;
			ptail=pnew;
		}
		else
		{
			ptail->pnext=pnew;
			ptail=pnew;
		}
		n+=1;
		pHead=phead;
	}
	printf("创建成功!\n");
}
void insert(ints *phead)
{
	int N;
	ints *pnew=(ints *)malloc(sizeof(ints));
	pnew->pnext=NULL;
	ints *ptemp=phead;
	ints *pold=NULL;
	while(1)
	{
		printf("请输入插入位置:(0->%d)\n",n);
		scanf("%d",&N);
		if(N<0||N>n)
		{
			printf("请输入有效数字!\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("请输入该成员的学号:\n");
		scanf("%d",&pnew->num);
		if(pnew->num==0)
			printf("学号不合法!请重新输入!\n");
		else if(Repeat(pnew)==0)
		{
			printf("*****\n");
			continue;
		}
		else
			break;
	}
	printf("请输入该成员的姓名：\n");
	scanf("%s",pnew->name);
	printf("请输入该成员的成绩：\n");
	scanf("%f",&pnew->score);
	for(int i=1;i<N;i++)
		ptemp=ptemp->pnext;
	pold=ptemp->pnext;
	if(N==0)
	{
		pnew->pnext=phead;
		pHead=pnew;
	}
	else if(N==n)
		ptemp->pnext=pnew;
	else if(N>0&&N<n)
	{
			pnew->pnext=pold;
			ptemp->pnext=pnew;
	}
	n+=1;
	printf("插入成功!\n");
}
void del(ints *head)
{
	int N;
	ints *pdd=head;
	ints *ptemp=head;
	while(1)
	{
		printf("请输入删除位置(1->%d)：\n",n);
		scanf("%d",&N);
		if(N<1||N>n)
		{
			printf("请输入有效数字");
			continue;
		}
		else
		   break;
	}
	for(int i=1;i<N-1;i++)
	  ptemp=ptemp->pnext;
	pdd=ptemp->pnext;
	if(N>1&&N<n)
	{
	  pdd=ptemp->pnext;
	  ptemp->pnext=pdd->pnext;
	  pdd->pnext=NULL;
	  free(pdd);
	}
	else if(N==n)
	   {
	   	ptemp->pnext=NULL;
	   	free(pdd);
	   }
	 else if(N==1)
	{
		pHead=ptemp->pnext;
		ptemp->pnext=NULL;
		free(ptemp);
	}
	n-=1;
	printf("删除成功!\n");
}
void Print(ints *ptemp)
{
	printf("当前所有成员信息如下:\n");
	printf("学号\t姓名\t成绩\t\n");
	while(ptemp->pnext!=NULL)
	{
		printf("%d\t%s\t%.2f\n",ptemp->num,ptemp->name,ptemp->score);
		ptemp=ptemp->pnext;
	}
	printf("%d\t%s\t%.2f\n",ptemp->num,ptemp->name,ptemp->score);
}
int Menu()
{
	int key1;
	printf("******欢迎来到链表学习********\n");
	printf("(1),创建初始链表\n");
	printf("(2),添加成员\n");
	printf("(3),删除成员\n");
	printf("(4),显示所有数据\n");
	printf("(0),退出\n");
	printf("当前有%d名成员\n",n);
	printf("******************************\n");
	while(1)
	{
		printf("请输入指令:\n");
		scanf("%d",&key1);
		if (key1 > 1 && key1 < 5 && n==0)
			printf("还没有成员,请先创建初始链表!\n");
		else
			break;
	}
	switch(key1)
	{
		case 0 :
		{
			printf("********欢迎下次使用**********\n");
			return 0;
			break;
		}
		case 1 :
		{
			create();
			system("pause");
			return 7;
			break;
		}
		case 2 :
		{
			insert(pHead);
			system("pause");
			return 2;
			break;
		}
		case 3 :
		{
			del(pHead);
			system("pause");
			return 3;
			break;
		}
		case 4 :
		{
			Print(pHead);
			system("pause");
			return 4;
			break;
		}
		default :
		{
			printf("输入错误");
			Sleep(1800);
			return 5;
			break;
		}
	}
}
int main()
{
	int key2=1;
	while(key2!=0)
	{
		system("CLS");
		key2=Menu();
	}
	free(pHead);
	return 0;
}
