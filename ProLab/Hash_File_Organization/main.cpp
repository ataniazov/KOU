/**
 * Ata Niyazov      130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Dosya Organizasyonunda Hashing uygulamasi
 */

/**
 * main.cpp
 */

#include "main.h"
#include "persona.h"
#include "artwork.h"

int main() {

    //bool status = false;
    do{

    Randomizer RandomFile(RANDOM_FILE);
    //cout << RandomFile.Transaction() << endl;
    unsigned int Results[7];

    for(unsigned int i = 0; i < 7; i++){
        Results[i] = 0;
    }

    printResults(Results);

    Linear LinearFile(LINEAR_FILE, RANDOM_FILE);
    //cout << "Lineer Dosya Islem :          " << LinearFile.Transaction() << endl;
    Results[0] = LinearFile.Transaction();
    printResults(Results);

    DivRemainLP BolenKalanLY(DIVREMAIN_LP, LINEAR_FILE);
    //cout << "Bolen-Kalan Lineer Yoklama :  " << BolenKalanLY.Transaction() << endl;
    Results[1] = BolenKalanLY.Transaction();
    printResults(Results);

    DivRemainSO BolenKalanAT(DIVREMAIN_SO, LINEAR_FILE);
    //cout << "Bolen-Kalan Ayrik Tasma :     " << BolenKalanAT.Transaction() << endl;
    Results[2] = BolenKalanAT.Transaction();
    printResults(Results);

    FoldingLP KatlamaLY(FOLDING_LP, LINEAR_FILE);
    //cout << "Katlama Lineer Yoklama :      " << KatlamaLY.Transaction() << endl;
    Results[3] = KatlamaLY.Transaction();
    printResults(Results);

    FoldingSO KatlamaAT(FOLDING_SO, LINEAR_FILE);
    //cout << "Katlama Ayrik Tasma :         " << KatlamaAT.Transaction() << endl;
    Results[4] = KatlamaAT.Transaction();
    printResults(Results);

    MidSquareLP KareOrtasiLY(MIDSQUARE_LP, LINEAR_FILE);
    //cout << "Kare-Ortasi Lineer Yoklama :  " << KareOrtasiLY.Transaction() << endl;
    Results[5] = KareOrtasiLY.Transaction();
    printResults(Results);

    MidSquareSO KareOrtasiAT(MIDSQUARE_SO, LINEAR_FILE);
    //cout << "Kare-Ortasi Ayrik Tasma :     " << KareOrtasiAT.Transaction() << endl;
    Results[6] = KareOrtasiAT.Transaction();
    printResults(Results);

    printFastest(Results);
    /*
    unsigned int test = 20;
    string test_matrix[test] = {
        "100000000",
        "111111111",
        "123456789",
        "199999999",
        "187654321",
        "198765432",
        "176543210",
        "149999999",
        "150000000",
        "150000001",
        "144444444",
        "155555555",
        "135000000",
        "135000001",
        "135000010",
        "135000100",
        "135001000",
        "135010000",
        "135100000",
        "000000000"
    };

    cout << endl;

    cout << "Bolen-Kalan " << DIVREMAIN_MOD << " HASH TEST: " << endl << "----------------------" << endl;
    for(unsigned int i = 0; i < test; i++) {
        cout << test_matrix[i] << " : " << BolenKalanLY.HashFunction(test_matrix[i]) << endl;
    }

    cout << endl;

    cout << "Katlama HASH TEST: " << endl << "------------------" << endl;
    for(unsigned int i = 0; i < test; i++) {
        cout << test_matrix[i] << " : " << KatlamaLY.HashFunction(test_matrix[i]) << endl;
    }

    cout << endl;

    cout << "Kare-Ortasi HASH TEST: " << endl << "----------------------" << endl;
    for(unsigned int i = 0; i < test; i++) {
        cout << test_matrix[i] << " : " << KareOrtasiLY.HashFunction(test_matrix[i]) << endl;
    }
    */
    //cout << endl <<"Hello world!" << endl;


    } while(cin.ignore());

    return 0;
}
