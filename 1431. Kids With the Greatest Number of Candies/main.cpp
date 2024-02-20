class Solution
{
  public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int biggest = 0; // Variable pour stocker le plus grand nombre de bonbons initialisée à zéro
        vector<bool> result(candies.size()); // Vecteur pour stocker le résultat pour chaque enfant

        // Chercher le plus grand nombre de bonbons
        for (int c : candies)
        {
            biggest = max(c, biggest); // Met à jour le plus grand nombre de bonbons si un nombre plus grand est trouvé
        }

        // Calculer le résultat pour chaque enfant
        for (int indexKids = 0; indexKids < candies.size(); indexKids++)
        {
            if (candies[indexKids] + extraCandies >= biggest)
            {
                result[indexKids] = true; // Si un enfant peut avoir le plus grand nombre de bonbons, marquer comme vrai
            }
        }

        return result;
    }
};