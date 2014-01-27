/*
 * Merge Intervals
 *
 * Given a collection of intervals, merge all overlapping intervals.
 *
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18]. 
 *
 */

    class comp {
    public:
        bool operator() (const Interval &i1, const Interval &i2) {
            return i1.start < i2.start;
        }
    };
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> r;
        int n = intervals.size();
        int i = 0;
        sort(intervals.begin(), intervals.end(), comp());
        while (i < n) {
            r.push_back(intervals[i++]);
            while (i < n && intervals[i].start <= r.back().end) {
                r.back().end = max(r.back().end, intervals[i++].end);
            }
        }
        return r;
    }



    struct cmp {
        bool operator()(const Interval &a, const Interval &b) {
            return a.start < b.start;
        }
    };
    vector<Interval> merge(vector<Interval> &itv) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = itv.size();
        if (n <= 1) return itv;
        sort(itv.begin(), itv.end(), cmp());
        for (int i = 1; i < itv.size(); i++) {
            if (itv[i-1].end < itv[i].start) continue;
            itv[i-1].end = max(itv[i-1].end, itv[i].end); 
            itv.erase(itv.begin()+i);
            i--;
        }
        return itv;
    }



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
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> r;
        for (int i = 0; i < intervals.size(); i++) {
            insert(r, intervals[i]);
        }
        return r;
    }
