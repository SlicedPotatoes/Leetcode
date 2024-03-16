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
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Vérifier si la liste est vide
        if (!head)
        {
            // Si la liste est vide, il n'y a pas de doublons à supprimer
            return head;
        }

        // Initialisation du pointeur current pour parcourir la liste
        ListNode *current = head;

        // Parcourir la liste jusqu'à ce que le noeud suivant soit nul (fin de la liste)
        while (current->next)
        {
            // Vérifier si la valeur du noeud actuel est égale à la valeur du prochain noeud
            if (current->val == current->next->val)
            {
                // Si les valeurs sont égales, supprimer le prochain noeud en le liant au noeud suivant
                current->next = current->next->next;
                // Passer au prochain noeud sans avancer current
                continue;
            }
            // Avancer current au noeud suivant dans la liste
            current = current->next;
        }

        return head;
    }
};