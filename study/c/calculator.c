#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// 辅助函数：获取运算符优先级
int get_priority(char op){
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // '(' 优先级最低
}

// 辅助函数：执行一次计算
void apply_op(double *nums,int *num_top,char *ops, int *op_top){
    if(*num_top < 1||*op_top < 0){
        printf("表达式错误！\n");
        exit(1);
    }
    double b = nums[(*num_top)--]; // 右操作数
    double a = nums[(*num_top)--]; // 左操作数
    char op = ops[(*op_top)--]; // 运算符

    double res = 0;
    switch (op){
        case '+': res = a+b; break;
        case '-': res = a-b; break;
        case '*': res = a*b; break;
        case '/':
            if(b==0){
                printf("error: 除数不能为0！\n");
                exit(1);
            }
            res = a/b;
            break;
    }
    nums[++(*num_top)] = res; // 结果压回数字栈
}
int main(void){
    char expr[MAX];
    printf("请输入表达式（支持+ - * / 和括号）：\n");
    fgets(expr,MAX,stdin); // 读取整行

    double nums[MAX]; // 数字栈
    int num_top = -1;
    char ops[MAX]; // 符号栈
    int op_top = -1;
    int i = 0;
    while (expr[i] != '\0' && expr[i] != '\n')
    {
        if(isspace(expr[i])){ // 跳过空格
            i++;
            continue;
        }
        // 1. 处理数字（支持多位数和小数）
        if (isdigit(expr[i]) || expr[i] == '.') {
            double val = 0;
            // 处理整数部分
            while (isdigit(expr[i])) {
                val = val * 10 + (expr[i] - '0');
                i++;
            }
            // 处理小数部分（为了简单，v1 暂只处理整数部分也可以，这里扩展了一点）
            if (expr[i] == '.') {
                i++;
                double factor = 0.1;
                while (isdigit(expr[i])) {
                    val += (expr[i] - '0') * factor;
                    factor *= 0.1;
                    i++;
                }
            }
            nums[++num_top] = val; // 压入数字栈
            continue; // 注意这里 continue，i 已经指向下一个字符了
        }
        // 2.处理左括号
        if(expr[i] == '('){
            ops[++op_top] = expr[i];
            i++;
        }
        // 3.处理右括号
        else if (expr[i]  == ')'){
            while(op_top >= 0 && ops[op_top]!='('){
                apply_op(nums,&num_top,ops,&op_top);
            }
            if (op_top >= 0 && ops[op_top] == '('){
                op_top--; // 弹出 '('
            } else{
                printf("错误：括号不匹配！\n");
                return 1;
            }
            i++;
        }
        // 4.处理运算符 + - * /
        else{
            while (op_top >= 0 && get_priority(ops[op_top]) >= get_priority(expr[i])){
                apply_op(nums,&num_top,ops,&op_top);
            }
            ops[++op_top] = expr[i];
            i++;
        }
    }
    // 5.处理剩下的运算符
    while(op_top>=0){
        if(ops[op_top] == '('){
            printf("错误括号不匹配！\n");
            return 1;
        }
        apply_op(nums,&num_top,ops,&op_top);
    }
    // 6.输出最终结果
    if(num_top == 0){
        printf("结果：%g\n",nums[0]); // %g会自动去掉末尾0
    } else{
        printf("表达式错误!\n");
    }
    return 0;
}
