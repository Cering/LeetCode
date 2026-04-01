/*
 * @lc app=leetcode id=437 lang=cpp
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (46.33%)
 * Likes:    11910
 * Dislikes: 574
 * Total Accepted:    783.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        // 记录当前dfs路径上，各级节点到当前尾结点的路径和
        std::vector<int64_t> pathSum;
        return pathSumDfs(root, targetSum, pathSum);
    }

    int pathSumDfs(TreeNode* root, int targetSum, std::vector<int64_t>& pathSum) {
        if(!root)
            return 0;
        
        int cur = 0;
        for(auto& item : pathSum) {
            // 更新dfs路径中各级节点到当前节点的路径和
            item += root->val;
            // 如果符合目标值，则计数加1
            if(item == targetSum)
                cur++;
        }
        if(root->val == targetSum)
            cur++;
        // 当前结节记录进dfs路径
        pathSum.push_back(root->val);

        // dfs路径递归搜索左右子树，收集符合条件的结果
        int left = pathSumDfs(root->left, targetSum, pathSum);
        int right = pathSumDfs(root->right, targetSum, pathSum);

        // 从dfs路径中删除当前节点
        pathSum.pop_back();
        // 还原dfs路径中各级节点的路径和
        for(auto& item : pathSum)
            item -= root->val;

        return cur + left + right;
    }
};
// @lc code=end

