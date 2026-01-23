class TreeNode {
    value: number;
    left: TreeNode | null;
    right: TreeNode | null;

    constructor(value: number) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}

function convertToFullBinaryTree(node: TreeNode | null): TreeNode | null {
    if (!node) return null;

    node.left = convertToFullBinaryTree(node.left);
    node.right = convertToFullBinaryTree(node.right);

    if (!node.left && !node.right) {
        return node;
    }

    if (!node.left && node.right) {
        return node.right;
    }

    if (node.left && !node.right) {
        return node.left;
    }

    return node;
}


const root = new TreeNode(0);
root.left = new TreeNode(1);
root.right = new TreeNode(2);
root.left.left = new TreeNode(3);
root.left.left.right = new TreeNode(5);
root.right.right = new TreeNode(4);
root.right.right.left = new TreeNode(6);
root.right.right.right = new TreeNode(7);

const fullTree = convertToFullBinaryTree(root);

console.log(JSON.stringify(fullTree, (key, value) => value, 2));