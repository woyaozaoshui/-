#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

typedef enum Tag{
	Ptr,Thread
}PointerTag;
//Ptr=0:ָ�룬Thread=1������ 

//��������Ľ��ṹ 
typedef struct ThreadTreeNode{
	char data; 						//������ 
	struct ThreadTreeNode* lchild;  //����ָ���� 
	struct ThreadTreeNode* rchild;  //�Һ���ָ���� 
	PointerTag LTag;  				//���־λ 0 1 
	PointerTag RTag;				//�ұ�־λ 0 1 
}Tnode,*Ttree;

Ttree pre;  //ָ��ոշ��ʹ��Ľ�� 

void createBiTree(Ttree& T);				 //�����������������Ϣ 
void inOrderThreadTree(Ttree& Thrt,Ttree T); //����������������������������� 
void inThreading(Ttree p);		 			 //����������(�ݹ�)
void inOrderTraverse(Ttree Thrt);		     //�������������(�ǵݹ�)����ʱ�������Ѿ������� 

void createBiTree(Ttree& T)
{
	char ch;
	cin>>ch;
	if(ch=='#')	T=NULL;
	else
	{
		if(!(T=(Tnode*)malloc(sizeof(Tnode))))  exit(0);
		//����ע����ȷ�����˳�� 
		T->data=ch;
		//���н������ұ�־��ʼ����ΪPtr 0 
		T->LTag=Ptr;
		T->RTag=Ptr;
		createBiTree(T->lchild); //�ȹ��������� 
		createBiTree(T->rchild); //�ٹ��������� 
	}
}

void visit(char data)
{
	cout<<data;
}

//���������������������(�ǵݹ�) 
void inOrderTraverse(Ttree Thrt)
{
	Ttree p;
	//Tָ��ͷ��㣬pָ������ 
	p=Thrt->lchild;
	while(p!=Thrt)   //��p==T���������ɣ��ٴλص�ͷ��� 
	{
		while(p->LTag==Ptr)
		{
			p=p->lchild;  //ֱ���ҵ����������������������� 
		}
		visit(p->data);
		cout<<p->LTag<<p->RTag<<endl;
		while(p->RTag==Thread&&p->rchild!=Thrt)
		{
			p=p->rchild;
			visit(p->data);
			cout<<p->LTag<<p->RTag<<endl;
		}
		p=p->rchild;
	}
}

void inOrderThreadTree(Ttree& Thrt,Ttree T)
{
	//����ͷ���Thrt 
	if(!((Thrt)=(Ttree)malloc(sizeof(Tnode))))  exit(0);
	Thrt->LTag=Ptr;				//ͷ�������־λΪ0��ָ�� 
	Thrt->RTag=Thread;			//ͷ�����ұ�־λΪ1������ 
	Thrt->rchild=Thrt;  		//��ָ���ָ����
	if(!T)  Thrt->lchild=Thrt;  //������Ϊ��ʱ��ָ��Ϊ�ޣ���ָ���� 
	else						 
	{
		//�����������ڣ���ͷ����������������Ӧ������
		Thrt->lchild=T;			
		pre=Thrt;				//ͷ���Ϊǰ�� 
		inThreading(T);		    //���������������������
		pre->rchild=Thrt;		//��ָ���ָ���� 
		pre->RTag=Thread;		
		Thrt->rchild=pre; 
	}
}

void inThreading(Ttree p)
{
	//ͬ��������ҵĵݹ�˼�� 
	if(p)
	{ 
		inThreading(p->lchild);
		visit(p->data);
		if(!p->lchild)   //��ָ����Ϊ���������� 
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild) 
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
		pre=p;
		inThreading(p->rchild); 
	}
} 

int main()
{
	Ttree Thrt;  //ͷ��� 
	Ttree T;  	 //����� 
	createBiTree(T);
	inOrderThreadTree(Thrt,T);
	cout<<endl;
	inOrderTraverse(Thrt);
	return 0;
} 
 













































































































