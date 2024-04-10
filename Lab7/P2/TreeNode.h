#pragma once
template <typename T>
class TreeNode {
  public:
    T value;
    TreeNode<T>* parent;
    TreeNode<T>* children;
    TreeNode<T>* nextSibling;

    TreeNode(const T& val, TreeNode<T>* parentNode = nullptr);

    ~TreeNode();

    TreeNode<T>* add_node(const T& val);

    TreeNode<T>* get_node(TreeNode<T>* parentNode);

    void delete_node(TreeNode<T>* nodeToDelete);

    TreeNode<T>* find(bool (*compareFunc)(const T&, const T&), const T& valueToFind);

    TreeNode<T>* insert(TreeNode<T>* parentNode, const T& val, int index);

    void sort(bool (*compareFunc)(const T&, const T&) = nullptr);

    int count();
};