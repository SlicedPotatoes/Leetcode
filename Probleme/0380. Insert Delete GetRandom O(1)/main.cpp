// Définition de la structure de noeud pour la liste chaînée
struct NodeList
{
    int value;      // Valeur du noeud
    int index;      // Index du noeud dans le vecteur randomArr
    NodeList *next; // Pointeur vers le prochain noeud
};

// Classe implémentant un ensemble aléatoire
class RandomizedSet
{
  public:
    vector<NodeList *> bucket;    // Vecteur de pointeurs de noeuds pour le hachage
    vector<NodeList *> randomArr; // Vecteur de pointeurs de noeuds pour la sélection aléatoire

    // Constructeur
    RandomizedSet()
    {
        srand(time(NULL));                               // Initialisation du générateur de nombres aléatoires
        this->bucket = vector<NodeList *>(256, nullptr); // Initialisation du vecteur de hachage avec une taille de 256
    }

    // Methode de hachage pour obtenir l'indice du seau en fonction de la valeur
    int getHash(int val)
    {
        return abs(val) % this->bucket.size();
    }

    // Methode pour insérer une valeur dans l'ensemble
    bool insert(int val)
    {
        // Calcul de l'indice de hachage
        int hash = this->getHash(val);

        // Récupération du premier noeud dans le seau correspondant
        NodeList *node = this->bucket[hash];

        // Parcours de la liste chaînée pour vérifier si la valeur existe déjà
        while (node)
        {
            if (node->value == val)
            {
                // La valeur existe déjà, donc l'insertion échoue
                return false;
            }
            // Passer au prochain noeud dans la liste chaînée
            node = node->next;
        }

        // Création d'un nouveau noeud avec la valeur et son index dans randomArr
        NodeList *newNode = new NodeList(val, this->randomArr.size(), this->bucket[hash]);
        // Ajout du nouveau noeud au début du seau correspondant
        this->bucket[hash] = newNode;
        // Ajout du nouveau noeud à randomArr
        this->randomArr.push_back(newNode);

        // Redimensionnement du vecteur de hachage si nécessaire
        this->resizeBucket();

        // Insertion réussie
        return true;
    }

    // Methode pour supprimer une valeur de l'ensemble
    bool remove(int val)
    {
        // Calcul de l'indice de hachage
        int hash = this->getHash(val);

        // Pointeur vers le noeud précédent dans la liste chaînée
        NodeList *prev = nullptr;
        // Pointeur vers le premier noeud dans le seau correspondant
        NodeList *current = this->bucket[hash];

        // Parcours de la liste chaînée pour trouver le noeud à supprimer
        while (current)
        {
            if (current->value == val)
            {
                // noeud trouvé, sortie de la boucle
                break;
            }
            // Mise à jour du noeud précédent
            prev = current;
            // Passage au prochain noeud dans la liste chaînée
            current = current->next;
        }

        // Vérification si le noeud à supprimer a été trouvé
        if (current)
        {
            if (prev)
            {
                // Relier le noeud précédent au noeud suivant
                prev->next = current->next;
            }
            else
            {
                // Mettre à jour le premier noeud du seau si le noeud à supprimer est en tête
                this->bucket[hash] = current->next;
            }

            // Mise à jour de l'index du dernier noeud dans randomArr et échange avec le noeud à supprimer
            this->randomArr.back()->index = current->index;
            swap(this->randomArr[current->index], this->randomArr.back());
            // Suppression du dernier noeud de randomArr
            this->randomArr.pop_back();

            // Libération de la mémoire occupée par le noeud supprimé
            delete current;
            // Suppression réussie
            return true;
        }
        // La valeur à supprimer n'a pas été trouvée
        return false;
    }

    // Methode pour obtenir une valeur aléatoire dans l'ensemble
    int getRandom()
    {
        return this->randomArr[rand() % this->randomArr.size()]->value;
    }

    // Methode pour redimensionner le vecteur de hachage si nécessaire
    void resizeBucket()
    {
        // Vérification si le facteur de charge dépasse 0.7
        if ((double)this->randomArr.size() / this->bucket.size() >= 0.7)
        {
            // Redimensionnement du vecteur de hachage avec une taille doublée
            this->bucket = vector<NodeList *>(this->bucket.size() * 2, nullptr);

            // Réaffectation des noeuds dans le nouveau vecteur de hachage
            for (NodeList *node : randomArr)
            {
                // Calcul de l'indice de hachage pour chaque noeud
                int hash = this->getHash(node->value);
                // Mise à jour du pointeur next du noeud
                node->next = this->bucket[hash];
                // Ajout du noeud au début du seau correspondant
                this->bucket[hash] = node;
            }
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */