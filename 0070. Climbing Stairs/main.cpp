class Solution
{
  public:
    int climbStairs(int n)
    {
        // Initialisation des deux premières valeurs de la séquence de Fibonacci
        int a = 1; // Nombre de façons de monter les escaliers avec 1 marche
        int b = 1; // Nombre de façons de monter les escaliers avec 2 marches

        // Parcours de la séquence de Fibonacci jusqu'à n
        for (int i = 2; i <= n; i++)
        {
            // Échange des valeurs de a et b
            swap(a, b);

            // b est mis à jour pour contenir le nombre total de façons de monter les escaliers avec i marches
            b += a;
        }

        // Retourne le nombre total de façons de monter les escaliers avec n marches
        return b;
    }
};