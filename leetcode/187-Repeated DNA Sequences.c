/*
 * Repeated DNA Sequences
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T,
 * for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify
 * repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur
 * more than once in a DNA molecule.
 *
 * For example,
 *   Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *   Return: ["AAAAACCCCC", "CCCCCAAAAA"].
 */ 
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> m;
        vector<string> ans;
        int len = s.length(), i;
        for (i = 0; i+9 < len; i++) {
            string str = s.substr(i, 10);
            m[str]++;
            if (m[str] == 2) ans.push_back(str);
        }
        return ans;
    }
};
