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
    void reorderList(ListNode *head)
    {
        // Initialisation d'un pointeur lent à la tête de la liste
        ListNode *slow = head;
        // Initialisation d'un pointeur rapide à la deuxième position de la liste
        ListNode *fast = head->next;

        // Déplacement du pointeur rapide de deux positions à chaque itération et du pointeur lent d'une position
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Déclaration d'une pile pour stocker les noeuds de la deuxième moitié de la liste
        stack<ListNode *> stack;
        while (slow)
        {
            // Empile les noeuds de la deuxième moitié de la liste
            stack.push(slow);
            slow = slow->next;
        }

        // Pointeur actuel pour parcourir la première moitié de la liste
        ListNode *curr = head;

        // Réorganisation des noeuds en alternant entre les éléments de la première moitié et ceux de la pile
        while (!stack.empty() && curr != stack.top())
        {
            // Sauvegarde du prochain noeud de la première moitié de la liste
            ListNode *temp = curr->next;
            // Liaison du noeud actuel avec le noeud au sommet de la pile
            curr->next = stack.top();
            // Suppression du noeud au sommet de la pile
            stack.pop();
            // Reliaison du noeud au sommet de la pile avec le prochain noeud de la première moitié
            curr->next->next = temp;
            // Déplacement du pointeur actuel vers le prochain noeud de la première moitié de la liste
            curr = temp;
        }
        // La dernière partie de la liste est fixée à nullptr pour indiquer la fin de la liste
        curr->next = nullptr;
    }
};