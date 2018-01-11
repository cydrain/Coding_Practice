/*
 * Two Sum III - Data structure design
 *
 * Design and implement a TwoSum class. It should support the following
 * operations: add and find.
 *
 * add - Add the number to an internal data structure.
 * find - Find if there exists any pair of numbers which sum is equal to the value.
 *
 * For example,
 *  add(1); add(3); add(5);
 *  find(4) -> true
 *  find(7) -> false
 */ 
class TwoSum {
    unordered_multiset<int> nums;
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (int i : nums) {
            int count = (i == value-i ? 1 : 0);
            if (nums.count(value-i) > count)
                return true;
        }
        return false;
    }
};
