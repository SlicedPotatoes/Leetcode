class Solution
{
  public:
    // Fonction pour calculer le PGCD en utilisant l'algorithme d'Euclide
    int euclideGcd(int a, int b)
    {
        while (b != 0)
        {
            int leftover = a % b;

            // Affectation des valeurs pour continuer l'algorithme
            a = b;
            b = leftover;
        }

        return a;
    }

    string gcdOfStrings(string str1, string str2)
    {
        // Vérifie si les deux chaînes ont une sous-chaîne commune en les concaténant dans les deux sens
        if (str1 + str2 != str2 + str1)
        {
            return ""; // Si les deux chaînes ne partagent pas une sous-chaîne commune, retourne une chaîne vide
        }

        // Utilisation de l'algorithme d'Euclide avec les longueurs des deux chaînes pour obtenir le PGCD
        int gcd = euclideGcd(max(str1.size(), str2.size()), min(str1.size(), str2.size()));

        // Retourne le sous-chaîne contenant le motif répétitif commun entre les deux chaînes
        return str1.substr(0, gcd);
    }
};