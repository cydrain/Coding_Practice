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
    queue<int> data;
    int size;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0.0;
    }
    
    double next(int val) {
        if (data.size() < size) {
            data.push(val);
            sum += val;
        } else {
            int first = data.front();
            sum = sum - first + val;
            data.pop();
            data.push(val);
        }
        return (sum / data.size());
    }
};

