#pragma once
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
class LinkedList
{
public:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };

    // Construction / Destruction
    LinkedList();

    LinkedList(const LinkedList<T> &list);

    ~LinkedList();

    // Operators
    const T &operator[](unsigned int index) const;

    T &operator[](unsigned int index);

    bool operator==(const LinkedList<T> &rhs) const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    // Insertion
    void AddHead(const T &data);

    void AddTail(const T &data);

    void AddNodesHead(const T *data, unsigned int count);

    void AddNodesTail(const T *data, unsigned int count);

    void InsertBefore(Node *node, const T &data);

    void InsertAfter(Node *node, const T &data);

    void InsertAt(const T &data, unsigned int index);

    // Removal
    bool RemoveHead();

    bool RemoveTail();

    unsigned int Remove(const T &data);

    bool RemoveAt(unsigned int index);

    void Clear();

    // Accessors
    unsigned int NodeCount() const;

    Node *Head();

    const Node *Head() const;

    Node *Tail();

    const Node *Tail() const;

    Node *GetNode(unsigned int index);

    const Node *GetNode(unsigned int index) const;

    Node *Find(const T &data);

    const Node *Find(const T &data) const;

    void FindAll(vector<Node *> &outData, const T &value) const;

    // Behaviors
    void PrintForward();

    void PrintReverse();

    void PrintForwardRecursive(const Node *node) const;

    void PrintReverseRecursive(const Node *node) const;

private:
    int nodeCount;
    Node *head;
    Node *tail;
    Node *temp;
};

