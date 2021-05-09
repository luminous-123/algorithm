#include<iostream>
#include<cstdlib>
#include "LinkList.h"
using namespace std;

LinkList Find_x(LinkList L,ElemType x){
	if(!L)
		return NULL;
	if(L->data == x)
		return L;
	else
		return Find_x(L->next,x);
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
	cout<<"ÊäÈë²éÕÒÖµ:";
	cin>>x;
	CreateList(L,a,n);
	cout<<Find_x(L,x)<<endl;
}
