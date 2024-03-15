class Solution
{
  public:
    // Fonction pour obtenir la valeur d'un chiffre romain
    int romanValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return -1; // Retourne -1 si le chiffre romain est invalide
    }
    int romanToInt(const string &s)
    {
        int result = 0; // Initialisation du résultat

        int i = 0; // Initialisation de l'indice de boucle

        // Parcourir la chaîne de caractères
        for (; i < s.size() - 1; i++)
        {
            // Obtenir la valeur du chiffre romain courant
            int current = romanValue(s[i]);
            // Obtenir la valeur du chiffre romain suivant
            int next = romanValue(s[i + 1]);

            if (current >= next)
            {
                // Ajouter la valeur du chiffre courant au résultat
                result += current;
            }
            else
            {
                // Soustraire la valeur du chiffre courant du résultat et passer au suivant
                result += next - current;
                // Augmenter l'indice pour sauter le chiffre suivant
                i++;
            }
        }
        // Vérifier si le dernier chiffre a été traité ou s'il reste un chiffre à traiter
        if (i + 1 == s.size())
        {
            // Ajouter la valeur du dernier chiffre au résultat
            result += romanValue(s[i]);
        }

        return result;
    }
};