/*
 *  Flatten 2D Vector
 *
 * Implement an iterator to flatten a 2d vector.
 *
 * For example,
 *   Given 2d vector =
 *     [
 *      [1,2],
 *      [3],
 *      [4,5,6]
 *     ]
 *
 * By calling next repeatedly until hasNext returns false, the order of elements
 * returned by next should be: [1,2,3,4,5,6]. 
 */
class Vector2D {
private:
    vector<vector<int>>::iterator x, e;
    vector<int>::iterator y;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        x = vec2d.begin(), e = vec2d.end();
        if (x != e) y = x->begin();
    }

    int next() {
        return *y++;
    }

    bool hasNext() {
        while (x != e && y == x->end()) {
            x++;
            y = x->begin();
        }
        return (x != e);
    }
};



class Vector2D {
private:
    queue<pair<vector<int>::iterator,vector<int>::iterator>> q;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        for (int i = 0; i < vec2d.size(); i++) {
            if (!vec2d[i].empty())
                q.push(make_pair(vec2d[i].begin(), vec2d[i].end()));
        }
    }

    int next() {
        int val = *(q.front().first);
        q.front().first++;
        if (q.front().first == q.front().second)
            q.pop();
        return val;
    }

    bool hasNext() {
        return (!q.empty());
    }
};
