#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        
        while (left < right) {
            if (arr[left] == 0) {
                left++;
            }
            else if (arr[right] == 1) {
                right--;
            }
            else {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
    }
};

int main (){
    Solution sol;
    vector<int> arr = {0,1,0,1,1,0,1,0,0,1};
    sol.segregate0and1(arr);
    cout << "Segregated array:";
    for (int num : arr){
        cout << num << " ";
    }

    cout << endl;
    return 0;

}