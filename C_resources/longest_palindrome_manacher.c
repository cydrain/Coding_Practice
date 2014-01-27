#include<stdio.h>
#include<string.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

const int N = 100;

void Manacher(char *str,int *p)
{
    int i, j;
    int len = strlen(str);
    int id, mx;

    for (j = 0; j < len; j++) {
        p[j] = 0;
    }

    id = 1;
    mx = 1;
    p[0] = p[1] = 1;

    for (i = 2; i < len; i++) {
        p[i] = 1;
        if (mx > i) {
            p[i] = Min(p[id*2-i], mx-i);
        }

        printf("\np(i=%2d): ", i);
        for (j = 0; j < len; j++) {
            printf(" %d ", p[j]);
        }

        while (str[i+p[i]] == str[i-p[i]])
            p[i]++;

        if (i+p[i] > mx) {
            id = i;
            mx = i + p[i];
        }

        printf("\np(i=%2d): ", i);
        for (j = 0; j < len; j++) {
            printf(" %d ", p[j]);
        }
        printf("  (id = %d, mx = %d)\n", id, mx);
    }
}

void extend_str(char *src, char *des)
{
    int i;
    int len = strlen(src);

    des[0]='$';
    des[1]='#';
    for (i = 0; i < len; i++){
        des[i*2+2] = src[i];
        des[i*2+3] = '#';
    }
    des[i*2+2] = '\0';

    len = strlen(des);
    printf("\n  str  : ");
    for (i = 0; i < len; i++) {
        printf(" %c ", des[i]);
    }
}

int main()
{
    char str[N*2], s[N];
    int p[N*2];
    int i, j;
    int ans, ca = 1;
    int len;

    while (~scanf("%s",s)) {
        len = strlen(s);
        if (len == 3 && s[0]=='E' && s[1]=='N' && s[2]=='D')
            break;

        extend_str(s, str);
        Manacher(str,p);

        ans=1;
        len = strlen(str);
        for (i = 2; i < len; i++) {
            ans = Max(ans, p[i]-1);
        }

        printf("\nCase %d: %d\n", ca++, ans);
#if 0
        printf("str: ");
        for (i = 0; i < len; i++) {
            printf(" %c ", str[i]);
        }
        printf("\n p : ");
        for (i = 0; i < len; i++) {
            printf(" %d ", p[i]);
        }
        printf("\n\n");
#endif
    }
    
    return 0;
}

