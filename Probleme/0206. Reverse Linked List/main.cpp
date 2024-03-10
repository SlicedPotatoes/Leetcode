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
    ListNode *reverseList(ListNode *head)
    {
        // Initialisation de deux pointeurs, current pointe vers le début de la liste
        // et n pointe vers l'élément précédant l'élément courant pendant l'itération.
        ListNode *current = head;
        ListNode *n = nullptr;

        // Boucle tant que le pointeur current ne pointe pas vers un élément vide (nullptr)
        while (current)
        {
            // Stockage temporaire du pointeur vers le prochain élément dans la liste non inversée
            ListNode *temp = current->next;
            // Inversion du lien vers le prochain élément en faisant pointer l'élément courant vers n
            current->next = n;
            // Mise à jour de n pour qu'il pointe vers l'élément courant
            n = current;
            // Avancer current au prochain élément dans la liste non inversée
            current = temp;
        }

        // À la fin de la boucle, n pointe vers le début de la liste inversée
        // Donc, on le retourne pour renvoyer la liste inversée
        return n;
    }
};