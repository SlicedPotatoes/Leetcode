class Solution
{
  public:
    // Fonction pour vérifier si un caractère est une voyelle
    bool isVowels(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string &s, int k)
    {
        int sum = 0;
        // Calcul de la somme initiale des voyelles dans les k premiers caractères
        for (int i = 0; i < k; i++)
        {
            sum += isVowels(s[i]);
        }

        // Initialise l'output avec la somme initiale des voyelles.
        int output = sum;

        // Parcours de la chaîne à partir de l'indice k
        for (int i = k; i < s.size(); i++)
        {
            // Mise à jour de sum en ajoutant la voyelle actuelle et en retirant la voyelle qui n'est plus dans la
            // fenêtre
            sum += isVowels(s[i]) - isVowels(s[i - k]);
            // Mise à jour de output avec le maximum trouvé
            output = max(output, sum);
        }

        // Retourne le nombre maximal de voyelles trouvé dans une sous-chaîne de longueur k
        return output;
    }
};