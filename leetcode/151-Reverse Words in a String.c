// Reverse Words in a String
//
// Given an input string, reverse the string word by word.
//
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
//
class Solution {
public:
    void reverseWords(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++, end--;
        }
    }
    void reverseWords(string &s) {
        int len = s.length();
        int i = 0, j = 0, p = 0;
        reverseWords(s, 0, len-1);
        for (i = 0; i < len; i++) {
            if (s[i] != ' ') {
                if (p != 0) s[p++] = ' ';
                j = i;
                while (j < len && s[j] != ' ') s[p++] = s[j++];
                reverseWords(s, p-j+i, p-1);
                i = j;
            }
        }
        s.erase(s.begin()+p, s.end());
    }
};

    void reverseWords(string &s) {
        stack<string> sk;
        int start = -1, len = 0;
        int i;
        string r;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (start != -1) {
                    sk.push(s.substr(start, len));
                }
                start = -1;
                len = 0;
            }
            else {
                if (start == -1) {
                    start = i;
                }
                len++;
            }
        }
        if (start != -1) {
            sk.push(s.substr(start, len));
        }

        while (!sk.empty()) {
            r += sk.top();
            sk.pop();
            if (!sk.empty()) {
                r += " ";
            }
        }
        s = r;
    }


