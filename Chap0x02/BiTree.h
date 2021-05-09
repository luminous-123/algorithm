#include <iostream>
#include <cstdlib>
using namespace std;
typedef int ElemType;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

BiTree CreateBTree(ElemType a[],ElemType b[],int n) //对应例2.8的算法
//由先序序列a[0..n-1]和中序序列b[0..n-1]建立二叉链
{
 int k;
 if (n<=0) return NULL;
 ElemType root=a[0];   //根结点值
 BiTree bt=(BiTNode *)malloc(sizeof(BiTNode));
 bt->data=root;
 for (k=0;k<n;k++)   //在b中查找b[k]=root的根结点
  if (b[k]==root)
   break;
 bt->lchild=CreateBTree(a+1,b,k);   //递归创建左子树
 bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1); //递归创建右子树
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
void DestroyBTree(BiTNode *&bt)  //对应例2.9的算法
//释放以bt为根结点的二叉树
{ if (bt!=NULL)
 { DestroyBTree(bt->lchild);
  DestroyBTree(bt->rchild);
  free(bt);
 }
}
