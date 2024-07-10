class Solution
{
  public:
    int minOperations(vector<string> &logs)
    {
        // Initialisation de la profondeur à 0
        int depth = 0;

        // Parcourir chaque log dans le vecteur logs
        for (string &s : logs)
        {
            // Si le log est "../", on remonte d'un dossier (si on n'est pas déjà à la racine)
            if (s == "../")
            {
                if (depth > 0)
                {
                    depth--;
                }
            }
            // Si le log est "./", on reste dans le même dossier, donc rien ne change
            else if (s == "./")
            {
                continue;
            }
            // Si le log est un nom de dossier, on descend dans ce dossier
            else
            {
                depth++;
            }
        }

        // Retourner la profondeur finale après traitement de tous les logs
        return depth;
    }
};