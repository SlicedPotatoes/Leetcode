# 50. Pow(x, n)

## Énoncé

Implémentez `pow(x, n)`, qui calcule `x` élevé à la puissance `n` (c'est-à-dire `x^n`).

## Exemple

**Exemple 1:**  
**Input:** x = 2.00000, n = 10  
**Output:** 1024.00000

**Exemple 2:**  
**Input:** x = 2.10000, n = 3  
**Output:** 9.26100

**Exemple 3:**  
**Input:** x = 2.00000, n = -2  
**Output:** 0.25000

## Contraintes

`-100.0 < x < 100.0`  
`-2^31 <= n <= 2^31-1`  
`n` est un entier.  
Soit `x` n'est pas égal à zéro, soit `n > 0`.  
`-10^4 <= x^n <= 10^4`

## Note personnelle

Voici une approche initiale à considérer:

```cpp
double myPow(double x, int n) {
  // Initialisation de la valeur de retour
  double ans = 1;
  // Utilisation de la fonction abs() pour garantir que _n est positif
  int _n = abs(n);

  // Boucle pour calculer la puissance
  for (int i = 0; i < _n; i++) {
    // Multiplier la valeur de retour par x
    ans *= x;
  }

  // Si l'exposant est positif, retourner la réponse, sinon retourner l'inverse de la réponse
  return n > 0 ? ans : 1 / ans;
}
```

Cette méthode a une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`. Toutefois, elle peut être lente pour de grandes valeurs de `n`.

Une approche plus optimisée consiste à utiliser le principe de **Diviser pour régner**:

Prenons par exemple 10^10, le résultat serait `10*10*10*10*10*10*10*10*10*10 = 10000000000`.  
Ce calcul demande 10 opérations, mais elles peuvent être réduites comme suit:

`n = 10`  
Étape 1: `10*10 = 100` => 10^2  
Étape 2: `100*100 = 10000` => 10^4  
Étape 3: `10000*10000 = 100000000` => 10^8  
On ne peut pas continuer car nous dépasserions la valeur de `n`. On sauvegarde le résultat, soustrait la puissance maximale à `n` (`n -= 8`), et on recommence.

`n = 2`  
Étape 4: `10*10 = 100` => 10^2  
On ne peut pas continuer car nous dépasserions la valeur de `n`. On sauvegarde le résultat, soustrait la puissance maximale à `n` (`n -= 2`), et on recommence.

Étape 5: `n == 0`. Le résultat est le produit de tous les sous-résultats trouvés jusqu'à présent : `10^10 = 10^8 * 10^2 = 100000000*100 = 10000000000`

Voici une implémentation récursive de cette approche :

```cpp
double myPow(double x, int n) {
  // Si l'exposant est égal à 0, retourner 1
  if (n == 0) {
    return 1;
  }

  // Initialisation de la valeur de retour à x
  double ans = x;
  // Vérification si l'exposant est négatif
  bool neg = n < 0;
  // Utilisation de la fonction abs() pour garantir que n est positif
  n = abs(n);

  // Utilisation d'une boucle for pour calculer la puissance en utilisant la méthode de la division par 2
  size_t i;
  for(i = 1; i <= n - i; i*= 2){
    // Multiplier la valeur de retour par elle-même
    ans *= ans;
  }
  // Réduire n de la valeur i utilisée dans la boucle for
  n = n - i;

  // Récursion pour traiter le reste de la puissance
  ans *= myPow(x, n);

  // Si l'exposant était négatif, retourner l'inverse de la réponse, sinon retourner la réponse
  return neg ? 1 / ans : ans;
}
```

La complexité temporelle et spatiale de cette approche est de `O(log n)` en raison de sa nature récursive. Une approche itérative aurait une complexité spatiale de `O(1)`.

La version itérative est disponible [ici](main.cpp).

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
