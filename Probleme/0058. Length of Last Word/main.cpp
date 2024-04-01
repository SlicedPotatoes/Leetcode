class Solution
{
  public:
    int lengthOfLastWord(string s)
    {
        // Initialisation de l'indice à la fin de la chaîne
        int i = s.size() - 1;
        // Ignorer les espaces à la fin de la chaîne
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }

        // Initialisation du compteur de longueur du dernier mot
        int count = 0;
        // Calcul de la longueur du dernier mot
        while (i >= 0 && s[i] != ' ')
        {
            count++;
            i--;
        }

        // Retourne la longueur du dernier mot
        return count;
    }
};