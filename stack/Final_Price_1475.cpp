#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> result(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            // Pop strictly greater prices; keep the first price <= prices[i]
            while (!st.empty() && st.top() > prices[i]) {
                st.pop();
            }

            if (st.empty()) {
                result[i] = prices[i];
            } else {
                result[i] = prices[i] - st.top();
            }

            st.push(prices[i]);
        }

        return result;
    }
};

int main() {
    Solution sol;

    vector<int> prices = {8, 4, 6, 2, 3};

    cout << "Original Prices: ";
    for (int p : prices) cout << p << " ";
    cout << endl;

    vector<int> discounted = sol.finalPrices(prices);

    cout << "Final Prices:    ";
    for (int p : discounted) cout << p << " ";
    cout << endl;

    return 0;
}