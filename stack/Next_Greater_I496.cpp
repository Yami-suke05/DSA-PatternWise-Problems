#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int, int> nextGreater;
        vector<int> result(n);
        stack<int> st;

        for (int i = m - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                nextGreater[nums2[i]] = -1;
            }
            else {
                nextGreater[nums2[i]] = st.top();
            }
            st.push(nums2[i]);
        }

        for (int j = 0; j < n; j++) {
            result[j] = nextGreater[nums1[j]];
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    cout << "nums1: ";
    for (int x : nums1) cout << x << " ";
    cout << endl;

    cout << "nums2: ";
    for (int x : nums2) cout << x << " ";
    cout << endl;

    vector<int> output = sol.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}
