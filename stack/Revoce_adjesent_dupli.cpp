#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        int n = s.length();
        string result = "";
        for (int i = 0; i < n; i++) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }

        while (!st.empty()) {
            char c = st.top();
            st.pop();
            result.push_back(c);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;

    string s = "abbaca";

    cout << "Input: " << s << endl;
    string output = sol.removeDuplicates(s);
    cout << "Output: " << output << endl;

    return 0;
}