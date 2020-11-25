#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10 //ÿ������ջ��Ԫ
using namespace std;

typedef int ElemType;
typedef int Status;

int success = 0;

 typedef struct{
 	ElemType *base;
 	ElemType *top;
 	int stacksize;
 }SqStack;
 
 Status InitStack(SqStack &S){
 	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
 	S.top=S.base;
 	S.stacksize=STACK_INIT_SIZE;
 	success=1;
 	return OK;
 } 
 
 Status DestroyStack(SqStack &S){
 	S.top=NULL;
 	S.stacksize = 0;
 	free(S.base);
 	success=0;
 	return OK;
 }
 
 Status ClearStack(SqStack &S){
 	S.top=S.base;
 	return OK;
 }
 
 Status IfEmpty(SqStack S){
 	if(S.top==S.base)
 	{
 		return TRUE; 
	 }	 else	 {
	 	return FALSE;
	 }
 }
 
 Status StackLength(SqStack S){
 		if(S.top==S.base)
 		{return FALSE;
		 } else	 {
	 	return (S.top-S.base);
		 }
 }
 
 Status GetTop(SqStack &S,ElemType &e)
 {
 	if(S.top==S.base)
 	{
 		return ERROR;
	 }	 else	 {
	 	e=*(S.top-1);
	 	return OK;
	 }
 }
 
 Status Push(SqStack &S,ElemType &k)
 {
 	if (S.top - S.base >= STACK_INIT_SIZE)
    {
        S.base = (ElemType *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(ElemType));
        if (!S.base)
        {
            return false;
        }
        S.top = S.base + STACK_INIT_SIZE;//ջ�׵�ַ���ܸı䣬���¶�λջ��Ԫ��
        S.stacksize = S.stacksize + STACKINCREMENT;
    }
    *S.top = k;
    S.top++;
    return OK;
 }
 
 Status Pop(SqStack &S, ElemType &l)
{
    if (S.top == S.base)
        return ERROR;
    else  {
        S.top--;
        l = *S.top;//��Ԫ�ز�û����ɾ��
        return l;
    }
}

Status coutStack(SqStack S)
{
    if (S.top == S.base)
       return ERROR;
       
    ElemType *p;
    p = S.top;
    while (p > S.base)
    {
        p--;
        cout<<*p<<endl;
    }
    return OK;
}

Status cinStack(SqStack &S,int &num)
{
	S.base=(ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
 	S.top=S.base;
 	S.stacksize=STACK_INIT_SIZE;
 	success=1;
	while(S.top-S.base<num)
	{
		cin>>*S.top;
		S.top++;
	}
}

int main()
{
	while(1){

	cout<<"1.��ʼ��Ϊ��ջ"<<endl; 
	cout<<"2.����ջ"<<endl;
	cout<<"3.�ÿ�ջ"<<endl;
	cout<<"4.�ж�ջ�Ƿ�Ϊ��"<<endl;
	cout<<"5.����ջ����"<<endl;
	cout<<"6.��ջ��Ԫ��"<<endl;
	cout<<"7.��ջ������Ԫ��"<<endl;
	cout<<"8.ɾ��ջ��Ԫ�أ���������ֵ"<<endl;
	cout<<"9.���ջ��Ԫ��"<<endl;
	cout<<"10.����ջ������ջԪ��"<<endl;
	cout<<"11.�˳�"<<endl; 
	cout<<"**********************************"<<endl; 
	SqStack begin;
	int choose=0;
	cout<<"��ѡ��"<<endl;
	cin>>choose;
	switch(choose)
	{
		case 1:
			{
				InitStack(begin);
				cout<<"��ʼ���ɹ�"<<endl;
				break;
			}
		case 2:
			{
				if(success==1)
				{
					DestroyStack(begin);
					cout<<"���ٳɹ�"<<endl;
				}else{
					cout<<"��δ��ʼ��"<<endl;
				}
			break;
			}
		case 3:
			{
				if(success==1)
				{
					ClearStack(begin);
					cout<<"�ÿճɹ�"<<endl;
				}else{
					cout<<"��δ��ʼ��"<<endl;
				}
			break;
			}
		case 4:
			{
				if(success==1)
				{
					int status;
					status=IfEmpty(begin);
					if(status==0)
					{
						cout<<"��Ϊ��"<<endl;
					}else{
						cout<<"Ϊ��"<<endl;
					}
				}else{
					cout<<"��δ��ʼ��"<<endl;
				}
			break;
			}
		case 5:
			{
					if(success==1)
			{
				int status1=StackLength(begin);
				cout<<"ջ�ĳ���Ϊ:"<<status1<<endl;
			}else{
				cout<<"��δ��ʼ��"<<endl;
			}
			break;
			}
		
		
		case 6:
			if(success==1)
			{
				int e,status2;
				status2=GetTop(begin,e);
				if(status2==0)
				{
					cout<<"��ջ"<<endl;
				}else{
					cout<<"ջ��Ԫ��:"<<e<<endl;
				}
			}else{
				cout<<"��δ��ʼ��"<<endl;
			}
			break;
		case 7:
			if(success==1)
			{
				int k;
				cout<<"������Ҫ�����Ԫ��"<<endl;
				cin>>k;
				Push(begin,k);
				cout<<"����ɹ�"<<endl;
			}else{
				cout<<"��δ��ʼ��"<<endl;
			}
			break;
		case 8:
			{
			if(success==1)
			{
				int l,status3;
				status3=Pop(begin,l);
				if(status3==0)
				{
					cout<<"��ջ"<<endl;
				}else{
					cout<<"ɾ���ɹ���ɾ��ֵΪ��"<<l<<endl;
				}
			}else{
				cout<<"��δ��ʼ��"<<endl;
			}
			break;
			}
		case 9:
			{
				if(success==1)
				{
					int status4 = coutStack(begin);
					if(status4==0)
					{
						cout<<"��ջ"<<endl;
					}else{
						cout<<"����ɹ�"<<endl; 
					}
				}else{
					cout<<"��δ��ʼ��"<<endl; 
				}
				break;
			}
		case 10:
			{
				int num1;
				cout<<"������Ҫ�����Ԫ�ظ���"<<endl;
				cin>>num1;
				cout<<"����������"<<endl;
				cinStack(begin,num1);
				cout<<"����ɹ�"<<endl;
				break;
			}
		case 11:
			{
				return 0;
				break;
			}
		default:
			{
				cout<<"��������"<<endl;
			}
	}
		}
} 
