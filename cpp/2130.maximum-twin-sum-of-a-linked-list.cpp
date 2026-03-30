/*
 * @lc app=leetcode id=2130 lang=cpp
 *
 * [2130] Maximum Twin Sum of a Linked List
 *
 * https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/description/
 *
 * algorithms
 * Medium (81.63%)
 * Likes:    3925
 * Dislikes: 125
 * Total Accepted:    495.8K
 * Total Submissions: 607.1K
 * Testcase Example:  '[5,4,2,1]'
 *
 * In a linked list of size n, where n is even, the i^th node (0-indexed) of
 * the linked list is known as the twin of the (n-1-i)^th node, if 0 <= i <= (n
 * / 2) - 1.
 * 
 * 
 * For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the
 * twin of node 2. These are the only nodes with twins for n = 4.
 * 
 * 
 * The twin sum is defined as the sum of a node and its twin.
 * 
 * Given the head of a linked list with even length, return the maximum twin
 * sum of the linked list.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [5,4,2,1]
 * Output: 6
 * Explanation:
 * Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin
 * sum = 6.
 * There are no other nodes with twins in the linked list.
 * Thus, the maximum twin sum of the linked list is 6. 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [4,2,2,3]
 * Output: 7
 * Explanation:
 * The nodes with twins present in this linked list are:
 * - Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
 * - Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
 * Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: head = [1,100000]
 * Output: 100001
 * Explanation:
 * There is only one node with a twin in the linked list having twin sum of 1 +
 * 100000 = 100001.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the list is an even integer in the range [2,
 * 10^5].
 * 1 <= Node.val <= 10^5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *last_slow = nullptr;
        ListNode *next_slow = nullptr;

        while(fast && fast->next) {
            // 快指针每次移两格，直到移至尾结点
            fast = fast->next;
            if(!fast->next)
                break;
            fast = fast->next;

            // 慢指针每次移一格，同时反转链表
            next_slow = slow->next;
            slow->next = last_slow;
            last_slow = slow;
            slow = next_slow;
        }

        // 链表右半部分的头节点，遍历时从左往右移动
        ListNode *twin_right = slow->next;
        slow->next = last_slow;
        // 链表左半部分的头节点，已经被反转过了，遍历时从右往左移动
        ListNode *twin_left = slow;

        int max_sum = 0;
        // 计算每个孪生节点的和，并记录最大值
        while(twin_left && twin_right) {
            if(twin_left->val + twin_right->val > max_sum)
                max_sum = twin_left->val + twin_right->val;
            twin_left = twin_left->next;
            twin_right = twin_right->next;
        }

        return max_sum;
    }
};
// @lc code=end

