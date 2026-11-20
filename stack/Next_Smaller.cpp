#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
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

    vector<int> arr = {4, 8, 5, 2, 25};

    cout << "Input: ";
    for (int x : arr) cout << x << " ";
    cout << endl;

    vector<int> output = sol.nextSmallerEle(arr);

    cout << "Next Smaller Elements: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}
