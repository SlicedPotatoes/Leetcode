class Solution
{
  public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // Tableaux pour suivre les nombres vus sur les lignes, colonnes et sous-grilles
        bool seen[3][9][9] = {false};

        // Parcours de chaque cellule du tableau Sudoku
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // Si la cellule n'est pas vide
                if (board[i][j] != '.')
                {
                    // Calcul de l'indice de la sous-grille
                    int subGrid = i / 3 * 3 + j / 3;
                    // Conversion du caractère en chiffre
                    int number = board[i][j] - '0' - 1;

                    // Vérification si le nombre est déjà apparu sur la ligne, colonne ou sous-grille
                    if (seen[0][i][number] || seen[1][j][number] || seen[2][subGrid][number])
                    {
                        return false;
                    }

                    // Marquer le nombre comme vu sur la ligne, colonne et sous-grille
                    seen[0][i][number] = true;
                    seen[1][j][number] = true;
                    seen[2][subGrid][number] = true;
                }
            }
        }
        // Si aucune incohérence n'est trouvée, le Sudoku est valide
        return true;
    }
};