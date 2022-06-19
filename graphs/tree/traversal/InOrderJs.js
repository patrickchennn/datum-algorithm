class Node{
    constructor(inputData){
        this.left = null;
        this.data = inputData;
        this.right = null;
    }
}

function inOrder(currNode){
    if(currNode==null)
        return;

    inOrder(currNode.left);
    process.stdout.write(`${currNode.data} `);

    inOrder(currNode.right);
    return;
}

function main(){
    // trees 2
    // inOrder ouput: 1 6 7 8 9 10 11 14 20 22
    root = new Node(10);
    // left child
    root.left = new Node(7);
    root.left.left = new Node(6);
    root.left.left.left = new Node(1);

    root.left.right = new Node(8);
    root.left.right.right = new Node(9);

    // right child
    root.right = new Node(11);
    root.right.right = new Node(20);
    root.right.right.right = new Node(22);
    root.right.right.left = new Node(14);

    inOrder(root);
    console.log();
}

main();
/*
https://stackoverflow.com/questions/6157497/node-js-printing-to-console-without-a-trailing-newline
*/