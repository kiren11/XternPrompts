#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stack>
#include <iomanip>

//AU = Absolute URL
//AP = Absolute Path
//RP = Relative Path


int main() {

    //TODO: if an absolute url is not entered first, throw an errors

    int step = 0;
    char choice = true;
    int num;

    std::string updatedSite;
    std::string operation;

    //create a stack to store the addresses + operations
    std::stack<std::string> site;

    //temp array used for printing
    std::stack<std::string> temp;

    //to print the stack in reverse (temp stack)
    std::stack<std::string> reverseS;

    std::cout<<"|------------------------------------------------|"<<std::endl;
    std::cout<<"|              WELCOME TO NETXTERN               |"<<std::endl;
    std::cout<<"|------------------------------------------------|"<<std::endl<<std::endl;


    std::cout<<"If at any point you would like to quit, enter Q"<<std::endl;

    //keep going until the user wants to quit
    while (choice) {

        std::string linkType;

        std::cout<<"Please enter an operation: "<<std::flush;
        std::cin>>operation;

        std::cout<< " "<<std::endl;

        //if the operation is an Absolute URL push it onto the stack
        if(operation.find("https://") != std::string::npos) {
            linkType = ("Absolute URL");

            //if stack is empty, no AU before it, so push
            if(site.empty()) {
              site.push(operation);
            //otheriwse pop AU off, and push new AU
            } else {
              //TODO: write a while loop so that it pops til only 1 elements is left
                while(site.size() != 0) {
                  site.pop();
                }
              site.push(operation);
            }

        //if first character is a forward slash, its an absolute path
        } else if ((operation.find_first_of("/") ) != std::string::npos) {
            linkType = ("Absolute Path");

            // std::cout<<site.size()<<std::endl;

            num = site.size();

            //if AU present, push AP
            site.push(operation);

            //TODO: if AP existing, pop off, and push onto just AU

            // while(num != 2) {
            //   site.pop();
            //   num--;
            //   site.push(operation);
            // }



        } else {
            linkType = ("Relative Path");
            site.push("/");
            site.push(operation);

            //accounts for FORWARD and BACK cases
            if((operation == "BACK")) {
              linkType = ("");
            } else if (operation == "FORWARD") {
              linkType = ("");
            } else {
              // choice = false;
            }
        }

        step++;

        //printing
        std::cout<<std::setw(8) << std::left << "Step: " <<
                  std::setw(20) << std::left << "Operation:" <<
                  std::setw(15) << std::left << "Link Type:" <<
                  std::setw(10) << std::left << "Set Browswer Content To: " <<std::endl;

        std::cout<<std::setw(8) << std::left << step <<
                  std::setw(20) << std::left << operation <<
                  std::setw(15) << std::left << linkType << std::flush;

        //copy to a temporary stack (so it doesnt pop actual stack to print)
        for (temp = site; !temp.empty(); temp.pop()) {
                std::cout << temp.top() << std::flush;
        }

        std::cout<<" "<<std::endl;

        // //these 2 while loops -> to print in reverse order
        // while (!temp.empty()) {
        //   temp.push(reverseS.top());
        //   temp.pop();
        // }
        // while (!temp.empty()) {
        //   std::cout << reverseS.top() << '\n';
        //   reverseS.pop();
        // }


    }
}
