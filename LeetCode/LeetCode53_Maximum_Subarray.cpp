// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      nums[i] += nums[i - 1] > 0 ? nums[i - 1] : 0;
      ans = max(ans, nums[i]);
    }
    return ans;
  }
};
// Time complexity: O(N)
// Space complexity: O(1)
// N: size of nums
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] > 0) {
        nums[i] += nums[i - 1];
      }
    }
    return *max_element(nums.begin(), nums.end());
  }
};