// Time complexity: O(N^2)
// Space complexity: O(1)
/*
1. List all combination: O(N^2)
babad
^
|^|
 |^|
   ^
    ^
2. DP: O(N^2)
P(i, j) = true  if substring Si...Sj is Palindromic
         false  otherwise
-> P(i, j) = (P(i+1, j-1) and Si+1 == Sj-1)

Base case
P(i, i) = true
P(i, i+1) = true  if Si == Si+1
*/
class Solution {
    int palindromeLength(string& s, int centerL, int centerR) {
        while (centerL >= 0 && centerR < s.size() && s[centerL] == s[centerR]) {
            centerL--;
            centerR++;
        }
        return centerR - centerL - 1;
    }
public:
    string longestPalindrome(string s) {
        int begin = 0, end = -1;
        for (int i = 0; i < s.size(); i++) {
            int len = max(palindromeLength(s, i, i+1), palindromeLength(s, i, i));
            // cout << i << " " << len << endl;
            if (len > end - begin + 1) {
                begin = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return string(s.begin() + begin, s.begin() + end + 1);
    }
};
// DP
// Time complexity: O(N^2)
// Space complexity: O(N^2)
// N: length of s
class Solution {
 public:
  string longestPalindrome(string s) {
    // dp(i, j): have palindrome in s[i, j]
    // dp(i, j) =
    // true if i == j
    // dp(i+1, j-1) if s[i] == s[j] and i + 1 != j
    // true if s[i] == s[j] and i + 1 == j
    // false if s[i] != s[j]
    int N = s.size(), maxLen = 0, maxBegin = 0, maxEnd = 0;
    vector<vector<bool>> dp(N, vector<bool>(N, false));

    // init dp
    for (int i = 0; i < N; i++) dp[i][i] = true;

    for (int i = N - 2; i >= 0; i--) {
      for (int j = i + 1; j < N; j++) {
        if (s[i] == s[j]) {
          if (i + 1 != j) {
            dp[i][j] = dp[i + 1][j - 1];
          } else {
            dp[i][j] = true;
          }
          if (j - i > maxLen && dp[i][j]) {
            maxBegin = i;
            maxEnd = j;
            maxLen = j - i;
          }
        }
      }
    }

    return string(s.begin() + maxBegin, s.begin() + maxEnd + 1);
  }
};

// Brute force
// Time complexity: O(N^3)
// Space complexity: O(1)
// N: length of s
string longestPalindrome(string s) {
  auto longest = string(1, s[0]);
  for (int windowSize = s.size(); windowSize > 1; --windowSize) {
    int left = 0, right = windowSize - 1;
    bool odd = (right - left + 1) % 2;
    while (right < s.size()) {
      int mid = (right + left) / 2;
      // is even
      int checkl = mid, checkr = mid + 1;
      if (odd) checkl = mid - 1;
      while (checkr <= right) {
        if (s[checkl] != s[checkr]) break;
        if (checkr == right) {
          return string(s.begin() + left, s.begin() + right + 1);
        }
        ++checkr;
        --checkl;
      }
      ++right;
      ++left;
    }
  }
  return longest;
}