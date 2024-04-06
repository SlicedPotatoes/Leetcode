class Solution
{
  public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;

        int left = 0;
        int right = 0;

        // Parcourir le vecteur nums
        while (right < nums.size())
        {
            left = right;
            long current = nums[right];

            // Trouver la plage continue
            while (right < nums.size() && nums[right] == current)
            {
                right++;
                current++;
            }

            // Réduire right pour pointer vers la fin de la plage
            right--;

            // Si left et right pointent vers le même élément, ajouter simplement cet élément à la réponse
            if (right == left)
            {
                ans.push_back(to_string(nums[right]));
            }
            // Sinon, ajouter la plage sous forme "début->fin"
            else
            {
                ans.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
            }
            // Avancer right pour passer au prochain élément du vecteur
            right++;
        }

        return ans;
    }
};