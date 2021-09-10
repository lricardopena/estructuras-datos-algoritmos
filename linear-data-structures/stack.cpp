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


template <class T> class CustomStack{
    Node<T> *head;
    int n;

    public:
        CustomStack(){
            this->head = NULL;
            this->n = 0;
        }

        ~CustomStack(){

        }

        void push(T data){
            Node<T>* node = new Node<T>(data, this->head);
            
            this->head = node;
            this->n++;
        }

        T pop(){
            T data;
            if(this->head){
                Node<T>* node = this->head;
                data = node->get_data();
                this->head = this->head->get_next();
                delete node;
                this->n--;
            }
            return data;
        }

        T top(){
            T data;
            if(this->head){
                data = this->head->get_data();
            }
            return data;
        }

        bool isEmpty(){
            return this->head == NULL;
        }
};



int main(){
    CustomStack<int> stack;



    stack.push(10);
    stack.push(21);
    stack.push(11);
    
    stack.push(15);
    
    while(!stack.isEmpty()){
        cout << stack.pop() << endl;    
    }

    return 0;
}