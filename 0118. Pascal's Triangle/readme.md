# 118. Pascal's Triangle

## Énoncé

Étant donné un entier `numRows`, retournez les numRows premières lignes du **triangle de Pascal**.

Dans le triangle de Pascal, chaque nombre est la somme des deux nombres directement au-dessus, comme indiqué:

<img src="../imgs/0118-img1.gif"/>

## Exemple

**Exemple 1:**  
**Input:** numRows = 5  
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

**Exemple 2:**  
**Input:** numRows = 1  
**Output:** [[1]]

## Contraintes

`1 <= numRows <= 30`

## Note personnelle

Mon approche est assez simple, elle suit le principe du triangle de Pascal. Pour commencer, j'initialise un vecteur `answer` de longueur `numRows` qui représentera les lignes du triangle, et je lui assigne `answer[0] = {1}` pour la première ligne.

Ensuite, je crée une boucle imbriquée : la première parcourt les lignes grâce à l'indice `i`, et la seconde parcourt les colonnes grâce à l'indice `j`.

Pendant le parcours des lignes, je crée un vecteur `row` de taille `i+1` et j'initialise sa première valeur à 1.

Ensuite, je calcule les valeurs suivantes jusqu'à `i - 1` dans la boucle des colonnes en utilisant les valeurs de la ligne précédente. Enfin, je rajoute `1` à la fin de mon vecteur.

Cette approche a une complexité temporelle et spatiale de `O(n^2)`

<img src="../imgs/0118-runtime.png"/>
<img src="../imgs/0118-memory.png"/>
