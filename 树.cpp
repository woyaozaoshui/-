#include<stdio.h>
#include<stdlib.h>
typedef struct Node          //�������ṹ����
{
	char data;
	struct Node *lchild;
	struct Node *rchild;
}Bitree;




void CreateBiTree(Bitree *&t)    //�����������������
{
	char s;
	scanf("%c",&s);
	if(s=='#')
		t=NULL;
	else
	{
		t=(Bitree *)malloc(sizeof(Node));
		t->data=s;
		CreateBiTree(t->lchild);
		CreateBiTree(t->rchild);
	}
}




void Output(Bitree *t)                 //����������������
{
	if(t!=NULL)
	{
		printf("%c ",t->data);
		Output(t->lchild);
		Output(t->rchild);
	}
}




int main()
{
	Bitree *root;
	printf("���������������Ϊ��������ֵ:");
	CreateBiTree(root);
	printf("������������������:");
	Output(root);
	printf("\n");
	return 0;
}
