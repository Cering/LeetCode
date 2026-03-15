/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 *
 * https://leetcode.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (55.43%)
 * Likes:    10460
 * Dislikes: 5569
 * Total Accepted:    2.9M
 * Total Submissions: 5.2M
 * Testcase Example:  '"the sky is blue"'
 *
 * Given an input string s, reverse the order of the words.
 * 
 * A word is defined as a sequence of non-space characters. The words in s will
 * be separated by at least one space.
 * 
 * Return a string of the words in reverse order concatenated by a single
 * space.
 * 
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or trailing
 * spaces.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to a
 * single space in the reversed string.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^4
 * s contains English letters (upper-case and lower-case), digits, and spaces '
 * '.
 * There is at least one word in s.
 * 
 * 
 * 
 * Follow-up: If the string data type is mutable in your language, can you
 * solve it in-place with O(1) extra space?
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        // 当前单词第一个字符位置
        int word_left = 0;
        // 当前单词最后一个字符之后的位置
        int word_right = 0;
        int length = s.size();

        // 字符串当前位置
        int pos = 0;
        while(pos < length) {
            if(s[pos] != ' ') {
                if(word_left != 0 && word_left == word_right) {
                    // 非首次单词时，在当前单词前添加一个空格
                    s[word_right] = ' ';
                    word_left++;
                    word_right = word_left;
                }
                // 非空格字符，拷贝到当前单词
                s[word_right] = s[pos];
                word_right++;
            }
            else if(word_right > word_left) {
                // 遇到空格，当前单词拷贝完毕，反转单词
                reverse(s, word_left, word_right - 1);
                // 更新当前单词第一个字符位置
                word_left = word_right;
            }
            else {
                // 遇到了连续重复的空格，直接跳过
            }
            pos++;
        }

        // 反转最后一个单词
        if(word_right > word_left)
            reverse(s, word_left, word_right - 1);
        // 反转整个字符串
        reverse(s, 0, word_right - 1);
        // 返回反转后字符串中的有效内容
        return s.substr(0, word_right);
    }

    void reverse(string& s, int left, int right) {
        while(left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};
// @lc code=end

