class Solution
{
  public:
    int distributeCandies(vector<int> &candyType)
    {
        vector<bool> arr(200001, false); // Créer un vecteur booléen de taille 200001, initialisé à false

        int count = 0; // Initialiser un compteur à zéro pour compter les différents types de bonbons

        // Parcourir les différents types de bonbons
        for (int ct : candyType)
        {
            // Vérifier si ce type de bonbon n'a pas déjà été rencontré
            if (!arr[ct + 100000])
            {
                arr[ct + 100000] = true; // Marquer ce type de bonbon comme rencontré
                count++;                 // Incrémenter le compteur de types de bonbons différents
            }
        }

        // Retourner le minimum entre le nombre de types de bonbons différents et la moitié de la taille du vecteur de
        // bonbons
        return min(count, (int)candyType.size() / 2);
    }
};