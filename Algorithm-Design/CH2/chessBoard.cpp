#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int tile;//骨牌型号
int Board[maxn][maxn];
void chessBoard(int tr,int tc,int dr,int dc,int sz)//（tr tc） 棋盘左上角坐标  （dr dc）特殊格子的坐标  sz：棋盘大小
{
    if(sz==1) return ;
    int t=tile++;
    int s=sz/2;
    //覆盖左上角的
    if(dr<tr+s && dc<tc+s){//特殊方格在这个棋盘
        chessBoard(tr,tc,dr,dc,s);
    }
    else{//此区域没有特殊方格
        Board[tr+s-1][tc+s-1]=t;
        chessBoard(tr,tc,tr+s-1,tc+s-1,s);
    }
    //覆盖右上角
    if(dr<tr+s && dc>=tc+s){//特殊方格在这个棋盘
        chessBoard(tr,tc+s,dr,dc,s);
    }
    else{//此区域没有特殊方格
        Board[tr+s-1][tc+s]=t;
        chessBoard(tr,tc+s,tr+s-1,tc+s,s);
    }
    //覆盖左下角
    if(dr>=tr+s && dc<tc+s){//特殊方格在这个棋盘
        chessBoard(tr+s,tc,dr,dc,s);
    }
    else{//此区域没有特殊方格
        Board[tr+s][tc+s-1]=t;
        chessBoard(tr+s,tc,tr+s,tc+s-1,s);
    }
    //覆盖右下角
    if(dr>=tr+s && dc>=tc+s){//特殊方格在这个棋盘
        chessBoard(tr+s,tc+s,dr,dc,s);
    }
    else{//此区域没有特殊方格
        Board[tr+s][tc+s]=t;
        chessBoard(tr+s,tc+s,tr+s,tc+s,s);
    }
}
int main()
{
    int sz;
    while(cin>>sz){
        tile=1;
        memset(Board,0,sizeof(Board));
        chessBoard(0,0,1,1,sz);
        for(int i=0;i<sz;i++){
            for(int j=0;j<sz;j++)
                cout<<Board[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
