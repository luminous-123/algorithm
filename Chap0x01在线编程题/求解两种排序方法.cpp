#include<iostream>
#include<string>
#include<vector>
using namespace std;

void Check_Word(vector<string> words){
	bool islexicalorder=true;
	bool lengths=true;
	string pword;
	for(int i = 1;i<words.size();i++){
		pword=words[i-1];
		if(pword.length()>words[i].length()){
			lengths=false;
		}
		if(pword>words[i]){
			islexicalorder=false;
		}
	}
	if(lengths&&!islexicalorder){
		cout<<"lengths"<<endl;
	}
	if(islexicalorder&&!lengths){
		cout<<"islexicalorder"<<endl;
	}
	if(!islexicalorder&&!lengths){
		cout<<"none"<<endl;
	}
	if(islexicalorder&&lengths){
		cout<<"both"<<endl;
	}
}

int main(){
	int row;
	scanf("%d",&row);
	vector<string> words;
	for(int i = 0;i<row;i++){
		string word;
		cin>>word;
		words.push_back(word);
//		cout<<word.length()<<endl;
	}
	Check_Word(words);
	return 0; 
}

