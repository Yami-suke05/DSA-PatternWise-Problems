#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target){
        int n = nums.size();
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-2; i++){
            int requiredSum = target - nums[i];
            int low = i+1;
            int high = n-1;

            while(low < high){
                int Sum = nums[low] + nums[high];
                if(Sum >= requiredSum){
                    high--;
                }
                else{
                    cnt+=(high-low);
                    low++;
                }
            }

        }
        return cnt;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {-2, 0, 1, 3};
    int targetNumber = 2;

    int result = sol.threeSumSmaller(arr, targetNumber);
    cout << result << endl;
    return 0;
}