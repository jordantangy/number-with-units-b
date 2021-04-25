#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
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
        
        
        public:
        friend NumberWithUnits& operator+(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend const NumberWithUnits& operator+(const NumberWithUnits& nwu);
        friend NumberWithUnits& operator+=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend NumberWithUnits& operator-(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend NumberWithUnits& operator-(const NumberWithUnits& nwu);
        friend NumberWithUnits& operator-=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        //postfix
        NumberWithUnits& operator++(int);
        NumberWithUnits& operator--(int);
        //prefix
        friend NumberWithUnits& operator++(NumberWithUnits& nwu);
        friend NumberWithUnits& operator--(NumberWithUnits& nwu);

        friend bool UnitExists(const string& u1,const string& u2);
        friend bool operator>(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator>=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator<(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator<=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator==(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
        friend bool operator!=(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2) ;
        double ruleOfThree(double first, double second);

        friend NumberWithUnits operator*(const NumberWithUnits &nwu,const double &num);
        friend NumberWithUnits operator*(const double &num,const NumberWithUnits &nwu);

        friend ostream& operator<<(ostream& os,const NumberWithUnits& nwu);
        friend istream& operator>>(istream& is,NumberWithUnits& nwu){
            
            string unit;
            string e = " ";
            double num;
            is >>num>>e>>unit>>e;
            nwu.num = num;
            nwu.unit = unit;
            return is;
        }

        static void read_units(ifstream& file){
            if (!file) {
	            throw "file not found";
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
            for (size_t i = 0; i < v.size(); i++)
            {
                for (size_t j = 0; j < v[i].size(); j++)
                {
                    cout << v[i][j] ;
                }
                cout << " " << endl;
                
            }
            
            file.close();
        }
        friend bool unitsMatch(const string& unit1,const string& unit2);
        friend bool related(const string& unit1,const string& unit2);
        friend bool leftToRight(const string& u1, const string& u2);
        friend double rightToLeft(const string& u1, const string& u2);
        friend bool sameFamily(const string& u1, const string& u2);
        friend NumberWithUnits& convert(const NumberWithUnits& nwu1,const NumberWithUnits& nwu2);
    };
    

}

