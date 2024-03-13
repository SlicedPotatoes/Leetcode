# 443. String Compression

## Énoncé

Étant donné un tableau de caractères `chars`, compressez-le en utilisant l'algorithme suivant:

Commencez par une chaîne vide `s`. Pour chaque groupe de **caractères répétitifs consécutifs** dans `chars`:

- Si la longueur du groupe est `1`, ajoutez le caractère à `s`.
- Sinon, ajoutez le caractère suivi de la longueur du groupe.

La chaîne compressée `s` **ne doit pas être renvoyée séparément**, mais plutôt être stockée **dans le tableau de caractères d'entrée** `chars`. Notez que les longueurs de groupe de `10` ou plus seront divisées en plusieurs caractères dans `chars`.

Une fois que vous avez terminé **de modifier le tableau d'entrée**, renvoyez la nouvelle longueur du tableau.

Vous devez écrire un algorithme qui utilise uniquement un espace supplémentaire constant.

## Exemple

**Exemple 1:**  
**Input:** chars = ["a","a","b","b","c","c","c"]  
**Output:** Renvoie 6, et les 6 premiers caractères du tableau d'entrée doivent être: ["a","2","b","2","c","3"]  
**Explication:** Les groupes sont "aa", "bb", et "ccc", ce qui donne "a2b2c3".

**Exemple 2:**  
**Input:** chars = ["a"]  
**Output:** Renvoie 1 et le premier caractère du tableau d'entrée doit être: ["a"]  
**Explication:** Le seul groupe est "a", qui reste non compressé puisqu'il s'agit d'un seul caractère.

**Exemple 3:**  
**Input:** chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]  
**Output:** Renvoyez 4 et les 4 premiers caractères du tableau d'entrée doivent être: ["a","b","1","2"].  
**Explication:** Les groupes sont "a" et "bbbbbbbbbbbb", ce qui donne "ab12".

## Contraintes

`1 <= chars.length <= 2000`  
`chars[i]` est une lettre anglaise minuscule, une lettre anglaise majuscule, un chiffre ou un symbole.

## Note personnelle

Pour résoudre ce problème, j'ai opté pour une méthode basée sur l'utilisation de deux indices. Le premier, nommé `i`, est utilisé pour suivre la progression actuelle à travers le tableau, tandis que le second, `newIndex`, conserve la position actuelle du dernier élément du tableau compressé.

Je parcours le tableau en utilisant l'indice `i` et effectue les actions suivantes:

- Je conserve le caractère actuel dans une variable appelée `currentChar`.
- Je stocke la valeur de `i` dans une variable temporaire `j`.
- Tant que `chars[j] == currentChar`, j'incrémente `j`
- J'actualise le tableau `chars` de la manière suivante:
  - J'assigne `currentChar` à `chars[newIndex]`, puis j'incrémente `newIndex` de `1`.
  - Je calcule la différence entre `j` et `i`. Si cette différence est supérieure à `1`, je convertis cette différence en chaîne de caractères et j'ajoute chaque caractère à `chars`, en incrémentant `newIndex`.
- Je mets à jour la valeur de `i` avec celle de `j`.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
