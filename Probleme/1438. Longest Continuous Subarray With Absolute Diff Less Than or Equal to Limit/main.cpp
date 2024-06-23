class MonotonicQueue
{
  public:
    deque<int> dqMin; // deque pour maintenir les valeurs minimales
    deque<int> dqMax; // deque pour maintenir les valeurs maximales

    // Constructeur par défaut
    MonotonicQueue()
    {
    }

    // Méthode pour ajouter un élément à la MonotonicQueue
    void push(int n)
    {
        // Nettoyer dqMin de tous les éléments plus grands que n
        while (!dqMin.empty() && dqMin.back() > n)
        {
            dqMin.pop_back();
        }
        // Nettoyer dqMax de tous les éléments plus petits que n
        while (!dqMax.empty() && dqMax.back() < n)
        {
            dqMax.pop_back();
        }
        // Ajouter n à la fin de dqMin et dqMax
        dqMin.push_back(n);
        dqMax.push_back(n);
    }

    // Méthode pour supprimer un élément de la MonotonicQueue
    void pop(int n)
    {
        // Si l'élément à supprimer est le premier de dqMin, le supprimer
        if (!dqMin.empty() && n == dqMin.front())
        {
            dqMin.pop_front();
        }
        // Si l'élément à supprimer est le premier de dqMax, le supprimer
        if (!dqMax.empty() && n == dqMax.front())
        {
            dqMax.pop_front();
        }
    }

    // Méthode pour obtenir la valeur minimale de la MonotonicQueue
    int getMin()
    {
        if (dqMin.empty())
        {
            return -1; // Retourner -1 si dqMin est vide
        }
        return dqMin.front(); // Retourner le premier élément de dqMin
    }

    // Méthode pour obtenir la valeur maximale de la MonotonicQueue
    int getMax()
    {
        if (dqMax.empty())
        {
            return -1; // Retourner -1 si dqMax est vide
        }
        return dqMax.front(); // Retourner le premier élément de dqMax
    }
};

class Solution
{
  public:
    int longestSubarray(vector<int> &nums, int limit)
    {
        MonotonicQueue mq = MonotonicQueue(); // Instance de la classe MonotonicQueue

        int ans = 0;  // Variable pour stocker la longueur maximale
        int left = 0; // Indice de début du sous-tableau

        // Parcourir chaque élément du tableau
        for (int right = 0; right < nums.size(); right++)
        {
            mq.push(nums[right]); // Ajouter l'élément actuel à la MonotonicQueue

            // Tant que la différence entre la valeur maximale et la valeur minimale de la MonotonicQueue dépasse la
            // limite
            while (mq.getMax() - mq.getMin() > limit)
            {
                mq.pop(nums[left++]); // Supprimer l'élément à l'indice 'left' de la MonotonicQueue
            }

            // Mettre à jour la longueur maximale du sous-tableau
            ans = max(ans, right - left);
        }

        // Retourner la longueur maximale trouvée
        return ans + 1;
    }
};