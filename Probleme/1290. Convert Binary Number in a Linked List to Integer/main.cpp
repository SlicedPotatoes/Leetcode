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
    int getDecimalValue(ListNode *head)
    {
        // Initialisation de la variable pour stocker la valeur décimale
        int n = 0;

        // Parcours de la liste chaînée tant que le pointeur head n'est pas nul
        while (head)
        {
            // Décalage binaire à gauche de n pour faire de la place pour le prochain bit
            n <<= 1;
            // Ajout de la valeur du bit actuel de la liste chaînée à n
            n += head->val;
            // Déplacement du pointeur vers le prochain élément de la liste chaînée
            head = head->next;
        }
        // Retourne la valeur décimale calculée
        return n;
    }
};