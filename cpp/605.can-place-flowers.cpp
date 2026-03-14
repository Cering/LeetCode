/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (29.04%)
 * Likes:    7363
 * Dislikes: 1321
 * Total Accepted:    1.4M
 * Total Submissions: 4.7M
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * You have a long flowerbed in which some of the plots are planted, and some
 * are not. However, flowers cannot be planted in adjacent plots.
 * 
 * Given an integer array flowerbed containing 0's and 1's, where 0 means empty
 * and 1 means not empty, and an integer n, return true if n new flowers can be
 * planted in the flowerbed without violating the no-adjacent-flowers rule and
 * false otherwise.
 * 
 * 
 * Example 1:
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: true
 * Example 2:
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: false
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= flowerbed.length <= 2 * 10^4
 * flowerbed[i] is 0 or 1.
 * There are no two adjacent flowers in flowerbed.
 * 0 <= n <= flowerbed.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        int index = 0;
        while(index < length && n > 0) {
            if(flowerbed[index] == 1) {
                // 当前位置是1，其后面的位置肯定不能再种花，直接后跳两步
                index += 2;
            }
            else {
                if(index > 0 && flowerbed[index - 1] == 1) {
                    // 非首位时，前面一个位置如果是1，当前位置不能种花
                }
                else if(index + 1 < length && flowerbed[index + 1] == 1) {
                    // 非末位时，后面一个位置如果是1，当前位置不能种花
                }
                else {
                    // 种下花
                    n--;
                    // 种下花后，其后面的位置肯定不能再种花，直接跳过
                    index++;
                }
                index++;
            }
        }
        return n == 0;
    }
};
// @lc code=end

