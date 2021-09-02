#include <iostream>

using namespace std;

template <class T> class Node {
    private:
        T data; // The object information
        Node* next; // Pointer to the next node element

    public:
        Node(T new_data, Node* next_node){
            this->data = new_data;
            this->next = next_node;
        }

        Node(T new_data){
            this->data = new_data;
            this->next = NULL;
        }

        void set_data(T new_data){
            this->data = new_data;
        }

        T get_data(){
            return this->data;
        }

        void set_next(Node *next_node){
            this->next = next_node;
        }

        Node* get_next(){
            return this->next;
        }
};


template <class T> class CustomLinkedList{
    Node<T> *head;

    public:
        CustomLinkedList(){
            head = NULL;
        }

        ~CustomLinkedList(){

        }

        // Method adds data to the end of the list
        void add_end(T data){
            if(head == NULL){ //if our list is currently empty
                head = new Node<T>(data); //Create new node of type T
            }
            else{ //if not empty add to the end and move the tail
                Node<T>* temp = new Node<T>(data);
                
                Node<T>* current_node = this->head;
                while (current_node->get_next() != NULL){
                    current_node = current_node->get_next();
                }
                
                current_node->set_next(temp);
            }
        }

        // Method adds data to the begining of the list
        void add_begin(T data){
            Node<T>* temp = new Node<T>(data, head);
            
            this->head = temp;
        }

        // Method adds info to the begining of the list
        void add_after_node(T value_insert, T value_target){
            Node<T>* current_node = this->head;
            // Search for the node to delete
            while(current_node && current_node->get_data() != value_target){
                current_node = current_node->get_next();
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }

            Node<T>* node_insert = new Node<T>(value_insert, current_node->get_next());
            
            current_node->set_next(node_insert);
        }


        void delete_node(T value){
            if(!this->head){
                // Empty linked list, no values to delete
                return;
            }
            
            // Check if the node to delete is the head
            if(this->head->data == value){
                this->head = this->head->get_next();
                return;
            }

            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node && current_node->next->get_data() != value){
                current_node = current_node->get_next();
            }

            // current node is empty the node wasn't found 
            if(!current_node){
                return;
            }

            Node<T>* node_to_delete = current_node->get_next(), next_node = node_to_delete->get_next();

            current_node->set_next(next_node);
            delete node_to_delete;
        }

        Node<T>* search_node(T value_target){
            Node<T>* current_node = this->head;
            // Search for the node to delete
            while ( current_node){
                if(current_node->get_data() == value_target){
                    return current_node;
                }
                current_node = current_node->get_next();
            }

            return NULL;
        }

        void print_list(){
            Node<T>* current_node = this->head;
            while (current_node != NULL){
                cout << current_node->get_data() << " -> ";

                current_node = current_node->get_next();
            }
            cout << endl;
        }

        
};



int main(){
    CustomLinkedList<int> firstList;

    firstList.add_end(32);
    //Pause the program until input is received
    
    firstList.add_end(33);
    firstList.add_end(34);
    firstList.print_list();

    firstList.add_after_node(10, 33);
    firstList.print_list();
    
    Node<int>* element = firstList.search_node(11);

    if(element)
        cout << element->get_data() << endl;
    return 0;
}