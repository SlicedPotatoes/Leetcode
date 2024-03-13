class Solution
{
  public:
    int compress(vector<char> &chars)
    {
        // newIndex est utilisé pour suivre la position où insérer les caractères compressés
        int newIndex = 0;

        // Parcourir les caractères un par un
        for (int i = 0; i < chars.size();)
        {
            char currentChar = chars[i];
            int j = i;

            // Trouver la longueur de la séquence de caractères identiques
            while (j < chars.size() && chars[j] == currentChar)
            {
                j++;
            }

            // Stocker le caractère actuel dans la nouvelle position
            chars[newIndex] = currentChar;
            newIndex++;

            // Calculer la différence entre j et i pour obtenir la longueur de la séquence
            int diff = j - i;

            // Si la séquence a une longueur supérieure à 1, compresser et ajouter le nombre de répétitions
            if (diff > 1)
            {
                // Convertir la longueur en chaîne de caractères
                string s = to_string(diff);
                for (char c : s)
                {
                    chars[newIndex] = c;
                    newIndex++;
                }
            }

            // Passer au prochain caractère différent
            i = j;
        }
        return newIndex;
    }
};