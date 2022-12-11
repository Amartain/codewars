#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include <stdio.h>
#include <cctype>

using namespace std;

string pigaWord(std::string str){

    str += str[0];
    str += "ay ";
    str.erase(0,1);

    return str;

}

string pigaLetter(char c){
    string res;
    res += c;
    res += "ay ";

    return res;

}

set<int> detect1LetterWord(string str){
    //string letters = "";
    int len = 0;
    //bool res = false;
    set<int> indexes;

    for (int i = 0; str[i] != '\0' ; ++i) {
        len = i;
    }

    for (int i = 0; i < len; i++) {


        if( (str[i-1] == 32) && (str[i+1] == 32)  ){
            //letters += str[i];
            cout << "detect i: ";
            cout << i << endl;
            indexes.insert(i);

        }


    }


    return  indexes;
}


string cutToWords(string sentence){

    string words;
    string word = "";
    int st = 0, br, len;
    sentence += " ";

    for (int i = 0; sentence[i] != '\0' ; ++i) {
        len = i;
    }


    //cout << len << endl;

    //cout << sentence << endl;

            set<int> indexes = detect1LetterWord(sentence);

    for (int i = 0; i < len; i++) {

        bool is1Letter = indexes.find(i) != indexes.end();

        cout << "is1Letter i: ";
        cout << i << endl;
        cout << "is1Letter: ";
        cout << is1Letter << endl;

        if (ispunct(sentence[i])) {
            words += sentence[i];
            words += " ";
            cout << "_runs_: ";
            cout << words << endl;
            st = i + 2;
            i++;
        }
        else if( is1Letter) {
            words += pigaLetter(sentence[i]);
            st = i + 2;
            i++;
            cout << "1 letter: ";
            cout << words << endl;
        }


        else if( sentence[i+1] == 32) {
            word = "";
            br = i;
            int lng = (br - st) + 1;

            if (sentence[i - 1] != 32) {
                if (ispunct(sentence[i])) {
                    words += sentence[i];
                    words += " ";
                    cout << "_runs_: ";
                    cout << words << endl;
                    st = i + 2;
                    i++;
                }else{
                    for (int j = 0; j < lng; ++j) {
                        word += sentence[st + j];
                        cout << "word: ";
                        cout << word << endl;
                    }
                    st = i + 2;
                    i++;
                    cout << "i: ";
                    cout << i << endl;
                    cout << "sentence[i]: ";
                    cout << sentence[i] << endl;
                    words += pigaWord(word);
                    cout << "!ispunct normal word: ";
                    cout << words << endl;
                }

            }


            else{
                words += "_ERROR_";

            }


        }

    }


    words.pop_back();


    return words;
}




std::string pig_it(std::string str)
{


    string ret;

    ret = cutToWords(str);


    return ret;



}







int main(){
    string t1 = "This is my string";
    string t2 = ", fl";
    string t3 = "O tempora o mores !";
    string t4 = "a itypnv u ajop";

    string t1Res = "hisTay siay ymay tringsay";
    string t2Res = ", lfay";
    string t3Res = "Oay emporatay oay oresmay !";
    string t4Res = "aay typnviay uay jopay";

    string res;
    string tword = "This";
    string result;

    //vector<string> result;

   res =  pig_it(t3);
   //res = detect1LetterWord(t3);
  //res = pigaWord(tword);
    //result = cutToWords(t1);

    cout << t3 << endl;
   cout << res << endl;
   cout << t3Res << endl;

   //cout << result << endl;



    //for (auto i: result) {

       // cout << i << ' ';

    //}



}