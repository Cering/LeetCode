/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (69.70%)
 * Likes:    13425
 * Dislikes: 1089
 * Total Accepted:    2.2M
 * Total Submissions: 3.1M
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given the root of a binary tree, imagine yourself standing on the right side
 * of it, return the values of the nodes you can see ordered from top to
 * bottom.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,2,3,null,5,null,4]
 * 
 * Output: [1,3,4]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3,4,null,null,null,5]
 * 
 * Output: [1,3,4,5]
 * 
 * Explanation:
 * 
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,null,3]
 * 
 * Output: [1,3]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = []
 * 
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 100].
 * -100 <= Node.val <= 100
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
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if(!root)
            return result;

        // 层序遍历树，用队列记录每层从右至左的节点
        std::queue<TreeNode *> node_queue;
        node_queue.push(root);
        // 用空指针分隔每层的节点
        node_queue.push(nullptr);
        // 只把每层的第一个节点输出至result
        bool need_print = true;
        while(!node_queue.empty()) {
            TreeNode *node = node_queue.front();
            node_queue.pop();

            if(!node) {
                if(node_queue.empty())
                    // 弹出的空指针是队列中最后一个元素，说明已经遍历完所有节点，直接退出
                    break;
                else {
                    // 队列中剩余的节点属于下一层，重置输出标记，并添加一个空指针分隔下一层
                    node_queue.push(nullptr);
                    need_print = true;
                    continue;
                }
            }

            if(need_print) {
                // 只把每层的第一个节点输出至result
                result.push_back(node->val);
                need_print = false;
            }
            // 层序遍历下一层节点，按照从右至左的顺序记至队列 
                node_queue.push(node->right);
            if(node->left)
                node_queue.push(node->left);
        }

        return result;
    }
};
// @lc code=end

