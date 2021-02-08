/* Nume:Lapadus, Prenume:Raluca, Grupa:254
Compilator: CodeBlocks 17.12 GNU CC Compiler
Tutore Laborator: Gusatu Marian */
#include<iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

///************************************JUCARIE*******************************************************************///
class jucarie{
protected:
    string denumire;
    int dimensiune;
    string tip;
    static int nr_jucarii;
public:

    jucarie(string, int, string);
    virtual ~jucarie();
    jucarie(const jucarie&);
    jucarie& operator=(jucarie&);

    void set_denumire(string denumire){this->denumire=denumire;}
    string get_denumire()const{return denumire;}



    virtual void citire(istream&);
    friend istream& operator>>(istream&, jucarie&);

    virtual void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, jucarie&);

    static void nr_com()
    {
        cout<<"Nr total de : "<<nr_jucarii<<endl;
    }
    static int get_nr_(){return nr_jucarii;}
};
int jucarie::nr_jucarii;
jucarie:: jucarie(string denumire=" ", int dimensiune=0, string tip=" ")
{
    this->denumire=denumire;
    this->dimensiune=dimensiune;
    this->tip=tip;
}
jucarie::~jucarie()
{
    this->denumire=" ";
    this->dimensiune=0;
    this->tip=" ";
}
jucarie::jucarie(const jucarie& j)
{
    this->denumire=j.denumire;
    this->dimensiune=j.dimensiune;
    this->tip=j.tip;
}
jucarie& jucarie::operator=(jucarie& j)
{
    if(this!=&j)
    {
         this->denumire=j.denumire;
        this->dimensiune=j.dimensiune;
        this->tip=j.tip;
    }
    return *this;
}
void jucarie::citire(istream& in)
{
    cout<<"Introduceti denumirea jucariei: ";
    in>>denumire;
    cout<<"Introduceti dimensiunea: ";
    in>>dimensiune;
    cout<<"Introduceti tipul jucariei: ";
    in>>tip;
}
istream& operator>>(istream& in, jucarie& j)
{
    j.citire(in);
    return in;
}
void jucarie::afisare(ostream& out)const
{
    out<<"Denumirea este: "<<denumire<<endl;
    out<<"Dimenizunea este: "<<dimensiune<<endl;
    out<<"Tipul este: "<<tip<<endl;
}
ostream& operator<<(ostream& out, jucarie& j)
{
    j.afisare(out);
    return out;
}
///******************************************CLASICA**********************************************************************************///
class clasica:public jucarie{
private:
    string material;
    string culoare;
    static int nr_clasice;
public:

    clasica(string, int, string, string, string);
    ~clasica();
    clasica(const clasica&);
    clasica& operator=(clasica&);


    void citire(istream&);
    friend istream& operator>>(istream&, clasica&);

    void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, clasica&);

    static void nr_com()
    {
        cout<<"Nr total de clasice: "<<nr_clasice;
    }
    static int get_nr_clasice(){return nr_clasice;}
};
int clasica::nr_clasice;
clasica:: clasica(string denumire=" ", int dimensiune=0, string tip=" ", string material=" ", string culoare=" "):jucarie(denumire, dimensiune, tip)
{
    this->tip=tip;
    this->culoare=culoare;
}
clasica::~clasica()
{
    this->tip=" ";
    this->culoare=" ";
}
clasica::clasica(const clasica& c):jucarie(c)
{
    this->tip=c.tip;
    this->culoare=c.culoare;
}
clasica& clasica::operator=(clasica& c)
{
    if(this!=&c)
    {
        jucarie::operator=(c);
        this->tip=c.tip;
        this->culoare=c.culoare;
    }
    return *this;
}
void clasica::citire(istream& in)
{
    jucarie::citire(in);
    cout<<"Introduceti materialul: ";
    in>>material;
    cout<<"Introduceti culoarea: ";
    in>>culoare;

}
istream& operator>>(istream& in, clasica& c)
{
    c.citire(in);
    return in;
}
void clasica::afisare(ostream& out)const
{
    jucarie::afisare(out);
    out<<"Materialul este: "<<material<<endl;
    out<<"Culoarea este: "<<culoare<<endl;
}
ostream& operator<<(ostream& out, clasica& c)
{
    c.afisare(out);
    return out;
}
///*************************************EDUCATIVA***************************************************************************************///
class edu:public virtual jucarie{
protected:
    string abilitate;
    static int nr_edu;
public:

