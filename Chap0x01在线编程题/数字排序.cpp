#include<iostream>
#include<vector>
#include<map> 
#include<algorithm>
using namespace std;

bool cmp_by_value(const pair<int,int>& lhs, const pair<int,int>& rhs) {
  return lhs.second > rhs.second;
}

vector<pair<int,int> > sort_number(vector<int> numbers){
	map<int,int> number;
	for(int i = 0;i<numbers.size();i++){
		number[numbers[i]]++;
	}
	vector<pair<int,int> > count;
	map<int,int>::iterator it;
	for(it=number.begin();it!=number.end();it++){
		count.push_back(pair<int,int>(it->first,it->second));
	}
	std::sort(count.begin(),count.end(),cmp_by_value);
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> numbers;
	for(int i = 0;i<n;i++){
		int number;
		cin>>number;
		numbers.push_back(number);
	} 
	vector<pair<int,int> > result = sort_number(numbers);
	vector<pair<int,int> >::iterator it;
	for(it=result.begin();it!=result.end();it++){
		cout << it->first << " "<< it->second<<endl;
	}
}
