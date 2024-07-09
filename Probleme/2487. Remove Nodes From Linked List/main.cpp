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
    // Fonction récursive pour traiter la liste chaînée
    ListNode *process(ListNode *head)
    {
        // Si c'est le dernier nœud, le retourner
        if (!head->next)
        {
            return head;
        }

        // Appel récursif sur le nœud suivant
        ListNode *currentHead = process(head->next);

        // Si la valeur du nœud courant est supérieure ou égale à celle du nœud suivant
        if (head->val >= currentHead->val)
        {
            // Conserver le lien vers le nœud suivant
            head->next = currentHead;
            return head;
        }

        // Sinon, ne pas inclure le nœud courant dans la nouvelle liste
        return currentHead;
    }

    ListNode *removeNodes(ListNode *head)
    {
        return process(head);
    }
};