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
			printf("ѧ���Ѵ���,�������������!\n");
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
	printf("�������ʾ�����Ա�����Ϣ:\n");
	while(1)
	{
		pnew=(ints *)malloc(sizeof(ints));
		pnew->pnext=NULL;
		printf("�������%dλ��Ա��ѧ�ţ����������������0���¼��\n",n+1);
		scanf("%d",&pnew->num);
		if (pnew->num==0)
		{
			free(pnew);
			break;
		}
		if (Repeat(pnew)==0)
			continue;
		printf("�������%dλ��Ա��������\n",n+1);
		scanf("%s",pnew->name);
		printf("�������%dλ��Ա�ĳɼ���\n",n+1);
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
	printf("�����ɹ�!\n");
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
		printf("���������λ��:(0->%d)\n",n);
		scanf("%d",&N);
		if(N<0||N>n)
		{
			printf("��������Ч����!\n");
			continue;
		}
		else
			break;
	}
	while(1)
	{
		printf("������ó�Ա��ѧ��:\n");
		scanf("%d",&pnew->num);
		if(pnew->num==0)
			printf("ѧ�Ų��Ϸ�!����������!\n");
		else if(Repeat(pnew)==0)
		{
			printf("*****\n");
			continue;
		}
		else
			break;
	}
	printf("������ó�Ա��������\n");
	scanf("%s",pnew->name);
	printf("������ó�Ա�ĳɼ���\n");
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
	printf("����ɹ�!\n");
}
void del(ints *head)
{
	int N;
	ints *pdd=head;
	ints *ptemp=head;
	while(1)
	{
		printf("������ɾ��λ��(1->%d)��\n",n);
		scanf("%d",&N);
		if(N<1||N>n)
		{
			printf("��������Ч����");
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
	printf("ɾ���ɹ�!\n");
}
void Print(ints *ptemp)
{
	printf("��ǰ���г�Ա��Ϣ����:\n");
	printf("ѧ��\t����\t�ɼ�\t\n");
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
	printf("******��ӭ��������ѧϰ********\n");
	printf("(1),������ʼ����\n");
	printf("(2),��ӳ�Ա\n");
	printf("(3),ɾ����Ա\n");
	printf("(4),��ʾ��������\n");
	printf("(0),�˳�\n");
	printf("��ǰ��%d����Ա\n",n);
	printf("******************************\n");
	while(1)
	{
		printf("������ָ��:\n");
		scanf("%d",&key1);
		if (key1 > 1 && key1 < 5 && n==0)
			printf("��û�г�Ա,���ȴ�����ʼ����!\n");
		else
			break;
	}
	switch(key1)
	{
		case 0 :
		{
			printf("********��ӭ�´�ʹ��**********\n");
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
			printf("�������");
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
