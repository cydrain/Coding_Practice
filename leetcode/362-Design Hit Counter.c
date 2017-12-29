/*
 * Design Hit Counter
 *
 * Design a hit counter which counts the number of hits received in the past 5 minutes.
 *
 * Each function accepts a timestamp parameter (in seconds granularity) and you may
 * assume that calls are being made to the system in chronological order (ie, the
 * timestamp is monotonically increasing). You may assume that the earliest timestamp
 * starts at 1.
 *
 * It is possible that several hits arrive roughly at the same time.
 */
class HitCounter {
private:
    int times[300] = {0};
    int hits[300] = {0};
public:
    /** Initialize your data structure here. */
    HitCounter() {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp % 300;
        if (times[idx] != timestamp) {
            times[idx] = timestamp;
            hits[idx] = 1;
        } else {
            hits[idx]++;
        }
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int i, cnt = 0;
        for (i = 0; i < 300; i++) {
            if (timestamp-times[i] < 300) {
                cnt += hits[i];
            }
        }
        return cnt;
    }
};

