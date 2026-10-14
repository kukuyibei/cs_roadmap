#include <stdio.h>
#include <limits.h>

int main(void) {
    printf("========== 1. 整数溢出 ==========\n");
    int max = INT_MAX;
    printf("INT_MAX      = %d\n", max);
    printf("INT_MAX + 1  = %d  (回绕到最小值)\n", max + 1);

    int min = INT_MIN;
    printf("INT_MIN      = %d\n", min);
    printf("INT_MIN - 1  = %d  (回绕到最大值)\n", min - 1);

    printf("\n========== 2. unsigned 回绕 ==========\n");
    unsigned int u = 0;
    printf("0u - 1       = %u\n", u - 1);

    printf("\n========== 3. signed / unsigned 比较 ==========\n");
    int a = -1;
    unsigned int b = 1;
    if (a < b)  printf("-1 < 1u 成立\n");
    else        printf("-1 < 1u 不成立！(因为 -1 被转成 %u)\n", (unsigned)a);

    printf("\n========== 4. 截断 ==========\n");
    int big = 300;
    char c = (char)big;
    printf("(char)300    = %d  (300 - 256 = 44)\n", c);

    int neg = -1;
    unsigned char uc = (unsigned char)neg;
    printf("(uchar)-1    = %u  (补码回绕)\n", uc);

    printf("\n========== 5. 负数取模 ==========\n");
    printf(" 7 %%  3 = %d\n",  7 %  3);
    printf("-7 %%  3 = %d  (C 里向零取整)\n", -7 %  3);
    printf(" 7 %% -3 = %d\n",  7 % -3);
    printf("-7 %% -3 = %d\n", -7 % -3);

    printf("\n========== 6. 整除截断 ==========\n");
    printf("5 / 2        = %d\n", 5 / 2);
    printf("(double)5/2  = %f\n", (double)5 / 2);
    printf("5.0 / 2      = %f\n", 5.0 / 2);
    printf("-5 / 2       = %d  (向零截断，不是 -3)\n", -5 / 2);

    printf("\n========== 7. 浮点精度 ==========\n");
    float f = 0.1f;
    if (f == 0.1f) printf("0.1f == 0.1f 成立\n");
    else           printf("0.1f == 0.1f 不成立\n");   // 大概率会输出这句

    double d = 0.1 + 0.2;
    printf("0.1 + 0.2    = %.20f\n", d);
    printf("0.1 + 0.2 == 0.3 ? %d\n", d == 0.3);     // 0，不相等

    printf("\n========== 8. ++i vs i++ ==========\n");
    int i = 5;
    printf("i = 5\n");
    printf("i++ 表达式值 = %d, i 变成 %d\n", i++, i);
    i = 5;
    printf("++i 表达式值 = %d, i 变成 %d\n", ++i, i);

    return 0;
}