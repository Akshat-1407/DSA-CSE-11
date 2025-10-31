#include <iostream>
#include <vector>
using namespace std;


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


class MyCircularQueue {
public:
    int rear;
    int front;
    int size;
    vector<int>q;

    MyCircularQueue(int k) {
        q.resize(k+1);
        size = k+1;
        front = k;
        rear = k;
    }
    
    bool enQueue(int value) {
        if ((rear+1)%size == front)
            return false;

        rear = (rear+1) % size;
        q[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(rear == front)
            return false;

        front = (front+1) % size;
        return true;  
    }
    
    int Front() {
        if (rear == front)
            return -1;
        else
            return q[(front+1) % size];        
    }
    
    int Rear() {
        if(rear == front)
            return -1;
        else 
            return q[rear%size];
    }
    
    bool isEmpty() {
        if(rear == front)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if ((rear+1)%size == front)
            return true;
        else 
            return false;
    }
};


int main() {
    cout << "--- Circular Queue Demonstration (Capacity k=3) ---" << endl;
    
    // Create a queue with a capacity of 3
    MyCircularQueue* obj = new MyCircularQueue(3);

    cout << "Initial State:" << endl;
    cout << "Is Empty: " << (obj->isEmpty() ? "True" : "False") << endl; // Expected: True
    cout << "Is Full: " << (obj->isFull() ? "True" : "False") << endl;   // Expected: False
    cout << "Front: " << obj->Front() << endl; // Expected: -1
    cout << "Rear: " << obj->Rear() << endl;   // Expected: -1

    // 1. Enqueue elements (10, 20, 30)
    cout << "\n--- Enqueueing 10, 20, 30 ---" << endl;
    cout << "Enqueuing 10: " << (obj->enQueue(10) ? "Success" : "Fail") << endl;
    cout << "Enqueuing 20: " << (obj->enQueue(20) ? "Success" : "Fail") << endl;
    cout << "Enqueuing 30: " << (obj->enQueue(30) ? "Success" : "Fail") << endl;

    cout << "Front: " << obj->Front() << endl; // Expected: 10
    cout << "Rear: " << obj->Rear() << endl;   // Expected: 30
    cout << "Is Full: " << (obj->isFull() ? "True" : "False") << endl;   // Expected: True

    // 2. Attempt to enqueue when full
    cout << "\n--- Test Full Condition ---" << endl;
    cout << "Attempt Enqueue 40 (Queue is full): " << (obj->enQueue(40) ? "Success" : "Fail") << endl; // Expected: Fail

    // 3. Dequeue
    cout << "\n--- Dequeue Operations ---" << endl;
    cout << "Dequeuing (removes 10): " << (obj->deQueue() ? "Success" : "Fail") << endl; // Expected: Success
    cout << "Current Front: " << obj->Front() << endl; // Expected: 20
    cout << "Is Full: " << (obj->isFull() ? "True" : "False") << endl; // Expected: False

    // 4. Enqueue again (reusing space)
    cout << "\n--- Enqueue Reusing Space ---" << endl;
    cout << "Enqueuing 40: " << (obj->enQueue(40) ? "Success" : "Fail") << endl; // Expected: Success
    cout << "Front: " << obj->Front() << endl; // Expected: 20
    cout << "Rear: " << obj->Rear() << endl;   // Expected: 40
    cout << "Is Full: " << (obj->isFull() ? "True" : "False") << endl;   // Expected: True

    // 5. Empty the queue
    cout << "\n--- Emptying Queue ---" << endl;
    cout << "Dequeuing (removes 20): " << (obj->deQueue() ? "Success" : "Fail") << endl; // Expected: Success
    cout << "Dequeuing (removes 30): " << (obj->deQueue() ? "Success" : "Fail") << endl; // Expected: Success
    cout << "Dequeuing (removes 40): " << (obj->deQueue() ? "Success" : "Fail") << endl; // Expected: Success

    cout << "Is Empty: " << (obj->isEmpty() ? "True" : "False") << endl; // Expected: True

    // 6. Attempt to dequeue when empty
    cout << "Attempt Dequeue (Empty): " << (obj->deQueue() ? "Success" : "Fail") << endl; // Expected: Fail
    
    // Clean up allocated memory
    delete obj;

    return 0;
}
