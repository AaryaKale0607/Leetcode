
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
    ListNode* sortList(ListNode* head) {
          // Base case
        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle of the list
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list into two halves
        prev->next = nullptr;

        // Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        // Merge the sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (left != nullptr && right != nullptr) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }

            curr = curr->next;
        }

        // Attach remaining nodes
        if (left != nullptr)
            curr->next = left;
        else
            curr->next = right;

        return dummy.next;
    }
};