    edu(string, int, string, string);
    virtual ~edu();
    edu(const edu&);
    edu& operator=(edu&);

    virtual void citire(istream&);
    friend istream& operator>>(istream&, edu&);

    virtual void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, edu&);

    static void nr_com()
    {
        cout<<"Nr total de edu: "<<nr_edu;
    }
    static int get_nr_edu(){return nr_edu;}
};
int edu::nr_edu;
edu:: edu(string denumire=" ", int dimensiune=0, string tip=" ", string abilitate=" "):jucarie(denumire, dimensiune, tip)
{
    this->abilitate=abilitate;
}
edu::~edu()
{
        this->abilitate=" ";
}
edu::edu(const edu& a):jucarie(a)
{
    this->abilitate=a.abilitate;
}
edu& edu::operator=(edu& a)
{
    if(this!=&a)
    {
        jucarie::operator=(a);
        this->abilitate=a.abilitate;
    }
    return *this;
}
void edu::citire(istream& in)
{
    jucarie::citire(in);
    cout<<"Introduceti abilitatea: ";
    in>>abilitate;
}
istream& operator>>(istream& in, edu& a)
{
    a.citire(in);
    return in;
}
void edu::afisare(ostream& out)const
{
    jucarie::afisare(out);
    out<<"Abilitatea este: "<<abilitate<<endl;
}
ostream& operator<<(ostream& out, edu& a)
{
    a.afisare(out);
    return out;
}
///**********************************************electronice******************************************************************************///
class electronica:public virtual jucarie{
protected:
    int baterii;
public:

    electronica(string, int, string, int);
    virtual ~electronica();
    electronica(const electronica&);
    electronica& operator=(electronica&);

    void set_baterii(int baterii){this->baterii=baterii;}
    int get_baterii()const{return baterii;}

    virtual void citire(istream&);
    friend istream& operator>>(istream&, electronica&);

    virtual void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, electronica&);

};
electronica:: electronica(string denumire=" ", int dimensiune=0, string tip=" ", int baterii=0):jucarie(denumire, dimensiune, tip)
{
    this->baterii=baterii;
}
electronica::~electronica()
{
    this->baterii=0;
}
electronica::electronica(const electronica& e):jucarie(e)
{
    this->baterii=e.baterii;
}
electronica& electronica::operator=(electronica& e)
{
    if(this!=&e)
    {
        jucarie::operator=(e);
        this->baterii=e.baterii;
    }
    return *this;
}
void electronica::citire(istream& in)
{
    jucarie::citire(in);
    cout<<" Nr baterii: ";
    in>>baterii;
}
istream& operator>>(istream& in, electronica& e)
{
    e.citire(in);
    return in;
}
void electronica::afisare(ostream& out)const
{
    jucarie::afisare(out);
    out<<"Nr baterii este: "<<baterii<<endl;
}
ostream& operator<<(ostream& out, electronica& e)
{
    e.afisare(out);
    return out;
}
///**********************************************moderne******************************************************************************///
class modern:public edu, public electronica{
private:
    string brand;
    string model;
public:

    modern(string, int, string, int, string, string, string);
    ~modern();
    modern(const modern&);
    modern& operator=(modern&);

    void citire(istream&);
    friend istream& operator>>(istream&, modern&);

