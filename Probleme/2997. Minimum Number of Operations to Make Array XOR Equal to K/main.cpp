class Solution
{
  public:
    int minOperations(vector<int> &nums, int k)
    {
        // Calculer le XOR de tous les éléments dans nums
        int x = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            x ^= nums[i];
        }

        // Initialiser le compteur d'opérations minimales
        int ans = 0;

        // Parcourir chaque bit dans la représentation binaire de k et x
        for (int i = 0; i < 32; i++)
        {
            // Vérifier si les bits courants de k et x diffèrent
            if ((k & 1) != (x & 1))
            {
                ans++;
            }

            // Décaler les bits de k et x vers la droite pour examiner le bit suivant
            k >>= 1;
            x >>= 1;
        }

        return ans;
    }
};