/*
 * @lc app=leetcode id=328 lang=cpp
 *
 * [328] Odd Even Linked List
 *
 * https://leetcode.com/problems/odd-even-linked-list/description/
 *
 * algorithms
 * Medium (62.27%)
 * Likes:    11473
 * Dislikes: 596
 * Total Accepted:    1.5M
 * Total Submissions: 2.4M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * Given the head of a singly linked list, group all the nodes with odd indices
 * together followed by the nodes with even indices, and return the reordered
 * list.
 * 
 * The first node is considered odd, and the second node is even, and so on.
 * 
 * Note that the relative order inside both the even and odd groups should
 * remain as it was in the input.
 * 
 * You must solve the problem in O(1) extra space complexity and O(n) time
 * complexity.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the linked list is in the range [0, 10^4].
 * -10^6 <= Node.val <= 10^6
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *odd_head = nullptr;
        ListNode *even_head = nullptr;
        ListNode *cur_odd = nullptr;
        ListNode *cur_even = nullptr;

        int index = 1;
        while(head) {
            if(index++ & 0x1 == 1) {
                if(!odd_head) {
                    odd_head = head;
                    cur_odd = odd_head;
                }
                else {
                    cur_odd->next = head;
                    cur_odd = cur_odd->next;
                }
                head = head->next;
                cur_odd->next = nullptr;
            }
            else {
                if(!even_head) {
                    even_head = head;
                    cur_even = even_head;
                }
                else {
                    cur_even->next = head;
                    cur_even = cur_even->next;
                }
                head = head->next;
                cur_even->next = nullptr;
            }
        }

        if(cur_odd)
            cur_odd->next = even_head;

        return odd_head;
    }
};
// @lc code=end

