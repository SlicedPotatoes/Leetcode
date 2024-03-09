# 704. Binary Search

## Énoncé

Étant donné un tableau d'entiers `nums` qui est trié par ordre croissant et un entier `target`, écrivez une fonction pour rechercher `target` dans `nums`. Si `target` existe, renvoyez son index. Sinon, renvoyez `-1`.

Vous devez écrire un algorithme avec une complexité temporelle `O(log n)`.

## Exemple

**Exemple 1:**  
**Input:** nums = [-1,0,3,5,9,12], target = 9  
**Output:** 4  
**Explication:** 9 existe dans nums et son indice est 4

**Exemple 2:**  
**Input:** nums = [-1,0,3,5,9,12], target = 2  
**Output:** -1  
**Explication:** 2 n'existe pas dans nums donc renvoie -1

## Contraintes

`1 <= nums.length <= 10^4`  
`-10^4 < nums[i], target < 10^4`  
Tous les entiers dans `nums` sont **uniques**.  
`nums` est trié par **ordre croissant**.

## Note personnelle

Implémentation classique de la recherche dichotomique.
La complexité temporelle est de `O(log n)` et la complexité spatiale de `O(1)`, ce qui en fait une solution efficace pour rechercher des éléments dans une liste triée.

<img src="../imgs/0704-runtime.png"/>
<img src="../imgs/0704-memory.png"/>
