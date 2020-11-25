#include<stdio.h>
#include<malloc.h>
typedef int ElemType;
 
typedef struct //����˳��ջ
{ 
	ElemType data[100];
	int top;
}SqStack;
 
int main()
{ 
	void InitStack(SqStack *&s); //��ʼ��ջ
	void Push(SqStack *&s,int n,int r); //��ջ
	void Pop(SqStack *&s); //��ջ
	int n,r;
	SqStack *s;
	printf("������һ��10��������\n");
	scanf("%d",&n);
	printf("��������Ҫת���Ľ���\n");
	scanf("%d",&r);
	InitStack(s);
	if(n==0)
		printf("%d��%d����Ϊ0",n,r);
	else
	{
		Push(s,n,r);
		Pop(s);
	}
}
 
void InitStack(SqStack *&s) //��ʼ��ջ
{
	s=(SqStack *)malloc(sizeof(SqStack));
	s->top=-1;
}
 
void Push(SqStack *&s,int n,int r) //��ջ
{ 
	while(n)
	{
		s->top++;
		s->data[s->top]=n%r;
		n=n/r;
	}
}
 
void Pop(SqStack *&s) //��ջ
{ 
	ElemType e;
	printf("ת��������Ϊ��");
	while(s->top!=-1)
	{ 
		e=s->data[s->top];
		s->top--;
		if(e<10)
			printf("%d",e);
		else
			printf("%c",e+55);
	}
	printf("\n");
} 
