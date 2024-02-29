# 1732. Find the Highest Altitude

## Énoncé

Il y a un motard qui part en road trip. Le road trip se compose de `n + 1` points à différentes altitudes. Le motard commence son voyage au point 0 avec une altitude égale à `0`.

Vous recevez un tableau d'entiers `gain` de longueur `n` où `gain[i]` est le **gain net d'altitude** entre les points `i`​​​​​​ et `i + 1` pour tous (`0 <= i <n`). Renvoie l'**altitude la plus élevée** d'un point.

## Exemple

**Exemple 1:**  
**Input:** gain = [-5,1,5,0,-7]  
**Output:** 1  
**Explication:** Les altitudes sont [0,-5,-4,1,1,-6]. Le plus élevé est 1.

**Exemple 2:**  
**Input:** gain = [-4,-3,-2,-1,4,3,2]  
**Output:** 0  
**Explication:** Les altitudes sont [0,-4,-7,-9,-10,-6,-3,-1]. Le plus élevé est 0.

## Contraintes

`n == gain.length`  
`1 <= n <= 100`  
`-100 <= gain[i] <= 100`

## Note personnelle

Ma méthode consiste à parcourir les éléments du tableau tout en calculant leurs sommes et en notant le maximum rencontré.

Compléxité temporelle: `O(n)`  
Compléxité spatiale: `O(1)`

<img src="../imgs/1732-runtime.png"/>
<img src="../imgs/1732-memory.png"/>
