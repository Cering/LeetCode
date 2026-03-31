/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
 *
 * https://leetcode.com/problems/leaf-similar-trees/description/
 *
 * algorithms
 * Easy (70.19%)
 * Likes:    4378
 * Dislikes: 125
 * Total Accepted:    675.6K
 * Total Submissions: 962.4K
 * Testcase Example:  '[3,5,1,6,2,9,8,null,null,7,4]\n' +
  '[3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]'
 *
 * Consider all the leaves of a binary tree, from left to right order, the
 * values of those leaves form a leaf value sequence.
 * 
 * 
 * 
 * For example, in the given tree above, the leaf value sequence is (6, 7, 4,
 * 9, 8).
 * 
 * Two binary trees are considered leaf-similar if their leaf value sequence is
 * the same.
 * 
 * Return true if and only if the two given trees with head nodes root1 and
 * root2 are leaf-similar.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 =
 * [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root1 = [1,2,3], root2 = [1,3,2]
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in each tree will be in the range [1, 200].
 * Both of the given trees will have values in the range [0, 200].
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        std::vector<int> root1_leaf;
        getLeaf(root1, root1_leaf);
        std::vector<int> root2_leaf;
        getLeaf(root2, root2_leaf);
        return root1_leaf == root2_leaf;
    }

    inline void getLeaf(TreeNode *root, std::vector<int>& leaf) {
        if(!root)
            return;
        if(!root->left && !root->right) {
            leaf.push_back(root->val);
            return;
        }
        if(root->left)
            getLeaf(root->left, leaf);
        if(root->right)
            getLeaf(root->right, leaf);
    }
};
// @lc code=end

