#include <iostream>
using namespace std;
void disp(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		cout << a[i] <<" ";
	}
	cout << endl;
} 
//һ�˻��� 
int Partition(int a[],int s,int t){
	int i=s,j=t,tmp;
	int temp=a[s];
	while(i!=j){
		while(j>i&&a[j]>=temp)	//�Ӻ���ǰ�ұ�tmpС���� 
			j--;
		while(i<j&&a[i]<=temp)	//��ǰ�����ұ�tmp����� 
			i++;
//		disp(a,10); 
		if(i<j){	//���ҵ�����������λ�ý��� 
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
		QuickSort(a,left,i-1);//���������н��л��� 
		QuickSort(a,i+1,right);//���������н��л��� 
	}
} 

int main(){
	int n = 10;
	int a[] = {2,5,1,7,10,6,9,4,3,8};
	cout << "����ǰ��";
	disp(a,n);
	QuickSort(a,0,n-1);
	cout<<"�����";
	disp(a,n);
	return 0; 
} 
