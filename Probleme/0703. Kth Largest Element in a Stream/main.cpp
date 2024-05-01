class KthLargest
{
  private:
    // La valeur de k pour trouver le k-ième élément le plus grand
    int k;
    // Une file de priorité pour stocker les k plus grands éléments
    priority_queue<int, vector<int>, greater<int>> pq;

  public:
    // Constructeur prenant k et un vecteur de nombres
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        // Parcourir tous les nombres et les ajouter à la file de priorité
        for (int n : nums)
        {
            pq.push(n);
            // Si la taille de la file de priorité dépasse k, retirer le plus petit élément
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }

    // Méthode pour ajouter un nouveau nombre à l'ensemble et retourner le k-ième plus grand élément actuel
    int add(int val)
    {
        pq.push(val); // Ajouter le nouveau nombre à la file de priorité

        // Si la taille de la file de priorité dépasse k, retirer le plus petit élément
        if (pq.size() > k)
        {
            pq.pop();
        }

        // Retourner le k-ième plus grand élément actuel
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */