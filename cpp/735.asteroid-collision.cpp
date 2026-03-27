/*
 * @lc app=leetcode id=735 lang=cpp
 *
 * [735] Asteroid Collision
 *
 * https://leetcode.com/problems/asteroid-collision/description/
 *
 * algorithms
 * Medium (47.07%)
 * Likes:    9342
 * Dislikes: 1302
 * Total Accepted:    996.3K
 * Total Submissions: 2.1M
 * Testcase Example:  '[5,10,-5]'
 *
 * We are given an array asteroids of integers representing asteroids in a row.
 * The indices of the asteroid in the array represent their relative position
 * in space.
 * 
 * For each asteroid, the absolute value represents its size, and the sign
 * represents its direction (positive meaning right, negative meaning left).
 * Each asteroid moves at the same speed.
 * 
 * Find out the state of the asteroids after all collisions. If two asteroids
 * meet, the smaller one will explode. If both are the same size, both will
 * explode. Two asteroids moving in the same direction will never meet.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never
 * collide.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide
 * resulting in 10.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: asteroids = [3,5,-6,2,-1,4]​​​​​​​
 * Output: [-6,2,4]
 * Explanation: The asteroid -6 makes the asteroid 3 and 5 explode, and then
 * continues going left. On the other side, the asteroid 2 makes the asteroid
 * -1 explode and then continues going right, without reaching asteroid 4.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= asteroids.length <= 10^4
 * -1000 <= asteroids[i] <= 1000
 * asteroids[i] != 0
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::vector<int> result;
        for(const auto& a : asteroids) {
            if(a > 0 || result.empty())
                // 当前行星向右运动 或 向左运动但左边没有行星，可直接入栈
                result.push_back(a);
            else {
                // 当前行星向左运动 且 左边还有行星，需要循环判断
                while(!result.empty()) {
                    // 当前行星左边的行星
                    const auto& b = result.back();
                    if(b < 0) {
                        // 左边的行星也向左运动，当前行星不会相撞，可直接入栈，结束判断
                        result.push_back(a);
                        break;
                    }
                    else if(a + b < 0) {
                        // 左边行星质量小于当前行星，被撞毁出栈
                        result.pop_back();
                        if(result.empty()) {
                            // 撞毁后栈中已无行星，当前行星直接入栈，结束判断
                            result.push_back(a);
                            break;
                        }
                        // 左边行星撞毁后，栈中还有行星，需要继续下一轮循环判断
                    }
                    else if(a + b == 0) {
                        // 左边行星质量等于当前行星，双方撞毁，左边行星出栈，结束判断
                        result.pop_back();
                        break;
                    }
                    else
                        // 左边行星质量大于当前行星，当前行星撞毁，结束判断
                        break;
                }
            }
        }
        return result;
    }
};
// @lc code=end

