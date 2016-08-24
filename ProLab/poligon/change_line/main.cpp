#include <iostream>
#include <fstream>

using namespace std;

int main()
{

    fstream data_file;
    data_file.open("replace.txt", ios::out | ios::app);

    if(data_file.is_open()){
        for(int i=0; i<10; i++){
            data_file << "XXXXXXXXXX" << endl;
        }
    }



    data_file.close();


    cout << "Hello world!" << endl;
    return 0;
}
