#include <iostream>
#include <string>
#include <cstdio> 
using namespace std;
/*
����˼�룺��n��Ԫ�ص�ȫ���У�����Ϊn-1��Ԫ��ȫ���У��Դ����ƣ����ֻʣ��һ��Ԫ�ؾͲ���Ҫ���� 
		  ���е�ʱ��������Ҫ�ж�Ԫ���Ƿ����غϣ�������غϵģ���ôֱ�������������������
*/
void swap(char &a,char&b){
	char temp = a;
	a = b;
	b = temp;
}
int FindSame(char list[],int k,int m){//Ѱ���ظ���Ԫ�� 
	for(int i = k;i<m;i++){
		if(list[i]==list[m])
			return 1;
	}
	return 0;
}
void Perm(char list[],int k,int m,int &count){
	if(k == m){//�ݹ���ڣ����ֻ��һ��Ԫ�� 
		for(int i = 0;i<=m;i++){
			cout<<list[i]; 
		} 
		cout<<endl;
		count++;
	}
	else{
		for(int i = k;i<=m;i++){
			if(FindSame(list,k,i)==1)//���Ԫ��֮ǰ��������������
				continue;
			swap(list[k],list[i]);//��������Ԫ�ص�λ�� 
//			cout<<"Perm("<<k<<","<<m<<")"<<"first swap:";
//			for(int i = 0;i<=m;i++){
//				cout<<list[i]; 
//			}
//			cout << endl; 
			Perm(list,k+1,m,count);//��k+1~m�������� 
			swap(list[k],list[i]);//��ԭԭ�������� 
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
