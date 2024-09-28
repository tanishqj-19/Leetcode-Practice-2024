class MyCircularDeque {
    int* arr;
    int n, front, rear;
public:
    MyCircularDeque(int k) {
        arr = new int[k];
        n = k;
        front = rear = -1;
    }
    
    bool insertFront(int value) {

        if(isFull()){
            return false;
        }else if(front == -1){
            front = rear = 0;    
        }else if(front == 0 && rear != n-1){
            front = n-1;
        }else{
            front--;
        }
        arr[front] = value;

        return true;
    }
    
    bool insertLast(int value) {
        
        if(isFull()){
            return false;
        }else if(front == -1){
            rear = front = 0;
        }else if (rear == n-1 && front != 0){
            rear = 0;
        }else{
            rear++;
        }
        arr[rear] = value;

        return true;
    }
    
    bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }
        arr[front] = -1;

        if(front == rear){
            front = rear = -1;
        }else if (front == n-1)
            front = 0;
        else
            front++;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()){
            return false;
        }
        arr[rear] = -1;
        if(front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = n-1;
        else
            rear--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;

        return arr[front];

    }
    
    int getRear() {
        
        if(isEmpty()) return -1;

        return arr[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return ((front == 0 && rear == n-1) || (front != 0 && rear == (front - 1) % (n-1)));
        
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */