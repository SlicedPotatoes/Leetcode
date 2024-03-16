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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Vérifier si l'une des listes est vide, dans ce cas, retourner l'autre liste car elle est déjà triée.
        if (!list2)
        {
            return list1;
        }
        if (!list1)
        {
            return list2;
        }

        // Initialiser la tête de la liste fusionnée (une nouvelle liste) et un pointeur pour parcourir cette liste.
        ListNode *mergedListHead = new ListNode(); // Création du premier élément fictif.
        ListNode *currentML = mergedListHead;

        // Parcourir les deux listes tant qu'il y a des éléments dans les deux.
        while (list1 && list2)
        {
            // Comparer les valeurs des noeuds actuels des deux listes et insérer le plus petit dans la liste fusionnée.
            if (list1->val <= list2->val)
            {
                currentML->next = list1;
                list1 = list1->next; // Avancer dans la liste 1.
            }
            else
            {
                currentML->next = list2;
                list2 = list2->next; // Avancer dans la liste 2.
            }
            currentML = currentML->next; // Avancer dans la liste fusionnée.
        }

        // Une fois qu'une des listes est entièrement parcourue, il reste à attacher le reste de l'autre liste à la
        // liste fusionnée.
        if (list1)
        {
            currentML->next = list1;
        }
        else if (list2)
        {
            currentML->next = list2;
        }

        // Retourner la tête de la liste fusionnée (en sautant le premier élément fictif).
        return mergedListHead->next;
    }
};