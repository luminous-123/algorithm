#include <iostream>
#include <cstdio> 
using namespace std;
/*
	��Ҫ�����ܶ�İ�n�ֳ����ſ���ʹ�ó˻���󣬵���1��������ʱ�򣬳˻�һ�����������ģ�������ȥ��ҲҪʹÿ�����Ӿ����ܵĿ��� 
	��2+3+...+nֱ���ʹ��ڵ���s
	1. sum-s = 1��ô�Ͱ�2ȥ����Ȼ�����������һ
	2. sum-s = k���Ͱ�k�Ǹ���ȥ����Ȼ��k���䵽�������� 
*/
int main(){
	int a[1000];//��ֵ���
	int n;
	cin>>n;
	int sum = 0,l = 0,surplus = 0,ans=1;
	for(int i =2;i<=n;i++){
		a[l++] = i; //�洢2,3,...n 
		sum += i; // ����sum = 2+3+...+n 
		if(sum == n){
			break;
		}
		if(sum>n){ //sum>n
			sum = sum-i;//��ȥ���� 
			l--;//����-1�� 
			surplus = n-sum;//����ʣ�»�û�з������ 
			break;
		}
	}
	for(int i = l-1;surplus;surplus--){
		a[i]++;//��ʣ������Ӵ�С���� 
		i--;
		if(i<0)
			i = l-1; 
	}
	for(int i=0;i<l;i++){
		ans = ans * a[i];
		cout << a[i] << " ";
	} 
	cout << endl;
	cout << ans<<endl;
} 
