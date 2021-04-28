#include <iostream>
#include "NumberWithUnits.hpp"
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <bits/stdc++.h>
#include <algorithm>

const double epsylon = 0.000001;
map<string , map<string,double>> ariel::NumberWithUnits::mapUnits ;
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

double fromTo(const string& from, const string& to) {
    if(from != to) {
        return ariel::NumberWithUnits::mapUnits[from][to];
    }
    return 1.0;  
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

NumberWithUnits convert(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){

    NumberWithUnits n{nwu1.num,nwu1.unit};
    vector<string> vec;
    for(auto line : ariel::NumberWithUnits::v){
        if(find(line.begin(),line.end(),nwu2.unit) != line.end() && 
            find(line.begin(),line.end(),nwu1.unit) != line.end() ) {
            vec = line;
            break;
        }
    }
    n.unit = nwu2.unit;
    if(leftToRight(nwu2.unit,nwu1.unit)){
        n.num = nwu1.num*stod(vec[3]);
    }
    else if(!leftToRight(nwu2.unit,nwu1.unit) && (related(nwu1.unit,nwu2.unit))){
        n.num = nwu1.num/rightToLeft(nwu2.unit,nwu1.unit);
    }
    else{
        n.num = nwu1.num*fromTo(nwu1.unit,nwu2.unit);
    }
    return n;
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
    for(const auto& unit: s){
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


NumberWithUnits operator+(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){

    NumberWithUnits n{nwu1.num,nwu1.unit};
    vector<string> vec;
    if(UnitExists(nwu1.unit,nwu2.unit) && (sameFamily(nwu1.unit,nwu2.unit))){
        if(unitsMatch(nwu1.unit,nwu2.unit)){
            n.num = nwu1.num + nwu2.num;
        }
        else{
            for(auto line : ariel::NumberWithUnits::v){
                if(find(line.begin(),line.end(),n.unit) != line.end() && 
                    find(line.begin(),line.end(),nwu2.unit) != line.end()){
                    vec = line;
                    break;
                }
            }
            if(leftToRight(nwu1.unit,nwu2.unit)){
                n.num = nwu1.num+(stod(vec[3])*nwu2.num);
            }
            else if(!leftToRight(nwu1.unit,nwu2.unit) && (related(nwu1.unit,nwu2.unit))){
                n.num = nwu1.num+(nwu2.num/rightToLeft(nwu1.unit,nwu2.unit));
            }
            else{
                n.num = nwu1.num+(fromTo(nwu2.unit,nwu1.unit) * nwu2.num);
            }       
        }
    }
    else{
     throw invalid_argument("Units do not match ["+nwu1.unit+"] cannot be converted to ["+nwu2.unit+"]");
    }
    return n;
    
}
const NumberWithUnits& operator+(const NumberWithUnits& nwu) {
    return nwu;
}
NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits& nwu){
    if(!sameFamily(unit,nwu.unit)){
        throw invalid_argument("Error");
    }
    num = num +fromTo(nwu.unit,unit)*nwu.num;
    return *this;
}

NumberWithUnits operator-(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    vector<string> vec;
    NumberWithUnits n{nwu1.num,nwu1.unit};
    if(UnitExists(nwu1.unit,nwu2.unit) && (sameFamily(nwu1.unit,nwu2.unit))){
        if(unitsMatch(nwu1.unit,nwu2.unit)){
            n.num = nwu1.num - nwu2.num;
        }
        else{
            for(auto line : ariel::NumberWithUnits::v){
                if(find(line.begin(),line.end(),n.unit) != line.end() && 
                    find(line.begin(),line.end(),nwu2.unit) != line.end()){
                    vec = line;
                    break;
                }
            }
            if(leftToRight(nwu1.unit,nwu2.unit)){
                n.num = nwu1.num-(stod(vec[3])*nwu2.num);
            }
            else if(!leftToRight(nwu1.unit,nwu2.unit) && (related(nwu1.unit,nwu2.unit))){
                n.num = nwu1.num-(nwu2.num/rightToLeft(nwu1.unit,nwu2.unit));
            }
            else{
                n.num = nwu1.num - (fromTo(nwu2.unit,nwu1.unit) * nwu2.num);
            }
        }
    }
    else{
     throw invalid_argument("Units do not match ["+nwu1.unit+"] cannot be converted to ["+nwu2.unit+"]");
    }
    return n;
}


NumberWithUnits operator-(const NumberWithUnits& nwu){
    NumberWithUnits n{-nwu.num,nwu.unit};
    return n;
}


NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits& nwu){
    if(!sameFamily(unit,nwu.unit)){
        throw invalid_argument("Error");
    }
    num = num -fromTo(nwu.unit,unit)*nwu.num;
    return *this;
}

NumberWithUnits& operator++(NumberWithUnits& nwu) {
    nwu.num++;
    return nwu;
}
NumberWithUnits& operator--(NumberWithUnits& nwu){
    nwu.num--;
    return nwu;
}
bool operator>(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){

    if(!sameFamily(nwu1.unit,nwu2.unit)){
        throw invalid_argument("Cannot compare those units");
    }
     if(nwu1.unit == nwu2.unit){
         if(nwu1.num > nwu2.num){
             return true;
         }
     }
     else{
         double coeff = fromTo(nwu1.unit,nwu2.unit);
         if(nwu1.num*coeff > nwu2.num){
             return true;
        }
     }
    return false;
}
bool operator>=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){

    return ((nwu1 == nwu2) || (nwu1 >nwu2));
}
bool operator<(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
  if(!sameFamily(nwu1.unit,nwu2.unit)){
        throw invalid_argument("Cannot compare those units");
    }
     if(nwu1.unit == nwu2.unit){
         if(nwu1.num < nwu2.num){
             return true;
         }
     }
     else{
         double coeff = fromTo(nwu1.unit,nwu2.unit);
         if(nwu1.num*coeff < nwu2.num){
             return true;
        }
     }  
     return false;
}
bool operator<=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    if(!sameFamily(nwu1.unit,nwu2.unit)){
        throw invalid_argument("Cannot compare those units");
    }
     if(nwu1.unit == nwu2.unit){
         if(nwu1.num <= nwu2.num){
             return true;
         }
     }
     else{
         double coeff = fromTo(nwu1.unit,nwu2.unit);
         if(nwu1.num*coeff <= nwu2.num){
             return true;
        }
     }  
     return false;
}
bool operator==(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2) {
    if(!sameFamily(nwu1.unit,nwu2.unit)){
        throw invalid_argument("Cannot compare those units");
    }
    if(nwu1.unit != nwu2.unit){
        if(sameFamily(nwu1.unit,nwu2.unit)){
            NumberWithUnits toCheck = convert(nwu1,nwu2);
            return (unitsMatch(toCheck.unit,nwu2.unit) && (abs(toCheck.num-nwu2.num))<epsylon);
        }
    }
    return (unitsMatch(nwu1.unit,nwu2.unit) && (abs(nwu1.num-nwu2.num))<epsylon);
}
bool operator!=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    if(!sameFamily(nwu1.unit,nwu2.unit)){
        throw invalid_argument("Cannot compare those units");
    }
     if(nwu1.unit == nwu2.unit){
         if(nwu1.num != nwu2.num){
             return true;
         }
     }
     else{
         double coeff = fromTo(nwu1.unit,nwu2.unit);
         if(nwu1.num*coeff != nwu2.num){
             return true;
        }
     }  
     return false;
}

