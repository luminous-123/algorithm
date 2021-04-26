#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main(){
	string str;
	char temp;
	cin>>str;
	cout<<str<<endl;
	int i,j,count;
	int length=str.length();
	for(i = j = length-1;i>=0;i--){
		if(str[i]!='*'){
			temp = str[j];
			str[j] = str[i];
			str[i] = temp;
			j--;
		}
		else
			count++;
	}
	cout<<str<<endl;
		
}
