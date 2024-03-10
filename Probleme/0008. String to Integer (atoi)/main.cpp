class Solution
{
  public:
    int myAtoi(string &s)
    {
        int i = 0;
        bool isNeg = false;

        // Ignorer les espaces au début de la chaîne
        while (i < s.length() && s[i] == ' ')
        {
            i++;
        }

        // Gérer les signes + ou -
        if (!isdigit(s[i]))
        {
            if (s[i] == '-')
            {
                isNeg = true;
            }
            else if (s[i] != '+')
            {
                return 0;
            }
            i++;
        }

        uint32_t value = 0;

        // Ignorer les zéros en tête
        while (i < s.length() && s[i] == '0')
        {
            i++;
        }

        int startI = i; // Sauvegarde de l'indice de début pour vérifier la longueur du nombre

        // Convertir les chiffres en nombre entier
        while (i < s.length() && isdigit(s[i]))
        {
            // Vérifier le dépassement de capacité ou la longueur du nombre
            if (i - startI >= 10 || value > INT_MAX / 10)
            {
                return isNeg ? INT_MIN : INT_MAX; // Retourner INT_MIN ou INT_MAX en cas de dépassement
            }
            value *= 10;
            value += s[i] - '0'; // Conversion de caractère à entier en soustrayant le caractère '0'
            i++;
        }

        // Vérifier le dépassement après la boucle
        if (value > INT_MAX)
        {
            return isNeg ? INT_MIN : INT_MAX;
        }

        // Retourner la valeur avec le signe approprié
        return isNeg ? -value : value;
    }
};