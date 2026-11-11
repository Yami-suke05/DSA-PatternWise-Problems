#include <iostream>
#include <vector>
#include <cmath> // Required for abs()

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0;
        int right = n - 1;
        int index = n - 1; // Fill the result array from back to front

        while (left <= right) {
            // Using abs() to compare the magnitudes of extreme ends
            if (abs(nums[left]) > abs(nums[right])) {
                result[index] = nums[left] * nums[left];
                left++;
            } else {
                result[index] = nums[right] * nums[right];
                right--;
            }
            index--;
        }

        return result;
    }
};

int main() {
    Solution solution;
    
    // Test case with negative and positive numbers
    vector<int> nums = {-4, -1, 0, 3, 10};
    
    cout << "Original array: ";
    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> result = solution.sortedSquares(nums);

    cout << "Sorted squares array: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}