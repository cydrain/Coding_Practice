/*
 * Meeting Rooms II
 *
 * Given an array of meeting time intervals consisting of start and end times
 * [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
 * required.
 *
 * For example,
 *   Given [[0, 30],[5, 10],[15, 20]],
 *   return 2. 
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start, end;
        int i, room = 0, endptr = 0;
        for (i = 0; i < n; i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        for (i = 0, endptr = 0; i < n; i++) {
            if (start[i] < end[endptr]) {
                room++;
            } else {
                endptr++;
            }
        }
        return room;
    }
};



struct Time {
    int time;
    int type;   // 1: start; -1: end
    Time(int x, int y) : time(x), type(y) {}
};

class cmp {
public:
    bool operator()(Time& t1, Time& t2) {
        return (t1.time < t2.time || (t1.time == t2.time && t1.type < t2.type));;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<Time> vt;
        int i, overlap = 0, room = 0;
        for (i = 0; i < intervals.size(); i++) {
            vt.push_back(Time(intervals[i].start, 1));
            vt.push_back(Time(intervals[i].end, -1));
        }
        sort(vt.begin(), vt.end(), cmp());
        for (i = 0; i < vt.size(); i++) {
            overlap += vt[i].type;
            room = max(room, overlap);
        }
        return room;
    }
};
