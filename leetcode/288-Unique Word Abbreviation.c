/*
Unique Word Abbreviation

An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:

a) it                      --> it    (no abbreviation)

     1
b) d|o|g                   --> d1g

              1    1  1
     1---5----0----5--8
c) i|nternationalizatio|n  --> i18n

              1
     1---5----0
d) l|ocalizatio|n          --> l10n

Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.

Example:

Given dictionary = [ "deer", "door", "cake", "card" ]

isUnique("dear") -> false
isUnique("cart") -> true
isUnique("cane") -> false
isUnique("make") -> true
 */
class ValidWordAbbr {
public:
    unordered_map<string,unordered_set<string>> m;
    string strAbbr(string& word) {
        int len = word.length();
        if (len > 2) {
            string abbr = word[0] + to_string(len-2) + word[len-1];
            return abbr;
        } else {
            return word;
        }
    }
    ValidWordAbbr(vector<string> dictionary) {
        for (auto word : dictionary) {
            string abbr = strAbbr(word);
            m[abbr].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abbr = strAbbr(word);
        if (m.find(abbr) == m.end()) return true;
        auto s = m[abbr];
        return (s.count(word) == s.size());
    }
};
