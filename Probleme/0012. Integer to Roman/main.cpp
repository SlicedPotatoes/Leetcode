class Solution
{
  public:
    string intToRoman(int num)
    {
        // Vecteur de paires contenant les valeurs décimales et leurs équivalents romains
        vector<pair<int, string>> romanConverter{{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
                                                 {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
                                                 {5, "V"},    {4, "IV"},   {1, "I"}};

        // Initialisation de l'index à 0 et d'une chaîne de caractères de sortie
        int index = 0;
        string output;

        // Boucle tant que le nombre à convertir n'est pas nul
        while (num != 0)
        {
            // Si le nombre est supérieur ou égal à la valeur décimale actuelle
            if (num >= romanConverter[index].first)
            {
                // Soustraire la valeur décimale de la valeur numérique
                num -= romanConverter[index].first;
                // Ajouter le symbole romain correspondant à la chaîne de sortie
                output += romanConverter[index].second;
            }
            else
            {
                // Passer à la prochaine valeur décimale si le nombre est inférieur
                index++;
            }
        }

        // Retourner la chaîne de caractères résultante
        return output;
    }
};