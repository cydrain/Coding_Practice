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
    vector<int> nums;
    unordered_map<int,int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) == m.end()) {
            nums.push_back(val);
            m[val] = nums.size()-1;
            return true;
        } else {
            return false;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) != m.end()) {
            int last = nums.back();
            nums[m[val]] = last;
            m[last] = m[val];
            m.erase(val);
            nums.pop_back();
            return true;
        } else {
            return false;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % (nums.size())];
    }
};
