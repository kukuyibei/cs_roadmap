#include <stdio.h>
int main(void)
{
    for (int i = 1; i<=9; i++)
    {
        for(int j=1;j<=i;j++){
            // %-2d 表示左对齐，占2个字符宽度
            printf("%d*%d=%-2d",j,i,i*j);
        }
        printf("\n");
    }
    
    return 0;
}
