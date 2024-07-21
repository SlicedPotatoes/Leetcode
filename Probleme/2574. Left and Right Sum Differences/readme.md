# 2574. Left and Right Sum Differences

## Énoncé

Étant donné un tableau d'entiers **indexé à 0** `nums`, trouvez un tableau d'entiers **indexé à 0** `answer` où:

- `answer.length == nums.length`.
- `answer[i] = |leftSum[i] - rightSum[i]|`.

- `leftSum[i]` est la somme des éléments à gauche de l'indice `i` dans le tableau `nums`. S'il n'y a pas un tel élément, `leftSum[i] = 0`.
- `rightSum[i]` est la somme des éléments à droite de l'indice `i` dans le tableau `nums`. S'il n'y a pas un tel élément, `rightSum[i] = 0`.

Retournez le tableau `answer`.

## Exemple

**Exemple 1:**  
**Input:** nums = [10,4,8,3]  
**Output:** [15,1,11,22]  
**Explication:** Le tableau leftSum est [0,10,14,22] et le tableau rightSum est [15,11,3,0].
Le tableau answer est [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].

**Exemple 2:**  
**Input:** nums = [1]  
**Output:** [0]  
**Explication:** Le tableau leftSum est [0] et le tableau rightSum est [0].
Le tableau answer est [|0 - 0|] = [0].

## Contraintes

`1 <= nums.length <= 1000`  
`1 <= nums[i] <= 10^5`

## Note personnelle

### Approche 1

Dans cette approche, nous créons les tableaux `leftSum` et `rightSum` comme décrit dans l'énoncé.

```cpp
vector<int> leftRightDifference(vector<int>& nums) {
  int n = nums.size();

  // Vecteurs pour stocker les sommes cumulatives de gauche et de droite
  vector<int> leftSum(n, 0);
  vector<int> rightSum(n, 0);

  // Calcul des sommes cumulatives à gauche et à droite
  for(int i = 1; i < n; i++){
    leftSum[i] = leftSum[i - 1] + nums[i - 1];
    rightSum[n - i - 1] = rightSum[n - i] + nums[n - i];
  }

   // Vecteur pour stocker les résultats finaux
  vector<int> ans(n);

  // Calcul de la différence absolue entre les sommes à gauche et à droite
  for(int i = 0; i < n; i++){
    ans[i] = abs(leftSum[i] - rightSum[i]);
  }

  return ans;
}
```

- Complexité Temporelle `O(n)`
- Complexité Spatiale `O(n)`

## Approche 2

Cette approche optimise la précédente en remplaçant les tableaux par des variables entières. Les sommes à gauche et à droite sont calculées directement pendant la création du vecteur de résultats.

```cpp
vector<int> leftRightDifference(vector<int>& nums) {
  int leftSum = 0;  // Somme des éléments à gauche de l'élément actuel
  int rightSum = 0; // Somme des éléments à droite de l'élément actuel

  // Calcul de la somme totale des éléments du vecteur
  for(int n : nums){
    rightSum += n;
  }

  // Itération pour calculer les différences
  for(int i = 0; i < nums.size(); i++){
    int temp = nums[i]; // Stocke l'élément actuel

    // Met à jour rightSum en retirant l'élément actuel
    rightSum -= temp;

    // Calcul de la différence absolue
    nums[i] = abs(leftSum - rightSum);

    // Met à jour leftSum en ajoutant l'élément actuel
    leftSum += temp;
  }

  return nums; // Retourne le vecteur avec les différences absolues
}
```

- Complexité Temporelle `O(n)`
- Complexité Spatiale `O(1)`

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
