#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

void longest_palindrome(char *str)
{
    int dp[100][100] = {FALSE};
    int len = strlen(str);
    int i, j;
    int start = 0, longest = 1;

    for (i = 0; i < len; i++) {
        dp[i][i] = TRUE;
    }

    for (i = 0; i < len-1; i++) {
        if (str[i] == str[i+1]) {
            dp[i][i+1] = TRUE;
            start = i;
            longest = 2;
        }
    }

    for (j = 2; j < len; j++) {
        for (i = 0; i < len-j; i++) {
            if (str[i] == str[i+j] && dp[i+1][i+j-1]) {
                dp[i][i+j] = TRUE;
                if (longest < j+1) {
                    start = i;
                    longest = j+1;
                }
            }
        }
    }

    printf("\n\n");
    for (i = len-1; i >= 0; i--) {
        printf("dp[%2d]: ", i);
        for (j = 0; j < len; j++) {
            printf("%3d", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nThe longest palindrom sub-string is from index %d, with length %d: ", start, 
longest);
    for (i = 0; i < longest; i++) {
        printf("%c", str[start+i]);
    }
}

int main()
{
    char str[100];

    while (1) {
        printf("\nPlease input the string: ");
        scanf("%s", str);
        longest_palindrome(str);
    }
}

