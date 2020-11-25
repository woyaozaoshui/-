#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#define True 1;
#define False 0;
#define STACK_INIT_SISE 100
#define STACKINCREMENT 10
using namespace std; 

typedef char TElemType;
typedef int Status;

typedef struct BiTNode{
	TElemType data;
	struct BiTNode *lchild,*rchild;	
}BiTNode,*BiTree;

typedef BiTree ElemType;

typedef struct QNode{
	ElemType data;
	struct QNode *next;
}QNode,*QueuePtr; 

typedef struct{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

//����ջ�Ļ�������

void Initstack(SqStack &S){//��ʼ��ջΪ��ջ 
	S.base = (ElemType *)malloc(STACK_INIT_SISE*sizeof(ElemType));//��ջ�׷����ڴ�ռ� 
	S.top = S.base;
	S.stacksize = STACK_INIT_SISE; 
} 

void Destorystack(SqStack &S){//�ݻ�ջ 
	free(S.base);
	S.base = NULL;
	S.stacksize = 0;
} 

int ClearStack(SqStack &S){//���ջ 
	S.stacksize = 0;
	if(S.stacksize == 0);
	return 1;
	return 0;
}

int StackEmpty(SqStack S){//�ж�ջ�Ƿ�Ϊ�� 
	if(S.top == S.base)
	return 1;
	return 0;
}

int StackLength(SqStack S){//����ջ�ĳ���
	return (S.top-S.base);
}

void Push(SqStack &S,ElemType e){
	if(S.top - S.base >= S.stacksize){
	S.base = (ElemType *)realloc(S.base,(S.stacksize + STACKINCREMENT)*sizeof(ElemType));
//	if(!S.base) exit(OVERFLOW)�� 
	S.top = S.stacksize + S.base;//���¶�λջ��Ԫ�ص�λ��
	S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;//��ֵ����ջ��֮��ָ��λ�ü�һ 
} 

void Pop(SqStack &S,ElemType &e){//ɾ��ջ��Ԫ�أ���������ֵ
	S.top--;
	e=*S.top;
}

//���ڶ��еĻ�������

void InitQueue(LinkQueue &Q){
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
//	if(!Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
}

void DestroyQueue(LinkQueue &Q){//�ݻٶ��� 
	while(Q.front){
		Q.rear = Q.front->next;
		free(Q.front);
		Q.front = Q.rear;
	}
}

int ClearQueue(LinkQueue &Q){//������� 
	QueuePtr p = Q.front->next;
	while(p){
		Q.front->next = p->next;
		free(p);
		p = Q.front->next;
	}
	Q.front->data = 0;
	Q.front->next = NULL;
	if(p==NULL)
	return 1;
	return 0;
}

int QueueEmpty(LinkQueue Q){//�ж϶����Ƿ�Ϊ��
	if(Q.front==Q.rear)
	return 1;
	return 0;
}

int QueueLength(LinkQueue Q){//���ض�����Ԫ�ظ���
	int n=0;
	while(Q.front!=Q.rear){
		Q.front=Q.front->next;
		n++;
	}
	return n;
}

int GetHead(LinkQueue Q,ElemType &e){//���ض��ж�ͷԪ��
	if(Q.rear==Q.front)
	return 0;
	QueuePtr p=Q.front->next;
	e=p->data;
	return 1;
}

void EnQueue(LinkQueue &Q,ElemType e){//�����βԪ�� 
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	
	p->data = e;
	p->next = NULL;
	Q.rear->next = p;	//�޸�β�ڵ��ָ�� 
	Q.rear = p;  		//�ƶ���β��ָ�� 
}

void DeQueue(LinkQueue &Q,ElemType &e){//�����ͷԪ�� 
	QueuePtr p;
	p = Q.front->next;
	e = p->data;
	Q.front->next=p->next;
	if(p==Q.rear)
	Q.rear=Q.front;
	free(p);	
}

//�ص��������Ĳ���

void CreateBiTree(BiTree &T){
	char n;
	cin>>n;
	if(n == '#'){
		T = NULL;
	}else{
		T=(BiTree)malloc(sizeof(BiTNode));
		T->data = n;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
} 

Status PreOrderTraverse(BiTree T)//����ݹ� 
{
	if(T==NULL){
		return False;
	}
	else{
		cout<<T->data<<endl;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}

Status InOrderTraverse(BiTree T)//����ݹ� 
{
 
    if(T==NULL){
    	return False;
	}else{
        InOrderTraverse(T->lchild);
        cout<<T->data<<endl;
        InOrderTraverse(T->rchild);
    }
}

Status PostOrderTraverse(BiTree T)//�����ݹ�
{
 
    if(T==NULL){
    	return False;
	}else{
        InOrderTraverse(T->lchild);
        InOrderTraverse(T->rchild);
        cout<<T->data<<endl;
    }
}


void PreOrderTraverse_Nonrecursion(BiTree T){//ǰ��ǵݹ���� 
	SqStack S;
	Initstack(S);
	BiTree p=T;
    while(p || !StackEmpty(S)){
        if(p){
            Push(S, p) ;
			cout<<p->data<<endl;
            p = p->lchild ;
        }else{
            Pop(S, p) ;
            p = p->rchild ;
        }
    }
}

void InOrderTraverse_Nonrecursion(BiTree T){//����ǵݹ���� 
	SqStack S;
	Initstack(S);
	BiTree p=T;
	while( p || !StackEmpty(S)){
		if(p){
			Push(S,p);
			p=p->lchild;
		}else{
			Pop(S,p);
			cout<<p->data<<endl;
			p=p->rchild;
		}
	}
}

//void PostOrderTraverse_Nonrecursion//����ǵݹ���� 

int TreeDeep(BiTree T){//��� 
	int deep=0;
	if(T){
		int ldeep=TreeDeep(T->lchild);
		int rdeep=TreeDeep(T->rchild);
		deep=ldeep>=rdeep?ldeep+1:rdeep+1;
	}
	return deep;
} 

void LevelOrderTraverse(BiTree T){//������� 
	BiTree p=T; 
	LinkQueue Q;
	InitQueue(Q);
	EnQueue(Q,p);
	while(QueueEmpty(Q)!=1){//ѭ��������Q��Ϊ�� 
		DeQueue(Q,p);//������ͷԪ�� �����p�� 
		cout<<p->data<<endl;; 
		if(p->lchild!=NULL)
		EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
		EnQueue(Q,p->rchild);
	}
}

int main()
{
	while(1)
	{
	BiTree T;
	cout<<endl;
	cout<<"***********************"<<endl;
	cout<<"1.����������"<<endl;
	cout<<"2.����������������ݹ飩"<<endl;
	cout<<"3.����������������ݹ飩"<<endl;	 
	cout<<"4.����������������ݹ飩"<<endl;
	cout<<"5.����������������ǵݹ飩"<<endl;
	cout<<"6.����������������ǵݹ飩"<<endl;
	cout<<"7.�������������"<<endl;
	cout<<"8.������������"<<endl;
	cout<<"0.�˳�"<<endl;
	cout<<"***********************"<<endl;
	cout<<"��ѡ��"<<endl;
	int choose=0;
	BiTNode *Thre;
	cin>>choose;
	switch(choose){
		case 1:
			{
				cout<<"�����������ֵ��(һ���ַ�)��"<<endl;
				cout<<"������#ʱ��ʾ�����㲻����"<<endl;
				CreateBiTree(T);
				cout<<"�����ɹ�"<<endl;
				break;
			}
		case 2: 
		{
			PreOrderTraverse(T);
			break; 
		}
		case 3:
		{
			InOrderTraverse(T);
			break;	
		} 
		case 4:{				
			PostOrderTraverse(T);
			break;
		}
		case 5:{
			PreOrderTraverse_Nonrecursion(T);
			break;
		}
		case 6:{
			InOrderTraverse_Nonrecursion(T);
			break; 
		}
		case 7:{
			LevelOrderTraverse(T);
			break;
		}
		case 8:{
			cout<<TreeDeep(T)<<endl;;
			break;
		}		
		case 0:{				 
			break;
		}
		default:{
			cout<<"��������Ч�Ĳ�����"<<endl;
			break;
		}
	}
	}return 0;	
}
 













































































































