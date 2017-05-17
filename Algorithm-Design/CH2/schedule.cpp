#include<bits/stdc++.h>
using namespace std;
int G[100][100];
int n;
void merge(int i,int j,int n)
{
	if(n==2)
	{
		G[i][n]=j;
		G[j][n]=i;
		G[i][n-1]=i;
		G[j][n-1]=j;
	}
	else
	{
		merge(i,j/2,n/2);
		merge(j/2+1,j,n/2);
		for(int m=i;m<=j/2;m++)
			for(int k=j/2+1;k<=j;k++)
				G[m][k]=G[m+n/2][k-n/2];
		for(int m=j/2+1;m<=j;m++)
			for(int k=j/2+1;k<=j;k++)
				G[m][k]=G[m-n/2][k-n/2];
	}
}

void show()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<G[i][j]<<" ";
			cout<<endl;
	}

}

int main()
{
	memset(G,0,sizeof(G));
	cin>>n;
	merge(1,n,n);
	show();
}
