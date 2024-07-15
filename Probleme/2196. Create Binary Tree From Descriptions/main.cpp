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
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mp; // Lecture des valeurs de la description
        unordered_set<int> set;            // Set pour identifier les potentiels racines

        // Parcours de chaque description
        for (vector<int> &v : descriptions)
        {
            TreeNode *parent = mp[v[0]]; // Récupère le noeud parent depuis la map
            TreeNode *child = mp[v[1]];  // Récupère le noeud enfant depuis la map

            // Si le noeud enfant n'existe pas encore
            if (!child)
            {
                child = new TreeNode(v[1]); // Crée un nouveau noeud enfant
                mp[v[1]] = child;           // Ajoute le noeud enfant à la map
            }

            // Si le noeud parent n'existe pas encore
            if (!parent)
            {
                parent = new TreeNode(v[0]); // Crée un nouveau noeud parent
                mp[v[0]] = parent;           // Ajoute le noeud parent à la map
                set.insert(v[0]);            // Ajoute le parent au set des potentiels racines
            }

            // Affecter l'enfant au parent
            if (v[2])
            {
                parent->left = child;
            }
            else
            {
                parent->right = child;
            }

            // L'enfant ne peut pas être une racine, donc on l'enlève du set
            set.erase(v[1]);
        }

        // Le seul élément restant dans le set est la racine de l'arbre
        return mp[*set.begin()];
    }
};