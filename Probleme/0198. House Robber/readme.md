# 198. House Robber

## Énoncé

Vous êtes un voleur professionnel qui envisage de cambrioler des maisons le long d'une rue. Chaque maison a une certaine somme d'argent cachée, la seule contrainte qui vous empêche de cambrioler chacune d'elles est que les maisons adjacentes ont des systèmes de sécurité connectés et **il contactera automatiquement la police si deux maisons adjacentes ont été cambriolées la même nuit.**

Étant donné un tableau d'entiers `nums` représentant le montant d'argent de chaque maison, renvoyez le montant maximum d'argent que vous pouvez voler ce soir **sans alerter la police.**

## Exemple

**Exemple 1:**  
**Input:** nums = [1,2,3,1]  
**Output:** 4  
**Explication:** Volez la maison 1 (money = 1), puis volez la maison 3 (money = 3).
Montant total que vous pouvez voler = 1 + 3 = 4.

**Exemple 2:**  
**Input:** nums = [2,7,9,3,1]  
**Output:** 12  
**Explication:** Volez la maison 1 (money = 2), puis volez la maison 3 (money = 9) et cambrioler la maison 5 (money = 1).
Montant total que vous pouvez voler = 2 + 9 + 1 = 12.

## Contraintes

`1 <= nums.length <= 100`  
`0 <= nums[i] <= 400`

## Note personnelle

Mon approche utilise la programmation dynamique pour résoudre le problème.
L'idée fondamentale consiste à sauvegarder, pour chaque case, le gain maximal accumulé depuis le début jusqu'à la `ième` maison.

Pour ce faire, j'ai initialisé un tableau `dp` de taille `nums.size()`.
J'ai attribué à `dp[0]` la valeur de `nums[0]` et à `dp[1]` la valeur maximale entre `nums[0]` et `nums[1]`.

Ensuite, j'ai parcouru chaque valeur de `nums` à partir de `nums[2]`.
À chaque itération, j'ai calculé le gain en utilisant les valeurs des deux maisons précédentes (`dp[i - 1]` et `dp[i - 2]`). J'ai ensuite attribué à `dp[i]` la valeur maximale entre `dp[i - 1]` et `dp[i - 2] + nums[i]`.

```cpp
int rob(vector<int>& nums) {
  // Vérifie s'il n'y a qu'une seule maison à cambrioler
  if(nums.size() == 1){
    // Dans ce cas, le gain maximal est simplement le butin de cette maison
    return nums[0];
  }

  // Initialisation d'un vecteur pour stocker les gains maximaux possibles
  vector<int> dp(nums.size());
  dp[0] = nums[0];
  dp[1] = max(nums[0], nums[1]);

  // Parcourt les maisons pour calculer les gains maximaux possibles
  for(int i = 2; i < nums.size(); i++){
    // Le gain maximal pour la i-ème maison est le maximum entre :
    // 1. Le gain maximal obtenu en cambriolant la (i-1)-ème maison
    // 2. Le gain maximal obtenu en cambriolant la (i-2)-ème maison et en ajoutant le butin de la i-ème maison
    dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
  }

  // Retourne le gain maximal obtenu après avoir cambriolé toutes les maisons
  return dp[nums.size() - 1];
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Une optimisation potentielle consiste à se passer du tableau `dp`. Étant donné que nous n'utilisons que les deux dernières valeurs calculées, nous pouvons simplement les stocker dans des variables. Cette optimisation réduit la complexité spatiale à `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
