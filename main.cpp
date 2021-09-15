/********************************************************************************
 * Name             : Nirmal L.Y.T.
 * Index No         : 19/ENG/072
 * Registration No  : EN93921
*********************************************************************************/

/********************************************************************************
Can Convert upto 399 (CCCXCIX)
*********************************************************************************/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// I X C M repeated 3 times
int count_I =0, count_X = 0, count_C = 0;
// D L V cant be repeated
int count_V = 0, count_L = 0;


void countAdd(char roman){
    switch (roman) {
        case 1: count_I++; break;
        case 5: count_V++; break;
        case 10: count_X++; break;
        case 50: count_L++; break;
        case 100: count_C++; break;
    }
}

void countSub(char roman){
    switch (roman) {
        case  1: count_I--; break;
        case  5: count_V--; break;
        case  10: count_X--; break;
        case  50: count_L--; break;
        case  100: count_C--; break;
    }
}

int intValue(char roman){
    switch (roman) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
    }
}

//Return will check if there are valid numeric in here. But not the order
bool validation(string str){
    string arr_two[6] = {"IX", "IV", "XC", "XL", "CM", "CD"};
    char arr_one[3]= { 'I','X','C'};
    char arr_DC[3] = {'D','L','V'};

    string BasicString = str;

    for (char i: BasicString) {
        if (!(i == 'I' || i == 'V' || i == 'X' || i == 'L' || i == 'C')) return false;
    }

    //Check for 'D','L','V'
    int count = 0;
    for (char j: arr_DC) {
        count = 0;
        for (char i: BasicString) {
            //Search each char inn string with D L V
            if (i == j) count++;
        }
    }

    if (count < 2) {
        //Remove "IX","IV","XC","XL","CM","CD"
        for (auto StrToErase: arr_two) {
            string::size_type j = BasicString.find(StrToErase);
            if (j != string::npos) {
                BasicString.erase(j, StrToErase.length());
            }
        }
        //return true;
        //Count 'I','X','C' and If any of these exceed 3 times return false
        for (char j: arr_one) {
            count = 0;
            for (char i: BasicString) if (i == j) count++;
            return count < 4;
        }
    } else return false;
}

void chk(string inpStr, int tot=0){
    //Length of the string
    int n = inpStr.length();

    // IV  IX // XL XC // CD CM
    for (int i =0; i<inpStr.length(); i++){
        int s1 = intValue(inpStr[i]);

        //// Not Last Char
        if (i != inpStr.length() - 1) {
            int s2 = intValue(inpStr[i + 1]);

            // XX , LX , XV , XI
            if (s1 >= s2) {
                tot += s1;
                countAdd(s1);
            }

                // IV , IX && IL like not applicable
            else {
                int tempval = 0;
                // IV & and IX only in end
                //////////////////////////////////////////////// IV && IX
                if ((s1 == 1 && s2 == 5) || (s1 == 1 && s2 == 10)) {   //IV
                    // I IV(1 4) , IV I(4 1) , V IV (5 6)
                    int s3 = inpStr[i - 1];

                    //If first letter is I or V
                    if (!(s3 == 'I' || s3 == 'V')) {
                        //If S2 is last
                        if (i + 1 == n - 1) {
                            tempval = s2 - s1;
                            countSub(s1);
                            tot += tempval;
                            cout << "\t" << tot;
                            return;
                        } else {
                            cout << "\tERROR";
                            return;
                        }
                    } else {
                        cout << "\tERROR";
                        return;
                    }
                }

                    //////////////////////////////////////////////// XL && XC
                else if ((s1 == 10 && s2 == 100) || (s1 == 10 && s2 == 50)) {   //XC
                    // XCX XCC XCL || XXC LXC
                    // CCX CXC CXX
                    //Get previous val (For c)
                    if (i != 0) {
                        int s3 = inpStr[i - 1];
                        if (s3 == 'C') {
                            tempval = s2 - s1;
                            countSub(s1);
                            tot += tempval;
                            //Send Last part of the string to recursion
                            string r = inpStr.substr(i + 2, n - i - 2);
                            chk(r, tot);
                            return;
                        } else {
                            cout << "\tERROR";
                            return;
                        }
                    } else {
                        tempval = s2 - s1;
                        countSub(s1);
                        tot += tempval;
                        //Send Last part of the string to recursion
                        string r = inpStr.substr(i + 2, n - i - 2);
                        chk(r, tot);
                        return;
                    }
                } else {
                    cout << "\tERROR";
                    return;
                }
            }
        } else tot += s1;
    }
    cout<<"\t"<<tot;
}

int main() {
    string array[5000];
    int count = 0;
    string inpStr;
    ifstream file("C:\\Users\\timni\\CLionProjectsRomanToInt\\numbers.txt");

    if (!file)
        cout << "File not Found";
    while (!file.eof()) {
        getline(file, inpStr);
        transform(inpStr.begin(), inpStr.end(), inpStr.begin(), ::toupper);
        cout<<inpStr;
        if(validation(inpStr)){
            chk(inpStr);
        } else{
            cout<< "\tError";
        }
        cout<<endl;
    }

    return 0;
}

// I X C M repeated 3 times
// D L V cant be repeated
// IV  IX
// XL XC
// CD CM

