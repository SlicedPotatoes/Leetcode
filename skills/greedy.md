# Greedy

## Principe

Un algorithme **Greedy** ou **Glouton** est un algorithme qui suit le principe de réaliser, étape par étape, un choix optimal local, afin d'obtenir un résultat optimal global.

Par exemple, dans le problème du rendu de monnaie (donner une somme avec le moins possible de pièces), l'algorithme consistant à répéter le choix de la pièce de plus grande valeur qui ne dépasse pas la somme restante est un algorithme glouton.  
Suivant le système de pièces, l'algorithme glouton est optimal ou pas.  
Dans le système de pièces européen (en centimes : 1, 2, 5, 10, 20, 50, 100, 200), où l'algorithme glouton donne la somme suivante pour 37 : 20+10+5+2, on peut montrer que l'algorithme glouton donne toujours une solution optimale.  
Dans le système de pièces (1, 3, 4), l'algorithme glouton n'est pas optimal, comme le montre l'exemple simple suivant. Il donne pour 6 : 4+1+1, alors que 3+3 est optimal.

### Facile

| Label                                                                                   | Tags                                                                  | Date       |
| --------------------------------------------------------------------------------------- | --------------------------------------------------------------------- | ---------- |
| [605. Can Place Flowers](../Probleme/0605.%20Can%20Place%20Flowers/)                    | [`Array`](./array.md), [`Greedy`](./greedy.md)                        | 20-02-2024 |
| [2864. Maximum Odd Binary Number](../Probleme/2864.%20Maximum%20Odd%20Binary%20Number/) | [`Math`](./math.md), [`String`](./string.md), [`Greedy`](./greedy.md) | 01-03-2024 |

### Moyen

| Label                                                                                                                          | Tags                                                                                                           | Date       |
| ------------------------------------------------------------------------------------------------------------------------------ | -------------------------------------------------------------------------------------------------------------- | ---------- |
| [334. Increasing Triplet Subsequence](../Probleme/0334.%20Increasing%20Triplet%20Subsequence/)                                 | [`Array`](./array.md), [`Greedy`](./greedy.md)                                                                 | 26-02-2024 |
| [452. Minimum Number of Arrows to Burst Balloons](../Probleme/0452.%20Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons/) | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Sorting`](./sorting.md)                                      | 18-03-2024 |
| [948. Bag of Tokens](../Probleme/0948.%20Bag%20of%20Tokens/)                                                                   | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Two Pointers`](./two_pointers.md), [`Sorting`](./sorting.md) | 04-03-2024 |

### Difficile

| Label | Tags | Date |
| ----- | ---- | ---- |
