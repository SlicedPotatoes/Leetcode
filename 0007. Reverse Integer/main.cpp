class Solution
{
  public:
    int reverse(int x)
    {
        int answer = 0; // Initialiser la réponse à 0
        int power = 1;  // Initialiser la puissance à 1

        // Vérifier le dépassement
        if (abs(x) >= 1000000000)
        {
            int mod = 10; // Initialiser le modulo à 10
            int sum = 0;  // Initialiser la somme à 0

            // Initialiser un vecteur contenant des valeurs pour vérifier le dépassement
            vector<int8_t> elements = {2, 1, 4, 7, 4, 8, 3, 6, 4};

            // Parcourir le vecteur elements
            for (int i = 0; i < 9; i++)
            {
                int checkValue = ((abs(x) % mod) - sum) / (mod / 10); // Calculer la valeur de contrôle
                // Vérifier si la valeur de contrôle est inférieure à l'élément actuel
                if (checkValue < elements[i])
                {
                    break; // Sortir de la boucle si c'est le cas
                }
                // Vérifier si la valeur de contrôle est égale à l'élément actuel
                else if (checkValue == elements[i])
                {
                    // Si c'est le dernier élément
                    if (i == 8)
                    {
                        break; // Sortir de la boucle
                    }
                    sum += (checkValue * mod) / 10; // Ajouter la valeur de contrôle à la somme
                    mod *= 10;                      // Multiplier le modulo par 10
                    continue;                       // Passer à l'itération suivante de la boucle
                }
                return 0; // Retourner 0 en cas de dépassement détecté
            }
            power = 1000000000; // Définir la puissance sur 10^9
        }

        // Vérifier si la puissance est égale à 1
        if (power == 1)
        {
            // Tant que la puissance est inférieure ou égale à la valeur absolue de x
            while (power <= abs(x))
            {
                power *= 10; // Multiplier la puissance par 10
            }
            // Si la puissance est supérieure à la valeur absolue de x et différente de 1
            if (power > abs(x) && power != 1)
            {
                power /= 10; // Diviser la puissance par 10
            }
        }

        int offset = 1; // Initialiser le décalage à 1

        while (true)
        {
            int r = x % power; // Calculer le reste de x divisé par la puissance
            // Ajouter la partie entière de x divisée par la puissance à la réponse, multipliée par le décalage
            answer += ((x - r) / power) * offset;

            // Si la puissance est égale à 1
            if (power == 1)
            {
                break; // Sortir de la boucle
            }

            power /= 10;  // Diviser la puissance par 10
            offset *= 10; // Multiplier le décalage par 10

            x = r; // Mettre à jour x avec le reste
        }

        return answer; // Retourner la réponse
    }
};