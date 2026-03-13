/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 *
 * https://leetcode.com/problems/move-zeroes/description/
 *
 * algorithms
 * Easy (63.51%)
 * Likes:    19317
 * Dislikes: 594
 * Total Accepted:    5M
 * Total Submissions: 7.8M
 * Testcase Example:  '[0,1,0,3,12]'
 *
 * Given an integer array nums, move all 0's to the end of it while maintaining
 * the relative order of the non-zero elements.
 * 
 * Note that you must do this in-place without making a copy of the array.
 * 
 * 
 * Example 1:
 * Input: nums = [0,1,0,3,12]
 * Output: [1,3,12,0,0]
 * Example 2:
 * Input: nums = [0]
 * Output: [0]
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you minimize the total number of operations done?
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int length = nums.size();
        if(length <= 1)
            return;

        // left指向第一个0元素
        int left = 0;
        while(left < length && nums[left] != 0)
            left++;

        // right总指向left右边的元素
        int right = left + 1;

        while(right < length) {
            // right指向left右侧的非0元素
            if(nums[right] == 0) {
                right++;
                continue;
            }

            // 交换left和right的元素，0值移到了右侧
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;

            // 更新left指向下一个0元素
            while(left < length && nums[left] != 0)
                left++;
            right = left + 1;
        }
    }
};
// @lc code=end