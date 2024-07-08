class Solution
{
  public:
    int findTheWinner(int n, int k)
    {
        int prev = 1; // Initialisation avec le premier joueur

        // Boucle à travers tous les joueurs de 2 à n
        for (int i = 2; i <= n; i++)
        {
            // La formule ((prev + k - 1) % i) + 1 calcule la nouvelle position du gagnant
            prev = ((prev + k - 1) % i) + 1;
        }

        return prev; // Retourne la position du gagnant
    }
};