    void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, modern&);

};
modern:: modern(string denumire=" ", int dimensiune=0, string tip=" ", int baterii=0, string abilitate=" ", string brand=" ", string model=" "):electronica(denumire, dimensiune,tip,baterii), edu(denumire, dimensiune,tip, abilitate)
{
    this->brand=brand;
    this->model=model;
}
modern::~modern()
{
    this->brand=" ";
    this->model=" ";
}
modern::modern(const modern& m):edu(m), electronica(m)
{
    this->brand=m.brand;
    this->model=m.model;
}
modern& modern::operator=(modern& m)
{
    if(this!=&m)
    {
        edu::operator=(m);
        electronica::operator=(m);
        this->brand=m.brand;
        this->model=m.model;
    }
    return *this;
}
void modern::citire(istream& in)
{
    jucarie::citire(in);
    cout<<"Introduceti abilitatea: ";
    in>>abilitate;
     cout<<" Nr baterii: ";
    in>>baterii;
    cout<<"Brand este: ";
    in>>brand;
    cout<<"Model este: ";
    in>>model;

}
istream& operator>>(istream& in, modern& m)
{
    m.citire(in);
    return in;
}
void modern::afisare(ostream& out)const
{
    jucarie::afisare(out);

    out<<"Brand este: "<<brand<<endl;
    out<<"Modelul este: "<<model<<endl;
    out<<"Nr baterii este: "<<baterii<<endl;
    out<<"Abilitatea este: "<<abilitate<<endl;

}
ostream& operator<<(ostream& out, modern& m)
{
    m.afisare(out);
    return out;
}

///**********************************************copii******************************************************************************///
class copil{
protected:
    int id;
    string nume;
    string prenume;
    string adresa;
    int varsta;
    int bune;
    vector<jucarie*>jucarii;
public:

    copil(int, string, string, string, int, int, vector<jucarie*>);
    virtual ~copil();
    copil(const copil&);
    copil& operator=(copil&);

    void set_bune(int bune){this->bune=bune;}
    int get_bune()const{return bune;}

    int get_varsta()const{return varsta;}

    int get_id()const{return id;}

    string get_nume()const{return nume;}

    virtual void citire(istream&);
    friend istream& operator>>(istream&, copil&);

    virtual void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, copil&);
};
copil:: copil(int id=0, string nume=" ", string prenume=" ", string adresa=" ", int varsta=0, int bune=0, vector<jucarie*>jucarii=vector<jucarie*>() )
{
    this->id=id;
    this->nume=nume;
    this->prenume=prenume;
    this->adresa=adresa;
    this->varsta=varsta;
    this->bune=bune;
    for(unsigned int i=0;i<jucarii.size();i++)
        this->jucarii.push_back(jucarii[i]);
}
copil::~copil()
{
    this->id=0;
    this->nume=" ";
    this->prenume=" ";
    this->adresa=" ";
    this->varsta=0;
    this->bune=0;
    for(unsigned int i=0;i<jucarii.size();i++)
        jucarii.clear();
}
copil::copil(const copil& c)
{
    this->id=c.id;
    this->nume=c.nume;
    this->prenume=c.prenume;
    this->adresa=c.adresa;
    this->varsta=c.varsta;
    this->bune=c.bune;
    for(unsigned int i=0;i<jucarii.size();i++)
        this->jucarii.push_back(c.jucarii[i]);
}
copil& copil::operator=(copil& c)
{
    if(this!=&c)
    {
        this->id=c.id;
    this->nume=c.nume;
    this->prenume=c.prenume;
    this->adresa=c.adresa;
    this->varsta=c.varsta;
    this->bune=c.bune;
    for(unsigned int i=0;i<jucarii.size();i++)
        this->jucarii.push_back(c.jucarii[i]);
    }
    return *this;
}
void copil::citire(istream& in)
{
    int nr;
    string juc;
    cout<<"Introdueti id copil: ";
    in>>id;
    cout<<"Nume: ";
    in>>nume;
    cout<<"prenume: ";
    in>>prenume;
    cout<<"Varsat este: ";
    in>>varsta;
    cout<<"Adresa: ";
    in>>adresa;
    cout<<"Nr fapte bune: ";
    in>>bune;
    cout<<"****Introduceti jucariile!***"<<endl;
    if(bune>0)
    {
            for(int i=0;i<bune;i++)
        {
            cout<<"Alegeti tipul jucariei: ";
            in>>juc;
            if(juc=="clasica")
            {
                jucarie *d=new clasica;
                in>>*d;
                jucarii.push_back(d);
            }
            else if(juc=="educativa")
            {
                jucarie *d=new edu;
                in>>*d;
                jucarii.push_back(d);
            }
            else if(juc=="electronica")
            {
                jucarie *d=new electronica;
                in>>*d;
                jucarii.push_back(d);
            }
            else
            {
                cout<<"Nu ati introdus un tip de jucarie valid!"<<endl;
                i--;
            }

        }
    }
    else cout<<"Nu a facut fapte bune deci nu primeste jucarii";

}
istream& operator>>(istream& in, copil& c)
{
    c.citire(in);
    return in;
}
void copil::afisare(ostream& out)const
{
    out<<"Id este: "<<id<<endl;
    out<<"Nume: "<<nume<<endl;
    out<<"Prenume: "<<prenume<<endl;
    out<<"Adresa: "<<adresa<<endl;
    out<<"Bune: "<<bune<<endl;
    out<<"Varsta: "<<varsta<<endl;
    if(jucarii.size()>0)
    {
             for(unsigned int i=0;i<jucarii.size();i++)
        {
            out<<"\n--------------------------------------------\n";
            out<<*jucarii[i];
            out<<"\n--------------------------------------------\n";
        }
    }
    else cout<<"Nu a vrut jucarii"<<endl;


}
ostream& operator<<(ostream& out, copil& c)
{
    c.afisare(out);
    return out;
}
///**********************************************cuminti******************************************************************************///
class cuminte: public copil{
private:
   int nrdulc;
public:

