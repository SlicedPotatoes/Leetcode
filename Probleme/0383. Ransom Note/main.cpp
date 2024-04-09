class Solution
{
  public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // Vérifie si la taille du ransomNote est supérieure à celle du magazine
        // Si c'est le cas, il est impossible de construire le ransomNote avec les lettres disponibles dans le
        // magazine
        if (ransomNote.size() > magazine.size())
        {
            return false;
        }

        // On crée un vecteur pour stocker la fréquence de chaque lettre de l'alphabet en minuscule
        vector<int> frequency(26, 0);

        // On parcourt chaque caractère dans le magazine pour calculer la fréquence
        for (char c : magazine)
        {
            // On incrémente la fréquence du caractère courant
            frequency[c - 'a']++;
        }

        // On parcourt chaque caractère dans la note de rançon pour vérifier s'il est disponible dans le magazine
        for (char c : ransomNote)
        {
            // Si la fréquence du caractère courant dans la note de rançon est nulle,
            // cela signifie qu'il n'est pas disponible dans le magazine, donc on renvoie false
            if (frequency[c - 'a'] == 0)
            {
                return false;
            }
            // Sinon, on décrémente la fréquence du caractère courant dans le magazine
            frequency[c - 'a']--;
        }

        // Si on parcourt tous les caractères de la note de rançon sans aucun problème,
        // alors la note de rançon peut être construite à partir du magazine, donc on renvoie true
        return true;
    }
};