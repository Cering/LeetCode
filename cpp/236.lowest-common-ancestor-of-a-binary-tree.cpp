/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 *
 * https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/description/
 *
 * algorithms
 * Medium (68.69%)
 * Likes:    18653
 * Dislikes: 490
 * Total Accepted:    2.6M
 * Total Submissions: 3.7M
 * Testcase Example:  '[3,5,1,6,2,0,8,null,null,7,4]\n5\n1'
 *
 * Given a binary tree, find the lowest common ancestor (LCA) of two given
 * nodes in the tree.
 * 
 * According to the definition of LCA on Wikipedia: “The lowest common ancestor
 * is defined between two nodes p and q as the lowest node in T that has both p
 * and q as descendants (where we allow a node to be a descendant of
 * itself).”
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
 * Output: 3
 * Explanation: The LCA of nodes 5 and 1 is 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
 * Output: 5
 * Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant
 * of itself according to the LCA definition.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1,2], p = 1, q = 2
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [2, 10^5].
 * -10^9 <= Node.val <= 10^9
 * All Node.val are unique.
 * p != q
 * p and q will exist in the tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return nullptr;
        if(root == p || root == q)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        // 左子树找不到p和q，一定在右子树里
        if(!left)
            return right;

        // 右子树找不到p和q，一定在左子树里
        if(!right)
            return left;

        // p和q分散在左右子树里，当前节点就是公共祖先
        // 因为是先序遍历二叉树，当前节点就是最近公共祖先
        return root;
    }
};

class Solution2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode *> ppath;
        findPath(root, p, ppath);
        std::vector<TreeNode *> qpath;
        findPath(root, q, qpath);
        auto pit = ppath.begin();
        auto qit = qpath.begin();
        TreeNode *result = nullptr;
        while(pit != ppath.end() && qit != qpath.end() && *pit == *qit) {
            result = *pit;
            pit++;
            qit++;
        }
        return result;
    }

    bool findPath(TreeNode *root, TreeNode *node, std::vector<TreeNode *>& path) {
        if(!root)
            return false;
        path.push_back(root);
        if(root == node)
            return true;
        if(findPath(root->left, node, path))
            return true;
        if(findPath(root->right, node, path))
            return true;
        path.pop_back();
        return false;
    }
};
// @lc code=end

