#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public :
    int MinlenSubarray(vector<int> &nums, int target){
        int n = nums.size();
        int low = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for(int high = 0; high<n; high++){
            sum+= nums[high];

            while(sum >= target){
                minlen = min(minlen , high - low+1);
                low++;
                sum = sum-nums[low-1];
            }
        }
        return minlen;
    }
};

int main(){
    Solution sol;

    vector<int> arr = {2,3,1,2,4,3};
    int target = 7;
    int result = sol.MinlenSubarray(arr,target);
    cout<< "the minimum length of subarray whos sum greater or eqal to target is ";
    cout << result << endl;
}