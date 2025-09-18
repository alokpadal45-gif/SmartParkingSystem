#include <iostream>
using namespace std;

class Student {
    string name;
    int age;
    float total_marks;

public:
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setTotalMarks(float m) { total_marks = m; }

    string getName() { return name; }
    int getAge() { return age; }
    float getPercentage() { return (total_marks / 500.0f) * 100; }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Total Marks: " << total_marks << endl;
    }
};

int main() {
    Student ob1;

    ob1.setName("Ram");
    ob1.setAge(22);
    ob1.setTotalMarks(345);

    cout << "Following are the details: " << endl;
    ob1.display();
    cout << "Name (via getter): " << ob1.getName() << endl;
    cout << "Percentage: " << ob1.getPercentage() << "%" << endl;

    return 0;
}


