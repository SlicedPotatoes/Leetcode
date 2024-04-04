# 205. Isomorphic Strings

## Énoncé

Étant donné deux chaînes `s` et `t`, déterminez si elles sont isomorphes.

Deux chaînes `s` et `t` sont isomorphes si les caractères dans `s` peuvent être remplacés pour obtenir `t`.

Toutes les occurrences d'un caractère doivent être remplacées par un autre caractère tout en préservant l'ordre des caractères. Il n'est pas possible d'associer deux caractères au même caractère, mais un caractère peut être associé à lui-même.

## Exemple

**Exemple 1:**  
**Input:** s = "egg", t = "add"  
**Output:** true

**Exemple 2:**  
**Input:** s = "foo", t = "bar"  
**Output:** false

**Exemple 3:**  
**Input:** s = "paper", t = "title"  
**Output:** true

## Contraintes

`1 <= s.length <= 5 * 10^4`  
`t.length == s.length`  
`s` et `t` sont constitués de n'importe quel caractère ascii valide.

## Note personnelle

Ma première approche repose sur l'utilisation d'un hashmap pour établir une correspondance entre les caractères et un ensemble pour garder une trace des éléments déjà mappés.

L'idée est de parcourir simultanément les caractères de `s` et `t`. On vérifie si le caractère actuel de `s` est mappé, si c'est le cas, on vérifie si le caractère actuel de `t` correspond au mappage. Sinon, on retourne `false`.

Si le caractère actuel de `s` n'est pas mappé, on vérifie si le caractère de `t` l'a déjà été. Si c'est le cas, on retourne `false`, sinon, on effectue le mappage du caractère.

Si la boucle se termine sans avoir retourné `false`, on retourne `true`.

```cpp
bool isIsomorphic(string s, string t) {
  // Map pour stocker le mapping des caractères de s vers t
  unordered_map<char, char> mp;
  // Ensemble pour vérifier si un caractère de t est déjà mappé
  unordered_set<char> alreadyMapped;

  for(int i = 0; i < s.size(); i++){
    // Si le caractère de s n'est pas déjà mappé
    if(mp.find(s[i]) == mp.end()){
      // Si le caractère de t est déjà mappé à un autre caractère de s
      if(alreadyMapped.contains(t[i])){
        // Les chaînes ne sont pas isomorphes
        return false;
      }
      // Faire le mapping du caractère de s vers t
      mp[s[i]] = t[i];
      // Marquer le caractère de t comme déjà mappé
      alreadyMapped.insert(t[i]);
    }
    // Si le mapping existant pour le caractère de s ne correspond pas au caractère de t
    if(mp[s[i]] != t[i]){
      // Les chaînes ne sont pas isomorphes
      return false;
    }
  }

  // Les chaînes sont isomorphes
  return true;
}
```

La complexité temporelle et spatiale de cette approche est de `O(n)`, où `n` est la taille de la chaîne `s`.

On peut optimiser cette approche légèrement en remplaçant le hashmap par un vecteur de caractères de taille 128 et l'ensemble par un vecteur de booléens de taille 128.

128 est choisi car c'est le nombre d'éléments dans la table ASCII.

L'utilisation de deux vecteurs a l'avantage de réduire la mémoire et d'avoir une complexité de recherche constante par rapport au hashmap/ensemble, qui ont une complexité **moyenne** constante.

Cependant, cette approche présente un inconvénient: elle est uniquement adaptée aux chaînes utilisant des caractères ASCII.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
