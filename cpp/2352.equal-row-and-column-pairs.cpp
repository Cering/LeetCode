/*
 * @lc app=leetcode id=2352 lang=cpp
 *
 * [2352] Equal Row and Column Pairs
 *
 * https://leetcode.com/problems/equal-row-and-column-pairs/description/
 *
 * algorithms
 * Medium (70.79%)
 * Likes:    2491
 * Dislikes: 192
 * Total Accepted:    398.7K
 * Total Submissions: 562.7K
 * Testcase Example:  '[[3,2,1],[1,7,6],[2,7,7]]'
 *
 * Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri,
 * cj) such that row ri and column cj are equal.
 * 
 * A row and column pair is considered equal if they contain the same elements
 * in the same order (i.e., an equal array).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
 * Output: 1
 * Explanation: There is 1 equal row and column pair:
 * - (Row 2, Column 1): [2,7,7]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
 * Output: 3
 * Explanation: There are 3 equal row and column pairs:
 * - (Row 0, Column 0): [3,1,2,2]
 * - (Row 2, Column 2): [2,4,2,2]
 * - (Row 3, Column 2): [2,4,2,2]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * n == grid.length == grid[i].length
 * 1 <= n <= 200
 * 1 <= grid[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        std::map<std::vector<int>, int> row_map;
        for(const auto& row : grid)
            row_map[row]++;

        int equal_pairs = 0;
        const int length = grid.size();
        for(int j = 0; j < length; j++) {
            std::vector<int> col;
            for(int i = 0; i < length; i++)
                col.push_back(grid[i][j]);
            equal_pairs += row_map[col];
        }

        return equal_pairs;
    }
};

class Solution2 {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int equal_pairs = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int k;
                for(k = 0; k < n; k++) {
                    if(grid[k][j] != grid[i][k])
                        break;
                }
                if(k == n)
                    equal_pairs++;
            }
        }
        return equal_pairs;
    }
};
// @lc code=end

