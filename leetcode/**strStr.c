/*
 * Implement strStr()
 *
 * Returns a pointer to the first occurrence of needle in haystack,
 * or null if needle is not part of haystack. 
 */

    char *strStr(char *s, char *p) {
        int s_len = strlen(s);
        int p_len = strlen(p);
        int i = 0, j = 0;
        while (i < s_len && j < p_len) {
            if (s[i] == p[j]) {
                i++, j++;
            }
            else {
                i = i - j + 1;
                j = 0;
            }
        }
        if (j == p_len) {
            return s+i-j;
        }
        else {
            return NULL;
        }
    }



// KMP Algorithm
    void getNext(char *p, int next[]) {
        int p_len = strlen(p);
        int j = 0;
        int k = -1;     // K 就是最大前缀后缀值
        next[0] = -1;
        while (j < p_len-1) {
            if (k == -1 || p[k] == p[j]) {
                j++;
                k++;
                if (p[j] != p[k]) {
                    next[j] = k;
                }
                else {
                    next[j] = next[k];
                }
            }
            else {
                k = next[k];
            }
        }
    }
    char *strStr(char *s, char *p) {
        int s_len = strlen(s);
        int p_len = strlen(p);
        int *next = new int[p_len];
        int i = 0, j = 0;
        
        getNext(p, next);
        
        while (i < s_len && j < p_len) {
            if (j == -1 || s[i] == p[j]) {
                i++, j++;
            }
            else {
                j = next[j];
            }
        }
        
        delete []next;
        
        if (j == p_len) {
            return s+i-j;
        }
        else {
            return NULL;
        }
    }

