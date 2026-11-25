#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> result;
        int i = 0;
        int j = 0;

        while (i < n && j < m) {
            int start_1 = firstList[i][0];
            int end_1 = firstList[i][1];

            int start_2 = secondList[j][0];
            int end_2 = secondList[j][1];

            if (end_1 >= start_2 && end_2 >= start_1) {
                int start = max(start_1, start_2);
                int end = min(end_1, end_2);
                result.push_back({start, end});
            }

            if (end_1 < end_2) {
                i++;
            }
            else {
                j++;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> firstList = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};

    cout << "First List:  ";
    for (const auto& interval : firstList) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    cout << "Second List: ";
    for (const auto& interval : secondList) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    vector<vector<int>> intersections = sol.intervalIntersection(firstList, secondList);

    cout << "Intersections: ";
    for (const auto& interval : intersections) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
