/*
 * Next Closest Time
 *
 * Given a time represented in the format "HH:MM", form the next closest time by
 * reusing the current digits. There is no limit on how many times a digit can be
 * reused.
 *
 * You may assume the given input string is always valid. For example, "01:34",
 * "12:09" are all valid. "1:34", "12:9" are all invalid.
 *
 * Example 1:
 *   Input: "19:34"
 *   Output: "19:39"
 *   Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39,
 *   which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours
 *   and 59 minutes later.
 *
 * Example 2:
 *   Input: "23:59"
 *   Output: "22:22"
 *   Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22.
 *   It may be assumed that the returned time is next day's time since it is smaller
 *   than the input time numerically.
 */
class Solution {
public:
    string nextClosestTime(string time) {
        int d0 = time[0] - '0';
        int d1 = time[1] - '0';
        int d2 = time[3] - '0';
        int d3 = time[4] - '0';
        int h = d0*10 + d1;
        int m = d2*10 + d3;
        bitset<10> bs;
        bs.set(d0), bs.set(d1), bs.set(d2), bs.set(d3);
        int i;
        for (i = 0; i < 1440; i++) {
            if (++m == 60) {
                m = 0;
                if (++h == 24) h = 0;
            }
            d0 = h / 10, d1 = h % 10;
            d2 = m / 10, d3 = m % 10;
            if (bs.test(d0) && bs.test(d1) && bs.test(d2) && bs.test(d3)) {
                char buf[6] = {0};
                sprintf(buf, "%02d:%02d", h, m);
                return string(buf);
            }
        }
    }
};
