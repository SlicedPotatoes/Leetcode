# 41. First Missing Positive

## Énoncé

Étant donné un tableau d'entiers non triés `nums`. Renvoie le plus petit entier positif qui n'est pas présent dans `nums`.

Vous devez implémenter un algorithme avec une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

## Exemple

**Exemple 1:**  
**Input:** nums = [1,2,0]  
**Output:** 3  
**Explication:** Les nombres compris dans la plage [1,2] sont tous dans le tableau.

**Exemple 2:**  
**Input:** nums = [3,4,-1,1]  
**Output:** 2  
**Explication:** 1 est dans le tableau mais 2 est manquant.

**Exemple 3:**  
**Input:** nums = [7,8,9,11,12]  
**Output:** 1  
**Explication:** Le plus petit entier positif 1 est manquant.

## Contraintes

`1 <= nums.length <= 10^5`  
`-2^31 <= nums[i] <= 2^31 - 1`

## Note personnelle

Ce problème peut être assez technique à résoudre en raison des contraintes de temps et d'espace requises.

Pour y parvenir, étant donné que nous cherchons le plus petit entier positif qui n'est pas présent dans le tableau, cela revient à rechercher un nombre dans la plage `[1, nums.size() + 1]`. L'idée est donc que lorsqu'on rencontre un nombre positif compris dans cette plage (exclusive pour la fin de la plage), on le déplace à l'index du tableau correspondant.

Ensuite, en parcourant une dernière fois le tableau, si pour `nums[i]` la valeur n'est pas `i + 1` alors `i + 1` est l'élément manquant.

Si on arrive à la fin du tableau sans trouver d'élément manquant, cela signifie que celui-ci est `nums.size() + 1`.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
