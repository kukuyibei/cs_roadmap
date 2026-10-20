#include <stdio.h>
int main(void){
    int score;
    printf("请输入成绩（0-100）：");
    scanf("%d",&score);

    // 1.范围判断用if-else
    if(score < 0 || score > 100){
        printf("成绩输入无效!\n");
    } else if(score >= 90){
        printf("等级：A\n");
    } else if(score >= 80){
        printf("等级：B\n");
    } else if(score >= 60){
        printf("等级：C\n");
    } else {
        printf("等级：D\n");
    }

    // 2.等值判断用switch（巧妙利用整除和穿透）
    printf("Switch 判定：");
    switch(score / 10){
        case 10:
        case 9:
        printf("A\n");break;
        case 8:
        printf("B\n");break;
        case 6:
        case 7:
        printf("C\n");break;
        default:
        printf("D\n");break;
    }

    // 3.闰年判断
    int year;
    printf("\n请输入年份：");
    scanf("%d",&year);

    // 逻辑能被4整除且不能被100整除，或者能被400整除
    if((year % 4 == 0 && year % 100 != 0)|| (year % 400 == 0)){
        printf("%d 是闰年\n",year);
    } else{
        printf("%d 不是闰年\n",year);
    }

    // 4.三目运算符判断奇偶
    printf("%d 是 %s\n",year,(year % 2 == 0) ? "偶数" : "奇数");
    return 0;
}