/*
 * Meeting Rooms
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 *
 * For example,
 *  Given [[0, 30],[5, 10],[15, 20]],
 *  return false. 
 */
class Solution {
private:
    static bool comp(const Interval& a, const Interval& b) {
        return (a.start < b.start || (a.start == b.start && a.end <= b.end));
    }
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};


class comp {
public:
    bool operator()(const Interval& a, const Interval& b) {
        return (a.start < b.start || (a.start == b.start && a.end <= b.end));
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), comp());
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};
