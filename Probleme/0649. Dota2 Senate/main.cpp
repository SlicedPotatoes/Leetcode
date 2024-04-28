class Solution
{
  public:
    string predictPartyVictory(string &senate)
    {
        queue<char> q;

        int countR = 0; // Compteur pour les membres du parti "Radiant"
        int countD = 0; // Compteur pour les membres du parti "Dire"

        // Parcours de la chaîne de caractères "senate"
        for (int i = 0; i < senate.size(); i++)
        {
            q.push(senate[i]); // Ajout des membres du sénat à la file d'attente

            // Incrémentation des compteurs en fonction du parti
            if (senate[i] == 'R')
            {
                countR++;
                continue;
            }
            countD++;
        }

        int skipR = 0; // Nombre de membres du parti "Radiant" à ignorer
        int skipD = 0; // Nombre de membres du parti "Dire" à ignorer

        // Tant qu'il reste des membres des deux partis dans le sénat
        while (countR && countD)
        {
            char current = q.front(); // Récupération du membre actuel
            q.pop();                  // Suppression du membre traité de la file d'attente

            // Si le membre actuel est du parti "Radiant"
            if (current == 'R')
            {
                // Si le membre n'a pas été ignoré
                if (skipR == 0)
                {
                    skipD++;     // Ignorer un membre du parti "Dire"
                    q.push('R'); // Ajout du membre à la fin de la file d'attente
                    continue;
                }
                skipR--;  // Réduction du nombre de membres du parti "Radiant" à ignorer
                countR--; // Réduction du nombre total de membres du parti "Radiant"
            }
            // Si le membre actuel est du parti "Dire"
            else
            {
                // Si le membre n'a pas été ignoré
                if (skipD == 0)
                {
                    skipR++;     // Ignorer un membre du parti "Radiant"
                    q.push('D'); // Ajout du membre à la fin de la file d'attente
                    continue;
                }
                skipD--;  // Réduction du nombre de membres du parti "Dire" à ignorer
                countD--; // Réduction du nombre total de membres du parti "Dire"
            }
        }

        // Si le parti "Dire" a encore des membres, il gagne, sinon le parti "Radiant" gagne
        return countD ? "Dire" : "Radiant";
    }
};