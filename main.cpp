#include <iostream>
#include <string>

using namespace std;

class Squirrel {
private:
    string name;

public:
    Squirrel(string name) : name(name) {}

    string get_name() {
        return name;
    }
};

class Node {
private:
    Squirrel* data;
    Node* left_child;
    Node* right_child;

public:
    Node(Squirrel* squirrel) : data(squirrel), left_child(nullptr), right_child(nullptr) {}

    void set_left(Node* node) {
        left_child = node;
    }
    void set_right(Node* node) {
        right_child = node;
    }

    Node* left() {
        return left_child;
    }

    Node* right() {
        return right_child;
    }

    Squirrel* get_data() {
        return data;
    }
};


int main() {
    Squirrel cheeks("Cheeks");
    Squirrel squeaks("Squeaks");
    Squirrel fluffybutt("Mr. Fluffy Butt");

    Node node_one(&cheeks);
    Node node_two(&squeaks);
    Node node_three(&fluffybutt);

    node_one.set_left(&node_two);
    node_one.set_right(&node_three);

    Node* left_node = node_one.left();
    if (left_node) {
        cout << "Left child: " << left_node->get_data()->get_name() << endl;
    }

    Node* right_node = node_one.right();
    if (right_node) {
        cout << "Right child: " << right_node->get_data()->get_name() << endl;
    }

    return 0;
}
