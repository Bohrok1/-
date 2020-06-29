#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <cstdlib> 
#include <fstream> 
#include <algorithm>
using namespace std;
class TortA
{

public:
	string nazvanie;
	string proizvoditel;
	int nomer;
	TortA() : nazvanie(""), proizvoditel("")
	{}
	virtual ~TortA()
	{
		nazvanie = ("");
		proizvoditel = ("");
	}

	virtual void sd()
	{
		cout << "\n VVedite nazvanie torta -> ";
		cin >> nazvanie;
		cout << "\n VVtite proizvoditela torta -> ";
		cin >> proizvoditel;
	}


	virtual void gd()const = 0;

};
class TortB : public TortA
{
public:
	float dengi;
	int God;
	int Mesic;
	int Den;
	TortB() :TortA(), dengi(0.0), God(0), Mesic(0), Den(0)
	{}
	~TortB()
	{
		God = 0; Mesic = 0; Den = 0;
		dengi = 0.0;
	}
	void sd() override
	{
		TortA::sd();
		cout << "\n Vvedite ceny torta -> ";
		cin >> dengi;
		char symb = '\x0';
		cout << "\n Vvedite daty postyplenia v vvide den'-mesic-god -> ";
		cin >> Den >> symb >> Mesic >> symb >> God;
	}
	void gd()const
	{
		cout << "\n nomer " << nomer << " Torta -> ";
		cout << "\n Nazvanie torta -> " << nazvanie;
		cout << "\n Proizvoditel Torta -> " << proizvoditel;
		cout << "\n Cena = " << dengi;
		cout << "\n Data postuplenia = " << God << "|" << Mesic << "|" << Den;
	}

};
class TortS : public TortB
{
public:
	float Brytto;
	float Netto;
	TortS() :TortB(), Brytto(0.0), Netto(0.0)

	{}
	~TortS()
	{
		Brytto = 0.0;
		Netto = 0.0;
	}
	void sd() override
	{
		TortB::sd();
		cout << "\n Vvedite Macca Brytto -> ";
		cin >> Brytto;
		cout << "\n Vvedite Macca Netto -> ";
		cin >> Netto;
	}
	void getData()const
	{
		TortB::gd();
		cout << "\n Brytto = " << Brytto;
		cout << "\n Netto = " << Netto;
	}

};
class Klient : public TortS
{

public:
	string ima;
	string famima;
	int Go;
	int Mec;
	int De;
	Klient() :TortS(), ima("n/b"), famima("n/b"), Go(0), Mec(0), De(0)
	{}
	~Klient()
	{
		ima = "n/b";
		famima = "n/b";
	}
	void data()
	{
		TortS::sd();
	}
	void dataset()
	{
		TortS::getData();
	}
	void sd() override
	{
		nomer = 0;
		cout << "\n VVedite ima Klienta -> " << endl;
		cin >> ima;
		cout << "\n VVedite familia Klienta -> " << endl;
		cin >> famima;
		cout << "\n Vvedite daty pokypki Klientom dd mm yyyy  -> " << endl;
		cin >> De >> Mec >> Go;
	}
	void gd()const
	{
		
		cout << "\n Nazvanie torta -> " << nazvanie;
		cout << "\n Proizvoditel torta -> " << proizvoditel;
		cout << "\n Cena = " << dengi;
		cout << "\n Ima Klienta -> " << ima;
		cout << "\n familia Klienta = " << famima;
		cout << "\n Data pokupki-> " << De << "." << Mec << "." << Go;
		cout << "\n Brytto = " << Brytto;
		cout << "\n Netto = " << Netto;
	}
};

