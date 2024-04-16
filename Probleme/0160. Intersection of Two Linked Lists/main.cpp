/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        // Parcourir les deux listes pour trouver leur taille
        int sizeA = 0;
        int sizeB = 0;
        ListNode *currA = headA;
        ListNode *currB = headB;

        while (currA && currA->next)
        {
            sizeA++;
            currA = currA->next;
        }

        while (currB && currB->next)
        {
            sizeB++;
            currB = currB->next;
        }

        // Vérifié si les listes ont le même noeud de fin
        if (currA != currB)
        {
            return nullptr;
        }

        // Réinitialiser les pointeurs au début des listes
        currA = headA;
        currB = headB;

        // Ajuster les pointeurs pour qu'ils aient la même distance de la fin
        if (sizeA > sizeB)
        {
            for (int i = sizeA - sizeB; i > 0; i--)
            {
                currA = currA->next;
            }
        }
        else if (sizeB > sizeA)
        {
            for (int i = sizeB - sizeA; i > 0; i--)
            {
                currB = currB->next;
            }
        }

        // Parcourir les deux listes jusqu'à trouver le noeud d'intersection
        while (currA != currB)
        {
            currA = currA->next;
            currB = currB->next;
        }

        // Retourner le noeud d'intersection
        return currA;
    }
};