#include <iostream>

using namespace std;

class Solution {
private:
    int getNext(int n) {
        int totalsum = 0;
        while (n > 0) {
            int d = n % 10;
            totalsum += d * d;
            n = n / 10;
        }
        return totalsum;
    }

public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while (fast != 1) {
            slow = getNext(slow);
            fast = getNext(fast);
            fast = getNext(fast);

            if (slow == fast && slow != 1) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    int n = 19;
    cout << boolalpha << sol.isHappy(n) << endl;
    return 0;
}