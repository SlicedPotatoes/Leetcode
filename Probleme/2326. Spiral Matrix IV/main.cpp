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
    // Directions pour les mouvements en spirale : droite, bas, gauche, haut
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        // Initialisation de la matrice avec -1
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n, -1));

        // Position initiale dans la matrice
        int row = 0;
        int col = -1;

        // Indice de direction (0 = droite, 1 = bas, 2 = gauche, 3 = haut)
        int d = 0;

        // Pointeur sur le nœud courant de la liste
        ListNode *curr = head;

        // Remplir la matrice en spirale jusqu'à ce que la liste soit épuisée
        while (curr)
        {
            // Calculer la direction actuelle
            int currD = d % 4;

            // Déplacer vers la prochaine cellule
            row += dir[currD][0];
            col += dir[currD][1];

            // Vérifier les limites de la matrice et les cellules déjà remplies
            if (row < 0 || row == m || col < 0 || col == n || ans[row][col] != -1)
            {
                // Revenir à la position précédente
                row -= dir[currD][0];
                col -= dir[currD][1];

                // Changer de direction
                d++;
                currD = d % 4;

                // Déplacer vers la prochaine cellule dans la nouvelle direction
                row += dir[currD][0];
                col += dir[currD][1];
            }

            // Remplir la cellule courante avec la valeur du nœud
            ans[row][col] = curr->val;
            // Passer au nœud suivant dans la liste
            curr = curr->next;
        }

        return ans;
    }
};