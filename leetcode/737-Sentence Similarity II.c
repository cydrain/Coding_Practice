/*
 * Sentence Similarity II

Given two sentences words1, words2 (each represented as an array of strings), and a list of similar word pairs pairs, determine if two sentences are similar.

For example, words1 = ["great", "acting", "skills"] and words2 = ["fine", "drama", "talent"] are similar, if the similar word pairs are pairs = [["great", "good"], ["fine", "good"], ["acting","drama"], ["skills","talent"]].

Note that the similarity relation is transitive. For example, if "great" and "good" are similar, and "fine" and "good" are similar, then "great" and "fine" are similar.

Similarity is also symmetric. For example, "great" and "fine" being similar is the same as "fine" and "great" being similar.

Also, a word is always similar with itself. For example, the sentences words1 = ["great"], words2 = ["great"], pairs = [] are similar, even though there are no specified similar word pairs.

Finally, sentences can only be similar if they have the same number of words. So a sentence like words1 = ["great"] can never be similar to words2 = ["doubleplus","good"]. 
 */
class Solution {
public:
    bool match(unordered_map<string,unordered_set<string>>& m, string& w1, string& w2) {
        unordered_set<string> visited;
        queue<string> q;
        string s;
        q.push(w1);
        visited.insert(w1);
        while (!q.empty()) {
            s = q.front();
            q.pop();
            if (s == w2) return true;
            for (auto &t : m[s]) {
                if (visited.find(t) != visited.end()) continue;
                visited.insert(t);
                q.push(t);
            }
        }
        return false;
    }
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n = words1.size();
        if (n != words2.size()) return false;
        unordered_map<string,unordered_set<string>> m;
        int i;
        for (i = 0; i < pairs.size(); i++) {
            //m[pairs[i].first].insert(pairs[i].first);
            m[pairs[i].first].insert(pairs[i].second);
            //m[pairs[i].second].insert(pairs[i].second);
            m[pairs[i].second].insert(pairs[i].first);
        }
        for (i = 0; i < n; i++) {
            if (!match(m, words1[i], words2[i])) return false;
        }
        return true;
    }
};




class DSU {
private:
    int *parent;
public:
    DSU(int N) {
        parent = new int[N];
        for (int i = 0; i < N; ++i)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void setParent(int x, int y) {
        parent[find(x)] = find(y);
    }
};

class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if (words1.size() != words2.size()) return false;
        unordered_map<string, int> index;
        int count = 0;
        DSU *dsu = new DSU(2 * pairs.size());
        for (auto pair: pairs) {
            if (index.find(pair.first) == index.end()) index[pair.first] = count++;
            if (index.find(pair.second) == index.end()) index[pair.second] = count++;
            dsu->setParent(index[pair.first], index[pair.second]);
        }

        for (int i = 0; i < words1.size(); ++i) {
            string w1 = words1[i], w2 = words2[i];
            if (w1 == w2) continue;
            if (index.find(w1) == index.end() ||
                index.find(w2) == index.end() ||
                dsu->find(index[w1]) != dsu->find(index[w2]))
                return false;
        }
        return true;
    }
};

