#include<iostream>
#include<cstdlib>
#include "LinkList.h"
using namespace std;

void Delete_x(LinkList &L,ElemType x){
	if(!L)
		return;
	else if(L->data == x){
		L = L->next;
		return;
	}
	else{
		return Delete_x(L->next,x);
	}
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
	int x;
	cout<<"ÊäÈëÉ¾³ýÖµ:";
	cin>>x;
	CreateList(L,a,n);
	Delete_x(L,x);
	DispList(L); 
}
