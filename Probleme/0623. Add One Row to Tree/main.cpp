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
    // Fonction récursive pour ajouter une nouvelle rangée à l'arbre
    void addDFS(TreeNode *current, int currentNextDepth, int val, int targetDepth)
    {
        // Si la profondeur actuelle (currentNextDepth) correspond à la profondeur cible,
        // alors on insère un nouveau noeud avec la valeur donnée (val).
        if (currentNextDepth == targetDepth)
        {
            current->right = new TreeNode(val, nullptr, current->right);
            current->left = new TreeNode(val, current->left, nullptr);

            // On termine la fonction, puisqu'on a inséré les nouveaux noeuds.
            return;
        }

        // Sinon, on continue la descente dans l'arbre en explorant
        // les noeuds fils droit et gauche.
        if (current->right)
        {
            addDFS(current->right, currentNextDepth + 1, val, targetDepth);
        }
        if (current->left)
        {
            addDFS(current->left, currentNextDepth + 1, val, targetDepth);
        }
    }

    // Fonction principale pour ajouter une rangée supplémentaire à l'arbre
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        // Si la profondeur spécifiée est égale à 1, on ajoute une nouvelle racine
        // avec la valeur donnée (val), en faisant pointer son enfant gauche vers
        // l'ancienne racine (root).
        if (depth == 1)
        {
            return new TreeNode(val, root, nullptr);
        }

        // Sinon, on appelle la fonction récursive pour ajouter une nouvelle rangée à partir de la racine
        addDFS(root, 2, val, depth);

        return root;
    }
};