#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }

        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void InsertatBeg(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void InsertatEnd(int data)
    {
        Node *ptr = head;
        Node *newNode = new Node(data);
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newNode;
    }

    void deleteNode(int data)
    {
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return;
        }

        if (head->data == data)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node with data " << data << " deleted." << endl;
            return;
        }

        Node *temp = head;
        Node *prev = nullptr;
        while (temp != nullptr && temp->data != data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Node not found." << endl;
            return;
        }

        prev->next = temp->next;

        delete temp;
        cout << "Node with data " << data << " Deleted." << endl;
        return;
    }
};

class Stack
{
private:
    vector<int> stack;

public:
    void push(int x)
    {
        stack.push_back(x);
    }

    int pop()
    {
        if (stack.empty())
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int x = stack.back();
            stack.pop_back();
            return x;
        }
    }

    int peek()
    {
        if (stack.empty())
        {
            cout << "Stack is Empty." << endl;
            return -1;
        }
        else
        {
            return stack.back();
        }
    }

    bool isEmpty()
    {
        return stack.empty();
    }
    void display()
    {
        if (stack.empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = stack.size() - 1; i >= 0; i--)
            {
                cout << stack[i] << " ";
            }
            cout << endl;
        }
    }
};

class Queue
{
private:
    vector<int> queue;

public:
    void enqueue(int x)
    {
        queue.push_back(x);
    }

    int dequeue()
    {
        if (queue.empty())
        {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else
        {
            int x = queue.front();
            queue.erase(queue.begin());
            return x;
        }
    }

    int peek()
    {
        if (queue.empty())
        {
            cout << "Queue is Empty." << endl;
            return -1;
        }
        else
        {
            return queue.front();
        }
    }

    bool isEmpty()
    {
        return queue.empty();
    }
    void display()
    {
        if (queue.empty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = 0; i < queue.size(); i++)
            {
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }
};

void ListMenu(bool check)
{
    int choice, data;
    LinkedList list;
    do
    {
        if (check == false)
        {
            cout << "1. Insert at Beginning" << endl;
            cout << "2. Insert at End" << endl;
            cout << "3. Delete a node" << endl;
            cout << "4. Display" << endl;
            cout << "5. Back" << endl;
            cout << "6. Exit" << endl;

            cout << "Enter Your choice: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "\n Enter the data:";
            cin >> data;
            list.InsertatBeg(data);
            list.display();
            break;

        case 2:
            cout << "\n Enter the data:";
            cin >> data;
            list.InsertatEnd(data);
            list.display();
            break;

        case 3:
            cout << "\n Enter the data:";
            cin >> data;
            list.deleteNode(data);
            list.display();
            break;

        case 4:
            list.display();
            break;
        case 5:
            check = true;
            return;
            break;
        case 6:
            exit(1);
            break;
        }
    } while (choice != 6);
}

void StackMenu(bool check)

{
    int choice, x;
    Stack s;
    do
    {
        if (check == false)
        {
            cout << "1. Push" << endl;
            cout << "2. Pop " << endl;
            cout << "3. Display" << endl;
            cout << "4. peek" << endl;
            cout << "5. Back" << endl;
            cout << "6. Exit" << endl;

            cout << "Enter Your choice: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "\nEnter Data: ";
            cin >> x;
            s.push(x);
            s.display();
            break;
        case 2:
            s.pop();
            s.display();
            cout << s.pop();
            break;
        case 4:
            cout << s.peek();
            break;
        case 3:
            s.display();
        case 5:
            check = true;
            return;
            break;
        case 6:
            exit(1);
            break;
        }

    } while (choice != 6);
}

void QueueMenu(bool check)
{

    int choice, x;
    Queue q;
    do
    {
        if (check == false)
        {
            cout << "1. Enqueue " << endl;
            cout << "2. Dequeue " << endl;
            cout << "3. Display" << endl;
            cout << "4. peek" << endl;
            cout << "5. Back" << endl;
            cout << "6. Exit" << endl;

            cout << "Enter Your choice: ";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter data: ";
            cin >> x;
            q.enqueue(x);
            q.display();
            break;

        case 2:
            q.dequeue();
            q.display();
            break;

        case 3:
            q.display();
            break;
        case 4:
            cout << q.peek();
            break;
        case 5:
            check = true;
            return;
            break;

        case 6:
            exit(1);
            break;
        }

    } while (choice != 6);
}

int main()
{
    int choice, data;
    bool check = false;
    LinkedList list;
    do
    {
        cout << "======= MAIN MENU ========" << endl;

        cout << "1. LinkedList" << endl;
        cout << "2. Stack" << endl;
        cout << "3. Queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            ListMenu(check);
            break;
        case 2:
            StackMenu(check);
            break;
        case 3:
            QueueMenu(check);
            break;
        case 4:
            break;
        }

    } while (choice != 4);

    return 0;
}