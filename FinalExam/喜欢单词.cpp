#include <iostream>
#include <string>
#include <vector> 
using namespace std;
/*不喜欢的情况 
1. 有小写字母
2. 有连续相同的字母
3. 有相同的子序列 (可以不连续)
*/ 
//蛮力法 
bool checkSeq(string s){
	int i = 0,j = 0,x = 0;
	for(i = 0;i<s.length();i++){
		if(s[i]<'A'||s[i]>'Z'){//判断大写字母 
			return false;
		}
		if(i<s.length()-1){
			if(s[i]==s[i+1]){ //判断连续字母 
				return false;
			}
		}
	}
	for(i = 0;i<s.length()-1;i++){//寻找是否有相同的子序列 
		for(j = i+1;j<s.length();j++){
			if(s[i]==s[j]){//有第一个字母相同 
				for(int k = i+1;k<j;k++){//然后判断i之后的字母有没有与j之后相同的 
					for(x = j+1;x<s.length();x++){ //这样可以判断是否有不连续的相同子序列 
						if(s[k]==s[x])
							return false;
					}
				}
			}
		}
	}
	return true; 
}
int main(){
	string s;
	char choice;
	do{
		cin>>s;
		if(checkSeq(s)){
			cout << "Like!"<<endl;
		}
		else
			cout<<"DisLike!"<<endl;
		cout << "Continue?：";
		cin >> choice; 
		getchar();
	}while(choice=='y');
	return 0;
}
