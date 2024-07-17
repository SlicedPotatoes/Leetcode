/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
  public:
    // Fonction pour supprimer un noeud et ajuster l'arbre en conséquence
    void deleteNode(TreeNode *parent, TreeNode *child, bool isLeft, vector<TreeNode *> &ans,
                    unordered_set<int> &toDelete)
    {
        toDelete.erase(child->val); // Supprimer le noeud du set toDelete

        // Ajouter les enfants du noeud supprimé à la liste des résultats
        if (child->left)
        {
            ans.push_back(child->left);
        }
        if (child->right)
        {
            ans.push_back(child->right);
        }

        // Détacher le noeud supprimé de son parent
        if (isLeft)
        {
            parent->left = nullptr;
        }
        else
        {
            parent->right = nullptr;
        }

        // Libérer la mémoire des noeuds supprimés
        // delete child;
    }

    // Fonction DFS pour explorer et marquer les noeuds à supprimer
    bool dfs(TreeNode *root, vector<TreeNode *> &ans, unordered_set<int> &toDelete)
    {
        if (root->left && dfs(root->left, ans, toDelete))
        {
            deleteNode(root, root->left, true, ans, toDelete);
        }
        if (root->right && dfs(root->right, ans, toDelete))
        {
            deleteNode(root, root->right, false, ans, toDelete);
        }

        // Retourne true si le noeud actuel doit être supprimé
        return toDelete.find(root->val) != toDelete.end();
    }

    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> toDelete(to_delete.begin(), to_delete.end());

        // Si la racine doit être supprimée, ajouter ses enfants à la liste des résultats
        if (dfs(root, ans, toDelete))
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }

            // Libérer la mémoire des noeuds supprimés
            // delete root;
        }
        // Sinon, ajouter la racine à la liste des résultats
        else
        {
            ans.push_back(root);
        }

        // Retourner les racines des sous-arbres restants
        return ans;
    }
};