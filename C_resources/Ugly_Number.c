// 们把只包含因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做是第一个丑数。
// 求按从小到大的顺序的第1500个丑数。

#include <vector>
#include <stdio.h>
using namespace std;

int findUgly(int idx) {
    if (idx == 1) return 1;
    vector<int> ugly(idx, 1);
    int i;
    int m2idx, m3idx, m5idx;

    m2idx = m3idx = m5idx = 0;
    for (i = 1; i < idx; i++) {
        ugly[i] = min(min(ugly[m2idx]*2, ugly[m3idx]*3), ugly[m5idx]*5);
        printf("ugly[%03d] = %4d (%2d, %2d, %2d)\n",
               i, ugly[i], m2idx, m3idx, m5idx);
        while (ugly[m2idx] * 2 <= ugly[i]) m2idx++;
        while (ugly[m3idx] * 3 <= ugly[i]) m3idx++;
        while (ugly[m5idx] * 5 <= ugly[i]) m5idx++;
    }

    return ugly[idx-1];
}

int main(void) {
    findUgly(100);
    return 0;
}

