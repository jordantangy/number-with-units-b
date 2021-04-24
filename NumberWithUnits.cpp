#include <iostream>
#include "NumberWithUnits.hpp"
#include <stdexcept>
#include <vector>
#include <cstdlib>
#include <algorithm>

const double epsylon = 0.001;
namespace ariel{


bool unitsMatch(const string& unit1,const string& unit2) {
    return (unit1 == unit2);
}
// bool related(const string& unit1,const string& unit2){
//     for(auto line : ariel::NumberWithUnits::v){
//         if(find(line.begin(),line.end(),unit1) != line.end()){
//             if(find(line.begin(),line.end(),unit2) != line.end()){
//                 return true;
//             }
//         }
//     }
//     return false;
    
// }
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
    double ans;
    for (size_t i = 0; i < ariel::NumberWithUnits::v.size(); i++)
    {
        if(ariel::NumberWithUnits::v[i][1] == u1 && ariel::NumberWithUnits::v[i][4] == u2){
            ans =  stod(ariel::NumberWithUnits::v[i][3]);
            break;
        }
    }
    return ans;
}


NumberWithUnits& operator+(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2){
    NumberWithUnits *temp = new NumberWithUnits();
    vector<string> vec;
    if(UnitExists(nwu1.unit,nwu2.unit)){
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
            else if(!leftToRight(nwu1.unit,nwu2.unit)){
                temp->num = nwu1.num+(nwu2.num/rightToLeft(nwu1.unit,nwu2.unit));
            }
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