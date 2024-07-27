# Shortest Path

## Principe

Le **problème du plus court chemin** en algorithmie est un problème de théorie des graphes qui consiste à trouver un chemin entre deux sommets d'un graphe de manière à minimiser la somme des poids des arcs (ou des arêtes) de ce chemin.

### Algorithmes Courants

#### **Dijkstra**

- **Description**: Trouve le plus court chemin à partir d'un sommet source vers tous les autres sommets dans un graphe avec des poids d'arêtes non négatifs. Il est également possible de l'adapter pour trouver le plus court chemin entre un sommet source et une destination spécifique.
- **Contexte**: Graphes pondérés non négatifs.
- **Complexité Temporelle**: `O(E log V)`.

#### **Bellman-Ford**

- **Description**: Trouve le plus court chemin à partir d'un sommet source vers tous les autres sommets, même en présence de poids d'arêtes négatifs. Il peut détecter les cycles de poids négatifs.
- **Contexte**: Utilisé lorsqu'il est crucial de détecter des cycles de poids négatifs.
- **Complexité Temporelle**: `O(V * E)`.

#### **Floyd-Warshall**

- **Description**: Trouve les plus courts chemins entre toutes les paires de sommets dans un graphe. Il peut gérer les poids négatifs mais ne peut pas gérer les cycles de poids négatifs.
- **Contexte**: Adapté pour les graphes denses ou lorsqu'il est nécessaire de connaître les distances entre toutes les paires de sommets.
- **Complexité Temporelle**: `O(V^3)`.

#### **A-star**

- **Description**: Algorithme de recherche de chemin qui utilise une fonction de coût heuristique pour guider la recherche. Il est généralement utilisé pour trouver le plus court chemin dans des graphes avec des poids non négatifs, en se basant sur une estimation de la distance restante.
- **Contexte**: Graphes pondérés avec des poids non négatifs, performance accrue au détriment de la précision, souvent utilisé en IA pour les jeux vidéo et la robotique.
- **Complexité Temporelle**: Dépend fortement de la qualité de l'heuristique, en pratique il peut être très efficace.

### Facile

| Label | Tags | Date |
| ----- | ---- | ---- |

### Moyen

| Label                                                                                                     | Tags                                                                                                         | Date       |
| --------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------ | ---------- |
| [2976. Minimum Cost to Convert String I](../Probleme/2976.%20Minimum%20Cost%20to%20Convert%20String%20I/) | [`Array`](./array.md), [`String`](./string.md), [`Graph`](./graph.md), [`Shortest Path`](./shortest_path.md) | 27-07-2024 |

### Difficile

| Label | Tags | Date |
| ----- | ---- | ---- |
