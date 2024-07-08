# 1823. Find the Winner of the Circular Game

## Énoncé

Il y a `n` amis qui jouent à un jeu. Les amis sont assis en cercle et sont numérotés de `1` à `n` dans **le sens des aiguilles d'une montre**. Plus précisément, avancer dans le sens des aiguilles d'une montre à partir de l'ami numéro `i` vous amène à l'ami numéro `i+1` pour `1 <= i < n`, et avancer dans le sens des aiguilles d'une montre à partir de l'ami numéro `n` vous amène à l'ami numéro `1`.

Les règles du jeu sont les suivantes:

- **Commencez** avec l'ami numéro `1`.
- Comptez les `k` amis suivants dans le sens des aiguilles d'une montre **y compris** l'ami avec lequel vous avez commencé. Le comptage se fait en bouclant autour du cercle et peut compter certains amis plus d'une fois.
- Le dernier ami que vous avez compté quitte le cercle et perd le jeu.
- S'il reste encore plus d'un ami dans le cercle, revenez à l'étape `2` en **commençant** à partir de l'ami **immédiatement dans le sens des aiguilles d'une montre** de celui qui vient de perdre et répétez.
- Le dernier ami restant dans le cercle gagne le jeu.

Étant donné le nombre d'amis, `n`, et un entier `k`, retournez le gagnant du jeu.

Pourriez-vous résoudre ce problème en temps linéaire avec un espace constant ?

## Exemple

**Exemple 1:**

<img src="./imgs/img1.png" style="width: 500px; height: 345px; background: #ffffff"/>

**Input:** n = 5, k = 2  
**Output:** 3  
**Explication:** Les amis partent dans cet ordre : 2, 4, 1, 5. Le gagnant est l'ami 3.

**Exemple 2:**  
**Input:** n = 6, k = 5  
**Output:** 1  
**Explication:** Les amis partent dans cet ordre : 5, 4, 6, 2, 3. Le gagnant est l'ami 1.

## Contraintes

`1 <= k <= n <= 500`

## Note personnelle

### Approche 1: Utilisation d'un Vecteur

Cette approche simule les règles du jeu en maintenant l'état des joueurs avec un vecteur.

```cpp
int findTheWinner(int n, int k) {
  // Crée un vecteur de booléens pour suivre les joueurs encore en jeu
  vector<bool> playersInGame(n, true);

  // Variable pour suivre la position actuelle dans le cercle
  int currentPos = -1;

  // Boucle pour éliminer les joueurs jusqu'à ce qu'il n'en reste qu'un
  for (int i = 0; i < n; i++) {
    // Avance de 'k' positions dans le cercle
    for (int j = 0; j < k; j++) {
      currentPos = (currentPos + 1) % n; // Incrémenter la position

      // Trouve le prochain joueur encore en jeu
      while (!playersInGame[currentPos]) {
        currentPos = (currentPos + 1) % n;
      }
    }

    // Élimine le joueur à la position actuelle
    playersInGame[currentPos] = false;
  }

  // Retourne l'indice du gagnant
  return currentPos + 1;
}
```

- Complexité Temporelle: `O(n^2 * k)`.
- Complexité Spatiale: `O(n)`.

### Approche 2: Utilisation d'une File (Queue)

Cette méthode simule les règles du jeu en utilisant une file pour suivre les joueurs restants.

```cpp
int findTheWinner(int n, int k) {
  queue<int> q;

  // Ajouter tous les joueurs (de 1 à n) dans la file
  for(int i = 1; i <= n; i++){
    q.push(i);
  }

  // Répéter jusqu'à ce qu'il ne reste qu'un seul joueur dans la file
  while(q.size() != 1){
    // Passer le joueur k-1 fois du début de la file à la fin
    for(int i = 1; i < k; i++){
      q.push(q.front()); // Déplacer le joueur en tête de file à la fin
      q.pop();           // Retirer le joueur de la tête de file
    }
    // Éliminer le joueur en tête de file (le k-ème joueur)
    q.pop();
  }

  // Le joueur restant en tête de file est le gagnant
  return q.front();
}
```

- Complexité Temporelle: `O(n * k)`.
- Complexité Spatiale: `O(n)`.

