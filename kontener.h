#ifndef KONTENER_H_INCLUDED
#define KONTENER_H_INCLUDED

template<typename T>
struct Lista
{
private:
    struct Node
    {
        T value;
        Node * next;
        Node(T v, Node * n=nullptr)
        {
            value=v;
            next=n;
        }
    };
    Node * head=nullptr;
    int counter=0;

public:
    Lista()=default;
    ~Lista();
    void insert(T value);
    T pop();
    void clear();
    int size();
};

template<typename T>
Lista<T>::~Lista()
{
    clear();
}

template<typename T>
void Lista<T>::insert(T val)
{
    Node * creator=new Node(val);

    if(head==nullptr)
    {
        head=creator;
    }

    else if(val<=head->value)
    {
        creator->next=head;
        head=creator;
    }

    else
    {
        Node * succ=head;
        Node * pred=nullptr;

        while(succ != nullptr && succ->value<val)
        {
            pred=succ;
            succ=succ->next;
        }

        pred->next=creator;
        creator->next=succ;
    }

    counter++;
}

template<typename T>
T Lista<T>::pop()
{
    if(counter==0)
        throw logic_error("Lista jest pusta!");

    Node * killer=head;
    head=killer->next;
    T result=killer->value;

    delete killer;
    counter --;

    return result;
}

template<typename T>
void Lista<T>::clear()
{
    Node * killer;
    while(head != nullptr)
    {
        killer=head;
        head=killer->next;
        delete killer;
    }
    counter=0;
}

template <typename T>
int Lista<T>::size()
{
    return counter;
}



#endif // KONTENER_H_INCLUDED
