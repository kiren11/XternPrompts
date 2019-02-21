#include <cstdlib>
#include <iostream>
#include <list>
#include <iomanip>
#include <iterator>
#include <ostream>
#include <algorithm>
#include <stack>

//AU = Absolute URL
//AP = Absolute Path
//RP = Relative Path

int main() {

    //TODO: if an absolute url is not entered first, throw an error

    int step = 0;
    char choice = true;
    int num;

    //doubly linked list data structure used
    std::list<std::string> site;

    //will be used for forward operation, keeps track of each time user went back
    std::stack<std::string> back;

    std::string updatedSite;
    std::string operation;

    std::cout<<"|------------------------------------------------|"<<std::endl;
    std::cout<<"|              WELCOME TO NETXTERN               |"<<std::endl;
    std::cout<<"|------------------------------------------------|"<<std::endl<<std::endl;

    std::cout<<"If at any point you would like to quit, enter Q"<<std::endl;

    //keep going until the user wants to quit
    while (choice) {

        //used to determine the type of path
        std::string linkType;

        std::cout<<"Please enter an operation: "<<std::flush;
        std::cin>>operation;

        std::cout<< " "<<std::endl;


        //if the operation is an Absolute URL push it onto the stack
        if(operation.find("https://") != std::string::npos) {
            linkType = ("Absolute URL");

            //if stack is empty, no AU before it, so push
            if(site.empty()) {
              site.push_back(operation);

            //otheriwse pop AU off, and push new AU
            } else {

                while(site.size() != 0) {
                  site.pop_back();
                }
              site.push_back(operation);
              back.push(operation);
            }

        //if first character is a forward slash, its an absolute path
        } else if ((operation.find_first_of("/") ) != std::string::npos) {
            linkType = ("Absolute Path");

            //if AU present, push AP
            site.push_back(operation);

            back.push(operation);
            //if another AP exists, pop off everything except AU, then push on
            while(site.size() != 1) {
              site.pop_back();
            }
            site.push_back(operation);

        } else {

            linkType = ("Relative Path");
            site.push_back("/" + operation);

            back.push(operation);

            //accounts for FORWARD and BACK cases
            if((operation == "BACK")) {
              linkType = ("");
              site.pop_back();

              std::string x = site.back();
              site.pop_back();

                  // to account for if the user tries to go back before AU (not necessary)
                  // if(site.empty() ) {
                  //   site.push_back(AU);
                  // }

            //FORWARD doesnt completely work
                //attempt -> use a stack to push each back operation onto it, then pop the last operation before forward
            } else if (operation == "FORWARD") {
              linkType = ("");
              site.push_back(linkType);

              back.pop();
              back.pop();
            }
        }
        step++;

        std::cout<<std::setw(8) << std::left << "Step: " <<
                  std::setw(20) << std::left << "Operation:" <<
                  std::setw(15) << std::left << "Link Type:" <<
                  std::setw(10) << std::left << "Set Browswer Content To: " <<std::endl;

        std::cout<<std::setw(8) << std::left << step <<
                  std::setw(20) << std::left << operation <<
                  std::setw(15) << std::left << linkType << std::flush;

        //iterates through, and prints the final URL
        for (std::list<std::string>::iterator i = site.begin(); i != site.end(); ++i) {
            std::cout << *i << std::flush;
          }

        //breaks
        std::cout<<" "<<std::endl;
        std::cout<<" "<<std::endl;
    }
}
