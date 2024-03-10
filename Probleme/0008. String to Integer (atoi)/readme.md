# 8. String to Integer (atoi)

## Énoncé

Implémentez la fonction `myAtoi(string s)`, qui convertit une chaîne en un entier signé 32 bits (similaire à la fonction `atoi` de C/C++).

L'algorithme pour `myAtoi(string s)` est le suivant:

- Lisez et ignorez tout espace de début.
- Vérifiez si le caractère suivant (s'il n'est pas déjà à la fin de la chaîne) est `'-'` ou `'+'`. Lisez ce personnage si c'est le cas. Cela détermine si le résultat final est respectivement négatif ou positif. Supposons que le résultat soit positif si aucun des deux n’est présent.
- Lisez ensuite les caractères jusqu'à ce que le prochain caractère non numérique ou la fin de la saisie soit atteint. Le reste de la chaîne est ignoré.
- Convertissez ces chiffres en un entier (c'est-à-dire `"123" -> 123`, `"0032" -> 32`). Si aucun chiffre n’a été lu, alors l’entier est `0`. Modifiez le signe si nécessaire (à partir de l'étape 2).
- Si l'entier est en dehors de la plage d'entiers signés 32 bits `[-2^31, 2^31 - 1]`, bloquez l'entier pour qu'il reste dans la plage. Plus précisément, les entiers inférieurs à `-2^31` doivent être limités à `-2^31`, et les entiers supérieurs à `2^31 - 1` doivent être limités à `2^31 - 1`.
- Renvoie l'entier comme résultat final.

Note:

Seul le caractère espace `' '` est considéré comme un caractère d'espacement.
**N'ignorez** aucun caractère autre que l'espace de début ou le reste de la chaîne après les chiffres.

## Exemple

**Exemple 1:**  
**Input:** s = "42"  
**Output:** 42  
**Explication:**

```
Étape 1 : "42" (aucun caractère lu car il n'y a pas d'espace de début)
           ^
Étape 2 : "42" (aucun caractère lu car il n'y a ni '-' ni '+')
           ^
Étape 3 : "42" ("42" est lu)
             ^
L'entier analysé est 42.
Puisque 42 est compris entre [-2^31, 2^31 - 1], le résultat final est 42.
```

**Exemple 2:**  
**Input:** s = " -42"  
**Output:** -42  
**Explication:**

```
Étape 1 : "   -42 " (les espaces de début sont lus et ignorés)
              ^
Étape 2 : "   -42" ("-" est lu, le résultat doit donc être négatif)
               ^
Étape 3 : "   -42" ("42" est lu)
                 ^
L'entier analysé est -42.
Puisque -42 est compris entre [-2^31, 2^31 - 1], le résultat final est -42.
```

**Exemple 3:**  
**Input:** s = "4193 with words"  
**Output:** 4193  
**Explication:**

```
Étape 1 : "4193 avec mots" (aucun caractère lu car il n'y a pas d'espace de début)
           ^
Etape 2 : "4193 avec mots" (aucun caractère lu car il n'y a ni '-' ni '+')
           ^
Étape 3 : "4193 avec des mots" ("4193" est lu ; la lecture s'arrête car le caractère suivant n'est pas un chiffre)
               ^
L'entier analysé est 4193.
Puisque 4193 est compris entre [-2^31, 2^31 - 1], le résultat final est 4193.
```

## Contraintes

`0 <= s.length <= 200`  
`s` se compose de lettres anglaises (minuscules et majuscules), de chiffres (`0-9`), `' '`, `'+'`, `'-'`, et `'.'`.

## Note personnelle

J'ai suivi essentiellement les instructions fournies dans l'énoncé, en mettant également en œuvre certains concepts que j'ai rencontrés dans l'exercice précédent.

Complexité temporelle: `O(n)`  
Complexité spatiale: `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
