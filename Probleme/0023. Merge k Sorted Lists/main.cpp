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

// Foncteur utilisé pour comparer les noeuds dans la file de priorité
struct ListNodeSort
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // Utilisation d'une file de priorité pour trier les noeuds par valeur
        priority_queue<ListNode *, vector<ListNode *>, ListNodeSort> pq;

        // Ajout des têtes de liste initiales dans la file de priorité
        for (ListNode *head : lists)
        {
            if (head)
            {
                pq.push(head);
            }
        }

        // Création d'un noeud factice pour faciliter la construction de la liste fusionnée
        ListNode *answer = new ListNode(0);
        ListNode *current = answer;

        // Fusion des listes jusqu'à ce que la file de priorité soit vide
        while (!pq.empty())
        {
            current->next = pq.top(); // Ajout du noeud ayant la plus petite valeur actuelle
            pq.pop();                 // Suppression du noeud traité de la file de priorité
            current = current->next;  // Déplacement du pointeur courant
            if (current->next)
            {
                pq.push(current->next); // Ajout du prochain noeud de la liste dans la file de priorité
            }
        }

        return answer->next; // Retour de la liste fusionnée
    }
};