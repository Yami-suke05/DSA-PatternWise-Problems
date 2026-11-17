#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int max_end = nums[0];
        int min_end = nums[0];
        int res = nums[0];

        for (int i = 1; i < n; i++) {
            int v1 = nums[i];
            int v2 = max_end * nums[i];
            int v3 = min_end * nums[i];

            max_end = max(v1, max(v2, v3));
            min_end = min(v1, min(v2, v3));

            res = max(res, max(max_end, min_end));
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 3, -2, 4};

    cout << "Array: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    int result = sol.maxProduct(nums);
    cout << "Maximum Product Subarray: " << result << endl;

    return 0;
}