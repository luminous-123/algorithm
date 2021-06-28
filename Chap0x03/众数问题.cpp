#include <iostream>
#include <vector>
using namespace std;

int mode = 0;
int duplicates = 0;
//通过遍历统计众数O(n),O(n) 
pair<int,int> Count(vector<int> num){
	int count[1024];
	for(int i = 0;i<num.size();i++){
		count[num[i]]++;
	}
	int max = 0,mode = 0;
	for(int i = 0;i<num.size();i++){
		if(count[num[i]]>max){
			max = count[num[i]];
			mode = num[i];
		}
	}
	return pair<int,int>(max,mode);
}
// 寻找中位数第一次出现的位置及其重数
pair<int,int> Count(vector<int> vec,int low,int high){
	int count = 1;
	int mid = (low+high+1)/2;
	int i = 1;
	while(mid+i<=high&&vec[mid+i]==vec[mid]){ //寻找中位数后面的数中与中位数相同的数字，重数+1 
		count++;
		i++;
	}
	i = 1;
	while(mid-i>=0&&vec[mid-i]==vec[mid]){
		count++;
		i++;
	}
	return pair<int,int>(count,mid-i+1);
} 
void find_mode(vector<int> vec,int low,int high){
	if(low>=high)
		return;
	int mid = (low+high+1)/2;
	pair<int,int> mid_info = Count(vec,low,high);
	int mid_count = mid_info.first;
	int mid_first = mid_info.second;
	
	if(mid_count >= duplicates){
		mode = vec[mid];
		duplicates = mid_count;
	} 
	if(high+1-(mid_first+mid_count)>duplicates){
		find_mode(vec,mid_first+mid_count,high);
	}
	if(mid_first+1>duplicates)
		find_mode(vec,low,mid_first);
}
int main()
{
    int a[7]={1,1,1,2,3,3};
    vector<int> nums(a,a+7);
    find_mode(nums,0,nums.size()-1);
    cout << "mode: "<<mode<<endl;
    cout << "duplicates: "<<duplicates<<endl; 
    //pair<int,int> res = Count(nums);
    //cout << "mode:" << res.second << endl;
    //cout << "duplicates:" << res.first << endl;

    return 0;
}
