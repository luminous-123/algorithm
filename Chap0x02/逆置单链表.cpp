#include<iostream>
#include<cstdlib>
#include "LinkList.h"
using namespace std;

void Print(LinkList L){
	LNode *p,*q;
	if(!L){
		return;
	}
	cout<<L->data<<endl;
	Print(L->next);
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
	Print(L);
	return 0;
} 
