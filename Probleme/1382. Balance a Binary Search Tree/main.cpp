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
    // Fonction pour remplir un vecteur avec les nœuds de l'arbre en ordre croissant
    void fillVector(TreeNode *root, vector<TreeNode *> &arr)
    {
        if (!root)
        {
            return; // Si le nœud est nul, retour
        }

        fillVector(root->left, arr);  // Parcourir le sous-arbre gauche
        arr.push_back(root);          // Ajouter le nœud courant au vecteur
        fillVector(root->right, arr); // Parcourir le sous-arbre droit
    }

    // Fonction pour construire un arbre binaire de recherche équilibré à partir d'un vecteur de nœuds
    TreeNode *buildBalancedBST(int start, int end, vector<TreeNode *> &arr)
    {
        if (start <= end)
        {
            int mid = start + (end - start) / 2; // Calculer l'index du milieu

            TreeNode *root = arr[mid]; // Récupérer le nœud du milieu

            root->left = buildBalancedBST(start, mid - 1, arr); // Construire le sous-arbre gauche
            root->right = buildBalancedBST(mid + 1, end, arr);  // Construire le sous-arbre droit

            return root; // Retourner le nœud racine
        }
        return nullptr; // Si la sous-partie est invalide, retourner nul
    }

    // Fonction pour équilibrer un arbre binaire de recherche
    TreeNode *balanceBST(TreeNode *root)
    {
        vector<TreeNode *> arr;
        fillVector(root, arr); // Remplir le vecteur avec les nœuds de l'arbre

        return buildBalancedBST(0, arr.size() - 1, arr); // Construire et retourner un arbre équilibré
    }
};