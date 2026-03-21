/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 *
 * https://leetcode.com/problems/find-pivot-index/description/
 *
 * algorithms
 * Easy (62.02%)
 * Likes:    9274
 * Dislikes: 933
 * Total Accepted:    1.6M
 * Total Submissions: 2.6M
 * Testcase Example:  '[1,7,3,6,5,6]'
 *
 * Given an array of integers nums, calculate the pivot index of this array.
 * 
 * The pivot index is the index where the sum of all the numbers strictly to
 * the left of the index is equal to the sum of all the numbers strictly to the
 * index's right.
 * 
 * If the index is on the left edge of the array, then the left sum is 0
 * because there are no elements to the left. This also applies to the right
 * edge of the array.
 * 
 * Return the leftmost pivot index. If no such index exists, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [1,7,3,6,5,6]
 * Output: 3
 * Explanation:
 * The pivot index is 3.
 * Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
 * Right sum = nums[4] + nums[5] = 5 + 6 = 11
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output: -1
 * Explanation:
 * There is no index that satisfies the conditions in the problem statement.
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [2,1,-1]
 * Output: 0
 * Explanation:
 * The pivot index is 0.
 * Left sum = 0 (no elements to the left of index 0)
 * Right sum = nums[1] + nums[2] = 1 + -1 = 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 10^4
 * -1000 <= nums[i] <= 1000
 * 
 * 
 * 
 * Note: This question is the same as 1991:
 * https://leetcode.com/problems/find-the-middle-index-in-array/
 * 
 */

// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int> &nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            // 如果i是中心索引，其左右两侧元素之和相等都是sum，这时应满足
            // sum + nums[i] + sum = total
            if(2 * sum + nums[i] == total)
                return i;
            sum += nums[i];
        }
        return -1;
    }
};

class Solution2 {
public:
    int pivotIndex(vector<int>& nums) {
        const int length = nums.size();

        std::vector<int> left_sum(length, 0);
        for(int i = 1; i < length; i++)
            left_sum[i] = left_sum[i - 1] + nums[i - 1];

        std::vector<int> right_sum(length, 0);
        for(int i = length - 2; i >= 0; i--)
            right_sum[i] = right_sum[i + 1] + nums[i + 1];
        
        int pivot_index = -1;
        for(int i = 0; i < length; i++) {
            if(left_sum[i] == right_sum[i]) {
                pivot_index = i;
                break;
            }
        }

        return pivot_index;
    }
};
// @lc code=end

