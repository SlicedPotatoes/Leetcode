# 3065. Minimum Operations to Exceed Threshold Value I

## Énoncé

Vous recevez un tableau d'entiers **indexés à 0** `nums` et un entier `k`.

En une seule opération, vous pouvez supprimer une occurrence du plus petit élément de `nums`.

Renvoie le nombre **minimum** d'opérations nécessaires pour que tous les éléments du tableau soient supérieurs ou égaux à `k`.

## Exemple

**Exemple 1:**  
**Input:** nums = [2,11,10,1,3], k = 10  
**Output:** 3  
**Explication:**  
Après une opération, nums devient égal à [2, 11, 10, 3].  
Après deux opérations, nums devient égal à [11, 10, 3].  
Après trois opérations, nums devient égal à [11, 10].  
A ce stade, tous les éléments de nums sont supérieurs ou égaux à 10 donc on peut s'arrêter.
On peut montrer que 3 est le nombre minimum d'opérations nécessaires pour que tous les éléments du tableau soient supérieurs ou égaux à 10.

**Exemple 2:**  
**Input:** nums = [1,1,2,4,9], k = 1  
**Output:** 0  
**Explication:** Tous les éléments du tableau sont supérieurs ou égaux à 1, nous n’avons donc pas besoin d’appliquer d’opérations sur les nombres.

**Exemple 3:**  
**Input:** nums = [1,1,2,4,9], k = 9  
**Output:** 4  
**Explication:** un seul élément de nums est supérieur ou égal à 9 il faut donc appliquer les opérations 4 fois sur nums.

## Contraintes

`1 <= nums.length <= 50`  
`1 <= nums[i] <= 10^9`  
`1 <= k <= 10^9`  
L'entrée est générée de telle sorte qu'il y ait au moins un index `i` tel que `nums[i] >= k`.

## Note personnelle

Étant donné qu'il n'est pas nécessaire d'effectuer les opérations en tant que telles, il nous suffit de compter le nombre d'éléments `< k` et de renvoyer cette réponse.

Complexité temporelle: `O(n)`  
Complexité spatiale: `O(1)`

<img src="../imgs/3065-runtime.png"/>
<img src="../imgs/3065-memory.png"/>
