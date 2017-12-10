/*
 * Insert Interval
 *
 * Given a set of non-overlapping intervals, insert a new interval into
 * the intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to
 * their start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 
 *
 */

    vector<Interval> insert(vector<Interval> &itv, Interval n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        for (i = 0; i < itv.size(); i++) {
            if (n.start > itv[i].end) continue;
            
            if (n.end < itv[i].start) {
                itv.insert(itv.begin()+i, 1, n);
                return itv;
            }
            else if (n.end <= itv[i].end) {
                itv[i].start = min(n.start, itv[i].start);
                return itv;
            }
            else {
                n.start = min(n.start, itv[i].start);
                itv.erase(itv.begin()+i);
                i--;
            }
        }
        itv.push_back(n);
        return itv;
    }


    vector<Interval> insert(vector<Interval> &itv, Interval newInt) {
        int n = itv.size();
        vector<Interval> res;
        int i = 0;
        while (i < n && newInt.start > itv[i].end) {
            res.push_back(itv[i++]);
        }
        while (i < n && newInt.end >= itv[i].start) {
            newInt.start = min(newInt.start, itv[i].start);
            newInt.end = max(newInt.end, itv[i].end);
            i++;
        }
        res.push_back(newInt);
        while (i < n) {
            res.push_back(itv[i++]);
        }
        return res;
    }


/* Java solution */
public class Solution {
    public List<Interval> insert(List<Interval> itv, Interval n) {
        List<Interval> res = new ArrayList<>();
        int i = 0, len = itv.size();
        while (i < len && itv.get(i).end < n.start) {
            res.add(itv.get(i++));
        }
        while (i < len && itv.get(i).start <= n.end) {
            n.start = Math.min(n.start, itv.get(i).start);
            n.end = Math.max(n.end, itv.get(i).end);
            i++;
        }
        res.add(n);
        while (i < len) {
            res.add(itv.get(i++));
        }
        
        return res;
    }
}

