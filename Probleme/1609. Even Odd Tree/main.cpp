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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;     // Queue pour parcourir les noeuds de l'arbre
        queue<TreeNode *> tempQ; // Queue temporaire pour stocker les noeuds à chaque niveau

        q.push(root);         // On commence à partir de la racine de l'arbre
        int currentDepth = 0; // Profondeur actuelle de l'arbre
        int currentValue = 0; // Valeur actuelle du noeud précédemment visité a la même profondeur

        while (!q.empty())
        {
            TreeNode *currentNode = q.front(); // On récupère le premier noeuds de la queue
            q.pop();                           // On enlève le noeuds traité de la queue principale

            // Vérification des règles établies
            if (currentDepth % 2 == 0) // Si la profondeur est paire
            {
                // Si la valeur du noeud est impaire ou inférieure ou égale à la valeur précédente
                if (currentNode->val % 2 != 1 || currentNode->val <= currentValue)
                {
                    return false; // L'arbre ne respecte pas les règles
                }
            }
            else // Si la profondeur est impaire
            {
                // Si la valeur du noeud est paire ou supérieure ou égale à la valeur précédente
                if (currentNode->val % 2 != 0 || currentNode->val >= currentValue)
                {
                    return false; // L'arbre ne respecte pas les règles
                }
            }

            currentValue = currentNode->val; // Mise à jour de la valeur actuelle

            // Ajout des enfants du noeud courant dans la queue temporaire
            if (currentNode->left != nullptr)
            {
                tempQ.push(currentNode->left);
            }
            if (currentNode->right != nullptr)
            {
                tempQ.push(currentNode->right);
            }

            // Si on a fini de traiter les noeuds du niveau actuel
            if (q.empty())
            {
                swap(q, tempQ); // On échange les queues pour passer au niveau suivant
                currentDepth++; // On incrémente la profondeur
                // Réinitialisation de la valeur actuelle en fonction de la profondeur
                if (currentDepth % 2 == 0)
                {
                    currentValue = 0; // Pour les niveaux pairs, la valeur actuelle est minimale
                }
                else
                {
                    currentValue = INT_MAX; // Pour les niveaux impairs, la valeur actuelle est maximale
                }
            }
        }

        return true;
    }
};