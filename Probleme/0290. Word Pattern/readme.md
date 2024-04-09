# 290. Word Pattern

## Énoncé

Étant donné un `pattern` et une chaîne `s`, recherchez si `s` suit le même `pattern`.

Ici, **suit** signifie une correspondance complète, telle qu'il y a une bijection entre une lettre dans `pattern` et un mot **non vide** dans `s`.

## Exemple

**Exemple 1:**  
**Input:** pattern = "abba", s = "dog cat cat dog"  
**Output:** true

**Exemple 2:**  
**Input:** pattern = "abba", s = "dog cat cat fish"  
**Output:** false

**Exemple 3:**  
**Input:** pattern = "aaaa", s = "dog cat cat dog"  
**Output:** false

## Contraintes

`1 <= pattern.length <= 300`  
`pattern` ne contient que des lettres anglaises minuscules.  
`1 <= s.length <= 3000`  
`s` ne contient que des lettres anglaises minuscules et des espaces `' '`.  
`s` **ne contient aucun** espace de début ou de fin.  
Tous les mots dans `s` sont séparés par un **unique espace**.

## Note personnelle

Pour résoudre ce problème, j'ai choisi d'adopter une approche utilisant le principe des **Deux Pointeurs** pour extraire les mots de la chaîne. J'utilise également une HashMap pour établir une correspondance entre un caractère du motif et un mot, et pour garantir l'unicité des mots, j'utilise un ensemble.

Pour faciliter l'extraction du dernier mot, j'ajoute un espace `' '` à la fin de `s`.

Je commence par initialiser deux variables:

- `indexPattern`, qui représente l'indice du caractère du motif, est initialisée à `0`.
- `left`, qui représente le début d'un mot, est également initialisée à `0`.

Je crée une boucle qui itère sur chaque élément de `s` grâce à un indice `right`. À chaque itération, je vérifie si `s[right]` est un espace, dans ce cas, nous avons un mot qui commence à l'indice `left` et se termine à l'indice `right` exclu.

Il ne me reste plus qu'à vérifier la correspondance avec le motif. Il y a plusieurs cas:

- Le caractère du motif a déjà été vu, alors on vérifie si le mot correspond.
- LLe caractère du motif n'a pas été vu, on vérifie si le mot est unique grâce à l'ensemble, si c'est le cas, on l'ajoute à l'ensemble et on définit dans la HashMap le caractère du motif au mot.

Si pendant l'itération, le mot ne correspond pas pour un caractère du motif, ou n'est pas unique quand on définit la valeur d'un caractère, alors on retourne `false`.

Si la boucle se termine sans retourner `false`, on vérifie si l'on a parcouru la totalité du motif et on retourne `true` si c'est le cas, sinon `false`.

La complexité temporelle de cette approche est de `O(n)`, où `n` est la taille de `s`. La complexité spatiale de cette approche est de `O(n + p)`, où `p` est le nombre de caractères distincts dans `pattern`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
