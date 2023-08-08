#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Logger{
    // To create a singleton we need to create a static variable
    public:
        static Logger & getInstance(){
            static Logger * s_logger = new Logger();;  // We want to have it create only once
            // if(s_logger == NULL){
            //     s_logger = new Logger();  // Create an object of this class and assign it as our logger pointer
            // }
            return *s_logger;
        }
        void printMessages(){
            for(string& m: logger_array){
                std::cout << m << "\n";
            }
        }
        void addMessage(std::string s){
            logger_array.push_back(s);
        }

    private:
        Logger(){
            std::cout << "Logger is created \n";
        }

        ~Logger(){
            std::cout << "Logger is destroyed \n";
        }
        //static Logger * s_logger; // We cannot initialize a static instance inside the class.
        std::vector<std::string> logger_array;
};

//Logger *Logger::s_logger = NULL; // We are able to instantiate here // We dont want to do it here. 

int main(){
    Logger * l = &Logger::getInstance();
    l->addMessage("First message");
    l->addMessage("Second message");
    l->addMessage("Third message");
    l->printMessages();

    //delete l; We cannot delete the instance since it is private
    return 0;
}