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
    int sumOfLeftLeaves(TreeNode *root, bool isLeft = false)
    {
        // Vérifie si le noeud est nul, auquel cas il n'y a pas de feuilles à ajouter.
        if (!root)
        {
            return 0;
        }
        // Vérifie si le noeud est une feuille et si c'est un enfant gauche, alors retourne sa valeur.
        if (!root->left && !root->right)
        {
            return isLeft ? root->val : 0;
        }

        // Appelle récursivement sumOfLeftLeaves pour le sous-arbre gauche et le sous-arbre droit.
        // Ajoute les résultats de ces appels récursifs.
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right);
    }
};