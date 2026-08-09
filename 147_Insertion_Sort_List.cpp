
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
          if (head == nullptr || head->next == nullptr)
            return head;

        // Dummy node to simplify insertion at the beginning
        ListNode* dummy = new ListNode(0);

        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;

            // Find the correct position
            ListNode* prev = dummy;

            while (prev->next != nullptr &&
                   prev->next->val < curr->val) {
                prev = prev->next;
            }

            // Insert curr into sorted list
            curr->next = prev->next;
            prev->next = curr;

            curr = nextNode;
        }

        ListNode* result = dummy->next;
        delete dummy;

        return result;
    }
};