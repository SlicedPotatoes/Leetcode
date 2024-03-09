# 415. Add Strings

## Énoncé

Étant donné deux entiers non négatifs, `num1` et `num2` représentés sous forme de chaîne, renvoie la somme de `num1` et `num2` sous forme de chaîne.

Vous devez résoudre le problème sans utiliser de bibliothèque intégrée pour gérer les grands entiers (comme `BigInteger`). Vous ne devez pas non plus convertir directement les entrées en entiers.

## Exemple

**Exemple 1:**  
**Input:** num1 = "11", num2 = "123"  
**Output:** "134"

**Exemple 2:**  
**Input:** num1 = "456", num2 = "77"  
**Output:** "533"

**Exemple 2:**  
**Input:** num1 = "0", num2 = "0"  
**Output:** "0"

## Contraintes

`1 <= num1.length, num2.length <= 10^4`  
`nums1` et `nums2` se composent uniquement de chiffres.  
`nums1` et `nums2` n'ont pas de zéros non significatifs, à l'exception du zéro lui-même.

## Note personnelle

L'algorithme fonctionne en parcourant simultanément les deux chaînes à partir de la fin. Pour ce faire, j' initialise deux variables, `i` et `j`, respectivement avec `num1.size()` et `num2.size()`.

À chaque itération, je crée une variable `sum` que j'initialise avec la valeur actuelle de la retenue.
Ensuite, pour chaque indice, je vérifie s'il est `>= 0`. Si c'est le cas, j'extrais la valeur numérique du caractère en soustrayant la valeur ASCII de `'0'`, et j'ajoute cette valeur à la somme `sum`.

Je gère la retenue dans le cas où `sum > 9`. La retenue devient alors `1` et `sum` récupère la valeur de `sum % 10`.
Enfin, j'ajoute à la fin de ma chaîne la valeur de `sum + '0'`.

Après la sortie de la boucle, s'il reste une retenue, j'ajouter `1` à la fin de la chaîne.

Il ne reste plus qu'a retourné la chaine inversée.

<img src="../imgs/0415-runtime.png"/>
<img src="../imgs/0415-memory.png"/>
