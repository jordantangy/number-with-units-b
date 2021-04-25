#include <iostream>
#include "NumberWithUnits.hpp"
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>

const double epsylon = 0.001;
namespace ariel{

bool leftToRight(const string& u1, const string& u2){
    for (size_t i = 0; i < ariel::NumberWithUnits::v.size(); i++)
    {
        if(ariel::NumberWithUnits::v[i][1] == u2 && ariel::NumberWithUnits::v[i][4] == u1){
            return true;
        }
    }
    return false;
}
double rightToLeft(const string& u1, const string& u2){
    double ans = 1;
    for (size_t i = 0; i < ariel::NumberWithUnits::v.size(); i++)
    {
        if(ariel::NumberWithUnits::v[i][1] == u1 && ariel::NumberWithUnits::v[i][4] == u2){
            ans =  stod(ariel::NumberWithUnits::v[i][3]);
            break;
        }
    }
    return ans;
}


bool unitsMatch(const string& unit1,const string& unit2) {
    return (unit1 == unit2);
}
bool UnitExists(const string& u1,const string& u2){
    for (size_t i = 0; i < ariel::NumberWithUnits::v.size(); i++)
    {
        if(ariel::NumberWithUnits::v[i][1] == u1 || ariel::NumberWithUnits::v[i][4] == u1 || 
            ariel::NumberWithUnits::v[i][1] == u2 || ariel::NumberWithUnits::v[i][4] == u2 ){
            return true;
        }
    }
    return false;   
}

NumberWithUnits& convert(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    NumberWithUnits *temp = new NumberWithUnits();
    vector<string> vec;
    for(auto line : ariel::NumberWithUnits::v){
        if(find(line.begin(),line.end(),nwu2.unit) != line.end()){
            vec = line;
        }
    }
    temp->unit = nwu2.unit;
    if(leftToRight(nwu2.unit,nwu1.unit)){
        temp->num = nwu1.num*stod(vec[3]);
        return *temp;
    }
    else {
        temp->num = nwu1.num+(nwu2.num/rightToLeft(nwu1.unit,nwu2.unit));
    }
    return *temp;
}


bool related(const string& unit1,const string& unit2){
    
    for(auto line : ariel::NumberWithUnits::v){
        if(find(line.begin(),line.end(),unit1) != line.end()){
            if(find(line.begin(),line.end(),unit2) != line.end()){
                return true;
            }
        }
    }
    return false;
}
bool sameFamily(const string& u1, const string& u2){
    vector<vector<string>> extract;
    //look for u1 in the unit matrix
    for(auto line : ariel::NumberWithUnits::v){
        if(find(line.begin(),line.end(),u1) != line.end()){
                    extract.push_back(line);
            }
    }
    vector<vector<string>> copy = extract;
    //the for loop returns at least one line, we extract the units we
    //are looking for and then add to the extract vector the related 
    //equalities between different units
    set<string> s;
    for (size_t i = 0; i < extract.size(); i++)
    {
        string u1_tofind = extract[i][1];
        string u2_tofind = extract[i][4];
        for(auto line : ariel::NumberWithUnits::v){
            if(find(line.begin(),line.end(),u1_tofind) != line.end() || 
                find(line.begin(),line.end(),u2_tofind) != line.end() ){
                    copy.push_back(line);
            }
        }
    }
    for (size_t i = 0; i < copy.size(); i++)
    {
        s.insert(copy[i][1]);
        s.insert(copy[i][4]);
    }
    for(auto unit : s){
        for(auto line : ariel::NumberWithUnits::v){
            if(find(line.begin(),line.end(),unit) != line.end()){
                copy.push_back(line);
            }
        }
    }
    copy.erase(std::unique(copy.begin(), copy.end()), copy.end());
    //seach for the second given units in the extract matrix
    for(auto line : copy){
         if(find(line.begin(),line.end(),u2) != line.end()){
             return true;
        }
          
      }
    return false;
}


NumberWithUnits& operator+(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    NumberWithUnits *temp = new NumberWithUnits();
    vector<string> vec;
    if(UnitExists(nwu1.unit,nwu2.unit) && (sameFamily(nwu1.unit,nwu2.unit))){
        temp->unit = nwu1.unit;
        if(unitsMatch(nwu1.unit,nwu2.unit)){
            temp->num = nwu1.num + nwu2.num;
            return *temp;
        }
        else{
            for(auto line : ariel::NumberWithUnits::v){
                if(find(line.begin(),line.end(),temp->unit) != line.end()){
                    vec = line;
                }
            }
            if(leftToRight(nwu1.unit,nwu2.unit)){
                temp->num = nwu1.num+(stod(vec[3])*nwu2.num);
                return *temp;
            }
            else if(!leftToRight(nwu1.unit,nwu2.unit) && (related(nwu1.unit,nwu2.unit))){
                temp->num = nwu1.num+(nwu2.num/rightToLeft(nwu1.unit,nwu2.unit));
            }
            // else if(!leftToRight(nwu1.unit,nwu2.unit) && (!related(nwu1.unit,nwu2.unit))){
            //     // vector<vector<string>> extract;
            //     // for(auto line : ariel::NumberWithUnits::v){
            //     //     if(find(line.begin(),line.end(),nwu1.unit) != line.end() ||
            //     //         (find(line.begin(),line.end(),nwu2.unit) != line.end())){
            //     //         extract.push_back(line);
            //     //     }
            //     // }
                
                

            // }
        }
    }
    else{
     throw invalid_argument("Units do not match ["+nwu1.unit+"] cannot be converted to ["+nwu2.unit+"]");
    }
    return *temp;
}
const NumberWithUnits& operator+(const NumberWithUnits& nwu) {
    return nwu;
}
NumberWithUnits& operator+=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    NumberWithUnits *temp = new NumberWithUnits();
    return *temp;
}
NumberWithUnits& operator-(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    if((!UnitExists(nwu1.unit,nwu2.unit)) ){
        throw invalid_argument("the units are not matching");
    }
    NumberWithUnits *temp = new NumberWithUnits();
    return *temp;
}
NumberWithUnits& operator-(const NumberWithUnits& nwu){
    NumberWithUnits *temp = new NumberWithUnits();
    return *temp;
}
NumberWithUnits& operator-=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    NumberWithUnits *temp = new NumberWithUnits();
    return *temp;
}

