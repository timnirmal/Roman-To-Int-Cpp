#include <iostream>
#include <cstring>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

// I X C M repeated 3 times
int count_I =0, count_X = 0, count_C = 0, count_M = 0;
// D L V cant be repeated
int count_V = 0, count_L = 0, count_D = 0;


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
bool validation2(string str){
    string arr_x[6] = {"IX","IV","XC","XL","CM","CD"};
    string arr_I[9] = {"III","XXX","CCC","II","XX","CC","I","X","C"};
    char arr_one[3]= { 'I','X','C'};
    string arr_D[3] = {"D", "L", "V"};
    char arr_DC[3] = {'D','L','V'};

    string BasicString = str;

    for (char j : arr_DC) {
        int count = 0;
        for (char i : BasicString){
            if (i == j)  count++;
        }

        cout<<endl<<"\t"<<count<<endl;
        if (count < 2){
            //Remove "IX","IV","XC","XL","CM","CD"
            for(int i =0; i < 6 ; i++) {
                string StrToErase = arr_x[i];
                string::size_type j = BasicString.find(StrToErase);
                if (j != string::npos) {
                    BasicString.erase(j, StrToErase.length());
                }
            }

            //Remove "D", "L", "V"
            for(int i =0; i < 3 ; i++) {
                string StrToErase = arr_D[i];
                string::size_type j = BasicString.find(StrToErase);
                if (j != string::npos) {
                    BasicString.erase(j, StrToErase.length());
                }
            }
        } else{
            return false;
        }
    }



    //Count 'I','X','C' and If any of theese exeed 3 times return false
    for (char j : arr_one) {
        int count = 0;
        for (char i : BasicString){
            if (i == j)  count++;
        }

        if (count >= 4){
            cout<< " Bigger = "<<count<<endl;
            cout<<endl<<BasicString<<endl;
            return false;
        }

    }

    for(auto StrToErase : arr_I) {
        string::size_type j = BasicString.find(StrToErase);
        if (j != string::npos) {
            BasicString.erase(j, StrToErase.length());
        }
    }
    //cout<<endl<<BasicString<<endl;

    if(BasicString.empty()){
        cout<<endl<<"YES"<<endl;
        return true;
    }
    else {

        return false;
    }
}

int RomanToInt(string str){

    // Initialize result
    int res = 0;

    for (int i = 0; i < str.length(); i++)
    {
        // Getting value of symbol s[i]
        int s1 = intValue(str[i]);

        if (i + 1 < str.length())
        {
            int s2 = intValue(str[i + 1]);

            if (s1 >= s2){
                res = res + s1;
            }
            else {
                res = res + s2 - s1;
                i++;
            }
        }
        else {
            res = res + s1;
        }
    }
    return res;

}

bool validation(string str){
    string arr_x[6] = {"IX","IV","XC","XL","CM","CD"};
    string arr_I[9] = {"III","XXX","CCC","II","XX","CC","I","X","C"};
    char arr_one[3]= { 'I','X','C'};
    string arr_D[3] = {"D", "L", "V"};
    char arr_DC[3] = {'D','L','V'};

    string BasicString = str;

    //Check for 'D','L','V'
    int count = 0;
    for (char j: arr_DC) {
        count = 0;
        for (char i: BasicString) {
            if (i == j) count++;
        }
    }

    cout << endl << "\t" << count << endl;
    if (count < 2) {
        //Remove "IX","IV","XC","XL","CM","CD"
        for (int i = 0; i < 6; i++) {
            string StrToErase = arr_x[i];
            string::size_type j = BasicString.find(StrToErase);
            if (j != string::npos) {
                BasicString.erase(j, StrToErase.length());
            }
        }
        //return true;
        //Count 'I','X','C' and If any of theese exeed 3 times return false
        count = 0;
        for (char j: arr_one) {

            for (char i: BasicString) {
                if (i == j) count++;
            }
        }
        if (count >= 4) {
            return false;
        } else {
            return true;
        }

    }
    else {
        cout << "\tError";
        return false;
    }



}

