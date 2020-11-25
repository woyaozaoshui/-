#include<iostream>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1  //����ʵ�е�
#define OVERFLOW -2   //���  
using namespace std;

typedef int Status;

typedef struct LinkNode{
	int data;
	struct LinkNode *next;
}LinkNode,*LinkList;

void createNode(LinkList &head);
void destroyNode(LinkList &head);
Status numberNode(LinkList head);
Status locateElem(LinkList head,int l,int &s1);
Status location(LinkNode &N,int l,int &s2);
Status former(LinkList head,int e,int &s3);
Status later(LinkList head,int e,int &s4);
Status insert(LinkList &head,int l,int e); 
Status remove(LinkList &head,int l);
Status coutelem(LinkList &head);
Status cinelem(LinkList &head,int n);
void clear(LinkList &head);

int success=0;
int num666;

int main()
{
	int choose=0;
	LinkList head;
	head=(LinkList)malloc(sizeof(LinkNode));
	head->data=0;
	head->next=NULL;
	while(1)
	{
		cout<<"1----��ʼ��(����)����������"<<endl;
		cout<<"2----��������"<<endl;
		cout<<"3----���������ݵ�Ԫ�ظ���"<<endl;
		cout<<"4----��ָλ���Ԫ��ֵ"<<endl;
		cout<<"5----�����Ѵ���Ԫ�ص�λ��"<<endl;
		cout<<"6----������Ԫ�أ���ֱ��ǰ��"<<endl;
		cout<<"7----������Ԫ�أ���ֱ�Ӻ��"<<endl;
		cout<<"8----�ڵ�i��λ�ò���Ԫ��"<<endl;
		cout<<"9----ɾ����i��Ԫ��"<<endl;
		cout<<"10----������е�����Ԫ��"<<endl;
		cout<<"11----��ʼ������������Ԫ��"<<endl;
		cout<<"12----�������"<<endl;
		cout<<"0----�˳�"<<endl;
		cout<<"��ѡ��"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				{
					createNode(head);
					cout<<"��ʼ���ɹ�"<<endl;
				}
				break;
			case 2:
				{
					if(success==1)
					{
						destroyNode(head);
						cout<<"�ݻٳɹ�"<<endl;
					}
					else
					{
						cout<<"��δ��ʼ��"<<endl; 
					}
				}
				break;
			case 3:
				{
					int i;
					if(success==1)
					{
						numberNode(head);
						cout<<"Ԫ�ظ���Ϊ"<<num666<<endl;
					}
					else
					{
						cout<<"��δ��ʼ��"<<endl; 
					}
					
				}
				break;
			case 4:
				{
					int i,j;
					if(success==1)
					{
						int s1;
						cout<<"������λ��"<<endl;
						cin>>i;
						locateElem(head,i,s1);
						if(i<1||i>num666)
						{
							cout<<"�������"<<endl;
						}
						else{
						cout<<"��λ�õ�Ԫ��Ϊ:"<<s1<<endl; 
						}
						
					}
					else
					{
						cout<<"��δ��ʼ��"<<endl; 
					}
				}
				break;
			case 5:
				{
					int i,j,s2;
					if(success==1)
					{
						cout<<"������Ԫ��"<<endl;
						cin>>j;
						i=location(*head,j,s2);
						if(i==0)
						{
							cout<<"δ���ҵ�"<<endl;
						}
						else
						{
							cout<<"λ��Ϊ:"<<s2<<endl; 
						} 
					}
					else{
						cout<<"��δ��ʼ��"<<endl;
					}
				}
				break;
			case 6:
				{
					if(success==1)
					{
						LinkList p;
						p=head;
						int i,j,s3;
						bool yes;
						cout<<"������Ԫ��"<<endl;
						cin>>j; 
						while(p->next!=NULL)
						{
							p=p->next;
							if(p->data==j)
							{
								yes=true;
								break;
							} 
						}
						if(yes)
						{
							if(head->next->data==j)
							{
								cout<<"��ǰ��"<<endl; 
							}
							else
							{
								former(head,j,s3);
								cout<<"ǰ��Ϊ"<<s3<<endl;
							}
						}
						else
						{
							cout<<"û�и�Ԫ��"<<endl;
						}
			
					}
					else
					{
						cout<<"��δ��ʼ��"<<endl;
					}
				}
				break;
			case 7:
				{
					if(success==1)
					{
						LinkList p,q;
						p=head;
						bool yes;
						int i,j,s4,asd;
						cout<<"������Ԫ��"<<endl;
						cin>>j; 
						asd=later(head,j,s4);
						if(asd==0)
						{
							cout<<"����"<<endl; 
						}
						else
						{
							cout<<"���Ϊ��"<<s4<<endl;
						}	
				}
				else{
					cout<<"��δ��ʼ��"<<endl;
				}
			}
				break;
			case 8:
				{
					if(success==1)
					{
						int i,j,k;
						cout<<"����������Ҫ�����λ�ú�Ԫ��"<<endl;
						cin>>j;
						cin>>k; 
						i=insert(head,j,k);
						if(i==-1)
						{
							cout<<"����λ������"<<endl;
						}
						if(i==1)
						{
							cout<<"����ɹ�"<<endl;
						} 
					} 
					
					else
					{
						cout<<"��δ��ʼ��"<<endl;
					}
				} 
				break;
			case 9:
				{
					if(success==1)
					{
						int i,j,k;
						cout<<"������Ҫɾ����λ��"<<endl;
						cin>>j;
						i=remove(head,j);
						if(i==-1)
						{
							cout<<"ɾ��λ������"<<endl;
						}
						else if(i==1)
						{
							cout<<"ɾ���ɹ�"<<endl;
						}
					} 
					else
					{
						cout<<"��δ��ʼ��"<<endl;
					}
				
				}
				break;
			case 10:
			{
				if(success==1)
				{
					int ak=coutelem(head);
					if(ak==0)
					{
						cout<<"�ձ�"<<endl;
					}
				}
				else
				{
					system("CLS");
					cout<<"��δ��ʼ��"<<endl;
					
				}
			 } 
			 break;
			case 11:
				{
					int i,j,k;
					cout<<"����Ԫ�ظ���"<<endl;
					cin>>j;
					system("CLS");
					cout<<"������"<<endl;
					int akk=cinelem(head,j);
					if(akk==1)
					{
						cout<<"����ɹ�"<<endl;
					}
					success=1;
				}
				break;
			case 12:
				{
					if(success==1)
					{
						clear(head);
						cout<<"��ճɹ�"<<endl;
					}
					else
					{
						cout<<"��δ��ʼ��"<<endl;
					} 
				}
				break;
			case 0:
				{
					return 0;
				}
			default:
				{
					cout<<"�������"<<endl;
					break;
				}
		}
	}
}

