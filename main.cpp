#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// コールバック関数のプロトタイプ宣言
typedef void (*Callback)(int result);

// サイコロの出目を決定する関数
int roll_dice() {
    return (rand() % 6) + 1; // ランダム関数で1～6のどれかを返す
}

// 判定を行うコールバック関数
void judge_result(int result) {

    int input;

    printf("サイコロの出目が奇数(1)か偶数(2)か入力:");
    scanf_s("%d", &input);

    printf("判定中...\n");

    Sleep(3000);

    if ((result % 2 == 1 && input == 1) || (result % 2 == 0 && input == 2)) {
        printf("正解\n");
    } else {
        printf("不正解\n");
    }

    printf("サイコロの目は%d\n", result);
}

// メイン関数
int main() {

    srand((int)time(NULL));

    int dice_result = roll_dice();

    Callback callback = judge_result; // 実行したい関数のアドレス（関数名がアドレスを表す）

    callback(dice_result); // サイコロの値を引数にして関数ポインタから関数を実行

    return 0;
}