// Définition de la constante MIN_YEARS pour spécifier l'année minimale
const int MIN_YEARS = 1950;

class Solution
{
  public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        // Création d'un vecteur pour stocker le nombre de personnes vivantes pour chaque année (de 1950 à 2050 inclus)
        vector<int> years(101);

        // Parcours de chaque intervalle de vie dans les logs
        for (vector<int> &person : logs)
        {
            // Incrémentation du nombre de personnes vivantes pour l'année de naissance
            years[person[0] - MIN_YEARS]++;
            // Décrémentation du nombre de personnes vivantes pour l'année de décès
            years[person[1] - MIN_YEARS]--;
        }

        // Initialisation de la variable pour stocker le nombre maximal de personnes vivantes
        int max = 0;
        // Initialisation de la variable pour stocker l'année correspondant au nombre maximal de personnes
        int maxYears;

        int n = 0;

        // Parcours du vecteur years pour trouver l'année avec le nombre maximal de personnes vivantes
        for (int i = 0; i < years.size(); i++)
        {
            n += years[i]; // Ajout du nombre de personnes vivantes pour l'année i
            if (n > max)
            {
                max = n;      // Mise à jour du nombre maximal de personnes vivantes
                maxYears = i; // Mise à jour de l'année correspondant au nombre maximal de personnes vivantes
            }
        }

        // Retourne l'année avec le nombre maximal de personnes vivantes
        return maxYears + MIN_YEARS;
    }
};