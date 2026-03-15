/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (68.56%)
 * Likes:    25794
 * Dislikes: 1691
 * Total Accepted:    4.4M
 * Total Submissions: 6.4M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 * 
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 * 
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 * 
 * 
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The input is generated such that answer[i] is guaranteed to fit in a 32-bit
 * integer.
 * 
 * 
 * 
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();

        // 存储从左边开始到当前位置的乘积
        std::vector<int> product_from_left(length, 1);
        for(int i = 0; i < length; i++) { 
            if(i == 0)
                product_from_left[i] = nums[i];
            else
                product_from_left[i] = nums[i] * product_from_left[i - 1];
        }

        // 存储从右边开始到当前位置的乘积
        std::vector<int> product_from_right(length, 1);
        for(int i = length - 1; i >= 0; i--) {
            if(i == length - 1)
                product_from_right[i] = nums[i];
            else
                product_from_right[i] = nums[i] * product_from_right[i + 1];
        }

        std::vector<int> result(length, 1);
        for(int i = 0; i < length; i++) {
            // 当前位置 = 左位所有数的乘积 * 右边所有数的积 = 排除当前元素数组所有数的积
            if(i > 0)
                result[i] *= product_from_left[i - 1];
            if(i < length - 1)
                result[i] *= product_from_right[i + 1];
        }

        return result;
    }
};
// @lc code=end