// Construction / Destruction
template <typename T>
LinkedList<T>::LinkedList()
{
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list)
{
    this->head = nullptr;
    this->tail = nullptr;
    this->nodeCount = 0;

    const Node *temp = list.Head();
    while (temp != nullptr)
    {
        AddTail(temp->data);
        temp = temp->next;
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    nodeCount = 0;
    head = nullptr;
    tail = nullptr;
}

// Operators
template <typename T>
T &LinkedList<T>::operator[](unsigned int index)
{
    if (nodeCount == 0 || index > nodeCount - 1)
    {
        throw out_of_range("Out of range exception");
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
const T &LinkedList<T>::operator[](unsigned int index) const
{
    if (nodeCount == 0 || index > nodeCount - 1)
    {
        throw out_of_range("Out of range exception");
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
bool LinkedList<T>::operator==(const LinkedList<T> &rhs) const
{
    if (nodeCount != rhs.nodeCount)
    {
        return false;
    }
    if (head == rhs.head)
    {
        if (head == nullptr)
            return true;
    }

    Node *pointer1 = head;
    Node *pointer2 = rhs.Head();

    while (pointer1 != nullptr && pointer2 != nullptr)
    {
        if (pointer1->data != pointer2->data)
        {
            return false;
        }
        pointer1 = pointer1->next;
        pointer2 = pointer2->next;
    }
    return true;
}

template <typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{

    Node *temp = head;
    while (temp != nullptr)
    {
        Node *nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
    head = nullptr;
    tail = nullptr;
    nodeCount = 0;

    Node *newTemp = rhs.head;
    while (newTemp != nullptr)
    {
        AddTail(newTemp->data);
        newTemp = newTemp->next;
    }
    return *this;
}

// Insertion
template <typename T>
void LinkedList<T>::AddHead(const T &data)
{
    temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (nodeCount == 0)
    {
        head = temp;
        tail = temp;
        nodeCount++;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
        nodeCount++;
    }
}

template <typename T>
void LinkedList<T>::AddTail(const T &data)
{
    temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    temp->prev = nullptr;

    if (nodeCount == 0)
    {
        head = temp;
        tail = temp;
        nodeCount++;
    }
    else
    {
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
        nodeCount++;
    }
}

template <typename T>
void LinkedList<T>::AddNodesHead(const T *data, unsigned int count)
{
    for (int i = int(count) - 1; i >= 0; i--)
    {
        AddHead(data[i]);
    }
}

template <typename T>
void LinkedList<T>::AddNodesTail(const T *data, unsigned int count)
{
    for (int i = 0; i < int(count); i++)
    {
        AddTail(data[i]);
    }
}

template <typename T>
void LinkedList<T>::InsertBefore(Node *node, const T &data)
{
    if (node == nullptr)
    {
        AddTail(data);
    }
    else
    {
        Node *newNode = new Node();
        newNode->data = data;
        Node *prevNode = node->prev;
        if (prevNode != nullptr)
        {
            prevNode->next = newNode;
        }
        newNode->prev = node->prev;
        newNode->next = node;
        node->prev = newNode;
        if (prevNode == nullptr)
        {
            head = newNode;
        }
        nodeCount++;
    }
}

template <typename T>
void LinkedList<T>::InsertAfter(Node *node, const T &data)
{
    if (node == nullptr)
    {
        AddTail(data);
    }
    else
    {
        Node *newNode = new Node();
        newNode->data = data;
        Node *nextNode = node->next;
        if (nextNode != nullptr)
        {
            nextNode->prev = newNode;
        }
        newNode->next = node->next;
        newNode->prev = node;
        node->next = newNode;
        if (nextNode == nullptr)
        {
            tail = newNode;
        }
        nodeCount++;
    }
}

template <typename T>
void LinkedList<T>::InsertAt(const T &data, unsigned int index)
{
    if ((int)index > nodeCount)
    {
        throw out_of_range("Out of range");
    }

    Node *temp = head;
    for (unsigned int i = 0; i < index && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    InsertBefore(temp, data);
}

// Removal
template <typename T>
bool LinkedList<T>::RemoveHead()
{
    if (nodeCount == 0)
    {
        return false;
    }
    else if (nodeCount == 1)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
        return true;
    }
    else
    {
        Node *temp = head->next;
        temp->prev = nullptr;
        delete head;
        head = temp;
        nodeCount--;
        return true;
    }
}

template <typename T>
bool LinkedList<T>::RemoveTail()
{
    if (nodeCount == 0)
    {
        return false;
    }
    else if (nodeCount == 1)
    {
        delete tail;
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
        return true;
    }
    else
    {
        Node *temp = tail->prev;
        temp->next = nullptr;
        delete tail;
        tail = temp;
        nodeCount--;
        return true;
    }
}

template <typename T>
unsigned int LinkedList<T>::Remove(const T &data)
{
    vector<unsigned int> toRemove;
    Node *temp = head;
    for (int i = 0; i < nodeCount; i++)
    {
        if (temp->data == data)
        {
            toRemove.push_back(i);
        }
        temp = temp->next;
    }
    unsigned int numRemoved = toRemove.size();
    for (int j = toRemove.size() - 1; j >= 0; j--)
    {
        RemoveAt(toRemove[j]);
    }
    return numRemoved;
}

template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index)
{
    if ((int)index >= nodeCount)
    {
        return false;
    }
    else if (index == 0)
    {
        RemoveHead();
        return true;
    }
    else if ((int)index == (nodeCount - 1))
    {
        RemoveTail();
        return true;
    }
    else
    {
        unsigned int count = 0;
        Node *temp = head;
        while (temp != nullptr)
        {
            if (count == index)
            {
                break;
            }
            count++;
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        temp = nullptr;
        nodeCount--;
        return true;
    }
}

template <typename T>
void LinkedList<T>::Clear()
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
        temp = nullptr;
    }
    tail = nullptr;
    nodeCount = 0;
}

// Accessors
template <typename T>
unsigned int LinkedList<T>::NodeCount() const
{
    return nodeCount;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Head()
{
    return head;
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Head() const
{
    return head;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Tail()
{
    return tail;
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Tail() const
{
    return tail;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index)
{
    if ((int)index >= nodeCount)
    {
        throw out_of_range("Index out of range");
    }
    else
    {
        Node *temp = head;
        for (unsigned int i = 0; i < index && temp != nullptr; i++)
        {
            temp = temp->next;
        }
    }
    return temp;
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::GetNode(unsigned int index) const
{
    if (index >= nodeCount)
    {
        throw out_of_range("Index out of range");
    }
    Node *temp = head;
    for (int i = 0; i < index && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    return temp;
}

template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
const typename LinkedList<T>::Node *LinkedList<T>::Find(const T &data) const
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

template <typename T>
void LinkedList<T>::FindAll(vector<Node *> &outData, const T &value) const
{
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            outData.push_back(temp);
        }
        temp = temp->next;
    }
}

// Behaviors
template <typename T>
void LinkedList<T>::PrintForward()
{
    if (nodeCount == 0)
    {
        cout << "Linked List is empty." << endl;
    }

    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <typename T>
void LinkedList<T>::PrintReverse()
{
    if (nodeCount == 0)
    {
        cout << "Linked List is empty." << endl;
    }

    temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node *node) const
{
    if (node == tail)
    {
        cout << node->data << endl;
    }
    else
    {
        cout << node->data << endl;
        PrintForwardRecursive(node->next);
    }
}

template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node *node) const
{
    if (node == head)
    {
        cout << node->data << endl;
    }
    else
    {
        cout << node->data << endl;
        PrintReverseRecursive(node->prev);
    }
}