# 27. Remove Element

## Énoncé

Étant donné un tableau d'entiers `nums` et un entier `val`, supprimez toutes les occurrences de `val` dans `nums`.
L'ordre des éléments peut être modifié. Renvoyez ensuite le nombre d'éléments dans `nums` qui ne sont pas égaux à `val`.

Considérez que le nombre d'éléments dans `nums` qui ne sont pas égaux à `val` comme étant `k`, pour être accepté, vous devez faire ce qui suit:

- Modifiez le tableau `nums` de telle sorte que les premiers `k` éléments de `nums` contiennent les éléments qui ne sont pas égaux à `val`. Les éléments restants de `nums` ne sont pas importants, tout comme la taille de `nums`.
- Renvoie `k`.

**Juge:**

Le juge testera votre solution avec le code suivant:

```
int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
```

Si toutes les assertions sont réussies, alors votre solution sera **acceptée**.

## Exemple

**Exemple 1:**  
**Input:** nums = [3,2,2,3], val = 3  
**Output:** 2, nums = [2,2,_,_]  
**Explication:** Votre fonction doit renvoyer k = 2, les deux premiers éléments de nums étant 2.
Peu importe ce que vous laissez au-delà du k renvoyé

**Exemple 2:**  
**Input:** nums = [0,1,2,2,3,0,4,2], val = 2  
**Output:** 5, nums = [0,1,4,0,3,_,_,_]  
**Explication:** Votre fonction doit renvoyer k = 5, avec les cinq premiers éléments de nums contenant 0, 0, 1, 3 et 4.
Notez que les cinq éléments peuvent être renvoyés dans n’importe quel ordre.
Peu importe ce que vous laissez au-delà du k renvoyé

## Contraintes

`0 <= nums.length <= 100`  
`0 <= nums[i] <= 50`  
`0 <= val <= 100`

## Note personnelle

Ma méthode est relativement simple: je maintiens une trace de l'indice du dernier élément dans le nouveau tableau appelé `size`. En parcourant le tableau d'origine, je compare l'élément actuel à `val`. Si ils sont différents, j'attribue la valeur de `nums[i]` à `nums[size]` et j'incrémente `size`.

Cette approche présente une complexité temporelle de `O(n)`, où `n` est la taille de `nums`, et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
