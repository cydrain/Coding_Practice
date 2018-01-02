/*
 * Implement Magic Dictionary
 *
 * Implement a magic directory with buildDict, and search methods.
 *
 * For the method buildDict, you'll be given a list of non-repetitive words to
 * build a dictionary.
 *
 * For the method search, you'll be given a word, and judge whether if you modify
 * exactly one character into another character in this word, the modified word is
 * in the dictionary you just built.
 *
 * Example 1:
 * Input: buildDict(["hello", "leetcode"]), Output: Null
 * Input: search("hello"), Output: False
 * Input: search("hhllo"), Output: True
 * Input: search("hell"), Output: False
 * Input: search("leetcoded"), Output: False
 */
class MagicDictionary {
private:
    unordered_map<string,int> m;
    unordered_set<string> s;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (string word : dict) {
            for (int i = 0; i < word.length(); i++) {
                string str = word;
                str[i] = '*';
                if (m.find(str) == m.end()) {
                    m[str] = 1;
                } else {
                    m[str]++;
                }
            }
            s.insert(word);
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        for (int i = 0; i < word.length(); i++) {
            string str = word;
            str[i] = '*';
            if (m.find(str) != m.end()) {
                if (m[str] > 1 || (m[str] == 1 && s.find(word) == s.end()))
                    return true;
            }
        }
        return false;
    }
};
