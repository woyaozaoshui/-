#include <iostream>
#include <stdlib.h>
using namespace std;
#define ERROR 0  
#define OK 1
#define INIT_SIZE 100
typedef int ElemType;
typedef int Status;
typedef struct queue
{
	ElemType *base;//�����׵�ַ
	int front,rear;//һ��ͷ�±꣬һ��β�±�
}Queue;


Status InitQueue(Queue &Q)
{
	Q.base = (ElemType *)malloc(INIT_SIZE*sizeof(ElemType));
	if (!Q.base)
	{
		cout<<"�ڴ����ʧ��"<<endl;
		return ERROR;
	}
	Q.rear = 0;
	Q.front = 0;
	return OK;
}
 
Status IsEmpty(Queue &Q)
{
	if (Q.front == Q.rear)
	{
		cout<<"�ö���Ϊ��"<<endl;
		return OK;
	}
	cout<<"�ö��в�Ϊ��"<<endl;
	return 0;
}
 
Status IsFull(Queue &Q)
{
	if ((Q.rear+1)%INIT_SIZE==Q.front)//�˴��ж϶����Ƿ���������isfull�����ж�
	{
		cout<<"�ö�������"<<endl;
		return OK;
	}
	cout<<"�ö���δ��"<<endl;
	return 0;
}
 
Status EnQueue(Queue &Q,ElemType value)
{
	if ((Q.rear+1)%INIT_SIZE == Q.front)
	{
		cout<<"�ö��������������ٽ�������"<<endl;
		return ERROR;
	}
	Q.base[Q.rear] = value;
	cout<<Q.base[Q.front]<<endl;
	Q.rear = (Q.rear+1)%INIT_SIZE;
	return OK;
}
 
Status DeQueue(Queue &Q,ElemType &data)
{
	if (Q.front == Q.rear)
	{
		cout<<"�ö���Ϊ�գ�"<<endl;
		return ERROR;
	}
	data = Q.base[Q.front];
	cout<<"���ӵ�ֵΪ��"<<data<<endl;
	Q.front = (Q.front+1)%INIT_SIZE;
	return OK;
}
 
Status GetHead(Queue &Q,ElemType &head)
{
	if (Q.front == Q.rear)
	{
		cout<<"����Ϊ��"<<endl;
		return ERROR;
	}
	head = Q.base[Q.front];
	return OK;
}

int main()
{
	int choice;
	ElemType value;
	ElemType head,data;
	Queue Q;
	Q.base = NULL;
	while (1)
	{
		cout<<"˳��ѭ�����еĻ�������"<<endl;		
		cout<<"1.��ʼ������"<<endl;
		cout<<"2.�ж϶����Ƿ�Ϊ��"<<endl;
		cout<<"3.�ж϶����Ƿ���"<<endl;
		cout<<"4.Ԫ�����"<<endl;
		cout<<"5.Ԫ�س���"<<endl;
		cout<<"6.��ȡͷ��ֵ"<<endl;
		cout<<"0.�˳�����"<<endl;
		cout<<"�������ѡ��"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			if (InitQueue(Q))
			{
				cout<<"��ʼ���ɹ�"<<endl;
			}
			break;
		case 2:
			IsEmpty(Q);
			break;
		case 3:
			IsFull(Q);
			break;
		case 4:
			cout<<"	������Ҫ��ӵ�ֵ:"<<endl;
			cin>>value;
			EnQueue(Q,value);
			break;
		case 5:
			cout<<"	����ִ�С���������"<<endl;
			DeQueue(Q,data);
			break;
		case 6:
			GetHead(Q,head);
			cout<<"ͷ��ֵΪ"<<head<<endl;
			break;
		case 0:
			exit(0);
		default:
			exit(0);
		}
	}
	system("pause");
}
