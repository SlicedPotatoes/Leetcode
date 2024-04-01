# 69. Sqrt(x)

## Énoncé

Étant donné un entier non négatif `x`, renvoie la racine carrée de `x` arrondie vers le bas à l'entier le plus proche. L'entier renvoyé doit également être **non négatif**.

Vous **ne devez pas utiliser** de fonction ou d'opérateur d'exposant intégré.

Par exemple, n'utilisez pas `pow(x, 0.5)` en c++ ou `x ** 0.5` en python.

## Exemple

**Exemple 1:**  
**Input:** x = 4  
**Output:** 2  
**Explication:** La racine carrée de 4 est 2, donc 2 est retourné.

**Exemple 2:**  
**Input:** x = 8  
**Output:** 2  
**Explication:** La racine carrée de 8 est 2.82842..., et puisque nous l'arrondissons vers le bas à l'entier le plus proche, 2 est retourné.

## Contraintes

`0 <= x <= 2^31 - 1`

## Note personnelle

Mon approche utilise la méthode de la recherche binaire pour trouver la racine carrée d'un nombre `x`.

L'idée est d'initialiser un intervalle, avec `start` à `1` et `end` à `x`.

Je procède ainsi : tant que `start <= end`, , je calcule le milieu de l'intervalle, puis le carré de ce milieu. En fonction de si le carré du milieu est supérieur ou non à `x`, je mets à jour la borne correspondante.

```cpp
int mySqrt(int x) {
  int start = 1;
  int end = x;

  // Utilisation de la recherche binaire pour trouver la racine carrée de x.
  while (start <= end){
    // Calcul du milieu de l'intervalle
    int mid = start + (end - start) / 2;
    long long midSquare = mid * (long long)mid;

    // Si le carré du milieu est supérieur à x, réduire l'intervalle en ajustant la borne supérieure.
    if(midSquare > x){
      end = mid - 1;
    }
    // Si le carré du milieu est inférieur à x, réduire l'intervalle en ajustant la borne inférieure.
    else{
      start = mid + 1;
    }
  }

  // À ce stade, end contient la plus grande valeur entière dont le carré est inférieur ou égal à x.
  // Cela peut être la réponse exacte ou la valeur juste en dessous de la racine carrée.
  return end;
}
```

Cette approche est plutôt efficace. Cependant, il existe un moyen d'éviter l'utilisation d'un `int_64` (`long long`).

Étant donné que `Sqrt(x) * Sqrt(x) == x`, alors `x / Sqrt(x) == Sqrt(x)`. En utilisant cette propriété de la racine carrée, on peut donc éviter le dépassement d'un `int_32`

```cpp
if(mid > x / mid){
  end = mid - 1;
}
else{
  start = mid + 1;
}
```

Cette méthode présente une complexité temporelle de `O(log x)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
