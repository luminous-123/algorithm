#include <iostream>
#include <vector>
using namespace std;

void to_Palindrome(vector<int> number,int &count){
	if(number.size()<=1)
		return;
	vector<int>::iterator first = number.begin();
	vector<int>::iterator last = number.end()-1;
	if(*first == *last){
		number.erase(first);
		number.erase(last);
		to_Palindrome(number,count);
	}
	else if(*first < *last){
		*(first+1) = *(first+1)+*first;
		number.erase(first);
		to_Palindrome(number,++count);
	}
	else{
		*(last-1) = *last + *(last-1);
		number.erase(last);
		to_Palindrome(number,++count);
	}
} 

int main(){
	int count = 0,number = 0,temp = 0;
	vector<int> list;
	cin>>number;
	while(number>0){
		cin>>temp;
		list.push_back(temp);
		number--;
	}
	to_Palindrome(list,count);
	cout << count << endl;
}
