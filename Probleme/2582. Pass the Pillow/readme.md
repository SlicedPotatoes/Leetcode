# 2582. Pass the Pillow

## Énoncé

Il y a `n` personnes debout en ligne, numérotées de `1` à `n`. La première personne dans la ligne tient un coussin au départ. Chaque seconde, la personne tenant le coussin le passe à la personne suivante dans la ligne. Une fois que le coussin atteint la fin de la ligne, la direction change, et les gens continuent de se passer le coussin dans la direction opposée.

Par exemple, une fois que le coussin atteint la `nième` personne, celle-ci le passe à la `n - 1ème` personne, puis à la `n - 2ème` personne, et ainsi de suite.

Étant donné les deux entiers positifs `n` et `time`, retournez l'indice de la personne tenant le coussin après `time` secondes.

## Exemple

**Exemple 1:**  
**Input:** n = 4, time = 5  
**Output:** 2  
**Explication:** Les gens se passent l'oreiller de la manière suivante: 1 -> 2 -> 3 -> 4 -> 3 -> 2.
Après 5 secondes, la 2nd personne tient l'oreiller.

**Exemple 2:**  
**Input:** n = 3, time = 2  
**Output:** 3  
**Explication:** Les gens se passent l'oreiller de la manière suivante: 1 -> 2 -> 3.
Après 2 secondes, la 3eme personne tient l'oreiller.

## Contraintes

`2 <= n <= 1000`  
`1 <= time <= 1000`

## Note personnelle

### Approche 1: Simulation

Cette approche vise à simuler les déplacements de l'oreiller pour déterminer qui le possédera à la fin.

```cpp
int passThePillow(int n, int time) {
  int curr = 1;  // Position actuelle de l'oreiller.
  int d = 1;     // Direction de passage de l'oreiller: 1 pour droite, -1 pour gauche.

  for(int i = 0; i < time; i++){
    curr += d; // Déplacer l'oreiller dans la direction actuelle.

    // Changer la direction si l'oreiller atteint les extrémités.
    if(curr == n){
      d = -1;
    }
    else if(curr == 1){
      d = 1;
    }
  }

  return curr; // Position finale de l'oreiller.
}
```

- Complexité Temporelle: `O(time)`.
- Complexité Spatiale: `O(1)`.

### Optimisation Approche 1

Cette optimisation réduit le nombre d'itérations en calculant les cycles complets de passage de l'oreiller.

```cpp
int passThePillow(int n, int time) {
  int count = 0; // Nombre de cycles complets de passage d'oreiller.

  // Compter le nombre de cycles, tout en calculant le temps restant pour le dernier cycle incomplet.
  while(time >= n){
    time -= (n - 1);
    count++;
  }

  if(count % 2 == 0){
    return time + 1; // Position après le temps restant.
  }
  else{
    return n - time; // Position après le temps restant en sens inverse.
  }
}
```

- Complexité Temporelle: `O(time / n)`.
- Complexité Spatiale: `O(1)`.

### Approche 2: Mathématique

Cette approche optimise davantage en utilisant des calculs mathématiques pour déterminer la position finale de l'oreiller.

```cpp
int passThePillow(int n, int time) {
  int count = time / (n - 1); // Nombre de cycles complets de passage d'oreiller.
  time %= (n - 1); // Temps restant après les cycles complets.

  if(count % 2 == 0){
    return time + 1; // Position après le temps restant.
  }
  else{
    return n - time; // Position après le temps restant en sens inverse.
  }
}
```

- Complexité Temporelle: `O(1)`.
- Complexité Spatiale: `O(1)`.

### Comparaison des différentes approches

- **Approche 1: Simulation**: Simple à comprendre et à implémenter, mais moins optimale pour de grandes valeurs de `time`.
- **Optimisation Approche 1**: Gère efficacement de grandes valeurs de `time` lorsque `n` également élevé.
- **Approche 2: Mathématique**: La plus optimale des trois, avec une complexité constante indépendamment de `time` et `n`, adaptée à diverses situations.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
