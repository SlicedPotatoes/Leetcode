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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        // Trouver le noeud précédant la zone d'insertion
        ListNode *start = list1;
        for (int i = 1; i < a; i++)
        {
            start = start->next;
        }

        // Trouver le noeud suivant la zone d'insertion
        ListNode *end = start->next;
        for (int i = a; i <= b; i++)
        {
            end = end->next;
        }

        // Trouver le noeud suivant la zone d'insertion
        ListNode *endList2 = list2;
        while (endList2->next)
        {
            endList2 = endList2->next;
        }

        // Relier la fin de la première section à list2
        start->next = list2;
        // Relier la fin de list2 à la suite de la section
        endList2->next = end;

        // Retourner la liste résultante
        return list1;
    }
};