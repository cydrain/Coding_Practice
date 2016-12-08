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

/* C++ solution */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> n(nums);
        vector<int> r(2, -1);
        int len = nums.size();
        int i = 0, j = len-1;
        int sum, n1, n2;
        
        sort(n.begin(), n.end());
        while (i < j) {
            sum = n[i] + n[j];
            if (sum == target) {
                n1 = n[i];
                n2 = n[j];
                break;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        
        for (i = 0; i < len; i++) {
            if (n1 == nums[i]) {
                r[0] = i;
                break;
            }
        }
        for (i = len-1; i >= 0; i--) {
            if (n2 == nums[i]) {
                r[1] = i;
                break;
            }
        }
        
        return r;
    }
};


/* Java solution */
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] result = new int[2];
        int[] num = Arrays.copyOf(numbers, numbers.length);
        int v1 = 0, v2 = 0;
        int i = 0, j = num.length-1;
        Arrays.sort(num);
        while (i < j) {
            if (num[i] + num[j] == target) {
                v1 = num[i];
                v2 = num[j];
                break;
            } else if (num[i] + num[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        
        for (i = 0; i < numbers.length; i++) {
            if (numbers[i] == v1) {
                result[0] = i+1;
                break;
            }
        }
        
        for (i = numbers.length-1; i >= 0; i--) {
            if (numbers[i] == v2) {
                result[1] = i+1;
                break;
            }
        }
        
        if (result[0] > result[1]) {
            int tmp;
            tmp = result[0];
            result[0] = result[1];
            result[1] = tmp;
        }
        
        return result;
    }
}

