// 计算x按比特左右反转的数

unsigned char func1(unsigned char c) {
    int i;
    unsigned char newc = 0;
    for (i = 0; i < 8; i++) {
        newc |= (c & 0x1);
        newc <<= 1;
        c >>= 1;
    }
    return newc;
}

unsigned char func2(unsigned char c) {
    c = ((c & 0xaa) >> 1) | ((c & 0x55) << 1);
    c = ((c & 0xcc) >> 2) | ((c & 0x33) << 2);
    c = ((c & 0xf0) >> 4) | ((c & 0x0f) << 4);
    return c;
}

