/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  public:
    ListNode *doubleIt(ListNode *head)
    {
        // REVERSE
        ListNode *prev = nullptr;
        ListNode *curr = head;

        while (curr)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;

        // X2 + REVERSE

        bool carry = false;
        prev = nullptr;
        curr = head;

        while (curr)
        {
            // X2
            curr->val = curr->val * 2 + carry;
            carry = curr->val >= 10;
            curr->val %= 10;

            // REVERSE
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head = prev;

        if (carry)
        {
            return new ListNode(1, head);
        }
        return head;
    }
};