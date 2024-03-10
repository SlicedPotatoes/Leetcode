class Solution
{
  public:
    int minOperations(vector<int> &nums, int k)
    {
        // Déclaration d'une file de priorité min contenant des entiers non signés 32 bits
        priority_queue<uint32_t, vector<uint32_t>, greater<uint32_t>> pq(nums.begin(), nums.end());

        int count = 0; // Initialisation du compteur d'opérations

        // Boucle principale
        while (pq.top() < k)
        {
            uint32_t x = pq.top(); // Obtention de l'élément le plus petit de la file
            pq.pop();              // Suppression de l'élément le plus petit de la file
            uint32_t y = pq.top(); // Obtention de l'élément le plus petit de la file
            pq.pop();              // Suppression de l'élément le plus petit de la file

            // Si y est supérieur ou égal à k, arrêter le processus et incrémenté le compteur
            // (Leur opération sera forcément > k)
            if (y >= k)
            {
                count++;
                break;
            }

            // Ajouter un nouvel élément à la file de priorité résultant de la fusion de x et y
            pq.push(x * 2 + y);
            count++; // Incrémenter le compteur d'opérations
        }

        return count; // Retourner le nombre total d'opérations effectuées
    }
};