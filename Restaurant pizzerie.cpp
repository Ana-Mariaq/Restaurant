#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<exception>
#include <cstring>
using namespace std;

class IngredienteDisponibile
{
private:
    char* NumeIngredient;
    float CantitateDisponibila;
    int Valabilitate;
    bool esteBio;
public:
    char* getNumeIngredient() {
        return this->NumeIngredient;
    }
    void setNumeIngredient(char* NumeIngredient) {
        if (NumeIngredient != nullptr)
        {
            this->NumeIngredient = new char[strlen(NumeIngredient) + 1];
            strcpy(this->NumeIngredient, NumeIngredient);
        }
    }

    float getCantitateDisponibila() {
        return this->CantitateDisponibila;
    }
    void setCantitateDisponibila(float CantitateDisponibila) {
        if (CantitateDisponibila >= 0) {
            this->CantitateDisponibila = CantitateDisponibila;
        }
    }

    int getValabilitate() {
        return this->Valabilitate;
    }
    void setValabilitate(int Valabilitate) {
        if (Valabilitate > 0)
            this->Valabilitate = Valabilitate;
    }

    bool getesteBio() {
        return this->esteBio;
    }
    void setesteBio(bool esteBio) {
        this->esteBio = esteBio;
    }

    IngredienteDisponibile() {
        this->NumeIngredient = nullptr;
        this->CantitateDisponibila = 0;
        this->Valabilitate = 0;
        this->esteBio = false;
    }

    IngredienteDisponibile(char* NumeIngredient, float CantitateDisponibila) {
        if (NumeIngredient != nullptr)
        {
            this->NumeIngredient = new char[strlen(NumeIngredient) + 1];
            strcpy(this->NumeIngredient, NumeIngredient);
        }
        if (CantitateDisponibila >= 0)
            this->CantitateDisponibila = CantitateDisponibila;
        else
            this->CantitateDisponibila = 0;
    }

    IngredienteDisponibile(char* NumeIngredient, float CantitateDisponibila, int Valabilitate, bool esteBio) {
        if (NumeIngredient != nullptr)
        {
            this->NumeIngredient = new char[strlen(NumeIngredient) + 1];
            strcpy(this->NumeIngredient, NumeIngredient);
        }
        if (CantitateDisponibila >= 0 && Valabilitate > 0)
        {
            this->CantitateDisponibila = CantitateDisponibila;
            this->Valabilitate = Valabilitate;
        }
        else
        {
            this->CantitateDisponibila = 0;
            this->Valabilitate = 0;
        }
        this->esteBio = esteBio;
    }

    IngredienteDisponibile(const IngredienteDisponibile& a) {
        if (a.NumeIngredient != nullptr)
        {
            this->NumeIngredient = new char[strlen(a.NumeIngredient) + 1];
            strcpy(this->NumeIngredient, a.NumeIngredient);
        }
        if (a.CantitateDisponibila >= 0 && a.Valabilitate > 0) {
            this->CantitateDisponibila = a.CantitateDisponibila;
            this->Valabilitate = a.Valabilitate;
        }
        else
        {
            this->CantitateDisponibila = 0;
            this->Valabilitate = 0;
        }
        this->esteBio = a.esteBio;
    }

    ~IngredienteDisponibile() {
        delete[]NumeIngredient;
        this->NumeIngredient = nullptr;
    }

    IngredienteDisponibile& operator=(const IngredienteDisponibile& a)
    {
        delete[] this->NumeIngredient;
        this->NumeIngredient = nullptr;
        if (this != &a)
        {
            this->NumeIngredient = new char[strlen(a.NumeIngredient) + 1];
            strcpy(this->NumeIngredient, a.NumeIngredient);
            this->CantitateDisponibila = a.CantitateDisponibila;
            this->Valabilitate = a.Valabilitate;
            this->esteBio = a.esteBio;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const IngredienteDisponibile& a) {
        if (a.NumeIngredient != nullptr)
        {
            out << "\nDenumire: " << a.NumeIngredient;
        }
        else
        {
            out << "-";
        }
        out << "\nCantitate disponibila: " << a.CantitateDisponibila << " grame";
        out << "\nValabilitate: " << a.Valabilitate << " zile";
        out << "\nEste BIO: ";
        if (a.esteBio) {
            out << "Da";
        }
        else {
            out << "Nu";
        }
        out << "\n-------------------------------------------------";
        return out;
    }

    friend istream& operator>>(istream& in, IngredienteDisponibile& a) {
        delete[] a.NumeIngredient;
        a.NumeIngredient = nullptr;
        cout << "\n------------ Adaugare ingredient nou ------------";
        cout << "\nIntroduceti denumirea: ";
        char buffer[30];
        in >> buffer;
        a.NumeIngredient = new char[strlen(buffer) + 1];
        strcpy(a.NumeIngredient, buffer);
        cout << "\nIntroduceti cantitatea disponibila: ";
        in >> a.CantitateDisponibila;
        if (a.CantitateDisponibila <= 0)
            a.CantitateDisponibila = 0;
        cout << "\nIntroduceti valabilitatea: ";
        in >> a.Valabilitate;
        if (a.Valabilitate <= 0)
            a.Valabilitate = 0;
        cout << "\nIntroduceti daca ingredientul este BIO: ";
        in >> a.esteBio;
        cout << "\n-------------------------------------------------";
        return in;
    }

    operator const char* () const {
        return this->NumeIngredient;
    }

};

class Retetar {
private:
    int id;
    int NrIngredienteNecesare;
    float* CantitatiNecesare;
    IngredienteDisponibile* IngredienteNecesare;
public:

    int getId() const {
        return this->id;
    }
    void setId(int id) {
        if (id > 0)
            this->id = id;
    }

    int getNrIngredienteNecesare() {
        return this->NrIngredienteNecesare;
    }
    void setNrIngredienteNecesare(int NrIngredienteNecesare) {
        if (NrIngredienteNecesare > 0)
            this->NrIngredienteNecesare = NrIngredienteNecesare;
    }

    float* getCantitatiNecesare() {
        return this->CantitatiNecesare;
    }
    void setCantitatiNecesare(float* CantitatiNecesare, int NrIngredienteNecesare) {
        if (NrIngredienteNecesare > 0) {
            this->NrIngredienteNecesare = NrIngredienteNecesare;
            if (this->CantitatiNecesare != nullptr) {
                this->CantitatiNecesare = new float[this->NrIngredienteNecesare];
                for (int i = 0; i < this->NrIngredienteNecesare; i++)
                    this->CantitatiNecesare[i] = CantitatiNecesare[i];
            }
        }
    }

    IngredienteDisponibile* getIngredienteNecesare() {
        return this->IngredienteNecesare;
    }
    void setIngredienteNecesare(IngredienteDisponibile* nou, int NrIngredienteNecesare) {
        if (NrIngredienteNecesare > 0 && nou != nullptr) {
            this->NrIngredienteNecesare = NrIngredienteNecesare;
            this->IngredienteNecesare = new IngredienteDisponibile[this->NrIngredienteNecesare];
            for (int i = 0; i < this->NrIngredienteNecesare; i++)
                this->IngredienteNecesare[i] = nou[i];
        }
    }

    Retetar() {
        this->id = 0;
        this->NrIngredienteNecesare = 0;
        this->IngredienteNecesare = nullptr;
        this->CantitatiNecesare = nullptr;
    }

    Retetar(int id, int NrIngredienteNeceare, IngredienteDisponibile* IngredienteNecesare) {
        if (id > 0)
            this->id = id;
        if (NrIngredienteNecesare > 0 && IngredienteNecesare != nullptr) {
            this->NrIngredienteNecesare = NrIngredienteNecesare;
            this->IngredienteNecesare = new IngredienteDisponibile[this->NrIngredienteNecesare];
            for (int i = 0; i < this->NrIngredienteNecesare; i++)
                this->IngredienteNecesare[i] = IngredienteNecesare[i];
        }
        else {
            this->NrIngredienteNecesare = 0;
            this->IngredienteNecesare = nullptr;
        }
    }


    Retetar(int id, int NrIngredienteNecesare, float* CantitatiNecesare, IngredienteDisponibile* IngredienteNecesare) {
        if (id > 0)
            this->id = id;
        if (NrIngredienteNecesare > 0 && CantitatiNecesare != nullptr && IngredienteNecesare != nullptr) {
            this->NrIngredienteNecesare = NrIngredienteNecesare;
            this->CantitatiNecesare = new float[this->NrIngredienteNecesare];
            for (int i = 0; i < this->NrIngredienteNecesare; i++)
                this->CantitatiNecesare[i] = CantitatiNecesare[i];
            this->IngredienteNecesare = new IngredienteDisponibile[this->NrIngredienteNecesare];
            for (int i = 0; i < this->NrIngredienteNecesare; i++)
                this->IngredienteNecesare[i] = IngredienteNecesare[i];
        }
        else {
            this->NrIngredienteNecesare = 0;
            this->CantitatiNecesare = nullptr;
            this->IngredienteNecesare = nullptr;
        }
    }