//1��ʼ��(����)����������
void createNode(LinkList &head)
{
	LinkList p;
	p=new LinkNode;
	p->data=0;
	p->next=NULL;
	head=p;
	success=1;
	system("CLS");
}
//2��������
void destroyNode(LinkList &head)
{ 
	LinkList p=head->next;
	while(p!=NULL){
		head->next=p->next;
		free(p);
		p=head->next;
	}
	free(head);
	head=NULL;
		success=0;
		system("CLS");
}
//3���������ݵ�Ԫ�ظ���
Status numberNode(LinkList head)
{
		system("CLS");
		return OK;
}
//4��ָλ���Ԫ��ֵ
Status locateElem(LinkList head,int l,int &s1)
{
		LinkList p;
		p=head;
		if(l<1&&l>num666)
		{
			return ERROR;
		}
		else
		{
			int num=0;
			while(p->next!=NULL)
			{
				p=p->next;
				num++;
				if(num==l)
				{
					s1=p->data;
					system("CLS");
					return OK;
				}
			}
		}
}
//5�����Ѵ���Ԫ�ص�λ��
Status location(LinkNode &N,int l,int &s2)
{
		LinkList p;
		p=&N;
		int num=0;
		while(p->next!=NULL)
		{
			p=p->next;
			num++;
			if(p->data==l)
			{
				s2=num;
				system("CLS");
				return TRUE;
			}
		}
		system("CLS");
		return FALSE;
}
//6������Ԫ�أ���ֱ��ǰ��
Status former(LinkList head,int e,int &s3)
{
	
		LinkList p,q;
		p=head;
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
			if(p->data==e)
			{
				s3=q->data;
				system("CLS");
				return OK;
			}
		}
		system("CLS");
		return ERROR;
} 
//7������Ԫ�أ���ֱ�Ӻ��
Status later(LinkList head,int e,int &s4)
{
		LinkList p,q;
		p=head;
		while(p->next->next!=NULL)
		{
			p=p->next;
			q=p->next;
			if(p->data==e)
			{
				s4=q->data;
				return OK;
			}
		}
		return ERROR;
}
//8�ڵ�i��λ�ò���Ԫ��
Status insert(LinkList &head,int l,int e)
{
		LinkList p,q;
		int location=0;
		p=head;
		q=new LinkNode;
		q->data=e;
		if(l<1||l>num666+1)
		{
			system("CLS");
			return INFEASIBLE;
		}
		else
		{
			while(p->next!=NULL)
			{
				location++;
				if(location==l)
				{
					break;
				}
				p=p->next;
			}
			q->next=p->next;
			p->next=q;
			num666++;
			system("CLS");
			return OK;
		}
}
//9ɾ����i��Ԫ��
Status remove(LinkList &head,int l)
{
		LinkList p,q;
		q=head;
		p=q->next; 
		int location=1;
		if(l<1||l>num666)
		{
			return INFEASIBLE;
		}
		else
		{
			while(p!=NULL)
			{
				if(l==location)
				{
					break;
				}
				
				q=p;
				p=p->next;
				location++;
			}	
			q->next=p->next;
			free(p);
			num666--; 
			system("CLS");
			return OK;
		}
}
//10������е�����Ԫ��
Status coutelem(LinkList &head)
{
		LinkList p;
		p=head;
		int num555=0;
		if(p->next==NULL)
		{
			system("CLS");
			return FALSE;
		}
		else
		{
		system("CLS");
		for(int num555=0;num555<num666;num555++)
		{
			p=p->next;
			cout<<p->data<<"  ";
		}
		}
		cout<<endl;
		return OK;
}
//11��ʼ������������Ԫ��
Status cinelem(LinkList &head,int n)
{/*�����߼����� 
	success=1;
	LinkList p,q;
	p=(LinkList)malloc(sizeof(LinkNode));
	p->data=0;
	p->next=NULL;
	head=p;
	num666=0;
	while(num666!=n)
	{
		q=(LinkList)malloc(sizeof(LinkNode));
		cin>>q->data;
		p->next=q;
		p=q;
		num666++;
	}
	return OK;*/
	success=1;
	LinkList p,q;
	q=head;
	num666=0;
	for(num666=0;num666<n;num666++){
		p=(LinkList)malloc(sizeof(LinkNode));
		if(p==NULL){
			return ERROR;
		}
		cin>>p->data;
		p->next=q->next;
		q->next=p;
		q=p;
	}
	return OK;
}
//12�������
void clear(LinkList &head)
{
	LinkList p=head->next;
	while(p!=NULL){
		head->next=p->next;
		free(p);
		p=head->next;
	}
	system("CLS");
}

