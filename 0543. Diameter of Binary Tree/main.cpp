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
    // Fonction récursive pour parcourir l'arbre et calculer le diamètre
    int dfs(TreeNode *node, int *result)
    {
        if (node == nullptr)
        {
            return 0; // Si le nœud est nul, le diamètre est 0
        }

        // Appel récursif pour obtenir les hauteurs des sous-arbres gauche et droit
        int dL = dfs(node->left, result);
        int dR = dfs(node->right, result);

        // Met à jour le résultat si la somme des hauteurs des sous-arbres gauche et droit est plus grande
        if (dL + dR > (*result))
        {
            (*result) = dL + dR;
        }

        // Retourne la hauteur maximale entre le sous-arbre gauche et le sous-arbre droit, plus 1 pour le noeud actuel
        return dL > dR ? dL + 1 : dR + 1;
    }
    // Fonction principale pour calculer le diamètre de l'arbre binaire
    int diameterOfBinaryTree(TreeNode *root)
    {
        int result = 0;     // Initialiser le résultat à 0
        dfs(root, &result); // Appel de la fonction de parcours de l'arbre récursif

        return result;
    }
};