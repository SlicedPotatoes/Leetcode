# 23. Merge k Sorted Lists

## Énoncé

Vous recevez un tableau de `k` listes chaînées `lists`, chaque liste chaînée est triée par ordre croissant.

Fusionnez toutes les listes chaînées en une seule liste chaînée triée et renvoyez-la.

## Exemple

**Exemple 1:**  
**Input:** lists = [[1,4,5],[1,3,4],[2,6]]  
**Output:** [1,1,2,3,4,4,5,6]

**Exemple 2:**  
**Input:** lists = []  
**Output:** []

**Exemple 3:**  
**Input:** lists = [[]]  
**Output:** []

## Contraintes

`k == lists.length`  
`0 <= k <= 10^4`  
`0 <= lists[i].length <= 500`  
`-10^4 <= lists[i][j] <= 10^4`  
`lists[i]`est trié par ordre croissant.  
La somme de `lists[i].length` ne dépassera pas `10^4`.

## Note personnelle

Pour résoudre ce problème, j'ai opté pour l'utilisation d'une file de priorité, ce qui me permet d'identifier efficacement la plus petite valeur parmi tous les éléments des listes chaînées qui n'ont pas encore été traités.

J'ai mis en place un foncteur pour trier les éléments de type `ListNode` en fonction de leurs valeurs.

Ensuite, j'ai ajouté les têtes des listes à ma file de priorité. Par la suite, j'ai initialisé une nouvelle `ListNode` nommée `answer` pour simplifier la construction de la nouvelle liste triée. De plus, j'ai créé un pointeur vers l'élément actuel de `answer` appelé `current`, ce qui facilitera l'insertion des éléments.

Je continue à itérer tant que la file de priorité n'est pas vide. À chaque itération, je récupère l'élément ayant la priorité la plus élevée que j'ajoute à `current->next`.
Ensuite, j'avance mon pointeur `current` vers l'élément suivant (le nouvel élément que nous venons d'insérer).
Si l'élément suivant (de la tête de la liste que nous venons d'insérer) n'est pas nul, je l'ajoute à la file de priorité.

À la fin de la boucle, il ne me reste plus qu'à retourner la tête de la nouvelle liste, qui est `answer->next`.

Cette approche présente une complexité temporelle de `O(n log k)`, où `n` est la taille totale des listes et `k` le nombre de listes. La complexité spatiale est de `O(k)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
