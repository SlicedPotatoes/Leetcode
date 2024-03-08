class Solution
{
  public:
    bool isSubsequence(string &s, string &t)
    {
        // Initialisation de l'index pour parcourir la sous-séquence 's'
        int indexSub = 0;

        // Parcours de la chaîne 't'
        for (int i = 0; i < t.size(); i++)
        {
            // Si le caractère courant de 't' correspond au caractère courant de 's'
            if (t[i] == s[indexSub])
            {
                // Si le caractère courant de 't' correspond au caractère courant de 's'
                indexSub++;
            }
        }

        // Si l'index de la sous-séquence 's' est égal à sa taille, alors 's' est une sous-séquence de 't'
        return indexSub == s.size();
    }
};