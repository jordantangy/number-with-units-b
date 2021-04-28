/**
 * 
 * 
 * Tests for Ex3 - NumberWithUnits
 * AUTHORS: Name of Author: Yair Raviv
 * 
 * Date: 2021-04
 */
#include <iostream>
#include<string>
#include <fstream>
#include <sstream>
#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <stdexcept>
using namespace ariel;
using namespace std;


  
TEST_CASE("Comperators") 
{
    ofstream File("units.txt");

    File << "1 km = 1000 m" << endl;
    File << "1 m = 100 cm" << endl;
    File << "1 cm = 10 mm" << endl;
    File << "1 kg = 1000 g" << endl;
    File << "1 ton = 1000 kg" << endl;
    File << "1 g = 1000 mg" << endl;
    File << "1 hour = 60 min" << endl;
    File << "1 min = 60 sec" << endl;
    File << "1 EUR = 4.5 ILS" << endl;
    File << "1 USD = 3.33 ILS ";

    // Close the file
    File.close();
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    //////////////////////////////////////////////////////// operators '==' , '>=' , '<=' ////////////////////////////////////////////////
    
    //Distances
    NumberWithUnits km_1(1 , "km");
    NumberWithUnits m_1000(1000 , "m");
    NumberWithUnits cm_100000(100000 , "cm");

    //Weights
    NumberWithUnits ton_1(1 , "ton");
    NumberWithUnits kg_1000(1000 , "kg");
    NumberWithUnits g_1000000(1000000 , "g");
    NumberWithUnits mg_1000000000(1000000000 , "mg");

    //Coins
    NumberWithUnits EUR_10(10,"EUR");
    NumberWithUnits USD_100(100,"USD");
    NumberWithUnits ILS_45(45,"ILS");
    NumberWithUnits ILS_333(333,"ILS");

    //Time units
    NumberWithUnits hour_1(1 , "hour");
    NumberWithUnits min_60(60 , "min");
    NumberWithUnits sec_3600(3600 , "sec");


    //Tests ==
    CHECK(km_1 == m_1000);
    CHECK(km_1 == cm_100000);
    CHECK(m_1000 == cm_100000);

    CHECK(ton_1 == kg_1000);
    CHECK(ton_1 == g_1000000);
    CHECK(ton_1 == mg_1000000000);
    CHECK(kg_1000 == g_1000000);
    CHECK(kg_1000 == mg_1000000000);
    CHECK(g_1000000 == mg_1000000000);
    
    CHECK(EUR_10 == ILS_45);
    CHECK(USD_100 == ILS_333);

    CHECK(hour_1 == min_60);
    CHECK(hour_1 == sec_3600);
    CHECK(min_60 == sec_3600);



    //Tests >=
    CHECK(km_1 >= m_1000);
    CHECK(km_1 >= cm_100000);
    CHECK(m_1000 >= cm_100000);


    CHECK(ton_1 >= kg_1000);
    CHECK(ton_1 >= g_1000000);
    CHECK(ton_1 >= mg_1000000000);
    CHECK(kg_1000 >= g_1000000);
    CHECK(kg_1000 >= mg_1000000000);
    CHECK(g_1000000 >= mg_1000000000);
    
    CHECK(ILS_45 >= EUR_10);
    CHECK(USD_100 >= ILS_333);

    CHECK(hour_1 >= min_60);
    CHECK(hour_1 >= sec_3600);
    CHECK(min_60 >= sec_3600);


    //Tests <=
    CHECK(km_1 <= m_1000);
    CHECK(km_1 <= cm_100000);
    CHECK(m_1000 <= cm_100000);

    CHECK(ton_1 <= kg_1000);
    CHECK(ton_1 <= g_1000000);
    CHECK(ton_1 <= mg_1000000000);
    CHECK(kg_1000 <= g_1000000);
    CHECK(kg_1000 <= mg_1000000000);
    CHECK(g_1000000 <= mg_1000000000);
    
    CHECK(EUR_10 <= ILS_45);
    CHECK(USD_100 <= ILS_333);

    CHECK(hour_1 <= min_60);
    CHECK(hour_1 <= sec_3600);
    CHECK(min_60 <= sec_3600);


    //////////////////////////////////////////////////////// operators '>' , '>=' , '!=' ////////////////////////////////////////////////
    

    //Increase all Units 
    km_1++;
    m_1000++;
    cm_100000++;
    
    ton_1++;
    kg_1000++;
    g_1000000++;
    mg_1000000000++;

    EUR_10++;
    USD_100++;
    ILS_45++;
    ILS_333++;

    hour_1++;
    min_60++;
    sec_3600++;




    //Tests !=
    CHECK(km_1 != m_1000);
    CHECK(km_1 != cm_100000);
    CHECK(m_1000 != cm_100000);
    
    CHECK(ton_1 != kg_1000);
    CHECK(ton_1 != g_1000000);
    CHECK(ton_1 != mg_1000000000);
    CHECK(kg_1000 != g_1000000);
    CHECK(kg_1000 != mg_1000000000);
    CHECK(g_1000000 != mg_1000000000);
    
    CHECK(EUR_10 != ILS_45);
    CHECK(USD_100 != ILS_333);

    CHECK(hour_1 != min_60);
    CHECK(hour_1 != sec_3600);
    CHECK(min_60 != sec_3600);



    //Tests >=
    CHECK(km_1 >= m_1000);
    CHECK(km_1 >= cm_100000);
    CHECK(m_1000 >= cm_100000);

    CHECK(ton_1 >= kg_1000);
    CHECK(ton_1 >= g_1000000);
    CHECK(ton_1 >= mg_1000000000);
    CHECK(kg_1000 >= g_1000000);
    CHECK(kg_1000 >= mg_1000000000);
    CHECK(g_1000000 >= mg_1000000000);
    
    CHECK(EUR_10 >= ILS_45);
    CHECK(USD_100 >= ILS_333);

    CHECK(hour_1 >= min_60);
    CHECK(hour_1 >= sec_3600);
    CHECK(min_60 >= sec_3600);


    //Tests >
    CHECK(km_1 > m_1000);
    CHECK(km_1 > cm_100000);
    CHECK(m_1000 > cm_100000);

    CHECK(ton_1 > kg_1000);
    CHECK(ton_1 > g_1000000);
    CHECK(ton_1 > mg_1000000000);
    CHECK(kg_1000 > g_1000000);
    CHECK(kg_1000 > mg_1000000000);
    CHECK(g_1000000 > mg_1000000000);
    
    CHECK(EUR_10 > ILS_45);
    CHECK(USD_100 > ILS_333);

    CHECK(hour_1 > min_60);
    CHECK(hour_1 > sec_3600);
    CHECK(min_60 > sec_3600);



    //////////////////////////////////////////////operators '<' , '<=' , '!='////////////////////////////////////////

    //Decrease all Units
    for(int i = 0;i<2;i++)
    {
    km_1--;
    m_1000--;
    cm_100000--;
    
    ton_1--;
    kg_1000--;
    g_1000000--;
    mg_1000000000--;

    EUR_10--;
    USD_100--;
    ILS_45--;
    ILS_333--;

    hour_1--;
    min_60--;
    sec_3600--;
    }
    //Tests !=
    CHECK(km_1 != m_1000);
    CHECK(km_1 != cm_100000);
    CHECK(m_1000 != cm_100000);

    CHECK(ton_1 != kg_1000);
    CHECK(ton_1 != g_1000000);
    CHECK(ton_1 != mg_1000000000);
    CHECK(kg_1000 != g_1000000);
    CHECK(kg_1000 != mg_1000000000);
    CHECK(g_1000000 != mg_1000000000);
    
    CHECK(EUR_10 != ILS_45);
    CHECK(USD_100 != ILS_333);

    CHECK(hour_1 != min_60);
    CHECK(hour_1 != sec_3600);
    CHECK(min_60 != sec_3600);



    //Tests <=
    CHECK(km_1 <= m_1000);
    CHECK(km_1 <= cm_100000);
    CHECK(m_1000 <= cm_100000);

    CHECK(ton_1 <= kg_1000);
    CHECK(ton_1 <= g_1000000);
    CHECK(ton_1 <= mg_1000000000);
    CHECK(kg_1000 <= g_1000000);
    CHECK(kg_1000 <= mg_1000000000);
    CHECK(g_1000000 <= mg_1000000000);
    
    CHECK(EUR_10 <= ILS_45);
    CHECK(USD_100 <= ILS_333);

    CHECK(hour_1 <= min_60);
    CHECK(hour_1 <= sec_3600);
    CHECK(min_60 <= sec_3600);


    //Tests <
    CHECK(km_1 < m_1000);
    CHECK(km_1 < cm_100000);
    CHECK(m_1000 < cm_100000);

    CHECK(ton_1 < kg_1000);
    CHECK(ton_1 < g_1000000);
    CHECK(ton_1 < mg_1000000000);
    CHECK(kg_1000 < g_1000000);
    CHECK(kg_1000 < mg_1000000000);
    CHECK(g_1000000 < mg_1000000000);
    
    CHECK(EUR_10 < ILS_45);
    CHECK(USD_100 < ILS_333);

    CHECK(hour_1 < min_60);
    CHECK(hour_1 < sec_3600);
    CHECK(min_60 < sec_3600);
}

 TEST_CASE("Aritmethic Operations")
 {
    //Distances
    NumberWithUnits km(1 , "km");
    NumberWithUnits m_100(100 , "m");
    NumberWithUnits cm_100(100 , "cm");

    //Weights
    NumberWithUnits ton(1 , "ton");
    NumberWithUnits kg_200(200 , "kg");
    NumberWithUnits g_30000(30000 , "g");

    //Coins
    NumberWithUnits EUR_10(10,"EUR");
    NumberWithUnits USD_100(100,"USD");
    NumberWithUnits ILS_45(45,"ILS");
    NumberWithUnits ILS_33(33.3,"ILS");


    //Time units
    NumberWithUnits hour_1(1 , "hour");
    NumberWithUnits min_30(30 , "min");
    NumberWithUnits sec_720(720 , "sec");


    ///////////////////////////////////////////////Operator '++' , '--' ////////////////////////////////////////////
    
    //test ++
    km++;
    m_100++;
    cm_100++;

    ton++;
    kg_200++;
    g_30000++;

    EUR_10++;
    USD_100++;
    ILS_45++;
    ILS_33++;

    hour_1++;
    min_30++;
    sec_720++;


    CHECK(km == NumberWithUnits(2 , "km"));
    CHECK(m_100 == NumberWithUnits(101 , "m"));
    CHECK(cm_100 == NumberWithUnits(101 , "cm"));

    CHECK(ton == NumberWithUnits(2 , "ton"));
    CHECK(kg_200 == NumberWithUnits(201 , "kg"));
    CHECK(g_30000 == NumberWithUnits(30001 , "g"));

    CHECK(EUR_10 == NumberWithUnits(11 , "EUR"));
    CHECK(USD_100 == NumberWithUnits(101 , "USD"));
    CHECK(ILS_45 == NumberWithUnits(46 , "ILS"));
    CHECK(ILS_33 == NumberWithUnits(34.3 , "ILS"));

    CHECK(hour_1 == NumberWithUnits(2 , "hour"));
    CHECK(min_30 == NumberWithUnits(31 , "min"));
    CHECK(sec_720 == NumberWithUnits(721 , "sec"));



    //test --
    km--;
    m_100--;
    cm_100--;

    ton--;
    kg_200--;
    g_30000--;

    EUR_10--;
    USD_100--;
    ILS_45--;
    ILS_33--;

    hour_1--;
    min_30--;
    sec_720--;

    CHECK(km == NumberWithUnits(1 , "km"));
    CHECK(m_100 == NumberWithUnits(100 , "m"));
    CHECK(cm_100 == NumberWithUnits(100 , "cm"));

    CHECK(ton == NumberWithUnits(1 , "ton"));
    CHECK(kg_200 == NumberWithUnits(200 , "kg"));
    CHECK(g_30000 == NumberWithUnits(30000 , "g"));

    CHECK(EUR_10 == NumberWithUnits(10 , "EUR"));
    CHECK(USD_100 == NumberWithUnits(100 , "USD"));
    CHECK(ILS_45 == NumberWithUnits(45 , "ILS"));
    CHECK(ILS_33 == NumberWithUnits(33.3 , "ILS"));

    CHECK(hour_1 == NumberWithUnits(1 , "hour"));
    CHECK(min_30 == NumberWithUnits(30 , "min"));
    CHECK(sec_720 == NumberWithUnits(720 , "sec"));




    //////////////////////////////////////////////Operators '+=' , '-=' ///////////////////////////////////////////////
    NumberWithUnits test_1(1 , "km");
    NumberWithUnits test_2(100 , "m");
    NumberWithUnits test_3(1000 , "cm");

    NumberWithUnits test_4(1 , "ton");
    NumberWithUnits test_5(100 , "kg");
    NumberWithUnits test_6(10000 , "g");

    NumberWithUnits test_7(1 , "EUR");
    NumberWithUnits test_8(1 , "USD");
    NumberWithUnits test_9(1 , "ILS");
    NumberWithUnits test_10(1 , "ILS");

    NumberWithUnits test_11(1 , "hour");
    NumberWithUnits test_12(10 , "min");
    NumberWithUnits test_13(720 , "sec");


    km+=test_1; //2 km
    m_100+=test_2;// 200 m
    cm_100+=test_3; // 200 cm

    ton+=test_4; //2 ton
    kg_200+=test_5; //300 kg
    g_30000+=test_6; //40000 g

    EUR_10+=test_7; // 11 EUR
    USD_100+=test_8; // 101 USD
    ILS_45+=test_9; //46 ILS
    ILS_33+=test_10; //34 ILS

    hour_1+=test_11; //2 hour
    min_30+=test_12; //40 min
    sec_720+=test_13; //1440 sec


    CHECK(km == NumberWithUnits(2, "km"));
    CHECK(m_100 == NumberWithUnits(200 , "m"));
    CHECK(cm_100 == NumberWithUnits(1100 , "cm"));

    CHECK(ton == NumberWithUnits(2 , "ton"));
    CHECK(kg_200 == NumberWithUnits(300 , "kg"));
    CHECK(g_30000 == NumberWithUnits(40000 , "g"));

    CHECK(EUR_10 == NumberWithUnits(11 , "EUR"));
    CHECK(USD_100 == NumberWithUnits(101 , "USD"));
    CHECK(ILS_45 == NumberWithUnits(46 , "ILS"));
    CHECK(ILS_33 == NumberWithUnits(34.3 , "ILS"));

    CHECK(hour_1 == NumberWithUnits(2 , "hour"));
    CHECK(min_30 == NumberWithUnits(40 , "min"));
    CHECK(sec_720 == NumberWithUnits(1440 , "sec"));




    km-=test_1; //2 km
    m_100-=test_2;// 200 m
    cm_100-=test_3; // 200 cm

    ton-=test_4; //2 ton
    kg_200-=test_5; //300 kg
    g_30000-=test_6; //40000 g

    EUR_10-=test_7; // 11 EUR
    USD_100-=test_8; // 101 USD
    ILS_45-=test_9; //46 ILS
    ILS_33-=test_10; //34 ILS

    hour_1-=test_11; //2 hour
    min_30-=test_12; //40 min
    sec_720-=test_13; //1440 sec


    CHECK(km == NumberWithUnits(1 , "km"));
    CHECK(m_100 == NumberWithUnits(100 , "m"));
    CHECK(cm_100 == NumberWithUnits(100 , "cm"));

    CHECK(ton == NumberWithUnits(1 , "ton"));
    CHECK(kg_200 == NumberWithUnits(200 , "kg"));
    CHECK(g_30000 == NumberWithUnits(30000 , "g"));

    CHECK(EUR_10 == NumberWithUnits(10 , "EUR"));
    CHECK(USD_100 == NumberWithUnits(100 , "USD"));
    CHECK(ILS_45 == NumberWithUnits(45 , "ILS"));
    CHECK(ILS_33 == NumberWithUnits(33.3 , "ILS"));

    CHECK(hour_1 == NumberWithUnits(1 , "hour"));
    CHECK(min_30 == NumberWithUnits(30 , "min"));
    CHECK(sec_720 == NumberWithUnits(720 , "sec"));





    ///////////////////////////////////////////////Operator '+' ////////////////////////////////////////////

    NumberWithUnits d_1 = km + m_100; // 1.1 km
    NumberWithUnits d_2 = km + cm_100; // 1.001 km
    NumberWithUnits d_3 = m_100 + km; // 1100 m
    NumberWithUnits d_4 = m_100 + cm_100; // 101 m
    NumberWithUnits d_5 = cm_100 + km; // 100100 cm
    NumberWithUnits d_6 = cm_100 + m_100; // 10100 cm

    NumberWithUnits w_1 = ton + kg_200; // 1.2 ton
    NumberWithUnits w_2 = ton + g_30000; // 1.03 ton
    NumberWithUnits w_3 = kg_200 + ton; // 1200 kg
    NumberWithUnits w_4 = kg_200 + g_30000; // 230 kg
    NumberWithUnits w_5 = g_30000 + ton; // 1030000 g
    NumberWithUnits w_6 = g_30000 + kg_200; // 230000 g

    NumberWithUnits c_1 = EUR_10 + ILS_45; //20 EUR
    NumberWithUnits c_2 = USD_100 + ILS_33; //110 USD
    NumberWithUnits c_3 = ILS_45 + EUR_10;//90 ILS
    NumberWithUnits c_4 = ILS_33 + USD_100;//378 ILS

    NumberWithUnits t_1 = hour_1 + min_30; //1.5 hour
    NumberWithUnits t_2 = hour_1 + sec_720; // 1.2 hour
    NumberWithUnits t_3 = min_30 + hour_1; // 90 min
    NumberWithUnits t_4 = min_30 + sec_720; // 42 min
    NumberWithUnits t_5 = sec_720 + hour_1; // 4320 sec
    NumberWithUnits t_6 = sec_720 + min_30; // 2520 sec

    CHECK(d_1 == NumberWithUnits(1.1 , "km"));
    CHECK(d_2 == NumberWithUnits(1.001 , "km"));
    CHECK(d_3 == NumberWithUnits(1100 , "m"));
    CHECK(d_4 == NumberWithUnits(101 , "m"));
    CHECK(d_5 == NumberWithUnits(100100 , "cm"));
    CHECK(d_6 == NumberWithUnits(10100 , "cm"));


    CHECK(w_1 == NumberWithUnits(1.2 , "ton"));
    CHECK(w_2 == NumberWithUnits(1.03 , "ton"));
    CHECK(w_3 == NumberWithUnits(1200 , "kg"));
    CHECK(w_4 == NumberWithUnits(230 , "kg"));
    CHECK(w_5 == NumberWithUnits(1030000 , "g"));
    CHECK(w_6 == NumberWithUnits(230000 , "g"));

    CHECK(c_1 == NumberWithUnits(20 , "EUR"));
    CHECK(c_2 == NumberWithUnits(110 , "USD"));
    CHECK(c_3 == NumberWithUnits(90 , "ILS"));
    CHECK(c_4 == NumberWithUnits(366.3 , "ILS"));

    CHECK(t_1 == NumberWithUnits(1.5 , "hour"));
    CHECK(t_2 == NumberWithUnits(1.2 , "hour"));
    CHECK(t_3 == NumberWithUnits(90 , "min"));
    CHECK(t_4 == NumberWithUnits(42 , "min"));
    CHECK(t_5 == NumberWithUnits(4320 , "sec"));
    CHECK(t_6 == NumberWithUnits(2520 , "sec"));


   ///////////////////////////////////////////////Operator '-' ////////////////////////////////////////////

     d_1 = km - m_100; // 0.9 km
     d_2 = km - cm_100; // 0.999 km
     d_3 = m_100 - km; // -900 m
     d_4 = m_100 - cm_100; // 99 m
     d_5 = cm_100 - km; // -99900 cm
     d_6 = cm_100 - m_100; // -9900 cm

     w_1 = ton - kg_200; // 0.8 ton
     w_2 = ton - g_30000; // 0.97 ton
     w_3 = kg_200 - ton; // -800 kg
     w_4 = kg_200 - g_30000; // 170 kg
     w_5 = g_30000 - ton; // -970000 g
     w_6 = g_30000 - kg_200; // -170000 g

     c_1 = EUR_10 - ILS_45; //0 eur
     c_2 = USD_100 - ILS_33; //90 USD
     c_3 = ILS_45 - EUR_10;//0 ILS
     c_4 = ILS_33 - USD_100;//-299.7 ILS

     t_1 = hour_1 - min_30; //0.5 hour
     t_2 = hour_1 - sec_720; // 0.8 hour
     t_3 = min_30 - hour_1; // -30 min
     t_4 = min_30 - sec_720; // 18 min
     t_5 = sec_720 - hour_1; // -2880 sec
     t_6 = sec_720 - min_30; // -1080 sec


    CHECK(d_1 == NumberWithUnits(0.9 , "km"));
    CHECK(d_2 == NumberWithUnits(0.999 , "km"));
    CHECK(d_3 == NumberWithUnits(-900 , "m"));
    CHECK(d_4 == NumberWithUnits(99 , "m"));
    CHECK(d_5 == NumberWithUnits(-99900 , "cm"));
    CHECK(d_6 == NumberWithUnits(-9900 , "cm"));


    CHECK(w_1 == NumberWithUnits(0.8 , "ton"));
    CHECK(w_2 == NumberWithUnits(0.97 , "ton"));
    CHECK(w_3 == NumberWithUnits(-800 , "kg"));
    CHECK(w_4 == NumberWithUnits(170 , "kg"));
    CHECK(w_5 == NumberWithUnits(-970000 , "g"));
    CHECK(w_6 == NumberWithUnits(-170000 , "g"));

    CHECK(c_1 == NumberWithUnits(0 , "EUR"));
    CHECK(c_2 == NumberWithUnits(90 , "USD"));
    CHECK(c_3 == NumberWithUnits(0 , "ILS"));
    CHECK(c_4 == NumberWithUnits(-299.7 , "ILS"));

    CHECK(t_1 == NumberWithUnits(0.5 , "hour"));
    CHECK(t_2 == NumberWithUnits(0.8 , "hour"));
    CHECK(t_3 == NumberWithUnits(-30 , "min"));
    CHECK(t_4 == NumberWithUnits(18 , "min"));
    CHECK(t_5 == NumberWithUnits(-2880 , "sec"));
    CHECK(t_6 == NumberWithUnits(-1080 , "sec"));

    ///////////////////////////////////////////////Operator '++' , '--' Before object//////////////////////////////////////


    CHECK(++km == NumberWithUnits(2 , "km"));
    CHECK(++m_100 == NumberWithUnits(101 , "m"));
    CHECK(++cm_100 == NumberWithUnits(101 , "cm"));

    CHECK(++ton == NumberWithUnits(2 , "ton"));
    CHECK(++kg_200 == NumberWithUnits(201 , "kg"));
    CHECK(++g_30000 == NumberWithUnits(30001 , "g"));

    CHECK(++EUR_10 == NumberWithUnits(11 , "EUR"));
    CHECK(++USD_100 == NumberWithUnits(101 , "USD"));
    CHECK(++ILS_45 == NumberWithUnits(46 , "ILS"));
    CHECK(++ILS_33 == NumberWithUnits(34.3 , "ILS"));

    CHECK(++hour_1 == NumberWithUnits(2 , "hour"));
    CHECK(++min_30 == NumberWithUnits(31 , "min"));
    CHECK(++sec_720 == NumberWithUnits(721 , "sec"));



    CHECK(--km == NumberWithUnits(1 , "km"));
    CHECK(--m_100 == NumberWithUnits(100 , "m"));
    CHECK(--cm_100 == NumberWithUnits(100 , "cm"));

    CHECK(--ton == NumberWithUnits(1 , "ton"));
    CHECK(--kg_200 == NumberWithUnits(200 , "kg"));
    CHECK(--g_30000 == NumberWithUnits(30000 , "g"));

    CHECK(--EUR_10 == NumberWithUnits(10 , "EUR"));
    CHECK(--USD_100 == NumberWithUnits(100 , "USD"));
    CHECK(--ILS_45 == NumberWithUnits(45 , "ILS"));
    CHECK(--ILS_33 == NumberWithUnits(33.3 , "ILS"));

    CHECK(--hour_1 == NumberWithUnits(1 , "hour"));
    CHECK(--min_30 == NumberWithUnits(30 , "min"));
    CHECK(--sec_720 == NumberWithUnits(720 , "sec"));




    /////////////////////////////////////////////// Operators '+' , '-' Before object//////////////////////////////////

    CHECK(+km == NumberWithUnits(1 , "km"));
    CHECK(+m_100 == NumberWithUnits(100 , "m"));
    CHECK(+cm_100 == NumberWithUnits(100 , "cm"));

    CHECK(+ton == NumberWithUnits(1 , "ton"));
    CHECK(+kg_200 == NumberWithUnits(200 , "kg"));
    CHECK(+g_30000 == NumberWithUnits(30000 , "g"));

    CHECK(+EUR_10 == NumberWithUnits(10 , "EUR"));
    CHECK(+USD_100 == NumberWithUnits(100 , "USD"));
    CHECK(+ILS_45 == NumberWithUnits(45 , "ILS"));
    CHECK(+ILS_33 == NumberWithUnits(33.3 , "ILS"));

    CHECK(+hour_1 == NumberWithUnits(1 , "hour"));
    CHECK(+min_30 == NumberWithUnits(30 , "min"));
    CHECK(+sec_720 == NumberWithUnits(720 , "sec"));





    CHECK(-km == NumberWithUnits(-1 , "km"));
    CHECK(-m_100 == NumberWithUnits(-100 , "m"));
    CHECK(-cm_100 == NumberWithUnits(-100 , "cm"));

    CHECK(-ton == NumberWithUnits(-1 , "ton"));
    CHECK(-kg_200 == NumberWithUnits(-200 , "kg"));
    CHECK(-g_30000 == NumberWithUnits(-30000 , "g"));

    CHECK(-EUR_10 == NumberWithUnits(-10 , "EUR"));
    CHECK(-USD_100 == NumberWithUnits(-100 , "USD"));
    CHECK(-ILS_45 == NumberWithUnits(-45 , "ILS"));
    CHECK(-ILS_33 == NumberWithUnits(-33.3 , "ILS"));

    CHECK(-hour_1 == NumberWithUnits(-1 , "hour"));
    CHECK(-min_30 == NumberWithUnits(-30 , "min"));
    CHECK(-sec_720 == NumberWithUnits(-720 , "sec"));





    //////////////////////////////////////////////Operator '*' /////////////////////////////////////////////////////



    ///Before object

    CHECK(2.5*km == NumberWithUnits(2.5 , "km"));
    CHECK(2.5*m_100 == NumberWithUnits(250 , "m"));
    CHECK(2.5*cm_100 == NumberWithUnits(250 , "cm"));

    CHECK(2.5*ton == NumberWithUnits(2.5 , "ton"));
    CHECK(2.5*kg_200 == NumberWithUnits(500 , "kg"));
    CHECK(2.5*g_30000 == NumberWithUnits(75000 , "g"));

    CHECK(2.5*EUR_10 == NumberWithUnits(25 , "EUR"));
    CHECK(2.5*USD_100 == NumberWithUnits(250 , "USD"));
    CHECK(2.5*ILS_45 == NumberWithUnits(112.5 , "ILS"));
    CHECK(2.5*ILS_33 == NumberWithUnits(83.25 , "ILS"));

    CHECK(2.5*hour_1 == NumberWithUnits(2.5 , "hour"));
    CHECK(2.5*min_30 == NumberWithUnits(75 , "min"));
    CHECK(2.5*sec_720 == NumberWithUnits(1800 , "sec"));


    ///After object

    CHECK(km*2.5 == NumberWithUnits(2.5 , "km"));
    CHECK(m_100*2.5 == NumberWithUnits(250 , "m"));
    CHECK(cm_100*2.5 == NumberWithUnits(250 , "cm"));

    CHECK(ton*2.5 == NumberWithUnits(2.5 , "ton"));
    CHECK(kg_200*2.5 == NumberWithUnits(500 , "kg"));
    CHECK(g_30000*2.5 == NumberWithUnits(75000 , "g"));

    CHECK(EUR_10*2.5 == NumberWithUnits(25 , "EUR"));
    CHECK(USD_100*2.5 == NumberWithUnits(250 , "USD"));
    CHECK(ILS_45*2.5 == NumberWithUnits(112.5 , "ILS"));
    CHECK(ILS_33*2.5 == NumberWithUnits(83.25 , "ILS"));

    CHECK(hour_1*2.5 == NumberWithUnits(2.5 , "hour"));
    CHECK(min_30*2.5 == NumberWithUnits(75 , "min"));
    CHECK(sec_720*2.5 == NumberWithUnits(1800 , "sec"));

 }
