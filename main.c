#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct LinkedStackNode 
{	
	elemtype data;
	struct LinkedStackNode * next;
} LinkedStackNode, * LinkedStack;                                  
  LinkedStack top;

//��ʼ��
LinkedStack Init_LinkedStack()                                       
{	
	LinkedStack top=(LinkedStackNode * )malloc (sizeof( LinkedStackNode));
	if(top!=NULL)//����ռ�ɹ�
	top->next=NULL;//����ջ��ָ��Ϊ��
	return top;
}

//��ջ��
int LinkedStack_Empty(LinkedStack top)                            
{	
	if(top->next==NULL)//���ջ��ָ���ֵ 
	{
		return 1;//ջSΪ�գ���������1
	}	
	else
	{
		return 0;
	}
}

//��ջ
int Push_LinkedStack(LinkedStack top,elemtype x)                     
	//��������Ԫ��xΪ�µ�ջ��Ԫ��
{	
	LinkedStackNode * node;
	node=(LinkedStackNode * )malloc(sizeof(LinkedStackNode));
	if(node==NULL)
	{
		return 0;//������ռ�ʧ��,����ʧ�ܣ���������0
	}
	else
	{
		node->data=x;//�����½���������
		node->next=top->next;//�����½���ָ���
		top->next=node;//����ͷ���ָ���ָ���µ�ջ��Ԫ��
		return 1;//����ɹ�����������1
	}
}

//��ջ��
int Length_LinkedStack(LinkedStack top)                                       
{
	int count = 0;
	while(top->next!=NULL) 
	{
		++count;
		top=top->next;
	}
	return count;
}

//��ջ
int Pop_LinkedStack(LinkedStack top, elemtype *x)                    
{	LinkedStackNode * node;
	if(top->next==NULL)
	{
		return 0;
	}
	else
	{
		node=top->next;//��ԭջ������Ԫ�ص���������node
		*x=node->data;//��ԭջ������Ԫ�ص����ݸ�ֵ��x
		top->next=node->next;//topָ����ջ�е���һ������Ԫ��
		free (node);//�ͷ�ԭջ������Ԫ����ռ�Ŀռ�
		return 1;
	}
}  

//ȡջ��Ԫ��
int GetTop_LinkedStack(LinkedStack top)                
{ 
	if(top->next)
      {
            return top->next->data;

      }
      return -1;
}

//������
void main()
{
	int i,t,x,a[20];
	LinkedStack top=Init_LinkedStack();//��ʼ��ջ
	x=LinkedStack_Empty(top);//��ջ�ս����ֵ��X
	if(x=0)
	{
		printf("ջΪ��\n");
	}

	printf("����������5����,��ʼ��ջ��\n");
	for(i=0;i<5;i++) 
	{
		scanf("%d",&a[i]);
		Push_LinkedStack(top,a[i]);
		x=GetTop_LinkedStack(top);
		if(x!=-1)
		{
			printf("��ǰջ��Ԫ��Ϊ%d\n",x);
		}
	}
	printf("��ջ����\n");
	printf("ջ��Ϊ%d\n",Length_LinkedStack(top));
	printf("��ʼ��ջ:\n");
	for (i=0;i<5;i++)
	{
		Pop_LinkedStack(top,&t);
        printf("%d",t);
	}
	printf("\n");
	printf("��ջ��ջ��Ϊ%d\n",Length_LinkedStack(top));
}

