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

string s = "gref";
string t;
for (size_t i = 0; i < count; i++)
{
  /* code */
}

    
}