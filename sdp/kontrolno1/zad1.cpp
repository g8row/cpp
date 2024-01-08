#include <iostream>
#include <string>
#include <stack>
#include <queue>

struct Book {
    std::string name;
    std::string genre;
};

void read(std::queue<std::stack<Book>> books, int DIFF) {
    Book lastRead = books.front().top();
    std::cout << lastRead.name << " " << lastRead.genre << std::endl;
    int lastReadBooks = books.front().size();
    while (!books.empty()) {
        std::stack<Book> currStack = books.front();
        books.pop();
        if (abs(lastReadBooks - currStack.size()) <= DIFF) {
            lastReadBooks = 0;
            if (!lastRead.name.compare(currStack.top().name)) {
                lastReadBooks++;
                currStack.pop();
            }
            while (!currStack.empty()) {
                if (!lastRead.genre.compare(currStack.top().genre)) {
                    books.front().push(currStack.top());
                }
                else {
                    std::cout << currStack.top().name << " " << currStack.top().genre << std::endl;
                    lastRead = currStack.top();
                    lastReadBooks++;
                }
                currStack.pop();
            }
        }
        else {
            books.push(currStack);
        }
        if (lastReadBooks == 0) {
            std::cout << "can't be read" << std::endl;
            break;
        }
    }
}


/* int main() {
    int DIFF = 1;
    std::stack<Book> stack1;
    std::stack<Book> stack2;
    std::stack<Book> stack3;



    stack1.push(Book{ "Crime_in_the_car", "mystery" });
    stack1.push(Book{ "1984", "dystopia" });
    stack1.push(Book{ "Lord_of_the_flies", "dystopia" });
    stack1.push(Book{ "Dracula", "horror" });
    stack1.push(Book{ "Persuasion", "romance" });



    stack2.push(Book{ "Lolita", "romance" });

    stack3.push(Book{ "Harry_Potter", "fantasy" });
    stack3.push(Book{ "A_study_in_scarlet", "mystery" });
    stack3.push(Book{ "Little_women", "historical" });

    std::queue<std::stack<Book>> books;
    books.push(stack1);
    books.push(stack2);
    books.push(stack3);



} */