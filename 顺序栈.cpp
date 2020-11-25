#include<stdio.h>
#include<malloc.h>
#include <iostream>
using namespace std;

typedef int SElemType;
typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define Error 0
#define True 1
#define False 0
#define OVERFLOW -1 

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize; 
}SqStack;

Status InitStack(SqStack &S){
	S.base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof (SElemType));
	if(!S.base){
		exit(OVERFLOW);
	}
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
} //��ʼ��ջ

Status DestoryStack(SqStack &S){
	
	free(S.base);
	S.base = NULL;
	S.top = NULL;
	S.stacksize=0;
	return OK; 
}

Status ClearStack(SqStack &S){
	if(S.base == S.top){
		return OK;
	}else{
		S.base = S.top;
		return OK;
	}
}

Status StackEmpty(SqStack &S){
	if(S.base == S.top){
		return True;
	}else{
		return False;
	}
}

int StackLength(SqStack S){
	S.top + 1;
	return OK;
}

Status GetTop(SqStack S,SElemType &e){
	if(S.top == S.base){
		return Error;
	}
	e = *(S.top - 1);
	return OK;
}

Status Push(SqStack &S, SElemType e){
	if(S.top - S.base >= S.stacksize){
		S.base = (SElemType * )realloc(S.base,(S.stacksize + STACKINCREMENT) * sizeof(SElemType));
	
	if(!S.base) exit(OVERFLOW);
	S.top = S.base +S.stacksize;
	S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
	if(S.top == S.base) return Error;
	e = *--S.top;
	return OK;
}

Status StackTraverse(SqStack *S,Status(*visit)(SElemType))
 {
     SElemType *b = S->base;//�˴�����ֱ����base��top�ƶ��������ܸı�ԭջ�Ľṹ
     SElemType *t = S->top;
   while(t > b)
     visit(*b++);
   printf("\n");
   return OK;
 }
 
Status visit(SElemType c)
 {
   printf("%d ",c);
   return OK;
 }

int main()
{
	SqStack S;
	int e;
	char choice;
	int n;
	while(1){
		printf("���������ѡ��:\n");
		scanf("%c", &choice);
		getchar();//ÿ����һ�����ݣ���Ҫȡ�߻س�������ֹswitch�������,getchar�����������ǣ���
 
		switch(choice) 
		{
		cout<<"1----��ʼ��(����)������˳��ջ"<<endl;
		cout<<"2----���˳��ջ"<<endl;
		cout<<"3----˳��ջ�����ݵ�Ԫ�ظ���"<<endl;
		cout<<"4----�ж�ջ�Ƿ�Ϊ�ղ�����ջ��Ԫ��"<<endl;
		cout<<"5----��˳��ջ��ջ��Ԫ��"<<endl;
		cout<<"6----�ж�ջ�Ƿ�Ϊ��"<<endl;
		cout<<"7----������Ԫ�أ���ֱ�Ӻ��"<<endl;
		cout<<"8----����˳��ջ"<<endl;
			case '1':
				InitStack(S);
				printf("��ջ�����ɹ�");
				printf("start to create stack,plz write the num which u want the length");
				scanf("%d", &n);
				getchar();//move huichefu
				for(int i = 0; i<n; i++)
				{
					scanf("%d", &e);
					getchar();
					Push(S,e);
				}
				cout<<"stack is "<<endl; 
				break;
			case '2':
				ClearStack(S);
				cout<<"stack is null"<<endl;
				break;
			case '3':
				cout<<"length is "<<endl;
				StackLength(S);
				break;
			case '4':
				cout<<"stack top is "<<endl;
				if(!GetTop(S,e))
				cout<<"stack is null"<<endl;
				else
				cout<<e<<endl;
			case '5':
				cout<<"write the 'e'"<<endl;
				scanf("%d", &e);
				getchar();
				Push(S,e);
				cout<<"elem was pushed in the stack"<<endl;
				cout<<"now the stack is"<<endl;

				break;
			case '6':
				if(!Pop(S,e))
				cout<<"stack is null"<<endl;
				else
				cout<<"stack pop"<<e<<endl;
				cout<<"now the stack is"<<endl;

				break;
			case '7':
				if(!StackEmpty(S))
				cout<<"stack is not null"<<endl;
				else
				cout<<"stack is null"<<endl;
				break;
			case '8':
				DestoryStack(S);
				cout<<"stack was destroied"<<endl;
				break;
			default:
				exit(0);
				break;
		}
		
	}
}






























































  
