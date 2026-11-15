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
    bool hasCycle(ListNode *head) {
        // Base case: if the list is empty or has only one node without a cycle
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        // Fast pointer moves 2 steps, slow pointer moves 1 step
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps

            // If they meet, there is a cycle
            if (slow == fast) {
                return true;
            }
        }

        // If fast reaches the end (nullptr), there is no cycle
        return false;
    }
};

int main() {
    Solution sol;

    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating the cycle (pointing the last node back to the second node)
    head->next->next->next->next = head->next;

    if (sol.hasCycle(head)) {
        cout << "Cycle detected in the linked list!" << endl;
    } else {
        cout << "No cycle found in the linked list." << endl;
    }

    return 0;
}