/*
 * @lc app=leetcode id=1493 lang=cpp
 *
 * [1493] Longest Subarray of 1's After Deleting One Element
 *
 * https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/
 *
 * algorithms
 * Medium (71.10%)
 * Likes:    4807
 * Dislikes: 110
 * Total Accepted:    632.7K
 * Total Submissions: 889.8K
 * Testcase Example:  '[1,1,0,1]'
 *
 * Given a binary array nums, you should delete one element from it.
 * 
 * Return the size of the longest non-empty subarray containing only 1's in the
 * resulting array. Return 0 if there is no such subarray.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,1,0,1]
 * Output: 3
 * Explanation: After deleting the number in position 2, [1,1,1] contains 3
 * numbers with value of 1's.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [0,1,1,1,0,1,1,0,1]
 * Output: 5
 * Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1]
 * longest subarray with value of 1's is [1,1,1,1,1].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [1,1,1]
 * Output: 2
 * Explanation: You must delete one element.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^5
 * nums[i] is either 0 or 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        const int length = nums.size();
        int left = 0;
        int right = 0;
        int longest_ones = 0;

        int zero_cnt = 0;
        int one_cnt = 0;
        while(right < length) {
            if(zero_cnt == 0) {
                // 当前窗口里没有0，直接更新0和1的计数
                if(nums[right] == 0)
                    zero_cnt++;
                else
                    one_cnt++;
            }
            else if(nums[right] == 1) {
                // 当前窗口里有1个0，当前位置是1，直接更新1的计数
                one_cnt++;
            }
            else {
                // 当前窗口里有1个0，当前位置是0，需要把前面的0移出窗口
                while(left < right && nums[left] == 1) {
                    // 不断移出窗口左边界的1，直到找到0
                    one_cnt--;
                    left++;
                }
                // 移出窗口左边界的0，此时0的计数仍然是1，不需要更新
                left++;
            }

            right++;
            if(zero_cnt == 1 && one_cnt > longest_ones)
                // 如果当前窗口里有1个0，需要去掉这个0
                // 剩余one_cnt个1即为符合条件的子数组长度
                longest_ones = one_cnt;
            else if(zero_cnt == 0 && one_cnt - 1 > longest_ones)
                // 如果当前窗口里没有0，需要去掉1个1
                // 剩余one_cnt-1个1即为符合条件的子数组长度
                longest_ones = one_cnt - 1;
        }

        return longest_ones;
    }
};
// @lc code=end

