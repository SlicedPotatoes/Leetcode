# 2859. Sum of Values at Indices With K Set Bits

## Énoncé

On vous donne un tableau d'entiers **indexé à partir de 0** `nums` et un entier `k`.

Retournez un entier qui représente la **somme** des éléments de `nums` dont les **indices** correspondants ont **exactement** `k` bits à 1 dans leur représentation binaire.

## Exemple

**Exemple 1:**  
**Input:** nums = [5,10,1,5,2], k = 1  
**Output:** 13  
**Explication:**  
La représentation binaire des indices est:  
0 = "000"  
1 = "001"  
2 = "010"  
3 = "011"  
4 = "100"  
Les indices 1, 2, et 4 ont 1 bits de valeur 1 dans leur représentation binaire.
Ainsi, la réponse est nums[1] + nums[2] + nums[4] = 13.

**Exemple 2:**  
**Input:** nums = [4,3,2,1], k = 2  
**Output:** 1  
**Explication:**  
La représentation binaire des indices est:  
0 = "00"  
1 = "01"  
2 = "10"  
3 = "11"  
Seulement l'indice 3 a 2 bits de valeur 1 dans ca représentation binaire.
Ainsi, la réponse est nums[3] = 1.

## Contraintes

`1 <= nums.length <= 1000`  
`1 <= nums[i] <= 10^5`  
`0 <= k <= 10`

## Note personnelle

Pour résoudre ce problème, je parcours les indices `0` jusqu'à `nums.size()` et je compte à chaque itération le nombre de bits à `1` de l'indice. Si ce nombre est égal à `k`, j'ajoute la valeur correspondante de `nums` à ma réponse.

```cpp
int sumIndicesWithKSetBits(vector<int>& nums, int k) {
  int ans = 0; // Initialisation de la somme à 0

  // Parcourir tous les indices du vecteur 'nums'
  for(int i = 0; i < nums.size(); i++){
    if(__builtin_popcount(i) == k){
      ans += nums[i]; // Ajouter l'élément à la somme si le nombre de bits à 1 de l'indice est égal à 'k'
    }
  }

  // Retourner la somme totale
  return ans;
}
```

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

Une autre technique consiste à générer les nombres ayant exactement `k` bits à 1.

Pour initialiser le premier nombre, on effectue un décalage de `k` bits vers la gauche au nombre `1` puis on soustrait `1` au résultat.

Ensuite, pour générer le nombre suivant, voici les étapes:

- On commence par récupérer le bit le plus bas: `lowestBit = n & -n`.
- On décale vers la gauche le bit à 1 le plus à droite de `n`: `leftBits = n + lowestBit`.
- On calcule les bits modifiés: `n ^ leftbits`.
- On calcule les bits à droite du bit `lowestBit`: `(changedBits / lowestBit) >> 2`. La division entière donne le nombre de bits à droite du bit le plus bas à 1. Ensuite, `>> 2` effectue un décalage de 2 bits vers la droite, ce qui équivaut à diviser par 4 pour obtenir la partie correcte des bits de droite.
- On obtient le résultat final: `leftBits | rightBits`.

Voici le fonctionnement démontré avec un exemple:
Prenons `n` qui a pour valeur `7`.

1. Trouver le `lowestBit`:  
   `lowestBit = n & -n`.  
   `7 & -7 = 1; 0111(7) & 1001(-7) = 0001(1)`.
2. Calculer les bits de gauche:  
   `leftBits = n + lowestBit`.  
   `7 + 1 = 0; 0111(7) + 0001(1) = 1000(8)`.
3. Calculer les bits modifiés:  
   `changedBits = n ^ leftBits`.  
   `7 ^ 8 = 15; 0111(7) ^ 1000(8) = 1111(15)`.
4. Calculer les bits de droite:  
   `rightBits = (changedBits / lowestBit) >> 2`  
   `changedBits / lowestBit = 15 / 1 = 15 = 1111(15) / 0001(1) = 15 (1111)`.  
   `rightBits = 15 >> 2 = 1111(15) >> 2 = 0011(3)`.
5. Résultat final:  
   `result = leftBits | rightBits`  
   `8 | 3 = 11 = 1000(8) | 0011(3) = 1011(11)`.

```cpp
int getNext(int n){
  // Obtenir le bit le plus bas à 1
  int lowestBit = n & -n;
  // Obtenir les bits à gauche
  int leftBits = n + lowestBit;
  // Bits changés entre n et leftBits
  int changedBits = n ^ leftBits;
  // Bits à droites ajustés
  int rightBits = (changedBits / lowestBit) >> 2;

  // Combiner les bits gauche et droite pour obtenir le prochain nombre
  return leftBits | rightBits;
}

int sumIndicesWithKSetBits(vector<int>& nums, int k) {
  // Si k est 0, retourner le premier élément car seul l'indice 0 a 0 bits à 1
  if(k == 0){
    return nums[0];
  }

  int ans = 0;

  // Initialiser l'index avec les k bits les plus bas à 1
  for(int index = (1 << k) - 1; index < nums.size(); index = getNext(index)){
    ans += nums[index]; // Ajouter l'élément au résultat
  }

  // Retourner la somme totale
  return ans;
}
```

Je tiens à préciser que la formule pour trouver le prochain nombre ne vient pas de moi, et que j'ai du mal à comprendre exactement pourquoi elle fonctionne. Cependant, je tenais à la partager car c'est la manière optimale de résoudre ce problème.

Cette approche présente une complexité temporelle de `O( C(n, k) )` et une complexité spatiale de `O(1)` où `C(n, k)` est le coefficient binomial qui représente le nombre de combinaisons d'indices avec `k` bits à `1` compris entre `0` et `n`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
