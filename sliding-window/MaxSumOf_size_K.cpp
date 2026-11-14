#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public :
    int MaxSubarraySum(vector<int> & nums, int k){
        int n = nums.size();
        int left = 0;
        int right = k-1;
        int sum = 0;
        for (int i=0; i < k; i++){
            sum+=nums[i];
        }
        int maxsum = INT_MIN;
        while(right < n){
            maxsum = max(maxsum, sum);
            left++;
            right++;

            if(right == n) break;
            sum = sum-nums[left-1] + nums[right];
        }
        return maxsum;
    }

};

int main(){
    Solution sol;
    vector<int> arr = {100,200,300,400};
    int k = 2;
    cout << "Maximum sum of the subarray is " ;
    int result = sol.MaxSubarraySum(arr,k);
    cout << result << endl;
    return 0;
}