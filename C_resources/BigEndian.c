/*
 * Example: 0x12345678
 * 
 * Big Endian
 *
 * low addr                  high addr
 * ----------------------------------->
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |  12 |  34 |  56 |  78 |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 *
 * Little Endian
 * low addr                  high addr
 * ----------------------------------->
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 * |  78 |  56 |  34 |  12 |
 * +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
 *
 */

#include <stdio.h>

int main()
{
    unsigned int a = 0x11223344;
    unsigned char *c;

    c = (unsigned char*)&a;

    printf("\naddress of a: %p, value = 0x%x", &a, a);
    printf("\naddress of c: %p, value = 0x%x, 0x%x, 0x%x, 0x%x",
           c, *c, *(c+1), *(c+2), *(c+3));
    if (*c == 0x11) {
        printf("\nThis is big endian.\n");
    }
    else if (*c == 0x44) {
        printf("\nThis is little endian.\n");
    }
    else {
        printf("\nUnknown.\n");
    }
}

