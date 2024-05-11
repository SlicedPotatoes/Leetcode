class Solution
{
  public:
    int sumOfTheDigitsOfHarshadNumber(int x)
    {
        int sum = 0;     // Initialisation de la somme à 0.
        int current = x; // Stocke la copie de x pour la manipulation.

        // Boucle pour calculer la somme des chiffres de x.
        while (current != 0)
        {
            sum += current % 10; // Ajoute le dernier chiffre de current à la somme.
            current /= 10;       // Supprime le dernier chiffre de current.
        }

        // Vérifie si x est divisible par la somme de ses chiffres (nombre Harshad).
        // Retourne la somme si x est un nombre Harshad, sinon retourne -1.
        return x % sum == 0 ? sum : -1;
    }
};