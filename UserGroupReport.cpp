#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm> //std::sort

//ATEMPT - to organzie alphabetically, a better solution would've been to put in a set as a container in the map, that
//way the values would sort as inserted

int main() {

      bool moreData = true;
      std::string line;

      //input data
      std::string name;
      std::string group;

      //map that will contain group keys, and names
      std::multimap<std::string, std::string> Groups;
      std::multimap<std::string, std::string>::iterator it;


      //map that will contain group keys, and names
      // std::map<std::string, std::set<std::string> > Groups;
      // std::map<std::string, std::string>::iterator it;

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

        std::cout << " "<<std::endl;

        for (it = Groups.begin(); it != Groups.end(); ++it) {
            std::cout<< "Group: " << (*it).first << " Members: " << (*it).second<<std::endl;
         }

         std::cout << " "<<std::endl;


         //atempt to print out set as a part of map:

      //    for(it = Groups.begin(); it != Groups.end(); ++it) {
      //           std::cout<<"For group: "<<it->first<<": {"; //it->first gives you the key of the map.

      //    for (std::set<std::string>::iterator itr = it->second.begin(); itr!=it->second.end(); itr++) {
      //         std::cout<<*itr<<std::endl;
      //           std::cout<<"}\n";
      //    }
      //  }
    }
  }
