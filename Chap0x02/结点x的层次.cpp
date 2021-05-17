#include<iostream>
#include<cstdlib>
#include "BiTree.h"
using namespace std;
int Find_High(BiTree T,int x,int high){
	 if(!T)
	 	return 0;
	if(T->data==x)
		return high;
	int rhigh = Find_High(T->rchild,x,high+1);
	int lhigh = Find_High(T->lchild,x,high+1);
	if(lhigh==0&&rhigh==0)
		return 0;
	else if(lhigh!=0)
		return lhigh;
	else 
		return rhigh;
}
int main(){
	BiTree T;
	int count = 1,k;
	cin>>k;
	ElemType a[] = {1,5,2,3,4};
	ElemType b[] = { 5,1,3,2,4 };

	T = CreateBTree(a, b, 5);

	int sum = Find_High(T,k,count);

	cout << sum << endl;

	return 0;
}
