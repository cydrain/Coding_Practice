/*
 * Shortest Word Distance II
 *
 * This is a follow up of Shortest Word Distance. The only difference is now you
 * are given the list of words and your method will be called repeatedly many
 * times with different parameters. How would you optimize it?
 *
 * Design a class which receives a list of words in the constructor, and implements
 * a method that takes two words word1 and word2 and return the shortest distance
 * between these two words in the list.
 *
 * For example,
 * Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 *
 * Given word1 = “coding”, word2 = “practice”, return 3.
 * Given word1 = "makes", word2 = "coding", return 1. 
 */
class WordDistance {
private:
    unordered_map<string,vector<int>> wordMap;
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            wordMap[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int i = 0, j = 0, dist = INT_MAX;
        while (i < wordMap[word1].size() && j < wordMap[word2].size()) {
            dist = min(dist, abs(wordMap[word1][i]-wordMap[word2][j]));
            wordMap[word1][i] < wordMap[word2][j] ? i++ : j++;
        }
        return dist;
    }
};

