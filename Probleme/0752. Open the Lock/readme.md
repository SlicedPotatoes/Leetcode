# 752. Open the Lock

## Énoncé

Vous avez un cadenas devant vous avec 4 roues circulaires. Chaque roue a 10 emplacements: `'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'`. Les roues peuvent tourner librement et se réinitialiser: par exemple, nous pouvons tourner `'9'` pour qu'il devienne `'0'`, ou `'0'` pour qu'il devienne `'9'`. Chaque mouvement consiste à tourner une roue d'un cran.

Le cadenas démarre initialement à `'0000'`, une chaîne représentant l'état des 4 roues.

Vous disposez d'une liste de `deadends`, qui sont des impasses, ce qui signifie que si le cadenas affiche l'un de ces codes, les roues du cadenas cesseront de tourner et vous ne pourrez pas l'ouvrir.

Étant donné une `target` représentant la valeur des roues qui déverrouillera le cadenas, renvoyez le nombre total minimum de tours nécessaires pour ouvrir le cadenas, ou -1 s'il est impossible de le faire.

## Exemple

**Exemple 1:**  
**Input:** deadends = ["0201","0101","0102","1212","2002"], target = "0202"  
**Output:** 6  
**Explication:**  
Une séquence de mouvements valides serait "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202".  
Notez qu'une séquence comme "0000" -> "0001" -> "0002" -> "0102" -> "0202" serait invalide, car les roues de la serrure se coincent après que l'affichage soit devenu l'impasse "0102".

**Exemple 2:**  
**Input:** deadends = ["8888"], target = "0009"  
**Output:** 1  
**Explication:** On peut tourner la dernière roue en sens inverse pour passer de "0000" -> "0009".

**Exemple 3:**  
**Input:** deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"  
**Output:** -1  
**Explication:** Nous ne pouvons pas atteindre l’objectif sans rester bloqué.

## Contraintes

`1 <= deadends.length <= 500`  
`deadends[i].length == 4`  
`target.length == 4`  
la cible ne sera pas dans la liste des `deadends`.  
`target` et `deadends[i]` sont constitués uniquement de chiffres.

## Note personnelle

J'ai approché ce problème en le considérant comme une recherche de chemin dans un graphe. L'idée était de partir de la combinaison initiale (`'0000'`) et de trouver un chemin permettant d'atteindre `target` sans passer par les combinaisons figurant dans `deadends`.

J'ai adopté une approche utilisant un BFS (Breadth-First Search) et un ensemble pour stocker les combinaisons visitées.

Pour gérer le cas des `deadends`, je les ai simplement ajoutés à l'ensemble visité, ce qui permet d'éviter de les explorer pendant le parcours.

```cpp
int openLock(vector<string>& deadends, string target) {
  unordered_set<string> seen;

  // Ajouter les combinaisons interdites à l'ensemble
  for (string& s : deadends) {
    seen.insert(s);
  }

  // Vérifier si la combinaison initiale est interdite
  if(seen.contains("0000")){
    return -1;
  }

  // Marquer la combinaison initiale comme visitée
  seen.insert("0000");

  queue<string> q;
  // Ajouter la combinaison initiale à la file d'attente
  q.push("0000");

  // Initialiser la réponse
  int ans = 0;

  // Parcourir toutes les combinaisons possibles jusqu'à ce que la cible soit atteinte
  while (!q.empty()) {
    int size = q.size();
    for (int _ = 0; _ < size; _++) {
      string current = q.front();
      q.pop();

      if(current == target){
        // Retourner le nombre de mouvements nécessaires si la cible est atteinte
        return ans;
      }

      // Générer les combinaisons voisines en incrémentant et en décrémentant chaque chiffre
      for (int i = 0; i < 4; i++) {
        string next = current;
        string prev = current;

        next[i] = (current[i] + 1);
        prev[i] = current[i] - 1;

        // Gérer les dépassements de limite en ajustant les chiffres de 0 à 9
        if(next[i] > '9'){
          next[i] = '0';
        }
        else if (prev[i] < '0') {
          prev[i] = '9';
        }

        // Ajouter les combinaisons voisines à la file d'attente si elles ne sont pas encore visitées
        if (!seen.contains(next)) {
          q.push(next);
          seen.insert(next);
        }
        if (!seen.contains(prev)) {
          q.push(prev);
          seen.insert(prev);
        }
      }
    }
    // Incrémenter le nombre de mouvements après avoir exploré toutes les combinaisons à une distance donnée
    ans++;
  }

  // Retourner -1 si la cible n'est pas atteignable
  return -1;
}
```

Cette approche présente une complexité temporelle et spatiale de `O(10^L)` où `L` est la longueur du code (`4` dans ce cas).

Étant donné que le nombre de combinaisons possibles est relativement petit, nous pouvons nous permettre de remplacer l'ensemble par un vecteur de booléens de taille 10000 (qui représente le nombre de combinaisons possibles), ce qui réduit la mémoire utilisée lorsque nous parcourons 2500 combinaisons ou plus (une chaîne de 4 caractères de longueur en ASCII utilisera 4 octets, tandis qu'un booléen n'en utilisera qu'un seul. 2500 \* 4 = 10000, qui est la taille de notre vecteur).

Ce point de basculement se trouve à une profondeur de 5 dans l'arbre en théorie:

- Un nœud peut avoir au maximum 8 combinaisons voisines.
- 8^0 = 1; 8^1 = 8; 8^2 = 64; 8^3 = 512; 8^4 = 4096.

Cette méthode de calcul ne prend pas en compte les nœuds déjà visités qui ne se trouvent pas à la profondeur suivante. Le moyen le plus simple est de mettre un point d'arrêt dans notre programme lorsque le nombre de nœuds explorés dépasse 2500. D'après mes tests sur différentes entrées, ce point de basculement se produit à une profondeur moyenne de 9.

Cette approche ne réduit pas la complexité temporelle et spatiale du problème, mais elle réduit le coût engendré par l'ensemble et la mémoire consommée.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
