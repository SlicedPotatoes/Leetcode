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
    // Fonction pour effectuer une recherche binaire dans un vecteur trié
    bool binarySearch(vector<int> &nums, int n)
    {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + ((end - start) / 2);

            if (nums[mid] == n)
            {
                return true;
            }

            if (nums[mid] > n)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return false;
    }

    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        // Trier les valeurs dans 'nums' pour permettre la recherche binaire
        sort(nums.begin(), nums.end());

        // Créer un noeud 'dummy' pour simplifier la gestion des suppressions en tête de liste
        ListNode *dummy = new ListNode(-1, head);
        ListNode *curr = dummy->next; // Noeud courant, commence au premier noeud de la liste
        ListNode *prev = dummy;       // Noeud précédent, commence au noeud 'dummy'

        // Parcourir la liste chaînée
        while (curr)
        {
            // Si la valeur du noeud courant est dans 'nums'
            if (binarySearch(nums, curr->val))
            {
                // Supprimer le noeud courant
                prev->next = curr->next;
            }
            else
            {
                // Sinon, avancer le pointeur 'prev' au noeud courant
                prev = curr;
            }
            // Avancer le pointeur 'curr' au prochain noeud
            curr = curr->next;
        }

        // Retourner la tête de la liste modifiée
        return dummy->next;
    }
};