/* abcde五人打渔，打完睡觉，a先醒来，扔掉1条鱼，把剩下的分成5分，拿一份走了；
 * b再醒来，也扔掉1条，把剩下的分成5份，拿一份走了；然后cde都按上面的方法取鱼。
 * 问他们一共打了多少条鱼，写程序和算法
 *
 * 共打了多少条鱼的结果有很多。但求最少打的鱼的结果是3121条鱼
 */
#include <stdio.h>

#define MAXNUM 10000
#define PERSON 5
int main(void) {
    int fish[PERSON+1];
    int i, j, k;

    for (i = 1; i < MAXNUM; i++) {
        fish[0] = i;
        for (j = 1; j <= PERSON+1; j++) {
            if ((fish[j-1]-1) % PERSON == 0) {
                fish[j] = fish[j-1] - 1 - (fish[j-1]-1)/PERSON;
            }
            else {
                break;
            }
        }
        if (j == PERSON+1) {
            for (k = 0; k <= PERSON; k++) {
                printf("%d  ", fish[k]);
            }
            printf("\n");
        }
    }
}
