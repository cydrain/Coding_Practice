/*
 * Substring with Concatenation of All Words
 *
 * You are given a string, S, and a list of words, L, that are all of the same length.
 * Find all starting indices of substring(s) in S that is a concatenation of each word
 * in L exactly once and without any intervening characters.
 *
 * For example, given:
 * S: "barfoothefoobarman"
 * L: ["foo", "bar"]
 *
 * You should return the indices: [0,9].
 * (order does not matter). 
 */

vector<int> findSubstring(string S, vector<string> &L) {
        int n = S.length();
        int tnum = L.size();
        int tsize = L[0].length();
        int tlen = tnum * tsize;
        map<string,int> tmap;
        vector<int> res;
        int i, j, count;
        
        for (i = 0; i < tnum; i++) {
            if (tmap.find(L[i]) != tmap.end()) {
                tmap[L[i]]++;
            }
            else {
                tmap[L[i]] = 1;
            }
        }
        for (i = 0; i < n-tlen; i++) {
            string s = S.substr(i, tlen);
            map<string,int> left(tmap);
            count = 0;
            for (j = 0; j < tnum; j++) {
                string t = s.substr(j*tsize, tsize);
                if (left.find(t) != left.end()) {
                    if (left[t] > 0) {
                        left[t]--;
                        count++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (count == tnum) {
                res.push_back(i);
            }
        }
        return res;
    }



    vector<int> findSubstring(string S, vector<string> &L) {
        int slen = S.length();
        int tnum = L.size();
        int tsize = L[0].length();
        int tlen = tnum * tsize;
        string s, t;
        // tmap: L[i] -> index
        // dict: index -> times of appearence
        map<string,int> tmap;
        vector<int> dict;
        // store the index of substr of S in dict
        vector<int> index(slen, -1);

        vector<int> res;
        int i, j, count, idx;
        
        for (i = 0; i < tnum; i++) {
            if (tmap.find(L[i]) == tmap.end()) {
                tmap[L[i]] = dict.size();
                dict.push_back(1);
            }
            else {
                dict[tmap[L[i]]]++;
            }
        }
        for (i = 0; i <= slen-tsize; i++) {
            s = S.substr(i, tsize);
            if (tmap.find(s) != tmap.end()) {
                index[i] = tmap[s];
            }
        }
        for (i = 0; i <= slen-tlen; i++) {
            s = S.substr(i, tlen);
            vector<int> left(dict);
            count = 0;
            for (j = 0; j < tnum; j++) {
                idx = index[i+j*tsize];
                if (idx != -1) {
                    if (left[idx] > 0) {
                        left[idx]--;
                        count++;
                    }
                    else {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            if (count == tnum) {
                res.push_back(i);
            }
        }
        return res;
    }

