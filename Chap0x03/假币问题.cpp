#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
//通过质量比较分辨假币在哪一部分
int sum(vector<int> vec,int low,int high){
	return accumulate(vec.begin()+low,vec.begin()+high+1,0);
} 
//对硬币进行堆划分
int binery(vector<int> coins,int low,int high){
	if(low==high)
		return low;
	else if(low == high -1)
		return coins[low] < coins[high]?low:high;
	int mid = (low + high +1)/2;//划分中间界限 
	if(mid %2==0)//递归形式，哪一堆更轻，就递归寻找更轻的那一堆 
		return sum(coins,low,mid) < sum(coins,mid+1,high) ? binery(coins,low,mid): binery(coins,mid+1,high); 
	else{
		if(sum(coins,low,mid-1)<sum(coins,mid+1,high))
			return binery(coins,low,mid-1);
		else if(sum(coins,low,mid-1)>sum(coins,mid+1,high))
			return binery(coins,mid+1,high);
		else
			return mid; 
	} 
} 
int main(){
	vector<int>coins;
	for(int i = 0 ;i<7;i++){
		coins.push_back(100);
	}
	coins[3]=98;
	cout << "Number " << binery(coins,0,coins.size()-1)+1<<" is fake!"<<endl; 
}
