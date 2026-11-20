#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        result[0] = -1;
        st.push(arr[0]);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                result[i] = -1;
            }
            else {
                result[i] = st.top();
            }
            st.push(arr[i]);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {4, 5, 3, 10, 8};

    cout << "Input: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> output = sol.prevSmaller(arr);

    cout << "Previous Smaller Elements: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}