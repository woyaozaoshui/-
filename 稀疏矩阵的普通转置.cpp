#include<cstring>
#include<cstdio>
#define M 100
typedef struct
{
    int x;    //����Ԫ����
    int y;    //����Ԫ����
    int v;   //����Ԫ�ر����ֵ
}node;         //������Ԫ������Ӧ����Ԫ��
typedef struct
{
    int nu;   //�������
    int mu;   //�������
    int tu;   //�������Ԫ�صĸ���
    node data[2000];
}matrix;       //���������������Ԫ������ɵĽṹ
matrix A;
matrix B;
void trans_A()     //����ת��
{
    B.mu=A.nu;
    B.nu=A.mu;
    B.tu=A.tu;
    if(B.tu>0)
    {
        int p=1;
        for(int j=1;j<=A.mu;j++)
        {
            for(int i=1;i<=A.tu;i++)
            {
                if(A.data[i].y==j)
                {
                    B.data[p].x=A.data[i].y;
                    B.data[p].y=A.data[i].x;
                    B.data[p].v=A.data[i].v;
                    p++;
                }
            }
        }
    }
}
int main()
{
    int r,c;
    int num;
    int t=1;
    printf("��������Ҫת�þ����������(�м��ÿո����)��\n"); 
    scanf("%d%d",&r,&c);
    A.mu=r;
    A.nu=c;
    A.tu=0;
    printf("���������\n");
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            scanf("%d",&num);
            if(num!=0)       //����Ԫ�ؽ���Ԫ��
            {
                A.data[t].x=i;
                A.data[t].y=j;
                A.data[t].v=num;
                t++;
                A.tu++;
            }
        }
    }
    trans_A();         //����ת��
    t=1;
    int sum=0;
    printf("ת�ú�ľ���\n"); 
    for(int i=1;i<=c;i++)
    {
        for(int j=1;j<=r;j++)
        {
            if(B.data[t].x==i&&B.data[t].y==j)
            {
                printf("%d ",B.data[t].v);
                t++;
            }
            else
                printf("0 ");
            sum++;
            if(sum%r==0)
                printf("\n");
        }
    }
    return 0;
}
