NumberWithUnits&  NumberWithUnits::operator++(int) {
    this->num++;
    return *this;
}
NumberWithUnits&  NumberWithUnits::operator--(int){
    this->num--;
    return *this;
}
 bool operator>(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    return true;
}
bool operator>=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    return true;
}
bool operator<(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    return true;
}
bool operator<=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    return true;
}
bool operator==(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2) {
    if(nwu1.unit != nwu2.unit){
        if(sameFamily(nwu1.unit,nwu2.unit)){
            NumberWithUnits toCheck = convert(nwu1,nwu2);
             return (unitsMatch(toCheck.unit,nwu2.unit) && (abs(toCheck.num-nwu2.num))<epsylon);
        }
    }
    return (unitsMatch(nwu1.unit,nwu2.unit) && (abs(nwu1.num-nwu2.num))<epsylon);
}
bool operator!=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    return true;
}

NumberWithUnits operator*(const NumberWithUnits &nwu,const double &num){
    NumberWithUnits *temp = new NumberWithUnits();
    temp->num =num*nwu.num;
    temp->unit = nwu.unit;
    return *temp;
}
NumberWithUnits operator*(const double &num,const NumberWithUnits& nwu){
    return nwu*num;
}
NumberWithUnits& operator++(NumberWithUnits& nwu){
    NumberWithUnits *temp = new NumberWithUnits();
    temp->num =nwu.num+1;
    temp->unit = nwu.unit;
    return *temp;

}
NumberWithUnits& operator--(NumberWithUnits& nwu){
    NumberWithUnits *temp = new NumberWithUnits();
    temp->num =nwu.num-1;
    temp->unit = nwu.unit;
    return *temp;

}
ostream& operator<<(ostream& os,const NumberWithUnits& nwu) {
    os << nwu.num << " " << "["+nwu.unit+"]";
    return os;
}

}