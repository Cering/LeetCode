/*
 * @lc app=leetcode id=1137 lang=cpp
 *
 * [1137] N-th Tribonacci Number
 *
 * https://leetcode.com/problems/n-th-tribonacci-number/description/
 *
 * algorithms
 * Easy (63.28%)
 * Likes:    4836
 * Dislikes: 213
 * Total Accepted:    1.1M
 * Total Submissions: 1.7M
 * Testcase Example:  '4'
 *
 * The Tribonacci sequence Tn is defined as follows: 
 * 
 * T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.
 * 
 * Given n, return the value of Tn.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 4
 * Output: 4
 * Explanation:
 * T_3 = 0 + 1 + 1 = 2
 * T_4 = 1 + 1 + 2 = 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 25
 * Output: 1389537
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 37
 * The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31
 * - 1.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int tribonacci(int n) {
        if(n <= 1)
            return n;
        if(n == 2)
            return 1;
        int t_3 = 0;
        int t_2 = 1;
        int t_1 = 1;
        int t;
        for(int i = 3; i <= n; i++) {
            t = t_3 + t_2 + t_1;
            t_3 = t_2;
            t_2 = t_1;
            t_1 = t;
        }
        return t;
    }
};
// @lc code=end

