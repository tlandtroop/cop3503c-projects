#include <iostream>
using namespace std;
template <typename T>

class ABS {
    public:
        // Constructor
        ABS();

        // Parameterized Constructor
        ABS(int capacity);
        
        ABS(const ABS &otherStack);

        // Copy Assignment Operator
        ABS &operator=(const ABS &otherStack);

        // Destructor
        ~ABS();

        // Add new item to the top of stack / resize if necessary
        void push(T data);

        // Removes an item from top of stack, resizes if necessary, return value removed
        T pop();
       

        T peek();

        unsigned int getSize();
        
        unsigned int getMaxCapacity();

        T* getData();
        
    private:
        static double scale_factor;
        T* array;
        int size;
        int capacity;
};


template <class T>
double ABS<T>::scale_factor = 2.0;

// Constructor
template <typename T>
ABS<T>::ABS() {
   capacity = 1;
   size = 0;
   array = new T[capacity];
}

// Parameterized Constructor
template <typename T>
ABS<T>::ABS(int capacity) {
   this->capacity = capacity;
   size = 0;
   array = new T[this->capacity];
}

template <typename T>
ABS<T>::ABS(const ABS &otherStack) {
   capacity = otherStack.capacity;
   size = otherStack.size;
   array = new T[capacity];

// Copies array items from one stack to another
   for (int i = 0; i < otherStack.size; i++) {
      array[i] = otherStack[i];
   }
}

// Copy Assignment Operator
template <typename T>
ABS<T>& ABS<T>::operator=(const ABS &otherStack) {
   ABS newStack;
   newStack.capacity = otherStack.capacity;
   newStack.size = otherStack.size;
   newStack.array = new T[otherStack.capacity];

   // Adds array items from other stack to the new stack
   for (int i = 0; i < otherStack.size; i++) {
      newStack.array[i] = otherStack.array[i];
   }
   return newStack;
}

// Destructor
template <typename T>
ABS<T>::~ABS() {
   delete[] array;
}

// Add new item to the top of stack / resize if necessary
template <typename T>
void ABS<T>::push(T data) {
   // If stack is full, double size and add item to the top of stack
   if (size == capacity) {
      capacity = capacity * scale_factor;
      T* newArray = new T[capacity];
      for (int i = 0; i < size; i++) {
         newArray[i] = array[i];
      }
      // Deallocates memory before redirecting pointer
      delete[] array;
      array = newArray;
   }
   array[size] = data;
   size++;
}

// Removes an item from top of stack, resizes if necessary, return value removed
template <class T>
T ABS<T>::pop() {         
   // If stack is empty, throw runtime error
   if (size == 0) {
      throw runtime_error("Cannot pop from an empty stack");
   }
   T topItem = array[size - 1];
   size--;
   double percentFull = double(size) / capacity;
   if (percentFull < (1.0 / scale_factor)) {
      capacity = capacity / scale_factor;
      T* newArray = new T[capacity];
      for (int i = 0; i < capacity; i++) {
         newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
   }
   return topItem;
}

template <class T>
T ABS<T>::peek() {       
// If stack is empty, throw runtime error
   if (size == 0) {
      throw runtime_error ("An error has occurred.");
   }
   return array[size - 1];
}

template <typename T>
unsigned int ABS<T>::getSize() {
   return size;
}

template <typename T>
unsigned int ABS<T>::getMaxCapacity() {
   return capacity;

}

template <typename T>
T* ABS<T>::getData() {
   return array;
}








