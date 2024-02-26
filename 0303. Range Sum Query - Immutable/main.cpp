class NumArray
{
  public:
    vector<int> prefixSum; // Vecteur pour stocker les sommes préfixes

    // Constructeur prenant un vecteur d'entiers en entrée
    NumArray(vector<int> &nums)
    {
        prefixSum.reserve(nums.size() + 1); // Réserver de l'espace pour le vecteur prefixSum

        // Calculer les sommes préfixes
        for (int i = 0; i < nums.size(); i++)
        {
            prefixSum[i + 1] = nums[i] + prefixSum[i]; // Ajouter la somme partielle au vecteur prefixSum
        }
    }

    // Méthode pour calculer la somme dans une plage donnée
    int sumRange(int left, int right)
    {
        return prefixSum[right + 1] - prefixSum[left]; // Calculer la somme dans la plage [left, right]
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */