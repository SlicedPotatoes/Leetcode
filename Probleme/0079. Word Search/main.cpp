class Solution
{
  public:
    // Définition d'un caractère pour marquer les cases visitées
    const char MARKED_CHAR = '.';
    // Vecteur d'indices pour déplacement dans les 4 directions
    vector<pair<int, int>> indexHelper = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Fonction de backtracking pour rechercher le mot dans la grille
    bool backtracking(vector<vector<char>> &board, string &word, int indexW, int y, int x)
    {
        // Si on a parcouru tout le mot, c'est une solution
        if (indexW == word.size())
        {
            return true;
        }

        // Parcours des déplacements possibles à partir de la position actuelle
        for (const auto &iH : indexHelper)
        {
            int _y = y + iH.first;
            int _x = x + iH.second;

            // Vérification des limites de la grille et correspondance avec le prochain caractère du mot
            if (_y >= 0 && _y < board.size() && _x >= 0 && _x < board[0].size() && board[_y][_x] == word[indexW])
            {
                // Marquage de la case visitée
                board[_y][_x] = MARKED_CHAR;

                // Appel récursif pour explorer le prochain caractère
                if (backtracking(board, word, indexW + 1, _y, _x))
                {
                    return true;
                }

                // Restauration du caractère original après exploration
                board[_y][_x] = word[indexW];
            }
        }

        return false;
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int countFirstChar = 0; // Compteur pour le premier caractère du mot
        int countLastChar = 0;  // Compteur pour le dernier caractère du mot

        // Parcours de la grille pour compter les occurrences du premier et dernier caractère du mot
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (board[y][x] == word[0])
                {
                    countFirstChar++;
                }
                else if (board[y][x] == word.back())
                {
                    countLastChar++;
                }
            }
        }

        // Si le premier caractère apparaît plus souvent que le dernier, on inverse le mot pour optimiser la recherche
        if (countFirstChar > countLastChar)
        {
            reverse(word.begin(), word.end());
        }

        // Parcours de la grille pour rechercher le premier caractère du mot
        for (int y = 0; y < board.size(); y++)
        {
            for (int x = 0; x < board[0].size(); x++)
            {
                if (board[y][x] == word[0])
                {
                    // Marquage de la case visitée
                    board[y][x] = MARKED_CHAR;
                    // Appel à la fonction de backtracking pour rechercher le reste du mot
                    if (backtracking(board, word, 1, y, x))
                    {
                        return true;
                    }
                    // Restauration du caractère original après exploration
                    board[y][x] = word[0];
                }
            }
        }

        // Le mot n'a pas été trouvé dans la grille
        return false;
    }
};