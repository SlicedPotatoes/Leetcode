class Solution
{
  public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        // Initialisation du nombre d'occurrences du premier élément (index 0) dans les sous-tableaux
        int nbOfOccurrences = ceil(float(arr.size()) / 2);
        arr[0] *= nbOfOccurrences; // Mise à jour du premier élément

        // Parcours du tableau à partir de l'indice 1
        for (int i = 1; i < arr.size(); i++)
        {
            // Calcul du nombre d'occurrences de l'élément à l'indice i dans les sous-tableaux
            nbOfOccurrences += ceil(float(arr.size() - i) / 2) - ceil((float)i / 2);

            // Calcul de la somme cumulative des précédents et ajout du produit de l'élément actuel par son nombre
            // d'occurrences
            arr[i] = arr[i] * nbOfOccurrences + arr[i - 1];
        }

        // Retourne la somme cumulative de tous les sous-tableaux impairs
        return arr[arr.size() - 1];
    }
};