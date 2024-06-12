class Solution
{
  public:
    int minimumLevels(vector<int> &possible)
    {
        // Somme totale des éléments, en comptant 0 comme -1 et autres valeurs comme 1
        int sum = 0;
        for (int n : possible)
        {
            sum += n == 0 ? -1 : 1;
        }

        // Variable pour suivre la somme courante lors du parcours du tableau
        int current = 0;

        // Parcourir le tableau jusqu'à l'avant-dernier élément
        for (int i = 0; i < possible.size(); i++)
        {
            // Mise à jour de la somme courante
            current += possible[i] == 0 ? -1 : 1;
            // Mise à jour de la somme restante
            sum -= possible[i] == 0 ? -1 : 1;

            // Vérification de la condition pour retourner l'indice (i + 1)
            if (current > sum)
            {
                return i + 1;
            }
        }

        // Retourner -1 si aucune condition n'est remplie
        return -1;
    }
};