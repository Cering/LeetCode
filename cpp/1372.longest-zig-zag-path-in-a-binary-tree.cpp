/*
 * @lc app=leetcode id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 *
 * https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/description/
 *
 * algorithms
 * Medium (66.97%)
 * Likes:    3748
 * Dislikes: 86
 * Total Accepted:    282.4K
 * Total Submissions: 421.2K
 * Testcase Example:  '[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]'
 *
 * You are given the root of a binary tree.
 * 
 * A ZigZag path for a binary tree is defined as follow:
 * 
 * 
 * Choose any node in the binary tree and a direction (right or left).
 * If the current direction is right, move to the right child of the current
 * node; otherwise, move to the left child.
 * Change the direction from right to left or from left to right.
 * Repeat the second and third steps until you can't move in the tree.
 * 
 * 
 * Zigzag length is defined as the number of nodes visited - 1. (A single node
 * has a length of 0).
 * 
 * Return the longest ZigZag path contained in that tree.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1]
 * Output: 3
 * Explanation: Longest ZigZag path in blue nodes (right -> left -> right).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,1,1,null,1,null,null,1,1,null,1]
 * Output: 4
 * Explanation: Longest ZigZag path in blue nodes (left -> right -> left ->
 * right).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: 0
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [1, 5 * 10^4].
 * 1 <= Node.val <= 100
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
    int longestZigZag(TreeNode* root) {
        // 记录最长交错路径上的节点数
        int max_zz_nodes = 1;
        // 记录每一步的路径信息：
        //   1. 当前节点属于父节点的左孩子(1)或右孩子(2)
        //   2. 以当前节点为结尾的交错路径里，最长的节点数
        std::vector<std::pair<int, int>> path_info;
        longestZigZagDfs(root, max_zz_nodes, path_info);
        return max_zz_nodes - 1;
    }

    void longestZigZagDfs(TreeNode *root, int& max_zz_nodes,
                          std::vector<std::pair<int, int>>& path_info) {
        if(!root)
            return;
        
        // 默认为根节点情况，没有父节点，最长交错节点数为1
        int cur_direction = 0;
        int cur_zz_nodes = 1;
        if(!path_info.empty()) {
            // 非根节点时，取出当前节点的路径信息
            auto& cur_info = path_info.back();
            cur_direction = cur_info.first;
            cur_zz_nodes = cur_info.second;
        }

        if(root->left) {
            // 路径向左，移动至左孩子
            int next_direction = 1;
            int next_zz_nodes = 2;
            if(cur_direction == 0 || cur_direction != next_direction) {
                // 父节点-当前节点-左孩子的路径不一致，属于交错路径，左孩子的节点数+1
                next_zz_nodes = cur_zz_nodes + 1;
                if(next_zz_nodes > max_zz_nodes)
                    max_zz_nodes = next_zz_nodes;
            }
            // 记录左孩子路径，递归搜索左子树
            path_info.push_back({next_direction, next_zz_nodes});
            longestZigZagDfs(root->left, max_zz_nodes, path_info);
            // 弹出左孩子路径，恢复路径至原始状态
            path_info.pop_back();
        }

        if(root->right) {
            // 路径向右，移动至右孩子
            int next_direction = 2;
            int next_zz_nodes = 2;
            if(cur_direction == 0 || cur_direction != next_direction) {
                // 父节点-当前节点-右孩子的路径不一致，属于交错路径，右孩子的节点数+1
                next_zz_nodes = cur_zz_nodes + 1;
                if(next_zz_nodes > max_zz_nodes)
                    max_zz_nodes = next_zz_nodes;
            }
            // 记录右孩子路径，递归搜索右子树
            path_info.push_back({next_direction, next_zz_nodes});
            longestZigZagDfs(root->right, max_zz_nodes, path_info);
            // 弹出右孩子路径，恢复路径至原始状态
            path_info.pop_back();
        }
    }
};
// @lc code=end