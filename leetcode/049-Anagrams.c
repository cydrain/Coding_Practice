/*
 * Anagrams
 *
 * Given an array of strings, return all groups of strings that are anagrams.
 *
 * Note: All inputs will be in lower-case.
 *
 */

/* C solution */
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


/* Java solution */
public class Solution {
    public String sort(String s){
        char[] chars = s.toCharArray();
        Arrays.sort(chars);
        return new String(chars);
    }
    public List<String> anagrams(String[] strs) {
        Map<String,List<String>> map = new HashMap<>();
        List<String> list = null;
        List<String> res = new ArrayList<>();
        String key = null;
        for (int i = 0; i < strs.length; i++) {
            key = sort(strs[i]);
            list = map.get(key);
            if (list == null) {
                list = new ArrayList<>();
                list.add(strs[i]);
                map.put(key, list);
            } else {
                list.add(strs[i]);
            }
        }
        
        for (List<String> list1: map.values()) {
            if (list1.size() > 1) {
                for (String s: list1) {
                    res.add(s);
                }
            }
        }
        return res;
    }
}