int main()
{

	
	int Tortz = 0;
	int n;
	int a = 0;
	bool cop = false;

	Klient ** Pok;
	Klient ** kopirovdannih;
	Klient** prodtorta;

	int zxc = 0;
	int asd = 0;
	Pok = new Klient*[zxc + 1];
	prodtorta = new Klient*[asd + 1];
	kopirovdannih = new Klient*[zxc + 1];

	ifstream qwe; 
	{

		Pok[0] = new Klient;
		zxc = 0;
		while (!qwe.eof())
		{
			if (zxc < 1) {
				qwe >> Pok[0]->nomer;
				qwe >> Pok[0]->nazvanie;
				qwe >> Pok[0]->proizvoditel;
				qwe >> Pok[0]->dengi;
				qwe >> Pok[0]->Den;
				qwe >> Pok[0]->Mesic;
				qwe >> Pok[0]->God;
				qwe >> Pok[0]->Brytto;
				qwe >> Pok[0]->Netto;
			}
			else
			{
				kopirovdannih = new Klient*[zxc];
				for (int j = 0; j < zxc; j++) {
					kopirovdannih[j] = Pok[j];
				}
				Pok = new Klient*[zxc + 1];
				for (int j = 0; j < zxc; j++) {
					Pok[j] = kopirovdannih[j];
				}
				Pok[zxc] = new Klient;
				qwe >> Pok[zxc]->nomer;
				qwe >> Pok[zxc]->nazvanie;
				qwe >> Pok[zxc]->proizvoditel;
				qwe >> Pok[zxc]->dengi;
				qwe >> Pok[zxc]->Den;
				qwe >> Pok[zxc]->Mesic;
				qwe >> Pok[zxc]->God;
				qwe >> Pok[zxc]->Brytto;
				qwe >> Pok[zxc]->Netto;
				zxc += 1;
			}
		}
	}
	

	ifstream prodaga;
	{
		int i = 0;
		prodtorta[0] = new Klient;
		asd = 0;
		while (!prodaga.eof())
		{
			if (asd < 1) {
				prodaga >> prodtorta[i]->nazvanie;
				prodaga >> prodtorta[i]->proizvoditel;
				prodaga >> prodtorta[i]->dengi;
				prodaga >> prodtorta[i]->De;
				prodaga >> prodtorta[i]->Mec;
				prodaga >> prodtorta[i]->Go;
				prodaga >> prodtorta[i]->ima;
				prodaga >> prodtorta[i]->famima;
				prodaga >> prodtorta[i]->Brytto;
				prodaga >> prodtorta[i]->Netto;
				i++;
				asd += 1;
			}
			else
			{
				kopirovdannih = new Klient*[asd];
				for (int j = 0; j < asd; j++) {
					kopirovdannih[j] = prodtorta[j];
				}
				prodtorta = new Klient*[asd + 1];
				for (int j = 0; j < asd; j++) {
					prodtorta[j] = kopirovdannih[j];
				}
				prodtorta[asd] = new Klient;
				prodaga >> prodtorta[asd]->nazvanie;
				prodaga >> prodtorta[asd]->proizvoditel;
				prodaga >> prodtorta[asd]->dengi;
				prodaga >> prodtorta[asd]->De;
				prodaga >> prodtorta[asd]->Mec;
				prodaga >> prodtorta[asd]->Go;
				prodaga >> prodtorta[asd]->ima;
				prodaga >> prodtorta[asd]->famima;
				prodaga >> prodtorta[asd]->Brytto;
				prodaga >> prodtorta[asd]->Netto;
				asd += 1;
			}

		}
	}
	prodaga.close();




	while (a == 0) {
		cout << "         ////////////////////////             " << endl;
		cout << "         Baza dannih: Baza tortov             " << endl;
		cout << "         ////////////////////////             " << endl;
		cout << "1     Dobavit tort v bazy          " << endl;
		cout << "2     Prodat' tort           " << endl;
		cout << "3     Posmotret vse torti v baze dannih     " << endl;
		cout << "                                            " << endl;
		cout << "                  ,:/+/-                          " << endl;
		cout << "                  /M/              .,-=;//;-                           " << endl;
		cout << "             .:/= ;MH/,    ,=/+%$XH@MM#@:                              " << endl;
		cout << "            -$##@+$###@H@MMM######H:.      -/H#                        " << endl;
		cout << "        .,H@H@ X######@ -H#####@+-     -+H###@X                        " << endl;
		cout << "         .,@##H;      +XM##M/,     =%@###@X;-                          " << endl;
		cout << "       X%-  :M##########$.    .:%M###@%:                               " << endl;
		cout << "       M##H,   +H@@@$/-.  ,;$M###@%,          -                        " << endl;
		cout << "       M###M=, ,---,.-%%H####M$:          ,+@##                        " << endl;
		cout << "       @##################@/.         :%H##@$-                         " << endl;
		cout << "       M###############H,         ;HM##M$=                             " << endl;
		cout << "       #################.    .=$M##M$=                                 " << endl;
		cout << "       ################H..;XM##M$=          .:+                        " << endl;
		cout << "       M###################@%=           =+@MH%                        " << endl;
		cout << "       @################M/.          =+H#X%=                           " << endl;
		cout << "       =+M##############M,       -/X#Z+;.                              " << endl;
		cout << "         .;XM##########H=    ,/X#H+:,                                  " << endl;
		cout << "            .=+HM######M+/+HM@+=.                                      " << endl;
		cout << "                ,:/%XM####H/.                                          " << endl;
		cout << "                     ,.:=-.                                            " << endl;
		cin >> n;
		switch (n) {
		case 1:
			if (zxc <= 0)
			{
				
				Pok[0] = new Klient;
				Pok[0]->data();

				Pok[0]->nomer = 1;
				zxc += 1;
				cout << "\n \n Dobavil tort v bazy" << endl;
				
			}
			else
			{
				kopirovdannih = new Klient*[zxc + 1];
				cop = true;
				for (int i = 0; i < zxc; i++) {
					kopirovdannih[i] = Pok[i];
				}
				Pok = new Klient*[zxc + 1];
				for (int i = 0; i < zxc; i++) {
					Pok[i] = kopirovdannih[i];
				}
				
				Pok[zxc] = new Klient;
				Pok[zxc]->data();
				Pok[zxc]->nomer = zxc + 1;
				cout << "\n \n Dobavil tort v bazy" << endl;
				zxc += 1;
				
			}
			break;
		case 2:
			if (zxc < 1) { cout << "Baza pysta" << endl; }
			else
			{
				int id;
				cout << "Vvedite nomer torta kotorii bydete prodat'" << endl;
				cin >> id;
				kopirovdannih = new Klient*[asd];
				cop = true;
				for (int i = 0; i < asd; i++)
				{
					kopirovdannih[i] = prodtorta[i];
				}
				prodtorta = new Klient*[asd + 1];
				for (int i = 0; i < asd; i++)
				{
					prodtorta[i] = kopirovdannih[i];
				}
				prodtorta[asd] = new Klient;
				prodtorta[asd] = Pok[id - 1];
				prodtorta[asd]->sd();
			
				cout << "    Tort prodan  " << endl;
				asd += 1;
				kopirovdannih = new Klient*[zxc - 1];
				cop = true;
				for (int i = 0; i < zxc - 1; i++)
				{
					if (i < id - 1) { kopirovdannih[i] = Pok[i]; }
					else { kopirovdannih[i] = Pok[i + 1]; kopirovdannih[i]->nomer -= 1; }
				}
				zxc -= 1;
				Pok = new Klient*[zxc];
				for (int i = 0; i < zxc; i++) {
					Pok[i] = kopirovdannih[i];
				}

			}
			break;
		case 3:
			if (zxc < 1) { cout << "Baza pysta" << endl; }
			else
			{
				for (int i = 0; i < zxc; i++) {
				
					Pok[i]->dataset();
					
				}

			}
			break;
		}
	}
	int i = 0;
	if (asd != 0)
	{
		ofstream sellist;
		sellist << prodtorta[i]->nazvanie << " "
			<< prodtorta[i]->proizvoditel << " "
			<< prodtorta[i]->dengi << " "
			<< prodtorta[i]->De << " "
			<< prodtorta[i]->Mec << " "
			<< prodtorta[i]->Go << " "
			<< prodtorta[i]->ima << " "
			<< prodtorta[i]->famima << " "
			<< prodtorta[i]->Brytto << " "
			<< prodtorta[i]->Netto;
		for (i = 1; i < asd; i++)
		{
			sellist << "\n"
				<< prodtorta[i]->nazvanie << " "
				<< prodtorta[i]->proizvoditel << " "
				<< prodtorta[i]->dengi << " "
				<< prodtorta[i]->De << " "
				<< prodtorta[i]->Mec << " "
				<< prodtorta[i]->Go << " "
				<< prodtorta[i]->ima << " "
				<< prodtorta[i]->famima << " "
				<< prodtorta[i]->Brytto << " "
				<< prodtorta[i]->Netto;
		}
		sellist.close();
		delete[] * prodtorta;
	}
	else { delete[] prodtorta; }
	if (zxc != 0) {
		ofstream out;
		out.clear();
		i = 0;
		out << Pok[i]->nomer << " "
			<< Pok[i]->nazvanie << " "
			<< Pok[i]->proizvoditel << " "
			<< Pok[i]->dengi << " "
			<< Pok[i]->Den << " "
			<< Pok[i]->Mesic << " "
			<< Pok[i]->God << " "
			<< Pok[i]->Brytto << " "
			<< Pok[i]->Netto;
		for (i = 1; i < zxc; i++) {


			out << "\n"
				<< Pok[i]->nomer << " "
				<< Pok[i]->nazvanie << " "
				<< Pok[i]->proizvoditel << " "
				<< Pok[i]->dengi << " "
				<< Pok[i]->Den << " "
				<< Pok[i]->Mesic << " "
				<< Pok[i]->God << " "
				<< Pok[i]->Brytto << " "
				<< Pok[i]->Netto;
		}
		out.close();
		delete[] * Pok;
	}
	else { delete[] Pok; }
	delete[] kopirovdannih;
	return 0;



}