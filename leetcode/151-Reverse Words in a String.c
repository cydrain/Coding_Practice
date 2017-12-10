/*
 * Reverse Words in a String
 *
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 */

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

