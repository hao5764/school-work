//最后存在dp[n-1][n]的位置 
#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn];
int dp[maxn][maxn];
int main()
{
    int n;
    while(cin>>n){
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            cin>>a[i];
        for(int l=2;l<=n;l++){
            for(int i=1;i<=n-l+1;i++){
                int j= i+l-1;
                dp[i][j]=dp[i+1][j]+a[i-1]*a[i]*a[j];
                for(int k=i+1;k<j;k++){
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]);
                }
            }
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<dp[n-1][n]<<endl;
    }
    return 0;
}
/*
6
30 35 15 5 10 20 25
*/
