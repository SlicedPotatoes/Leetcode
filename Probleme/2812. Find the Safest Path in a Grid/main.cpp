// Variable globale pour la taille de la grille.
int n = -1;

// Structure représentant un nœud dans la grille.
struct Node
{
    int y;     // Coordonnée y
    int x;     // Coordonnée x
    int value; // Valeur associée au nœud
};

// Comparateur personnalisé pour la priority_queue
struct Compare
{
    bool operator()(Node &a, Node &b)
    {
        // Si les valeurs sont égales, comparer par la distance depuis le coin bas-droit
        if (a.value == b.value)
        {
            int dA = (n - a.y) + (n - a.x);
            int dB = (n - b.y) + (n - b.x);
            return dA > dB; // Prioriser le nœud le plus proche du coin bas-droit
        }
        // Sinon, prioriser le nœud avec la plus grande valeur
        return a.value < b.value;
    }
};

class Solution
{
  public:
    // Vecteurs pour le déplacement dans les quatre directions (haut, droite, bas, gauche)
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};

    // Fonction d'aide pour calculer le facteur de sécurité maximal
    int helper(vector<vector<int>> &arr)
    {
        // Priority queue utilisant notre comparateur personnalisé
        priority_queue<Node, vector<Node>, Compare> pq;
        pq.push(Node(0, 0, arr[0][0]));
        arr[0][0] = -1; // Marquer comme visité

        // Initialiser la valeur minimale au maximum possible
        int minValue = INT_MAX;

        while (!pq.empty())
        {
            Node curr = pq.top();
            pq.pop();

            // Mettre à jour la valeur minimale rencontrée
            minValue = min(minValue, curr.value);

            // Si nous avons atteint le coin bas-droit, nous avons fini
            if (curr.y == n - 1 && curr.x == n - 1)
            {
                break;
            }

            // Explorer les voisins
            for (int d = 0; d < 4; d++)
            {
                int y = curr.y + dy[d];
                int x = curr.x + dx[d];

                // Vérifier si le voisin est valide et non visité
                if (y >= 0 && y < n && x >= 0 && x < n && arr[y][x] != -1)
                {
                    pq.push(Node(y, x, arr[y][x]));
                    arr[y][x] = -1; // Marquer comme visité
                }
            }
        }

        return minValue; // Retourner la valeur minimale trouvée sur le chemin
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        n = grid.size();
        vector<vector<int>> arr(n, vector<int>(n, 1000)); // Initialiser la matrice

        // Première passe : calculer les distances minimales des obstacles (valeur 1)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    arr[i][j] = 0;
                    continue;
                }
                int m = arr[i][j];

                // Vérifier les voisins au-dessus et à gauche
                if (i != 0)
                {
                    m = min(m, arr[i - 1][j]);
                }
                if (j != 0)
                {
                    m = min(m, arr[i][j - 1]);
                }

                arr[i][j] = m + 1;
            }
        }

        // Deuxième passe : raffiner les distances en considérant les autres directions
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (grid[i][j] == 1)
                {
                    continue;
                }
                int m = arr[i][j];

                // Vérifier les voisins dans les quatre directions
                for (int d = 0; d < 4; d++)
                {
                    int y = i + dy[d];
                    int x = j + dx[d];

                    if (y >= 0 && y < n && x >= 0 && x < n)
                    {
                        m = min(m, arr[y][x]);
                    }
                }

                arr[i][j] = m + 1;
            }
        }

        return helper(arr); // Appeler la fonction d'aide pour obtenir la réponse finale
    }
};