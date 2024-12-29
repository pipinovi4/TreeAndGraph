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
        const queue = [[currentNode]];

        while (queue.length !== 0) {
            currentNode = queue.unshift();
            if (currentNode.value === value) {
                return currentNode;
            }
            for (const child of currentNode.children) {
                queue.push(child);
            }
        }

        return undefined;
    }

    traversalInOrder(node=undefined) {
        if (!node) {
            node = this.root;
        }

        const queue = [];
        let current_node = node;

        while (current_node || queue) {
            while (current_node) {
                queue.push(current_node);
                current_node = current_node.children.length !== 0 ? current_node.children[0] : undefined;
            }

            current_node = queue.pop();
            process.stdout.write(current_node.value);

            if (current_node.children.length !== 0) {
                current_node = current_node.children > 1 ? current_node.children[1] : undefined;
            } else {
                current_node = undefined;
            }
        }
    }

    traversalPreOrder(node=undefined) {
        const queue = [[node]];

        while (queue.length !== 0) {
            let current_node = queue.shift();

            if (current_node) {
                process.stdout.write(current_node.value);

                for (const child of current_node.children) {
                    queue.push(child);
                }
            }
        }
    }

    traversalPostOrder(node=undefined) {
        if (!node) {
            node = this.root;
        }

        const stack = [];
        const visited = {};

        stack.push(node);

        while (stack) {
            const current_node = stack[stack.length - 1];
            if (current_node.children && (visited[current_node] ?? false)) {
                for (const child of current_node.children) {
                    stack.push(child);
                }
                visited.add(current_node);
            } else {
                process.stdout.write(current_node.value);
                stack.pop();
            }
        }
    }

    display(node=undefined, level =0) {
        if (!node) {
            node = this.root;
        }

        console.log(" " * level * 4 + `TreeNode(${node.value})`);
    }
}

module.exports = TreeGraph;