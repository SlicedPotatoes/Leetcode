# 442. Find All Duplicates in an Array

## Énoncé

Étant donné un tableau d'entiers `nums` de longueur `n` où tous les entiers de `nums` sont dans la plage `[1, n]` et chaque entier apparaît **une** ou **deux** fois, renvoie un tableau de tous les entiers qui apparaît **deux** fois.

Vous devez écrire un algorithme qui s'exécute avec une complexité temporelle `O(n)` et utilise uniquement un espace supplémentaire constant.

## Exemple

**Exemple 1:**  
**Input:** nums = [4,3,2,7,8,2,3,1]  
**Output:** [2,3]

**Exemple 2:**  
**Input:** nums = [1,1,2]  
**Output:** [1]

**Exemple 3:**  
**Input:** nums = [1]  
**Output:** []

## Contraintes

`n == nums.length`  
`1 <= n <= 10^5`  
`1 <= nums[i] <= n`  
Chaque élément de `nums` **une fois** ou **deux fois**.

## Note personnelle

Pour cet exercice, les contraintes de temps et d'espace ajoutent une complexité notable. Respecter ces contraintes nécessite d'exploiter une subtilité afin de garantir leur respect, notamment en ce qui concerne la complexité spatiale

Comme stipulé dans l'énoncé, les éléments de la liste `nums` se trouvent dans une plage comprise entre `[1, n]`, où `n` représente la taille de `nums`. . Cette caractéristique nous permet de marquer les éléments déjà rencontrés sans nécessiter d'espace supplémentaire.

L'idée est la suivante: pour chaque élément, nous utilisons son indice dans le tableau et nous changeons le signe de la valeur à cet indice.  
Par exemple, pour `nums[2] = 4`, nous accédons à `nums[4 - 1]` (en soustrayant 1 car l'intervalle est inclusif et les tableaux sont indexés à partir de 0), puis nous multiplions cette valeur par -1 pour la rendre négative sans perdre l'information d'origine grâce à sa valeur absolue. En effectuant cette opération, si une correspondance est négative plus tard, cela signifie que le nombre a déjà été rencontré.

Cette approche présente une complexité temporelle de `O(n)` et nécessite un espace supplémentaire constant.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
