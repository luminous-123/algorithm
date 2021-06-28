#include <iostream>
#include <cstdio> 
using namespace std;
/*
	需要尽可能多的把n分出来才可以使得乘积最大，当有1做因数的时候，乘积一定不会是最大的，所以舍去。也要使每个因子尽可能的靠近 
	令2+3+...+n直到和大于等于s
	1. sum-s = 1那么就把2去掉，然后把最大的数加一
	2. sum-s = k，就把k那个数去掉，然后k分配到其他数上 
*/
int main(){
	int a[1000];//拆分的数
	int n;
	cin>>n;
	int sum = 0,l = 0,surplus = 0,ans=1;
	for(int i =2;i<=n;i++){
		a[l++] = i; //存储2,3,...n 
		sum += i; // 计算sum = 2+3+...+n 
		if(sum == n){
			break;
		}
		if(sum>n){ //sum>n
			sum = sum-i;//减去余数 
			l--;//长度-1； 
			surplus = n-sum;//计算剩下还没有分配的数 
			break;
		}
	}
	for(int i = l-1;surplus;surplus--){
		a[i]++;//把剩余的数从大到小分配 
		i--;
		if(i<0)
			i = l-1; 
	}
	for(int i=0;i<l;i++){
		ans = ans * a[i];
		cout << a[i] << " ";
	} 
	cout << endl;
	cout << ans<<endl;
} 
