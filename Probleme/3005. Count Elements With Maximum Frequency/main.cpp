class Solution
{
  public:
    int maxFrequencyElements(vector<int> &nums)
    {
        // Map pour stocker les fréquences de chaque élément du vecteur.
        unordered_map<int, int> frequencies;

        // Initialisation de la fréquence maximale et du compteur de fréquences maximales.
        int maxFrequency = 0;
        int countMaxFrequency = 0;

        // Parcours de chaque élément du vecteur.
        for (int num : nums)
        {
            // Incrémente la fréquence de l'élément actuel.
            frequencies[num]++;

            // Si la fréquence de l'élément actuel est égale à la fréquence maximale,
            // incrémente le compteur de fréquences maximales.
            if (frequencies[num] == maxFrequency)
            {
                countMaxFrequency++;
            }
            // Si la fréquence de l'élément actuel dépasse la fréquence maximale,
            // met à jour la fréquence maximale et réinitialise le compteur de fréquences maximales à 1.
            else if (frequencies[num] > maxFrequency)
            {
                maxFrequency = frequencies[num];
                countMaxFrequency = 1;
            }
        }

        // Retourne le produit du nombre d'éléments de fréquence maximale et de cette fréquence maximale.
        return countMaxFrequency * maxFrequency;
    }
};