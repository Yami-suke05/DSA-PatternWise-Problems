#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubarraySum(vector<int> &arr) {
        int bestending = arr[0];
        int ans = arr[0];
        int n = arr.size();

        for (int i = 1; i < n; i++) {
            int v1 = bestending + arr[i];
            int v2 = arr[i];

            bestending = min(v1, v2);
            ans = min(ans, bestending);
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {3, -4, 2, -3, -1, 7, -5};

    cout << "Array: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    int result = sol.minSubarraySum(arr);
    cout << "Minimum Subarray Sum: " << result << endl;

    return 0;
}