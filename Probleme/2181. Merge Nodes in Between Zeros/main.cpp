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
    ListNode *mergeNodes(ListNode *head)
    {
        int sum = 0;                                // Variable pour accumuler les valeurs entre les zéros
        ListNode *curr = head->next;                // Pointeur pour parcourir la liste à partir du deuxième noeud
        ListNode *currAns = new ListNode(-1, head); // Pointeur pour la nouvelle liste

        while (curr)
        {
            if (curr->val == 0)
            {
                // Lorsque nous rencontrons un noeud avec la valeur 0, nous définissons la valeur du noeud suivant dans
                // currAns avec la somme accumulée
                currAns->next->val = sum;
                // Nous réutilisons le noeud actuel (qui a la valeur 0) pour le lien suivant
                currAns->next->next = curr;
                currAns = currAns->next; // Avancer à la prochaine position
                sum = 0;                 // Réinitialiser la somme
            }
            else
            {
                // Sinon, nous ajoutons la valeur du noeud courant à la somme
                sum += curr->val;
            }
            curr = curr->next; // Passer au noeud suivant
        }

        // Finalement, nous mettons le pointeur suivant de currAns à nullptr
        currAns->next = nullptr;

        return head; // Retourner la tête de la liste modifiée
    }
};