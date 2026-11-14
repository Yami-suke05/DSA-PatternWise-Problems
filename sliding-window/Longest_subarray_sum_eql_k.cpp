#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public : 
    int LongestSubarraySum(vector<int> &nums, int k){
        int n = nums.size();
        int low = 0;
        int maxlen = -1;
        int sum = 0;
        for(int high = 0; high<n; high++){
            sum+= nums[high];
            while(sum > k){
                sum= sum-nums[low];
                low++;
            }

            if(sum == k){
                maxlen = max(maxlen, high - low+1);
            }
        }
        return maxlen ;
    }
};

int main() {
    Solution sol;
    
    // Test case (Note: sliding window for exact sum works best with non-negative numbers)
    vector<int> nums = {1, 2, 3, 1, 1, 1, 1};
    int k = 3;

    int result = sol.LongestSubarraySum(nums, k);
    
    cout << "Longest Subarray Length with Sum " << k << ": " << result << endl;

    return 0;
}