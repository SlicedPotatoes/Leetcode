# 202. Happy Number

## Énoncé

Écrivez un algorithme pour déterminer si un nombre `n` est heureux.

Un **nombre heureux** est un nombre défini par le processus suivant:

- En commençant par n'importe quel entier positif, remplacez le nombre par la somme des carrés de ses chiffres.
- Répétez le processus jusqu'à ce que le nombre soit égal à 1, ou qu'il **boucle sans fin dans un cycle** qui n'inclut pas 1.
- Les nombres pour lesquels ce processus **se termine par 1** sont heureux.

Renvoie `true` si `n` est un nombre heureux, ou `false` sinon.

## Exemple

**Exemple 1:**  
**Input:** n = 19  
**Output:** true  
**Explication:**  
1^2 + 9^2 = 82  
8^2 + 2^2 = 68  
6^2 + 8^2 = 100  
1^2 + 0^2 + 0^2 = 1

**Exemple 2:**  
**Input:** n = 2  
**Output:** false

## Contraintes

`1 <= n <= 2^31 - 1`

## Note personnelle

Pour aborder ce problème, j'ai développé deux fonctions distinctes. La première fonction calcule le nombre suivant, tandis que la seconde détecte les cycles et renvoie si `n` est un nombre heureux.

Dans la première fonction, j'emploie une méthode de division successive par 10 pour extraire chaque chiffre du nombre.

```cpp
int next(int n) {
  int _n = 0; // Variable pour stocker le résultat

  // Boucle tant que le nombre n'est pas égal à zéro
  while (n != 0) {
    int digit = n % 10;  // Obtient le dernier chiffre du nombre
    n -= digit;          // Soustrait le dernier chiffre de n
    n /= 10;             // Supprime le dernier chiffre de n
    _n += digit * digit; // Ajoute le carré du chiffre à _n
  }

  // Retourne la somme des carrés des chiffres
  return _n;
}
```

Cette fonction affiche une complexité temporelle de `O(d)`, où `d` représente le nombre de chiffres de `n`, et une complexité spatiale de `O(1)`.

Ensuite, pour la détection de cycle, j'ai élaboré deux approches différentes. La première utilise un ensemble.

L'utilisation d'un ensemble permet de suivre les nombres déjà rencontrés, simplifiant ainsi la détection de cycle.

```cpp
bool isHappy(int n) {
  // Crée un ensemble pour stocker les nombres déjà vus
  unordered_set<int> set{n};

  // Boucle tant que n n'est pas égal à 1 ou qu'un cycle est détecté
  while (n != 1) {
    // Calcule le prochain nombre dans la séquence
    n = next(n);

    // Vérifie si le nombre est déjà présent dans l'ensemble
    if (set.contains(n)) {
      // Si c'est le cas, retourne false (cycle détecté)
      return false;
    }
    // Ajoute le nombre à l'ensemble
    set.insert(n);
  }
  // Si n atteint 1, le nombre est heureux
  return true;
}
```

En raison de la nature du problème, il est difficile d'estimer la complexité temporelle, car elle dépend de la nature du nombre d'entrée. La complexité spatiale est proportionnelle au nombre de termes de la suite avant un cycle.

Une autre approche, utilisant la technique du lièvre et de la tortue, permet également de détecter le cycle sans recourir à un ensemble.

Dans cette approche, la tortue (`slow`) avance d'une unité dans la séquence tandis que le lièvre (`fast`) avance de deux. L'itération s'arrête lorsque `slow == fast`.

Illustrons cette approche avec un exemple:
`n` a pour valeur de départ 19, les thermes de la suite sont les suivants: [19,82,68,100,1,...,1]

Itération 1:  
slow = nums[1] = 82  
fast = nums[2] = 68

Itération 2:  
slow = nums[2] = 68  
fast = nums[4] = 1

Itération 3:  
slow = nums[3] = 100  
fast = nums[6] = 1

Itération 4:  
slow = nums[4] = 1  
fast = nums[8] = 1

`slow == fast`, on arrête l'itération, le cycle se termine avec `1` comme digit, alors 19 est heureux.

```cpp
bool isHappy(int n) {
  // Initialise deux pointeurs, un lent et un rapide
  int slow = next(n);       // Pointeur lent, avance d'une étape à la fois
  int fast = next(next(n)); // Pointeur rapide, avance de deux étapes à la fois

  // Boucle jusqu'à ce que les pointeurs se rencontrent
  while(slow != fast){
    slow = next(slow);        // Avance le pointeur lent d'une étape
    fast = next(next(fast));  // Avance le pointeur rapide de deux étapes
  }

  // Si slow atteint 1, le nombre est heureux, sinon, il n'est pas heureux
  return slow == 1;
}
```

Cette approche présente la même complexité temporelle que la précédente, mais une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
