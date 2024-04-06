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
    TreeNode *invertTree(TreeNode *root)
    {
        // Vérifier si l'arbre est vide
        if (!root)
        {
            return nullptr;
        }

        // Inverser les sous-arbres gauche et droit de manière récursive
        swap(root->right, root->left);
        invertTree(root->right);
        invertTree(root->left);

        // Renvoyer la racine de l'arbre inversé
        return root;
    }
};