//
//  main.cpp
//  StrTok
//
//  Created by caiyd on 18/1/5.
//  Copyright © 2018年 caiyd. All rights reserved.
//
//  Realize StrTok, getNext() return a token seperated by delimit;
//  '|' is used as escape char.

#include <iostream>
#include <string>
#include <unordered_set>
#include <stdio.h>
using namespace std;

class StrTok {
private:
    char* str;
    const char* delimit;
    int start, end;
    int len;
    unordered_set<char> st;
    
public:
    StrTok(char* str, const char* delimit);
    int find_first_of(int idx);
    void removeDelimit();
    int findEnd();
    char* getNext();
};

StrTok::StrTok(char* str, const char* delimit) {
    this->str = str;
    this->delimit = delimit;
    start = end = 0;
    len = strlen(str);
    
    for (int i = 0; i < strlen(delimit); i++) {
        st.insert(delimit[i]);
    }
}

int StrTok::find_first_of(int idx) {
    int i;
    for (i = idx; i < len; i++) {
        if (st.find(str[i]) != st.end()) {
            break;
        }
    }
    return i;
}

void StrTok::removeDelimit() {
    int i = start, p = start;
    while (i < end) {
        if (str[i] == '|') {
            i++;
        }
        str[p++] = str[i++];
    }
    str[p] = '\0';
}

int StrTok::findEnd() {
    int i = start, end;
    while (i < len) {
        end = find_first_of(i);
        
        if (end != len) {
            int j = end - 1, count = 0;
            while (j >= 0 && str[j] == '|') {
                count++;
                j--;
            }
            if (count % 2 == 0) return end;
            else i = end + 1;
        } else {
            return end;
        }
    }
    return len;
}


char* StrTok::getNext() {
    if (start >= len) return nullptr;
    char *ptr;
    end = findEnd();
    removeDelimit();
    ptr = str + start;
    if (end != len) str[end] = '\0';
    start = end + 1;
    return ptr;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char *str = "I'm very handsom|,||| and rich";
    char *delimit = " ,";
    StrTok *st1 = new StrTok(strdup(str), delimit);
    char* ptr;
    while (ptr = st1->getNext()) {
        printf("%s\n", ptr);
    }
    return 0;
}
