#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestending = nums[0];
        int ans = nums[0];
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            int v1 = bestending + nums[i];
            int v2 = nums[i];

            bestending = max(v1, v2);
            ans = max(ans, bestending);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    int result = sol.maxSubArray(nums);
    cout << "Maximum Subarray Sum: " << result << endl;

    return 0;
}