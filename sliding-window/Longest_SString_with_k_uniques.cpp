#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestKSubstr(string &s, int k) {
        int n = s.length();
        int low = 0;
        unordered_map<char, int> charCount;
        int maxlen = -1; // Returns -1 if no such substring exists
        
        for(int high = 0; high < n; high++){
            charCount[s[high]]++;
            
            while(charCount.size() > k){
                charCount[s[low]]--;
                
                if(charCount[s[low]] == 0){
                    charCount.erase(s[low]);
                }
                low++;
            }
            
            if(charCount.size() == k){
                int len = high - low + 1;
                maxlen = max(maxlen, len);
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    
    // Test case
    string s = "aabacbebebe";
    int k = 3;

    int result = sol.longestKSubstr(s, k);
    
    cout << "String: " << s << endl;
    cout << "K: " << k << endl;
    cout << "Longest Substring Length: " << result << endl;

    return 0;
}