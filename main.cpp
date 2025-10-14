#include <stdio.h>
#include <iostream>
#include <windows.h>

int Recursive(int kyuuryou, int zikan, int koteikyu)
{
    if (kyuuryou >= koteikyu)
    {
        printf("%d時間後に超える\n", zikan);
        return zikan;
    }

    printf("%d時給　%d固定給\n", kyuuryou, koteikyu);

    // 毎時間給料が2倍になる
    kyuuryou = kyuuryou * 2 - 50;

    // 固定給
    koteikyu += 1072;

    return Recursive(kyuuryou, zikan + 1, koteikyu);
}

int main()
{


    int saiki = 100;
    int ippan = 1226;
    int zikan = 0;
    int result1 = Recursive(saiki, zikan, ippan);

    printf("\n結果: %d時間後\n", result1);

    return 0;
}
