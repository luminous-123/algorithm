#include<iostream>
#include<vector> 
#include<string>
using namespace std;

bool Loop_Word(string L1,string L2){
	int size1=L1.size();
	int size2=L2.size();
	if(size1==0||size2==0) return false;
	string str=L2+L2;
	if(str.find(L1)==-1){
		return false;
	}
	return true;
}

int main(){
	int n;
	vector<string> loopword;
	cin>>n;
	for(int i = 0;i<n;i++){
		string str1,str2;
		cin>>str1>>str2;
		loopword.push_back(str1);
		loopword.push_back(str2);
	}
//	cout<<loopword.size()<<endl;
	for(int i = 0;i<loopword.size();i+=2){
		string s1=loopword[i];
		string s2=loopword[i+1];
		if(Loop_Word(s1,s2)){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
} 
