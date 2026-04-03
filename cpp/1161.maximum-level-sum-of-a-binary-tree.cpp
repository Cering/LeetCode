/*
 * @lc app=leetcode id=1161 lang=cpp
 *
 * [1161] Maximum Level Sum of a Binary Tree
 *
 * https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (69.98%)
 * Likes:    4132
 * Dislikes: 117
 * Total Accepted:    566.7K
 * Total Submissions: 810K
 * Testcase Example:  '[1,7,0,7,-8,null,null]'
 *
 * Given the root of a binary tree, the level of its root is 1, the level of
 * its children is 2, and so on.
 * 
 * Return the smallest level x such that the sum of all the values of nodes at
 * level x is maximal.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,7,0,7,-8,null,null]
 * Output: 2
 * Explanation: 
 * Level 1 sum = 1.
 * Level 2 sum = 7 + 0 = 7.
 * Level 3 sum = 7 + -8 = -1.
 * So we return the level with the maximum sum which is level 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
 * Output: 2
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 10^4].
 * -10^5 <= Node.val <= 10^5
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
    int maxLevelSum(TreeNode* root) {
        if(!root)
            return 0;

        std::queue<TreeNode *> queue;
        queue.push(root);
        queue.push(nullptr);
        int level = 1;
        int level_sum = 0;
        int max_level = 1;
        int max_level_sum = root->val;

        while(!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop();

            if(!node) {
                if(level_sum > max_level_sum) {
                    max_level = level;
                    max_level_sum = level_sum;
                }
                if(queue.empty())
                    break;
                level++;
                level_sum = 0;
                queue.push(nullptr);
                continue;
            }

            level_sum += node->val;

            if(node->left)
                queue.push(node->left);
            if(node->right)
                queue.push(node->right);
        } 

        return max_level;
    }
};
// @lc code=end

