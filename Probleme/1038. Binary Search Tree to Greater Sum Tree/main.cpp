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
    // Fonction récursive pour convertir un BST en Greater Sum Tree
    void convertToGreaterTree(TreeNode *root, int &currSum)
    {
        // Si le noeud actuel est nul, on retourne
        if (!root)
        {
            return;
        }

        // Appel récursif sur le sous-arbre droit (les valeurs plus grandes)
        convertToGreaterTree(root->right, currSum);

        // Mise à jour de la valeur du noeud actuel en ajoutant la somme courante
        root->val += currSum;
        // Mise à jour de la somme courante avec la nouvelle valeur du noeud
        currSum = root->val;

        // Appel récursif sur le sous-arbre gauche (les valeurs plus petites)
        convertToGreaterTree(root->left, currSum);
    }

    // Fonction principale pour convertir un BST en Greater Sum Tree
    TreeNode *bstToGst(TreeNode *root)
    {
        int currSum = 0; // Initialisation de la somme courante à 0

        // Appel de la fonction récursive pour effectuer la conversion
        convertToGreaterTree(root, currSum);

        // Retourner la racine de l'arbre modifié
        return root;
    }
};