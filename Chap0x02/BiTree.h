#include <iostream>
#include <cstdlib>
using namespace std;
typedef int ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBTree(ElemType a[],ElemType b[],int n) //��Ӧ��2.8���㷨
//����������a[0..n-1]����������b[0..n-1]����������
{
 int k;
 if (n<=0) return NULL;
 ElemType root=a[0];   //�����ֵ
 BiTree bt=(BiTNode *)malloc(sizeof(BiTNode));
 bt->data=root;
 for (k=0;k<n;k++)   //��b�в���b[k]=root�ĸ����
  if (b[k]==root)
   break;
 bt->lchild=CreateBTree(a+1,b,k);   //�ݹ鴴��������
 bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1); //�ݹ鴴��������
 return bt;
}
void PreOrderTraverse(BiTree T){
	if(T){
		cout<<T->data<<endl;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
	else
		return;
}
void DestroyBTree(BiTNode *&bt)  //��Ӧ��2.9���㷨
//�ͷ���btΪ�����Ķ�����
{ if (bt!=NULL)
 { DestroyBTree(bt->lchild);
  DestroyBTree(bt->rchild);
  free(bt);
 }
}
