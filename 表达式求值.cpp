#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
 
typedef  int ElemType;
#define STACK_INIT_SIZE 100
#define  STACKINCREMENT 10
#define OK 1
 
typedef struct{
        ElemType *base;//null
        ElemType *top;
        int  stacksize;
}sqStack;
 
void InitStack(sqStack  *s)
{
    s->base=(ElemType*)malloc(STACK_INIT_SIZE* sizeof(ElemType));
    if(!s->base)
    {
        exit(1);
    }
    s->top=s->base;
    s->stacksize=STACK_INIT_SIZE;
}
void Push(sqStack *s,ElemType e)//��e��ֵ����top    eû��
{
    if(s->top-s->base>=s->stacksize) //ջ��׷�Ӵ���ռ�
    {
        s->base=(ElemType*)realloc(s->base,(s->stacksize+STACKINCREMENT)*sizeof(ElemType));
       if(!s->base)
       {
        exit(1);
        }
        s->top=s->base+s->stacksize;
        s->stacksize+=STACKINCREMENT;
    }
    *(s->top)=e;
     s->top++;
    //*s->top++=e     *((s->op)++)=e
 
}
void  Pop(sqStack *s,char *e)//��e�ĵ�ַȥ�õ�ֵ��e�������� ��������
{
        if(s->top==s->base)
             exit(1);
        *e=*(--(s->top));//�������ٸ�ֵ
 
}
char GetTop(sqStack *s)
{
    if(s->top==s->base)
	{
		return -1;
    }
		return  *(s->top-1);
 
}
 
int In(char e)//�ж϶����ַ��Ƿ�Ϊ����� 
{
	if(e=='+'||e=='-'||e=='*'||e=='/'||e=='('||e==')'||e=='#')
	    return 1;//�� 
	else 
	    return 0; //���� 
}
char Precede(char a,char b)//�Ƚ�����������ȼ� 
{
	char f;
	if(a=='+'||a=='-')
	{
		if(b=='+'||b=='-'||b==')'||b=='#')
		    f='>';
		else if(b=='*'||b=='/'||b=='(')
		    f='<';
	}
	else if(a=='*'||a=='/')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
		   f='>';
		else if(b=='(')
		   f='<';
	}
	else if(a=='(')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
		   f='<';
		else if(b==')')
		   f='=';
	}
	else if(a==')')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b==')'||b=='#')
		   f='>';
	}
	else if(a=='#')
	{
		if(b=='+'||b=='-'||b=='*'||b=='/'||b=='(')
		   f='<';
		else if(b=='#')
		   f='=';
	}
	return f;
}
char Operate(char a,char theta,char b)//���� 
{
	char c;
	a=a-'0';
	b=b-'0';
	if(theta=='+')
	  c=a+b+'0';
	else if(theta=='-')
	  c=a-b+'0';
	else if(theta=='*')
	  c=a*b+'0';
	else if(theta=='/')
	  c=a/b+'0';	  
	return c; 
}
int EvaluateExpression()
{
	sqStack OPND,OPTR;
	char ch,a,b,theta,x;
	InitStack(&OPND);//�Ĵ�������������� 
	InitStack(&OPTR);//�Ĵ������ 
	Push(&OPTR,'#');
	ch=getchar();
	while(ch!='#'||GetTop(&OPTR)!='#')
	{
		if(!In(ch))
		{
			Push(&OPND,ch);
			ch=getchar();
		}
		else
		{
			switch(Precede(GetTop(&OPTR),ch))
			{
				case '<':
					Push(&OPTR,ch);
				    ch=getchar();
					break;
				case '>':
					Pop(&OPTR,&theta);
					Pop(&OPND,&b);
					Pop(&OPND,&a);
					Push(&OPND,Operate(a,theta,b));
					break;
				case '=':
					Pop(&OPTR,&x);
				    ch=getchar();
					break;
			}
		} 
	}
	return GetTop(&OPND)-'0';
}
int main()
{
	printf("�������������ʽ,��#����\n");
	printf("����\t  1*(2-1)# \t\n");
	printf("�����: %d\n",EvaluateExpression());
	return OK;
} 
	

