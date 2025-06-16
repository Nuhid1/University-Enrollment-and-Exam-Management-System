#include<iostream>
using namespace std;

class admission
{
  public:

      struct student
{
   int id;
   student* next;
   student* pre;
   student(int x)
   {
     id=x;
     next=nullptr;
     pre=nullptr;
   }
};

  student* head=nullptr;

  void addStudent (int x)
{
    cout << "student added : "<<x <<endl<<endl;
    student* n1 = new student(x);
    student* temp=head;
    if (temp==nullptr)
    {
        head=n1;
        return;
    }
    else
    {
        while (temp->next!=nullptr)
    {
      temp=temp->next;
    }

    temp->next=n1;
    n1->pre=temp;

    }

}

void removeStudent (int id)
{
    cout << "student removed : "<<id<<endl;
   int x;
   student* temp=head;
   while (temp!=nullptr && temp->id!=id)
   {
    temp=temp->next;
   }

   if (temp==nullptr)
   {
    cout << "invalid id"<<endl;
    return;
   }

   if (temp==head)
   {
    head=head->next;
    head->pre=nullptr;
   }

   if (temp->next!=nullptr)
   {
    temp->next->pre=temp->pre;
    temp->pre->next=temp->next;
   }
   delete temp;

}

void displayForward ()
{
    cout << "student list (forward) :"<<endl;
    student* temp=head;
    while (temp!=nullptr)
    {
        cout << temp->id << " -> ";
        temp=temp->next;
    }
    cout << endl<<endl;

}

void displayBackward ()
{
    cout << "student list (backward) :"<<endl;
    student* temp=head;
    while (temp->next!=nullptr)
    {
        temp=temp->next;
    }
    while (temp!=nullptr)
    {
        cout << temp->id << " -> ";
        temp=temp->pre;
    }
    cout << endl<<endl;
}

};

class registration
{
public:
    struct student
{
   int id;
   int course_id;
   student* next;
   student(int x,int y)
   {
     id=x;
     course_id=y;
     next=nullptr;
   }
};
student* front=nullptr;
student* rear=nullptr;

void registerCourse (int id,int course)
{
    cout << "course registered : "<< id << " - " << course <<endl;
    student* n1=new student(id,course);
    if (rear==nullptr)
    {
        rear=front=n1;
        return;
    }
    rear->next=n1;
    rear=rear->next;
}

void display ()
{
    student* temp=front;
    if (temp==nullptr)
    {
        cout << "empty registration queue"<<endl;
        return;
    }
    cout << "course registration queue : "<<endl;
    while (temp!=nullptr)
    {
        cout << temp->id << " - "<< temp->course_id << " -> ";
        temp=temp->next;
    }
    cout <<endl<<endl;
}

void dequeue ()
{
    student* temp=front;
    if (front==nullptr)
    {
        cout << "empty registration queue. so cannot dequeue "<<endl;
     return;
    }
    cout << "dequeue : " << front->id << " - "<< front->course_id <<endl;
    front=front->next;
    return;
}
};

class resultManagement
{
    public:

    struct student
    {
        int id;
        int result;
        student* left;
        student* right;

        student (int x , int y)
        {
            id=x;
            result=y;
            left = nullptr;
            right=nullptr;
        }
    };

    student* root=nullptr;

    student* insert (student* root,int a,int b)
{
    student* n=new student(a,b);
    if (root==nullptr)
    {
        root=n;
    }
    else if (a<root->id)
    {
        root->left=insert(root->left,a,b);
    }
    else if (a>root->id)
    {
        root->right=insert(root->right,a,b);
    }
    return root;
}

    student* insertExamResult (int a1,int b1)
{
    cout<< " exam record inserted : "<<a1<<endl<<"marks: "<<b1<<endl;
    root=insert(root,a1,b1);
    return root;
}

void display(student* temp)
{
    if (temp != nullptr) {
        display(temp->left);  // Visit left subtree
        cout << "ID: " << temp->id << " | Result: " << temp->result << endl;  // Visit current node
        display(temp->right); // Visit right subtree
    }
}
void displayResult()
{
    cout << "Exam result (inorder):" << endl;
    display(root);
}


};


int main ()
{
    // for admission students
    admission a;

    a.addStudent(11);
    a.addStudent(14);
    a.addStudent(15);
    a.addStudent(16);
    a.addStudent(13);

    a.removeStudent(15);
    a.removeStudent(16);
    cout<<endl;
    a.displayForward();
    a.displayBackward();

    //using queue for registration course
    registration r;
           //student ID | course ID
    r.registerCourse(11 , 222);
    r.registerCourse(14 , 822);
    r.registerCourse(15 , 272);
    r.registerCourse(13 , 202);

    r.dequeue();
    r.display();

    //using BST for result managements system
    resultManagement q;
    q.insertExamResult(11,85);
    q.insertExamResult(14,89);
    q.insertExamResult(15,55);
    q.insertExamResult(12,80);
    q.insertExamResult(13,75);
    cout<<endl;

    q.displayResult();

    return 0;
}
