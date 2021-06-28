#include <iostream>
#include <string>
#include <cstdio> 
using namespace std;
/*
基本思想：将n个元素的全排列，划分为n-1个元素全排列，以此类推，最后只剩下一个元素就不需要排列 
		  排列的时候我们需要判断元素是否有重合，如果有重合的，那么直接跳过，否则进行排列
*/
void swap(char &a,char&b){
	char temp = a;
	a = b;
	b = temp;
}
int FindSame(char list[],int k,int m){//寻找重复的元素 
	for(int i = k;i<m;i++){
		if(list[i]==list[m])
			return 1;
	}
	return 0;
}
void Perm(char list[],int k,int m,int &count){
	if(k == m){//递归出口，最后只有一个元素 
		for(int i = 0;i<=m;i++){
			cout<<list[i]; 
		} 
		cout<<endl;
		count++;
	}
	else{
		for(int i = k;i<=m;i++){
			if(FindSame(list,k,i)==1)//这个元素之前被交换过就跳过
				continue;
			swap(list[k],list[i]);//交换两个元素的位置 
//			cout<<"Perm("<<k<<","<<m<<")"<<"first swap:";
//			for(int i = 0;i<=m;i++){
//				cout<<list[i]; 
//			}
//			cout << endl; 
			Perm(list,k+1,m,count);//对k+1~m进行排列 
			swap(list[k],list[i]);//还原原本的数组 
//			cout <<"Perm("<<k<<","<<m<<") "<<"second swap: ";
//			for(int i = 0;i<=m;i++){
//				cout<<list[i]; 
//			} 
//			cout << endl;
		}
	}
}

int main(){
	int n,i,count=0;
	char list[15];
	cout<<"Input element number: ";
	cin>>n;
	cout<<"Input element: "; 
	cin>>list;
	Perm(list,0,n-1,count);
	cout<<"ALL sort number is "<<count<<endl;
	return 0;
} 
