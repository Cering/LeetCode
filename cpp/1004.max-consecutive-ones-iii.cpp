/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 *
 * https://leetcode.com/problems/max-consecutive-ones-iii/description/
 *
 * algorithms
 * Medium (67.24%)
 * Likes:    10411
 * Dislikes: 187
 * Total Accepted:    1.3M
 * Total Submissions: 2M
 * Testcase Example:  '[1,1,1,0,0,0,1,1,1,1,0]\n2'
 *
 * Given a binary array nums and an integer k, return the maximum number of
 * consecutive 1's in the array if you can flip at most k 0's.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
 * Output: 6
 * Explanation: [1,1,1,0,0,1,1,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
 * Output: 10
 * Explanation: [0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
 * Bolded numbers were flipped from 0 to 1. The longest subarray is
 * underlined.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 0 <= k <= nums.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int length = nums.size();
        
        // 窗口左边界
        int left = 0;
        // 窗口右边界的下一个位置
        int right = 0;
        // 当前窗口中0的个数
        int cur_k = 0;

        int longest_ones = 0;
        int cur_ones = 0;
        while(right < length) {
            if(cur_k < k) {
                // 窗口中0的数量没超上限，不需要缩小窗口左边界
                if(nums[right] == 0)
                    cur_k++;
            }
            else if(nums[right] == 0) {
                // 下一个位置是0，且当前窗口里的0已达到上限
                // 需要缩小窗口左边界直至移出一个0
                while(left < right && nums[left] != 0)
                    left++;
                // 移出窗口最左侧的0
                left++;
            }
            // 窗口右边界扩大
            right++;
            // 窗口扩大后更新最大值
            cur_ones = right - left;
            if(cur_ones > longest_ones)
                longest_ones = cur_ones;
        }

        return longest_ones;
    }
};
// @lc code=end

