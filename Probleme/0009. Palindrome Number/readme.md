# 9. Palindrome Number

## Énoncé

Étant donné un entier `x`, renvoie `true` si `x` est un palindrome, sinon `false`.

Pourriez-vous le résoudre sans convertir l'entier en chaîne ?

## Exemple

**Exemple 1:**  
**Input:** x = 121  
**Output:** true  
**Explication:** 121 se lit 121 de gauche à droite et de droite à gauche.

**Exemple 2:**  
**Input:** x = -121  
**Output:** false  
**Explication:** De gauche à droite, on lit -121. De droite à gauche, cela devient 121-. Ce n'est donc pas un palindrome.

**Exemple 3:**  
**Input:** x = 10  
**Output:** false  
**Explication:** 01 de droite à gauche. Ce n'est donc pas un palindrome.

## Contraintes

`-2^31 <= x <= 2^31 - 1`

## Note personnelle

Ma première approche implique la conversion de l'entier en une chaîne de caractères nommée `s`. Ensuite, je déclare deux variables, `i` initialisée à `0`, et `j` initialisée à `s.size() - 1`.

Je parcours ces indices tant que `i <= j`, vérifiant à chaque itération si `s[i] != s[j]`. Si tel est le cas, cela signifie que `x` n'est pas un palindrome, sinon, j'incrémente `i` et décrémente `j`.

```cpp
bool isPalindrome(int x) {
  // Convertir le nombre entier en une chaîne de caractères
  string s = to_string(x);

  // Déclarer deux indices, un au début et un à la fin de la chaîne
  int i = 0, j = s.size() - 1;

  // Parcourir la chaîne des deux côtés simultanément jusqu'au milieu
  while (i <= j) {
    // Si les caractères à ces indices sont différents, ce n'est pas un palindrome
    if (s[i] != s[j]) {
      return false;
    }

    // Déplacer les indices vers le centre de la chaîne
    i++;
    j--;
  }

  // Si la boucle se termine sans retourner false, alors c'est un palindrome
  return true;
}
```

Bien que cette méthode soit efficace avec une complexité temporelle et spatiale de `O(n)`, où `n` représente le nombre de chiffres dans `x`, elle ne satisfait pas la condition d'écrire un algorithme sans conversion de l'entier en chaîne de caractères. Je vais donc envisager une approche plus mathématique.

Cette nouvelle approche consiste à créer la valeur inversée de `x` et à vérifier si elle est égale à `x`.

Pour cela, j'initialise une variable `_x` avec la valeur de `x`, afin de ne pas altérer `x` pour la comparaison finale. Ensuite, je crée une variable `__x` pour stocker la valeur inversée de `x`.

Je mets en place une boucle qui continue tant que `_x != 0`. À chaque itération, je réalise les étapes suivantes:

- J'obtiens le dernier chiffre de `_x` avec `_x % 10` , que je stocke dans une variable `r`.
- Je supprime le dernier élément de `_x` comme ceci: `(_x - r) / 10`.
- Je construis ma valeur inversée: `__x *= 10` et `__x += r`.

À la fin de la boucle, je vérifie si `x == __x`.

Une optimisation consiste à vérifier si `x` est négatif. Dans ce cas, nous n'avons pas besoin de calculer son inverse car il ne sera pas un palindrome.

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
