#include <iostream>
using namespace std;

int set(int n){
	int count = 1;
	for(int i =1;i<=n/2;i++){
		count += set(i);
	}
	return count;
}
int main(){
	int n = 0;
	cin>>n;
	cout << "Set("<<n<<") = "<<set(n)<<endl; 
}
