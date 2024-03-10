class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        // Création d'un vecteur pour stocker les carrés des nombres
        vector<int> output(nums.size());

        // Recherche du premier index du dernier élément négatif
        int GLZ = -1; // GLZ : Greatest Less than Zero (Plus Grand que Zéro Négatif)
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                GLZ++;
            }
            else
            {
                break; // Arrête la boucle dès qu'on trouve un nombre positif ou nul
            }
        }

        int i = GLZ + 1; // Initialisation de l'indice pour parcourir les nombres positifs ou nuls

        // Parcours du vecteur nums et construction du vecteur de carrés en ordre croissant
        while (i < nums.size() || GLZ != -1)
        {
            if (GLZ >= 0 && (i == nums.size() || -nums[GLZ] < nums[i]))
            {
                // Si GLZ est valide et le prochain élément positif est plus grand ou inexistant, ajouter le carré de
                // GLZ
                output[i - GLZ - 1] = nums[GLZ] * nums[GLZ];
                GLZ--;
            }
            else
            {
                // Sinon, ajouter le carré du prochain élément positif
                output[i - GLZ - 1] = nums[i] * nums[i];
                i++;
            }
        }

        // Renvoie du vecteur contenant les carrés en ordre croissant
        return output;
    }
};