void chk(string inpStr, int tot=0){

    //Length of the string
    int n = inpStr.length();
    //int tot =0;     //Total

    // IV  IX
    // XL XC
    // CD CM

    for (int i =0; i<inpStr.length(); i++){
        //cout << " \t"<< inpStr[i]<<" ";

       /* cout << endl << "I : " <<
             count_I << " " << "V : " <<
             count_V << " " << "X : " <<
             count_X << " " << "L : " <<
             count_L << " " << "C : " <<
             count_C << " " << endl;*/

        //Termination Conditions
     /*   if ((count_I > 3) || (count_X > 3) || (count_C > 3)
            || (count_V > 1) || (count_L > 1)) {
            cout << " " << count_I << " " << count_V << " " <<
                 count_X << " " << count_L << " " <<
                 count_C << " " << "ER";
            return;
        }*/

        int s1 = intValue(inpStr[i]);

        //// Not Last Charz
        if (i != inpStr.length()-1){
            int s2 = intValue(inpStr[i+1]);

            // XX , LX , XV , XI
            if (s1 >= s2){
                tot += s1;
                countAdd(s1);
                if (s1 == s2){

                }
            }
                // IV = 1  5    IX = 1  10
                // XL = 10 50   XC = 10 100
            // IV , IX , IL
            else {
                int tempval = 0;
                // IV & and IX only in end
                //////////////////////////////////////////////// IV && IX
                if ((s1 == 1 && s2 == 5)  || (s1 == 1 && s2 == 10)) {   //IV
                    // I IV(1 4) , IV I(4 1) , V IV (5 6)
                    int s3 = inpStr[i-1];

                    //If first letter is I or V
                    if (!(s3 == 'I' || s3 == 'V')){
                        //If S2 is last
                        if ( i+1 == n-1 ) {
                            tempval = s2 - s1;
                            countSub(s1);
                            tot += tempval;
                            cout<<"\t"<<tot;
                            return;
                        }
                        else{
                            cout<< "ERROR";
                            return;
                        }
                    }
                    else{
                        cout<< "ERROR";
                        return;
                    }

                }
/*
                /////////////////////////////////////////////// IX
                else if (s1 == 1 && s2 == 10) {   //IX
                    // IIX , IXI
                    int s3 = inpStr[i - 1];
                    if (s3 != 'I') {
                        if (i + 1 == n - 1) {
                            tempval = s2 - s1;
                            countVal(s1);
                            tot += tempval;
                            cout<<"\t"<<tot;
                            count_I--;
                            return;
                        } else {
                            cout << "ERROR";
                            return;
                        }
                    }
                    else{
                        cout<< "ERROR";
                        return;
                    }
                }
*/
                //////////////////////////////////////////////// XL
             /*   else if (s1 == 10 && s2 == 50) {   //XL
                    // LXL XLX XLL XXL XLC not
                    // CXL XLV XLI can
                        //Get previous val (only can be C or higher)
                    if (i != 0){
                        cout<<"\tPrev\n";
                        int s3 = inpStr[i-1];
                        if (! (s3 == 'L' || s3 == 'X' || s3 == 'I' || s3 == 'V')){
                            tempval = s2 - s1;
                            countVal(s1);
                            tot += tempval;
                            cout<<"\t"<<tot;
                            count_X--;
                            continue;
                        }
                        else{
                            cout<< "ERROR";
                            return;
                        }
                    }
                    // i == 0
                    else{
                        tempval = s2 - s1;
                        countVal(s1);
                        tot += tempval;
                        cout<<"\t"<<tot;
                        count_X--;
                        continue;
                    }

                    //Get Next val (I V can || L X C cant)
                    if(i + 1 == n - 1){
                        cout <<"\tNEXT";
                        int s3 = intValue(inpStr[i+2]);
                        cout<<endl<<s1 << " "<< s3<<endl;
                        if (s1 >= s3){
                            cout<< "Error";
                        }
                        else{
                            tempval = s2 - s1;
                            countVal(s1);
                            tot += tempval;
                            cout<<"\t"<<tot;
                            count_X--;
                            return;
                        }
                    }
                }*/

                //////////////////////////////////////////////// XL && XC
                else if ((s1 == 10 && s2 == 100) || (s1 == 10 && s2 == 50)) {   //XC
                    // XCX XCC XCL || XXC LXC
                    // CCX CXC CXX
                    //Get previous val (For c)
                    if (i != 0){
                        int s3 = inpStr[i-1];
                        if (s3 == 'C'){
                            tempval = s2 - s1;
                            countSub(s1);
                            tot += tempval;
                            //cout<<"\t"<<tot;
                            string r = inpStr.substr(i+2, n-i-2);
                            //cout<<endl<<endl<<"Print "<<r<<"  "<<n-i-2<<endl;
                            chk(r,tot);
                            return;
                        }
                        else {
                            cout << "ERROR";
                            return;
                        }
                    }
                    else{
                        tempval = s2 - s1;
                        countSub(s1);
                        tot += tempval;
                        string r = inpStr.substr(i+2, n-i-2);
                        //cout<<endl<<endl<<"Print "<<r<<"  "<<n-i-2<<endl;
                        chk(r,tot);
                        return;
                    }
                }

                else{
                    cout << "ERROR";
                    return;
                }

                //////////////////////////////////////////////////
                //cout<<"\n"<<tot;
                tot += tempval;
                //cout<<"\n"<<tot;
            }

        }
            //last char
        else {
            //cout<<"\nHere\n";
            tot += s1;
        }

        //cout<< "\nNext val\n";
    }

    cout<<"\t"<<tot;
}

void check(string inpStr){
    vector <int> stack;
    int tot=0;

    for (int i =0; i<inpStr.length(); i++){
        int s1 = intValue(inpStr[i]);

        //// Not Last Charz
        if (i != inpStr.length()-1){
            int s2 = intValue(inpStr[i+1]);

            // XX , LX , XV , XI
            if (s1 >= s2){
                tot += s1;
                countAdd(s1);
                if (s1 == s2){

                }
            }
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    string array[5000];
    int count = 0;
    string inpStr;
    ifstream file("C:\\Users\\timni\\CLionProjectsRomanToInt\\Input.txt");

    if (!file)
        cout << "File not Found";
    while (!file.eof()) {
        getline(file, inpStr);
        cout<<inpStr;
        if(validation(inpStr)){
            chk(inpStr);
        }
        else{
            cout<<"\tEROOR";
        }

        cout<<endl<<endl;
    }


    //cin >> inpStr;

    /*transform(inpStr.begin(), inpStr.end(), inpStr.begin(), ::toupper);
    cout<<validation(inpStr);

    cout << "\nInteger form of Roman Numeral is "
         <<RomanToInt(inpStr) << endl;*/

    return 0;
}

// I X C M repeated 3 times
// D L V cant be repeated
// IV  IX
// XL XC
// CD CM


//["DC","DCC","DCCC","LX","LXX","LXXX","XC","VI","VII","VIII"]
/*    string arr[18] = {"III","IX","IV","II","I",
                      "XXX","XC","XL","XX","X",
                      "CCC","CM","CD","CC","C",
                      "D", "L", "V"};*/

