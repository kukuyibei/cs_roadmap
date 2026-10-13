#include <stdio.h>
#include <limits.h> // 整数范围宏
#include <float.h>  // 浮点精度宏

#define PRINT_SIZE(type) \
    printf("%-20s %2zu 字节\n",#type,sizeof(type))

int main(void)
{
    printf("========== 各类型字节数 ==========\n");
    PRINT_SIZE(char);
    PRINT_SIZE(unsigned char);
    PRINT_SIZE(short);
    PRINT_SIZE(unsigned short);
    PRINT_SIZE(int);
    PRINT_SIZE(unsigned int);
    PRINT_SIZE(long);
    PRINT_SIZE(unsigned long);
    PRINT_SIZE(long long);
    PRINT_SIZE(float);
    PRINT_SIZE(double);
    PRINT_SIZE(long double);
    PRINT_SIZE(int *);
    PRINT_SIZE(void *);
    printf("\n========== 整数取值范围 ==========\n");
    printf("char:            %d ~ %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char:   0 ~ %u\n", UCHAR_MAX);
    printf("short:           %d ~ %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short:  0 ~ %u\n", USHRT_MAX);
    printf("int:             %d ~ %d\n", INT_MIN, INT_MAX);
    printf("unsigned int:    0 ~ %u\n", UINT_MAX);
    printf("long:            %ld ~ %ld\n", LONG_MIN, LONG_MAX);
    printf("long long:       %lld ~ %lld\n", LLONG_MIN, LLONG_MAX);

    printf("\n========== 浮点精度 ==========\n");
    printf("float 有效位数:  %d\n", FLT_DIG);
    printf("double 有效位数: %d\n", DBL_DIG);
    printf("float 最大值:    %e\n", FLT_MAX);
    printf("double 最大值:   %e\n", DBL_MAX);
    int max = INT_MAX;
    printf("INT_MAX = %d\n",max);
    printf("INT_MAX + 1 = %d\n",max+1);
    unsigned int zero = 0;
    printf("0 - 1 = %u\n", zero - 1);
    return 0;
}
