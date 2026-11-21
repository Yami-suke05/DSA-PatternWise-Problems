#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public :
    int MaxSumSubarray(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int sum = 0;
        int maxsum = INT_MIN;

        for(int high = 0; high < n; high++){
            sum+=nums[high];

            while(sum > target && low <= high){
                sum = sum-nums[low];
                low++;
            }
            maxsum = max(maxsum , sum);
        }
        return maxsum;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1,2,3,4,5,6,7};
    int target = 11;

    int result = sol.MaxSumSubarray(arr,target);
    cout << "The Maxlen of Subarray with sum less than or equal to target is = ";
    cout << result << endl;
}