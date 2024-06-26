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

| Label                                                                                                                                                       | Tags                                                                                                                                                                                                                | Date       |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| [11. Container With Most Water](../Probleme/0011.%20Container%20With%20Most%20Water/)                                                                       | [`Array`](./array.md), [`Two Pointers`](./two_pointers.md), [`Greedy`](./greedy.md)                                                                                                                                 | 18-04-2024 |
| [334. Increasing Triplet Subsequence](../Probleme/0334.%20Increasing%20Triplet%20Subsequence/)                                                              | [`Array`](./array.md), [`Greedy`](./greedy.md)                                                                                                                                                                      | 26-02-2024 |
| [452. Minimum Number of Arrows to Burst Balloons](../Probleme/0452.%20Minimum%20Number%20of%20Arrows%20to%20Burst%20Balloons/)                              | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Sorting`](./sorting.md)                                                                                                                                           | 18-03-2024 |
| [649. Dota2 Senate](../Probleme/0649.%20Dota2%20Senate/)                                                                                                    | [`String`](./string.md), [`Greedy`](./greedy.md), [`Queue`](./queue.md)                                                                                                                                             | 18-04-2024 |
| [948. Bag of Tokens](../Probleme/0948.%20Bag%20of%20Tokens/)                                                                                                | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Two Pointers`](./two_pointers.md), [`Sorting`](./sorting.md)                                                                                                      | 04-03-2024 |
| [1382. Balance a Binary Search Tree](../Probleme/1382.%20Balance%20a%20Binary%20Search%20Tree/)                                                             | [`Divide and Conquer`](./divide_and_conquer.md), [`Greedy`](./greedy.md), [`Tree`](./tree.md), [`Depth-First Search`](./dfs.md), [`Binary Search Tree`](./binary_search_tree.md), [`Binary Tree`](./binary_tree.md) | 26-06-2024 |
| [3075. Maximize Happiness of Selected Children](../Probleme/3075.%20Maximize%20Happiness%20of%20Selected%20Children/)                                       | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Sorting`](./sorting.md)                                                                                                                                           | 09-05-2024 |
| [3081. Replace Question Marks in String to Minimize Its Value](../Probleme/3081.%20Replace%20Question%20Marks%20in%20String%20to%20Minimize%20Its%20Value/) | [`Hash Table`](./hash_table.md), [`String`](./string.md), [`Greedy`](./greedy.md), [`Sorting`](./sorting.md), [`Heap (Priority Queue)`](./priority_queue.md), [`Counting`](./counting.md)                           | 22-03-2024 |

### Difficile

| Label                                                             | Tags                                                                                                                      | Date       |
| ----------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------- | ---------- |
| [44. Wildcard Matching](../Probleme/0044.%20Wildcard%20Matching/) | [`String`](./string.md), [`Dynamic Programming`](./dp.md), [`Greedy`](./greedy.md), [`Recursion`](./recursion.md)         | 01-05-2024 |
| [502. IPO](../Probleme/0502.%20IPO/)                              | [`Array`](./array.md), [`Greedy`](./greedy.md), [`Sorting`](./sorting.md), [`Heap (Priority Queue)`](./priority_queue.md) | 15-06-2024 |
