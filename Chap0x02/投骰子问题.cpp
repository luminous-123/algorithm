#include <iostream>
using namespace std;

int count;
int step(int n){
	int sum = 0;
	if(n == 1){
		count = 1;//��nΪ1��ʱ�򣬾�ֻ��һ��Ͷ������ 
	}
	else{
		for(int i = n-1;i>=1;i--){
			sum = sum + step(i); 
		}
		count = sum + 1; 
	} 
	return count;
}
int main(){
	int n = 0;
	cin >> n;
	cout<<step(n);
	return 0;
}
