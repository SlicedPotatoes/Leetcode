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
    ListNode *middleNode(ListNode *head)
    {
        // Initialisation de deux pointeurs, fast et slow, au début de la liste
        ListNode *fast = head; // Pointeur rapide qui avance de 2 éléments à la fois
        ListNode *slow = head; // Pointeur lent qui avance de 1 élément à la fois

        // Parcourt la liste tant que fast n'a pas atteint la fin et qu'il y a au moins deux éléments restants
        while (fast != nullptr && fast->next != nullptr)
        {
            // Avance le pointeur rapide de deux éléments
            fast = fast->next->next;
            // Avance le pointeur lent de un élément
            slow = slow->next;
        }

        // Une fois que fast a atteint la fin ou qu'il n'y a plus que un élément restant,
        // slow pointe vers le milieu de la liste
        return slow;
    }
};