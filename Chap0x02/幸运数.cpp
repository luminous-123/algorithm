#include <iostream>
#include <vector> 
using namespace std;

int g(int ord){
	if(ord == 0)
		return 0;
	return ord % 2 +  g(ord/2);
} 

int f(int n){
	if(n==0)
		return 0;
	return n % 10 + f(n/10);
} 
int main(){
	int n;
	int count = 0;
	cin >> n;
	for(int i = 1;i<=n;i++){
		if(f(i)==g(i))
			count++; 
	} 
	cout << count << endl;
} 
