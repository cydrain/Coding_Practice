/*
 * Sentence Similarity
 *
 * Given two sentences words1, words2 (each represented as an array of strings),
 * and a list of similar word pairs pairs, determine if two sentences are similar.
 *
 * For example, "great acting skills" and "fine drama talent" are similar, if the
 * similar word pairs are pairs = [["great", "fine"], ["acting","drama"],
 * ["skills","talent"]].
 *
 * Note that the similarity relation is not transitive. For example, if "great"
 * and "fine" are similar, and "fine" and "good" are similar, "great" and "good"
 * are not necessarily similar.
 *
 * However, similarity is symmetric. For example, "great" and "fine" being similar
 * is the same as "fine" and "great" being similar.
 *
 * Also, a word is always similar with itself. For example, the sentences
 * words1 = ["great"], words2 = ["great"], pairs = [] are similar,
 * even though there are no specified similar word pairs.
 *
 * Finally, sentences can only be similar if they have the same number of words.
 * So a sentence like words1 = ["great"] can never be similar to
 * words2 = ["doubleplus","good"]. 
 */
class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        int n1 = words1.size();
        int n2 = words2.size();
        if (n1 != n2) return false;
        unordered_map<string,set<string>> m;
        int i;
        for (i = 0; i < pairs.size(); i++) {
            m[pairs[i].first].insert(pairs[i].second);
            m[pairs[i].second].insert(pairs[i].first);
        }
        for (i = 0; i < n1; i++) {
            if (words1[i] != words2[i] && 
                (m.find(words1[i]) == m.end() || m[words1[i]].find(words2[i]) == m[words1[i]].end()))
                return false;
        }
        return true;
    }
};