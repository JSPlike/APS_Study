## Queue의 구현

### 선형 큐

삽입 : enQueue

삭제 : deQueue

> 선형 큐는 계속 해서 데이터가 들어감에 따라서
  front, rear가 증가하기 때문에 나중엔 배열의 한계점을 넘어갈 수 있다.
  
  > 1. 배열을 크게 만든다.
  > 2. Linked List를 이용하여 Queue를 만든다.



### 연결 큐

```
  #include<iostream>
  using namespace std;

  struct Node{
    string data;
    struct Node *link;
  };
  struct LinkedQueue {
    Node *front, *rear;
    int len = 0;
    LinkedQueue() {
      front = rear = NULL;
    }
    bool isEmpty() {
      return len == 0;
    }
    int size() {
      return len;
    }
    void enQueue(string data) {
      Node *node = (Node*)malloc(sizeof(Node));
      node->data = data;
      node->link = NULL;


      if (isEmpty()) front = rear = node;
      else {
        rear->link = node;
        rear = rear->link;
      }
      ++len;
    }
    void deQueue() {
      if (isEmpty()) cout << "Empty!!" << '\n';
      else {
        Node *delNode = front;
        string ret = delNode->data;
        front = delNode->link;
        free(delNode);
        --len;
      }
    }
  };
  int main() {
    LinkedQueue q;
    for (int i = 0; i <= 10; i++) q.enQueue;

    q.enQueue(10);
    while (!q.isEmpty) {
      cout << q.deQueue << endl;
    }
  }
```
