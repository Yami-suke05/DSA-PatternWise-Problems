#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestsum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++){
            // check for the duplicates
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int requiredPairSum = target - nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high){
                int pairsum = nums[low] + nums[high];
                int currenttotal = nums[i] + nums[low] + nums[high];

                if(abs(target - currenttotal) < abs(target - closestsum)){
                    closestsum = currenttotal;
                }
                if (pairsum == requiredPairSum) {
                    return currenttotal;
                }
                else if (pairsum > requiredPairSum) {
                    high--;
                }
                else {
                    low++; // Since it's neither equal nor greater, it MUST be smaller!
                }
            }
        }
        return closestsum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;

    int result = sol.threeSumClosest(nums, target);
    
    cout << "The closest sum is: " << result << endl;

    return 0;
}