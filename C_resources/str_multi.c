#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <malloc.h>

char* multi_str(char* str1, char* str2)
{
    char *a, *b, *tmp, *result, ch;
    int len_a, len_b, len_result;
    int i, j, k;
    int num_a, num_b, num_c, num_r;

    len_a = strlen(str1);
    len_b = strlen(str2);

    a = (char*)malloc(sizeof(char)*(len_a + 1));
    b = (char*)malloc(sizeof(char)*(len_b + 1));
    tmp = (char*)malloc(sizeof(char)*(len_a + 2));
    result = (char*)malloc(sizeof(char)*(len_a + len_b + 1));
    memset(result, 0, len_a + len_b + 1);

    /* reverse str1[] to a[] */
    for (i = 0; i < len_a; i++) {
        a[i] = str1[len_a-i-1];
    }
    /* reverse str2[] to b[] */
    for (i = 0; i < len_b; i++) {
        b[i] = str2[len_b-i-1];
    }

    for (j = 0; j < len_b; j++) {
        num_b = b[j] - '0';
        num_c = 0;
        for (i = 0; i < len_a; i++) {
            num_a = a[i] - '0';
            num_r = num_b * num_a + num_c;
            num_c = num_r / 10;
            num_r = num_r % 10;
            tmp[i] = num_r + '0';
        }
        if (num_c > 0) {
            tmp[i++] = num_c + '0';
            tmp[i] = '\0';
        }
        else {
            tmp[i] = '\0';
        }

        num_c = 0;
        for (k = 0; tmp[k]; k++) {
            if (result[k+j] >= '0') {
                num_r = (tmp[k]-'0') + (result[k+j]-'0') + num_c;
            }
            else {
                num_r = (tmp[k]-'0') + num_c;
            }
            num_c = num_r / 10;
            num_r = num_r % 10;
            result[k+j] = num_r + '0';
        }
        if (num_c > 0) {
            result[k+j] = num_c + '0';
            result[k+j+1] = '\0';
        }
        else {
            result[k+j] = '\0';
        }
    }

    len_result = strlen(result);
    for (k = 0; k < len_result/2; k++) {
        ch = result[k];
        result[k] = result[len_result-k-1];
        result[len_result-k-1] = ch;
    }

    free(a);
    free(b);
    free(tmp);
    return result;
}

int main()
{
    char a[100], b[100];
    char* result;

    while (1) {
        printf("\nPlease input 2 strings: ");
        scanf("%s %s", a, b);
        result = multi_str(a, b);
        printf(" %s * %s = %s\n", a, b, result);
        free(result);
    }
}

