#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int m[maxn][maxn],s[maxn][maxn],w[maxn][maxn];
double a[maxn],b[maxn];
int main()
{
    int n;
    while(cin>>n){
        memset(a,0,sizeof(a));
        memset(m,0,sizeof(m));
        memset(s,0,sizeof(s));
        memset(w,0,sizeof(w));
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        for(int i=0;i<=n;i++) w[i+1][i]=a[i];
        for(int r=0;r<n;i++){
            for(int i=1;i<=n-r;i++){
                int j=i+r,i1=s[i][j-1]>i?s[i][j-1]:i,j1=s[i+1][j]>i?s[i+1][j]:j;
                w[i][j]=w[i][j-1]+a[j]+b[j];
                m[i][j]=m[i][i1-1]+m[i1+1][j];
                s[i][j]=i1;
                for(int k=i1+1;k<=j1;k++){
                    int t=m[i][k-1]+m[k+1][j];
                    if(t<=m[i][j]){m[i][j]=t;k[i][j]=k;}
                }
                m[i][j]+=w[i][j];
            }
        }
        cout<<w[n][n]<<endl;
    }
    return 0;
}
