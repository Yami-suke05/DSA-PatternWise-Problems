#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public :
    ListNode *detectCycle(ListNode *head){
        ListNode *slow = head ;
        ListNode *fast = head;

        while(fast->next != nullptr && fast->next->next !=nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;


    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating the cycle (pointing -4 back to 2)
    head->next->next->next->next = head->next;

    ListNode *cycleNode = sol.detectCycle(head);

    if (cycleNode != nullptr) {
        cout << "Cycle starts at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle found in the linked list." << endl;
    }

    return 0;
}