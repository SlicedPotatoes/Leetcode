# 575. Distribute Candies

## Énoncé

Alice a `n` bonbons, où le `ième` bonbon est de type `candyType[i]`. Alice a remarqué qu'elle commençait à prendre du poids, alors elle a consulté un médecin.

Le médecin a conseillé à Alice de ne manger que `n / 2` des bonbons qu'elle a (`n` est toujours pair). Alice aime beaucoup ses bonbons et elle veut manger le nombre maximum de types de bonbons différents tout en suivant les conseils du médecin.

Étant donné le tableau d'entiers `candyType` de longueur `n`, renvoyez le **nombre maximum** de types de bonbons différents qu'elle peut manger si elle ne mange que `n / 2` d'entre eux.

## Exemple

**Exemple 1:**  
**Input:** candyType = [1,1,2,2,3,3]  
**Output:** 3  
**Explication:** Alice ne peut manger que 6/2 = 3 bonbons. Puisqu'il n'y en a que 3 types, elle peut en manger un de chaque.

**Exemple 2:**  
**Input:** candyType = [1,1,2,3]  
**Output:** 2  
**Explication:** Alice ne peut manger que 4/2 = 2 bonbons. Qu'elle mange les types [1,2], [1,3] ou [2,3], elle ne peut manger que 2 types différents.

**Exemple 3:**  
**Input:** candyType = [6,6,6,6]  
**Output:** 1  
**Explication:** Alice ne peut manger que 4/2 = 2 bonbons. Même si elle peut manger 2 bonbons, elle n'en a qu'un seul type distinct.

## Contraintes

`n == candyType.length`  
`2 <= n <= 10^4`  
`n` est pair.  
`-10^5 <= candyType[i] <= 10^5`

## Note personnelle

Dans ce problème, nous cherchons essentiellement à déterminer le nombre de types différents de bonbons, puis à renvoyer la valeur minimale entre le nombre de types uniques et le nombre de bonbons qu'Alice peut manger.

Il existe différentes façons de trouver le nombre de types uniques.

Une approche consiste à trier le tableau, puis à initialiser deux variables, une pour suivre le type actuel (`currentType`) et une pour compter les types uniques (`countType`). Ensuite, nous parcourons le tableau trié, mettant à jour `currentType` et incrémentant `countType` lorsque l'élément du tableau est différent de `currentType`.

```cpp
int distributeCandies(vector<int>& candyType) {
  // Trie les types de bonbons pour faciliter le comptage
  sort(candyType.begin(), candyType.end());

  // Initialise le nombre de types de bonbons à 1, car il y a au moins un type de bonbon
  int countType = 1;
  // Initialise le type de bonbon actuel au premier élément du vecteur
  int currentType = candyType[0];

  // Parcourt les types de bonbons à partir du deuxième élément
  for(int i = 1; i < candyType.size(); i++){
    // Si le type de bonbon actuel est différent du type précédent
    if(candyType[i] != currentType){
      currentType = candyType[i]; // Met à jour le type de bonbon actuel
      countType++;                // Incrémente le nombre de types de bonbons différents
    }
  }

  // Retourne le minimum entre le nombre de types de bonbons différents et la moitié de la taille du vecteur de bonbons
  return min(countType, int(candyType.size() / 2));
}
```

Cette approche a une complexité temporelle de `O(n log n)`, où `n` est le nombre d'éléments dans `candyType` et une complexité spatiale de `O(1)`.

Une autre approche consiste à utiliser un ensemble pour stocker les types uniques.

```cpp
int distributeCandies(vector<int>& candyType) {
  // Crée un ensemble non ordonné pour stocker les types de bonbons uniques
  unordered_set<int> set;

  for(int i = 0; i < candyType.size(); i++) {
    set.insert(candyType[i]); // Insère chaque type de bonbon dans l'ensemble
  }

  // Retourne le minimum entre la moitié de la taille du vecteur de bonbons et le nombre de types de bonbons uniques
  return min(int(candyType.size() / 2), (int)set.size());
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Une dernière approche consiste à remplacer l'ensemble par un vecteur de booléens. Dans les contraintes, on remarque que le type est un entier compris entre -10^5 et 10^5, donc le vecteur aura une taille de 10^5 \* 2 + 1 pour permettre de gérer les nombres négatifs et le zéro.

Cette approche est plus rapide car elle évite les surcoûts liés à l'ensemble et stocke seulement des booléens, cependant elle est moins flexible car il faut adapter la taille du vecteur en fonction des types.

Elle présente une complexité temporelle de `O(n)` et une complexité spatiale de "`O(1)`".

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
