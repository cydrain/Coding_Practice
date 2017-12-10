/*
 * Roman to Integer
 *
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

/* C solution */
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i, r = 0;
        for (i = s.length()-1; i >= 0; i--) {
            if (i < s.length()-1 && m[s[i]] < m[s[i+1]]) {
                r -= m[s[i]];
            } else {
                r += m[s[i]];
            }
        }
        return r;
    }


/* Java solution */
public class Solution {
    public int romanToInt(String s) {
        HashMap<Character,Integer> map = new HashMap<>();
        map.put('I', 1);
        map.put('V', 5);
        map.put('X', 10);
        map.put('L', 50);
        map.put('C', 100);
        map.put('D', 500);
        map.put('M', 1000);
        int n = s.length();
        int i, num = 0;
        
        for (i = n-1; i >= 0; i--) {
            if (i == n-1 || map.get(s.charAt(i)) >= map.get(s.charAt(i+1))) {
                num += map.get(s.charAt(i));
            } else {
                num -= map.get(s.charAt(i));
            }
        }
        
        return num;
    }
}

