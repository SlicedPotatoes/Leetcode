/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
  public:
    int ans = 0;

    // Fonction de parcours en profondeur d'abord (DFS) pour calculer la somme des nombres formés par les chemins
    // racine-feuille
    void dfs(TreeNode *root, int curr)
    {
        // Si le noeud est nul, retourner
        if (!root)
        {
            return;
        }

        // Mise à jour du nombre actuel formé par le chemin racine-feuille
        curr *= 10;
        curr += root->val;

        // Si le noeud actuel est une feuille, ajouter le nombre formé à la somme totale
        if (!root->left && !root->right)
        {
            ans += curr;
        }

        // Appels récursifs pour les noeuds enfants gauche et droit
        dfs(root->left, curr);
        dfs(root->right, curr);
    }

    // Fonction principale pour calculer la somme des nombres formés par les chemins racine-feuille
    int sumNumbers(TreeNode *root)
    {
        // Appel de la fonction DFS avec le noeud racine et une valeur initiale de 0
        dfs(root, 0);
        // Retourner la somme calculée
        return ans;
    }
};