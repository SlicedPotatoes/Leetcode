class Solution
{
  public:
    string addStrings(string num1, string num2)
    {
        // Initialisation des indices pour parcourir les chaînes de caractères
        int i = num1.size() - 1;
        int j = num2.size() - 1;

        // Initialisation de la chaîne de résultat et de la retenue
        string result;
        int carrying = 0;

        // Parcours des chaînes de caractères de droite à gauche
        while (i >= 0 || j >= 0)
        {
            // Initialisation de la somme avec la retenue précédente
            int sum = carrying;
            carrying = 0;

            // Ajout des chiffres des deux nombres s'ils existent
            if (i >= 0)
            {
                sum += num1[i] - '0'; // Conversion du caractère en chiffre en soustrayant le caractère '0'
                i--;
            }
            if (j >= 0)
            {
                sum += num2[j] - '0'; // Conversion du caractère en chiffre en soustrayant le caractère '0'
                j--;
            }

            // Gestion de la retenue
            if (sum > 9)
            {
                carrying = 1;
                sum %= 10;
            }

            // Conversion du chiffre de la somme en caractère et ajout à la chaîne de résultat
            result += sum + '0';
        }

        // Ajout de la dernière retenue si elle existe
        if (carrying)
        {
            result += '1';
        }

        // Inversion de la chaîne de résultat pour obtenir le résultat final
        reverse(result.begin(), result.end());

        return result;
    }
};