#include <iostream>
#include <vector>
using namespace std;
// n :开始的列数
//m ：结束的列数
// mat：保存螺旋矩阵的数组
//num：要输入的数据 

void Spirtal_num(int n,int m,vector<vector<int> > &mat, int &num){
	if(n>m)
		return;
	if(n == m){
		mat[n][m]=num;
		return;
	}
	int i;
	for(i = n;i<=m;i++){
		mat[n][i] = num++;
	}
	for(i = n+1;i<=m;i++){
		mat[i][m] = num++;
	}
	for(i = m-1;i>=n;i--){
		mat[m][i] = num++;
	}
	for(i = m-1;i>=n+1;i--){
		mat[i][n] = num++;
	}
	Spirtal_num(n+1,m-1,mat,num);
}
int main(){
	int n,end,num = 1;
	cin>>n;
	cin>>end;
	vector<vector<int> > mat(n,vector<int>(n));
	Spirtal_num(0,n-1,mat,num);
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}
