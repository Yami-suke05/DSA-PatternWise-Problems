#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int low = 0;
        int high = n - 1;
        while(low < high){
            int sum = numbers[low] + numbers[high];
            if(sum == target) {
                return {low + 1, high + 1};
            }
            else if(sum < target){
                low++;
            }
            else{
                high--;
            }
        }
        return {};
    }
};

// --- THIS MAIN FUNCTION IS REQUIRED TO RUN IT LOCALLY ---
int main() {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = solution.twoSum(numbers, target);

    cout << "Indices: ";
    for(int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}