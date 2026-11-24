#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if (st.empty()) {
                result[i] = 0;
            }
            else {
                result[i] = st.top() - i;
            }
            st.push(i);
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};

    cout << "Temperatures: ";
    for (int x : temperatures) cout << x << " ";
    cout << endl;

    vector<int> output = sol.dailyTemperatures(temperatures);

    cout << "Days until warmer temperature: ";
    for (int x : output) cout << x << " ";
    cout << endl;

    return 0;
}
