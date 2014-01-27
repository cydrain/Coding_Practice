/*
 * Count and Say
 *
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 *
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string. 
 *
 */

    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string read;
        string say("1");
        char c;
        int count;
        
        while (n > 1) {
            c = '#';
            count = 0;
            read = say;
            say = "";
            for (int i = 0; i < read.length(); i++) {
                if (read[i] != c) {
                    if (count > 0) {
                        say += to_string(count) + c;
                    }
                    c = read[i];
                    count = 1;
                }
                else {
                    count++;
                }
            }
            say += to_string(count) + c;
            n--;
        }
        return say;
    }



    string countAndSay(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        string s(1, '1');
        char c;
        int count;
        for (int i = 1; i < n; i++) {
            c = '#';
            count = 0;
            string t;
            for (int j = 0; j < s.length(); j++) {
                if (s[j] != c) {
                    if (count) {
                        t += string(1, count+'0') + c;
                    }
                    c = s[j];
                    count = 1;
                }
                else {
                    count++;
                }
            }
            t += string(1, count+'0') + c;
            s = t;
        }
        return s;
    }



string itoa(int n) {
    string r;
    while (n) {
        r = string(1, n%10+'0') + r;
        n = n / 10;
    }
    return r;
}
string countAndSay(string s) {
    string r;
    int count = 1;
    int i = 1;
    while (i < s.length()) {
        if (s[i] == s[i-1]) {
            count++;
        }
        else {
            r += itoa(count) + s[i-1];
            count = 1;
        }
        i++;
    }
    r += itoa(count) + s[i-1];
    return r;
}
string countAndSay(int n) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    string r(1, '1');
    while (--n) {
        r = countAndSay(r);
    }
    return r;
}


