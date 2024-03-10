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
    // Fonction récursive pour supprimer le n-ième élément en partant de la fin d'une liste chaînée
    int remove(ListNode *h, int n)
    {
        // Vérifier si on est arrivé au dernier élément de la liste
        if (h->next == nullptr)
        {
            // Si oui, retourner 1 pour indiquer que c'est le dernier élément
            return 1;
        }

        // Appel récursif pour avancer dans la liste et trouver le n-ième élément en partant de la fin
        int c = remove(h->next, n);
        // Si on a trouvé le n-ième élément en partant de la fin
        if (c == n)
        {
            // Vérifier si le n-ième élément est le dernier élément de la liste
            if (h->next->next == nullptr)
            {
                // Si oui, le supprimer en le déréférençant
                h->next = nullptr;
            }
            else
            {
                // Sinon, supprimer le n-ième élément en ajustant les pointeurs
                h->next = h->next->next;
            }
        }
        // Retourner le compteur actuel
        return c + 1;
    }

    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // Appeler la fonction remove pour supprimer le n-ième élément en partant de la fin
        if (remove(head, n) == n)
        {
            // Si l'élément à supprimer est le premier de la liste, retourner le deuxième élément
            return head->next;
        }
        // Si l'élément à supprimer n'est pas le premier, retourner la tête de la liste inchangée
        return head;
    }
};