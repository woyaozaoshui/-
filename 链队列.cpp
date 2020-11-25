#include<iostream>
#include<malloc.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
} QNode,*QueuePtr;

typedef struct {
	QueuePtr front,rear;
} LinkQueue;

//��ʼ������
int InitQueue(LinkQueue &Q) {
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if(!Q.front) {
		cout<<"��ʼ��ʧ�ܣ�"<<endl;
		return ERROR;
	}
	Q.front->next=NULL;
	return OK;
}

//���ٶ���
int DestroyQueue(LinkQueue &Q) {
	while(Q.front) {
		Q.rear=Q.front->next;
		free(Q.front);
		Q.front=Q.rear;
	}
	return OK;
}

//��ն���
int ClearQueue(LinkQueue &Q) {
	QueuePtr p,q;
	Q.rear=Q.front;
	p=Q.front->next;
	Q.front->next=NULL;
	while(p) {
		q=p;
		p=p->next;
		free(q);
	}
	return OK;
}

//�ж϶����Ƿ�Ϊ��
int QueueEmpty(LinkQueue Q) {
	if(Q.front==Q.rear) {
		cout<<"����Ϊ�գ�"<<endl;
		return TRUE;
	} else {
		cout<<"���в�Ϊ�գ�"<<endl;
		return FALSE;
	}
}

//���ض�����Ԫ�ظ���
int QueueLength(LinkQueue Q) {
	QueuePtr p;
	int i=0;
	p=Q.front;
	while(p!=Q.rear) {
		i++;
		p=p->next;
	}
	cout<<"������Ԫ�ظ���Ϊ��"<<i<<endl;
	return OK;
}

//���ض��ж�ͷԪ��
int QueueFront(LinkQueue Q) {
	QueuePtr p;
	if(Q.front==Q.rear) {
		cout<<"�ö����ǿյģ�"<<endl;
		return ERROR;
	}
	p=Q.front->next;
	cout<<"����ͷԪ��Ϊ��"<<p->data<<endl;
	return OK;
}

//�����µĶ�βԪ��
int InsertQueue(LinkQueue &Q,QElemType e) {
	QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
	if(!s) {
		cout<<"����ʧ�ܣ�"<<endl;
		return ERROR;
	}
	s->data=e;
	s->next=NULL;
	Q.rear->next=s;
	Q.rear=s;
	return OK;
}

//ɾ����ͷԪ��
int DeQueue(LinkQueue &Q) {
	QueuePtr p;
	if(Q.front==Q.rear) {
		cout<<"�ö����ǿյģ�ɾ��ʧ�ܣ�"<<endl;
		return ERROR;
	}
	p=Q.front->next;
	Q.front->next=p->next;
	if(Q.rear==p) Q.rear=Q.front;
	free(p);
	cout<<"ɾ���ɹ���"<<endl;
	return OK;
}

//��ʼ������������
int PutIn(LinkQueue &Q) {
	InitQueue(Q);
	QElemType e;
	while((cin>>e)!=0) {
		if(e<0) return ERROR;
		InsertQueue(Q,e);
	}
	return OK;
}

//�������Ԫ��
int QueueTraverse(LinkQueue Q) {
	QueuePtr p;
	p=Q.front->next;
	while(p) {
		cout<<p->data<<" ";
		p=p->next;
	}
	return OK;
}

int main() {
	cout<<"��ִ�в����У�" <<endl;
	cout<<"    1.��ʼ������            "<<endl;
	cout<<"    2.���ٶ���              "<<endl;
	cout<<"    3.��ն���              "<<endl;
	cout<<"    4.�ж϶����Ƿ�Ϊ��      "<<endl;
	cout<<"    5.���ض�����Ԫ�ظ���    "<<endl;
	cout<<"    6.���ض��ж�ͷԪ��      "<<endl;
	cout<<"    7.�����µĶ�βԪ��      "<<endl;
	cout<<"    8.ɾ����ͷԪ��          "<<endl;
	cout<<"    9.��ʼ������������      "<<endl;
	cout<<"   10.�������Ԫ��          "<<endl;
	cout<<"   11.�˳�                  "<<endl;
	cout<<endl<<"���������ѡ��";
	LinkQueue q;
	q.front=NULL;
	QElemType e;
	int num;
	while( (cin>>num) != 0 ) {
		switch(num) {
			case 1:
				if(q.front) {
					cout<<"�ѳ�ʼ�����У�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					InitQueue(q);
					cout<<"��ʼ���ɹ���"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 2:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					DestroyQueue(q);
					cout<<"���ٳɹ���"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 3:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					ClearQueue(q);
					cout<<"��ճɹ���"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 4:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					QueueEmpty(q);
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 5:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					QueueLength(q);
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 6:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					QueueFront(q);
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 7:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					cout<<"���������Ԫ�أ�";
					cin>>e;
					int a=InsertQueue(q,e);
					if(a==1) cout<<"����ɹ���"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 8:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					DeQueue(q);
					cout<<endl<<"���������ѡ��";
					break;
				}
			case 9:
					cout<<"���������Ԫ�ز���һ��������β��"<<endl;
					PutIn(q);
					cout<<endl<<"���������ѡ��";
					break;
			case 10:
				if(q.front == NULL) {
					cout<<"�����в����ڣ�"<<endl;
					cout<<endl<<"���������ѡ��";
					break;
				} else {
					if(q.front==q.rear) {
						cout<<"�ö�����û��Ԫ�أ�"<<endl;
						cout<<endl<<"���������ѡ��";
						break;
					} else {
						cout<<"����Ԫ��Ϊ��";
						QueueTraverse(q);
						cout<<endl;
						cout<<endl<<"���������ѡ��";
						break;
					}
				}
			case 11:
				return 0;
			default:
				cout<<"��������Ч�����������룺";
				break;
		}
	}
	return 0;
}
