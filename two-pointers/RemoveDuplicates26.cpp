#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0;
        for(int j = 1; j < n; j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4};
    
    cout << "Original array: ";
    for(int val : nums) {
        cout << val << " ";
    }
    cout << endl;

    int k = solution.removeDuplicates(nums);

    cout << "Number of unique elements (k): " << k << endl;
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < k; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}