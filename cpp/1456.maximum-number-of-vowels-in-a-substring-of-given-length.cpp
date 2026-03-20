/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 *
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
 *
 * algorithms
 * Medium (61.49%)
 * Likes:    3934
 * Dislikes: 152
 * Total Accepted:    671K
 * Total Submissions: 1.1M
 * Testcase Example:  '"abciiidef"\n3'
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 * 
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s consists of lowercase English letters.
 * 1 <= k <= s.length
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maxVowels(string s, int k) {
        int max_vowels = 0;
        int left = 0;
        int right = 0;

        // 先初始化一个k大小的窗口
        while(right < k) {
            if(isVowelLetters(s[right]))
                max_vowels++;
            right++;
        }

        int cur_vowels = max_vowels;
        // 滑动窗口
        while(right < s.size()) {
            // 有元音字母移出窗口，减少计数
            if(isVowelLetters(s[left]))
                cur_vowels--;
            // 有元音字母进入窗口，增加计数
            if(isVowelLetters(s[right]))
                cur_vowels++;
            if(cur_vowels > max_vowels)
                max_vowels = cur_vowels;
            left++;
            right++;
        }
        
        return max_vowels;
    }

    inline bool isVowelLetters(const char& ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
// @lc code=end

