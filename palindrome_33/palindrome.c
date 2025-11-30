#include <stdio.h>
#include <stdbool.h>  // 使用bool类型（C99及以上支持）

/**
 * @brief 判断一个整数是否为回文数
 * @param x 待判断的整数
 * @return bool 是回文数返回true，否则返回false
 * @note 回文数定义：正读和反读完全相同的整数（负数因负号排除，0是回文数）
 */
bool isPalindrome(int x) {
    // 边界条件1：负数不是回文数（包含负号）
    if (x < 0) {
        return false;
    }
    // 边界条件2：0是回文数
    if (x == 0) {
        return true;
    }
    // 边界条件3：非0但末尾为0的数不是回文数（反转后首位为0，与原数不等）
    if (x % 10 == 0) {
        return false;
    }

    int reversed_half = 0;  // 存储反转的后半部分数字
    // 反转后半部分数字，直到原数小于等于反转后的数（说明已经处理了一半）
    while (x > reversed_half) {
        reversed_half = reversed_half * 10 + x % 10;  // 取最后一位拼接到反转数
        x /= 10;  // 去掉最后一位
    }

    // 两种情况：
    // 1. 数字位数为偶数（如1221）：x == reversed_half
    // 2. 数字位数为奇数（如12321）：x == reversed_half / 10（去掉中间位）
    return (x == reversed_half) || (x == reversed_half / 10);
}

int main() {
    int num;
    printf("===== 回文数判断程序 =====\n");
    printf("请输入一个整数：");
    // 输入合法性检查
    if (scanf("%d", &num) != 1) {
        printf("错误：输入的不是有效整数！\n");
        return 1;
    }

    // 调用判断函数并输出结果
    if (isPalindrome(num)) {
        printf("%d 是回文数\n", num);
    } else {
        printf("%d 不是回文数\n", num);
    }

    return 0;
}