    cuminte(int, string, string, string, int, int, vector<jucarie*>, int);
    ~cuminte();
    cuminte(const cuminte&);
    cuminte& operator=(cuminte&);

    void set_dulc(int nrdulc){this->nrdulc=nrdulc;}
    int get_dulc()const{return nrdulc;}

    void citire(istream&);
    friend istream& operator>>(istream&, cuminte&);

    void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, cuminte&);
};
cuminte:: cuminte(int id=0, string nume=" ", string prenume=" ", string adresa=" ", int varsta=0, int bune=0, vector<jucarie*>jucarii=vector<jucarie*>(), int nrdulc=0):copil(id, nume, prenume, adresa, varsta, bune, jucarii)
{
    this->nrdulc=nrdulc;
}
cuminte::~cuminte()
{
    this->nrdulc=0;
}
cuminte::cuminte(const cuminte& c):copil(c)
{
    this->nrdulc=c.nrdulc;
}
cuminte& cuminte::operator=(cuminte& c)
{
    if(this!=&c)
    {
        copil::operator=(c);
        this->nrdulc=c.nrdulc;
    }
    return *this;
}
void cuminte::citire(istream& in)
{
    int nr;
    string juc;
    cout<<"Introdueti id copil: ";
    in>>id;
    cout<<"Nume: ";
    in>>nume;
    cout<<"prenume: ";
    in>>prenume;
    cout<<"Varsat este: ";
    in>>varsta;
    cout<<"Adresa: ";
    in>>adresa;
    cout<<"Nr fapte bune: ";
    while (true)
    {
        try {
                in>>bune;
                if (bune<10) {
                    throw "\nCopiii cuminti nu pot avea mai putin de 10 fapte bune, citeste numarul din nou.\n";
                }
                break;
            } catch (const char* c)
             {
                cout <<c;
             }
    }
    cout<<"****Introduceti jucariile!***"<<endl;
            for(int i=0;i<bune;i++)
        {
            cout<<"Alegeti tipul jucariei: ";
            in>>juc;
            if(juc=="clasica")
            {
                jucarie *d=new clasica;
                in>>*d;
                jucarii.push_back(d);
            }
            else if(juc=="educativa")
            {
                jucarie *d=new edu;
                in>>*d;
                jucarii.push_back(d);
            }
            else if(juc=="electronica")
            {
                jucarie *d=new electronica;
                in>>*d;
                jucarii.push_back(d);
            }
            else
            {
                cout<<"Nu ati introdus un tip de jucarie valid!"<<endl;
                i--;
            }

        }
    cout<<"Nr dulciuri: ";
    in>>nrdulc;
}
istream& operator>>(istream& in, cuminte& c)
{
    c.citire(in);
    return in;
}
void cuminte::afisare(ostream& out)const
{
    copil::afisare(out);
    out<<"Nr dulciuri: "<<nrdulc<<endl;
}
ostream& operator<<(ostream& out, cuminte& c)
{
    c.afisare(out);
    return out;
}
///***********************************************rau**************************************************************************************************///
class rau: public copil{
private:
   int nrcarb;
public:

    rau(int, string, string, string, int, int, vector<jucarie*>, int);
    ~rau();
    rau(const rau&);
    rau& operator=(rau&);

