#include <iostream>
using namespace std;

class Book {
    string title;
    string author;
    float price;
    string publication;
    bool issued;

public:
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setPrice(float p) { price = p; }
    void setPublication(string pub) { publication = pub; }
    void setIssued(bool i) { issued = i; }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    float getPrice() { return price; }
    string getPublication() { return publication; }
    bool isIssued() { return issued; }

    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
        cout << "Publication: " << publication << endl;
        cout << "Issued: " << (issued ? "Yes" : "No") << endl;
    }
};

int main() {
    Book cricketBook;

    cricketBook.setTitle("Cricket: The Gentleman's Game");
    cricketBook.setAuthor("Rahul Dravid");
    cricketBook.setPrice(899.50);
    cricketBook.setPublication("Sports World Publications");
    cricketBook.setIssued(true);

    cout << "Cricket Book Details:\n";
    cricketBook.display();

    return 0;
}

