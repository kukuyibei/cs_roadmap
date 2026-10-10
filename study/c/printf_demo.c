#include <stdio.h>
int main(void)
{
    // 1 整数
    int a = 42;
    unsigned int u = 3000000000u;
    long l = 1234567899L;
    long long ll = 1234567890123456789LL;

    printf("int:        %d\n",a);
    printf("unsigned:        %u\n",u);
    printf("long:        %ld\n",l);
    printf("long long:        %lld\n",ll);

    // 2 浮点
    float f = 3.14159f;
    double d = 2.718281828459045;
    printf("float:        %f\n",f);
    printf("double:        %lf\n",d);
    printf("科学计数:        %e\n",d);

    // 3 字符和字符串
    char c = 'A';
    char *s= "hello";

    printf("char:        %c\n",c);
    printf("string:        %s\n",s);

    // 4 进制
    int x = 255;
    printf("十进制:        %d\n",x);
    printf("八进制:        %o\n",x);
    printf("十六进制:        %x\n",x);
    printf("带前缀十六进制:        %#x\n",x);

    // 5 指针
    int *p = &x;
    printf("指针地址:        %p\n",(void *)p);

    // 6 宽度 / 精度 / 对齐
    printf("默认:        [%d]\n",42);
    printf("宽度8:        [%8d]\n",42);
    printf("左对其:        [%-8d]\n",42);
    printf("补零:        [%08d]\n",42);
    printf("保留两位小数:        [%.2f]\n",d);

    // 7 百分号本身
    printf("百分比：         100%%\n");
    return 0;
}
