#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public :
    int findDuplicate(vector<int> & nums){
        int n = nums.size();
        int fast = 0;
        int slow = 0;

        while(true){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];

            if(slow == fast){
                slow = 0;
                while(slow != fast){
                    slow = nums[slow];
                    fast = nums[fast];
                }
                return nums[slow] ;
            }
        }
        return -1;
    }
};
int main() {
    Solution sol;
    
    // Test case: The duplicate number is 2
    vector<int> nums = {1, 3, 4, 2, 2};

    int duplicate = sol.findDuplicate(nums);

    cout << "The duplicate number is: " << duplicate << endl; // Should output 2

    return 0;
}