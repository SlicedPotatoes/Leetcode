class Solution
{
  public:
    double myPow(double x, int n)
    {
        // Initialisation du résultat à 1
        double ans = 1;
        // Vérification si l'exposant est négatif
        bool neg = n < 0;
        // Convertir l'exposant en valeur absolue pour simplifier les calculs
        n = abs(n);

        // Tant que l'exposant est positif
        while (n > 0)
        {
            // Initialisation du produit partiel
            double _ans = x;
            // Déclarer une variable pour l'itération dans la boucle for
            size_t i;
            // Itérer jusqu'à ce que i dépasse la moitié de n
            for (i = 1; i <= n - i; i *= 2)
            {
                // Élever x au carré à chaque itération
                _ans *= _ans;
            }
            // Mettre à jour l'exposant en soustrayant la valeur de l'itération i
            n = n - i;
            // Mettre à jour le résultat en multipliant par la valeur temporaire
            ans *= _ans;
        }

        // Si l'exposant était négatif, retourner l'inverse du résultat, sinon, retourner le résultat
        return neg ? 1 / ans : ans;
    }
};