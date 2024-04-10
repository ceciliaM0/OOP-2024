#include "TreeNode.h"

template <typename T>
TreeNode<T>::TreeNode(const T& val, TreeNode<T>* parentNode)
    : value(val), parent(parentNode), children(nullptr), nextSibling(nullptr) {
}

template <typename T>
TreeNode<T>::~TreeNode() {
    TreeNode<T>* current = children;
    while (current != nullptr) {
        TreeNode<T>* next = current->nextSibling;
        delete current;
        current = next;
    }
}

template <typename T>
TreeNode<T>* TreeNode<T>::add_node(const T& val) {
    if (children == nullptr) {
        children = new TreeNode<T>(val, this);
        return children;
    }
    TreeNode<T>* current = children;
    while (current->nextSibling != nullptr) {
        current = current->nextSibling;
    }
    current->nextSibling = new TreeNode<T>(val, this);
    return current->nextSibling;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_node(TreeNode<T>* parentNode) {
    if (parentNode == nullptr) {
        return this;
    }
    TreeNode<T>* current = children;
    while (current != nullptr) {
        if (current->parent == parentNode) {
            return current;
        }
        current = current->nextSibling;
    }
    return nullptr;
}

template <typename T>
void TreeNode<T>::delete_node(TreeNode<T>* nodeToDelete) {
    if (nodeToDelete == nullptr) {
        return;
    }
    TreeNode<T>* current = nodeToDelete->children;
    while (current != nullptr) {
        TreeNode<T>* next = current->nextSibling;
        delete_node(current);
        current = next;
    }
    if (nodeToDelete->parent != nullptr) {
        TreeNode<T>* prev = nullptr;
        current = nodeToDelete->parent->children;
        while (current != nullptr) {
            if (current == nodeToDelete) {
                if (prev != nullptr) {
                    prev->nextSibling = current->nextSibling;
                } else {
                    nodeToDelete->parent->children = current->nextSibling;
                }
                delete nodeToDelete;
                break;
            }
            prev = current;
            current = current->nextSibling;
        }
    } else {
        delete nodeToDelete;
    }
}


template<typename T>
TreeNode<T>* TreeNode<T>::find(bool (*compareFunc)(const T&, const T&), const T& valueToFind) {
    if (compareFunc(value, valueToFind)) {
        return this;
    }
    TreeNode<T>* current = children;
    while (current != nullptr) {
        TreeNode<T>* found = current->find(compareFunc, valueToFind);
        if (found != nullptr) {
            return found;
        }
        current = current->nextSibling;
    }
    return nullptr;
}

template <typename T>
TreeNode<T>* TreeNode<T>::insert(TreeNode<T>* parentNode, const T& val, int index) {
    if (parentNode == nullptr || index < 0) {
        return nullptr;
    }

    // Se creează nodul nou
    TreeNode<T>* newNode = new TreeNode<T>(val, parentNode);
    if (parentNode->children == nullptr) {
        // Dacă părintele nu are niciun copil, nodul nou devine primul copil
        parentNode->children = newNode;
    } else {
        // Se găsește poziția pentru inserare
        TreeNode<T>* current = parentNode->children;
        int currentIndex = 0;
        while (current->nextSibling != nullptr && currentIndex < index) {
            current = current->nextSibling;
            currentIndex++;
        }
        // Se inserează nodul nou înaintea nodului curent
        newNode->nextSibling = current;
        if (current == parentNode->children) {
            parentNode->children = newNode;
        } else {
            // Se actualizează referința nodului anterior pentru a include nodul nou
            TreeNode<T>* prev = parentNode->children;
            while (prev->nextSibling != current) {
                prev = prev->nextSibling;
            }
            prev->nextSibling = newNode;
        }
    }
    return newNode;
}

template <typename T>
void TreeNode<T>::sort(bool (*compareFunc)(const T&, const T&)) {
    // Verificăm dacă părintele are copii
    if (children == nullptr) {
        return;
    }

    // Bubble sort pentru a sorta copiii
    bool swapped;
    TreeNode<T>* current;
    TreeNode<T>* prev = nullptr;

    do {
        swapped = false;
        current = children;

        while (current->nextSibling != nullptr) {
            if (compareFunc ? compareFunc(current->value, current->nextSibling->value)
                            : (current->value < current->nextSibling->value)) {
                // Schimbăm pozițiile nodurilor dacă sunt în ordine inversă
                if (prev != nullptr) {
                    prev->nextSibling = current->nextSibling;
                } else {
                    children = current->nextSibling;
                }
                current->nextSibling = current->nextSibling->nextSibling;
                prev = current->nextSibling;
                prev->nextSibling = current;
                swapped = true;
            } else {
                prev = current;
                current = current->nextSibling;
            }
        }
    } while (swapped);
}

template <typename T>
int TreeNode<T>::count() {
    // Verificăm dacă nodul este nullptr, caz în care numărăm toți copiii din arbore
    if (this == nullptr) {
        int totalCount = 0;
        TreeNode<T>* current = children;
        while (current != nullptr) {
            totalCount++;
            totalCount += current->count(); // Apelăm recursiv count pentru fiecare copil
            current = current->nextSibling;
        }
        return totalCount;
    } else {
        // Numărăm copiii nodului curent și apelăm recursiv count pentru fiecare copil
        int childCount = 0;
        TreeNode<T>* current = children;
        while (current != nullptr) {
            childCount++;
            childCount += current->count(); // Apelăm recursiv count pentru fiecare copil
            current = current->nextSibling;
        }
        return childCount;
    }
}


// Explicit instantiation for int
template class TreeNode<int>;
