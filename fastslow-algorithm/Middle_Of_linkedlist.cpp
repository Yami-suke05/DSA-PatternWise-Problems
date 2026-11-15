#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNodeFirst(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Condition adjusted to stop one step early for even-length lists
        //We can adjust it to stop it at correct plac as well //
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;     
            fast = fast->next->next;     

            if(slow == fast){
                return nullptr;
            }
        }

        // Returns the first/previous middle node
        return slow;
    }
};

int main() {
    Solution sol;

    // Creating an even-length linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // The two middles are 3 and 4. This code should return 3!
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode* middle = sol.middleNodeFirst(head);

    if (middle != nullptr) {
        cout << "First middle node value: " << middle->val << endl; // Should output 3
    }

    return 0;
}