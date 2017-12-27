/*
 * Zigzag Iterator
 *
 * Given two 1d vectors, implement an iterator to return their elements alternately.
 *
 * For example, given two 1d vectors:
 *   v1 = [1, 2]
 *   v2 = [3, 4, 5, 6]
 *
 * By calling next repeatedly until hasNext returns false, the order of elements
 * returned by next should be: [1, 3, 2, 4, 5, 6]. 
 */
// using queue
class ZigzagIterator {
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> Q;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (!v1.empty()) Q.push(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) Q.push(make_pair(v2.begin(), v2.end()));
    }

    int next() {
        vector<int>::iterator it = Q.front().first;
        vector<int>::iterator itEnd = Q.front().second;
        Q.pop();
        if (it + 1 != itEnd) Q.push(make_pair(it+1, itEnd));
        return *it;
    }

    bool hasNext() {
        return (!Q.empty());
    }
};

// using vector
class ZigzagIterator {
private:
    int top;
    int size;
    vector<vector<int>> v;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        top = 0;
        size = 2;
        v.push_back(v1);
        v.push_back(v2);
    }

    int next() {
        int num, idx;
        num = top % size;
        idx = top / size;
        top++;
        return v[num][idx];
    }

    bool hasNext() {
        int i;
        int num, idx;
        for (i = 0; i < size; i++) {
            num = top % size;
            idx = top / size;
            if (idx < v[num].size()) return true;
            top++;
        }
        return false;
    }
};
