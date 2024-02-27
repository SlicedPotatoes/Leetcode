# 1413. Minimum Value to Get Positive Step by Step Sum

## Énoncé

Étant donné un tableau d'entiers `nums`, vous commencez avec une valeur initiale positive startValue.

À chaque itération, vous calculez la somme étape par étape des éléments de `nums` (de gauche à droite) en commençant par startValue.

Renvoie la valeur positive **minimale** de startValue telle que la somme étape par étape ne soit jamais inférieure à 1.

## Exemple

**Example 1:**  
**Input:** nums = [-3,2,-3,4,2]  
**Output:** 5  
**Explication:** Si vous choisissez startValue = 4, lors de la troisième itération, votre somme étape par étape est inférieure à 1.  
|**startValue = 4** | **startValue = 5** | **nums** |
|:-:|:-:|:-:|
|(4 **-3**) = 1 | (5 **-3**) = 2 | -3 |
|(1 **+2**) = 3 | (2 **+2**) = 4 | 2 |
|(3 **-3**) = 0 | (4 **-3**) = 1 | -3 |
|(0 **+4**) = 4 | (1 **+4**) = 5 | 4 |
|(4 **+2**) = 6 | (5 **+2**) = 7 | 2 |

**Example 2:**  
**Input:** nums = [1,2]  
**Output:** 1  
**Explication:** La valeur de départ minimale doit être positive.

**Example 3:**  
**Input:** nums = [1,-2,-3]  
**Output:** 5  
**Explication:** Si vous choisissez startValue = 4, lors de la troisième itération, votre somme étape par étape est inférieure à 1.  
|**startValue = 4** | **startValue = 5** | **nums** |
|:-:|:-:|:-:|
|(4 **+1**) = 5 | (5 **+1**) = 6 | 1 |
|(5 **-2**) = 3 | (6 **-2**) = 4 | -2 |
|(3 **-3**) = 0 | (4 **-3**) = 1 | -3 |

## Contraintes

`1 <= nums.length <= 100`  
`-100 <= nums[i] <= 100`

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une approche consistant à calculer la somme cumulée des éléments du tableau.  
Pendant ce calcul, je maintiens une trace de la somme minimale rencontrée jusqu'à présent, si celle-ci est inférieure à `0`.  
Ainsi, je peux simplement faire `1 - min` pour obtenir la plus petite valeur possible pour `startValue`.  
Le fait de conserver le minimum inférieur à `0` garantit que la valeur de `startValue` trouvée sera au moins égale à `1`.

En prenant l'**exemple 1** , les sommes cumulées seraient les suivantes: [-3, -1, -4, 0, 2]. Le minimum inférieur à 0 est -4, donc 1 - (-4) = 5.

Cette solution a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="../imgs/1413-runtime.png"/>
<img src="../imgs/1413-memory.png"/>
