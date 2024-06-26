long long countSubarrays(vector<int> &nums, int k)
{
    // Trouver l'élément maximum dans le vecteur nums
    int maxElement = -1;
    for (int n : nums)
    {
        maxElement = max(n, maxElement);
    }

    long long ans = 0;
    int left = 0;
    int curr = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == maxElement)
        {
            curr++; // Compte le nombre d'occurrences de maxElement dans la fenêtre actuelle
        }

        // Tant qu'on a au moins k occurrences de maxElement
        while (curr >= k)
        {
            if (nums[left++] == maxElement)
            {
                curr--; // Réduire le nombre d'occurrences de maxElement
            }

            // Ajouter le nombre de sous-tableaux valides
            ans += nums.size() - right;
        }
    }

    return ans;
}