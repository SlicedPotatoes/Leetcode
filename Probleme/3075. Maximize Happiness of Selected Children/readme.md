# 3075. Maximize Happiness of Selected Children

## Énoncé

On vous donne un tableau `happiness` de longueur `n`, et un **positif** `k`.

Il y a `n` enfants qui se tiennent en file, où l'enfant `i` a une **valeur de bonheur** `happiness[i]`. Vous voulez sélectionner `k` enfants parmi ces `n` enfants en `k` tours.

À chaque tour, lorsque vous sélectionnez un enfant, la **valeur de bonheur** de tous les enfants qui **n'ont pas** encore été sélectionnés diminue de `1`. Notez que la valeur de bonheur **ne peut pas** devenir négative et ne se décrémente **que** si elle est positive.

Retournez la **somme maximale** des valeurs de bonheur des enfants sélectionnés que vous pouvez obtenir en sélectionnant `k` enfants.

## Exemple

**Exemple 1:**  
**Input:** happiness = [1,2,3], k = 2  
**Output:** 4  
**Explication:** Nous pouvons choisir 2 enfants de la manière suivante:

- Choisir l'enfant avec la valeur de bonheur égale à 3. La valeur de bonheur des enfants restants devient [0,1].
- Choisir l'enfant avec la valeur de bonheur égale à 1. La valeur de bonheur des enfants restants devient [0].

Notez que la valeur de bonheur ne peut pas devenir inférieure à 0.  
La somme des valeurs de bonheur des enfants sélectionnés est 3 + 1 = 4.

**Exemple 2:**  
**Input:** happiness = [1,1,1,1], k = 2  
**Output:** 1  
**Explication:** Nous pouvons choisir 2 enfants de la manière suivante:

- Choisir un enfant avec la valeur de bonheur égale à 1. La valeur de bonheur des enfants restants devient [0,0,0].
- Choisir un enfant avec la valeur de bonheur égale à 0. La valeur de bonheur des enfants restants devient [0,0].

La somme des valeurs de bonheur des enfants sélectionnés est 1 + 0 = 1.

**Exemple 3:**  
**Input:** happiness = [2,3,4,5], k = 1  
**Output:** 5  
**Explication:** Nous pouvons choisir 1 enfant de la manière suivante:

- Choisir l'enfant avec la valeur de bonheur égale à 5. La valeur de bonheur des enfants restants devient [1,2,3].

La somme des valeurs de bonheur des enfants sélectionnés est 5.

## Contraintes

`1 <= n == happiness.length <= 2 * 10^5`  
`1 <= happiness[i] <= 10^8`  
`1 <= k <= n`

## Note personnelle

Si l'on simplifie l'énoncé en enlevant tout le contexte superflu, le problème devient le suivant:
L'objectif est de trouver la plus grande somme de `k` éléments d'une liste, en sachant que pour chaque élément ajouté à la somme, tous les nombres de la liste sont décrémentés de 1. Si un nombre devient négatif, on ajoute `0`.

### Ma Solution

Pour résoudre ce problème, j'ai utilisé un algorithme glouton qui fonctionne comme suit:

- Trier la liste `happiness` par ordre décroissant.
- Parcourir les `k` premiers éléments de la liste triée.
- Ajouter au résultat `happiness[i] - i` pour chaque élément.

Cette approche présente une complexité temporelle de `O(n log n)` et une complexité spatiale de `O(1)`.

### Preuve de l'optimalité de l'algotihme

#### 1. Choix Glouton

L'idée clé est de toujours choisir les plus grands nombres disponibles. En triant `happiness` par ordre décroissant et en choisissant les `k` premiers éléments, on s'assure de sélectionner les valeurs les plus élevées.

#### 2. Ajustement par `i`

Lorsqu'on sélectionne le `ième` élément, tous les éléments précédents ont été réduits de 1 à chaque étape. Donc, l'ajustement de chaque élément par `i` (`happiness[i] - i`) est correct car:

- Le premier élément est sélectionné sans ajustement (i = 0)
- Le deuxième élément est ajusté par 1 (i = 1), ect.

#### 3. Conclusion

L'algorithme suit une stratégie gloutonne qui consiste à toujours choisir le plus grand élément disponible après avoir réduit les éléments de 1 à chaque étape.

Mathématiquement, l'algorithme est optimal car il mène à la plus grande somme possible des `k` éléments sous les contraintes données.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
