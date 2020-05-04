#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string.h>

using namespace std;
const int ASCII_zero = 48 ;

int main(){

    string factorial ;
    vector<char> result ;

    cout << "Q5.Factorial" << endl ;
    cout << "Please Enter Number:" ;
    cin >> factorial ;

    while ( strcmp( factorial.c_str(), "quit" ) != 0 ) {

        cout << factorial << "!" << endl ;

        int nextNum = 0 ;

        for ( int i = factorial.size() - 1, digits = 1 ; i >= 0 ; i--, digits = digits*10 ) {

            result.push_back( factorial.at(i) ) ; // 0:0, 1:0, 2:5 ;
            nextNum = nextNum + ( factorial.at(i) - ASCII_zero ) * digits ; // 500 ;

        } // for

        nextNum-- ; // 499 ;

        int carryout = 0 ;

        for ( ; nextNum != 0 ; nextNum-- ) {

            for ( int i = 0 ; i < result.size() ; i++ ) {

                int calculate = ( result.at(i) - ASCII_zero ) * nextNum + ( carryout % 10 ) ;
                result.at(i) = calculate % 10 + ASCII_zero ; // 50'0' * 499 ;
                carryout = ( carryout / 10 ) + calculate / 10 ; // carry out ;

                if ( i+1 == result.size() && carryout > 0 ) {

                    char c = ASCII_zero ;
                    result.push_back( c ) ;

                } // if

            } // for

        } // for


        for ( int printout = result.size() - 1 ; printout >= 0 ; printout-- )
            cout << result.at( printout ) ;


        cout << endl << "Please Enter Number:" ;
        cin >> factorial ;
        result.clear() ;

    } // for


    return 0 ;

} // main
