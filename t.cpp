#include <iostream>
#include "NumberWithUnits.hpp"
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>
#include <map>

 set<string> path;

void findPath(string& from, string& to){
    if(from == to){
      return ;
    }

      for(auto line : ariel::NumberWithUnits::v){
          if(from == line[1]){
            path.insert(line[4]);
            return findPath(line[4],to);
          }
          if(from == line[4]){
            path.insert(line[1]);
            return findPath(line[1],to);
          }
        }
}

int main(){
// ifstream units_file{"unitss.txt"};
//   ariel::NumberWithUnits::read_units(units_file);
//   ariel::NumberWithUnits a{1,"min"};
//   ariel::NumberWithUnits b{5,"day"};
//   findPath(b.unit,a.unit);
//   for(auto i : path){
//     cout << i << endl;
//   }
    // for (size_t i = 0; i < ariel::NumberWithUnits::v.size(); i++)
    // {
    //     for (size_t j = 0; j < ariel::NumberWithUnits::v[i].size(); j++)
    //     {
    //         cout << ariel::NumberWithUnits::v[i][j];
    //     }
    //     cout << " " << endl;
    // }


    map< string, map<string,double>> units;
    string km = "km";
    map<string,double> a;
    a.insert({"m",1000.0});
    units.insert({km,a});
    map<string,double> b;
    b = units[km];
    string unit = b.begin()->first;
    cout << unit << endl;
    
    
}