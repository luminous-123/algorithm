#include <iostream>
using namespace std;
void disp(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout << a[i] <<" ";
	}
	cout << endl;
} 
//一趟划分 
int Partition(int a[],int s,int t){
	int i=s,j=t,tmp;
	int temp=a[s];
	while(i!=j){
		while(j>i&&a[j]>=temp)	//从后往前找比tmp小的数 
			j--;
		while(i<j&&a[i]<=temp)	//从前往后找比tmp大的数 
			i++;
//		disp(a,10); 
		if(i<j){	//将找到的两个数的位置交换 
			tmp=a[i];
			a[i]=a[j];
			a[j]=tmp;
		}
//		disp(a,10); 
	}
	a[s] = a[i];
	a[i] = temp;
	return i;
}
void QuickSort(int a[],int left,int right){
	if(left < right){
		int i = Partition(a,left,right);
		QuickSort(a,left,i-1);//对左子序列进行划分 
		QuickSort(a,i+1,right);//对右字序列进行划分 
	}
} 

int main(){
	int n = 10;
	int a[] = {2,5,1,7,10,6,9,4,3,8};
	cout << "排序前：";
	disp(a,n);
	QuickSort(a,0,n-1);
	cout<<"排序后：";
	disp(a,n);
	return 0; 
} 
