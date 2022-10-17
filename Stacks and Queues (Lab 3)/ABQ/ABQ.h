#include <iostream>
using namespace std;
template <typename T>

class ABQ {
   private:
        static double scale_factor;
        T* array;
        int size;
        int capacity;
   
   public:
      ABQ();
      
      ABQ(int capacity);
      
      ABQ(const ABQ &d);
      
      ABQ &operator=(const ABQ &d);
      
      ~ABQ();
      
      void enqueue(T data);
      
      T dequeue();
      
      T peek();
      
      unsigned int getSize();
      
      unsigned int getMaxCapacity();
      
      T* getData();   
};

template <typename T>
double ABQ<T>::scale_factor = 2.0;

// Constructor
template <typename T>
ABQ<T>::ABQ() {
   capacity = 1;
   size = 0;
   array = new T[capacity];
}

// Parameterized Constructor
template <typename T>
ABQ<T>::ABQ(int capacity) {
   this->capacity = capacity;
   size = 0;
   array = new T[this->capacity];
}

// Copy Constructor
template <typename T>
ABQ<T>::ABQ(const ABQ &otherQueue) {
   capacity = otherQueue.capacity;
   size = otherQueue.size;
   array = new T[capacity];
   
   for (int i = 0; i < otherQueue.size; i++) {
      array[i] = otherQueue[i];
   }
}

// Copy Assignment Operator
template <typename T>
ABQ<T>& ABQ<T>::operator=(const ABQ &otherQueue) {
   ABQ newQueue;
   newQueue.capacity = otherQueue.capacity;
   newQueue.size = otherQueue.size;
   newQueue.array = new T[otherQueue.capacity];
   
   for (int i = 0; i < otherQueue.size; i++) {
      newQueue.array[i] = otherQueue.array[i];
   }
   return newQueue;
}

// Destructor
template <typename T>
ABQ<T>::~ABQ() {
   delete[] array;
}

// Adds new item to start of queue and resizes if necessary
template <typename T>
void ABQ<T>::enqueue(T data) {
   if (size == capacity) {
      capacity = capacity * scale_factor;
      T* newArray = new T[capacity];
      for (int i = 0; i < size; i++) {
         newArray[i] = array[i];
      }
      delete[] array;
      array = newArray;
   }
   array[size] = data;
   size++;
}

// Removes item from front of queue, resizes if necessary, throws runtime error if empty
template <typename T>
T ABQ<T>::dequeue() {
   if (size == 0) {
      throw runtime_error("Can't dequeue if queue is empty.");
   }
   
   T topItem = array[0];
   
   for (int i = 0; i < size - 1; i++) {
      array[i] = array[i + 1];
   }
   
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

// Returns value from front of queue, without removing, throws runtime error if empty.
template <typename T>
T ABQ<T>::peek() {
   if (size == 0) {
      throw runtime_error("Can't peek if queue is empty.");
   }
   return array[0];
}

template <typename T>
unsigned int ABQ<T>::getSize() {
   return size;
}

template <typename T>
unsigned int ABQ<T>::getMaxCapacity() {
   return capacity;
}

template <typename T>
T* ABQ<T>::getData() {
   return array;
}