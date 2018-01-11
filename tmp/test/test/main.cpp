//
//  main.cpp
//  test
//
//  Created by caiyd on 18/1/11.
//  Copyright © 2018年 caiyd. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int maximumSwap(int num) {
    string s = to_string(num);
    int len = s.length(), i, j;
    bool maxidx;
    for (i = 0; i < len; i++) {
        maxidx = i;
        for (j = len-1; j > i; j--) {
            if (s[j] > s[maxidx]) {
                maxidx = j;
                printf("maxidx = %d\n", maxidx);
            }
        }
        if (maxidx != i) {
            printf("swap %c(%d) <==> %c(%d)\n", s[maxidx], maxidx, s[i], i);
            swap(s[maxidx], s[i]);
            break;
        }
        
    }
    return stoi(s);
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << maximumSwap(9967) << endl;
    return 0;
}
