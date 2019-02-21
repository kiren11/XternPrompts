
#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <ctime>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>

int main() {

  std::string line;
  int values;

  //vector used to hold all of the input values
  std::vector<int> processes;

  //TODO: if the user does not input a number, throw an exception

  //get values, stores them in the vector called processes
  std::cout<<"Please enter the values of the processes: "<<std::endl;

  while(std::getline(std::cin, line) && !line.empty()) {
      std::istringstream ss(line);
      ss >> values;
      processes.push_back(values);
  }

  for(int i = 0; (i < processes.size() - 1); i++ ) {
    bool match = false;

    for(int j = i + 1; j < processes.size(); j++)
        if(processes[i] == processes[j]) {
          std::cout<<processes[i]<<"      Start"<<std::endl;
          std::cout<<processes[j]<<"      Finish"<<std::endl<<std::endl;
          match = true;

      if(processes[i] != processes[j]) {
        std::cout<<processes[i]<<"      Start"<<std::endl;
        std::cout<<processes[j]<<"      Start"<<std::endl;
      }
    }
  }
}
