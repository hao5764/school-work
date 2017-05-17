#include <iostream>
#include <cstdio>
using namespace std;
void hanoi(int n,int a,int b,int c)//把n个盘子 从第一个位置上（a位置）移动到第二个位置上(B位置) 借助第三个位置（C位置）
{
    if(n>0){
        hanoi(n-1,a,c,b);
        printf("把 %c 柱子上的盘子 移动到  %c柱子上\n",'a'+a-1,'a'+b-1);
        hanoi(n-1,c,b,a);
    }
}
int main()
{
    hanoi(3,1,2,3);
    return 0;
}
