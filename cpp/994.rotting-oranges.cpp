/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * https://leetcode.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Medium (58.08%)
 * Likes:    15167
 * Dislikes: 477
 * Total Accepted:    1.6M
 * Total Submissions: 2.8M
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * You are given an m x n grid where each cell can have one of three
 * values:
 * 
 * 
 * 0 representing an empty cell,
 * 1 representing a fresh orange, or
 * 2 representing a rotten orange.
 * 
 * 
 * Every minute, any fresh orange that is 4-directionally adjacent to a rotten
 * orange becomes rotten.
 * 
 * Return the minimum number of minutes that must elapse until no cell has a
 * fresh orange. If this is impossible, return -1.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
 * Output: -1
 * Explanation: The orange in the bottom left corner (row 2, column 0) is never
 * rotten, because rotting only happens 4-directionally.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[0,2]]
 * Output: 0
 * Explanation: Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 10
 * grid[i][j] is 0, 1, or 2.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int result = 10;
        const int m = grid.size();
        const int n = grid[0].size();

        bool has_rotten = false;
        do {
            has_rotten = false;
            int fresh_cnt = 0;

            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    // 空单元格，不需要处理
                    if(grid[i][j] == 0)
                        continue;
                    // 新鲜橘子，只计数不处理
                    if(grid[i][j] == 1) {
                        fresh_cnt++;
                        continue;
                    }
                    // 本轮刚腐烂的橘子，不需要处理
                    if(grid[i][j] == result)
                        continue;
                    // 上一轮腐烂的橘子，本轮标记为腐烂
                    if(grid[i][j] == result - 1)
                        grid[i][j] = 2;

                    if(j >= 1 && grid[i][j-1] == 1) {
                        // 腐烂左边的橘子
                        grid[i][j-1] = result;
                        has_rotten = true;
                    }
                    if(j < n-1 && grid[i][j+1] == 1) {
                        // 腐烂右边的橘子
                        grid[i][j+1] = result;
                        has_rotten = true;
                    }
                    if(i >= 1 && grid[i-1][j] == 1) {
                        // 腐烂上边的橘子
                        grid[i-1][j] = result;
                        has_rotten = true;
                    }
                    if(i < m-1 && grid[i+1][j] == 1) {
                        // 腐烂下边的橘子
                        grid[i+1][j] = result;
                        has_rotten = true;
                    }
                }
            }

            // 本轮如果发生过腐烂，分钟计数加1
            if(has_rotten)
                result++;
            else {
                // 本轮没发生过腐烂，结束循环
                if(fresh_cnt > 0) {
                    // 存在无法被腐烂的橘子，返回-1
                    result = -1;
                }
                else {
                    // 所有橘子都已经被腐烂，减去初始偏移量，作为最终分钟结果
                    result -= 10;
                }
                break;
            }
        } while(has_rotten);

        return result;
    }
};
// @lc code=end

