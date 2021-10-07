#include <iostream>

using namespace std;

template <class T> class Node {
    public:
        T data; // The object information
        int key; // key of the value
        Node<T>* left; // Pointer to the left node element
        Node<T>* right; // Pointer to the right node element
        
        Node(T new_data, int key, Node<T>* left, Node<T>* right){
            this->data = new_data;
            this->key = key;
            this->left = left;
            this->right = right;
        }

        Node(T new_data, int key){
            this->data = new_data;
            this->key = key;
            this->left = NULL;
            this->right = NULL;
        }
};

template <class T> class BinarySearchTree{
    public:
        Node<T> *root;
        
        BinarySearchTree(){
            this->root = NULL;
        }

        ~BinarySearchTree(){

        }

        void inorder(Node<T>* current_node){
            if(current_node) {
                inorder(current_node->left);
                cout << current_node->key << " ";
                inorder(current_node->right);
            }

            if(this->root == current_node){
                cout << endl;
            }
        }

        void insert(Node<T> * current_node, Node<T> *node_insert){
            // Go to the next node according to the rules;
            Node<T> * next_node = current_node->left;
            bool is_left = true;            
            if(node_insert->key > current_node->key){
                next_node = current_node->right;
                is_left = false;
            }

            if(next_node){
                // If exist the next node then, we go for the next
                this->insert(next_node, node_insert);
            }
            else if(is_left){
                // If the node doesn't exist and the node is in the left then we insert in the left side
                current_node->left = node_insert;
            }
            else{
                // If the node doesn't exist and the node is in the left then we insert in the left side
                current_node->right = node_insert;
            }
        }

        void insert(T data, int key){
            Node<T> *node_insert = new Node<T>(data, key);
            if (this->root){
                this->insert(this->root, node_insert);
            }
            else{
                // Insert the first node, if root is NULL.
                this->root = node_insert;
            }
            
        }
        Node<T>* search(Node<T>* current_node, int key_searched){
            if(!current_node || key_searched == current_node->key){
                return current_node;
            }

            if(key_searched < current_node->key){
                return search(current_node->left, key_searched);
            }
            return search(current_node->right, key_searched);
        }

        Node<T>* search(int key_searched){
            return this->search(this->root, key_searched);
        }

        Node<T>* minimum_element(Node<T>* current_node){
            if(!current_node->left){
                return current_node;
            }
            return minimum_element(current_node->left);
        }

        Node<T>* delete_node(Node<T>* current_node, int key_delete){
            if(!current_node) return NULL;
            // First search for the element to delete
            else if(key_delete < current_node->key){
                current_node->left = this->delete_node(current_node->left, key_delete);
            }
            else if(key_delete > current_node->key){
                current_node->right = this->delete_node(current_node->right, key_delete);
            }
            else{
                if(!current_node->left &&!current_node->right){
                    // If the node is a leaf we just delete it
                    delete current_node;
                    current_node = NULL;
                }
                else if(!current_node->left){
                    // If the node doesn't have left node, 
                    // then just replace the current node with the right root
                    Node<T> * right_node = current_node->right;
                    delete current_node;
                    current_node = right_node;
                }
                else if(!current_node->right){
                    // If the node doesn't have right node, 
                    // then just replace the current node with the left root
                    Node<T> * left_node = current_node->left;
                    delete current_node;
                    current_node = left_node;   
                }
                else{
                    // If the node to delete has both nodes
                    // We search the minimum element in the right side
                    Node<T>* successor  = this->minimum_element(current_node->right);
                    // Replace the data with the minimum element (also the key)
                    Node<T>* new_node_minimum = new Node<T>(
                        successor ->data, successor->key, 
                        current_node->left, current_node->right);

                    if(current_node == this->root){
                        this->root = new_node_minimum;
                    }

                    // Delete the current node
                    delete current_node;

                    // Now we recursively delete the minimum element in the right subtree
                    current_node = new_node_minimum;
                    current_node->right = this->delete_node(current_node->right, successor->key);
                }
            }
            return current_node;       
        }

        Node<T>* delete_node(int key_delete){
            return this->delete_node(this->root, key_delete);
        }

};


int main(){
    BinarySearchTree<char> bst;
    
    bst.insert('h', 50);
    bst.insert('o', 30);
    bst.insert('l', 20);
    bst.insert('a', 40);
    bst.insert('h', 70);
    bst.insert('o', 60);
    bst.insert('l', 80);

    bst.inorder(bst.root);
    
    bst.delete_node(50);
    

    cout << endl;
    bst.inorder(bst.root);


    bst.delete_node(70);
    cout << endl;
    bst.inorder(bst.root);


    bst.delete_node(20);
    cout << endl;
    bst.inorder(bst.root);

    return 0;
}