    void set_carb(int nrcarb){this->nrcarb=nrcarb;}
    int get_carb()const{return nrcarb;}

    void citire(istream&);
    friend istream& operator>>(istream&, rau&);

    void afisare(ostream&)const;
    friend ostream& operator<<(ostream&, rau&);
};
rau:: rau(int id=0, string nume=" ", string prenume=" ", string adresa=" ", int varsta=0, int bune=0, vector<jucarie*>jucarii=vector<jucarie*>(), int nrcarb=0):copil(id, nume, prenume, adresa, varsta, bune, jucarii)
{
    this->nrcarb=nrcarb;
}
rau::~rau()
{
    this->nrcarb=0;
}
rau::rau(const rau& r):copil(r)
{
    this->nrcarb=r.nrcarb;
}
rau& rau::operator=(rau& r)
{
    if(this!=&r)
    {
        copil::operator=(r);
        this->nrcarb=r.nrcarb;
    }
    return *this;
}
void rau::citire(istream& in)
{
    copil::citire(in);
    cout<<"Nr dulciuri: ";
    in>>nrcarb;
}
istream& operator>>(istream& in, rau& r)
{
    r.citire(in);
    return in;
}
void rau::afisare(ostream& out)const
{
    copil::afisare(out);
    out<<"Nr dulciuri: "<<nrcarb<<endl;
}
ostream& operator<<(ostream& out, rau& r)
{
    r.afisare(out);
    return out;
}
///**********************************************MENIU-SINGLETON***********************************************************************///
class SingleTon {
private:
	static SingleTon* instanta_unica;
	SingleTon(){}
	void output_meniu();
public:
	static SingleTon* instance()
	 {
		if (instanta_unica == NULL)
			instanta_unica = new SingleTon();
		return instanta_unica;
	}
	void meniu();
};
SingleTon* SingleTon::instanta_unica = 0;
void SingleTon::output_meniu() {
	cout<<"\n\t MENIU:";
    cout<<"\n===========================================\n";
    cout<<"\n";
    cout<<"1.  Citeste n copii"; cout<<"\n";
    cout<<"2.  Afiseaza n copii"; cout<<"\n";
    cout<<"3.  Citeste m jucarii"; cout<<"\n";
    cout<<"4.  Afiseaza m jucarii"; cout<<"\n";
    cout<<"5.  Cauta copil dupa nume"; cout<<"\n";
    cout<<"6.  Ordoneaza copiii dupa varsta"; cout<<"\n";
    cout<<"7.  Ordoneaza copiii dupa numarul de fapte bune"; cout<<"\n";
    cout<<"8.  Modificati numarul de fapte bune ale unui copil: "; cout<<"\n";
    cout<<"9.  Afisati raportul jucariilor: "; cout<<"\n";
    cout<<"10. Stoc jucarii: "; cout<<"\n";
    cout<<"0.  Iesire."; cout<<"\n";
}
void SingleTon::meniu() {
	 int option=0,nr;
	 string juc;
	 vector<copil*> copii;
    vector<jucarie*> jucarii;
	do {
		SingleTon::output_meniu();
		 cout<<"Introduceti optiunea dorita: ";
            cin>>option;
        switch(option)
        {
        case 1:
        {
                string tip;
                cout<<"Tip copil(cuminte, neastamparat): ";
                cin>>tip;
                    if (tip == "cuminte")
                    {
                        copil *p = new cuminte;
                        cin >> *p;
                        copii.push_back(p);
                    }
                    else if (tip == "neastamparat")
                     {
                        copil *p = new rau;
                        cin >> *p;
                        copii.push_back(p);
                    }
            break;
        }
        case 2:
            {
                 cout<<"Acestia sunt copii!"<<endl;
                    for(unsigned int i=0; i<copii.size(); i++)
                cout<<*copii[i]<<endl;
                break;
            }
        case 3:
            {
                cout<<"Introduceti nr de jucarii: ";
            cin>>nr;
        if(nr>0)
        {
                for(int i=0;i<nr;i++)
            {
                cout<<"Alegeti tipul jucariei(clasica/educativa/electronica/moderna): ";
                cin>>juc;
                if(juc=="clasica")
                {
                    jucarie *d=new clasica;
                    cin>>*d;
                    jucarii.push_back(d);
                }
                else if(juc=="educativa")
                {
                    jucarie *d=new edu;
                    cin>>*d;
                    jucarii.push_back(d);
                }
                else if(juc=="electronica")
                {
                    jucarie *d=new electronica;
                    cin>>*d;
                    jucarii.push_back(d);
                }
                else if(juc=="moderna")
                {
                    jucarie *d=new modern;
                    cin>>*d;
                    jucarii.push_back(d);
                }
                else
                {
                    cout<<"Nu ati introdus un tip de jucarie valid!"<<endl;
                    i--;
                }
        }
    }
                break;
            }
        case 4:
            {
                 cout<<"Acestea sunt jucariile!"<<endl;
            for(unsigned int i=0; i<jucarii.size(); i++)
                cout<<*jucarii[i]<<endl;
                break;
            }
        case 5:
            {
            string num;
            cout<<"Introduceti numele copilului cautat: ";
            cin>>num;
            for( int i=0; i<copii.size(); i++)
            {
                if(copii[i]->get_nume()==num)
                {
                    cout<<"Copilul cautat: "<<endl;
                    cout<<*copii[i];
                }
            }
                break;
            }
        case 6:
            {
                cout<<"Copii inainte de sortarea dupa varsta!"<<endl;
                for(int i=0; i<copii.size(); i++)
                    cout<<*copii[i];

                for(int i=0; i<copii.size()-1; i++)
                {
                    for(int j=i+1; j<copii.size(); j++)
                        if(copii[i]->get_varsta()>copii[j]->get_varsta())
                            swap(copii[i], copii[j]);
                }
                cout<<"copii dupa ordonarea dupa varsta!"<<endl;
                for(int i=0; i<copii.size(); i++)
                    cout<<*copii[i];
                break;
            }
        case 7:
            {
                cout<<"Copii inainte de sortarea dupa fapte bune!"<<endl;
                for(int i=0; i<copii.size(); i++)
                    cout<<*copii[i];

                for(int i=0; i<copii.size()-1; i++)
                {
                    for(int j=i+1; j<copii.size(); j++)
                        if(copii[i]->get_bune()>copii[j]->get_bune())
                            swap(copii[i], copii[j]);
                }
                cout<<"copii dupa ordonarea dupa fapte bune!"<<endl;
                for(int i=0; i<copii.size(); i++)
                    cout<<*copii[i];
                break;
            }
        case 8:
            {
                int nrb, ID, fapte_bune_actuale;
                cout<<"Valoarea X cu care vreau sa cresc numarul de fapte bune: ";
                cin>>nrb;
                cout<<"ID-ul copilului: ";
                cin>>ID;
                for(unsigned int i=0; i<copii.size(); i++)
                {
                    if(copii[i]->get_id()==ID)
                    {
                        fapte_bune_actuale=copii[i]->get_bune();
                        copii[i]->set_bune(fapte_bune_actuale+nrb);
                    }
                }
                break;
            }
        case 9:
            {
                break;
            }
        case 10:
            {
                int nr_c=0, nr_e=0, nr_ed=0, nr_m=0;
                for(int i=0; i<jucarii.size(); i++)
                {
                    clasica *c=dynamic_cast<clasica*>(jucarii[i]);
                    edu *ed=dynamic_cast<edu*>(jucarii[i]);
                    electronica *e=dynamic_cast<electronica*>(jucarii[i]);
                    modern* m=dynamic_cast<modern*>(jucarii[i]);

                    if(c)
                        nr_c++;
                    if(ed)
                        nr_ed++;
                    if(e)
                        nr_e++;
                    if(m)
                        nr_m++;
                }
                cout<<"Nr jucarii clasice: "<<nr_c<<endl;
                cout<<"Nr jucarii educative: "<<nr_ed<<endl;
                cout<<"Nr jucarii electronice: "<<nr_e<<endl;
                cout<<"Nr jucarii moderne: "<<nr_m<<endl;
                break;
            }
        default:
            cout<<"\nSelectie invalida\n";

        }
         cout<<"\n";
		system("pause");
		system("cls");
	} while (option != 0);
}
int main()
{
    SingleTon* meniu = meniu->instance();
	meniu->meniu();
    return 0;
}

