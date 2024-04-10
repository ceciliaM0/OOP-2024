#include <iostream>
#include "TreeNode.h"

bool compareInt(const int& a, const int& b) {
    return a > b;
}

int main() {
    TreeNode<int> root(10);
    TreeNode<int>* child1 = root.add_node(5);
    TreeNode<int>* child2 = root.add_node(15);
    TreeNode<int>* child3 = root.add_node(20);
    TreeNode<int>* grandchild1 = child1->add_node(3);
    TreeNode<int>* grandchild2 = child1->add_node(7);
    TreeNode<int>* grandchild3 = child3->add_node(25);

    std::cout << "Numar total fii ai arborelui " << root.count() << std::endl;

    root.sort(compareInt);
    std::cout << "Fii sortati ";
    TreeNode<int>* current = root.children;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->nextSibling;
    }
    std::cout << std::endl;

    TreeNode<int>* newChild = root.insert(&root, 8, 1);
    std::cout << "Inserted value: " << newChild->value << std::endl;
    std::cout << "Children values of the root node after insertion: ";
    current = root.children;
    while (current != nullptr) {
        std::cout << current->value << " ";
        current = current->nextSibling;
    }
    std::cout << std::endl;

    TreeNode<int>* foundNode = root.find([](const int& a, const int& b) { return a == b; }, 25);
    if (foundNode != nullptr) {
        std::cout << "Gasit nod cu valoarea " << foundNode->value << std::endl;
    } else {
        std::cout << "Nodul nu este gasit" << std::endl;
    }

    root.delete_node(child1);
    std::cout << "Nr total fii " << root.count() << std::endl;

    return 0;
}
