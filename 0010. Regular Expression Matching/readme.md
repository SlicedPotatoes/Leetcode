# 10. Regular Expression Matching

## Énoncé

Étant donné une chaîne d'entrée `s` et un modèle `p`, implémentez la correspondance d'expression régulière avec la prise en charge de `'.'` et `'*'` où :

- `'.'` Correspond à n'importe quel caractère.​​​​
- `'*'` Correspond à zéro ou plusieurs éléments précédents.

La correspondance doit couvrir la chaîne d'entrée **entière** (et non partielle).

## Exemple

**Exemple 1:**  
**Input:** s = "aa", p = "a"  
**Output:** false  
**Explication:** "a" ne correspond pas à la chaîne entière "aa".

**Exemple 2:**  
**Input:** s = "aa", p = "a*"  
**Output:** true  
**Explication:** `*` signifie zéro ou plusieurs des éléments précédents, 'a'.

**Exemple 2:**  
**Input:** s = "ab", p = "._"  
**Output:** true  
**Explication:** `._` signifie zéro ou plus de n'importe quel caractère.

## Contraintes

`1 <= s.length <= 20`  
`1 <= p.length <= 20`  
`s` contient uniquement des lettres anglaises minuscules.  
`p` contient uniquement des lettres anglaises minuscules, `'.'`, et `'*'`.  
Il est garanti qu'à chaque apparition du caractère ``*'`, il y aura un précédent caractère valide auquel correspondre.

## Note personnelle

J'ai opté pour une approche récursive pour résoudre ce problème, mais je dois admettre que mon code est extrêmement désorganisé en raison de mon manque de compétence. Je suis pleinement conscient que sa complexité temporelle et spatiale est de `O(2^n)` dans le pire des cas, ce qui est considérable pour ce type de problème.

Les contraintes généreuses permettent à mon code de ne pas **Time Out**, au vu de la longueur maximale du pattern et de la chaine d'entrée.

Mon code ressemble à un "Spaghetti code", ce qui rend difficile sa description. Pour le rédiger, j'ai progressé petit à petit en me confrontant à des données d'entrée qui ne donnaient pas le résultat escompté, puis en corrigeant au fur et à mesure jusqu'à obtenir une solution qui réussit tous les jeux de tests.

J'ai également apporté plusieurs optimisations, passant de la première version qui prenait 2250ms, à la seconde qui prenait 280ms, jusqu'à atteindre 0ms.

Cependant, j'ai remarqué des approches en `O(n^2)` voire même `O(n)` utilisant la programmation dynamique. Je pense que je vais explorer ce concept à l'avenir car c'est un type d'approche que j'ai du mal à maîtriser, même si j'en comprends légèrement le principe.

<img src="../imgs/0010-runtime.png"/>
<img src="../imgs/0010-memory.png"/>
