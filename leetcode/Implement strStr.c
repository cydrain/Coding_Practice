/*
 * Implement strStr()
 *
 * Implement strStr().
 *
 * Returns a pointer to the first occurrence of needle in haystack,
 * or null if needle is not part of haystack. 
 *
 */

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!*needle) return haystack;
        char *p = NULL;
        int i;
        for (p = haystack; *p != NULL; p++) {
            i = 0;
            while (p[i] && needle[i] && p[i] == needle[i]) {
                i++;
            }
            if (needle[i] == NULL) {
                return p;
            }
        }
        return NULL;
    }



    void getNext(const char* pattern,int next[]) {
        next[0] = -1;
        int k = -1, j = 0;
        while (pattern[j] != '\0') {
            if (k != -1 && pattern[k] != pattern[j]) {
                k = next[k];
            }
            ++j;++k;
            if (pattern[k] == pattern[j]) {
                next[j] = next[k];
            }
            else {
                next[j] = k;
            }
        }
    }
    char *strStr(char *Text, char *Pattern) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!Pattern) {
            return Text;
        }
        int len = 0;
        char *c = Pattern;
        while (*c++ != '\0') {  //移动指针比移动下标快。
            ++len;  //字符串长度。
        }
        int *next = new int[len+1];
        getNext(Pattern, next); //求Pattern的next函数值

        int index = 0, i = 0, j = 0;
        while (Text[i] != '\0' && Pattern[j] != '\0') {
            if (Text[i] == Pattern[j]) {
                ++i;// 继续比较后继字符
                ++j;
            }
            else {
                index += j - next[j];
                if (next[j] != -1) {
                    j = next[j];// 模式串向右移动
                }
                else {
                    j = 0;
                    ++i;
                }
            }
        }//while
        
        delete []next;
        if (Pattern[j] == '\0') {
            return Text+index;   // 匹配成功
        }
        else {
            return NULL;
        }
    }
