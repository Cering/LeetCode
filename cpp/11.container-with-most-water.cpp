/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (59.67%)
 * Likes:    34043
 * Dislikes: 2192
 * Total Accepted:    5.2M
 * Total Submissions: 8.7M
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the i^th line are (i, 0) and (i,
 * height[i]).
 * 
 * Find two lines that together with the x-axis form a container, such that the
 * container contains the most water.
 * 
 * Return the maximum amount of water a container can store.
 * 
 * Notice that you may not slant the container.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
 * container can contain is 49.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: height = [1,1]
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == height.length
 * 2 <= n <= 10^5
 * 0 <= height[i] <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int max_area = 0;
        while(left < right) {
            int cur_width = right - left;
            int cur_height = 0;
            // 仅移动两个边界中的较小者，因为其限制了水池容积上限，以较小作为边界的其它容积
            // 不可能比当前更大了。这里left++和right--都是为了尝试取到更多的水，如果短的
            // 板不动的话，取到的水永远不会比上次多。
            if(height[left] < height[right]) {
                cur_height = height[left];
                left++;
            }
            else {
                cur_height = height[right];
                right--;
            }
            int area = cur_width * cur_height;
            if(area > max_area)
                max_area = area;
        }

        return max_area;
    }
};
// @lc code=end

