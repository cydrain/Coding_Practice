#include <stdio.h>

/* method 1: common method */
int BitCount_0(unsigned int n)
{
    int count;

    for (count = 0; n; n >>= 1) {
        count += n & 0x1;
    }

    return count;
}

/* method 2: fast method */
int BitCount_1(unsigned int n)
{
    int count;

    for (count = 0; n; count++) {
        n = n & (n-1);  // clear the lowest 1
    } 

    return count;
}

/* method 3: bit flag method */
struct _byte {
    unsigned a: 1;
    unsigned b: 1;
    unsigned c: 1;
    unsigned d: 1;
    unsigned e: 1;
    unsigned f: 1;
    unsigned g: 1;
    unsigned h: 1;
    unsigned i: 1;
};
int BitCount_char(unsigned char ch)
{
    struct _byte *b_ch = (struct _byte*)&ch;
    return (b_ch->a + b_ch->b + b_ch->c + b_ch->d + b_ch->e + b_ch->f + b_ch->g + b_ch->h + b_ch->i);
}
int BitCount_2(unsigned int n)
{
    return (BitCount_char((unsigned char)(n & 0xff)) +
            BitCount_char((unsigned char)((n >> 8) & 0xff)) +
            BitCount_char((unsigned char)((n >> 16) & 0xff)) +
            BitCount_char((unsigned char)((n >> 24) & 0xff)));
}

/* method 4: dynamic lookup table */
int BitCount_3(unsigned int n)
{
    int table[256];
    int i;
    unsigned char *c;

    table[0] = 0;
    for (i = 1; i < 256; i++) {
        table[i] = table[i/2] + (i & 0x1);
    }

    c = (unsigned char *)&n;
    return (table[c[0]] + table[c[1]] + table[c[2]] + table[c[3]]);
}

/* method 5: parallel method */
int BitCount_4(unsigned int n)
{
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

    return n;
}

/* method 6: perfect method */
int BitCount_5(unsigned int n)
{
    unsigned int tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
    //printf("\ntmp = 0x%x", tmp);
    return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}


typedef int (*BitCount_func)(unsigned int);
int main()
{
    BitCount_func func[] = {BitCount_0,
                            BitCount_1,
                            BitCount_2,
                            BitCount_3,
                            BitCount_4,
                            BitCount_5,
                            NULL};
    unsigned int array[5] = { 0x0, 0x12345678, 0xabcdef90, 0x7d3051a9, 0xffffffff};
    int i, j;

    for (i = 0; func[i] != NULL; i++) {
        printf("\nBitCount_%d:", i);
        for (j = 0; j < 5; j++) {
            printf(" %2d,", func[i](array[j]));
        }
    }
    printf("\n");
}

