# 649. Dota2 Senate

## Énoncé

## Exemple

Dans le monde de Dota2, il y a deux factions : les Radiant et les Dire.

Le sénat de Dota2 se compose de sénateurs venant des deux factions. Maintenant, le Sénat souhaite décider d'un changement dans le jeu Dota2. Le vote pour ce changement est une procédure basée sur des tours. À chaque tour, chaque sénateur peut exercer **un** des deux droits suivants:

- **Interdire le droit d'un sénateur**: Un sénateur peut faire perdre à un autre sénateur tous ses droits dans ce tour et dans tous les tours suivants.
- **Annoncer la victoire**: Si ce sénateur trouve que les sénateurs qui ont encore des droits de vote appartiennent tous à la même faction, il peut annoncer la victoire et décider du changement dans le jeu.

Étant donné une chaîne `senate` représentant l'appartenance à la faction de chaque sénateur. Les caractères `'R'` et `'D'` représentent respectivement les factions Radiant et Dire. Ensuite, s'il y a `n` sénateurs, la taille de la chaîne donnée sera `n`.

La procédure basée sur les tours commence du premier sénateur au dernier sénateur dans l'ordre donné. Cette procédure durera jusqu'à la fin du vote. Tous les sénateurs qui ont perdu leurs droits seront ignorés pendant la procédure.

Supposez que chaque sénateur soit assez intelligent et joue la meilleure stratégie pour sa propre faction. Prédisez quelle faction annoncera finalement la victoire et changera le jeu Dota2. La sortie devrait être `"Radiant"` ou `"Dire"`.

**Exemple 1:**  
**Input:** senate = "RD"  
**Output:** "Radiant"  
**Explication:**  
Le premier sénateur vient de Radiant et il peut simplement interdire le droit du prochain sénateur au premier tour.
Le deuxième sénateur ne peut plus exercer aucun droit puisque son droit a été interdit.
Au deuxième tour, le premier sénateur peut simplement annoncer la victoire puisqu'il est le seul homme au Sénat qui peut voter.

**Exemple 2:**  
**Input:** senate = "RDD"  
**Output:** "Dire"  
**Explication:**  
Le premier sénateur vient de Radiant et il peut simplement interdire le droit du prochain sénateur.
Le deuxième sénateur ne peut plus exercer aucun droit puisque son droit a été interdit.
Le troisième sénateur vient de Dire et il peut interdire le droit du premier sénateur.
Au deuxième tour, le troisième sénateur peut simplement annoncer la victoire puisqu'il est le seul homme au Sénat qui peut voter.

## Contraintes

`n == senate.length`  
`1 <= n <= 10^4`  
`senate[i]` est `'R'` ou `'D'`.

## Note personnelle

Ma première approche pour aborder ce problème consiste à utiliser deux files, une pour chaque parti.

L'idée est de stocker la position de chaque membre dans l'ordre. Par exemple, si la chaîne d'entrée est `"RDD"`, alors la file Radiant contiendra `[0]` et la file Dire contiendra `[1,2]`.

Ensuite, on itère tant que les deux files contiennent des éléments. À chaque itération, je compare quel est l'élément le plus petit entre le premier élément des deux files.

L'élément le plus petit représente la personne qui va voter pour ce tour.

Je rajoute cet élément à la fin de la liste à laquelle il appartient pour maintenir l'ordre de comparaison, en ajoutant à sa valeur la taille du sénat.

Ensuite, je supprime le premier élément de chaque liste.

```cpp
string predictPartyVictory(string &senate) {
  queue<int> r; // File d'attente pour les sénateurs du parti "Radiant"
  queue<int> d; // File d'attente pour les sénateurs du parti "Dire"

  // Parcours de la chaîne de caractères "senate"
  for(int i = 0; i < senate.size(); i++){
    if(senate[i] == 'R'){
      // Ajout de l'index du sénateur du parti "Radiant" à la file d'attente "r"
      r.push(i);
    }
    else{
      // Ajout de l'index du sénateur du parti "Dire" à la file d'attente "d"
      d.push(i);
    }
  }

  // Tant qu'il reste des sénateurs des deux partis dans les files d'attente
  while(!r.empty() && !d.empty()){
    // Vérification si le sénateur "Radiant" a un indice plus petit que le sénateur "Dire"
    bool isR = r.front() < d.front();

    // Si le sénateur "Radiant" a un indice plus petit que le sénateur "Dire"
    if(isR){
      // Ajout de l'index du sénateur "Radiant" à la fin de la file d'attente "r" avec un décalage de la taille du sénat
      r.push(r.front() + senate.size());
    }
    else{
      // Sinon, ajout de l'index du sénateur "Dire" à la fin de la file d'attente "d" avec un décalage de la taille du sénat
      d.push(d.front() + senate.size());
    }

    // Suppression du sénateur qui a perdu ses droits et du sénateur qui est passé a la fin de la file.
    d.pop();
    r.pop();
  }

  // Si la file d'attente "r" est vide, cela signifie que le parti "Dire" a gagné, sinon le parti "Radiant" a gagné
  return r.empty() ? "Dire" : "Radiant";
}
```

Cette approche présente une complexité temporelle et spatiale de `O(n)`.

Une autre approche nécessite une seule file et quatre variables.

Dans la file, nous ajoutons les caractères correspondants aux parties dans l'ordre de passage. On maintient également quatre variables:

- `CountR`, représentant le nombre de personnes du parti "Radiant" qui ont toujours un droit de vote.
- `CountD`, représentant le nombre de personnes du parti "Dire" qui ont toujours un droit de vote.
- `SkipR`, représentant le nombre de personnes du parti "Radiant" que l'on doit ignorer.
- `SkipD`, représentant le nombre de personnes du parti "Dire" que l'on doit ignorer.

On itère sur la file tant que `countR` et `countD` sont supérieurs à `0`.

À chaque itération, on effectue les actions suivantes:

- On récupère et supprime le premier élément de la file.
- On vérifie si on doit ignorer ce sénateur. Si c'est le cas, on décrémente `SkipX` et `countX` en fonction de son parti.
- Sinon, on incrémente `SkipX` du parti opposé et on rajoute à la file ce même sénateur.

Cette approche présente la même complexité temporelle et spatiale que la précédente.

En conclusion, les deux approches présentent la même complexité temporelle et spatiale.

La première approche a l'avantage d'être plus concise et compréhensible que la seconde, donc plus facilement maintenable.

La seconde approche a l'avantage d'utiliser qu'une seule file et celle-ci stocke des caractères au lieu d'entiers. Un caractère utilise 1 octet de mémoire tandis qu'un int en utilise 4. Elle consommera légèrement moins de mémoire en contrepartie du fait qu'elle soit moins concise.

<img src="./imgs/runtime.png"/>
<img src="./imgs/memory.png"/>
