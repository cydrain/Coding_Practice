/*
 * Moving Average from Data Stream
 *
 * Given a stream of integers and a window size, calculate the moving average of
 * all integers in the sliding window.
 *
 * For example,
 *
 * MovingAverage m = new MovingAverage(3);
 * m.next(1) = 1
 * m.next(10) = (1 + 10) / 2
 * m.next(3) = (1 + 10 + 3) / 3
 * m.next(5) = (10 + 3 + 5) / 3
 */
class MovingAverage {
private:
    queue<int> q;
    double sum;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->sum = 0.0;
        this->size = size;
    }
    
    double next(int val) {
        q.push(val);
        sum += val;
        if (q.size() > size) {
            sum -= q.front();
            q.pop();
        }
        return sum/q.size();
    }
};
