/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
  public:
    // Fonction pour inverser les k premiers éléments d'une liste
    ListNode *reverse(ListNode *head, int k)
    {
        ListNode *curr = head;    // Noeud actuel
        ListNode *prev = nullptr; // Noeud précédent

        // Compteur pour suivre le nombre d'éléments inversés
        int currentK = 0;

        while (currentK < k)
        {
            currentK++;
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Retourne la nouvelle tête de la séquence inversée
        return prev;
    }

    // Fonction pour inverser la liste par groupe de k éléments
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1)
        {
            return head; // Si k = 1, pas besoin d'inversion, retourne la liste originale
        }

        ListNode *dummy = new ListNode(0); // Noeud factice pour le début de la liste
        ListNode *curr = head;             // Noeud actuel de la liste
        ListNode *prev = dummy;            // Noeud précédent (initialisé au Noeud factice)

        while (true)
        {
            int currentK = 0;    // Compteur pour suivre le nombre d'éléments dans le groupe actuel
            ListNode *_h = curr; // Pointeur vers le début du groupe actuel

            // Vérifier si l'on peu formait un groupe complet de K éléments
            while (curr && currentK < k)
            {
                curr = curr->next; // Avance jusqu'au prochain Noeud
                currentK++;        // Incrémente le compteur
            }

            if (currentK == k)
            {
                // Inverse le groupe actuel et attache-le à la fin du groupe précédent
                prev->next = reverse(_h, k);
            }
            else
            {
                prev->next = _h; // Si le groupe actuel a moins de k éléments, laisse-le tel quel
                break;           // Sort de la boucle principale
            }

            // Met à jour le pointeur vers le dernier Noeud du groupe inversé
            prev = _h;
        }

        return dummy->next; // Retourne la liste inversée par groupe de k éléments
    }
};