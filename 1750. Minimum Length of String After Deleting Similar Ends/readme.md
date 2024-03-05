# 1750. Minimum Length of String After Deleting Similar Ends

## Énoncé

Étant donné une chaîne `s` composée uniquement de caractères `'a'`, `'b'`, et `'c'`. Il vous est demandé d'appliquer l'algorithme suivant sur la chaîne un certain nombre de fois:

- Choisissez un préfixe **non vide** dans la chaîne `s` où tous les caractères du préfixe sont égaux.
- Choisissez un suffixe **non vide** dans la chaîne `s` où tous les caractères de ce suffixe sont égaux.
- Le préfixe et le suffixe ne doivent se croiser à aucun index.
- Les caractères du préfixe et du suffixe doivent être identiques.
- Supprimez à la fois le préfixe et le suffixe

Renvoie la **longueur minimale** de `s` après avoir effectué l'opération ci-dessus un certain nombre de fois (éventuellement zéro fois).

## Exemple

**Exemple 1:**  
**Input:** s = "ca"  
**Output:** 2  
**Explication:** Vous ne pouvez supprimer aucun caractère, la chaîne reste donc telle quelle.

**Exemple 2:**  
**Input:** s = "cabaabac"  
**Output:** 0  
**Explication:**  
Une séquence optimale d’opérations est la suivante:

- Prenez le préfixe = "c" et le suffixe = "c" et supprimez-les, s = "abaaba".
- Prenez le préfixe = "a" et le suffixe = "a" et supprimez-les, s = "baab".
- Prenez le préfixe = "b" et le suffixe = "b" et supprimez-les, s = "aa".
- Prenez le préfixe = "a" et le suffixe = "a" et supprimez-les, s = "".

**Exemple 3:**  
**Input:** s = "aabccabba"  
**Output:** 3  
**Explication:**  
Une séquence optimale d’opérations est la suivante:

- Prenez le préfixe = "aa" et le suffixe = "a" et supprimez-les, s = "bccabb".
- Prenez le préfixe = "b" et le suffixe = "bb" et supprimez-les, s = "cca".

## Contraintes

`1 <= s.length <= 10^5`  
`s` only consists of characters `'a'`, `'b'`, and `'c'`.

## Note personnelle

J'ai suivi les directives de l'exercice de la manière suivante:

- J'ai déclaré deux variables, `i` initialisée à `0` et `j` initialisée à `s.size() - 1`
- Ensuite, j'ai mis en place une boucle qui continue tant que `i < j`
- À chaque itération, je vérifie si `s[i] == s[j]`
- Si ce n'est pas le cas, je sors de la boucle.
- Si c'est le cas, j'incrémente `i` jusqu'à ce que `s[i]` soit un caractère différent. Je fais de même pour `j` en le décrémentant.

La taille de la nouvelle chaîne est `j - i + 1`.

Complexité temporelle: `O(n)`  
Complexité spatiale: `O(1)`

<img src="../imgs/1750-runtime.png"/>
<img src="../imgs/1750-memory.png"/>
