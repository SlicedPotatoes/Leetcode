class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        // Initialisation de la retenue à 1 car on ajoute 1 à la valeur
        int carrying = 1;

        // Parcourir le vecteur digits à partir de la fin
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carrying; // Somme de la valeur actuelle et de la retenue

            carrying = sum / 10;  // Mise à jour de la retenue (division entière par 10)
            digits[i] = sum % 10; // Mise à jour de la valeur dans digits (reste de la division par 10)

            // Si la retenue est devenue 0, inutile de continuer
            if (!carrying)
            {
                break;
            }
        }

        // Si une retenue subsiste après le parcours du vecteur
        if (carrying)
        {
            digits.insert(digits.begin(), 1); // Insérer 1 au début de digits
        }

        return digits; // Retourner le vecteur modifié
    }
};