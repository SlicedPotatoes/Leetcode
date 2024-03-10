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
    bool hasCycle(ListNode *head)
    {
        // Utilisation de l'algorithme du pointeur rapide et du pointeur lent pour détecter une boucle.
        ListNode *slow = head;
        ListNode *fast = head;

        // Parcourt la liste jusqu'à ce que le pointeur rapide atteigne la fin de la liste ou qu'il rencontre le
        // pointeur lent.
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next; // Le pointeur rapide avance de deux noeuds à la fois.
            slow = slow->next;       // Le pointeur lent avance d'un noeud à la fois.

            // Si le pointeur rapide et le pointeur lent pointent vers le même noeud à un certain moment, cela signifie
            // qu'il y a une boucle.
            if (fast == slow)
            {
                return true;
            }
        }
        // Si le pointeur rapide atteint la fin de la liste (nullptr), alors il n'y a pas de boucle.
        return false;
    }
};