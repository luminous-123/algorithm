/*
�㷨˼·���Ծ����в�ͬ���н���ɨ�裬��ɨ�����ͬһ����ӣ�ת��Ϊ�����У����ö�̬�滮��b[i]=max{b[i-1]+a[i],a[i]}���ҵ�ɨ�������������������� 
*/
#include <iostream>
#include <cstring>
using namespace std;
int MaxSum(int n,int *a){//��ÿһ���Ӷκ͵����ֵ 
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
		for(int k =0;k<n;k++) //��ʼ�� 
			b[k]=0;
		for(int j=i;j<m;j++){ //����ɨ��1,12,123,1234,2,23,234,3,34,4 
			for(int k=0;k<n;k++){
				b[k]+=a[j][k];//��ÿһ�е��ܺ� 
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
	cout<<"����"<<m<<"��"<<n<<"�о�������"<<endl;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++)
		{
		 	cin>>a[i][j];
		 }
	}
 
	 cout<<endl<<endl<<"�������Ӿ���ͣ�"<<MaxSum2(m,n,a);
	return 0;
}

