# 2215. Find the Difference of Two Arrays

## Énoncé

Étant donné deux tableaux d'entiers **indexés à 0** `nums1` et `nums2`, renvoie une liste `answer` de taille `2` où:

- `answer[0]` est une liste de tous les entiers **distincts** dans `nums1` qui ne sont **pas** présents dans `nums2`.
- `answer[1]` est une liste de tous les entiers **distincts** dans `nums2` qui ne sont **pas** présents dans `nums1`.

**Note:** Les entiers des listes peuvent être renvoyés dans **n'importe quel** ordre.

## Exemple

**Exemple 1:**  
**Input:** nums1 = [1,2,3], nums2 = [2,4,6]  
**Output:** [[1,3],[4,6]]

**Exemple 2:**  
**Input:** nums1 = [1,2,3,3], nums2 = [1,1,2,2]  
**Output:** [[3],[]]

## Contraintes

`1 <= nums1.length, nums2.length <= 1000`  
`-1000 <= nums1[i], nums2[i] <= 1000`

## Note personnelle

Une méthode simple consiste à utiliser deux ensembles distincts, un pour chaque tableau.

Cela facilite le stockage des éléments uniques de chaque tableau et permet de vérifier en temps constant si un élément se trouve dans le tableau.

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
