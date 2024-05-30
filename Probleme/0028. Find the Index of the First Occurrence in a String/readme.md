# 28. Find the Index of the First Occurrence in a String

## Énoncé

Étant donné deux chaînes de caractères `needle` et `haystack`, renvoyez l'index de la première occurrence de `needle` dans `haystack`, ou `-1` si `needle` ne fait pas partie de `haystack`.

## Exemple

**Exemple 1:**  
**Input:** haystack = "sadbutsad", needle = "sad"  
**Output:** 0  
**Explication:** "sad" apparaît aux index 0 et 6.  
La première occurrence est à l’index 0, nous renvoyons donc 0.

**Exemple 2:**  
**Input:** haystack = "leetcode", needle = "leeto"  
**Output:** -1  
**Explication:** "leeto" n'est pas apparu dans "leetcode", nous renvoyons donc -1.

## Contraintes

`1 <= haystack.length, needle.length <= 10^4`  
`haystack` et `needle` se composent uniquement de caractères anglais minuscules.

## Note personnelle

Pour résoudre ce problème, j'ai utilisé la technique des deux pointeurs. Un pointeur `j` est utilisé pour parcourir `needle`, et un autre pointeur `i` est utilisé pour parcourir `haystack`.

L'idée est de vérifier caractère par caractère s'il y a correspondance. En cas de non-correspondance, on recule pour réessayer.

Cette méthode a une complexité temporelle de `O(n * m)`, où `n` est la taille de `haystack` et `m` est la taille de `needle`. a complexité spatiale est de `O(1)`.

L'algorithme KMP est une solution plus efficace pour notre problème de recherche de sous-chaîne. Il consiste à créer un tableau de correspondance partielle pour `needle`, qui indique pour chaque position la prochaine position possible d'une occurrence potentielle de la chaîne.

Ensuite, on recherche dans `haystack` en utilisant ce tableau pour savoir comment se déplacer lorsque la correspondance est cassée, ce qui évite de revenir en arrière dans `haystack`.

Pour plus de détails, voir l'[algorithme KMP](https://fr.wikipedia.org/wiki/Algorithme_de_Knuth-Morris-Pratt)

```cpp
// Fonction pour construire le tableau de correspondance partielle (tableau de préfixe) pour l'algorithme KMP
vector<int> buildPartialMatch(string &needle){
  vector<int> pm(needle.size() + 1);
  pm[0] = -1; // Initialisation de la première valeur à -1

  int i = 0;
  int j = -1;

  // Boucle pour remplir le tableau de correspondance partielle
  while (i < needle.size()) {
    if (j == -1 || needle[i] == needle[j]) {
      i++;
      j++;
      pm[i] = j; // Mise à jour du tableau de correspondance partielle
    }
    else {
      j = pm[j]; // Réduction de la longueur du préfixe
    }
  }

  return pm;
}

// Fonction pour trouver la première occurrence de 'needle' dans 'haystack' en utilisant l'algorithme KMP
int strStr(string haystack, string needle) {
  vector<int> pm = buildPartialMatch(needle); // Construction du tableau de correspondance partielle

  int m = 0; // Index pour 'haystack'
  int i = 0; // Index pour 'needle'

  // Boucle pour chercher 'needle' dans 'haystack'
  while(m + i < haystack.size() && i < needle.size()){
    if(haystack[m + i] == needle[i]){
      i++;
      if(i == needle.size()){ return m; } // Correspondance trouvée
    }
    else{
      m += i - pm[i];
      if(i > 0){ i = pm[i]; } // Réinitialiser 'i' pour suivre le tableau de correspondance partielle
    }
  }

  return -1;
}
```

Cette approche KMP a une complexité temporelle de `O(n + m)` et une complexité spatiale de `O(m)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
