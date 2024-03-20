// Structure pour représenter une paire index-valeur
struct PVI
{
    int index;
    int value;
};
// Foncteur de comparaison pour utiliser PVI avec une priority_queue
struct comparePVI
{
    bool operator()(PVI const &a, PVI const &b)
    {
        // Comparaison d'abord par valeur, puis par index si les valeurs sont égales
        if (a.value == b.value)
        {
            return a.index > b.index;
        }
        return a.value > b.value;
    }
};

class Solution
{
  public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        // Initialiser la somme totale
        long long totalSum = 0;

        // Utiliser une priority_queue pour stocker les éléments triés par valeur
        priority_queue<PVI, vector<PVI>, comparePVI> pq;

        // Calculer la somme totale et initialiser la file de priorité
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push({i, nums[i]});
            totalSum += nums[i];
        }

        // Initialiser un vecteur pour marquer les éléments déjà pris en compte
        vector<bool> markedElements(nums.size(), false);
        // Initialiser un vecteur pour stocker les réponses
        vector<long long> ans(queries.size());

        // Parcourir toutes les requêtes
        for (int qIndex = 0; qIndex < queries.size(); qIndex++)
        {
            int index = queries[qIndex][0]; // Récupérer l'index de la requête
            int ki = queries[qIndex][1];    // Récupérer ki de la requête

            // Vérifier si l'élément est déjà marqué
            if (!markedElements[index])
            {
                markedElements[index] = true; // Marquer l'élément
                totalSum -= nums[index];      // Soustraire sa valeur de la somme totale
            }

            // Parcourir les ki plus petits éléments de la priority_queue
            for (int i = 0; i < ki && !pq.empty(); i++)
            {
                PVI element = pq.top(); // Récupérer l'élément avec la plus petite valeur
                pq.pop();               // Retirer l'élément de la file de priorité

                // Vérifier si l'élément est déjà marqué
                if (markedElements[element.index])
                {
                    // Si marqué, réduire le compteur et passer à l'élément suivant
                    i--;
                    continue;
                }

                markedElements[element.index] = true; // Marquer l'élément
                totalSum -= element.value;            // Soustraire sa valeur de la somme totale
            }
            ans[qIndex] = totalSum; // Stocker la somme totale actuelle dans la réponse
        }

        return ans;
    }
};