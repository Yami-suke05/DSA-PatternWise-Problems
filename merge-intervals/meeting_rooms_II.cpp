#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int n = start.size();
        int i = 0;
        int j = 0;
        int room = 0;
        int maxRooms = 0;

        while (i < n) {
            if (start[i] < end[j]) {
                room++;
                i++;
            }
            else {
                room--;
                j++;
            }
            maxRooms = max(maxRooms, room);
        }
        return maxRooms;
    }
};

int main() {
    Solution sol;

    vector<int> start = {0, 5, 15};
    vector<int> end = {30, 10, 20};

    cout << "Start times: ";
    for (int s : start) cout << s << " ";
    cout << endl;

    cout << "End times:   ";
    for (int e : end) cout << e << " ";
    cout << endl;

    int result = sol.minMeetingRooms(start, end);
    cout << "Minimum Meeting Rooms Required: " << result << endl;

    return 0;
}