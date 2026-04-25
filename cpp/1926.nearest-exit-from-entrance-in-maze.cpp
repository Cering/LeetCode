/*
 * @lc app=leetcode id=1926 lang=cpp
 *
 * [1926] Nearest Exit from Entrance in Maze
 *
 * https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/description/
 *
 * algorithms
 * Medium (48.30%)
 * Likes:    2639
 * Dislikes: 128
 * Total Accepted:    278.7K
 * Total Submissions: 575K
 * Testcase Example:  '[["+","+",".","+"],[".",".",".","+"],["+","+","+","."]]\n[1,2]'
 *
 * You are given an m x n matrix maze (0-indexed) with empty cells (represented
 * as '.') and walls (represented as '+'). You are also given the entrance of
 * the maze, where entrance = [entrancerow, entrancecol] denotes the row and
 * column of the cell you are initially standing at.
 * 
 * In one step, you can move one cell up, down, left, or right. You cannot step
 * into a cell with a wall, and you cannot step outside the maze. Your goal is
 * to find the nearest exit from the entrance. An exit is defined as an empty
 * cell that is at the border of the maze. The entrance does not count as an
 * exit.
 * 
 * Return the number of steps in the shortest path from the entrance to the
 * nearest exit, or -1 if no such path exists.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: maze = [["+","+",".","+"],[".",".",".","+"],["+","+","+","."]],
 * entrance = [1,2]
 * Output: 1
 * Explanation: There are 3 exits in this maze at [1,0], [0,2], and [2,3].
 * Initially, you are at the entrance cell [1,2].
 * - You can reach [1,0] by moving 2 steps left.
 * - You can reach [0,2] by moving 1 step up.
 * It is impossible to reach [2,3] from the entrance.
 * Thus, the nearest exit is [0,2], which is 1 step away.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: maze = [["+","+","+"],[".",".","."],["+","+","+"]], entrance = [1,0]
 * Output: 2
 * Explanation: There is 1 exit in this maze at [1,2].
 * [1,0] does not count as an exit since it is the entrance cell.
 * Initially, you are at the entrance cell [1,0].
 * - You can reach [1,2] by moving 2 steps right.
 * Thus, the nearest exit is [1,2], which is 2 steps away.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: maze = [[".","+"]], entrance = [0,0]
 * Output: -1
 * Explanation: There are no exits in this maze.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * maze.length == m
 * maze[i].length == n
 * 1 <= m, n <= 100
 * maze[i][j] is either '.' or '+'.
 * entrance.length == 2
 * 0 <= entrancerow < m
 * 0 <= entrancecol < n
 * entrance will always be an empty cell.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int m = maze.size();
        const int n = maze[0].size();
        std::queue<std::vector<int>> bfs_queue;
        // 记录从起点走到某个位置所需要的最少步数
        std::vector<std::vector<int>> steps(m, std::vector<int>(n, -1));
        bfs_queue.push(entrance);
        // 起点位置标记为已走过，步数标记为0
        maze[entrance[0]][entrance[1]] = '#';
        steps[entrance[0]][entrance[1]] = 0;
        int result = -1;

        while(!bfs_queue.empty()) {
            const std::vector<int>& pos = bfs_queue.front();
            const int i = pos[0];
            const int j = pos[1];
            bfs_queue.pop();

            // 从起点走到当前位置所需要的步数
            int s = steps[i][j];
            if((i == 0 || i == m-1 || j == 0 || j == n-1) && s != 0) {
                // 当前位置并且处于边界上并且不是起点，即为出口
                result = s;
                break;
            }

            if(i > 0 && maze[i-1][j] == '.') {
                // 向左走一步
                maze[i-1][j] = '#';
                steps[i-1][j] = s + 1;
                bfs_queue.push(std::vector<int>{i-1, j});
            }
            if(i < m-1 && maze[i+1][j] == '.') {
                // 向右走一步
                maze[i+1][j] = '#';
                steps[i+1][j] = s + 1;
                bfs_queue.push(std::vector<int>{i+1, j});
            }
            if(j > 0 && maze[i][j-1] == '.') {
                // 向上走一步
                maze[i][j-1] = '#';
                steps[i][j-1] = s + 1;
                bfs_queue.push(std::vector<int>{i, j-1});
            }
            if(j < n-1 && maze[i][j+1] == '.') {
                // 向下走一步
                maze[i][j+1] = '#';
                steps[i][j+1] = s + 1;
                bfs_queue.push(std::vector<int>{i, j+1});
            }
        }

        return result;
    }
};
// @lc code=end

