class Solution
{
  public:
    int minimumLength(const string &s)
    {
        // Initialisation des indices de début et de fin.
        int i = 0;
        int j = s.size() - 1;

        // Parcours de la chaîne jusqu'à ce que les indices se croisent.
        while (i < j)
        {
            // Si les caractères aux extrémités sont les mêmes.
            if (s[i] == s[j])
            {
                char c = s[i];
                // Avancer l'indice i tant que les caractères sont égaux.
                while (s[i] == c && i <= j)
                {
                    i++;
                }
                // Reculer l'indice j tant que les caractères sont égaux.
                while (s[j] == c && i <= j)
                {
                    j--;
                }
                // Continuer à chercher des caractères égaux au milieu de la chaîne.
                continue;
            }
            // Si les caractères aux extrémités ne sont pas égaux, sortir de la boucle.
            break;
        }

        // La longueur minimale est la différence entre les indices plus 1.
        return j - i + 1;
    }
};