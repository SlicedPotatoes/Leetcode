class Solution
{
  public:
    int numberOfEmployeesWhoMetTarget(vector<int> &hours, int target)
    {
        int ans = 0; // Initialise le compteur à 0

        // Parcourt chaque nombre d'heures dans le vecteur
        for (int n : hours)
        {
            // Vérifie si le nombre d'heures est supérieur ou égal à la cible
            if (n >= target)
            {
                ans++; // Incrémente le compteur
            }
        }

        return ans; // Retourne le nombre d'employés ayant atteint la cible
    }
};