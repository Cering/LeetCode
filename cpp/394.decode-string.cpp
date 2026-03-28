/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (62.23%)
 * Likes:    13979
 * Dislikes: 702
 * Total Accepted:    1.2M
 * Total Submissions: 1.9M
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * Given an encoded string, return its decoded string.
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * You may assume that the input string is always valid; there are no extra
 * white spaces, square brackets are well-formed, etc. Furthermore, you may
 * assume that the original data does not contain any digits and that digits
 * are only for those repeat numbers, k. For example, there will not be input
 * like 3a or 2[4].
 * 
 * The test cases are generated so that the length of the output will never
 * exceed 10^5.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "3[a]2[bc]"
 * Output: "aaabcbc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "3[a2[c]]"
 * Output: "accaccacc"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "2[abc]3[cd]ef"
 * Output: "abcabccdcdcdef"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 30
 * s consists of lowercase English letters, digits, and square brackets
 * '[]'.
 * s is guaranteed to be a valid input.
 * All the integers in s are in the range [1, 300].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        std::string result;
        std::string stack;
        for(const auto& ch : s) {
            if(stack.empty()) {
                // 栈为空时，数字字符进入栈，其它字符进入最终结果
                if(isDigit(ch))
                    stack.push_back(ch);
                else
                    result.push_back(ch);
            }
            else if(ch != ']')
                // 栈非空时，除了右方括号，其它字符全部入栈
                stack.push_back(ch);
            else {
                // 栈非空时，遇到了右方括号，处理重复字符串
                std::string repeat_str;
                while(stack.back() != '[') {
                    // 取出左方括号之前的所有字符串，用于后续重复
                    repeat_str.insert(repeat_str.begin(), stack.back());
                    stack.pop_back();
                }
                // 弹出左方括号
                stack.pop_back();

                std::string repeat_times;
                while(!stack.empty() && isDigit(stack.back())) {
                    // 取出左方括号之前的数字字符串，用于后续重复
                    repeat_times.insert(repeat_times.begin(), stack.back());
                    stack.pop_back();
                }
                int times = std::stoi(repeat_times);

                // 取出数字后，如果栈已空，则重复的结果可以直接写入结果字符串
                // 如果栈非空，需要将重复字符串重新入栈，用于继续重复
                auto& target_str = stack.empty() ? result : stack; 
                for(int i = 0; i < times; i++)
                    target_str.append(repeat_str);
            }
        }

        return result;
    }

    inline bool isDigit(const auto& ch) {
        return ch >= '0' && ch <= '9';
    }
};
// @lc code=end

