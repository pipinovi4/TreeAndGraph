class TreeNode {
    constructor(value) {
        this.value = value;
        this.children = [];
    }

    addChild(node) {
        this.children.push(node);
    }

    toString() {
        return `TreeNode(${this.value})`
    }
}

class TreeGraph {
    constructor(rootValue) {
        this.root = new TreeNode(rootValue);
    }

    addNode(parentValue, childValue) {
        let parentNode = this._findNode(this.root, parentValue);
        if (parentNode) {
            const childNode = new TreeNode(childValue);
            parentNode.addChild(childNode);
        } else {
            console.log(`Parent node with value ${parentNode.toString()} not found`)
        }
    }

    _findNode(currentNode, value) {
        const queue = [currentNode];

        while (queue.length !== 0) {
            currentNode = queue.shift();  // Use shift() to dequeue the first element
            if (currentNode.value === value) {
                return currentNode;
            }

            if (currentNode.children) {
                for (const child of currentNode.children) {
                    queue.push(child);  // Enqueue children to the back of the queue
                }
            }
        }

        return undefined;
    }

    traversalInOrder(node = undefined) {
        if (!node) {
            node = this.root;
        }

        const stack = [];
        let currentNode = node;

        while (currentNode || stack.length > 0) {
            // Traverse to the leftmost node
            while (currentNode) {
                stack.push(currentNode);
                currentNode = currentNode.children && currentNode.children.length > 0 ? currentNode.children[0] : undefined;
            }

            currentNode = stack.pop();

            if (currentNode) {
                process.stdout.write(currentNode.value + " ");  // Process the current node
            }

            // Move to the next child node (right)
            if (currentNode && currentNode.children && currentNode.children.length > 1) {
                currentNode = currentNode.children[1];  // Go to the second child (right in binary trees)
            } else {
                currentNode = undefined;  // No more nodes to traverse at this level
            }
        }

        process.stdout.write("\n");
    }

    traversalPreOrder(node=undefined) {
        if (!node) {
            node = this.root;
        }

        const queue = [node];

        while (queue.length !== 0) {
            let currentNode = queue.pop();

            if (currentNode) {
                process.stdout.write(currentNode.value + " ");

                if (currentNode.children.length !== 0) {
                    for (const child of currentNode.children) {
                        queue.push(child);
                    }
                }
            }
        }

        process.stdout.write("\n");
    }

    traversalPostOrder(node = undefined) {
        if (!node) {
            node = this.root;
        }

        const stack = [];
        const visited = new Set(); // Use a Set to track visited nodes

        stack.push(node);

        while (stack.length > 0) {
            const currentNode = stack[stack.length - 1]; // Peek at the top of the stack

            if (currentNode.children && !visited.has(currentNode)) {
                // Push children to the stack (in reverse order for correct post-order processing)
                for (let i = currentNode.children.length - 1; i >= 0; i--) {
                    stack.push(currentNode.children[i]);
                }
                visited.add(currentNode); // Mark the current node as visited
            } else {
                // Process the current node after all children
                process.stdout.write(currentNode.value + " ");
                stack.pop();
            }
        }

        process.stdout.write("\n");
    }

    display(node = undefined, level = 0) {
        const stack = [node || this.root]; // Use the root if no node is provided

        while (stack.length > 0) {  // Loop while the stack has elements
            let currentNode = stack.shift();  // Get the first element from the stack

            if (!currentNode) continue;  // Skip null or undefined nodes

            console.log(" ".repeat(level * 4) + `TreeNode(${currentNode.value})`);  // Indent based on the level

            if (currentNode.children) {
                for (const child of currentNode.children) {
                    stack.push(child);  // Add children to the stack
                }
            }
        }
    }
}

module.exports = TreeGraph;