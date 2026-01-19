type Point = [number, number];

function getDistance(p1: Point, p2: Point): number {
    return Math.sqrt(Math.pow(p1[0] - p2[0], 2) + Math.pow(p1[1] - p2[1], 2))
}

function findClosestPoints(points: Point[]): [Point, Point] | null {
    if (points.length < 2) return null;

    let minDistance = Infinity;
    let closestPair: [Point, Point] = [points[0], points[1]];

    for (let i = 0; i < points.length; i++) {
        for (let j = i + 1; j < points.length; j++) {
            const distance = getDistance(points[i], points[j]);

            if (distance < minDistance) {
                minDistance = distance;
                closestPair = [points[i], points[j]];
            }
        }
    }

    return closestPair;
}

const points: Point[] = [
    [1, 1],
    [-1, -1],
    [3, 4],
    [6, 1],
    [-1, -6],
    [-4, -3]
];

const result = findClosestPoints(points);

console.log(result); // [[1, 1], [-1, -1]]