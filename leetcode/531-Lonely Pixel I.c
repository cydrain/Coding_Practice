/*
 * Lonely Pixel I
 *
 * Given a picture consisting of black and white pixels, find the number of black
 * lonely pixels.
 *
 * The picture is represented by a 2D char array consisting of 'B' and 'W', which
 * means black and white pixels respectively.
 *
 * A black lonely pixel is character 'B' that located at a specific position where
 * the same row and same column don't have any other black pixels.
 *
 * Example:
 *
 * Input: 
 * [['W', 'W', 'B'],
 *  ['W', 'B', 'W'],
 *  ['B', 'W', 'W']]
 *
 * Output: 3
 *  Explanation: All the three 'B's are black lonely pixels.
 */
class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int m = picture.size();
        if (m == 0) return 0;
        int n = picture[0].size();
        vector<int> row(m, 0);
        vector<int> col(n, 0);
        int i, j, count = 0;
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        for (i = 0; i < m; i++) {
            for (j = 0; j < n; j++) {
                if (picture[i][j] == 'B' && row[i] == 1 && col[j] == 1)
                    count++;
            }
        }
        return count;
    }
};
