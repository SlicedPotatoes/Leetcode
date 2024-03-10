// Structure de hachage pour une arête (réunion entre deux personnes)
template <> struct std::hash<std::vector<int>>
{
    size_t operator()(const std::vector<int> &n) const
    {
        size_t seed = 0;

        // Combinaison des éléments du vecteur pour générer un hash unique
        seed ^= std::hash<int>{}(min(n[0], n[1])) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<int>{}(max(n[0], n[1])) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        seed ^= std::hash<int>{}(n[2]) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

        return seed;
    }
};
class Solution
{
  public:
    vector<int> findAllPeople(int nb, vector<vector<int>> &meetings, int firstPerson)
    {
        // Trie du tableau meetings par ordre décroissant de time
        sort(meetings.begin(), meetings.end(),
             [](const std::vector<int> &a, const std::vector<int> &b) { return a[2] > b[2]; });

        // Création du graphe des réunions
        vector<vector<vector<int> *>> edges(nb);
        for (int i = 0; i < meetings.size(); i++)
        {
            edges[meetings[i][0]].push_back(&meetings[i]);
            edges[meetings[i][1]].push_back(&meetings[i]);
        }

        // Cartographie des personnes qui ont déjà eu connaissance du secret et le temps le plus bas auquel elles l'ont
        // appris
        unordered_map<int, int> personWhoKnow;

        // Initialisation de la liste des personnes connaissant le secret après toutes les réunions
        vector<int> output;

        // Initialisation de l'ensemble des arêtes déjà explorées
        unordered_set<vector<int> *> seen;

        // Création d'une arête de départ, nécessaire pour l'algorithme de parcours en profondeur
        vector<int> start = {0, firstPerson, 0};
        // Ajout de cette arête aux arêtes déjà explorées
        seen.insert(&start);

        // Parcours en profondeur (DFS)
        stack<vector<int> *> s;
        s.push(&start);
        while (!s.empty())
        {
            // Récupération et suppression de l'arête en haut de la pile
            vector<int> *current = s.top();
            s.pop();

            // Parcours des deux personnes liées par l'arête
            for (auto person : {(*current)[0], (*current)[1]})
            {
                // Si c'est la première fois que cette personne apprend le secret
                if (personWhoKnow.find(person) == personWhoKnow.end())
                {
                    // Ajout de cette personne à la liste des personnes connaissant le secret
                    output.push_back(person);
                    personWhoKnow[person] = INT_MAX;
                }
                // Si cette personne a déjà eu connaissance du secret mais que le temps actuel est >= au temps
                // précédent, on ignore
                if (personWhoKnow[person] <= (*current)[2])
                {
                    continue;
                }
                // Mise à jour du temps le plus bas auquel cette personne a eu connaissance du secret
                personWhoKnow[person] = (*current)[2];
                // Parcours des arêtes associées à cette personne
                for (const auto &n : edges[person])
                {
                    // Si le temps actuel est >= au temps associé à l'arête et que cette arête n'a pas déjà été explorée
                    if ((*n)[2] >= (*current)[2] && seen.count(n) == 0)
                    {
                        // Ajout de l'arête à la pile pour exploration ultérieure
                        s.push(n);
                        // Ajout de l'arête à l'ensemble des arêtes déjà explorées
                        seen.insert(n);
                    }
                    // Si le temps associé à l'arête est inférieur au temps actuel, on arrête de parcourir les arêtes de
                    // cette personne
                    if ((*n)[2] < (*current)[2])
                    {
                        break;
                    }
                }
            }
        }
        return output;
    }
};