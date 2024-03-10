# 35. Search Insert Position

## Énoncé

Étant donné un tableau trié d'entiers distincts et une valeur cible, renvoie l'index si la cible est trouvée. Sinon, renvoyez l'index là où il se trouverait s'il avait été inséré dans l'ordre.

Vous devez écrire un algorithme avec une complexité temporelle de `O(log n)`.

## Exemple

**Exemple 1:**  
**Input:** nums = [1,3,5,6], target = 5  
**Output:** 2

**Exemple 2:**  
**Input:** nums = [1,3,5,6], target = 2  
**Output:** 1

**Exemple 3:**  
**Input:** nums = [1,3,5,6], target = 7  
**Output:** 4

## Contraintes

`1 <= nums.length <= 10^4`  
`-10^4 <= nums[i] <= 10^4`  
`nums` contient des valeurs **distinctes** triées par **ordre croissant**.  
`-10^4 <= target <= 10^4`

## Note personnelle

Implémentation classique de la recherche dichotomique. Elle inclut une petite subtilité pour déterminer l'indice d'insertion dans le cas où l'élément recherché n'est pas trouvé. Dans ce scénario, il suffit de retourner l'indice de départ de la plage de recherche.

La complexité temporelle de cette méthode est de `O(log n)`, tandis que la complexité spatiale est de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
