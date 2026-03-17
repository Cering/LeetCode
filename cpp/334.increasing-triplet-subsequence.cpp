/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 *
 * https://leetcode.com/problems/increasing-triplet-subsequence/description/
 *
 * algorithms
 * Medium (39.22%)
 * Likes:    8841
 * Dislikes: 692
 * Total Accepted:    911.7K
 * Total Submissions: 2.3M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given an integer array nums, return true if there exists a triple of indices
 * (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. If no such
 * indices exists, return false.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,2,3,4,5]
 * Output: true
 * Explanation: Any triplet where i < j < k is valid.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [5,4,3,2,1]
 * Output: false
 * Explanation: No triplet exists.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,1,5,0,4,6]
 * Output: true
 * Explanation: One of the valid triplet is (1, 4, 5), because nums[1] == 1 <
 * nums[4] == 4 < nums[5] == 6.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 5 * 10^5
 * -2^31 <= nums[i] <= 2^31 - 1
 * 
 * 
 * 
 * Follow up: Could you implement a solution that runs in O(n) time complexity
 * and O(1) space complexity?
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        // first用于记录当前最小的元素
        int first = INT_MAX;
        // 如果second已经赋值，则其左边一定有小于second的元素，second是三元组中的中间元素
        int second = INT_MAX;
        for(const auto& n : nums) {
            if(n <= first)
                // 更新first后可能在second的右边，但second左边仍然有小于其的元素，所以
                // second的值仍然有效, 这里更新first是为了后续寻找更小的second值
                first = n;
            else if(n <= second)
                second = n;
            else
                // 当前数比second大，即可作为三元组中最后一个元素，返回true
                return true;
        }
        return false;
    }
};
// @lc code=end

