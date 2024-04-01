# 66. Plus One

## Énoncé

Vous recevez un **grand entier** représenté sous la forme d'un tableau d'entiers `digits`, où chaque `digits[i]` est le `ith` chiffre de l'entier. Les chiffres sont classés du plus significatif au moins significatif, de gauche à droite. Le grand entier ne contient aucun zéro non significatif.

Incrémentez le grand entier de un et renvoyez le tableau de chiffres résultant.

## Exemple

**Exemple 1:**  
**Input:** digits = [1,2,3]  
**Output:** [1,2,4]  
**Explication:** Le tableau représente l'entier 123.  
Incrémenter d'un donne 123 + 1 = 124.  
Le résultat devrait donc être [1,2,4].

**Exemple 2:**  
**Input:** digits = [4,3,2,1]  
**Output:** [4,3,2,2]  
**Explication:** Le tableau représente l'entier 4321.  
Incrémenter d'un donne 4321 + 1 = 4322.  
Le résultat devrait donc être [4,3,2,2].

**Exemple 3:**  
**Input:** digits = [9]  
**Output:** [1,0]  
**Explication:** Le tableau représente l'entier 9.  
Incrémenter d'un donne 9 + 1 = 10.  
Le résultat devrait donc être [1,0].

## Contraintes

`1 <= digits.length <= 100`  
`0 <= digits[i] <= 9`  
`digits` ne contient aucun zéro non significatif.

## Note personnelle

Ma méthode est plutôt simple: je commence par initialiser une variable appelée `carrying`, qui représente la retenue, à 1.

Ensuite, je parcours le tableau à partir de la fin. À chaque étape, je calcule la somme de la valeur actuelle du tableau et de la retenue, que je stocke dans une variable temporaire appelée `sum`.

Je mets à jour la valeur du tableau à cet indice en prenant le reste de la division de `sum` par 10: `digits[i] = sum % 10`.

Ensuite, je mets à jour la valeur de la retenue en prenant la partie entière de la division de `sum` par 10: `carrying = sum / 10`.

Si à un moment donné la retenue devient zéro, j'arrête prématurément le parcours du tableau.

Enfin, si une retenue subsiste à la fin du tableau, j'insère `1` au début du tableau.

Cette approche présente une complexité temporelle de `O(n)`, où `n` est la taille du tableau `digits`, et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
