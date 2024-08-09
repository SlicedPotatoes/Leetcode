class Solution
{
  public:
    // Définition des directions de mouvement : droite, bas, gauche, haut
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    // Fonction pour ajuster les coordonnées lorsqu'on dépasse les limites sur les axes positif
    void jumpA(int &i, int &curr, int length)
    {
        // Si on sort du côté négatif, on ramène curr à -1 et ajuste l'indice i
        if (curr < 0)
        {
            i += abs(curr) - 1;
            curr = -1;
        }
        // Sinon, on avance curr au maximum permis par la longueur restante et ajuste i
        else
        {
            curr += length - i - 1;
            i = length;
        }
    }

    // Fonction pour ajuster les coordonnées lorsqu'on dépasse les limites sur les axes négatif
    void jumpB(int &i, int &curr, int length, int n)
    {
        // Si curr dépasse la limite supérieure, on l'ajuste à la limite et ajuste l'indice i
        if (curr >= n)
        {
            i += curr - n;
            curr = n;
        }
        // Sinon, on recule curr de la longueur restante et ajuste i
        else
        {
            curr -= length - i - 1;
            i = length;
        }
    }

    // Génère une matrice parcourue en spirale à partir d'une position de départ
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        // Calcul de la taille totale de la matrice
        int size = rows * cols;

        // Initialisation de la matrice de résultat avec la position de départ
        vector<vector<int>> ans = {{rStart, cStart}};

        // Variables pour garder la trace de la position actuelle
        int currR = rStart;
        int currC = cStart;
        // Variable pour indiquer la direction actuelle
        int d = 0;

        // Boucle jusqu'à ce que toutes les positions valides soient visitées
        while (ans.size() != size)
        {
            // Détermine la longueur de la prochaine étape dans la direction courante
            int length = (d / 2) + 1;
            // Sélectionne la direction actuelle (0: droite, 1: bas, 2: gauche, 3: haut)
            int curr = d % 4;

            // Avance dans la direction choisie pour la longueur déterminée
            for (int i = 0; i < length; i++)
            {
                currR += dir[curr][0]; // Mise à jour de la ligne courante
                currC += dir[curr][1]; // Mise à jour de la colonne courante

                // Si la nouvelle position est à l'intérieur de la matrice, l'ajoute au résultat
                if (currR >= 0 && currR < rows && currC >= 0 && currC < cols)
                {
                    ans.push_back({currR, currC});
                }
                // Si la position dépasse les limites elle est ajusté
                else
                {
                    if (curr == 0)
                    {
                        jumpA(i, currC, length); // Ajuste la colonne en cas de dépassement à droite
                    }
                    else if (curr == 1)
                    {
                        jumpA(i, currR, length); // Ajuste la ligne en cas de dépassement en bas
                    }
                    else if (curr == 2)
                    {
                        jumpB(i, currC, length, cols); // Ajuste la colonne en cas de dépassement à gauche
                    }
                    else
                    {
                        jumpB(i, currR, length, rows); // Ajuste la ligne en cas de dépassement en haut
                    }
                }
            }

            // Passe à la direction suivante
            d++;
        }

        return ans;
    }
};