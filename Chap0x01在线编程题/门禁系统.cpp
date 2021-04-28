#include<iostream>
#include<vector>
using namespace std;

void count_number(vector<int> menjin,int times){
	int count[times]={0};
	vector<int> count_times;
	for(int i = 0;i<times;i++){
		cout<<++count[menjin[i]]<<" ";
	}
}
int main(){
	int times;
	vector<int> menjin;
	cin>>times;
//	cout<<times;
	for(int i = 0;i<times;i++){
		int a;
		cin>>a;
		menjin.push_back(a);
//		cout<<menjin[i]<<"\t";
	}
	count_number(menjin,times);
}
