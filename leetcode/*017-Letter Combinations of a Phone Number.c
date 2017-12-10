/*
 * Letter Combinations of a Phone Number
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical order, your answer could be in any order you want. 
 *
 */

/* C solution */
    void letterCombinHelper(map<char,string> &m,    
                            string &digits,
                            int idx,            // the index of current handling charactor
                            string &p,          // reference of string, used to store intermedia combination
                            vector<string> &r   // reference of string vector to store all combinations
                            ) {
        if (idx == digits.length()) {
            r.push_back(p);
            return;
        }
        if (digits[idx] == '1') {
            letterCombinHelper(m, digits, idx+1, p, r);
        }
        else {
            string s = m[digits[idx]];
            for (int i = 0; i < s.length(); i++) {
                p += s[i];
                letterCombinHelper(m, digits, idx+1, p, r);
                p.erase(p.end()-1);
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<char,string> m;
        m['0'] = string(" ");
        m['1'] = string("");
        m['2'] = string("abc");
        m['3'] = string("def");
        m['4'] = string("ghi");
        m['5'] = string("jkl");
        m['6'] = string("mno");
        m['7'] = string("pqrs");
        m['8'] = string("tuv");
        m['9'] = string("wxyz");
        
        vector<string> r;
        string p;
        letterCombinHelper(m, digits, 0, p, r);
        return r;
    }



    vector<string> letterCombinations(string digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        const string key[] = {" ", "", "abc", "def", "ghi", "jkl",
                              "mno", "pqrs", "tuv", "wxyz"};
        vector<string> r(1);
        
        for (int i = 0; i < digits.size(); i++) {
            const string s = key[digits[i]-'0'];
            vector<string> tmp;
            for (int j = 0; j < s.length(); j++) {
                for (int k = 0; k < r.size(); k++) {
                    tmp.push_back(r[k]+s[j]);
                }
            }
            r = tmp;
        }
        return r;
    }


/* Java solution */
public class Solution {
    public List<String> letterCombinations(String digits) {
        Map<Integer,String> map = new HashMap<>();
        map.put(0, "");
        map.put(1, "");
        map.put(2, "abc");
        map.put(3, "def");
        map.put(4, "ghi");
        map.put(5, "jkl");
        map.put(6, "mno");
        map.put(7, "pqrs");
        map.put(8, "tuv");
        map.put(9, "wxyz");
        
        List<String> r = new ArrayList<>();
        int n = digits.length();
        if (n == 0) return r;
        List<String> tmp;
        r.add("");
        int i, j, k;
        String key = null;
        for (i = 0; i < digits.length(); i++) {
            key = map.get(digits.charAt(i)-'0');
            tmp = new ArrayList<String>();
            for (j = 0; j < key.length(); j++) {
                for (k = 0; k < r.size(); k++) {
                    tmp.add(r.get(k) + key.charAt(j));
                }
            }
            r = tmp;
        }
        return r;
    }
}

