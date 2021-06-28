#include <iostream>
#include <vector>
using namespace std;

int ans;

void Merge(vector<int>&vec,int low,int mid,int high){
	int i = low;
	int j = mid+1;
	int k = 0;
	vector<int> tmp;
	while(i<=mid&&j<=high){
		if(vec[i]>vec[j]){
			tmp.push_back(vec[j++]);
			ans += mid - i + 1;//如果i<mid还大于vec[j]，就说明在i后面到mid的数均大于vec[j]，都是逆序对 
		} 
		else
			tmp.push_back(vec[i++]);
	}
	while(i<=mid)
		tmp.push_back(vec[i++]);
	while(j<=high)
		tmp.push_back(vec[j++]);
	for(int m = 0 ;m<tmp.size();m++){
		vec[low+m] = tmp[m];
	}
}
void Merge_sort(vector<int> &vec, int low, int high) //递归二路归并排序
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge_sort(vec, low, mid);
        Merge_sort(vec, mid + 1, high);
        Merge(vec, low, mid, high);
    }
}
int Inversion(vector<int> vec, int n) //二路归并法求逆序数
{
    ans = 0;
    Merge_sort(vec, 0, n - 1);
    return ans;
}
int main()
{
	int a[5] = {3,1,4,5,2};
    vector<int> nums(a,a+5);
    cout << Inversion(nums, nums.size()) << endl;
}
