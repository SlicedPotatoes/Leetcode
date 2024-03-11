# 791. Custom Sort String

## Énoncé

Vous recevez deux chaînes `order` et `s`. Tous les caractères de `order` sont **uniques** et ont été triés auparavant dans un ordre personnalisé.

Permutez les caractères de `s` afin qu'ils correspondent à l'ordre dans lequel `order` a été trié. Plus précisément, si un caractère `x` apparaît avant un caractère `y` dans `order`, alors `x` doit apparaître avant `y` dans la chaîne permutée.

Renvoie toute permutation de `s` qui satisfait cette propriété.

## Exemple

**Exemple 1:**  
**Input:** order = "cba", s = "abcd"  
**Output:** "cbad"  
**Explication:**  
`"a"`, `"b"`, `"c"` apparaissent dans `order`, donc l'ordre de `"a"`, `"b"`, `"c"` devrait être `"c"`, `"b"`, et `"a"`.  
Puisque `"d"` n'apparaît pas dans `order`, il peut se trouver à n'importe quelle position dans la chaîne renvoyée. `"dcba"`, `"cdba"`, `"cbda"` sont également des sorties valides.

**Exemple 2:**  
**Input:** order = "bcafg", s = "abcd"  
**Output:** "bcad"  
**Explication:**  
La sortie `"bcad"` suit correctement cette règle. D'autres arrangements comme `"bacd"` ou `"bcda"` seraient également valides, tant que `"b"`, `"c"`, `"a"` maintiennent leur ordre.

## Contraintes

`1 <= order.length <= 26`  
`1 <= s.length <= 200`  
`order` et `s` sont constitués de lettres anglaises minuscules.  
Tous les caractères de `order` sont **uniques**.

## Note personnelle

Pour aborder l'exercice, j'ai d'abord adopté une approche utilisant une structure de données HashMap pour stocker les éléments de `order` avec leur indice d'apparition respectif. Ensuite, j'ai utilisé la fonction `sort` de C++ en passant en paramètre une fonction personnalisée qui exploite les informations de la HashMap.

```cpp
// Définition d'un conteneur unordered_map pour stocker la priorité de chaque caractère
unordered_map<char, int> orderPriority;
// Fonction d'aide à la comparaison utilisée pour trier les caractères
bool sortHelper(char i, char j) {
  // Si le caractère i est présent dans orderPriority, met à jour sa valeur
  if (orderPriority.find(i) != orderPriority.end()) {
    i = orderPriority[i];
  }
  // Si le caractère j est présent dans orderPriority, met à jour sa valeur
  if (orderPriority.find(j) != orderPriority.end()) {
    j = orderPriority[j];
  }
  // Compare les valeurs mises à jour des caractères i et j
  return i < j;
}

class Solution {
public:
  string customSortString(string order, string s) {
    // Remplit l'unordered_map orderPriority avec les priorités des caractères de order
    for (int i = 0; i < order.size(); i++) {
      orderPriority[order[i]] = i;
    }

    // Trie la chaîne s en utilisant la fonction sortHelper pour déterminer l'ordre de tri
    sort(s.begin(), s.end(), sortHelper);

    // Renvoie la chaîne s triée selon l'ordre spécifié dans order
    return s;
  }
};
```

Cette approche a une complexité temporelle de `O(n log n)` où `n` représente la taille de `s`, et une complexité spatiale de `O(m)` où `m` est la taille de `order`.

Une autre approche que j'ai explorée consiste à initialiser une HashMap pour contenir le nombre d'occurrences de chaque élément de `s`, ainsi qu'un ensemble pour stocker les éléments de `order`.
Une fois la HashMap et l'ensemble remplis, j'itérais sur chaque caractère de `order` pour vérifier s'il se trouve dans la HashMap. Si c'est le cas, j'ajoutais à ma chaîne de sortie le nombre d'occurrences de ce caractère à la fin de celle-ci, préservant ainsi l'ordre des éléments de `order`.

Ensuite, je parcourais les caractères de `s` et je vérifiais s'ils se trouvaient dans l'ensemble `order`. Si ce n'est pas le cas, je les ajoute à la fin de la chaîne de sortie.

L'utilisation d'un ensemble pour stocker les éléments de `order` permet d'obtenir une complexité constante pour déterminer la présence d'un caractère dans `order`.

Cette approche a une complexité temporelle et spatiale de `O(n + m)` où `n` est la longueur de `s` et `m` la longueur de `order`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