### Approche 3: Utilisation d'une Liste Chaînée (Linked List)

Cette approche simule les règles du jeu avec une liste chaînée pour suivre les joueurs restants.

```cpp
// Définition de la structure Node pour la liste chaînée circulaire
struct Node{
  int n;
  Node* next;

  // Constructeur pour initialiser un nœud avec une valeur
  Node(int n) {
    this->n = n;
    this->next = nullptr;
  }
};
int findTheWinner(int n, int k) {
  // Création du premier nœud et initialisation de la tête de liste
  Node* head = new Node(1);
  Node* curr = head;

  // Création des autres nœuds et construction de la liste chaînée circulaire
  for(int i = 2; i <= n; i++){
    curr->next = new Node(i);
    curr = curr->next;
  }
  // Circularité de la liste
  curr->next = head;

  // Pointeur pour garder une trace du nœud précédent
  Node* prev = nullptr;

  // Boucle pour éliminer les joueurs jusqu'à ce qu'il ne reste qu'un seul joueur
  for(int i = 1; i < n; i++){
    // Avancer de 'k' positions dans la liste
    for(int j = 0; j < k; j++){
      prev = curr;
      curr = curr->next;
    }
    // Suppression du k-ème joueur
    prev->next = curr->next;
    delete curr;
    curr = prev;
  }

  // Le dernier joueur restant est le gagnant
  int ans = curr->n;
  delete curr;
  return ans;
}
```

- Complexité Temporelle: `O(n * k)`.
- Complexité Spatiale: `O(n)`.

### Approche 4: Méthode Récursive de Josephus

L'idée de cette approche est de trouver la position du gagnant pour `n - 1` joueurs et de l'ajuster en lui ajoutant `k`.

Plus d'informations ici: [FR](https://fr.wikipedia.org/wiki/Probl%C3%A8me_de_Jos%C3%A8phe), [EN](https://en.wikipedia.org/wiki/Josephus_problem). (La version anglaise est plus complète).

Je précise également que sans les informations de Wikipédia je ne serais pas parvenue à cette solution.

```cpp
int findTheWinner(int n, int k) {
  // Cas de base : si n'est égal à 1, le gagnant est le seul joueur restant
  if (n == 1) {
    return 1;
  }

  // Récursion : trouve la position du gagnant pour n-1 joueurs et ajuste la position pour inclure le k-ème pas
  return ((findTheWinner(n - 1, k) + k - 1) % n) + 1;
}
```

- Complexité Temporelle: `O(n)`.
- Complexité Spatiale: `O(n)`.

### Approche 5: Méthode Itérative de Josephus

Cette approche itérative utilise une méthode similaire à l'Approche 4 mais de manière itérative.

```cpp
int findTheWinner(int n, int k) {
  int prev = 1; // Initialisation avec le premier joueur

  // Boucle à travers tous les joueurs de 2 à n
  for(int i = 2; i <= n; i++){
    // La formule ((prev + k - 1) % i) + 1 calcule la nouvelle position du gagnant
    prev = ((prev + k - 1) % i) + 1;
  }

  return prev; // Retourne la position du gagnant
}
```

- Complexité Temporelle: `O(n)`.
- Complexité Spatiale: `O(1)`.

### Comparatif des Approches

- L'**Approche 1: Utilisation d'un Vecteur** est la moins efficace en termes de temps d'exécution
- L'**Approche 2: Utilisation d'une File** est plus efficace que l'Approche 1, elle est facile à implémenter et efficace pour des valeurs moyennes de `n` et `k`.
- L'**Approche 3: Utilisation d'une Liste Chaînée** est similaire à l'Approche 2 en termes de complexité, mais elle peut être plus complexe à implémenter pour ceux qui ne sont pas familiers avec les listes chaînées.
- L'**Approche 4: Méthode Récursive de Josephus** utilise un principe différent un peu plus compliqué à comprendre, elle sera nettement plus efficace que les approches précédentes notamment pour les grandes valeurs de `n` et `k`.
- L'**Approche 5: Josephus Itérative** a les mêmes avantages que l'approche 4, en profitant d'être itérative et donc consomme moins de mémoire.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
