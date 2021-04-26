#include<iostream>
#include<string>
using namespace std;

void Delete_char(string& first,string dele){
	for(int i=0;i<dele.length();i++){
		for(int j =0;j<first.length();j++){
			if(first[j]==dele[i]){
				first.erase(j,1);
			}
		}
	}
	cout<<first<<endl;
	cout<<dele<<endl;
}
int main(){
	string first_string;
	string del_string;
	getline(cin,first_string);
	getline(cin,del_string);
	cout<<"First string="<<first_string<<endl;
	cout<<"delete string="<<del_string<<endl;
//	string Line = "They are students";
//	string str = "aeiou";
//	Delete_char(Line,str);
	Delete_char(first_string,del_string); 
	return 0;
}
