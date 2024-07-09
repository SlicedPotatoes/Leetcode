class Solution
{
  public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        long totalWaitTime = 0; // Variable pour stocker le temps d'attente total
        int currEnd = 0;        // Variable pour stocker la fin du traitement actuel

        // Boucle sur chaque client
        for (vector<int> &customer : customers)
        {
            // Si le chef est libre
            if (currEnd <= customer[0])
            {
                currEnd = customer[0] + customer[1]; // Met à jour l'heure de fin actuelle
                totalWaitTime += customer[1];        // Le temps d'attente est le temps de traitement uniquement
            }
            // Si le chef est occupé à l'arrivée du client
            else
            {
                totalWaitTime +=
                    currEnd - customer[0] +
                    customer[1]; // Temps d'attente = temps de traitement + (temps jusqu'à ce que le chef soit libre)
                currEnd += customer[1]; // Met à jour l'heure de fin actuelle
            }
        }

        // Retourne le temps d'attente moyen
        return (double)totalWaitTime / customers.size();
    }
};