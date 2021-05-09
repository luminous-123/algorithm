#include <iostream>
#include <cstdlib>
using namespace std;

typedef int ElemType;
typedef struct LNode{
	ElemType data;
	struct LNode* next;
}LNode,*LinkList;
//β�巨 
void CreateList(LinkList &L,ElemType a[],int n){
	LinkList p, r;
	L = (LinkList)malloc(sizeof(LNode));
	L->data = a[0];
	r = L;
	for(int i = 1;i<n;i++){
		p = (LNode*)malloc(sizeof(LNode));
		p->data = a[i];
		r->next = p;
		r = p;
	}
	r->next = NULL;
}
void DispList(LinkList L){
	LNode* p = L;
	while(p!=NULL){
		cout<<p->data<<endl;
		p = p->next;
	}
}

void ClearList(LinkList &L){
	if(L!=NULL){
		ClearList(L->next);
		free(L);
	}
}
