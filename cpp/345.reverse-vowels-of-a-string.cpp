/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (60.55%)
 * Likes:    5336
 * Dislikes: 2859
 * Total Accepted:    1.6M
 * Total Submissions: 2.6M
 * Testcase Example:  '"IceCreAm"'
 *
 * Given a string s, reverse only all the vowels in the string and return it.
 * 
 * The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both
 * lower and upper cases, more than once.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "IceCreAm"
 * 
 * Output: "AceCreIm"
 * 
 * Explanation:
 * 
 * The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes
 * "AceCreIm".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "leetcode"
 * 
 * Output: "leotcede"
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s consist of printable ASCII characters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int length = s.size();
        int left = 0;
        int right = length - 1;
        while(left < right) {
            while(left < length && !isVowels(s[left]))
                left++;
            while(right >= 0 && !isVowels(s[right]))
                right--;
            if(left < length && right >= 0 && left < right) {
                char tmp = s[left];
                s[left] = s[right];
                s[right] = tmp;
                left++;
                right--;
            }
        }
        return s;
    }

    bool isVowels(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            return true;
        return false;
    }
};
// @lc code=end

