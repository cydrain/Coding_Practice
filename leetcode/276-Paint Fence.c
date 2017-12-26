/*
 * Paint Fence
 *
 * There is a fence with n posts, each post can be painted with one of the k colors.
 *
 * You have to paint all the posts such that no more than two adjacent fence posts
 * have the same color.
 *
 * Return the total number of ways you can paint the fence. 
 */
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0 || (n > 2 && k == 1)) return 0;
        int w1 = k;
        int w2 = k * k;
        int w3 = (n == 1 ? w1 : w2);
        for (int i = 0; i <= n-3; i++) {
            // if previous 2 posts use same color (w1), current post can choose left (k-1) colors
            // or current post always select different color (k-1) than the previous post (w2)
            w3 = (w1+w2) * (k-1);
            w1 = w2;
            w2 = w3;
        }
        return w3;
    }
};
