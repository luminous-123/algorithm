#include<iostream>
#include<cstdlib>
#include "LinkList.h"
using namespace std;

void Reverse_Print(LinkList L){
	if(!L)
		return;
	Reverse_Print(L->next);
	cout<<L->data<<endl;
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
	Reverse_Print(L);
}
