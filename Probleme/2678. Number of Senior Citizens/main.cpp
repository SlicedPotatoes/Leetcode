class Solution
{
  public:
    int countSeniors(vector<string> &details)
    {
        int ans = 0;

        // Parcourir chaque chaîne de caractères dans le vecteur 'details'.
        for (string &s : details)
        {
            // Extraire l'âge.
            int age = ((s[11] - '0') * 10) + s[12] - '0';
            // Vérifier si l'âge est supérieur à 60 ans.
            if (age > 60)
            {
                ans++; // Incrémenter le compteur si l'âge est supérieur à 60.
            }
        }

        return ans; // Retourner le nombre total de personnes âgées de plus de 60 ans.
    }
};