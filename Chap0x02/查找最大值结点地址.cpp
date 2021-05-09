#include<iostream>
#include<cstdlib>
#include "LinkList.h"
using namespace std;

LinkList Find_Max(LinkList L){
	if(!L->next)
		return L;
	LNode* temp = Find_Max(L->next);
	return L->data > temp->data ? L : temp;
} 

int main(){
	LinkList L;
	int n;
	int a[156];
	cin>>n;
	getchar();
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	CreateList(L,a,n);
	cout<<Find_Max(L)<<endl;
	return 0;
}
