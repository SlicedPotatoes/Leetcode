# 155. Min Stack

## Énoncé

Concevez une pile qui prend en charge le push, le pop, le top et la récupération de l'élément minimum en temps constant.

Implémentez la classe `MinStack`:

- `MinStack()` initialise l'objet pile.
- `void push(int val)` pousse l'élément val sur la pile.
- `void pop()` supprime l'élément en haut de la pile.
- `int top()` récupère l'élément en haut de la pile.
- `int getMin()` récupère l'élément minimum dans la pile.

Vous devez implémenter une solution avec une complexité temporelle `O(1)` pour chaque fonction.

## Exemple

**Exemple 1:**  
**Input:**  
["MinStack","push","push","push","getMin","pop","top","getMin"]  
[[],[-2],[0],[-3],[],[],[],[]]

**Output:**  
[null,null,null,null,-3,null,0,-2]

**Explication:**  
MinStack minStack = new MinStack();  
minStack.push(-2);  
minStack.push(0);  
minStack.push(-3);  
minStack.getMin(); // return -3  
minStack.pop();  
minStack.top(); // return 0  
minStack.getMin(); // return -2

## Contraintes

`-2^31 <= val <= 2^31 - 1`  
Les opérations des méthodes `pop`, `top` et `getMin` seront toujours appelées sur des piles **non vides**.  
Au plus `3 * 10^4` des appels seront effectués vers `push`, `pop`, `top` et `getMin`.

## Note personnelle

En prenant en compte la contrainte spécifiant qu'aucun appel aux méthodes `pop`, `top` et `getMin` ne serait effectué sur une pile vide, j'ai décidé de ne pas inclure les vérifications nécessaires pour optimiser le temps d'exécution.

Mon approche initiale consistait à utiliser une liste chaînée pour stocker les valeurs. Chaque noeud de cette liste est composé de la valeur, du minimum et d'un pointeur vers l'élément suivant. J'ai choisi cette structure car il est facile d'ajouter ou de supprimer un élément en tête de la liste.

```cpp
// Définition de la structure Node qui représente un noeud dans la pile
struct Node{
  int value;    // Valeur stockée dans le noeud
  int minValue; // Valeur minimale de la pile jusqu'à ce noeud
  Node* next;   // Pointeur vers le prochain noeud dans la pile
};
class MinStack {
private:
  Node * head; // Pointeur vers le sommet de la pile
public:
  MinStack() {
    head = nullptr; // Initialisation du sommet de la pile à nullptr (pile vide)
  }

  // Fonction pour ajouter un élément à la pile
  void push(int val) {
    // Vérifie s'il existe déjà des éléments dans la pile
    if(head){
      // Crée un nouveau noeud avec la valeur donnée et la valeur minimale mise à jour
      head = new Node(val, min(val, head->minValue), head);
    }
    else{
      // Si la pile est vide, initialise la valeur minimale avec la valeur donnée
      head = new Node(val, val, head);
    }
  }

  // Fonction pour supprimer l'élément au sommet de la pile
  void pop() {
    Node * temp = head; // Stocke le pointeur vers le noeud à supprimer
    head = head->next;  // Met à jour le sommet de la pile
    delete temp;        // Libère la mémoire du noeud supprimé
  }

  // Fonction pour obtenir la valeur au sommet de la pile
  int top() {
    return head->value;
  }

  // Fonction pour obtenir la valeur minimale dans la pile
  int getMin() {
    return head->minValue;
  }
};
```

Cette approche respecte la contrainte de complexité `O(1)` pour chaque méthode, mais elle stocke de manière redondante la valeur minimale puisqu'elle est dupliquée sur chaque noeud.

Pour remédier à ce problème, j'ai ajouté une deuxième liste chaînée pour stocker uniquement les valeurs minimales. Ainsi, lors de l'ajout d'un élément, je mets à jour cette liste si la nouvelle valeur est inférieure ou égale à la valeur minimale actuelle.

```cpp
// Définition de la structure Node qui représente un noeud dans la pile
struct Node{
  int value; // Valeur stockée dans le noeud
  Node* next; // Pointeur vers le prochain noeud dans la pile
};
class MinStack {
private:
  Node * head;     // Pointeur vers le sommet de la pile
  Node * minValue; // Pointeur vers le sommet de la pile des valeurs minimales
public:
  MinStack() {
    // Initialisation du sommet de la pile à nullptr (pile vide)
    head = nullptr;
    // Initialisation du sommet de la pile des valeurs minimales à nullptr
    minValue = nullptr;
  }

  // Fonction pour ajouter un élément à la pile
  void push(int val) {
    // Crée un nouveau noeud avec la valeur donnée et le pointeur vers le prochain noeud
    head = new Node(val, head);
    // Vérifie si la pile des valeurs minimales est vide ou si la valeur à ajouter est inférieure ou égale à la valeur minimale actuelle
    if(!minValue || (minValue && val <= minValue->value)){
      minValue = new Node(val, minValue); // Met à jour la pile des valeurs minimales avec la nouvelle valeur
    }
  }

  // Fonction pour supprimer l'élément au sommet de la pile
  void pop() {
    Node * temp = head; // Stocke le pointeur vers le noeud à supprimer
    head = head->next;  // Met à jour le sommet de la pile

    // Vérifie si la valeur supprimée est la même que la valeur minimale actuelle
    if(temp->value == minValue->value){
      // Stocke le pointeur vers le noeud à supprimer dans la pile des valeurs minimales
      Node * tempM = minValue;
      // Met à jour le sommet de la pile des valeurs minimales
      minValue = minValue->next;
      // Libère la mémoire du noeud supprimé de la pile des valeurs minimales
      delete tempM;
    }
    // Libère la mémoire du noeud supprimé de la pile principale
    delete temp;
  }

  // Fonction pour obtenir la valeur au sommet de la pile
  int top() {
    return head->value;
  }

  // Fonction pour obtenir la valeur minimale dans la pile
  int getMin() {
    return minValue->value;
  }
};
```

Bien que cette approche fonctionne, elle peut être améliorée. L'utilisation d'un simple tableau plutôt que d'une liste chaînée serait plus efficace en termes d'utilisation de la mémoire, car les opérations d'insertion et de suppression du dernier élément sont constantes `O(1)`. Cela éviterait également de stocker les pointeurs vers les éléments suivants.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
