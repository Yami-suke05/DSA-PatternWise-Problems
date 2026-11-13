#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if (k <= 1) return 0;
        int currentproduct = 1;
        int l = 0;
        int cnt = 0;

        for(int r = 0; r < n; r++){
            currentproduct *= nums[r];
            while(currentproduct >= k && l <= r){
                currentproduct /= nums[l];
                l++;
            }
            cnt += (r - l + 1);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    
    int result = sol.numSubarrayProductLessThanK(nums, k);
    
    cout << "Number of subarrays with product less than " << k << " is: " << result << endl;
    
    return 0;
}