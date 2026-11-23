#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (st.empty()) {
                    result[i] = -1;
                }
                else {
                    result[i] = st.top();
                }
            }
            st.push(nums[i % n]);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 1};

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    vector<int> output = sol.nextGreaterElements(nums);

    cout << "Next Greater Elements (Circular): ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}
