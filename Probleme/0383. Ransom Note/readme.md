# 383. Ransom Note

## Énoncé

Étant donné deux chaînes `ransomNote` et `magazine`, renvoyez `true` si `ransomNote` peut être construit en utilisant les lettres de `magazine` et `false` sinon.

Chaque lettre dans `magazine` ne peut être utilisée qu'une seule fois dans `ransomNote`.

## Exemple

**Exemple 1:**  
**Input:** ransomNote = "a", magazine = "b"  
**Output:** false

**Exemple 2:**  
**Input:** ransomNote = "aa", magazine = "ab"  
**Output:** false

**Exemple 3:**  
**Input:** ransomNote = "aa", magazine = "aab"  
**Output:** true

## Contraintes

`1 <= ransomNote.length, magazine.length <= 10^5`  
`ransomNote` et `magazine` sont constitués de lettres anglaises minuscules.

## Note personnelle

Pour résoudre ce problème, une première étape consiste à inclure une condition au début de la fonction pour vérifier si la longueur de la chaîne `ransomNote` est supérieure à celle de la chaîne `magazine`. Si tel est le cas, il est impossible de construire `ransomNote`, donc la fonction retourne `false`.

Mon approche initiale utilise une HashMap pour compter les occurrences de chaque caractère de `magazine`. Une fois les caractères comptés, je parcours `randomNode` et vérifie si son nombre d'occurrences est supérieur à `0`. Si ce n'est pas le cas, je retourne `false`, sinon je décrémente le compteur.

```cpp
bool canConstruct(string ransomNote, string magazine) {
  // Vérifie si la taille du ransomNote est supérieure à celle du magazine
  // Si c'est le cas, il est impossible de construire le ransomNote avec les lettres disponibles dans le magazine
  if (ransomNote.size() > magazine.size()){
    return false;
  }

  // Utilisation d'une unordered_map pour enregistrer la fréquence des caractères dans le magazine
  unordered_map<char, int> mp;

  // Calcul de la fréquence des caractères dans le magazine
  for(char c : magazine){
    mp[c]++; // Incrémente le compteur pour le caractère c
  }

  // Vérifie si chaque caractère du ransomNote peut être construit à partir du magazine
  for(char c : ransomNote){
    // Si la fréquence du caractère dans le magazine est égale à zéro, cela signifie qu'il n'est pas disponible
    if(mp[c] == 0){
      return false;
    }
    // Décrémente la fréquence du caractère utilisé
    mp[c]--;
  }

  // Si toutes les lettres du ransomNote peuvent être construites à partir du magazine, retourne vrai
  return true;
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`, où `n` est la taille de `magazine`.

Une autre approche consiste à exploiter la contrainte indiquant que les chaînes en entrée sont composées uniquement de lettres anglaises minuscules. Ainsi, on peut remplacer la HashMap par un vecteur de taille 26, ce qui évite l'utilisation d'une structure de données plus lourde à gérer.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
