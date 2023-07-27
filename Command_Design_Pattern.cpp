// https://stackoverflow.com/questions/32597736/why-should-i-use-the-command-design-pattern-while-i-can-easily-call-required-met
// Reasons to use command design pattern: 1) Hide the implementation 2) Allow methods to be built around command, aka command extensions

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Character{
    int x;
    int y;
    std::string name;
    Character(std::string _name): name(_name){}
    void move(int _x, int _y){
        x = _x;
        y = _y;
    }
};

// Command Design Pattern
class Command{ // This is an interface 
    public:
        virtual ~Command(){}; // Destructor
        virtual void execute(Character &c) = 0;   // Execute the command - Pure Virtual Functions
        virtual void undo(Character &c) = 0;   // Undo the command - Pure Virtual Functions
};

class Move : public Command{
    public:
        void execute(Character &c){
            int randx = rand() % 4;
            int randy = rand() % 4;
            c.move(randx,randy);
            x = randx;
            y = randy;
            std::cout << c.name << " Moved " << x << " " << y << "\n";
        }
        void undo(Character &c){
            c.move(-x, -y);
            std::cout << c.name << " has Undone " << x << " " << y << "\n";
        }
    private:
        int x;
        int y;
};

int main()
{
    srand(time(NULL));
    std::vector<Command*> command_queue;
    Character c("Anisha");
    Move *m1 = new Move;
    command_queue.push_back(m1);
    Move *m2 = new Move;
    command_queue.push_back(m2);
    Move *m3 = new Move;
    command_queue.push_back(m3);
    Move *m4 = new Move;
    command_queue.push_back(m4);

    for(int i = 0; i < command_queue.size(); i++){
        command_queue[i]->execute(c);
    }
    
    for(int i = command_queue.size() - 1; i > -1; i--){
        command_queue[i]->undo(c);
    }

    return 0;
}