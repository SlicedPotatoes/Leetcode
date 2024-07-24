class Solution
{
  public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums)
    {
        vector<pair<int, int>> arr; // Vecteur de paires pour stocker les nombres transformés et les originaux

        // Transformation des éléments de nums selon le mapping
        for (int i = 0; i < nums.size(); i++)
        {
            int element = nums[i];

            int n = 0;
            int p = 1;

            // Convertir chaque chiffre de l'élément
            do
            {
                int digit = element % 10; // Extraire le dernier chiffre
                n += mapping[digit] * p;  // Appliquer le mapping et mettre à la bonne position
                element /= 10;            // Supprimer le dernier chiffre
                p *= 10;                  // Passer à la position suivante
            } while (element > 0);

            arr.push_back({n, nums[i]}); // Ajouter le nombre transformé et l'original au vecteur de paires
        }

        // Tri des paires en fonction des valeurs transformées
        stable_sort(arr.begin(), arr.end(), [](auto &a, auto &b) { return a.first < b.first; });

        // Mise à jour de nums avec les éléments triés
        for (int i = 0; i < arr.size(); i++)
        {
            nums[i] = arr[i].second;
        }

        return nums; // Retourner le vecteur trié
    }
};