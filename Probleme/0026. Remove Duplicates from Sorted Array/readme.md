# 26. Remove Duplicates from Sorted Array

## Énoncé

Étant donné un tableau d'entiers `nums` trié par **ordre croissant**, supprimez les doublons de sorte que chaque élément unique n'apparaisse qu'**une seule fois**.
L'**ordre relatif** des éléments doit rester le **même**. Renvoyez ensuite le nombre d'éléments uniques dans `nums`.

Considérez que le nombre d'éléments uniques de `nums` comme étant `k`, pour être accepté, vous devez faire ce qui suit:

- Modifiez le tableau `nums` de telle sorte que les premiers `k` éléments de `nums` contiennent les éléments uniques dans l'ordre dans lequel ils étaient présents initialement dans `nums`. Les éléments restants de `nums` ne sont pas importants, tout comme la taille de `nums`.
- Renvoie `k`.

**Juge:**

Le juge testera votre solution avec le code suivant:

```
int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
```

Si toutes les assertions sont réussies, alors votre solution sera **acceptée**.

## Exemple

**Exemple 1:**  
**Input:** nums = [1,1,2]  
**Output:** 2, nums = [1,2,_]  
**Explication:** Votre fonction doit renvoyer k = 2, les deux premiers éléments de nums étant respectivement 1 et 2.
Peu importe ce que vous laissez au-delà du k renvoyé

**Exemple 2:**  
**Input:** nums = [0,0,1,1,1,2,2,3,3,4]  
**Output:** 5, nums = [0,1,2,3,4,_,_,_,_,_]  
**Explication:** Votre fonction doit renvoyer k = 5, les cinq premiers éléments de nums étant respectivement 0, 1, 2, 3 et 4.
Peu importe ce que vous laissez au-delà du k renvoyé

## Contraintes

`1 <= nums.length <= 3 * 10^4`  
`-100 <= nums[i] <= 100`  
`nums` est trié par ordre **croissant**.

## Note personnelle

Ma méthode est relativement simple: je maintiens une trace de l'indice du dernier élément dans le nouveau tableau appelé `size`. En parcourant le tableau d'origine, je compare l'élément actuel à celui se trouvant à l'indice `size`. Si ils sont différents, j'incrémente `size` et j'attribue la valeur de `nums[i]` à `nums[size]`.

Cette approche présente une complexité temporelle de `O(n)`, où `n` est la taille de `nums`, et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
