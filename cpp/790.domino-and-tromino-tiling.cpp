/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (51.45%)
 * Likes:    4157
 * Dislikes: 1321
 * Total Accepted:    281.1K
 * Total Submissions: 547K
 * Testcase Example:  '3'
 *
 * You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You
 * may rotate these shapes.
 * 
 * Given an integer n, return the number of ways to tile an 2 x n board. Since
 * the answer may be very large, return it modulo 10^9 + 7.
 * 
 * In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3
 * Output: 5
 * Explanation: The five different ways are shown above.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 1
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numTilings(int n) {
        if(n <= 2)
            return n;

        static constexpr long long MOD = 1e9 + 7;
        std::vector<long long> ways(n + 1, 0);
        ways[1] = 1;
        ways[2] = 2;
        ways[3] = 5;

        for(int i = 4; i <= n; i++) {
            ways[i] = (ways[i-1] * 2 + ways[i-3]) % MOD;
        }

        return ways[n];
    }
};


class Solution2 {
public:
    int numTilings(int n) {
        if(n <= 2)
            return n;

        static constexpr long long MOD = 1e9 + 7;
        std::vector<std::vector<long long>> ways(
            n + 1, std::vector<long long>(4, 0));
        ways[0][3] = 1;

        for(int i = 1; i <= n; i++) {
            ways[i][0] = ways[i-1][3];
            ways[i][1] = (ways[i-1][0] + ways[i-1][2]) % MOD;
            ways[i][2] = (ways[i-1][0] + ways[i-1][1]) % MOD;
            ways[i][3] = (ways[i-1][0] + ways[i-1][1] + ways[i-1][2] +
                         ways[i-1][3]) % MOD;
        }

        return ways[n][3];
    }
};
// @lc code=end

