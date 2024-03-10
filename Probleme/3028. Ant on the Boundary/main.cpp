class Solution
{
  public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int currentPos = 0; // Initialiser la position courante à zéro
        int count = 0;      // Initialiser le compteur à zéro pour compter les retours à la frontière

        // Parcourir tous les éléments de nums
        for (int n : nums)
        {
            currentPos += n;     // Mettre à jour la position courante en ajoutant la valeur actuelle
            if (currentPos == 0) // Vérifier si la position courante est de retour à la frontière
            {
                count++; // Incrémenter le compteur si nous sommes de retour à la frontière
            }
        }

        return count; // Retourner le nombre total de retours à la frontière
    }
};