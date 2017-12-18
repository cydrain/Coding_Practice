//
//  main.cpp
//  Trie-Tree
//
//  Created by caiyd on 17/12/18.
//  Copyright © 2017年 caiyd. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

#define CHAR_NUM    26

struct Trie_node {
    bool isStr;
    Trie_node *next[CHAR_NUM];
    
    Trie_node() : isStr(false) {
        memset(next, NULL, sizeof(next));
    }
};

class Trie {
private:
    Trie_node *root;
    
public:
    Trie();
    void insert(const char *word);
    bool search(const char *word);
    void destroy(Trie_node *root);
};

Trie::Trie() {
    root = new Trie_node();
}

void Trie::insert(const char *word) {
    if (word == NULL) return;
    Trie_node *curr = this->root;
    const char *p = word;
    while (*p != '\0') {
        int idx = *p - 'a';
        if (curr->next[idx] == NULL) {
            curr->next[idx] = new Trie_node();
        }
        curr = curr->next[idx];
        p++;
    }
    curr->isStr = true;
}

bool Trie::search(const char *word) {
    Trie_node *curr = this->root;
    const char *p = word;
    while (*p != '\0') {
        int idx = *p - 'a';
        if (curr->next[idx] == NULL) {
            return false;
        }
        curr = curr->next[idx];
        p++;
    }
    return curr->isStr;
}

void Trie::destroy(Trie_node *root) {
    if (!root) return;
    for (int i = 0; i < CHAR_NUM; i++) {
        destroy(root->next[i]);
    }
    delete root;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Trie t;
    t.insert("cyd");
    t.insert("a");
    t.insert("abc");
    printf("%s\n", t.search("ab") ? "true" : "false");
    printf("%s\n", t.search("a") ? "true" : "false");
    printf("%s\n", t.search("cyd") ? "true" : "false");
    printf("%s\n", t.search("cl") ? "true" : "false");
    return 1;
}


