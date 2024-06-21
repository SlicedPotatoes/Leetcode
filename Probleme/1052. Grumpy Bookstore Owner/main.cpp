class Solution
{
  public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int total = 0; // Total des clients satisfaits sans tenir compte des périodes de mauvaise humeur
        int curr = 0;  // Nombre de clients potentiellement récupérables dans la fenêtre actuelle

        // Calculer le total des clients satisfaits et les clients potentiellement récupérables dans la première fenêtre
        // de 'minutes' minutes
        for (int right = 0; right < minutes; right++)
        {
            if (grumpy[right])
            {
                curr += customers[right];
            }
            else
            {
                total += customers[right];
            }
        }

        int best = curr; // Initialiser la meilleure récupération avec la première fenêtre
        int left = 0;

        // Utiliser une fenêtre glissante pour maximiser le nombre de clients satisfaits
        for (int right = minutes; right < customers.size(); right++, left++)
        {
            if (grumpy[left])
            {
                curr -= customers[left]; // Retirer les clients de la fenêtre sortante
            }
            if (grumpy[right])
            {
                curr += customers[right]; // Ajouter les clients de la nouvelle fenêtre entrante
                best = max(best, curr);   // Mettre à jour la meilleure récupération si nécessaire
            }
            else
            {
                total += customers[right]; // Ajouter les clients satisfaits sans tenir compte des périodes de mauvaise
                                           // humeur
            }
        }

        // Retourner le total des clients satisfaits plus la meilleure récupération trouvée
        return total + best;
    }
};