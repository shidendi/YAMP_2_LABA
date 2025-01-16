// ���������� ������� ������ Node.
#include "Node.h"
#include <iostream>

// ����������� ����, ����� ��� � �����.
Node::Node(const std::string& name, const Token& token)
    : name(name), token(token) {}

// ���������� ��������� ����.
void Node::addChild(std::shared_ptr<Node> child) {
    children.push_back(child);
}

// ��������� ����� ����.
const std::string& Node::getName() const {
    return name;
}

// ��������� ���������� ������.
const Token& Node::getToken() const {
    return token;
}

// ��������� �������� �����.
const std::vector<std::shared_ptr<Node>>& Node::getChildren() const {
    return children;
}

// ������ ������ � ������� � ���������.
void printTree(const std::shared_ptr<Node>& node, int indent) {
    for (int i = 0; i < indent; ++i)
        std::cout << "    ";
    std::cout << node->getName();
    if (node->getToken().type != END_OF_FILE) {
        std::cout << " [" << node->getToken().value << "]";
    }
    std::cout << std::endl;
    for (const auto& child : node->getChildren()) {
        printTree(child, indent + 1);
    }
}
