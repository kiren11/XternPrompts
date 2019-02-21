//Written by Kiren Kaur


#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>

//take it out of the vector if you find two matching values
//vector is better becasue it is dynamic and dont know how many things you're going to put in
//at the end of iterating, if there is a value that is remaining, print it out
//otherwise print out a zero

int main() {

      std::string line;
      int values;
      int n;

      //vector used to hold all of the input values
      std::vector<int> processes;

      //TODO: if the user does not input a number, throw an exception

      //get values, stores them in the vector called processes
      std::cout<<"Please enter the values of the processes: "<<std::endl;

      while(std::getline(std::cin, line) && !line.empty()) {
          std::istringstream ss(line);
          ss >> values;

          if(!std::cin.good()) {
            std::cout<<"Please enter numerical values for the processes."<<std::endl;
          }

          //if there is already a matching value in the vector
          //erase that value
          if(std::find(processes.begin(), processes.end(), values) != processes.end()) {
            processes.erase(std::remove(processes.begin(), processes.end(), values), processes.end());
          } else  {
            //if it doesnt exist in the vector, push it to the vector
            processes.push_back(values);
          }
    }

    //print everything left in the vector
    for (int i = 0; i < processes.size(); i++) {
      std::cout<<"Unfinished processes: "<<std::flush;
      std::cout<<processes[i]<<std::endl;
    }

    //if all elements have a match, it will return that there are no unfinished processes
    if(processes.empty()) {
      std::cout<<"No unfinished processes"<<std::endl;
    }
    std::cout<<"Unfinished process: "<<std::flush;

}
