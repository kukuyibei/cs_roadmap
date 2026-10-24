#include <stdio.h>
int main(void){
    printf("100 - 999 之间的水仙花数：\n");
    for(int i = 100;i<=999;i++){
        int a = i/100; // 百位
        int b = (i/10) % 10; // 十位
        int c = i%10; // 个位
        if(a*a*a + b*b*b + c*c*c == i){
            printf("%d\t",i);
        }
    }
    printf("\n");
    return 0;
}