NumberWithUnits operator*(const NumberWithUnits &nwu,const double &num){

    NumberWithUnits n{nwu.num*num,nwu.unit};
    return n;
}

NumberWithUnits operator*(const double &num,const NumberWithUnits& nwu){
    return nwu*num;
}
NumberWithUnits operator++(NumberWithUnits& nwu,int postfix){
    NumberWithUnits n = NumberWithUnits(nwu);
    ++nwu;
    return n;
}
NumberWithUnits operator--(NumberWithUnits& nwu, int postfix){
    NumberWithUnits n = NumberWithUnits(nwu);
    --nwu;
    return n;
}
ostream& operator<<(ostream& os,const NumberWithUnits& nwu) {
    os << nwu.num << ""<< "["+nwu.unit+"]";
    return os;
}
void ariel::NumberWithUnits::convUnit(const string& from, const string& to){
        for(auto& elem: ariel::NumberWithUnits::mapUnits[to]){
            if(elem.first != from){
                double number = ariel::NumberWithUnits::mapUnits[from][to]*elem.second;
                ariel::NumberWithUnits::mapUnits[from][elem.first] = number;
                ariel::NumberWithUnits::mapUnits[elem.first][from] = 1.0/number;
            }
        }
    }

void ariel::NumberWithUnits::read_units(ifstream& file){
            if (!file) {
	            throw invalid_argument("file not found");
	        }
            char delimiter = ' ';
            string s;
            string h;
            vector<string> vec;
            while(getline(file,s)){
                for (size_t i = 0; i < s.size(); i++)
                {   
                    if(s.at(i) != delimiter){
                        h.push_back(s.at(i));
                        if( i == s.size()-1){
                            vec.push_back(h);
                            h.clear();
                        }
                    }
                    else{
                    vec.push_back(h);
                    h.clear();
                    }
                }
                ariel::NumberWithUnits::v.push_back(vec);
                vec.clear();
                h.clear();  
            }
            file.clear();
            mapAllCombs(file);
        
        }
    void ariel::NumberWithUnits::mapAllCombs(ifstream& file){
        file.seekg(0);
        if(!file.is_open()) {
            return;
        }
        string one, from , to;
        double value =0 ;
        while(!file.eof()){
            file>>one>>from>>one>>value>>to;  
            ariel::NumberWithUnits::mapUnits[from][to] = value;
            ariel::NumberWithUnits::mapUnits[to][from] = 1.0/value;
            convUnit(from,to);   
            convUnit(to,from);
        }
    
        file.close();
    }

std::istream& operator>>(std::istream& input, NumberWithUnits &nwu){
    string s, unit; 
    double num;
    input >> num;
    getline(input, s,']'); 
    char space = ' ';
    char open = '[';
    char close = ']';
    for (size_t i = 0; i < s.size(); i++)
    {
        if(s[i] != open && s[i] != close &&  s[i] != space ){
            unit.push_back(s[i]);
        }
    }
    nwu.num = num;
    nwu.unit = unit;
    if(ariel::NumberWithUnits::mapUnits.find(unit)== ariel::NumberWithUnits::mapUnits.end()){
        throw invalid_argument("This unit does not exist in the list");
    }
    return input;
}
            
    
}