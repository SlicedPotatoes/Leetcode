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
    // Fonction pour ajouter deux nombres représentés par des listes chaînées
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans = new ListNode(-1); // Nœud factice pour la liste résultat
        ListNode *currAns = ans;          // Pointeur pour construire la liste résultat

        ListNode *currL1 = l1; // Pointeur pour parcourir la première liste
        ListNode *currL2 = l2; // Pointeur pour parcourir la deuxième liste
        bool carry = false;    // Variable pour gérer la retenue

        // Parcours des deux listes tant qu'il y a des nœuds dans les deux
        while (currL1 && currL2)
        {
            int sum = currL1->val + currL2->val + (carry ? 1 : 0); // Somme des valeurs des nœuds et de la retenue
            carry = sum >= 10;                                     // Mise à jour de la retenue
            sum %= 10;                                             // Extraction de la dernière chiffre de la somme

            currAns->next = new ListNode(sum); // Création d'un nouveau nœud avec la somme
            currAns = currAns->next;           // Déplacement du pointeur de la liste résultat

            currL1 = currL1->next; // Déplacement du pointeur de la première liste
            currL2 = currL2->next; // Déplacement du pointeur de la deuxième liste
        }

        // Parcours des nœuds restants de la première liste, s'il y en a
        while (currL1)
        {
            int val = currL1->val + (carry ? 1 : 0);
            carry = val >= 10;
            val %= 10;

            currAns->next = new ListNode(val);
            currAns = currAns->next;

            currL1 = currL1->next;
        }

        // Parcours des nœuds restants de la deuxième liste, s'il y en a
        while (currL2)
        {
            int val = currL2->val + (carry ? 1 : 0);
            carry = val >= 10;
            val %= 10;

            currAns->next = new ListNode(val);
            currAns = currAns->next;

            currL2 = currL2->next;
        }

        // Si il y a une retenue après avoir parcouru les deux listes, ajouter un nouveau nœud
        if (carry)
        {
            currAns->next = new ListNode(1);
        }

        return ans->next; // Retourne la tête de la liste résultat en ignorant le nœud factice
    }
};