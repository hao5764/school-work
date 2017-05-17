#include<bits/stdc++.h>
using namespace std;
int a[10001];
int Partition(int *a,int p,int r)
{
	int x=a[r];//把最后一个坐标作为这一部分的比较中心 称标准元素吧
	int i=p-1;//开始位置指针指向数组第一个元素的前面
	int j;
	for(j=p;j<r;j++)
	{
		if(a[j]<x)//如果当前位置的元素比 标准元素小 把它放在整个数组的左边
		{
			i++;
			swap(a[j],a[i]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;  //最后的结果i+1的左边都比i+1小 右边都比i+1大
}
void quickSort(int *a,int p,int r)//三个参数 排序的数组，第一个元素的位置，最后一个元素的位置
{
	if(p<r)
	{
		int q=Partition(a,p,r);//找到一个划分点 对这个划分点的左边和右边进行快速排序
		quickSort(a,p,q-1);
		quickSort(a,q+1,r);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	quickSort(a,0,n-1);
    for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
    cout<<endl;
}
