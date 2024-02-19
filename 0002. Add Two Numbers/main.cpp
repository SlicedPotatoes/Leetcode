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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *result = new ListNode(); // Création d'une liste chaînée pour stocker les résultats.
        ListNode *currentNode = result;    // Le noeud courant de la liste chaînée.
        int leftover = 0;                  // Stocke la retenue de l'opération en cours.

        // Effectue l'addition en parcourant la liste chaînée.
        while (true)
        {
            // Valeur de l'élément courant dans la liste chaînée initialisée à zéro.
            int l1Value = 0;
            int l2Value = 0;

            // Si l'élément de la liste chaînée n'est pas nul, on récupère sa valeur et change le pointeur de l'élément
            // courant.
            if (l1 != nullptr)
            {
                l1Value = l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                l2Value = l2->val;
                l2 = l2->next;
            }

            // On effectue l'addition avec la retenue.
            int sum = l1Value + l2Value + leftover;

            // On calcule la prochaine retenue.
            if (sum >= 10)
            {
                leftover = 1;
                sum -= 10;
            }
            else
            {
                leftover = 0;
            }

            // Ajout du résultat à la liste chaînée de sortie.
            currentNode->val = sum;
            if (l1 != nullptr || l2 != nullptr)
            {
                currentNode->next = new ListNode();
                currentNode = currentNode->next;
            }
            else
            {
                // Si une retenue est présente à la fin, on crée un nouveau noeud pour l'ajouter.
                if (leftover == 1)
                {
                    currentNode->next = new ListNode();
                    currentNode = currentNode->next;
                    currentNode->val = 1;
                }
                // Fin du traitement, sortie de la boucle.
                break;
            }
        }

        return result;
    }
};