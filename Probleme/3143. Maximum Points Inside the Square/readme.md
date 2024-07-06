# 3143. Maximum Points Inside the Square

## Énoncé

Vous disposez d'un tableau 2D `points` et d'une chaîne `s` où, `points[i]` représente les coordonnées du point `i`, et `s[i]` représente le **tag** du point `i`.

Un carré **valide** est un carré centré à l'origine `(0, 0)`, avec des côtés parallèles aux axes, et **ne contient pas** deux points ayant la même tag.

Retournez le nombre **maximum** de points contenus dans un carré **valide**.

Notes:

- Un point est considéré comme étant à l'intérieur du carré s'il se trouve sur les frontières du carré ou à l'intérieur de celles-ci.
- La longueur du côté du carré peut être nulle.

## Exemple

**Exemple 1:**

<img style="background: #ffffff; width: 303px; height: 303px" src="./imgs/img1.png"/>

**Input:** points = [[2,2],[-1,-2],[-4,4],[-3,1],[3,-3]], s = "abdca"  
**Output:** 2  
**Explication:** Le carré de côté 4 couvre deux points `points[0]` et `points[1]`.

**Exemple 2:**

<img style="background: #ffffff; width: 303px; height: 303px" src="./imgs/img2.png"/>

**Input:** points = [[1,1],[-2,-2],[-2,2]], s = "abb"  
**Output:** 1  
**Explication:** Le carré de côté 2 couvre un point, qui est `points[0]`.

**Exemple 3:**  
**Input:** points = [[1,1],[-1,-1],[2,-2]], s = "ccd"  
**Output:** 0  
**Explication:** Il est impossible de créer des carrés valides centrés à l'origine de telle sorte qu'ils ne couvrent qu'un seul point parmi les `points[0]` et les `points[1]`.

## Contraintes

`1 <= s.length, points.length <= 10^5`  
`points[i].length == 2`  
`-10^9 <= points[i][0], points[i][1] <= 10^9`  
`s.length == points.length`  
`points` consists of distinct coordinates.  
`s` consists only of lowercase English letters.

## Note personnelle

### Approche 1: Tri

Le principe de cette approche consiste à trier les points en fonction de leur distance maximale par rapport à l'origine des axes.

Une fois triés, nous parcourons les points pour calculer le plus grand carré valide et compter le nombre de points à l'intérieur.

```cpp
// Structure définissant un point avec des coordonnées entières (x, y) et un caractère associé.
struct Point{
    int y;
    int x;
    char s;
};
int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
  vector<Point> p;

  // Remplissage du vecteur de points en convertissant chaque paire de coordonnées et caractère en Point.
  for(int i = 0; i < points.size(); i++){
    p.push_back(Point(points[i][0], points[i][1], s[i]));
  }

  // Tri des points selon la distance maximale absolue de leurs coordonnées.
  sort(p.begin(), p.end(), [](Point &p1, Point &p2){
    int a = max(abs(p1.x), abs(p1.y));
    int b = max(abs(p2.x), abs(p2.y));

    return a < b;
  });

  // Utilisation d'un ensemble pour suivre les caractères déjà vus.
  unordered_set<char> see;
  int ans = 0;     // Nombre total de points dans le carré
  int curr = 0;    // Distance maximale courante parmi les points considérés
  int currAns = 0; // Nombre de points ayant la distance maximale courante

  // Parcours des points triés
  for(int i = 0; i < p.size(); i++){
    int a = max(abs(p[i].x), abs(p[i].y));

    // Si la distance maximale de ce point est plus grande que celle des points précédents
    if(a > curr){
      curr = a;       // Met à jour la distance maximale courante
      ans += currAns; // Ajoute le nombre de points à la réponse totale
      currAns = 0;    // Réinitialise le compteur pour la nouvelle distance maximale
    }

    // Si le caractère associé au point a déjà été vu, on arrête le calcul
    if(see.contains(p[i].s)){
      return ans;
    }

    see.insert(p[i].s); // Ajoute le caractère à l'ensemble des caractères vus
    currAns++;          // Incrémente le compteur de points pour la distance maximale courante
  }

  ans += currAns; // Ajoute les points restants à la réponse totale

  return ans; // Retourne le nombre maximal de points à l'intérieur du carré
}
```

- Complexité Temporelle: `O(n log n)`.
- Complexité Spatiale: `O(n)`.