    Retetar(const Retetar& r) {
        if (id > 0)
            this->id = r.id;
        if (r.NrIngredienteNecesare > 0 && r.CantitatiNecesare != nullptr) {
            this->NrIngredienteNecesare = r.NrIngredienteNecesare;
            this->CantitatiNecesare = new float[r.NrIngredienteNecesare];
            for (int i = 0; i < r.NrIngredienteNecesare; i++)
                this->CantitatiNecesare[i] = r.CantitatiNecesare[i];
        }
        else
        {
            this->NrIngredienteNecesare = 0;
            this->CantitatiNecesare = nullptr;
        }
        if (r.NrIngredienteNecesare > 0 && r.IngredienteNecesare != nullptr) {
            this->IngredienteNecesare = new IngredienteDisponibile[r.NrIngredienteNecesare];
            for (int i = 0; i < r.NrIngredienteNecesare; i++)
                this->IngredienteNecesare[i] = r.IngredienteNecesare[i];
        }
        else {
            this->NrIngredienteNecesare = 0;
            this->IngredienteNecesare = nullptr;

        }
    }

    ~Retetar() {
        delete[]CantitatiNecesare;
        this->CantitatiNecesare = nullptr;
    }

    Retetar& operator=(const Retetar& r) {
        if (this != &r) {
            this->id = r.id;
            this->NrIngredienteNecesare = r.NrIngredienteNecesare;
            delete[] this->CantitatiNecesare;
            delete[] this->IngredienteNecesare;
            if (r.NrIngredienteNecesare > 0) {
                this->CantitatiNecesare = new float[r.NrIngredienteNecesare];
                this->IngredienteNecesare = new IngredienteDisponibile[r.NrIngredienteNecesare];
                for (int i = 0; i < r.NrIngredienteNecesare; i++) {
                    this->CantitatiNecesare[i] = r.CantitatiNecesare[i];
                    this->IngredienteNecesare[i] = r.IngredienteNecesare[i];
                }
            }
            else {
                this->CantitatiNecesare = nullptr;
                this->IngredienteNecesare = nullptr;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Retetar& r) {
        out << "\nID: " << r.id;
        out << "\nNumarul de ingrediente necesare: " << r.NrIngredienteNecesare;
        out << "\nIngrediente necesare: ";
        if (r.IngredienteNecesare != nullptr)
        {
            for (int i = 0; i < r.NrIngredienteNecesare; i++)
                out << static_cast<const char*>(r.IngredienteNecesare[i]) << " ";
        }
        else
        {
            out << "-";
        }

        if (r.CantitatiNecesare != nullptr)
        {
            out << "\nCantitati necesare: ";
            for (int i = 0; i < r.NrIngredienteNecesare; i++)
                out << r.CantitatiNecesare[i] << " ";
        }
        else
        {
            out << "-";
        }
        out << "\n-------------------------------------------------";
        return out;
    }

    friend istream& operator>>(istream& in, Retetar& r) {
        cout << "\n-------------- Adaugare reteta noua --------------";
        cout << "\nIntroduceti ID-ul retetei: ";
        in >> r.id;
        cout << "\nIntroduceti numarul de ingrediente necesare: ";
        in >> r.NrIngredienteNecesare;
        if (r.NrIngredienteNecesare > 0) {
            delete[] r.CantitatiNecesare;
            delete[] r.IngredienteNecesare;

            r.CantitatiNecesare = new float[r.NrIngredienteNecesare];
            r.IngredienteNecesare = new IngredienteDisponibile[r.NrIngredienteNecesare];
            cout << "\nIntroduceti denumirile ingredientelor (cu spatiu intre ele): ";
            for (int i = 0; i < r.NrIngredienteNecesare; ++i) {
                char buffer[30];
                in >> buffer;
                r.IngredienteNecesare[i].setNumeIngredient(buffer);
            }
            cout << "\nIntroduceti cantitatile necesare(cu spatiu intre ele): ";
            for (int i = 0; i < r.NrIngredienteNecesare; ++i) {
                in >> r.CantitatiNecesare[i];
            }
        }
        else {
            r.NrIngredienteNecesare = 0;
            r.CantitatiNecesare = nullptr;
            r.IngredienteNecesare = nullptr;
        }
        cout << "\n-------------------------------------------------";
        return in;
    }

    operator int() const {
        return this->id;
    }
};

class Preparat {
private:
    char* Nume;
    Retetar Reteta;
    float Pret;
    string Alergeni;
    static int NumarPreparate;
public:

    char* getNume() const {
        return this->Nume;
    }
    void setNume(char* Nume) {
        if (Nume != nullptr)
        {
            this->Nume = new char[strlen(Nume) + 1];
            strcpy(this->Nume, Nume);
        }
    }

    Retetar getReteta() {
        return this->Reteta;
    }
    void setReteta(Retetar nou)
    {
        this->Reteta = nou;
    }

    float getPret() {
        return this->Pret;
    }
    void setPret(float Pret) {
        if (Pret >= 0)
            this->Pret = Pret;
    }

    string getAlergeni() {
        return this->Alergeni;
    }
    void setAlergeni(string Alergeni) {
        if (Alergeni.length() >= 2)
            this->Alergeni = Alergeni;
    }

    Preparat() {
        this->Nume = nullptr;
        this->Reteta = Retetar();
        this->Pret = 0;
        this->Alergeni = "necunoscut";
    }

    Preparat(char* Nume, float Pret) {
        if (Nume != nullptr)
        {
            this->Nume = new char[strlen(Nume) + 1];
            strcpy(this->Nume, Nume);
        }
        else
        {
            this->Nume = nullptr;
        }
        if (Pret > 0)
            this->Pret = Pret;
        else {
            this->Pret = 0;
        }
        NumarPreparate++;
    }

    Preparat(char* Nume, Retetar Reteta, float Pret, string Alergeni) {
        if (Nume != nullptr)
        {
            this->Nume = new char[strlen(Nume) + 1];
            strcpy(this->Nume, Nume);
        }
        else
        {
            this->Nume = nullptr;
        }
        this->Reteta = Reteta;
        if (Pret > 0)
            this->Pret = Pret;
        else {
            this->Pret = 0;
        }
        if (Alergeni.length() >= 2)
            this->Alergeni = Alergeni;
        NumarPreparate++;
    }

    Preparat(const Preparat& p) {
        if (p.Nume != nullptr) {
            this->Nume = new char[strlen(p.Nume) + 1];
            strcpy(this->Nume, p.Nume);
        }
        else {
            this->Nume = nullptr;
        }
        this->Reteta = p.Reteta;
        this->Pret = p.Pret;
        this->Alergeni = p.Alergeni;
    }

    Preparat& operator=(const Preparat& p) {
        if (this != &p) {
            delete[] this->Nume;
            if (p.Nume != nullptr) {
                this->Nume = new char[strlen(p.Nume) + 1];
                strcpy(this->Nume, p.Nume);
            }
            else {
                this->Nume = nullptr;
            }
            this->Reteta = p.Reteta;
            this->Pret = p.Pret;
            this->Alergeni = p.Alergeni;
        }
        return *this;
    }

    ~Preparat() {
        delete[]Nume;
        this->Nume = nullptr;
    }

    friend ostream& operator<<(ostream& out, const Preparat& p) {
        out << "\nDenumire preparat: ";
        if (p.Nume != nullptr) {
            out << p.Nume;
        }
        else {
            out << "-";
        }
        out << "\nID-ul retetei: " << static_cast<unsigned int>(p.Reteta.getId());
        out << "\nPretul: ";
        if (p.Pret > 0) {
            out << p.Pret << " lei";
        }
        else {
            out << "0";
        }
        out << "\nAlergeni: " << p.Alergeni;
        out << "\n-------------------------------------------------";
        return out;
    }

    friend istream& operator>>(istream& in, Preparat& p) {
        cout << "\n-------------- Adaugare preparat nou --------------";
        char buffer[50];
        cout << "\nIntroduceti numele preparatului: ";
        in >> buffer;
        if (p.Nume != nullptr) {
            delete[] p.Nume;
        }
        p.setNume(buffer);
        cout << "\nCreati o noua reteta";
        Retetar r;
        in >> r;
        p.setReteta(r);
        int pret;
        cout << "\nIntroduceti pretul preparatului: ";
        in >> pret;
        if (pret > 0)
            p.setPret(pret);
        else
            p.setPret(0);
        string alergeni;
        cout << "\nIntroduceti alergenii: ";
        in >> alergeni;
        if (alergeni.length() >= 3)
            p.setAlergeni(alergeni);
        else
            p.setAlergeni("necunoscut");
        return in;
    }

    operator string() const {
        return this->Nume;
    }

    float operator+(const Preparat& p) {
        return this->Pret + p.Pret;
    }
};
int Preparat::NumarPreparate = 0;
class Meniu {
private:
    Preparat* listaPreparate;
    int numarPreparate;
public:

    int getnumarPreparate() {
        return this->numarPreparate;
    }
    void setnumarPreparate(int numarPreparate) {
        if (numarPreparate > 0)
            this->numarPreparate = numarPreparate;
    }

    Preparat* getlistaPreparate() {
        return this->listaPreparate;
    }
    void setlistaPreparate(Preparat* nou, int numarPreparate) {
        if (numarPreparate > 0 && nou != nullptr) {
            this->numarPreparate = numarPreparate;
            this->listaPreparate = new Preparat[this->numarPreparate];
            for (int i = 0; i < this->numarPreparate; i++)
                this->listaPreparate[i] = nou[i];
        }
    }

    Meniu() {
        this->listaPreparate = nullptr;
        this->numarPreparate = 0;
    }

    Meniu(int numarPreparate) {
        if (numarPreparate > 0)
        {
            this->numarPreparate = numarPreparate;
        }
        else
        {
            this->numarPreparate = 0;
        }
    }

    Meniu(Preparat* listaPreparate, int numarPreparate) {
        if (numarPreparate > 0 && listaPreparate != nullptr)
        {
            this->numarPreparate = numarPreparate;
            this->listaPreparate = new Preparat[this->numarPreparate];
            for (int i = 0; i < numarPreparate; i++)
                this->listaPreparate[i] = listaPreparate[i];
        }
        else
        {
            this->numarPreparate = 0;
            this->listaPreparate = nullptr;
        }
    }

    Meniu(const Meniu& m) {
        if (m.numarPreparate > 0 && m.listaPreparate != nullptr) {
            this->numarPreparate = m.numarPreparate;
            this->listaPreparate = new Preparat[this->numarPreparate];
            for (int i = 0; i < m.numarPreparate; i++)
                this->listaPreparate[i] = m.listaPreparate[i];
        }
        else {
            this->numarPreparate = 0;
            this->listaPreparate = nullptr;
        }
    }

    ~Meniu() {
        delete[]listaPreparate;
        this->listaPreparate = nullptr;
    }

    Meniu& operator=(const Meniu& m) {
        if (this != &m) {
            delete[] this->listaPreparate;
            if (m.numarPreparate > 0 && m.listaPreparate != nullptr) {
                this->numarPreparate = m.numarPreparate;
                this->listaPreparate = new Preparat[this->numarPreparate];
                for (int i = 0; i < this->numarPreparate; i++) {
                    this->listaPreparate[i] = m.listaPreparate[i];
                }
            }
            else {
                this->numarPreparate = 0;
                this->listaPreparate = nullptr;
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Meniu& m) {
        if (m.listaPreparate != nullptr) {
            for (int i = 0; i < m.numarPreparate; i++) {
                out << "\n" << m.listaPreparate[i].getNume();
                out << "\nPret: " << m.listaPreparate[i].getPret() << " lei";
                out << "\nAlergeni: " << m.listaPreparate[i].getAlergeni();
                out << "\n------------------------------------------------";
            }
        }
        else {
            out << "-";
        }
        return out;
    }

    friend istream& operator>>(istream& in, Meniu& m) {
        cout << "\nIntroduceti numarul de preparate din meniu: ";
        int numarPreparate;
        in >> numarPreparate;
        in.ignore();
        if (numarPreparate > 0) {
            Preparat* preparate = new Preparat[numarPreparate];
            for (int i = 0; i < numarPreparate; ++i) {
                char nume[100];
                float pret;
                char alergeni[100];

                cout << "Introduceti numele preparatului " << (i + 1) << ": ";
                in.getline(nume, 100);

                cout << "Introduceti pretul preparatului " << (i + 1) << ": ";
                in >> pret;
                in.ignore();

                cout << "Introduceti alergenii preparatului " << (i + 1) << ": ";
                in.getline(alergeni, 100);

                preparate[i].setNume(nume);
                preparate[i].setPret(pret);
                preparate[i].setAlergeni(alergeni);
            }
            m.setlistaPreparate(preparate, numarPreparate);
            delete[] preparate;
        }
        return in;
    }
};

class Comanda
{
private:
    const int id;
    Preparat* PreparateComandate;
    int numarPreparate;
    float ValoareTotala;
    bool StatusComanda;
    Meniu meniu;
public:

    int getNumarPreparate() {
        return this->numarPreparate;
    }
    void setNumarPreparate(int numarPreparate) {
        if (numarPreparate > 0)
            this->numarPreparate = numarPreparate;
    }

    Preparat* getPreparateComandate() {
        return this->PreparateComandate;
    }
    void setPreparateComandate(Preparat* nou, int numarPreparate) {
        if (numarPreparate > 0 && nou != nullptr) {
            this->numarPreparate = numarPreparate;
            this->PreparateComandate = new Preparat[this->numarPreparate];
            for (int i = 0; i < this->numarPreparate; i++)
                this->PreparateComandate[i] = nou[i];
        }
    }

    float getValoareTotala() {
        return this->ValoareTotala;
    }
    void setValoareTotala() {
        if (ValoareTotala > 0)
            this->ValoareTotala = ValoareTotala;
    }

    bool getStatusComanda() {
        return this->StatusComanda;
    }
    void setStatusComanda(bool StatusComanda) {
        this->StatusComanda = StatusComanda;
    }

    Comanda(int id) : id(id) {}

    Comanda() :id(0) {
        this->PreparateComandate = nullptr;
        this->numarPreparate = 0;
        this->ValoareTotala = 0;
        this->StatusComanda = false;
    }

    Comanda(int id, Preparat* PreparateComandate, int numarPreparate) : id(id) {
        if (numarPreparate > 0 && PreparateComandate != nullptr)
        {
            this->numarPreparate = numarPreparate;
            this->PreparateComandate = new Preparat[this->numarPreparate];
            for (int i = 0; i < numarPreparate; i++)
                this->PreparateComandate[i] = PreparateComandate[i];
        }
        else
        {
            this->numarPreparate = 0;
            this->PreparateComandate = nullptr;
        }
    }

    Comanda(int id, Preparat* PreparateComandate, int numarPreparate, float ValoareTotala, bool StatusComanda) : id(id) {
        if (numarPreparate > 0 && PreparateComandate != nullptr)
        {
            this->numarPreparate = numarPreparate;
            this->PreparateComandate = new Preparat[this->numarPreparate];
            for (int i = 0; i < numarPreparate; i++)
                this->PreparateComandate[i] = PreparateComandate[i];
        }
        else
        {
            this->numarPreparate = 0;
            this->PreparateComandate = nullptr;
        }
        if (ValoareTotala > 0)
            this->ValoareTotala = ValoareTotala;
        else
            this->ValoareTotala = 0;
        this->StatusComanda = StatusComanda;
    }

    Comanda(const Comanda& c) : id(c.id) {
        if (c.numarPreparate > 0 && c.PreparateComandate != nullptr) {
            this->numarPreparate = c.numarPreparate;
            this->PreparateComandate = new Preparat[this->numarPreparate];
            for (int i = 0; i < numarPreparate; i++)
                this->PreparateComandate[i] = c.PreparateComandate[i];
        }
        else {
            this->numarPreparate = 0;
            this->PreparateComandate = nullptr;
        }
        if (ValoareTotala > 0)
            this->ValoareTotala = c.ValoareTotala;
        else
            this->ValoareTotala = 0;
        this->StatusComanda = c.StatusComanda;
    }

    ~Comanda() {
        delete[]PreparateComandate;
        this->PreparateComandate = nullptr;
    }

    Comanda& operator=(const Comanda& c) {
        if (this != &c) {
            delete[] this->PreparateComandate;
            if (c.numarPreparate > 0 && c.PreparateComandate != nullptr) {
                this->numarPreparate = c.numarPreparate;
                this->PreparateComandate = new Preparat[this->numarPreparate];
                for (int i = 0; i < numarPreparate; i++)
                    this->PreparateComandate[i] = c.PreparateComandate[i];
            }
            else {
                this->numarPreparate = 0;
                this->PreparateComandate = nullptr;
            }
            this->ValoareTotala = c.ValoareTotala;
            this->StatusComanda = c.StatusComanda;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, Comanda& c) {
        out << "\nID comanda: " << c.id;
        out << "\nNumar de preparate: " << c.numarPreparate;
        out << "\nPreparate comandate: ";
        if (c.PreparateComandate != nullptr) {
            for (int i = 0; i < c.numarPreparate; i++) {
                out << c.PreparateComandate[i].getNume() << " ";
            }
        }
        else {
            out << "-";
        }
        c.calculeazaValoareTotala();
        out << "\nValoare totala: " << c.ValoareTotala << " lei";
        out << "\nStatus comanda: " << (c.StatusComanda ? "Plasata" : "Comanda nu a putut fi plasata deoarece ati introdus cel putin un preparat care nu se afla in meniu.");
        out << "\n-------------------------------------------------";
        return out;
    }

    friend istream& operator>>(istream& in, Comanda& c) {
        delete[] c.PreparateComandate;
        c.PreparateComandate = nullptr;
        cout << "\nCOMANDATI AICI:";
        cout << "\n--------------";
        cout << "\nIntroduceti numarul de produse: ";
        in >> c.numarPreparate;
        in.ignore();
        c.PreparateComandate = new Preparat[c.numarPreparate];
        c.StatusComanda = true;
        for (int i = 0; i < c.numarPreparate; i++) {
            cout << "\nIntroduceti numele produsului " << i + 1 << ": ";
            string numeProdus;
            getline(in, numeProdus);
            c.PreparateComandate[i].setNume(const_cast<char*>(numeProdus.c_str()));
            cout << "\nIntroduceti pretul produsului " << numeProdus << ": ";
            float pret;
            in >> pret;
            in.ignore();
            c.PreparateComandate[i].setPret(pret);
            if (!(numeProdus == "Pizza Margherita" || numeProdus == "Pizza Pepperoni" ||
                numeProdus == "Pizza Quattro Stagioni" || numeProdus == "Pizza Napoletana" ||
                numeProdus == "Pizza Capricciosa" || numeProdus == "Pizza Marinara")) {
                c.StatusComanda = false;
            }
        }
        cout << "\n-------------------------------------------------";
        return in;
    }

    void calculeazaValoareTotala() {
        ValoareTotala = 0;
        for (int i = 0; i < numarPreparate; i++) {
            ValoareTotala = ValoareTotala + PreparateComandate[i].getPret();
        }
    }
};
int main() {

    //Definirea ingredientelor
    char nume1[] = "sos de rosii";
    IngredienteDisponibile Ingr1(nume1, 5000, 90, true);

    char nume2[] = "pepperoni";
    IngredienteDisponibile Ingr2(nume2, 2000, 40, false);

    char nume3[] = "ciuperci";
    IngredienteDisponibile Ingr3(nume3, 4500, 10, true);

    char nume4[] = "mozzarella";
    IngredienteDisponibile Ingr4(nume4, 2000, 55, false);

    char nume5[] = "sunca";
    IngredienteDisponibile Ingr5(nume5, 5000, 30, false);

    //Definirea retetelor 
    float CantitatiNecesare1[] = { 150,300,50 };
    IngredienteDisponibile IngredienteNecesare1[] = { Ingr1, Ingr2, Ingr4 };
    Retetar r1(1, 3, CantitatiNecesare1, IngredienteNecesare1);

    float CantitatiNecesare2[] = { 155, 50, 40 };
    IngredienteDisponibile IngredienteNecesare2[] = { Ingr1, Ingr2, Ingr5 };
    Retetar r2(2, 3, CantitatiNecesare2, IngredienteNecesare2);

    float CantitatiNecesare3[] = { 234, 342, 323, 30 };
    IngredienteDisponibile IngredienteNecesare3[] = { Ingr1, Ingr5, Ingr3,Ingr4 };
    Retetar r3(3, 4, CantitatiNecesare3, IngredienteNecesare3);

    float CantitatiNecesare4[] = { 105, 50 };
    IngredienteDisponibile IngredienteNecesare4[] = { Ingr1, Ingr2 };
    Retetar r4(4, 2, CantitatiNecesare4, IngredienteNecesare4);

    float CantitatiNecesare5[] = { 40, 233, 100 };
    IngredienteDisponibile IngredienteNecesare5[] = { Ingr1, Ingr3,Ingr5 };
    Retetar r5(5, 3, CantitatiNecesare5, IngredienteNecesare5);

    float CantitatiNecesare6[] = { 344, 50, 46,544,122 };
    IngredienteDisponibile IngredienteNecesare6[] = { Ingr1, Ingr2, Ingr3,Ingr4,Ingr5 };
    Retetar r6(6, 5, CantitatiNecesare6, IngredienteNecesare6);

    // Definirea preparatelor
    char denumire1[] = "Pizza Margherita";
    Preparat p1(denumire1, r1, 25, "ou gluten");

    char denumire2[] = "Pizza Pepperoni";
    Preparat p2(denumire2, r2, 30, "gluten ciuperci");

    char denumire3[] = "Pizza Quattro Stagioni";
    Preparat p3(denumire3, r3, 34, "ou");

    char denumire4[] = "Pizza Napoletana";
    Preparat p4(denumire4, r4, 31, "ou lactoza");

    char denumire5[] = "Pizza Capricciosa";
    Preparat p5(denumire5, r5, 38, "gluten");

    char denumire6[] = "Pizza Marinara";
    Preparat p6(denumire5, r6, 28, "lactoza ou");

    //afisare Meniu
    Preparat* preparate = new Preparat[6]{ p1, p2 ,p3, p4, p5, p6 };

    Meniu m(preparate, 6);
    cout << "\n- - - - - - - - - MENIU PIZZERIE - - - - - - - - \n";
    cout << m << endl;

    // citire Comanda
    try {
        Comanda cNou(1);
        cin >> cNou;
        cout << "\n- DETALII COMANDA - " << cNou << endl;
    }
    catch (const exception& e) {
        cerr << "Exceptie: " << e.what() << endl;
    }
    /*
    //testare afisare ingrediente disponibile
    cout << "- - - - - - - - LISTA INGREDIENTE - - - - - - - - ";
    char nume1[] = "sos de rosii";
    IngredienteDisponibile Ingr1(nume1, 5000, 90, true);
    cout << Ingr1 << endl;
    char nume2[] = "pepperoni";
    IngredienteDisponibile Ingr2(nume2, 2000, 40, false);
    cout << Ingr2 << endl;
    char nume3[] = "ciuperci";
    IngredienteDisponibile Ingr3(nume3, 4500, 10, true);
    cout << Ingr3 << endl;
    char nume4[] = "mozzarella";
    IngredienteDisponibile Ingr4(nume4, 2000, 55, false);
    cout << Ingr4 << endl;

    //testare citire ingrediente disponibile
      try {
          IngredienteDisponibile IngrNou;
          cin >> IngrNou;
          cout << " \n- Ingredientul nou adaugat - " << IngrNou << endl;
      }
      catch (const exception& e) {
          cerr << "Exceptie: " << e.what() << endl;
      }

    //testare afisare retetar
    float CantitatiNecesare1[] = { 150, 300,50 };
    IngredienteDisponibile IngredienteNecesare1[] = { Ingr1, Ingr2, Ingr4 };
    Retetar r1(1, 3, CantitatiNecesare1, IngredienteNecesare1);
    cout << "\n- - - - - - - - - - RETETAR - - - - - - - - - - - \n";
    cout << r1 << endl;
    float CantitatiNecesare2[] = { 155, 50, 46 };
    IngredienteDisponibile IngredienteNecesare2[] = { Ingr1, Ingr2, Ingr3 };
    Retetar r2(2, 3, CantitatiNecesare2, IngredienteNecesare2);
    cout << r2 << endl;

    //testare citire retetar
    try {
         Retetar rNou;
         cin >> rNou;
         cout << "\n- Reteta noua - " << rNou << endl;
     }
     catch (const exception& e) {
         cerr << "Exceptie: " << e.what() << endl;
     }

    //testare afisare preparat
       cout << "\n- - - - - - - - - - PREPARAT - - - - - - - - - - -\n";
        char denumire1[] = "Pizza Margherita";
        Preparat p1(denumire1, r1, 25, "ou");
        cout << p1 << endl;
        char denumire2[] = "Pizza Pepperoni";
        Preparat p2(denumire2, r2, 30, "gluten");
        cout << p2 << endl;

   // Testare citire Preparat
            try {
                Preparat pNou;
                cin >> pNou;
                cout << "\n- Preparatul nou adaugat - " << pNou << endl;
            }
            catch (const exception& e) {
                cerr << "Exceptie: " << e.what() << endl;
            }

   //testare afisare meniu
        Preparat* preparate = new Preparat[3]{ p1, p2};
        Meniu m(preparate, 2);
        cout << "\n- - - - - - - - - MENIU PIZZERIE - - - - - - - - \n";
        cout << m << endl;

    // Testare citire Meniu
     try {
         Meniu mNou;
         cin >> mNou;
         cout << "\n- Meniul nou adaugat - " << mNou << endl;
     }
     catch (const exception& e) {
         cerr << "Exceptie: " << e.what() << endl;
     }

     // Testare afișare Comanda
    Preparat preparateComandate[] = { p1, p2 };
    Comanda c1(1, preparateComandate, 2, 0.0, true);
    cout << "\n- - - - - - - - - - COMANDA - - - - - - - - - - -\n";
    cout << c1 << endl;

     // Testare citire Comanda
    try {
        Comanda cNou;
        cin >> cNou;
        cout << "\n- Comanda noua - " << cNou << endl;
    }
    catch (const exception& e) {
        cerr << "Exceptie: " << e.what() << endl;
    }
 */
    return 0;
}

