vector<int> dx = {0, 0, 1, -1}; // Vecteur de déplacement horizontal
vector<int> dy = {1, -1, 0, 0}; // Vecteur de déplacement vertical

class Solution
{
  public:
    // Matrice de suivi des cellules visitées
    vector<vector<bool>> visited;

    // Fonction pour obtenir les contours d'une île
    vector<pair<int, int>> getOutline(pair<int, int> start, vector<vector<int>> &grid)
    {
        // Vecteur pour stocker les contours
        vector<pair<int, int>> v;

        queue<pair<int, int>> q; // File d'attente pour le parcours BFS
        q.push(start);           // Ajouter le point de départ à la file d'attente

        // Boucle principale du parcours BFS
        while (!q.empty())
        {
            pair<int, int> current = q.front(); // Prendre le premier élément de la file
            q.pop();                            // Retirer cet élément de la file

            // Indicateur de si la cellule courante est dans le vecteur
            bool inVector = false;

            // Parcourir les quatre directions possibles à partir de la cellule courante
            for (int i = 0; i < 4; i++)
            {
                int _y = current.second + dy[i]; // Calculer la coordonnée verticale de la cellule adjacente
                int _x = current.first + dx[i];  // Calculer la coordonnée horizontale de la cellule adjacente

                // Vérifier les limites du tableau
                if (_y < 0 || _y >= grid.size() || _x < 0 || _x >= grid.size())
                {
                    continue;
                }

                // Si la cellule voisine est de l'eau (0) et la cellule courante n'est pas dans le vecteur contours
                // On l'ajoute
                if (!inVector && grid[_y][_x] == 0)
                {
                    v.push_back(current);
                    inVector = true;
                }
                // Sinon, si la cellule voisine est une île (1) et n'a pas été visitée, la marquer comme visitée et
                // l'ajouter à la file d'attente
                if (grid[_y][_x] == 1 && !visited[_y][_x])
                {
                    visited[_y][_x] = true;
                    q.push(make_pair(_x, _y));
                }
            }
        }

        return v; // Retourner les contours de l'île
    }

    // Calculer la distance de Manhattan entre deux points
    int distance(int x, int y, int _x, int _y)
    {
        return abs(x - _x) + abs(y - _y);
    }

    // Fonction pour trouver le plus court pont entre deux îles
    int shortestBridge(vector<vector<int>> &grid)
    {
        // Vecteur de vecteurs pour stocker les îles
        vector<vector<pair<int, int>>> islands;
        // Initialiser la matrice de visite
        visited = vector<vector<bool>>(grid.size(), vector<bool>(grid.size(), false));

        // Parcourir la grille pour trouver toutes les îles
        for (int y = 0; y < grid.size(); y++)
        {
            for (int x = 0; x < grid.size(); x++)
            {
                if (grid[y][x] == 1 && !visited[y][x])
                {
                    visited[y][x] = false;
                    // Obtenir les contours de l'île actuelle
                    vector<pair<int, int>> v = getNeighbor(make_pair(x, y), grid);
                    // Ajouter les contours de l'île à la liste des îles
                    islands.push_back(v);
                }
            }
        }

        int ans = INT_MAX; // Initialiser la réponse avec une valeur maximale

        // Parcourir toutes les paires de contours d'îles pour trouver la distance minimale
        for (auto &p1 : islands[0])
        {
            for (auto &p2 : islands[1])
            {
                int d = distance(p1.first, p1.second, p2.first, p2.second);
                ans = min(ans, d); // Mettre à jour la distance minimale
            }
        }

        return ans - 1;
    }
};