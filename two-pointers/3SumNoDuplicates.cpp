#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n-2; i++){

            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;

            int target = -1*nums[i];
            int low = i+1;
            int high = n-1;
            
            while(low < high){
                int sum = nums[low]+nums[high];
                if(sum == target){
                    result.push_back({nums[i], nums[low], nums[high]});
                    while(low < high && nums[low] == nums[low+1] ){
                        low++;
                    }
                    while(low < high && nums[high] == nums[high-1]){
                        high--;
                    }
                    low++;
                    high--;
                }
                else if(sum > target) {
                    high --;
                }
                else{
                    low++;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    
    vector<vector<int>> ans = sol.threeSum(nums);
    
    cout << "Triplets found:\n";
    for(const auto& triplet : ans) {
        cout << "[ ";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}