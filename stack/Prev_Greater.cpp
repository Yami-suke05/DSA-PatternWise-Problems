#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        result[0] = -1;
        st.push(arr[0]);

        for (int i = 1; i < n; i++) {
            while (!st.empty() && st.top() <= arr[i]) {
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

    vector<int> arr = {10, 4, 2, 20, 40, 12, 30};

    cout << "Input: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> output = sol.preGreaterEle(arr);

    cout << "Previous Greater Elements: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}