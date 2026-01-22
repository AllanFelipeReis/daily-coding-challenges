function isBipartite(graph: number[][]): boolean {
    const n = graph.length
    const colors = new Int8Array(n);

    for (let i = 0; i < n; i++) {
        if (colors[i] === 0) {
            const queue: number[] = [i];
            colors[i] = 1;

            while (queue.length > 0) {
                const u = queue.shift()!;

                for (const v of graph[u]) {
                    if (colors[v] === 0) {
                        colors[v] = -colors[u] as any;
                        queue.push(v)
                    } else if (colors[v] === colors[u]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

const graph1 = [[1, 3], [0, 2], [1, 3], [0, 2]];
console.log(isBipartite(graph1)); // true

const graph2 = [[1, 2, 3], [0, 2], [0, 1, 3], [0, 2]];
console.log(isBipartite(graph2)); // false