class MinStack
{
  private:
    // Pile pour contenir tous les éléments
    vector<int> mainStack;
    // Pile pour contenir les éléments minimums rencontrés jusqu'à présent
    vector<int> minStack;

  public:
    MinStack()
    {
    }

    // Fonction pour ajouter un élément sur la pile
    void push(int val)
    {
        mainStack.push_back(val);
        // Si minStack est vide ou si la valeur à ajouter est inférieure ou égale au sommet de minStack,
        // ajoutez également cette valeur à minStack
        if (minStack.size() == 0 || minStack[minStack.size() - 1] >= val)
        {
            minStack.push_back(val);
        }
    }

    // Fonction pour retirer le sommet de la pile
    void pop()
    {
        // Si le sommet de minStack est égal au sommet de mainStack, retirez également le sommet de minStack
        if (minStack[minStack.size() - 1] == mainStack[mainStack.size() - 1])
        {
            minStack.pop_back();
        }
        // Retirez toujours le sommet de mainStack
        mainStack.pop_back();
    }

    // Fonction pour obtenir le sommet de la pile
    int top()
    {
        return mainStack[mainStack.size() - 1];
    }

    // Fonction pour obtenir le minimum dans la pile
    int getMin()
    {
        return minStack[minStack.size() - 1];
    }
};