#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

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
    string arr_x[6] = {"IX","IV","XC","XL","CM","CD"};
    string arr_I[9] = {"III","XXX","CCC","II","XX","CC","I","X","C"};
    char arr_one[3]= { 'I','X','C'};
    string arr_D[3] = {"D", "L", "V"};

    string BasicString = str;

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

    int p,ans=0;
    int n = str.length()-1;
    for (int i = n; i > 0; i-- ){
        if (intValue(str[i]) >= p) {
            ans += intValue(str[i]);
        }
        else {
            ans += intValue(str[i]);
        }
        p = intValue(str[i]);
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    string inpStr;
    cin >> inpStr;

    transform(inpStr.begin(), inpStr.end(), inpStr.begin(), ::toupper);
    cout<<validation(inpStr);

    cout<<endl<<endl<<inpStr;
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

