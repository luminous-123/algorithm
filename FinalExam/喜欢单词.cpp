#include <iostream>
#include <string>
#include <vector> 
using namespace std;
/*��ϲ������� 
1. ��Сд��ĸ
2. ��������ͬ����ĸ
3. ����ͬ�������� (���Բ�����)
*/ 
//������ 
bool checkSeq(string s){
	int i = 0,j = 0,x = 0;
	for(i = 0;i<s.length();i++){
		if(s[i]<'A'||s[i]>'Z'){//�жϴ�д��ĸ 
			return false;
		}
		if(i<s.length()-1){
			if(s[i]==s[i+1]){ //�ж�������ĸ 
				return false;
			}
		}
	}
	for(i = 0;i<s.length()-1;i++){//Ѱ���Ƿ�����ͬ�������� 
		for(j = i+1;j<s.length();j++){
			if(s[i]==s[j]){//�е�һ����ĸ��ͬ 
				for(int k = i+1;k<j;k++){//Ȼ���ж�i֮�����ĸ��û����j֮����ͬ�� 
					for(x = j+1;x<s.length();x++){ //���������ж��Ƿ��в���������ͬ������ 
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
		cout << "Continue?��";
		cin >> choice; 
		getchar();
	}while(choice=='y');
	return 0;
}
