class Solution
{
  public:
    int pivotInteger(int n)
    {
        int prefixSum = 0; // Somme des préfixes
        // Calcul de la somme cumulative des nombres de 1 à n
        for (int i = 1; i <= n; i++)
        {
            prefixSum += i;
        }

        int suffixSum = 0; // Somme des suffixes

        // Parcours des nombres de n à 1
        for (int i = n; i > 0; i--)
        {
            // Ajout de l'élément actuel à la somme des suffixes
            suffixSum += i;
            // Si les sommes des préfixes et suffixes sont égales
            if (prefixSum == suffixSum)
            {
                // On a trouvé le pivot, donc on retourne la valeur actuelle de i
                return i;
            }
            // Soustraction de l'élément actuel de la somme des préfixes
            prefixSum -= i;
        }
        // Si aucun pivot n'est trouvé, retourne -1
        return -1;
    }
};