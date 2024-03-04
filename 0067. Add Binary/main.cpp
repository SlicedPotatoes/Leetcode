class Solution
{
  public:
    string addBinary(string &a, string &b)
    {
        string output = ""; // Initialisation de la chaîne de caractères de sortie

        // Initialisation des indices pour parcourir les chaînes a et b en partant de la fin
        int i = a.size() - 1;
        int j = b.size() - 1;

        int carrying = false; // Utilisation de booléen pour représenter la retenue

        // Tant qu'il reste des chiffres binaires à additionner ou qu'une retenue est en cours
        while (i >= 0 || j >= 0 || carrying)
        {
            int sum = 0; // Initialisation de la somme des bits à ajouter

            // Si l'indice i est valide (pour la chaîne a), ajouter le bit correspondant à la somme
            if (i >= 0)
            {
                if (a[i] == '1')
                {
                    sum++;
                }
                i--;
            }
            // Si l'indice j est valide (pour la chaîne b), ajouter le bit correspondant à la somme
            if (j >= 0)
            {
                if (b[j] == '1')
                {
                    sum++;
                }
                j--;
            }
            // Ajouter une éventuelle retenue à la somme
            if (carrying)
            {
                sum++;
                carrying = false;
            }

            // Construire la sortie en fonction de la somme des bits
            if (sum == 0)
            {
                output += '0';
            }
            else if (sum == 1)
            {
                output += '1';
            }
            else if (sum == 2)
            {
                output += '0';
                carrying = true;
            }
            else
            {
                output += '1';
                carrying = true;
            }
        }

        // Inverser la chaîne de sortie pour obtenir le résultat correct
        reverse(output.begin(), output.end());

        return output;
    }
};