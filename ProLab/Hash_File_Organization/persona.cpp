/**
 * Ata Niyazov      130201108
 * Programlama Laboratuvari dersi
 * PROJE 2
 * Dosya Organizasyonunda Hashing uygulamasi
 */

/**
 * persona.cpp
 */

#include "main.h"
#include "persona.h"

/**
 * Base Dosya Class'inin constructor'u
 */

Base::Base(const char * _filename) {
    //dosya isimini alma
    filename = nullptr;

    const size_t len = strlen(_filename);
    char * tmp_filename = new char[len + 1];
    strncpy(tmp_filename, _filename, len);
    tmp_filename[len] = '\0';

    delete[] filename;
    filename = tmp_filename;
    // islem sayaci sifirlama
    transaction = 0;
    // dosya varsa siler
    if((strcmp(filename, _filename)) == 0) {
        Destroy(filename);
    }
}

/**
 * Base Dosya Class'inin Saklan Dosya ismini yazan fonksiyon
 */

void Base::FileName(void) {
    cout << filename;
}

/**
 * Base Dosya Class'inin islem sayisini geri donderen fonksiyon
 */

unsigned int Base::Transaction(void) {
    return transaction;
}

/**
 * Parametre olarak alinan _filename isimli dosya varsa siler
 */

int Base::Destroy(const char * _filename) {
    ifstream data_file(_filename);

    if(data_file.good()) {
        if((remove(_filename)) != 0) {
            cout << "Destroy(): " << "ERROR: Can't remove " << _filename << endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

/**
 * Parametre olarak aldigi _redLine katar dizisinden
 * Ogrenci No. ve Ogrenci Ismini ceker ve geri donderir
 */

Record Base::Parser(string _redLine) {
    stringstream temp(_redLine);

    Record Persona;
    getline(temp, Persona.uid, '\t');
    getline(temp, Persona.name, '\0');

    return Persona;
}

/**
 * Kalip Dosya hazirlama fonksiyonu
 */

int Base::Composer(unsigned int _lines) {
    ofstream data_file;
    data_file.open(filename, ios::out | ios::app);

    if( !data_file.is_open() ) {
        cout << "Composer(): " << "ERROR: " << filename << " Can't be opened" << endl;
        return EXIT_FAILURE;
    } else {
        for(unsigned int i = 0; i < _lines; i++) {
            data_file << RECORD_FORM << endl;
        }
        data_file.close();
    }
    return EXIT_SUCCESS;
}

/**
 * Cakisma kontrol fonksiyonu:
 * -1: dosya acilmadiysa
 *  0: cakisma yoksa (_hashline satiri bos ise)
 *  1: cakisma varsa (_hashline satirinda baska kayit varsa)
 */

int Base::Collision(unsigned int _hashline) {
    ifstream data_file;
    data_file.open(filename, ios::in);

    if( !data_file.is_open() ) {
        cout << "Collision(): " << "ERROR: " << filename << " Can't be opened" << endl;
        return -1;
    } else {
        string redLine;

        data_file.clear();
        data_file.seekg(_hashline * RECORD_LEN, ios::beg);

        getline(data_file, redLine);

        if(redLine.compare(RECORD_FORM) == 0) {
            data_file.close();
            return 0;
        }
        data_file.close();
    }
    return 1;
}

/**
 * Kayidi dosyanin _hashline satirina yazma
 */

int Base::Write(Record Persona, unsigned int _hashline) {
    // main file
    ifstream data_file;
    data_file.open(filename, ios_base::in);
    // temp file
    ofstream temp_file;
    temp_file.open(TEMP_FILE, ios_base::out);

    if( !data_file.is_open() || !temp_file.is_open() ) {
        cout << "Write(): " << "ERROR: " << filename << " OR " << TEMP_FILE << " Can't be opened" << endl;
        return EXIT_FAILURE;
    } else {
        string redline;

        for(unsigned int lineNo = 0; getline(data_file, redline); lineNo++) {
            if(lineNo == _hashline) {
                if(redline.compare(RECORD_FORM) == 0) {
                    temp_file << Persona.uid << "\t" << Persona.name << endl;
                } else {
                    cout << "Write(): " << "ERROR: In " << filename << " for UID: " << Persona.uid << " hashline: " << _hashline << " is NOT EMPTY" << endl;
                    return EXIT_FAILURE;
                }
            } else {
                temp_file << redline << endl;
            }
        }
        data_file.close();
        temp_file.close();

        Destroy(filename);

        if((rename(TEMP_FILE, filename)) != 0) {
            cout << "Write(): " << "ERROR: Can't rename " << TEMP_FILE << " to " << filename << endl;
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

/**
 * Dosyanin _hashline satirindan _uid Ogrenci No.'lu ogrencinin
 * bilgilerini geri donderir
 */

string Base::Search(string _uid, unsigned int _hashline) {
    ifstream data_file;
    data_file.open(filename, ios::in);

    if( !data_file.is_open() ) {
        cout << "Search(): " << "ERROR: " << filename << " Can't be opened" << endl;
        return RECORD_FORM;
    } else {
        data_file.clear();
        data_file.seekg(_hashline * RECORD_LEN, ios::beg);

        string redLine;
        getline(data_file, redLine);

        Record Persona = Parser(redLine);

        if(_uid.compare(Persona.uid) == 0) {
            data_file.close();
            return redLine;
        }
        data_file.close();
    }
    return RECORD_FORM;
}

/**
 * Base Dosya Class'inin destructor'u
 */

Base::~Base() {
    delete[] filename;
}

/**
 * Random Dosya Class'inin constructor'u
 */

Randomizer::Randomizer(const char * _filename) : Base(_filename) {
    Composer(ZERO);

    srand(time(nullptr));

    for(int i = 0; i < ENTRIES_NUM; i++) {
        Record Persona = CreatePersona();

        if(((Search(Persona.uid)).compare(RECORD_FORM)) == 0) {
            Append(Persona);
            // islem sayaci artirma
            transaction++;
        } else if (((Search(Persona.uid)).compare(RECORD_FORM)) != 0) {
            i--;
            continue;
        }
    }
}

/**
 * Random Ogrenci olusturma fonksiyonu
 */

Record Randomizer::CreatePersona(void) {
    Record Persona;

    stringstream buffer;
    buffer << RANGE_MIN + (rand() % ((int)(RANGE_MAX - RANGE_MIN) + 1));
    Persona.uid = buffer.str();

    static string charset = CHARSET;

    Persona.name.resize(DATA_LEN);

    for(int i = 0; i < DATA_LEN; i++) {
        Persona.name[i] = charset[rand() % charset.length()];
    }
    return Persona;
}

/**
 * Kayidi dosyanin sonuna yazma (ekleme)
 */

int Randomizer::Append(Record Persona) {
    ofstream data_file;
    data_file.open(filename, ios::out | ios::app);

    if( !data_file.is_open() ) {
        cout << "Append(): " << "ERROR: " << filename << " Can't be opened" << endl;
        return EXIT_FAILURE;
    } else {
        data_file << Persona.uid << "\t" << Persona.name << endl;
        data_file.close();
    }
    return EXIT_SUCCESS;
}

/**
 * Kayidi dosyadan lineer arama
 */

string Randomizer::Search(string _uid) {
    ifstream data_file;
    data_file.open(filename, ios::in);

    if( !data_file.is_open() ) {
        cout << "Search(): " << "ERROR: " << filename << " Can't be opened" << endl;
        return RECORD_FORM;
    } else {
        string redLine;

        while(data_file.good()) {
            getline(data_file, redLine);

            Record Persona = Parser(redLine);
            // islem sayaci artirma
            transaction++;

            if(_uid.compare(Persona.uid) == 0) {
                data_file.close();
                return redLine;
            }
        }
        data_file.close();
    }
    return RECORD_FORM;
}

/**
 * Random Dosya Class'inin destructor'u
 */

Randomizer::~Randomizer() {}

/**
 * Lineer Dosya Class'inin constructor'u
 */

Linear::Linear(const char * _filename, const char * random_filename) : Base(_filename) {
    ifstream random_file;
    random_file.open(random_filename, ios::in);

    if( !random_file.is_open() ) {
        cout << "Linear(): " << "ERROR: " << random_filename << " Can't be opened" << endl;
    } else {
        // dosyaya yazma islemi
        string redLine;
        while(random_file.good()) {
            getline(random_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);
                Composer(ONE);

                unsigned int line = 0;

                while(Collision(line) != 0) {
                    line++;
                    // islem sayisini artirma
                    transaction++;
                    // dosya dolu ise
                    if(line >= ENTRIES_NUM) {
                        cout << "Linear(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is FULL" << endl;
                        break;
                    }
                }
                // Correction control
                if(Collision(line) == 0) {
                    Write(Persona, line);
                    // islem sayisini artirma
                    transaction++;
                }
            }
        }
        // dosyada arama islemi
        random_file.clear();
        random_file.seekg(0, ios::beg);

        while(random_file.good()) {
            getline(random_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int line = 0;
                // adres dolu ve kayit o adreste degil ise
                while((Search(Persona.uid, line)).compare(RECORD_FORM) == 0 && line < ENTRIES_NUM) {
                    line++;
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if((Search(Persona.uid, line)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    //transaction++;
                } else {
                    cout << "Linear(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                }
            }
        }
        random_file.close();
    }
}

/**
 * Lineer Dosya Class'inin destructor'u
 */

Linear::~Linear() {}

/**
 * Bolen-Kalan Class'inin constructor'u
 */

DivRemain::DivRemain(const char * _filename) : Base(_filename) {
    Composer(DIVREMAIN_MOD);
}

/**
 * Bolen-Kalan hash fonksiyonu
 */

unsigned int DivRemain::HashFunction(string _uid) {
    stringstream temp(_uid);
    unsigned int key = 0;
    temp >> key;

    unsigned int hashline = (key % DIVREMAIN_MOD);

    return hashline;
}

/**
 * Bolen-Kalan Class'inin destructor'u
 */

DivRemain::~DivRemain() {}

/**
 * Bolen-Kalan Lineer Yoklama Dosya Class'inin constructor'u
 */

DivRemainLP::DivRemainLP(const char * _filename, const char * linear_filename) : DivRemain(_filename) {
    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "DivRemainLP(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;

                while(Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < DIVREMAIN_MOD)) {
                        hashline = 0;
                    }
                    // dosya dolu ise
                    if(hashline == homeline) {
                        cout << "DivRemainLP(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is FULL" << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;
                // adres dolu ve kayit o adreste degil ise
                while((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0 && Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < DIVREMAIN_MOD)) {
                        hashline = 0;
                    }
                    // kayit dosyada bulunamadi ise
                    if(hashline == homeline) {
                        cout << "DivRemainLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {
                    cout << "DivRemainLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Bolen-Kalan Lineer Yoklama Dosya Class'inin destructor'u
 */

DivRemainLP::~DivRemainLP() {}

/**
 * Bolen-Kalan Ayrik Tasma Dosya Class'inin constructor'u
 */

DivRemainSO::DivRemainSO(const char * _filename, const char * linear_filename) : DivRemain(_filename) {
    endpoint = DIVREMAIN_MOD;

    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "DivRemainSO(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                } else if(Collision(hashline) != 0) {
                    hashline = DIVREMAIN_MOD;

                    Composer(ONE);
                    endpoint++;

                    while(Collision(hashline) != 0) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                        // dosyanin max. boyutuna ulasmasi
                        if(!(hashline < (ENTRIES_NUM + DIVREMAIN_MOD))) {
                            cout << "DivRemainSO(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is OVERFLOW" << endl;
                            break;
                        }
                    }
                    // Correction control
                    if(Collision(hashline) == 0) {
                        Write(Persona, hashline);
                        // islem sayisini artirma
                        transaction++;
                    }
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {

                    hashline = DIVREMAIN_MOD;

                    while(((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0) && (hashline < endpoint)) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                    }
                    // Correction control
                    if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                        // islem sayisini artirma
                        transaction++;
                    } else {
                        cout << "DivRemainSO(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                    }
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Bolen-Kalan Ayrik Tasma Dosya Class'inin destructor'u
 */

DivRemainSO::~DivRemainSO() {}

/**
 * Katlama Class'inin constructor'u
 */

Folding::Folding(const char * _filename) : Base(_filename) {
    Composer(THOUSAND_MOD);
}

/**
 * Katlama hash fonksiyonu
 */

unsigned int Folding::HashFunction(string _uid) {
    stringstream temp(_uid);

    unsigned int key = 0;
    temp >> key;

    unsigned int hashline = 0;

    bool to_reverse = true;

    while(key != 0) {
        unsigned int cut;

        cut = key % THOUSAND_MOD;
        key /= THOUSAND_MOD;

        if(to_reverse) {
            stringstream buffer;
            buffer << setfill('0') << setw(3) << cut << endl;
            string reversed = buffer.str();

            reverse(reversed.begin(), reversed.end());

            buffer.str(string());
            buffer.clear();

            buffer.str(reversed);
            buffer >> cut;
        }
        to_reverse ^= true;
        hashline += cut;
    }
    hashline %= THOUSAND_MOD;
    return hashline;
}

/**
 * Katlama Class'inin destructor'u
 */

Folding::~Folding() {}

/**
 * Katlama Lineer Yoklama Dosya Class'inin constructor'u
 */

FoldingLP::FoldingLP(const char * _filename, const char * linear_filename) : Folding(_filename) {
    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "FoldingLP(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;

                while(Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < THOUSAND_MOD)) {
                        hashline = 0;
                    }
                    // dosya dolu ise
                    if(hashline == homeline) {
                        cout << "FoldingLP(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is FULL" << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;
                // adres dolu ve kayit o adreste degil ise
                while((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0 && Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < THOUSAND_MOD)) {
                        hashline = 0;
                    }
                    // kayit dosyada bulunamadi ise
                    if(hashline == homeline) {
                        cout << "FoldingLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {
                    cout << "FoldingLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Katlama Lineer Yoklama Dosya Class'inin destructor'u
 */

FoldingLP::~FoldingLP() {}

/**
 * Katlama Ayrik Tasma Dosya Class'inin constructor'u
 */

FoldingSO::FoldingSO(const char * _filename, const char * linear_filename) : Folding(_filename) {
    endpoint = THOUSAND_MOD;

    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "FoldingSO(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                } else if(Collision(hashline) != 0) {
                    hashline = THOUSAND_MOD;

                    Composer(ONE);
                    endpoint++;

                    while(Collision(hashline) != 0) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                        // dosyanin max. boyutuna ulasmasi
                        if(!(hashline < (ENTRIES_NUM + THOUSAND_MOD))) {
                            cout << "FoldingSO(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is OVERFLOW" << endl;
                            break;
                        }
                    }
                    // Correction control
                    if(Collision(hashline) == 0) {
                        Write(Persona, hashline);
                        // islem sayisini artirma
                        transaction++;
                    }
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {

                    hashline = THOUSAND_MOD;

                    while(((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0) && (hashline < endpoint)) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                    }
                    // Correction control
                    if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                        // islem sayisini artirma
                        transaction++;
                    } else {
                        cout << "FoldingSO(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                    }
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Katlama Ayrik Tasma Dosya Class'inin destructor'u
 */

FoldingSO::~FoldingSO() {}

/**
 * Kare-Ortasi Class'inin constructor'u
 */

MidSquare::MidSquare(const char * _filename) : Base(_filename) {
    Composer(THOUSAND_MOD);
}

/**
 * Kare-Ortasi hash fonksiyonu
 */

unsigned int MidSquare::HashFunction(string _uid) {
    stringstream temp(_uid);

    unsigned int key = 0;
    temp >> key;

    unsigned int hashline = ((pow(key, 2)) / TENMILLION_DIV);
    hashline %= THOUSAND_MOD;

    return hashline;
}

/**
 * Kare-Ortasi Class'inin destructor'u
 */

MidSquare::~MidSquare() {}

/**
 * Bolen-Kalan Lineer Yoklama Dosya Class'inin constructor'u
 */

MidSquareLP::MidSquareLP(const char * _filename, const char * linear_filename) : MidSquare(_filename) {
    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "MidSquareLP(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;

                while(Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < THOUSAND_MOD)) {
                        hashline = 0;
                    }
                    // dosya dolu ise
                    if(hashline == homeline) {
                        cout << "MidSquareLP(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is FULL" << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);
                unsigned int homeline = hashline;
                // adres dolu ve kayit o adreste degil ise
                while((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0 && Collision(hashline) != 0) {
                    hashline++;

                    if(!(hashline < THOUSAND_MOD)) {
                        hashline = 0;
                    }
                    // kayit dosyada bulunamadi ise
                    if(hashline == homeline) {
                        cout << "MidSquareLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                        break;
                    }
                    // islem sayisini artirma
                    transaction++;
                }
                // Correction control
                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {
                    cout << "MidSquareLP(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Kare-Ortasi Lineer Yoklama Dosya Class'inin destructor'u
 */

MidSquareLP::~MidSquareLP() {}

/**
 * Kare-Ortasi Ayrik Tasma Dosya Class'inin constructor'u
 */

MidSquareSO::MidSquareSO(const char * _filename, const char * linear_filename) : MidSquare(_filename) {
    endpoint = THOUSAND_MOD;

    ifstream linear_file;
    linear_file.open(linear_filename, ios::in);

    if( !linear_file.is_open() ) {
        cout << "MidSquareSO(): " << "ERROR: " << linear_filename << " Can't be opened" << endl;
    } else {
        string redLine;
        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if(Collision(hashline) == 0) {
                    Write(Persona, hashline);
                    // islem sayisini artirma
                    transaction++;
                } else if(Collision(hashline) != 0) {
                    hashline = THOUSAND_MOD;

                    Composer(ONE);
                    endpoint++;

                    while(Collision(hashline) != 0) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                        // dosyanin max. boyutuna ulasmasi
                        if(!(hashline < (ENTRIES_NUM + THOUSAND_MOD))) {
                            cout << "MidSquareSO(): " << "ERROR: " << filename << " Can't write UID: " << Persona.uid << " file is OVERFLOW" << endl;
                            break;
                        }
                    }
                    // Correction control
                    if(Collision(hashline) == 0) {
                        Write(Persona, hashline);
                        // islem sayisini artirma
                        transaction++;
                    }
                }
            }
        }

        linear_file.clear();
        linear_file.seekg(0, ios::beg);

        while(linear_file.good()) {
            getline(linear_file, redLine);

            if(redLine.compare("\0") != 0) {
                Record Persona = Parser(redLine);

                unsigned int hashline = HashFunction(Persona.uid);

                if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                    // islem sayisini artirma
                    transaction++;
                } else {

                    hashline = THOUSAND_MOD;

                    while(((Search(Persona.uid, hashline)).compare(RECORD_FORM) == 0) && (hashline < endpoint)) {
                        hashline++;
                        // islem sayisini artirma
                        transaction++;
                    }
                    // Correction control
                    if((Search(Persona.uid, hashline)).compare(RECORD_FORM) != 0) {
                        // islem sayisini artirma
                        transaction++;
                    } else {
                        cout << "MidSquareSO(): " << "ERROR: " << " Can't find UID: " << Persona.uid << " in file " << filename << endl;
                    }
                }
            }
        }
        linear_file.close();
    }
}

/**
 * Kare-Ortasi Ayrik Tasma Class'inin destructor'u
 */

MidSquareSO::~MidSquareSO() {}
