/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 *
 * https://leetcode.com/problems/number-of-provinces/description/
 *
 * algorithms
 * Medium (69.94%)
 * Likes:    11133
 * Dislikes: 427
 * Total Accepted:    1.5M
 * Total Submissions: 2.1M
 * Testcase Example:  '[[1,1,0],[1,1,0],[0,0,1]]'
 *
 * There are n cities. Some of them are connected, while some are not. If city
 * a is connected directly with city b, and city b is connected directly with
 * city c, then city a is connected indirectly with city c.
 * 
 * A province is a group of directly or indirectly connected cities and no
 * other cities outside of the group.
 * 
 * You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the
 * i^th city and the j^th city are directly connected, and isConnected[i][j] =
 * 0 otherwise.
 * 
 * Return the total number of provinces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 200
 * n == isConnected.length
 * n == isConnected[i].length
 * isConnected[i][j] is 1 or 0.
 * isConnected[i][i] == 1
 * isConnected[i][j] == isConnected[j][i]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;

        int n = isConnected.size();
        for(int i = 0; i < n; i++) {
            // 对角线值为1，说明当前城市已被访问过，跳过
            if(isConnected[i][i] == -1)
                continue;
            // 访问到一个新省份的城市，计数加1
            result++;

            // DFS存储当前城市所属省份的所有城市
            std::stack<int> province;
            province.push(i);
            while(!province.empty()) {
                int j = province.top();
                province.pop();
                // 当前城市已经被访问过，跳过
                if(isConnected[j][j] == -1)
                    continue;
                // 标记当前城市已被访问
                isConnected[j][j] = -1;
                for(int k = 0; k < n; k++) {
                    // 遍历当前城市连接的其它城市放入栈中
                    if(isConnected[j][k] == 1)
                        province.push(k);
                }
            }
        }

        return result;
    }
};
// @lc code=end

