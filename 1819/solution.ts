type Edge = {
    to: string;
    weight: number;
}

type Tree = {
    [key: string]: Edge[];
}

function findLongestPath(tree: Tree): number {
    let maxPath = 0;

    function dfs(node: string, parent: string | null): number {
        let longest = 0;
        let secondLongest = 0;

        for (const edge of (tree[node] || [])) {
            if (edge.to === parent) continue;

            const currentDistance = dfs(edge.to, node) + edge.weight;

            if (currentDistance > longest) {
                secondLongest = longest;
                longest = currentDistance;
            } else if (currentDistance > secondLongest) {
                secondLongest = currentDistance;
            }
        }

        maxPath = Math.max(maxPath, longest + secondLongest);

        return longest;
    }

    const root = Object.keys(tree)[0];

    if (!root) return 0;

    dfs(root, null);

    return maxPath;
}

const tree: Tree = {
  'a': [{ to: 'b', weight: 3 }, { to: 'c', weight: 5 }, { to: 'd', weight: 8 }],
  'b': [{ to: 'a', weight: 3 }],
  'c': [{ to: 'a', weight: 5 }],
  'd': [{ to: 'a', weight: 8 }, { to: 'e', weight: 2 }, { to: 'f', weight: 4 }],
  'e': [{ to: 'd', weight: 2 }, { to: 'g', weight: 1 }, { to: 'h', weight: 1 }],
  'f': [{ to: 'd', weight: 4 }],
  'g': [{ to: 'e', weight: 1 }],
  'h': [{ to: 'e', weight: 1 }]
};

console.log("Comprimento do caminho mais longo:", findLongestPath(tree));