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
    // Fonction pour inverser la liste chaînée après le nœud donné
    void reverse(ListNode *head)
    {
        ListNode *curr = head->next;
        ListNode *prev = nullptr;

        while (curr->next)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Mise à jour du lien entre le début de la liste et le reste après inversion
        head->next = curr;
        curr->next = prev;
    }

    bool isPalindrome(ListNode *head)
    {
        // Si la liste a un seul élément, elle est considérée comme un palindrome
        if (!head->next)
        {
            return true;
        }

        ListNode *ptr1 = head;
        ListNode *ptr2 = head->next;

        // Trouver le milieu de la liste en utilisant la technique du pointeur rapide et lent
        while (ptr2 && ptr2->next)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next->next;
        }

        // Inverser la deuxième moitié de la liste à partir du milieu
        reverse(ptr1);

        // Comparer la première moitié avec la deuxième moitié
        ptr2 = head;
        while (ptr1->next)
        {
            ptr1 = ptr1->next;
            if (ptr1->val != ptr2->val)
            {
                // Si une différence est trouvée, la liste n'est pas un palindrome
                return false;
            }
            ptr2 = ptr2->next;
        }

        // Si toutes les valeurs correspondent, la liste est un palindrome
        return true;
    }
};