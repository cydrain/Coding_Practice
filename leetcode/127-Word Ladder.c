/*
 * Word Ladder
 *
 * Given two words (start and end), and a dictionary, find the length of
 * shortest transformation sequence from start to end, such that:
 *   Only one letter can be changed at a time
 *   Each intermediate word must exist in the dictionary
 *
 * For example,
 * Given:
 *  start = "hit"
 *  end = "cog"
 *  dict = ["hot","dot","dog","lot","log"]
 *
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 *
 * Note:
 *  Return 0 if there is no such transformation sequence.
 *  All words have the same length.
 *  All words contain only lowercase alphabetic characters.
 *
 */

int ladderLength(string start, string end, unordered_set<string> &dict) {
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    if (start == end) return 1;
    unordered_set<string> visited;
    queue<string> q;
    int level1 = 0, level2 = 0;
    int steps = 2;
    dict.insert(start);
    dict.insert(end);
    
    q.push(start);
    level1++;
    visited.insert(start);
    while (!q.empty()) {
        string s = q.front();
        q.pop();
        level1--;
        for (int i = 0; i < s.length(); i++) {
            string t = s;
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == s[i]) continue;
                t[i] = c;
                if (t == end) return steps;
                // t is in the dict, and it has not been visited
                if (dict.find(t) != dict.end() && visited.find(t) == visited.end()) {
                    visited.insert(t);
                    q.push(t);
                    level2++;
                }
            }
        }
        if (level1 == 0) {
            level1 = level2;
            level2 = 0;
            steps++;
        }
    }
    return 0;
}