TEST_CASE("Exceptions")
{
    CHECK_THROWS(NumberWithUnits a(1 , "Km"));
    CHECK_THROWS(NumberWithUnits a(1 , "M"));
    CHECK_THROWS(NumberWithUnits a(1 , "usd"));
    CHECK_THROWS(NumberWithUnits a(1 , "EUr"));
    CHECK_THROWS(NumberWithUnits a(1 , "ILs"));
    CHECK_THROWS(NumberWithUnits a(1 , "CM"));
    NumberWithUnits km_1{1 , "km"};
    NumberWithUnits m_100{100 , "m"};
    NumberWithUnits cm_1000{1000 , "cm"};   
    NumberWithUnits Hour{1 , "hour"};
    NumberWithUnits Min{1 , "min"};
    NumberWithUnits Sec{1 , "sec"};
    NumberWithUnits shekel{1,"ILS"};
    NumberWithUnits dollar{1,"USD"};
    NumberWithUnits euro{1,"EUR"};
    CHECK_THROWS(km_1+=Hour);
    CHECK_THROWS(m_100-=dollar);
    CHECK_THROWS(NumberWithUnits g =  euro+Min);
    CHECK_THROWS(NumberWithUnits g =  euro-Min);
    CHECK_THROWS(bool flag = (cm_1000==Sec));
    CHECK_THROWS(bool flag =(cm_1000!=Sec));
    CHECK_THROWS(bool flag =(Min>dollar));
    CHECK_THROWS(bool flag =(km_1>=Hour));
    CHECK_THROWS(bool flag =(Min<dollar));
    CHECK_THROWS(bool flag =(km_1<=Hour));
}
TEST_CASE("Input & Output")
{
    istringstream sample_input_1{"1 [ kg ]"};
    istringstream sample_input_2{"10 [ g ]"};
    istringstream sample_input_3{"1 [ ton ]"};
    istringstream sample_input_4{"2 [ sec ]"};
    istringstream sample_input_5{"1 [ USD ]"};
    NumberWithUnits tmp{0,"kg"};
    sample_input_1>>tmp;

    CHECK(tmp==NumberWithUnits{1,"kg"});
    stringstream os_1;
    os_1<<tmp;
    CHECK(os_1.str()=="1[kg]");

    sample_input_2>>tmp;
    CHECK(tmp==NumberWithUnits{10,"g"});
    stringstream os_2;
    os_2<<tmp;
    CHECK(os_2.str()=="10[g]");

    sample_input_3>>tmp;
    CHECK(tmp==NumberWithUnits{1,"ton"});
    stringstream os_3;
    os_3<<tmp;
    CHECK(os_3.str()=="1[ton]");

    sample_input_4>>tmp;
    CHECK(tmp==NumberWithUnits{2,"sec"});
    stringstream os_4;
    os_4<<tmp;
    CHECK(os_4.str()=="2[sec]");

    sample_input_5>>tmp;
    CHECK(tmp==NumberWithUnits{1,"USD"});
    stringstream os_5;
    os_5<<tmp;
    CHECK(os_5.str()=="1[USD]");
  
    int end = remove("units.txt");

}


/* Add more test cases here */
