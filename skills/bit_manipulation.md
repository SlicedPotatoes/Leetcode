# Bit Manipulation

## Principe

La manipulation de bits consiste à travailler avec les plus petites unités de données, les bits, qui sont des valeurs binaires (0 ou 1). Cela permet de réaliser des opérations sur des données au niveau le plus fondamental.

Les opérations booléennes sont des opérations logiques qui agissent sur les bits individuels. Elles comprennent :

- **ET logique(AND)**: Cette opération retourne 1 seulement si les deux bits en entrée sont 1, sinon elle retourne 0.
- **OU logique(OR)**: Cette opération retourne 1 si au moins l'un des bits en entrée est 1, sinon elle retourne 0.
- **NON logique(NOT)**: Cette opération inverse chaque bit en entrée, transformant les 0 en 1 et les 1 en 0.
- **OU exclusif(XOR)**: Cette opération retourne 1 si exactement l'un des bits en entrée est 1, mais pas les deux, sinon elle retourne 0.

Il existe également des opérations de décalage:

- **Décalage à gauche(<<)**: Cette opération déplace tous les bits d'un nombre binaire vers la gauche d'un certain nombre de positions. Les bits vacants à droite sont remplis avec des zéros.
- **Décalage à droite(>>)**: Cette opération déplace tous les bits d'un nombre binaire vers la droite d'un certain nombre de positions. Pour les décalages à droite sans signe, les bits vacants à gauche sont remplis avec des zéros. Pour les décalages à droite avec signe, le bit le plus à gauche (le bit de signe) est dupliqué pour remplir les bits vacants à gauche.

### Facile

| Label                                                                                                                     | Tags                                                                                                                       | Date       |
| ------------------------------------------------------------------------------------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------- | ---------- |
| [67. Add Binary](../Probleme/0067.%20Add%20Binary/)                                                                       | [`Math`](./math.md), [`String`](./string.md), [`Bit Manipulation`](./bit_manipulation.md), [`Simulation`](./simulation.md) | 04-03-2024 |
| [338. Counting Bits](../Probleme/0338.%20Counting%20Bits/)                                                                | [`Dynamic Programming`](./dp.md), [`Bit Manipulation`](./bit_manipulation.md)                                              | 08-03-2024 |
| [401. Binary Watch](../Probleme/0401.%20Binary%20Watch/)                                                                  | [`Backtracking`](./backtracking.md), [`Bit Manipulation`](./bit_manipulation.md)                                           | 18-06-2024 |
| [3095. Shortest Subarray With OR at Least K I](../Probleme/3095.%20Shortest%20Subarray%20With%20OR%20at%20Least%20K%20I/) | [`Array`](./array.md), [`Bit Manipulation`](./bit_manipulation.md), [`Sliding Window`](./sliding_window.md)                | 11-05-2024 |

### Moyen

| Label                                                                                                                                                                 | Tags                                                                                                        | Date       |
| --------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------------------------------------------- | ---------- |
| [2997. Minimum Number of Operations to Make Array XOR Equal to K](../Probleme/2997.%20Minimum%20Number%20of%20Operations%20to%20Make%20Array%20XOR%20Equal%20to%20K/) | [`Array`](./array.md), [`Bit Manipulation`](./bit_manipulation.md)                                          | 22-06-2024 |
| [3011. Find if Array Can Be Sorted](../Probleme/3011.%20Find%20if%20Array%20Can%20Be%20Sorted/)                                                                       | [`Array`](./array.md), [`Bit Manipulation`](./bit_manipulation.md), [`Sorting`](./sorting.md)               | 22-06-2024 |
| [3097. Shortest Subarray With OR at Least K II](../Probleme/3097.%20Shortest%20Subarray%20With%20OR%20at%20Least%20K%20II/)                                           | [`Array`](./array.md), [`Bit Manipulation`](./bit_manipulation.md), [`Sliding Window`](./sliding_window.md) | 11-05-2024 |

### Difficile

| Label | Tags | Date |
| ----- | ---- | ---- |
