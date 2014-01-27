/*
 * Anagrams
 *
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 */

    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> r;
        map<string, vector<string> > dict;
        map<string, vector<string> >::iterator it;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            dict[s].push_back(strs[i]);
        }
        
        for (it = dict.begin(); it != dict.end(); it++) {
            if (it->second.size() > 1) {
                for (int j = 0; j < it->second.size(); j++) {
                    r.push_back(it->second[j]);
                }
            }
        }
        
        return r;
    }
