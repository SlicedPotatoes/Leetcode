class Solution
{
  public:
    int findMaxK(vector<int> &nums)
    {
        // Initialise la variable pour stocker le plus grand nombre `K` trouvé
        int ans = -1;

        // Crée un vecteur de booléens pour suivre les éléments vus, avec un décalage pour gérer les nombres négatifs
        vector<bool> v(2000, false);

        // Parcours des éléments du vecteur `nums`
        for (int n : nums)
        {
            // Si la valeur absolue de l'élément courant est plus grande que ans
            if (abs(n) > ans)
            {
                v[n + 1000] = true; // Met à jour la présence de l'élément courant dans le vecteur `v`

                // Si l'indice opposé est présent, mettre à jour ans
                if (v[-n + 1000])
                {
                    ans = abs(n);
                }
            }
        }

        return ans;
    }
};