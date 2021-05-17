#include<iostream>
#include<cstdlib>
#include "BiTree.h"
using namespace std;
int Count_Node(BiTree T,int k){
	if(!T->lchild&&!T->rchild)
		return T->data >= k ? 1:0;
	else if(!T->lchild)
		return Count_Node(T->rchild,k);
	else if(!T->rchild)
		return Count_Node(T->lchild,k);
	return T->data >= k? 1+Count_Node(T->lchild,k) + Count_Node(T->rchild,k):Count_Node(T->lchild,k) + Count_Node(T->rchild,k); 
}

int main(){
	BiTree T;
	int count = 0,k;
	cin>>k;
	ElemType a[] = {1,5,2,3,4};
	ElemType b[] = { 5,1,3,2,4 };

	T = CreateBTree(a, b, 5);

	int sum = Count_Node(T,k);

	cout << sum << endl;

	return 0;
}
