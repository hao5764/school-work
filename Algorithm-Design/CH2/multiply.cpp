#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

/*
 *将在数组中保存的字符串转成数字存到int数组中
*/
void getdigits(int *a,char *s){
     int i;
     char digit;
     int len = strlen(s);

     //对数组初始化
     for(i = 0; i < N; ++i)
           *(a + i) = 0;
     for(i = 0; i < len; ++i){
           digit = *(s + i);
           //字符串s="12345",因此第一个字符应该存在int数组的最后一个位置
           *(a + len - 1 - i) = digit - '0';
     }
}

/*
 *将数组a与数组b逐位相乘以后存入数组c
 */
void multiply(int *a,int *b,int *c)
{
     int i,j;

     //数组初始化
     for(i = 0; i < 2 * N; ++i)
           *(c + i) = 0;
     /*
      *数组a中的每位逐位与数组b相乘，并把结果存入数组c
      *比如，12345*12345，a中的5与12345逐位相乘
      *对于数组c：*(c+i+j)在i=0,j=0,1,2,3,4时存的是5与各位相乘的结果
      *而在i=1,j=0,1,2,3,4时不光会存4与各位相乘的结果，
      *还会累加上上次相乘的结果.这一点是需要注意的!!!
     */
     for(i = 0; i < N; ++i)
           for(j = 0; j < N; ++j)
                 *(c + i + j) += *(a + i) * *(b + j);
     /*
      *这里是移位、进位
     */
     for(i = 0; i < 2 * N - 1; ++i){
           *(c + i + 1) += *(c + i)/10;//将十位上的数向前进位，并加上原来这个位上的数
           *(c + i) = *(c + i)%10;//将剩余的数存原来的位置上
     }
}

int main()
{
    int a[N],b[N],c[2*N];
    char s1[N],s2[N];
    int j = 2*N-1;
    int i;

    printf("input the first number:");
    scanf("%s",s1);
    printf("\ninput the second number:");
    scanf("%s",s2);

    getdigits(a,s1);
    getdigits(b,s2);

    multiply(a,b,c);

    while(c[j] == 0)
               j--;
    for(i = j;i >= 0; --i)
           printf("%d",c[i]);
    printf("\n");
    return 0;
}
