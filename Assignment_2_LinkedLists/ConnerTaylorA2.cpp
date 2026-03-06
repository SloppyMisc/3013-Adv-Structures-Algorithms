/******************************************************************************************
*   Name: YOUR NAME
*   Course: Analysis of Algorithms
*   Assignment: Assignment #2 - Linked Lists
*   Semester: Spring 2026
*   Description: This program implements a simple student database using a linked list.
******************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
    Structure: Student
    Definition: Stores the information for a student in the database.
*/
struct Student
{
    string lastName;
    int mustangID;
    char gender;
    double gpa;
};

/*
    Structure: Node
    Definition: Represents a node in the linked list.
    Each node contains a Student and a pointer to the next node.
*/
struct Node
{
    Student data;
    Node* next;
};

/*
    Function: InsertNode
    Definition: Inserts a new student node at the end of the linked list.
*/
void InsertNode(Node*& head, Student s)
{
    Node* newNode = new Node;
    newNode->data = s;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/*
    Function: ShowList
    Definition: Traverses the linked list and displays all students.
*/
void ShowList(Node* head)
{
    Node* temp = head;

    cout << "\n------ STUDENT DATABASE ------\n";

    while (temp != NULL)
    {
        cout << "Last Name: " << temp->data.lastName << endl;
        cout << "Mustang ID: " << temp->data.mustangID << endl;
        cout << "Gender: " << temp->data.gender << endl;
        cout << "GPA: " << temp->data.gpa << endl;
        cout << "------------------------------\n";

        temp = temp->next;
    }
}

/*
    Function: CountLastName
    Definition: Counts how many students in the list have the same last name.
*/
int CountLastName(Node* head, string name)
{
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data.lastName == name)
            count++;

        temp = temp->next;
    }

    return count;
}

/*
    Function: CountGender
    Definition: Counts how many students are male and how many are female.
*/
void CountGender(Node* head)
{
    int males = 0;
    int females = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data.gender == 'M')
            males++;

        if (temp->data.gender == 'F')
            females++;

        temp = temp->next;
    }

    cout << "\nGender Statistics\n";
    cout << "Number of Male Students: " << males << endl;
    cout << "Number of Female Students: " << females << endl;
}

/*
    Function: RemoveByLastName
    Definition: Removes a student node from the list using the last name.
*/
void RemoveByLastName(Node*& head, string name)
{
    Node* temp = head;
    Node* previous = NULL;

    while (temp != NULL)
    {
        if (temp->data.lastName == name)
        {
            if (previous == NULL)
                head = temp->next;
            else
                previous->next = temp->next;

            delete temp;

            cout << "\nStudent with last name '" << name << "' has been removed.\n";
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    cout << "\nStudent with last name '" << name << "' was not found.\n";
}

int main()
{
    Node* head = NULL;

    /*
        Creating the student records required in the assignment
    */

    Student s1 = {"Stringfellow", 1111, 'F', 4.0};
    Student s2 = {"Colmenares", 2222, 'M', 3.8};
    Student s3 = {"Passos", 3333, 'M', 3.9};
    Student s4 = {"Johnson", 4444, 'F', 3.5};
    Student s5 = {"Roychonduri", 5555, 'F', 3.75};
    Student s6 = {"Morgan", 6666, 'F', 3.6};
    Student s7 = {"Griffin", 7777, 'M', 3.4};
    Student s8 = {"Eldefrawy", 8888, 'M', 3.85};

    // Insert students into the linked list
    InsertNode(head, s1);
    InsertNode(head, s2);
    InsertNode(head, s3);
    InsertNode(head, s4);
    InsertNode(head, s5);
    InsertNode(head, s6);
    InsertNode(head, s7);
    InsertNode(head, s8);

    // Display list before removal
    cout << "Displaying the student list BEFORE removal:";
    ShowList(head);

    // Count gender statistics
    CountGender(head);

    // Count same last name
    string searchName;
    cout << "\nEnter a last name to count how many times it appears: ";
    cin >> searchName;

    cout << "\nThe last name '" << searchName << "' appears "
         << CountLastName(head, searchName) << " time(s) in the list.\n";

    // Remove a student
    string removeName;
    cout << "\nEnter the last name of the student to remove: ";
    cin >> removeName;

    RemoveByLastName(head, removeName);

    // Display list after removal
    cout << "\nDisplaying the student list AFTER removal:";
    ShowList(head);

    return 0;
}