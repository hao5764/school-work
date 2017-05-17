//归并排序
#include<bits/stdc++.h>
using namespace std;
int a[10001],b[10001],c[10001];
void merge(int *a,int p,int q,int r)//  0 4 9
{
	int len1=q-p+1;
	int len2=r-q;
	int i=0,j=0;
	for( i=0;i<len1;i++)
		b[i]=a[p+i];
	for( j=0;j<len2;j++)
		c[j]=a[q+j+1];
	b[i]=c[j]=100000;
	i=j=0;

	for(int k=p;k<=r;k++)
	{
		if(b[i]<c[j])
		{
			a[k]=b[i];i++;
		}
		else
		{
			a[k]=c[j];j++;
		}
	}
}
void merge_sort(int *a,int p,int r)
{
	if(p<r)
	{
		int q=(p+r)/2;
		merge_sort(a,p,q);
		merge_sort(a,q+1,r);
		merge(a,p,q,r);
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
		cout<<endl;
}