### Approche 2: Limite par Tag

L'idée de cette approche est de trouver la distance maximale pour chaque tag, où cette distance maximale ne contient qu'un seul point avec le tag concerné.

Pour cela, on conserve pour chaque tag deux distances: la distance minimale et une seconde distance minimale telle que tout carré de taille inférieure à cette dernière contient exactement un point avec le tag.

Ensuite, on recherche la plus petite de ces distances minimales parmi tous les tags.

On compte le nombre de points où leurs distances sur un axe sont strictement inférieures à cette distance.

```cpp
int maxPointsInsideSquare(vector<vector<int>>& p, string s) {
  unordered_map<char, vector<int>> mp;

  // Parcours des points pour remplir la map avec les distances minimales par caractère.
  for(int i = 0; i < p.size(); i++){
    auto it = mp.find(s[i]);

    // Si le tag n'est pas déjà présent, l'ajouter avec des distances initiales.
    if(it == mp.end()){
      it = mp.insert({s[i], {INT_MAX, INT_MAX}}).first;
    }

    int d = max(abs(p[i][0]), abs(p[i][1]));

    // Mettre à jour les distances minimales et secondaires si nécessaire.
    if(it->second[0] > d){
      it->second[1] = it->second[0];
      it->second[0] = d;
    }
    else{
      it->second[1] = min(it->second[1], d);
    }
  }

  // Trouver la plus petite distance maximale parmi toutes les entrées dans la map.
  int m = INT_MAX;
  for(auto it = mp.begin(); it != mp.end(); it++){
    m = min(m, it->second[1]);
  }

  // Compter les points dont la distance maximale est inférieure à m.
  int ans = 0;
  for(vector<int> &point : p){
    if(max(abs(point[0]), abs(point[1])) < m){
      ans++;
    }
  }

  return ans;
}
```

- Complexité Temporelle: `O(n)`, où `n` est le nombre de points.
- Complexité Spatiale: `O(k)`, où `k` est le nombre de tags distincts.

### Optimisation de l'Approche 2 pour les Tags de `a` à `z`

Les contraintes de l'exercice précisent que les tags sont des caractères compris entre `a` et `z`, on peu donc remplacer la HashMap par un vecteur de taille 26 pour réduire le coût lié à la HashMap.

```cpp
int maxPointsInsideSquare(vector<vector<int>>& p, string s) {
  // Vecteur de paires pour stocker les distances minimales et la deuxième distance minimales par caractère ('a' à 'z').
  vector<pair<int, int>> mp(26, {INT_MAX, INT_MAX});

  // Parcours des points pour remplir le vecteur mp avec les distances minimales par caractère.
  for(int i = 0; i < p.size(); i++){
    int index = s[i] - 'a'; // Calcul de l'index correspondant au caractère
    int d = max(abs(p[i][0]), abs(p[i][1])); // Calcul de la distance maximale du point par rapport à l'origine.

    // Mettre à jour les distances minimales et secondaires si nécessaire.
    if(mp[index].first > d){
      mp[index].second = mp[index].first;
      mp[index].first = d;
    }
    else{
      mp[index].second = min(mp[index].second, d);
    }
  }

  // Trouver la plus petite distance maximale parmi toutes les entrées.
  int m = INT_MAX;
  for(int i = 0; i < 26; i++){
    m = min(m, mp[i].second);
  }

  // Compter les points dont la distance maximale est inférieure à m.
  int ans = 0;
  for(vector<int> &point : p){
    if(max(abs(point[0]), abs(point[1])) < m){
      ans++;
    }
  }

  return ans;
}
```

- Complexité Temporelle: `O(n)`.
- Complexité Spatiale: `O(1)`.

### Comparaison des Approches

- **Approche 1: Tri**: Cette approche est simple à comprendre et à implémenter, mais elle est moins performante que les autres approches en termes de temps d'exécution.
- **Approche 2: Limite par Tag**: C'est l'approche la plus polyvalente avec des performances supérieures à l'Approche 1 (Tri). Elle peut facilement être adaptée à différents types de tags.
- **Optimisation de l'Approche 2**: Cette optimisation est spécifiquement conçue pour le contexte précis de l'exercice, et elle est particulièrement efficace pour les tags qui sont des caractères compris entre `a` et `z`.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
