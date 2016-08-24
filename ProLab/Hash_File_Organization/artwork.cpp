/**
 * Ata Niyazov      130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Dosya Organizasyonunda Hashing uygulamasi
 */

/**
 * artwork.cpp
 */

#include "main.h"
#include "artwork.h"

/**
 * Parametre kadar Bosluk'lu (' ') string ureten
 * fonksiyon
 */

string makeSpace(unsigned int N) {
    if(N < 1) {
        // in this case tabular will return '\0' char
        return "\0";
    } else {
        stringstream buffer;
        buffer << " ";
        if(N > 1) {
            for(unsigned int i = 1; i < N; i++) {
                buffer << " ";
            }
        }
        string str = buffer.str();
        return str;
    }
}

void header(void){
    cout << "╔═════════════════════════════════════════════╗" << endl
         << "║  DOSYA ORGANİZASYONUNDA HASHING UYGULAMASI  ║" << endl
         << "╚═════════════════════════════════════════════╝" << endl
         << endl;

}

string justify(string str, unsigned int msglength){
    stringstream buffer;
    buffer << setfill(' ') << setw(msglength) << str;
    return buffer.str();
}

void printResults(unsigned int Results[7]){
    system("clear");
    header();
    stringstream buffer;
    string output;

    cout << "┌────────────────────────────────────┬────────┐" << endl;
    cout << "│  Lineer Dosya                      │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[0];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Bölen-Kalan Lineer Yoklama        │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[1];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Bölen-Kalan Ayrık Taşma           │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[2];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Katlama Lineer Yoklama            │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[3];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Katlama Ayrık Taşma               │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[4];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Kare-Ortasi Lineer Yoklama        │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[5];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "├────────────────────────────────────┼────────┤" << endl;
    cout << "│  Kare-Ortasi Ayrık Taşma           │";
    buffer.str(string());
    buffer.clear();
    buffer << Results[6];
    output = buffer.str();
    cout << justify(output, OUTPUT_LEN) << " │" << endl;

    cout << "└────────────────────────────────────┴────────┘" << endl << endl;
}

void printFastest(unsigned int Results[7]){

    unsigned int fastest = 0;

    for(unsigned int i = 0; i < 7; i++){
        if(Results[i] < Results[fastest]){
            fastest = i;
        }
    }

    cout << "┌─[!]─────────────────────────────────────────┐" << endl
         << "│               EN HIZLI YÖNTEM:              │" << endl
         << "└─────────────────────────────────────────────┘" << endl;

    string fastestName;

    if(fastest == 0){
        fastestName = "│  Lineer Dosya                      │";
    } else if(fastest == 1){
        fastestName = "│  Bölen-Kalan Lineer Yoklama        │";
    } else if(fastest == 2){
        fastestName = "│  Bölen-Kalan Ayrık Taşma           │";
    } else if(fastest == 3){
        fastestName = "│  Katlama Lineer Yoklama            │";
    } else if(fastest == 4){
        fastestName = "│  Katlama Ayrık Taşma               │";
    } else if(fastest == 5){
        fastestName = "│  Kare-Ortasi Lineer Yoklama        │";
    } else if(fastest == 6){
        fastestName = "│  Kare-Ortasi Ayrık Taşma           │";
    }

    cout << "┌────────────────────────────────────┬────────┐" << endl
         << fastestName;
    stringstream buffer;
    buffer.str(string());
    buffer.clear();
    buffer << Results[fastest];

    cout << justify(buffer.str(), OUTPUT_LEN) << " │" << endl;
    cout << "└────────────────────────────────────┴────────┘" << endl;

}
