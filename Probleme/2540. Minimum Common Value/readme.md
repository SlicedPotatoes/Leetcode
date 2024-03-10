# 2540. Minimum Common Value

## Énoncé

Étant donné deux tableaux d'entiers `nums1` et `nums2`, triés dans un ordre croissant, renvoie l'**entier minimum commun** aux deux tableaux. S'il n'y a pas d'entier commun entre `nums1` et `nums2`, renvoyez `-1`.

Notez qu'un entier est dit commun à `nums1` et `nums2` si les deux tableaux ont **au moins une** occurrence de cet entier.

## Exemple

**Exemple 1:**  
**Input:** nums1 = [1,2,3], nums2 = [2,4]  
**Output:** 2  
**Explication:** Le plus petit élément commun aux deux tableaux est 2, nous renvoyons donc 2.

**Exemple 2:**  
**Input:** nums1 = [1,2,3,6], nums2 = [2,3,4,5]  
**Output:** 2  
**Explication:** Il y a deux éléments communs dans les tableaux 2 et 3, dont 2 est le plus petit, donc 2 est renvoyé.

## Contraintes

`1 <= nums1.length, nums2.length <= 10^5`  
`1 <= nums1[i], nums2[j] <= 10^9`  
`nums1` et `nums2` sont triés dans un ordre **croissant**.

## Note personnelle

Pour résoudre ce problème, j'ai mis en place trois approches différentes, chacune avec son propre mode de fonctionnement. Je vais les présenter en commençant par la moins optimale et en terminant par la plus optimale.

La première approche utilise un ensemble non ordonné. Je parcours d'abord le premier tableau `nums1` et j'insère ses éléments dans l'ensemble. Ensuite, je parcours le tableau `nums2` et je vérifie si ses éléments se trouvent dans l'ensemble.

```cpp
int getCommon(vector<int>& nums1, vector<int>& nums2) {
  // Utilisation d'un ensemble non ordonné pour stocker les entiers de nums1
	unordered_set<int> seen;

  // Parcourir nums1 et ajouter chaque élément à l'ensemble 'seen'
	for(int n : nums1){
		seen.insert(n);
	}

  // Parcourir nums2 et vérifier si chaque élément est présent dans 'seen'
  // Si c'est le cas, retourner cet élément car il est commun aux deux vecteurs
	for(int n : nums2){
		if(seen.count(n) != 0){
			return n;
		}
	}

  // Si aucun élément commun n'est trouvé, retourner -1
	return -1;
}
```

Cette approche a une complexité temporelle de `O(n + m)` et une complexité spatiale de `O(n)`.

La deuxième approche exploite le fait que `nums1` et `nums2` sont trié.
sont triés. Je parcours les éléments de `nums1` et j'utilise une recherche dichotomique pour vérifier si je trouve le même élément dans `nums2`.

```cpp
// Fonction de recherche binaire pour trouver un élément dans un vecteur trié
bool binarySearch(int n, vector<int>& nums){
	int start = 0;
	int end = nums.size() - 1;

  // Tant que la fenêtre de recherche est valide
	while(start <= end){
    // Calculer l'indice du milieu de la fenêtre actuelle
		int mid = (start + end) / 2;

    // Si l'élément au milieu est l'élément recherché, retourner vrai
		if(nums[mid] == n){
			return true;
		}

    // Si l'élément recherché est plus grand que l'élément au milieu,
    // réduire la fenêtre de recherche à la moitié supérieure
		if(n > nums[mid]){
			start = mid + 1;
		}
    // Sinon, réduire la fenêtre de recherche à la moitié inférieure
		else{
			end = mid - 1;
		}
	}

  // Si l'élément n'est pas trouvé, retourner faux
	return false;
}

int getCommon(vector<int>& nums1, vector<int>& nums2) {
  // Parcourir chaque élément du premier vecteur
	for(int n : nums1){
    // Si l'élément est présent dans le deuxième vecteur, le retourner
		if(binarySearch(n, nums2)){
			return n;
		}
	}
  // Si aucun élément commun n'est trouvé, retourner -1
	return -1;
}
```

Cette approche a une complexité temporelle de `O(n * log(m))` et une complexité spatiale de `O(1)`.

La dernière approche utilise deux pointeurs `i` pour `nums1` et `j` pour `nums2`. Profitant du fait que les vecteurs sont triés, nous itérons simultanément sur les deux vecteurs, en incrémentant les indices en fonction des valeurs actuelles :

- Si `nums1[i] > nums2[j]`, nous incrémentons `j` de `1`.
- Sinon, nous incrémentons `i` de `1`.
- Si `nums1[i] == nums2[j]`, nous retournons la valeur correspondante.

Cette approche a une complexité temporelle de `O(n + m)` et une complexité spatiale de `O(1)`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
