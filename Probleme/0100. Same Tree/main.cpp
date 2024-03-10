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

// Définition de la structure pour stocker les éléments dans la file BFS
struct bfsNode
{
    TreeNode *p; // Pointeur vers le noeud dans l'arbre p
    TreeNode *q; // Pointeur vers le noeud dans l'arbre q

    // Constructeur pour initialiser les pointeurs
    bfsNode(TreeNode *p, TreeNode *q)
    {
        this->p = p;
        this->q = q;
    }
};

class Solution
{
  public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        // Création d'une file pour parcourir les deux arbres en même temps
        queue<bfsNode> bfsQueue;
        bfsQueue.push({p, q}); // Ajout des racines des deux arbres dans la file

        // Parcours BFS
        while (!bfsQueue.empty())
        {
            // Récupération du noeud courant des deux arbres
            bfsNode current = bfsQueue.front();
            bfsQueue.pop();

            // Si le noeud courant de l'arbre p est nul
            if (current.p == nullptr)
            {
                // Si le noeud courant de l'arbre q est également nul, on passe au noeud suivant
                if (current.q == nullptr)
                {
                    continue; // On passe au noeud suivant
                }
                // Sinon, les arbres sont différents, on retourne false
                return false;
            }
            // Si le noeud courant de l'arbre q est nul ou que les valeurs sont différentes,
            // les arbres ne sont pas identiques, on retourne false
            else if (current.q == nullptr || current.p->val != current.q->val)
            {
                return false;
            }

            // On ajoute les fils gauche et droit des noeuds courants des deux arbres dans la file
            bfsQueue.push({current.q->left, current.p->left});
            bfsQueue.push({current.q->right, current.p->right});
        }

        // Si le parcours BFS n'a pas trouvé de différence entre les deux arbres, on retourne true
        return true;
    }
};