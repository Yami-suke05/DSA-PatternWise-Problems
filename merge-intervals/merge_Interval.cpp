#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int start_1 = intervals[0][0];
        int end_1 = intervals[0][1];

        vector<vector<int>> result;
        for (int i = 1; i < n; i++) {
            int start_2 = intervals[i][0];
            int end_2 = intervals[i][1];

            if (start_2 <= end_1) {
                start_1 = start_1;
                end_1 = max(end_1, end_2);
                continue;
            }
            result.push_back({start_1, end_1});
            start_1 = start_2;
            end_1 = end_2;
        }
        result.push_back({start_1, end_1});
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    cout << "Input Intervals: ";
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
