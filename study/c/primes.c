#include <stdio.h>
#include <stdbool.h>

// 判断是否为素数
bool is_prime(int n){
    if (n<=1) return false;
    for (int i = 2; i*i <= n;i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}
int main(void){
    printf("100以内的素数：\n");
    int count = 0;
    for (int i = 2;i <= 100;i++){
        if (is_prime(i)){
            printf("%3d",i);
            count++;
            if (count%5 == 0) printf("\n");
        }
    }
    printf("\n");
    return 0;
}