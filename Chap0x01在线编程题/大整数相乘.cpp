#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;

int main(){
	string a,b,weishu = "";
	vector<string> every_time;
	cin>>a>>b;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	int length_a,length_b,jinwei = 0;
	length_a = a.length();
	length_b = b.length();
	for(int i = length_a-1;i>=0;i--){
		int add = 0;
		string result = "";
		for(int j = length_b-1;j>=0;j--){
			add = ((int(a[i])-48)*(int(b[j])-48)+jinwei)%10;//每一轮个位的加数
			jinwei = ((int(a[i])-48)*(int(b[j])-48)+jinwei)/10; //每一次的进位
			result = char(add+48) + result;
		}
		every_time.push_back((result+weishu));//将每一轮的结果存进向量中，用于最后相加计算 
		weishu = weishu+'0';
	}
	for(int i = every_time.size()-1;i>=0;i--){
		cout<<every_time.at(i)<<endl;
		
	} 
}
