class Solution
{
  public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int leftSum = 0;  // Somme des éléments à gauche de l'élément actuel
        int rightSum = 0; // Somme des éléments à droite de l'élément actuel

        // Calcul de la somme totale des éléments du vecteur
        for (int n : nums)
        {
            rightSum += n;
        }

        // Itération pour calculer les différences
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = nums[i]; // Stocke l'élément actuel

            // Met à jour rightSum en retirant l'élément actuel
            rightSum -= temp;

            // Calcul de la différence absolue
            nums[i] = abs(leftSum - rightSum);

            // Met à jour leftSum en ajoutant l'élément actuel
            leftSum += temp;
        }

        return nums; // Retourne le vecteur avec les différences absolues
    }
};