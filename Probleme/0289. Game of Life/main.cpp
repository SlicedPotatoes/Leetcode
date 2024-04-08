class Solution
{
  public:
    // Tableau des indices des cellules voisines
    vector<pair<int, int>> indexHelper{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    void gameOfLife(vector<vector<int>> &board)
    {
        // Parcourir chaque cellule du tableau
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                int sum = 0; // Initialiser la somme des cellules voisines

                // Parcourir les cellules voisines de la cellule actuelle
                for (const auto &iH : indexHelper)
                {
                    int _y = y + iH.first;
                    int _x = x + iH.second;

                    // Vérifier si les indices sont valides
                    if (_y >= 0 && _y < board.size() && _x >= 0 && _x < board[0].size())
                    {
                        int value = board[_y][_x];

                        // Récupéré la valeur dans le cas ou elle a été changé.
                        if (value > 1)
                        {
                            value -= 2;
                        }

                        // Ajouter la valeur de la cellule voisine à la somme
                        sum += value;
                    }
                }

                // Appliquer les règles du jeu de la vie
                if (board[y][x] == 1 && (sum < 2 || sum > 3))
                {
                    board[y][x] = 3; // Marquer la cellule comme morte
                }
                else if (board[y][x] == 0 && sum == 3)
                {
                    board[y][x] = 2; // Marquer la cellule comme vivante
                }
            }
        }

        // Mettre à jour les états des cellules selon les marquages effectués précédemment
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (board[y][x] == 2)
                {
                    board[y][x] = 1; // Mettre la cellule vivante
                }
                else if (board[y][x] == 3)
                {
                    board[y][x] = 0; // Mettre la cellule morte
                }
            }
        }
    }
};