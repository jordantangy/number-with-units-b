#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;



namespace ariel{
    
    class NumberWithUnits{
        public:
        double num;
        string unit;
        static inline vector<vector<string>> v;
        
        NumberWithUnits(){}
        NumberWithUnits(double num, string unit):num(num){
            set_unit(unit);
        }
        NumberWithUnits& set_unit(string& unit) {
        for (auto line : v){
        if(find(line.begin(),line.end(),unit) != line.end()){
                    this->unit = unit;
                    return *this;
                }
            }
            throw invalid_argument("The specified unit does not exist in the file");
        }
        NumberWithUnits(const NumberWithUnits& nwu):num{nwu.num},unit{nwu.unit}{}
        
        
        public:
        friend NumberWithUnits& operator+(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend const NumberWithUnits& operator+(const NumberWithUnits& nwu);
        NumberWithUnits operator+=(const NumberWithUnits& num);
        friend NumberWithUnits& operator-(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend NumberWithUnits& operator-(const NumberWithUnits& nwu);
        NumberWithUnits operator-=(const NumberWithUnits& num);
        //prefix
        friend NumberWithUnits& operator++(NumberWithUnits& nwu);
        friend NumberWithUnits& operator--(NumberWithUnits& nwu);
        //postfix
        friend NumberWithUnits operator++(NumberWithUnits& nwu,int postfix);
        friend NumberWithUnits operator--(NumberWithUnits& nwu,int postfix);

        friend bool UnitExists(const string& u1,const string& u2);
        friend bool operator>(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator>=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator<(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator<=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator==(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator!=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2) ;
        

        friend NumberWithUnits operator*(const NumberWithUnits &nwu,const double &num);
        friend NumberWithUnits operator*(const double &num,const NumberWithUnits &nwu);
        friend double convert_from_to(const std::string& from, const std::string& to);
        friend ostream& operator<<(ostream& os,const NumberWithUnits& nwu);
        static void convertNumType(std::string from_type, std::string to_type);
        friend istream& operator>> (std::istream& input, NumberWithUnits& nwu);
        static void read_units(ifstream& file);
         
        
        friend bool unitsMatch(const string& unit1,const string& unit2);
        friend bool related(const string& unit1,const string& unit2);
        friend bool leftToRight(const string& u1, const string& u2);
        friend double rightToLeft(const string& u1, const string& u2);
        friend bool sameFamily(const string& u1, const string& u2);
        friend NumberWithUnits& convert(NumberWithUnits& nwu1,NumberWithUnits& nwu2);
        static void mapAllCombs(ifstream& file);
         
        
    };
    

}

