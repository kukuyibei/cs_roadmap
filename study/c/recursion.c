#include <stdio.h>

// 阶乘
long long factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;                // 终止条件
    return n * factorial(n - 1); // 最小规模
}
int fib_iter(int n)
{
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
void hanoi(int n,char from,char aux,char to){
    if (n == 1 )
    { // 只有一个盘子直接移
        printf("盘子1：%c -> %c\n",from,to);
        return;
    }
    // 1.把上面n-1个盘子从from移动到aux（借助to）
    hanoi(n-1,from,to,aux);
    // 2.把最大的盘子从from移动到to
    printf("盘子%d:%c -> %c\n",n,from,to);
    // 3.把aux上的n-1个盘子移动到to(借助from)
    hanoi(n-1,aux,from,to);
}
int fib_rec(int n) {
    if (n <= 1) return n;
    return fib_rec(n - 1) + fib_rec(n - 2);
}
// 算 fib(40) 大概要跑几秒钟，算 fib(50) 要跑几十分钟
int memo[100] = {0}; // 全局数组记录算过的值
int fib_memo(int n) {
    if (n <= 1) return n;
    if (memo[n] != 0) return memo[n]; // 算过直接取
    memo[n] = fib_memo(n - 1) + fib_memo(n - 2);
    return memo[n];
}
int main(void) {
    printf("5! = %lld\n", factorial(5));
    printf("fib_iter(10) = %d\n", fib_iter(10));
    printf("fib_memo(40) = %d\n", fib_memo(40)); // 瞬间出结果
    printf("汉诺塔 3 层:\n");
    hanoi(3, 'A', 'B', 'C');
    return 0;
}
