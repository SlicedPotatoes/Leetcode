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
    ListNode *oddEvenList(ListNode *head)
    {
        // Vérifier si la liste est vide ou a un seul élément
        if (!head || (head && !head->next))
        {
            // Retourner la liste inchangée si elle est vide ou a un seul élément
            return head;
        }

        // Initialiser un pointeur pour le premier élément pair
        ListNode *even = head->next;

        // Initialiser des pointeurs pour les nœuds courants impair et pair
        ListNode *currOdd = head;
        ListNode *currEven = even;

        // Initialiser un pointeur pour parcourir la liste
        ListNode *curr = even->next;

        // Variable pour suivre si le prochain nœud est impair ou pair
        bool isOdd = true;

        // Parcourir la liste jusqu'à ce que le pointeur actuel atteigne la fin de la liste
        while (curr)
        {
            // Si le nœud actuel est impair
            if (isOdd)
            {
                // Ajouter le nœud actuel à la liste des nœuds impairs
                currOdd->next = curr;
                // Déplacer le pointeur du nœud courant impair
                currOdd = currOdd->next;
            }
            // Si le nœud actuel est pair
            else
            {
                // Ajouter le nœud actuel à la liste des nœuds pairs
                currEven->next = curr;
                // Déplacer le pointeur du nœud courant pair
                currEven = currEven->next;
            }

            // Inverser le statut de parité pour le prochain nœud
            isOdd = !isOdd;

            // Passer au nœud suivant dans la liste
            curr = curr->next;
        }

        // Relier la liste des nœuds impairs à celle des nœuds pairs
        currOdd->next = even;
        // Marquer la fin de la liste des nœuds pairs
        currEven->next = nullptr;

        // Retourner la tête de la liste
        return head;
    }
};