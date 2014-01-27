/*
 * Zigzag Conversion
 *
 * The string "PAYPALISHIRING" is written in a zigzag pattern
 * on a given number of rows like this: 
 *  P   A   H   N
 *  A P L S I I G
 *  Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 *
 * Write the code that will take a string and make this conversion
 * given a number of rows: 
 *   string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */

    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows == 1) return s;
        if (s.length() <= nRows) return s;
        vector<string> vs(nRows);
        string r;
        int i, j = 0;
        int dir = 1;
        for (i = 0; i < s.length(); i++) {
            vs[j] += s[i];
            j = j + dir;
            if (j == 0) {
                dir = 1;
            }
            else if (j == nRows-1) {
                dir = -1;
            }
        }
        for (j = 0; j < nRows; j++) {
            r += vs[j];
        }
        return r;
    }



    string convert(string s, int nRows) {
        // Note: The Solution object is instantiated only once and is reused by each test case.    
        int len = s.length();
        if (nRows == 1 || len <= nRows) return s;
        vector<string> row(nRows);
        string r;
        int dir = 1;
        int i = 0, n = 0;
        while (n < len) {
            row[i].append(1, s[n++]);
            if ((i == nRows-1 && dir == 1) || (i == 0 && dir == -1)) {
                dir *= -1;
            }
            i += dir;
        }
        for (i = 0; i < nRows; i++) {
            r += row[i];
        }
        return r;
    }
