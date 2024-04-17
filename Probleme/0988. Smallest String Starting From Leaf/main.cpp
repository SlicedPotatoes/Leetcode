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
    // Initialisation d'une chaîne avec un caractère arbitrairement grand pour stocker la plus petite chaîne trouvée
    // lexicographiquement
    string smallest = "|";

    // Fonction pour vérifier si une chaîne est plus petite que la plus petite chaîne actuellement trouvée.
    bool isSmaller(string &s)
    {
        int i = s.size() - 1;        // Indice pour parcourir la chaîne passée en paramètre
        int j = smallest.size() - 1; // Indice pour parcourir la plus petite chaîne actuellement trouvée

        // Parcours des deux chaînes de droite à gauche
        while (i >= 0 && j >= 0)
        {
            // Si les caractères sont égaux, continuer la comparaison
            if (s[i] == smallest[j])
            {
                i--;
                j--;
                continue;
            }
            // Si les caractères diffèrent, retourner vrai si le caractère de la chaîne actuelle est plus petit
            return s[i] < smallest[j];
        }

        // Si toutes les lettres correspondent mais la chaîne actuelle est plus courte, elle est considérée plus petite
        return s.size() < smallest.size();
    }

    // Fonction de parcours en profondeur (DFS) pour explorer tous les chemins de l'arbre.
    void dfs(TreeNode *root, string &curr)
    {
        // Si le noeud est nul, retourner
        if (!root)
        {
            return;
        }

        // Ajouter la valeur du noeud convertie en caractère à la chaîne courante
        curr.push_back('a' + root->val);

        // Si le noeud est une feuille
        if (!root->left && !root->right)
        {
            // Vérifier si la chaîne courante est plus petite que la plus petite trouvée jusqu'à présent
            if (isSmaller(curr))
            {
                // Mettre à jour la plus petite chaîne si nécessaire
                smallest = curr;
            }
            // Retirer le dernier caractère ajouté
            curr.pop_back();
            return;
        }

        dfs(root->right, curr); // Parcourir le sous-arbre droit
        dfs(root->left, curr);  // Parcourir le sous-arbre gauche

        // Retirer le dernier caractère ajouté
        curr.pop_back();
    }

    // Fonction principale pour trouver la plus petite chaîne à partir des feuilles de l'arbre.
    string smallestFromLeaf(TreeNode *root)
    {
        // Initialiser une chaîne vide pour stocker le chemin actuel lors du parcours de l'arbre
        string curr = "";
        // Démarrer le parcours en profondeur (DFS)
        dfs(root, curr);

        // Inverser la chaîne la plus petite pour obtenir l'ordre correct
        reverse(smallest.begin(), smallest.end());

        // Retourner la plus petite chaîne trouvée
        return smallest;
    }
};