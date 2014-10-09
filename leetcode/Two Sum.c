/*
 * Two Sum
 * 
 * Given an array of integers, find two numbers such that they
 * add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers
 * such that they add up to the target, where index1 must be less
 * than index2. 
 *
 * Please note that your returned answers (both index1 and index2)
 * are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2 
 *
 */

    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i, j;
        vector<int> r;
        for (i = 0; i < numbers.size(); i++) {
            for (j = i+1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    r.push_back(i+1);
                    r.push_back(j+1);    
                    return r;
                }
            }
        }
    }





    int search(vector<int> &num, int target) {
        int n = num.size();
        int i;
        for (i = 0; i < n; i++) {
            if (num[i] == target) {
                return i+1;
            }
        }
    }
    int rev_search(vector<int> &num, int target) {
        int n = num.size();
        int i;
        for (i = n-1; i >= 0; i--) {
            if (num[i] == target) {
                return i+1;
            }
        }
    }
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n-1, sum;
        vector<int> num(numbers);
        int num1, num2;
        vector<int> result(2, -1);
        
        sort(num.begin(), num.end());
        while (l < r) {
            sum = num[l] + num[r];
            if (sum == target) {
                num1 = num[l];
                num2 = num[r];
                break;
            }
            if (sum < target) {
                l++;
            }
            else {
                r--;
            }
        }
        
        result[0] = search(numbers, num1);
        result[1] = rev_search(numbers, num2);
        
        if (result[0] > result[1]) {
            swap(result[0], result[1]);
        }
        
        return result;
    }

