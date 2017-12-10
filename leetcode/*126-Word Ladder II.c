/*
 * Word Ladder II
 *
 * Given two words (start and end), and a dictionary, find all shortest
 * transformation sequence(s) from start to end, such that:
 *   Only one letter can be changed at a time
 *   Each intermediate word must exist in the dictionary
 *
 * For example,
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 *
 * Return
 *  [
 *      ["hit","hot","dot","dog","cog"],
 *      ["hit","hot","lot","log","cog"]
 *  ]
 *
 * Note:
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 * 
 */

void findLaddersHelper(int start, vector<int> &d, vector<string> &word_array, vector<vector<int> > &next,
                       vector<string> &path, vector<vector<string> > &result) {
    path.push_back(word_array[start]);
    if (d[start] == 0) {
        result.push_back(path);
    }
    else {
        for (int i = 0; i < next[start].size(); i++) {
            findLaddersHelper(next[start][i], d, word_array, next, path, result);
        }
    }
    path.pop_back();
}
vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    vector<vector<string> > result;
    if (start == end) return result;
    vector<string> word_array;
    map<string,int> word_idx;
    vector<vector<int> > conn;
    
    dict.insert(start);
    dict.insert(end);
    unordered_set<string>::iterator dict_it;
    for (dict_it = dict.begin(); dict_it != dict.end(); dict_it++) {
        // save all words in dict into a vector<string>
        word_array.push_back(*dict_it);
        // also create a map<string,int> to store the word&index
        word_idx[*dict_it] = word_array.size()-1;
    }
    
    // create a connect graph based on the words in dict
    conn.resize(word_array.size());
    for (int i = 0; i < word_array.size(); i++) {
        string s = word_array[i];
        for (int j = 0; j < s.length(); j++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == word_array[i][j]) continue;
                s[j] = c;
                if (dict.find(s) != dict.end()) {
                    conn[i].push_back(word_idx[s]);
                }
            }
            s[j] = word_array[i][j];
        }
    }
    
    // do BFS from end to start, for each node in the shortest path, record the prev node set
    queue<int> q;
    vector<int> d(word_array.size(), -1);
    vector<vector<int> > next(word_array.size());
    int from = word_idx[start], to = word_idx[end];
    int x, y, dist;
    q.push(to);
    d[to] = 0;
    while (!q.empty()) {
        x = q.front();
        dist = d[x]+1;
        if (d[from] >= 0 && dist > d[from]) break;
        q.pop();
        for (int i = 0; i < conn[x].size(); i++) {
            y = conn[x][i];
            if (d[y] == -1) {
                d[y] = dist;
                next[y].push_back(x);
                q.push(y);
            }
            else if (d[y] == dist) {
                next[y].push_back(x);
            }
        }
    }
    
    if (d[from] >= 0) {
        vector<string> path;
        findLaddersHelper(from, d, word_array, next, path, result);
    }
    return result;
}
