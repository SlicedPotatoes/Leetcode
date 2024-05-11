# 3099. Harshad Number

## Énoncé

Un entier divisible par la **somme** de ses chiffres est appelé un nombre **Harshad**. Vous avez un entier `x`. Retournez la somme des chiffres de `x` si `x` est un nombre Harshad, sinon, retournez `-1`.

## Exemple

**Exemple 1:**  
**Input:** x = 18  
**Output:** 9  
**Explication:**  
La somme des chiffres de `x` est `9`. `18` est divisible par `9`. Donc `18` est un nombre Harshad et la réponse est `9`.

**Exemple 2:**  
**Input:** 23  
**Output:** -1  
**Explication:**  
La somme des chiffres de `x` est `5`. `23` n'est pas divisible par `5`. Donc `23` n'est pas un nombre Harshad et la réponse est `-1`.

## Contraintes

`1 <= x <= 100`

## Note personnelle

La clé technique de cet exercice réside dans la manière de récupérer les chiffres d'un nombre. Plusieurs approches s'ouvrent à nous pour y parvenir.

Approche Conversion:

```cpp
int sumOfTheDigitsOfHarshadNumber(int x) {
  int sum = 0;
  string _x = to_string(x);

  for(char c : _x){
    sum += c - '0';
  }

  return x % sum == 0 ? sum : -1;
}
```

Cette méthode présente une complexité temporelle et spatiale de `O(d)`, où `d` est le nombre de chiffres composant `n`.

Approche Mathématique:

```cpp
int sumOfTheDigitsOfHarshadNumber(int x) {
  int sum = 0;
  int current = x;

  while(current != 0){
    sum += current % 10;
    current /= 10;
  }

  return x % sum == 0 ? sum : -1;
}
```

Cette méthode a une complexité temporelle de `O(d)` et une complexité spatiale de `O(1)`.

Généralement, la fonction qui convertit un entier en chaîne de caractères utilise le même principe de division successive pour y parvenir. Cette approche est donc la plus optimale pour obtenir le résultat.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
