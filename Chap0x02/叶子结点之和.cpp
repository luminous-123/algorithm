#include<iostream>
#include<cstdlib>
#include "BiTree.h"
using namespace std;

int Sum_Leaf(BiTree T){
	if(!T->lchild&&!T->rchild)
		return T->data;
	return Sum_Leaf(T->lchild) + Sum_Leaf(T->rchild);
}

int main(){
	BiTree T;
	ElemType a[] = {1,5,2,3,4};
	ElemType b[] = { 5,1,3,2,4 };

	T = CreateBTree(a, b, 5);

	int sum = Sum_Leaf(T);

	cout << sum << endl;

	return 0;
}
