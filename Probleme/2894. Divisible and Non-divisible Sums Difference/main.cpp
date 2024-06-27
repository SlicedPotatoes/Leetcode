class Solution
{
  public:
    int differenceOfSums(int n, int m)
    {
        // Calcul de la somme totale des entiers de 1 à n
        int sommeCumuler = (n * (n + 1)) / 2;

        // Calcul de la somme des multiples de m jusqu'à n
        int nbMultiple = n / m;
        int sumMultiple = m * (nbMultiple * (nbMultiple + 1)) / 2;

        // Calcul de la différence entre la somme totale et deux fois la somme des multiples de m
        return sommeCumuler - (sumMultiple * 2);
    }
};