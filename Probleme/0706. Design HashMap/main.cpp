// Structure de noeud pour stocker la paire clé-valeur et le lien vers le prochain noeud
struct Node
{
    int key;
    int value;
    Node *next;
};
// Classe implémentant une HashMap personnalisée
class MyHashMap
{
  private:
    int size;           // Taille de la table de hachage
    vector<Node *> arr; // Table de hachage, contenant des pointeurs vers des noeud
    // Fonction de hachage pour calculer l'index dans la table de hachage
    int hash(int key)
    {
        return key % this->size;
    }

    // Fonction pour vérifier si une clé existe déjà dans la table de hachage
    Node *isKeyExist(int key, int h)
    {
        Node *current = this->arr[h]; // Début de la chaîne de noeud à l'index h

        // Parcours de la chaîne jusqu'à trouver la clé ou la fin de la chaîne
        while (current && current->key != key)
        {
            current = current->next;
        }

        // Retourne le noeud s'il existe, sinon nullptr
        return current;
    }

  public:
    // Constructeur initialisant la taille de la table de hachage et redimensionnant le vecteur
    MyHashMap()
    {
        this->size = 1024;            // Taille arbitraire choisie pour la table de hachage
        this->arr.resize(this->size); // Redimensionnement de la table de hachage
    }

    // Fonction pour ajouter une nouvelle paire clé-valeur dans la table de hachage
    void put(int key, int value)
    {
        int h = this->hash(key);               // Calcul de l'index dans la table de hachage
        Node *node = this->isKeyExist(key, h); // Vérifie si la clé existe déjà

        if (node)
        {
            node->value = value; // Met à jour la valeur si la clé existe déjà
        }
        else
        {
            // Crée un nouveau noeud avec la paire clé-valeur
            node = new Node(key, value, this->arr[h]);
            // Met à jour la tête de la chaîne à l'index h
            this->arr[h] = node;
        }
    }

    // Fonction pour récupérer la valeur associée à une clé donnée
    int get(int key)
    {
        int h = this->hash(key);               // Calcul de l'index dans la table de hachage
        Node *node = this->isKeyExist(key, h); // Vérifie si la clé existe

        if (node)
        {
            return node->value; // Retourne la valeur si la clé existe
        }
        return -1; // Retourne -1 si la clé n'existe pas
    }

    void remove(int key)
    {
        int h = this->hash(key);      // Calcul de l'index dans la table de hachage
        Node *current = this->arr[h]; // Début de la chaîne de noeud à l'index h
        Node *prev = nullptr;         // Pointeur vers le noeud précédent

        // Parcours de la chaîne jusqu'à trouver la clé ou la fin de la chaîne
        while (current && current->key != key)
        {
            prev = current;
            current = current->next;
        }

        // Gestion des différents cas de suppression
        if (!prev && current)
        {
            // Si le noeud à supprimer est en tête de la chaîne
            this->arr[h] = current->next;
        }
        else if (current)
        {
            prev->next = current->next; // Si le noeud à supprimer est au milieu de la chaîne
        }
        else
        {
            return; // Si la clé n'existe pas dans la table de hachage
        }

        delete current; // Libère la mémoire du noeud supprimé
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */