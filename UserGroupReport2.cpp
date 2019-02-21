#include <cstdlib>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm> //std::sort

//TODO: make sure to delete at the endl

int main() {

      bool moreData = true;

      std::string line;

      //input data
      std::string name;
      std::string group;

      //map that will contain group keys, and names
      std::map<std::string, std::string> Groups;
      std::map<std::string, std::string>::iterator it;
      std::map<std::string, std::string>::iterator vitr;

      std::map< std::string, std::vector< std::string > > map;

      // std::vector<std::pair<group, name>> items;

      while(moreData = true) {

        std::cout<<"Please enter name of user first, then group name"<<std::endl;
        std::cin>>name;
        std::cin>>group;


        //make pair, insert into multimap
        Groups.insert(make_pair(group, name));

        //if no more input, ask if user would like to enter more data
        if(!line.empty()) {
          std::cout<<"Would you like to insert more data? (y/n)"<<std::endl;
          std::cin>>moreData;
            if(moreData == 'n' || moreData == 'N') {
              moreData = false;
            }
        }

        for(it = map.begin(); it!=map.end(); it++) {
      std::cout<<it->first<<":";
      for(vitr = it->second.begin(); vitr != it->second.end(); vitr++){
          std::cout<<*vitr<<","<<std::endl;

        std::cout << " "<<std::endl;

        // for (it = Groups.begin(); it != Groups.end(); ++it) {
        //     std::cout<< "Group: " << (*it).first << " Members: " << (*it).second<<std::endl;
        //
        //  }
        //
        //  std::cout << " "<<std::endl;
        //
        // }
      }
    }
  }
}
