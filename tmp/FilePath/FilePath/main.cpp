//
//  main.cpp
//  FilePath
//
//  Created by caiyd on 17/12/27.
//  Copyright © 2017年 caiyd. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthLongestPath(string input) {
    int len = input.length();
    int start = 0, end;
    int level = 0;
    vector<string> dir;
    int maxlen = 0, currlen, i;
    
    while (start < len) {
        if (input[start] == '\n') start++;
        
        // get current level
        level = 0;
        while (input[start] == '\t') {
            level++;
            start++;
        }
        
        // get current dir name
        end = input.find('\n', start);
        if (end == string::npos) end = len;
        string currdir = input.substr(start, end-start);
        printf("start = %d, end = %d, level = %d, currdir = '%s'\n", start, end, level, currdir.c_str());
        
        // insert current dir into dir vector
        if (level < dir.size()) {
            dir[level] = currdir;
        } else {
            dir.push_back(currdir);
        }
        
        // if reach file name, calculate the total length
        if (currdir.find('.') != string::npos) {
            for (i = 0, currlen = 0; i < dir.size(); i++) {
                currlen += dir[i].length();
                printf("'%s', currlen = %d\n", dir[i].c_str(), currlen);
            }
            currlen += (int)dir.size() - 1;  // add the length for '/'
            printf("dir.size() = %d, currlen = %d\n", dir.size(), currlen);
            maxlen = max(maxlen, currlen);
            printf("maxlen = %d\n", maxlen);
        }
        
        start = end;
    }
    return maxlen;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    string s("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext");
    cout << lengthLongestPath(s) << endl;
    return 0;
}
