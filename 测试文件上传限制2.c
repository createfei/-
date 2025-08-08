#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 生成[min, max]范围内的随机数
int generate_random_number(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(0)); // 初始化随机种子
    int score = 0;

    printf("欢迎参加50以内加减法测试！共10题，每题10分。\n");

    for (int i = 0; i < 10; i++) {
        int num1 = generate_random_number(1, 50);
        int num2 = generate_random_number(1, 50);
        char operator = (rand() % 2 == 0) ? '+' : '-'; // 随机选择加减法

        // 确保减法结果非负且总和不超过50
        if (operator == '-' && num1 < num2) {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        printf("第%d题: %d %c %d = ", i + 1, num1, operator, num2);
        int user_answer;
        scanf("%d", &user_answer);

        int correct_answer = (operator == '+') ? (num1 + num2) : (num1 - num2);
        if (user_answer == correct_answer) {
            printf("正确！\n");
            score += 10;
        } else {
            printf("错误！正确答案是：%d\n", correct_answer);
        }
    }

    printf("测试结束，你的得分是：%d/100\n", score);
    return 0;
}