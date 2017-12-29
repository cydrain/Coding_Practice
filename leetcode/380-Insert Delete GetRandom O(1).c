/*
 * Insert Delete GetRandom O(1)
 *
 * Design a data structure that supports all following operations in average O(1) time.
 *
 *  insert(val): Inserts an item val to the set if not already present.
 *  remove(val): Removes an item val from the set if present.
 *  getRandom: Returns a random element from current set of elements.
 *  Each element must have the same probability of being returned.
 */
class RandomizedSet {
private:
    unordered_map<int,int> m;
    vector<int> num;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        m[val] = num.size();
        num.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = num.back();
        num.pop_back();
        m[last] = m[val];
        num[m[last]] = last;
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return num[rand() % num.size()];
    }
};

