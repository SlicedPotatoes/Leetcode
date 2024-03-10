class Solution
{
  public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        // Trie les jetons par ordre croissant
        sort(tokens.begin(), tokens.end());

        int currentScore = 0; // Score actuel
        int maxScore = 0;     // Score maximum obtenu jusqu'à présent

        // Parcourt les jetons en utilisant deux pointeurs (i et j)
        for (int i = 0, j = tokens.size() - 1; i <= j;)
        {
            // Si le jeton peut être joué face visible
            if (tokens[i] <= power)
            {
                power -= tokens[i];                     // Dépense le pouvoir pour jouer le jeton face visible
                currentScore++;                         // Incrémente le score actuel
                maxScore = max(maxScore, currentScore); // Met à jour le score maximum
                i++;                                    // Passe au jeton suivant
            }
            // Sinon, si le jeton peut être joué face cachée
            else if (currentScore >= 1)
            {
                currentScore--;     // Dépense du score pour jouer le jeton face cachée
                power += tokens[j]; // Incrémenter le pouvoir de la valeur du jeton
                j--;                // Passe au jeton précédent
            }
            // Si nous ne pouvons ni jouer face visible ni face cachée, on sort de la boucle
            else
            {
                break;
            }
        }

        return maxScore;
    }
};