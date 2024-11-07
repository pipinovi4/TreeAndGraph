const Node = require("../Nodes/node");

class CompleteBinaryTree {
    constructor() {
        this.nodes = [];  // Array to store nodes in level-order, ensuring completeness
    }

    // Insert a new node in the complete binary tree
    insert(data) {
        const new_node = new Node(data);
        this.nodes.push(new_node);

        // Calculate the parent index based on the new node's position in the array
        const index = this.nodes.length - 1;
        if (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.nodes[parentIndex];

            // Assign the new node as the left or right child of its parent
            if (!parent.left) {
                parent.left = new_node;
            } else {
                parent.right = new_node;
            }
        }
    }

    // Search for a target value in the tree
    search(target) {
        for (const node of this.nodes) {
            if (node.data === target) {
                return true;
            }
        }
        return false;
    }

    // Print the tree in level-order
    printTree() {
        if (this.nodes.length === 0) return;

        const queue = [this.nodes[0]];  // Start with the root node
        const values = [];

        while (queue.length > 0) {
            const currentNode = queue.shift();
            if (currentNode) {
                values.push(currentNode.data);

                // Queue the left and right children if they exist
                if (currentNode.left !== null) queue.push(currentNode.left);
                if (currentNode.right !== null) queue.push(currentNode.right);
            }
        }

        console.log(values.join(" "));
    }
}

module.exports = CompleteBinaryTree;
