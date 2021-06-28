/*
算法思路：对矩阵中不同的行进行扫描，将扫描的行同一列相加，转化为子序列，利用动态规划（b[i]=max{b[i-1]+a[i],a[i]}）找到扫描行子序列相加最大的情况 
*/
#include <iostream>
#include <cstring>
using namespace std;
int MaxSum(int n,int *a){//找每一个子段和的最大值 
	int sum=0,b=0;
	for(int i = 0;i<n;i++){
		if(b>0)
			b+=a[i];
		else
			b=a[i];
		if(b>sum)
			sum=b; 
	}
	return sum;
} 
int MaxSum2(int m,int n,int **a){
	int sum=0;
	int *b=new int[n+1];
	for(int i=0;i<m;i++){
		for(int k =0;k<n;k++) //初始化 
			b[k]=0;
		for(int j=i;j<m;j++){ //依次扫描1,12,123,1234,2,23,234,3,34,4 
			for(int k=0;k<n;k++){
				b[k]+=a[j][k];//求每一行的总和 
//				cout <<b[k]<<endl; 
				int Max = MaxSum(n,b); 
				if(Max>sum)
					sum=Max;
			}
		}
	}
	return sum;
} 
int main()
{
 
	int m=4,n=4;
	int **a = new int *[m];
	for(int i=0;i<m;i++){
		a[i] = new int[n];
	}
	cout<<"输入"<<m<<"行"<<n<<"列矩阵如下"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		{
		 	cin>>a[i][j];
		 }
	}
 
	 cout<<endl<<endl<<"输出最大子矩阵和："<<MaxSum2(m,n,a);
	return 0;
}

