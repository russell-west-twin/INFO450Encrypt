#include <iostream>

#include <cctype>

#include <fstream>

#include <string>

using namespace std;

void encryptFile();

void decryptFile();





int main() {

    

    int answer;

    

    do {

        cout << '\n' << endl;

        cout << "**" << " **************************           " << "**" << endl;

        cout << "**" << "  Welcome to my File                  " << "**" << endl;

        cout << "**" << "  Encryption/Decryption Program!      " << "**" << endl;

        cout << "**" << "  Please enter which option:          " << "**" << endl;

        cout << "**" << " **************************           " << "**" << endl;

        cout << "**" << "     1. Encyrpt the File              " << "**" << endl;

        cout << "**" << "     2. Decrypt the File              " << "**" << endl;

        cout << "**" << "     3. Exit the Program              " << "**" << endl;

        cout << "**" << " **************************           " << "**" << endl;

        cout << endl;

    cin >> answer;

    if (answer == 1){

        cout << endl << "Encrypting the file now...\n" << endl;

        encryptFile();

    } else if (answer == 2){

        cout << endl << "Decrypting the file now...\n" << endl;

        decryptFile();

    } else if (answer == 3){

        cout << endl << "You chose to Exit the program!\n" << endl;

        exit(0);

    } else {

        cout << endl << "You entered the wrong choice.\n" << endl;

    }

    }while  ((answer != '3'));

    cout << '\n' << endl;

    return 0;

}

    

    void encryptFile()

    {

        string path;

        string family = "";

        cout << "Please enter the full file path: " << endl;

        cin >> path;

        ifstream inputFile;

        inputFile.open(path,ios::in);

        if (path.empty() || !inputFile){

            cout << "Error message.\n" << endl;

            cout << "Would you like to enter the file path again??\n";

            cin >> path;

            if (path == "N"){

                exit(1);

            }

            return;

        }

        string inputString;

        while (!inputFile.eof())

        {

            getline(inputFile,inputString,'\n');

            cout << inputString << endl;

            for (int i=0;i<inputString.length();i++){

                char input = (tolower(inputString[i]));

                char x = input + 8;

                if (input == ' '){

                    x = input;

                }

                else{

                    if(x > 122){

                        x -= 26;

                    }

                }

                family += x;

            }

            family += "\n";

        }

        inputFile.close();

        ofstream outFile;

        outFile.open(path,ios::trunc);

        outFile << family << "\n";

        cout << family << endl;

        outFile.close();

        }



void decryptFile()

   {

       string path;

       string family = "";

       string s;

       cout << "Please enter the full file path: " << endl;

       cin >> path;

       ifstream inputFile;

       inputFile.open(path,ios::in);

       if (path.empty() || !inputFile){

           cout << "Error message.\n" << endl;

           cout << "Would you like to enter the file path again??\n";

           cin >> path;

           if (path == "N"){

               exit(1);

           }

           return;

       }

       string inputString;

       while (!inputFile.eof())

       {

           getline(inputFile,inputString,'\n');

           cout << inputString << endl;

           for (int i=0;i<inputString.length();i++){

               char input = (tolower(inputString[i]));

               char x = input - 8;

               if (input == ' '){

                   x = input;

               }

               else{

                   if(x < 97){

                       x += 26;

                   }

               }

               family += x;

           }

           family += "\n";

       }

       inputFile.close();

       ofstream outFile;

       outFile.open(path,ios::trunc);

       outFile << family << "\n";

       cout << family << endl;

       outFile.close();

       }
