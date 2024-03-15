# 13. Roman to Integer

## Énoncé

Les chiffres romains sont représentés par sept symboles différents: `I`, `V`, `X`, `L`, `C`, `D` et `M`.

| **Symbol** | **Value** |
| ---------- | --------- |
| I          | 1         |
| V          | 5         |
| X          | 10        |
| L          | 50        |
| C          | 100       |
| D          | 500       |
| M          | 1000      |

Par exemple, `2` s'écrit `II` en chiffres romains, seulement deux uns additionnés. `12` s'écrit `XII`, qui est simplement `X + II`. Le nombre `27` s'écrit `XXVII`, qui est `XX + V + II`.

Les chiffres romains sont généralement écrits du plus grand au plus petit, de gauche à droite. Cependant, le chiffre romains pour quatre n'est pas `IIII`. Au lieu de cela, il s’écrit `IV`. Parce que le un est avant le cinq, nous le soustrayons, ce qui fait quatre. Le même principe s’applique au nombre neuf, qui s’écrit `IX`. Il existe six cas où la soustraction est utilisée:

- `I` peut être placé avant `V` (5) et `X` (10) pour faire 4 et 9.
- `X` peut être placé avant `L` (50) et `C` (100) pour faire 40 et 90.
- `C` peut être placé avant `D` (500) et `M` (1000) pour faire 400 et 900.

Étant donné un chiffre romain, convertissez-le en nombre entier.

## Exemple

**Exemple 1:**  
**Input:** s = "III"  
**Output:** 3  
**Explication:** III = 3.

**Exemple 2:**  
**Input:** s = "LVIII"  
**Output:** 58  
**Explication:** L = 50, V= 5, III = 3.

**Exemple 3:**  
**Input:** s = "MCMXCIV"  
**Output:** 1994  
**Explication:** M = 1000, CM = 900, XC = 90 and IV = 4.

## Contraintes

`1 <= s.length <= 15`  
`s` contient uniquement les caractères `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.  
Il est **garanti** que `s` est un chiffre romain valide dans la plage `[1, 3999]`.

## Note personnelle

Pour aborder ce problème, j'ai adopté une approche relativement simple. Je parcours l'ensemble des caractères de la chaîne `s` jusqu'à l'avant-dernier élément, excluant le dernier. À chaque itération, je compare l'élément actuel avec le suivant.

Mon approche est plutot simple, j'itére sur les de `s` jusqu'a `s.size() - 1` exclues, ensuite je récupére l'element actuel et suivant et je les compares.

- Si l'élément actuel est supérieur ou égal au suivant, je l'ajoute simplement à mon résultat.
- Sinon, j'ajoute à mon résultat leur différence et j'incrémente mon indice de 1 car nous avons traité 2 valeurs simultanément.

À la fin de la boucle, je vérifie si tous les éléments ont été traités. Si ce n'est pas le cas, j'ajoute le dernier élément non traité à mon résultat.

J'ai testé deux méthodes pour obtenir les valeurs numériques d'un caractère d'un chiffre romain :
La première méthode utilisait une hashmap, tandis que la seconde utilisait un switch. D'après mes observations, celle avec le switch était plus efficace en raison du faible nombre d'éléments. Elle présentait à peu près la même efficacité temporelle mais un gain significatif de mémoire.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
