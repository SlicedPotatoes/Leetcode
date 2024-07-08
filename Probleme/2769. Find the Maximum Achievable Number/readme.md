# 2769. Find the Maximum Achievable Number

## Énoncé

Étant donné deux entiers, `num` et `t`. Un **nombre est atteignable** s'il peut devenir égal à `num` après avoir appliqué l'opération suivante:

Augmenter ou diminuer le nombre de `1`, et simultanément augmenter ou diminuer `num  de `1`.

Retourner le **nombre atteignable maximal** après avoir appliqué l'opération au maximum `t` fois.

## Exemple

**Exemple 1:**  
**Input:** num = 4, t = 1  
**Output:** 6

**Exemple 2:**  
**Input:** num = 3, t = 2  
**Output:** 7

## Contraintes

`1 <= num, t <= 50`

## Note personnelle

### Simplification du Problème

Nous cherchons à déterminer un entier `x` le plus grand possible, tel que, après avoir appliqué au maximum `t` fois l'opération donnée, `x` et `num` soient égaux. La valeur de retour sera `x` initial.

L'opération optimale pour maximiser `x` consiste à diminuer `x` et à incrémenter `num`.

Cette valeur de `x` peut être facilement obtenue grâce à la formule suivante: `x = num + (t * 2)`.

### Preuve Mathématique de la Formule

Pour maximiser `x` initial, nous devons augmenter `x` au maximum tout en respectant la condition d'égalité avec `num` après `t` opérations.

Chaque opération optimale augmente `num` et diminue `x`, réduisant ainsi leur écart de `2`.  
Après `t` opérations, la différence entre `x` et `num` est réduite de `2t`.

Pour que `x` et `num` soient égaux après `t` opérations, nous devons avoir: `x_final = num_final`.

En partant des valeurs initiales `x_initial` et `num_initial`, après `t` opérations optimales, nous obtenons:

- `x_final = x_initial - t`
- `num_final = num_initial + t`

Pour que `x_final` soit égal à `num_final`, nous devons avoir `x_initial - t = num_initial + t`.  
En isolant `x_initial`, nous obtenons: `x_initial = num_initial + 2t`.

### Code et Complexité

```cpp
int theMaximumAchievableX(int num, int t) {
  return num + (t * 2);
}
```

- Complexité Temporelle: `O(1)`.
- Complexité Spatiale: `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
