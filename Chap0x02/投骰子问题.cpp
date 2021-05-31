#include <iostream>
using namespace std;

int count;
int step(int n){
	int sum = 0;
	if(n == 1){
		count = 1;//当n为1的时候，就只有一种投掷方法 
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
