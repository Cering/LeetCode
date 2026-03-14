/*
 * @lc app=leetcode id=1071 lang=cpp
 *
 * [1071] Greatest Common Divisor of Strings
 *
 * https://leetcode.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (53.37%)
 * Likes:    6002
 * Dislikes: 1656
 * Total Accepted:    931.4K
 * Total Submissions: 1.7M
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * For two strings s and t, we say "t divides s" if and only if s = t + t + t +
 * ... + t + t (i.e., t is concatenated with itself one or more times).
 * 
 * Given two strings str1 and str2, return the largest string x such that x
 * divides both str1 and str2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: str1 = "ABCABC", str2 = "ABC"
 * 
 * Output: "ABC"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: str1 = "ABABAB", str2 = "ABAB"
 * 
 * Output: "AB"
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: str1 = "LEET", str2 = "CODE"
 * 
 * Output: ""
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: str1 = "AAAAAB", str2 = "AAA"
 * 
 * Output: ""​​​​​​​
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= str1.length, str2.length <= 1000
 * str1 and str2 consist of English uppercase letters.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)
            return "";

        int gcd_len = std::gcd(str1.length(), str2.length());
        return str1.substr(0, gcd_len);
    }
};

class Solution2 {
public:
    string gcdOfStrings(string str1, string str2) {
        std::string result;

        // 寻找最大公共前缀
        auto it1 = str1.begin();
        auto it2 = str2.begin();
        while(it1 != str1.end() && it2 != str2.end() && *it1 == *it2) {
            result.push_back(*it1);
            it1++;
            it2++;
        }

        // 从最大公共前缀开始，逐步缩小，直到找到最大公因子
        while(!result.empty()) {
            if(isDivisible(str1, result) && isDivisible(str2, result))
                break;
            result.pop_back();
        }

        return result;
    }

    bool isDivisible(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        if(s_len % t_len != 0)
            return false;

        auto it = t.begin();
        for(const auto& c : s) {
            if(c != *it)
                return false;
            it++;
            if(it == t.end())
                it = t.begin();
        }
        return true;
    }
};
// @lc code=end

