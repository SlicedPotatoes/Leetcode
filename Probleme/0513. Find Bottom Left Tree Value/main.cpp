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
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;     // File d'attente pour le parcours en largeur
        queue<TreeNode *> tempQ; // File d'attente temporaire pour stocker les nœuds à chaque niveau

        int result = root->val; // Initialisation de la valeur à retourner avec la valeur du noeud racine
        q.push(root);           // Ajout du noeud racine à la file d'attente

        // Parcours de l'arbre en largeur
        while (!q.empty())
        {
            TreeNode *currentNode = q.front(); // Récupération du noeud en tête de file
            q.pop();                           // Suppression du noeud en tête de file

            // Ajout des fils du noeud courant à la file temporaire si ils existent
            if (currentNode->left != nullptr)
            {
                tempQ.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                tempQ.push(currentNode->right);
            }

            // Vérification si la file principale est vide, ce qui signifie qu'on a parcouru un niveau complet
            if (q.empty())
            {
                // Échange des files, la file temporaire devient la file principale pour le prochain niveau
                swap(tempQ, q);
                // Si la file principale n'est pas vide après l'échange, on met à jour la valeur de résultat avec le
                // premier noeud du prochain niveau
                if (!q.empty())
                {
                    result = q.front()->val;
                }
            }
        }

        return result; // Retourne la valeur du noeud le plus à gauche dans le dernier niveau de l'arbre
    }
};