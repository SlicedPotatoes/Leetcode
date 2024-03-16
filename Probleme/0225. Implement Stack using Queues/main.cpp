class MyStack
{
  public:
    queue<int> q; // Déclaration de la file pour stocker les éléments du stack
    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x); // Ajoute l'élément à la file

        // Déplace l'élément ajouté au début de la file pour simuler un stack
        for (int i = 1; i < q.size(); i++)
        {
            // Ajoute le premier élément à la fin de la file
            q.push(q.front());
            // Supprime le premier élément de la file
            q.pop();
        }
    }

    int pop()
    {
        // Récupère le premier élément de la file
        int element = q.front();
        // Supprime le premier élément de la file
        q.pop();
        // Retourne l'élément supprimé
        return element;
    }

    int top()
    {
        // Retourne le premier élément de la file
        return q.front();
    }

    bool empty()
    {
        // Vérifie si la file est vide
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */