class Solution
{
  public:
    int mySqrt(int x)
    {
        int start = 1;
        int end = x;

        // Utilisation de la recherche binaire pour trouver la racine carrée de x.
        while (start <= end)
        {
            // Calcul du milieu de l'intervalle.
            int mid = start + (end - start) / 2;

            // Si mid est plus grand que x / mid, cela signifie que mid est trop grand et la racine carrée de x est dans
            // la première moitié de l'intervalle.
            if (mid > x / mid)
            {
                end = mid - 1;
            }
            // Sinon, la racine carrée de x est dans la seconde moitié de l'intervalle.
            else
            {
                start = mid + 1;
            }
        }

        // À ce stade, end contient la plus grande valeur entière dont le carré est inférieur ou égal à x.
        // Cela peut être la réponse exacte ou la valeur juste en dessous de la racine carrée.
        return end;
    }
};