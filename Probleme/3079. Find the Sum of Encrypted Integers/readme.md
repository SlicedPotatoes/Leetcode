# 3079. Find the Sum of Encrypted Integers

## Énoncé

Vous recevez un tableau d'entiers `nums` contenant des entiers **positifs**. Nous définissons une fonction `encrypt` telle que `encrypt(x)` remplace **chaque** chiffre de `x` par le **plus grand** chiffre de `x`. Par exemple, `encrypt(523) = 555` et `encrypt(213) = 333`.

Renvoie la **somme** des éléments chiffrés.

## Exemple

**Exemple 1:**  
**Input:** nums = [1,2,3]  
**Output:** 6  
**Explication:** Les éléments chiffrés sont `[1,2,3]`. La somme des éléments cryptés est `1 + 2 + 3 == 6`.

**Exemple 2:**  
**Input:** nums = [10,21,31]  
**Output:** 66  
**Explication:** Les éléments chiffrés sont `[11,22,33]`. La somme des éléments cryptés est `11 + 22 + 33 == 66`.

## Contraintes

`1 <= nums.length <= 50`  
`1 <= nums[i] <= 1000`

## Note personnelle

La partie de problème qui peut varier selon les différentes personnes est la fonction utilisée pour crypter un entier. J'ai choisi d'adopter une approche mathématique pour cette fonction.

La première étape de cette fonction consiste à extraire le plus grand chiffre de `x` ainsi que le nombre de chiffres le composant.

Pour ce faire, je parcours chaque chiffre en récupérant le reste de la division de `x` par 10 (`x % 10`) et je maintiens une trace du maximum trouvé jusqu'à présent.
À chaque itération, j'incrémente également un compteur représentant le nombre de chiffres. Une fois le chiffre extrait, je le soustrais de `x` et je divise `x` par 10.
Ces opérations se répètent tant que `x != 0`.

La deuxième partie consiste à créer le cryptage de `x` en utilisant le chiffre le plus grand.

Pour cela, j'initialise une variable `e` à 0 qui stockera la version cryptée de `x`, et je répète le processus tant que la taille n'est pas égale à 0. À chaque itération, je multiplie `e` par 10 et j'ajoute l'élément maximum trouvé précédemment.

Il ne reste plus qu'à itérer sur chaque élément de `nums` et à calculer la somme des valeurs cryptées.

Cette fonction a une complexité temporelle de `O(n * x)`, où `n` est la taille de `nums` et `x` est le nombre de chiffres dans `nums[i]`. La complexité spatiale est de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
