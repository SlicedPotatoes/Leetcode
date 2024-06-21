# 1052. Grumpy Bookstore Owner

## Énoncé

Il y a un propriétaire de librairie qui a un magasin ouvert pendant `n` minutes. Chaque minute, un certain nombre de clients entrent dans le magasin. On vous donne un tableau d'entiers `customers` de longueur `n` où `customers[i]` est le nombre de clients qui entrent dans le magasin au début de la `ième` minute et tous ces clients quittent après la fin de cette minute.

À certaines minutes, le propriétaire de la librairie est de mauvaise humeur. On vous donne un tableau binaire `grumpy` où `grumpy[i]` est `1` si le propriétaire de la librairie est de mauvaise humeur pendant la `ième` minute, et est `0` sinon.

Lorsque le propriétaire de la librairie est de mauvaise humeur, les clients de cette minute ne sont pas satisfaits, sinon, ils sont satisfaits.

Le propriétaire de la librairie connaît une technique secrète pour ne pas être de mauvaise humeur pendant `minutes` minutes consécutives, mais il ne peut l'utiliser qu'une seule fois.

Retournez le nombre maximum de clients qui peuvent être satisfaits tout au long de la journée.

## Exemple

**Exemple 1:**  
**Input:** customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3  
**Output:** 16  
**Explication:** Le propriétaire de la librairie reste de bonne humeur pendant les 3 dernières minutes.
Le nombre maximum de clients qui peuvent être satisfaits = 1 + 1 + 1 + 1 + 7 + 5 = 16.

**Exemple 2:**  
**Input:** customers = [1], grumpy = [0], minutes = 1  
**Output:** 1

## Contraintes

`n == customers.length == grumpy.length`  
`1 <= minutes <= n <= 2 * 10^4`  
`0 <= customers[i] <= 1000`  
`grumpy[i]` vaut `0` ou `1`.

## Note personnelle

Pour résoudre ce problème, je commence par calculer le nombre de clients satisfaits lorsque le propriétaire est de bonne humeur, sans utiliser sa technique, et je stocke cette valeur dans une variable `total`.

Ensuite, j'utilise la technique de la fenêtre glissante, de taille `minutes`. Au cours de ce parcours, je garde une trace du nombre de clients potentiellement satisfaits dans la variable `curr`. Je mets également à jour la valeur maximale de satisfaction possible en additionnant `total` et `curr`.

```cpp
int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
  int total = 0;

  // Calculer le nombre total de clients satisfaits sans tenir compte des périodes de mauvaise humeur
  for (int i = 0; i < customers.size(); i++) {
    if (!grumpy[i]) {
      total += customers[i];
    }
  }

  int curr = 0;

  // Calculer le nombre de clients potentiellement récupérables dans la première fenêtre de 'minutes' minutes
  for (int right = 0; right < minutes; right++) {
    if (grumpy[right]) {
      curr += customers[right];
    }
  }

  int ans = total + curr;
  int left = 0;

  // Utiliser une fenêtre glissante pour trouver la fenêtre de 'minutes' minutes maximisant le nombre de clients satisfaits
  for (int right = minutes; right < customers.size(); right++, left++) {
    if (grumpy[left]) {
      curr -= customers[left]; // Retirer les clients de la fenêtre sortante
    }
    if (grumpy[right]) {
      curr += customers[right];      // Ajouter les clients de la nouvelle fenêtre entrante
      ans = max(ans, total + curr);  // Mettre à jour la réponse avec le maximum trouvé
    }
  }

  // Retourner le total des clients satisfaits plus la meilleure récupération trouvée
  return ans;
}
```

Cette approche présente une complexité temporelle de `O(n)` et une complexité spatiale de `O(1)`.

Une optimisation de cette approche consiste à calculer `total`, directement dans la fenêtre glissante. Nous remplaçons également `ans` par `best`, qui devient la valeur maximale de clients "récupérés". De cette façon, nous évitons une itération supplémentaire pour calculer `total` et une addition à chaque mise à jour de `ans`, cette addition étant effectuée à la fin lors du retour de la réponse.

```cpp
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
  int total = 0; // Total des clients satisfaits sans tenir compte des périodes de mauvaise humeur
  int curr = 0; // Nombre de clients potentiellement récupérables dans la fenêtre actuelle

  // Calculer le total des clients satisfaits et les clients potentiellement récupérables dans la première fenêtre de 'minutes' minutes
  for(int right = 0; right < minutes; right++){
    if(grumpy[right]){
      curr += customers[right];
    }
    else{
      total += customers[right];
    }
  }

  int best = curr; // Initialiser la meilleure récupération avec la première fenêtre
  int left = 0;

  // Utiliser une fenêtre glissante pour maximiser le nombre de clients satisfaits
  for(int right = minutes; right < customers.size(); right++, left++){
    if(grumpy[left]){
      curr -= customers[left]; // Retirer les clients de la fenêtre sortante
    }
    if(grumpy[right]){
      curr += customers[right]; // Ajouter les clients de la nouvelle fenêtre entrante
      best = max(best, curr); // Mettre à jour la meilleure récupération si nécessaire
    }
    else{
      total += customers[right]; // Ajouter les clients satisfaits sans tenir compte des périodes de mauvaise humeur
    }
  }

  // Retourner le total des clients satisfaits plus la meilleure récupération trouvée
  return total + best;
}
```

Cette optimisation conserve la même complexité temporelle et spatiale que l'approche initiale.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
