# 3146. Permutation Difference between Two Strings

## Énoncé

ous avez deux chaînes de caractères `s` et `t` telles que chaque caractère apparaît au maximum une fois dans `s` et `t` est une permutation de `s`.

La **différence de permutation** entre `s` et `t` est définie comme la **somme** de la différence absolue entre l'indice d'apparition de chaque caractère dans `s` et l'indice d'apparition du même caractère dans `t`.

Retournez la **différence de permutation** entre `s` et `t`.

## Exemple

**Exemple 1:**  
**Input:** s = "abc", t = "bac"  
**Output:** 2  
**Explication:**  
Pour `s = "abc"` et `t = "bac"`, la différence de permutation entre `s` et `t` est égale à la somme de:

- La différence absolue entre l'index de l'occurrence de `"a"` dans `s` et l'index de l'occurrence de `"a"` dans `t`.
- La différence absolue entre l'index de l'occurrence de `"b"` dans `s` et l'index de l'occurrence de `"b"` dans `t`.
- La différence absolue entre l'index de l'occurrence de `"c"` dans `s` et l'index de l'occurrence de `"c"` dans `t`.

C'est-à-dire, la différence de permutation entre `s` et `t` est égale à `|0 - 1| + |2 - 2| + |1 - 0| = 2`.

**Exemple 2:**  
**Input:** s = "abcde", t = "edbac"  
**Output:** 12  
**Explication:** La différence de permutation entre `s` et `t` est égale à `|0 - 3| + |1 - 2| + |2 - 4| + |3 - 1| + |4 - 0| = 12`.

## Contraintes

`1 <= s.length <= 26`  
Chaque caractère apparaît au plus une fois dans `s`.  
`t` est une permutation de `s`.  
`s` se compose uniquement de lettres anglaises minuscules.

## Note personnelle

Le fait qu'un caractère ne puisse apparaître qu'une seule fois dans `s` simplifie le problème. L'idée est d'utiliser une HashMap pour stocker l'indice d'apparition de chaque caractère.

Ensuite, nous allons itérer sur chaque caractère de `t`, calculer la différence absolue avec les valeurs stockées dans la HashMap, et retourner la somme de ces différences.

```cpp
int findPermutationDifference(string &s, string &t) {
  // Map pour stocker les positions des caractères de la chaîne s
  unordered_map<char, int> mp;

  // Remplir la map avec les positions des caractères de la chaîne s
  for(int i = 0; i < s.size(); i++){
    mp[s[i]] = i;
  }

  int ans = 0;

  // Calculer la différence de permutation
  for(int i = 0; i < t.size(); i++){
    ans += abs(i - mp[t[i]]);
  }

  return ans;
}
```

Cette approche a une complexité temporelle et spatiale de `O(n)`.

Étant donné que `s` est composé de caractères allant de `a` à `z`, nous pouvons remplacer la HashMap par un vecteur.

```cpp
int findPermutationDifference(string &s, string &t) {
  vector<int> arr(26, 0);

  for(int i = 0; i < s.size(); i++){
    arr[s[i] - 'a'] = i;
  }

  int ans = 0;

  for(int i = 0; i < t.size(); i++){
    ans += abs(i - arr[t[i] - 'a']);
  }

  return ans;
}
```

Cette solution présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

Cette approche a l'avantage de supprimer les coûts associés à l'utilisation de la HashMap, ce qui la rend théoriquement plus rapide et moins gourmande en mémoire que la précédente.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
