# 724. Find Pivot Index

## Énoncé

Étant donné un tableau d'entiers `nums`, calculez l'**index pivot** de ce tableau.

L'**index pivot** est l'index où la somme de tous les nombres **strictement** à gauche de l'index est égale à la somme de tous les nombres **strictement** à droite de l'index.

Si l'index est sur le bord gauche du tableau, alors la somme de gauche est `0` car il n'y a aucun élément à gauche. Cela s'applique également au bord droit du tableau.

Renvoie l'**index pivot le plus à gauche**. Si aucun index de ce type n'existe, renvoyez `-1`.

Remarque : Cette question est la même que [1991](https://leetcode.com/problems/find-the-middle-index-in-array/)

## Exemple

**Example 1:**  
**Input:** nums = [1,7,3,6,5,6]  
**Output:** 3  
**Explication:**
L’indice pivot est 3.  
Somme de gauche = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11  
Somme de droite = nums[4] + nums[5] = 5 + 6 = 11

**Example 2:**  
**Input:** nums = [1,2,3]  
**Output:** -1  
**Explication:**  
Il n'existe aucun index qui satisfasse aux conditions de l'énoncé du problème.

**Example 3:**  
**Input:** nums = [2,1,-1]  
**Output:** 0  
**Explication:**  
L’indice pivot est 0.  
Somme de gauche = 0 (aucun élément à gauche de l'index 0)  
Somme de droite = nums[1] + nums[2] = 1 + -1 = 0

## Contraintes

`1 <= nums.length <= 10^4`  
`-1000 <= nums[i] <= 1000`

## Note personnelle

Dans ma première approche, j'ai opté pour la création de deux vecteurs, `prefix` et `suffix`, afin de représenter les sommes cumulées depuis le début et la fin du tableau respectivement.

Ensuite, j'ai cherché à trouver un indice où `prefix[i] == suffix[i]`, ce qui indiquerait le pivot.

```cpp
int pivotIndex(vector<int>& nums) {
  vector<int> prefix(nums.size());
  vector<int> suffix(nums.size());

  prefix[0] = nums[0];
  suffix[nums.size() - 1] = nums[nums.size() - 1];

  for(int i = 1, j = nums.size() - 1 - i; i < nums.size(); i++, j--){
    prefix[i] = nums[i] + prefix[i - 1];
    suffix[j] = nums[j] + suffix[j + 1];
  }

  for(int i = 0; i < prefix.size(); i++){
    if(prefix[i] == suffix[i]){
      return i;
    }
  }

  return -1;
}
```

Cependant, après avoir soumis cette solution, j'ai réalisé que j'utilisais plus de mémoire que nécessaire, me classant parmi les 10% les moins performants en termes d'utilisation de la mémoire.

J'ai donc décidé d'optimiser l'utilisation de la mémoire. Mon intuition m'a dirigé vers la conclusion que seul le tableau 'prefix' était nécessaire. En examinant de plus près ce tableau, j'ai remarqué que l'indice pivot devait respecter la condition suivante : `prefix[i] + prefix[i - 1] == prefix[prefix.size() - 1]`.

Cependant, cette approche introduit quelques cas spéciaux plus complexes à gérer par rapport à la première approche :

- Le premier cas à traiter survient lorsque le tableau a une taille de 1, dans ce cas, le pivot est simplement 0.

- Le deuxième cas concerne le pivot situé à l'index 0. J'ai trouvé un moyen de le détecter en vérifiant si le dernier élément de `prefix` a la même valeur que son premier élément. Puisque le pivot est exclu des calculs, la somme cumulée est 0 pour la partie droite, et comme il n'y a aucun élément à gauche, cela donne également 0.

- Le troisième cas intervient lorsque le pivot est sur le dernier index du tableau. Je le détecte en vérifiant si l'élément précédant est 0. Cette vérification est effectuée après la boucle, car l'énoncé demande à trouver le pivot le plus à gauche, et dans certains cas, un pivot peut être trouvé avant lui.

J'ai également économisé de la mémoire en stockant les sommes cumulées dans `nums`

Les deux solutions ont une complexité temporelle de 'O(n)' et une complexité spatiale de 'O(n)'. Cependant, la deuxième approche utilise moins de mémoire et évite la création de vecteurs, ce qui permet également de gagner un peu en temps d'exécution.

<img src="../imgs/0724-runtime.png"/>
<img src="../imgs/0724-memory.png"/>
