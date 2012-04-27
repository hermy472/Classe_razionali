#include <math.h>
#include <iostream>
/*modifica*/
using namespace std;

struct razionale
	{
	int numeratore, denominatore;	
	bool attenzione;  
	  friend istream&operator >> (istream&is, razionale&c);
	  friend ostream&operator << (ostream&os, razionale k);	
	  friend double sin (razionale a);
	  friend double asin (razionale a);
	  friend double cos (razionale a);
	  friend double acos (razionale a);
	  friend double tan (razionale a);
	  friend double atan (razionale a);
	  friend double senh (razionale a);
	  friend double asinh (razionale a);
	  friend double cosh (razionale a);
	  friend double acosh (razionale a);
	  friend double tanh (razionale a);
	  friend double atanh (razionale a);
	  friend double sqrt (razionale a);
	  friend double log (razionale a);
	  friend double log10 (razionale a);
	  friend razionale conversione (double a);
	  friend razionale riduzione (razionale a);
	  friend razionale operator + (double k, razionale a);
	  friend razionale operator * (double k, razionale a);
	  friend razionale operator - (double k, razionale a);
	  friend razionale operator / (double k, razionale a);
       	  friend razionale operator + (int k, razionale a);
	  friend razionale operator * (int k, razionale a);
	  friend razionale operator - (int k, razionale a);
	  friend razionale operator / (int k, razionale a);
	  friend razionale pow (int a, razionale b);
	  friend razionale pow (razionale a, razionale b);
	  friend razionale pow (double a, razionale b);
	  friend bool operator < (double k,razionale a);
	  friend bool operator < (int k,razionale a);
	  friend bool operator > (int k, razionale a);
	  friend bool operator > (double k, razionale a);
	  friend bool operator == (double d, razionale r);
	  friend bool operator == (int d, razionale r);
	  friend bool operator <= (double a, razionale j);
	  friend bool operator <= (int a, razionale j);
	  friend bool operator >= (double a, razionale j);
	  friend bool operator >= (int a, razionale j);
	  friend bool operator != (double a, razionale j);
	  friend bool operator != (int a, razionale j);
	  
	 razionale (int a, int b)
	  {numeratore = a; denominatore = b; attenzione = (b==0);}
	 razionale () {}

/*operazioni con un razionale*/

razionale operator + (razionale s)
{razionale somma; 
  if (denominatore == 0 || s.denominatore == 0) {somma.attenzione = true; somma.numeratore = 1; somma.denominatore = 0;}  
  else {somma.denominatore = s.denominatore*denominatore;
    somma.numeratore=(somma.denominatore/s.denominatore)*s.numeratore+(somma.denominatore/denominatore)*numeratore; 
    somma.attenzione = false; } 
return somma;
		}

razionale operator - (razionale d) 
{razionale differenza;
  if (denominatore == 0 || d.denominatore == 0) {differenza.attenzione = true; differenza.numeratore = 1; 
differenza.denominatore = 0;}	
  else {differenza.denominatore = d.denominatore*denominatore;
    differenza.numeratore=-(differenza.denominatore/d.denominatore)*d.numeratore+(differenza.denominatore/denominatore)*numeratore;
    differenza.attenzione = false;}
  return differenza;
		}
		
razionale operator * (razionale p)
		{
		razionale prodotto;
		prodotto.numeratore = p.numeratore*numeratore;
		prodotto.denominatore = p.denominatore*denominatore;
		if (denominatore == 0 || p.denominatore == 0) prodotto.attenzione = true;
		return prodotto;
		}	 
		
razionale operator / (razionale f)
	{
	razionale divisione;
	divisione.numeratore=numeratore*f.denominatore;
	divisione.denominatore=denominatore*f.numeratore;
	if (denominatore == 0 || f.denominatore == 0 || f.numeratore == 0) divisione.attenzione = true;
	return divisione;
	}

/*booleani < > fra razionali*/

bool operator < (razionale d)
	  {
	    double c, e;
	    if (attenzione == true || d.attenzione == true || denominatore == 0 || d.denominatore == 0) 
	      {cout<<"Uno degli operandi e' inutilizzabile"<<endl; return false;} 
	    else {c=double(numeratore)/double (denominatore);
 e=double (d.numeratore)/(d.denominatore);
 return (c<e)?true:false;}}

bool operator > (razionale d)
       {
double c,e;
if (attenzione == true || d.attenzione == true || denominatore == 0 || d.denominatore == 0) 
	      {cout<<"Uno degli operandi e' inutilizzabile"<<endl; return false;} 
 else {c=double(numeratore)/double(denominatore);
e=double(d.numeratore)/double(d.denominatore);
 return (c>e)?true:false;}}

	  razionale operator + (double);
	  razionale operator * (double);
	  razionale operator / (double); 
	  razionale operator - (double);
	  razionale operator + (int);
	  razionale operator * (int);
	  razionale operator / (int);
	  razionale operator - (int);
	  bool operator == (razionale);
	  bool operator <= (razionale);
	  bool operator >= (razionale);
	  bool operator != (razionale);
	  bool operator == (int);
	  bool operator == (double);
	  bool operator <= (double);
	  bool operator <= (int);
	  bool operator >= (double);
	  bool operator >= (int);
	  bool operator != (double);
	  bool operator != (int);
	  razionale operator += (double);
	  razionale operator -= (double);
	  razionale operator *= (double);
	  razionale operator /= (double);
	  razionale operator += (int);
	  razionale operator -= (int);
	  razionale operator *= (int);
	  razionale operator /= (int);

	  
/*operatori > < con non razionali */
bool operator < (double e)
	  { 
if (denominatore == 0 || attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
 else { double c;
 c=double(numeratore)/double (denominatore);
 return (c<e)?true:false;}}

bool operator < (int e)
	 {
if (denominatore == 0 || attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
 else { double c;
 c=double(numeratore)/double (denominatore);
 return (c<e)?true:false;}}

bool operator > (double e)
       {
if (denominatore == 0 || attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
else {double c;
c=double(numeratore)/double(denominatore);
 return (c>e)?true:false;}}

bool operator > (int e) 
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
else {double c;
c=double(numeratore)/double(denominatore);
 return (c>e)?true:false;}
}

razionale operator += (razionale a)
	  {razionale somma; razionale b; b.numeratore = numeratore; b.denominatore = denominatore;
	    somma = a + b;
	    numeratore = somma.numeratore;
	    denominatore = somma.denominatore;
	    if (somma.attenzione) attenzione = true;
	    return *this;}

razionale operator -= (razionale a)
	  {razionale differenza, b; b.numeratore = numeratore; b.denominatore = denominatore;
	    differenza = b - a;
	    numeratore = differenza.numeratore;
	    denominatore = differenza.denominatore;
	    if (differenza.attenzione) attenzione = true;
	    return *this;}

razionale operator *= (razionale a)
	  {razionale prodotto, b; b.numeratore = numeratore; b.denominatore = denominatore;
	    prodotto = a*b;
	    numeratore=prodotto.numeratore;
	    denominatore = prodotto.denominatore;
	    if (prodotto.attenzione) attenzione = true;
	    return *this;}

razionale operator /= (razionale a)
	  {razionale rapporto, b; b.numeratore = numeratore; b.denominatore = denominatore;
	    rapporto=b/a;
	    numeratore = rapporto.numeratore;
	    denominatore = rapporto.denominatore;
	    if (rapporto.attenzione) attenzione = true;
	    return *this;}

};
/*FINE DELLA CLASSE!!!!*/

/* operatori booleani razionali e non razionali*/


	
bool operator > (double k, razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {double c;
c=double(a.numeratore)/double(a.denominatore);
 return (k>c)?true:false;}}

bool operator > (int k, razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
	   else {double c;
c=double(a.numeratore)/double(a.denominatore);
 return (k>c)?true:false;}}


bool operator < (int k,razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {double u; u=(double)a.numeratore/(double)a.denominatore;
    return (k<u)?true:false;}
}

bool operator < (double k,razionale a)
{
  if (a.denominatore == 0 || a.attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {double u; u=(double)a.numeratore/(double)a.denominatore;
    return (k<u)?true:false;}
}


/*funzione conversione*/
razionale conversione (double a)
{
  double num = a*pow (10, 4);
  razionale b; b.numeratore = rint(num); b.denominatore = pow(10, 4); b.attenzione = false; return b;}


/*operazioni razionali e non razionali*/

razionale razionale::operator + (double k)
	 {razionale somma; razionale conv;
	    conv = conversione (k);
if (denominatore == 0) {somma.attenzione = true; somma.numeratore = 1; somma.denominatore = 0;}
 else {somma.denominatore = conv.denominatore*denominatore;
   somma.numeratore=(somma.denominatore/conv.denominatore)*conv.numeratore+(somma.denominatore/denominatore)*numeratore; 
   somma.attenzione = false;}
	    return somma;}

razionale razionale::operator + (int k)
{razionale somma; razionale conv; double trucco;
  trucco = (double) k;
	    conv = conversione (trucco);
	    if (denominatore == 0) {somma.attenzione = true; somma.numeratore = 1; somma.denominatore = 0;}
	    else {somma.denominatore = conv.denominatore*denominatore;
	      somma.numeratore=(somma.denominatore/conv.denominatore)*conv.numeratore+(somma.denominatore/denominatore)*numeratore;
	      somma.attenzione = false;}
	    return somma;}


razionale razionale::operator * (double k)
{razionale prodotto, conv;
  conv=conversione(k);
  prodotto.numeratore=conv.numeratore*numeratore;
  prodotto.denominatore=conv.denominatore*denominatore;
  if (denominatore == 0) prodotto.attenzione = true;  
return prodotto;
}

razionale razionale::operator * (int k)
{razionale prodotto;
  prodotto.numeratore=k*numeratore;
  prodotto.denominatore=denominatore;
  if (denominatore == 0) prodotto.attenzione = true;
  return prodotto;
}

razionale razionale::operator / (double k)
	  {razionale divisione; razionale conv;
	    conv=conversione(k);
	    divisione.numeratore=numeratore*conv.denominatore;
	    divisione.denominatore=denominatore*conv.numeratore;
	    if (denominatore == 0 || conv.numeratore == 0 || conv.denominatore == 0) divisione.attenzione = true;	    return divisione;}

razionale razionale::operator / (int k)
	  {razionale divisione; razionale conv;
divisione.denominatore=denominatore*k;
	    divisione.numeratore=numeratore;
	    if (denominatore == 0 || k == 0) divisione.attenzione = true;
	    return divisione;}

razionale razionale::operator - (double k)
 {razionale differenza; razionale conv; double trucco;
  trucco = (double) k;
	    conv=conversione(trucco);
	    if (denominatore == 0) {differenza.attenzione = true; differenza.numeratore = 1; differenza.denominatore = 0;}
	    else {differenza.denominatore=conv.denominatore*denominatore;
	      differenza.numeratore=(differenza.denominatore/denominatore)*numeratore-(differenza.denominatore/conv.denominatore)*conv.numeratore;}
 return differenza;}

razionale razionale::operator - (int k)
 {razionale differenza; razionale conv;
   conv=conversione((double) k);
   if (denominatore == 0) {differenza.attenzione = true; differenza.numeratore = 1; differenza.denominatore = 0;}   
   else {differenza.denominatore=conv.denominatore*denominatore;
     differenza.numeratore=(differenza.denominatore/denominatore)*numeratore-(differenza.denominatore/conv.denominatore)*conv.numeratore;
     differenza.attenzione = false;}
return differenza;}

razionale operator + (double k, razionale a)
	 {razionale somma; razionale conv;
	    conv = conversione (k);
	    if (a.denominatore == 0) {somma.attenzione = true; somma.numeratore = 1; somma.denominatore = 0;}
	    else { somma.denominatore = conv.denominatore*a.denominatore;
	      somma.numeratore=(somma.denominatore/conv.denominatore)*conv.numeratore+(somma.denominatore/a.denominatore)*a.numeratore;
	      somma.attenzione = false;}
	   return somma;}

razionale operator + (int k, razionale a)
{razionale somma; razionale conv; double trucco;
  trucco = (double) k;
	    conv = conversione (trucco);
	    if (a.denominatore == 0) {somma.attenzione = true; somma.numeratore = 1; somma.denominatore = 0;}
	    else {somma.denominatore = conv.denominatore*a.denominatore;
	      somma.numeratore=(somma.denominatore/conv.denominatore)*conv.numeratore+(somma.denominatore/a.denominatore)*a.numeratore;
	      somma.attenzione = false;}
	    	   return somma;}

razionale operator - (double k, razionale a)
 {razionale differenza; razionale conv;
   conv=conversione(k);
   if (a.denominatore == 0) {differenza.attenzione = true; differenza.numeratore = 1; differenza.denominatore = 0;}
   else { differenza.denominatore=conv.denominatore*a.denominatore;
   differenza.numeratore=-(differenza.denominatore/a.denominatore)*a.numeratore+(differenza.denominatore/conv.denominatore)*conv.numeratore;
   differenza.attenzione = false;}
   return differenza;}

razionale operator - (int k, razionale a)
 {razionale differenza; razionale conv;double trucco;
  trucco = (double) k;
	    conv = conversione (trucco);
	    if (a.denominatore == 0) {differenza.attenzione = true; differenza.numeratore = 1; differenza.denominatore = 0; }
      else {differenza.denominatore=conv.denominatore*a.denominatore;
	differenza.numeratore=-(differenza.denominatore/a.denominatore)*a.numeratore+(differenza.denominatore/conv.denominatore)*conv.numeratore;
	differenza.attenzione = false;}
   return differenza;}


razionale operator * (double k, razionale a)
{razionale prodotto, conv;
  conv=conversione(k);
  prodotto.numeratore=conv.numeratore*a.numeratore;
  prodotto.denominatore=conv.denominatore*a.denominatore;
  if (a.denominatore == 0) prodotto.attenzione = true;
  return prodotto;
}

razionale operator * (int k, razionale a)
{razionale prodotto;
  prodotto.numeratore=k*a.numeratore;
  prodotto.denominatore=a.denominatore;
  if (a.denominatore == 0) prodotto.attenzione = true;  
return prodotto;
}

razionale operator / (double k, razionale a)
	  {razionale divisione; razionale conv;
	    conv=conversione(k);
	    divisione.denominatore=a.numeratore*conv.denominatore;
	    divisione.numeratore=a.denominatore*conv.numeratore;
	    if (a.denominatore == 0 || conv.numeratore == 0 || conv.denominatore == 0) divisione.attenzione = true;
	    return divisione;}

razionale operator /(int k, razionale a)
	  {razionale divisione;
	    divisione.numeratore=k*a.denominatore;
	    divisione.denominatore=a.numeratore;
	    if (a.denominatore == 0 || a.numeratore == 0) divisione.attenzione = true;
	    return divisione;}

razionale razionale::operator += (double b) 
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale somma; somma = a+b;
  numeratore = somma.numeratore;
  denominatore = somma.denominatore;
  if (somma.attenzione) attenzione = true;
  return *this;}

razionale razionale::operator -= (double b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale diff; diff = a - b;
  numeratore = diff.numeratore;
  denominatore = diff.denominatore;
  if (diff.attenzione) attenzione = true;
  return *this;}

razionale razionale::operator *= (double b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale prod; prod = a*b;
  numeratore = prod.numeratore;
  denominatore = prod.denominatore;
  if (prod.attenzione) attenzione = true;
  return *this;}

razionale razionale::operator /= (double b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale rapp; rapp = a/b;
  numeratore = rapp.numeratore;
  denominatore = rapp.denominatore;
  if (rapp.attenzione) attenzione = true;
  return *this; }


razionale razionale::operator += (int b) 
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale somma; somma = a+b;
  numeratore = somma.numeratore;
  denominatore = somma.denominatore;
  if (somma.attenzione) attenzione = true;
  return *this;}

razionale razionale::operator -= (int b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale diff; diff = a - b;
  numeratore = diff.numeratore;
  denominatore = diff.denominatore;
  if (diff.attenzione) attenzione = true;
  return *this;}

razionale razionale::operator *= (int b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale prod; prod = a*b;
  numeratore = prod.numeratore;
  denominatore = prod.denominatore;
  if (prod.attenzione) attenzione = true;  
return *this;}

razionale razionale::operator /= (int b)
{razionale a; a.numeratore = numeratore; a.denominatore = denominatore;
  razionale rapp; rapp = a/b;
  numeratore = rapp.numeratore;
  denominatore = rapp.denominatore;
  if (rapp.attenzione) attenzione = true;
  return *this; }

double operator += (double &a, razionale b)
{double valore = double (b.numeratore) / double (b.denominatore);
  double somma = a + valore;
  a = somma;
  return a;
}

double operator -= (double &a, razionale b)
{double valore = double (b.numeratore) / double (b.denominatore);
  double diff = a - valore;
  a = diff;
  return a;
}

double operator *= (double &a, razionale b)
{double valore = double (b.numeratore) / double (b.denominatore);
  double prod = a*valore;
  a = prod;
  return a;
}

double operator /= (double &a, razionale b)
{double valore = double (b.numeratore) / double (b.denominatore);
  double rapp = a/valore;
  a = rapp;
  return a;}


/*funzioni trigonometriche*/ 

double sin (razionale a)
{
  if (a.denominatore == 0 || a.attenzione == true) {return NAN; } 
  else {double b; b=sin((double)a.numeratore/(double)a.denominatore); 
return b;}
}

double cos (razionale a)
{
if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
 else { double b;
   b=cos((double)a.numeratore/(double)a.denominatore); return b;}
}

double asin (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double b;
    b=asin((double)a.numeratore/(double)a.denominatore); return b;}
}

double acos (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {  double b;
    b = acos((double)a.numeratore/(double)a.denominatore); return b;}
}

double tan (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double b;
    b=tan((double)a.numeratore/(double)a.denominatore); return b;}
}

double atan (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double b; 
    b=atan((double)a.numeratore/(double)a.denominatore); return b;}
}

double sinh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double b;
    b=sinh((double)a.numeratore/(double)a.denominatore); return b;}
}

double asinh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double b;
    b=asinh((double)a.numeratore/(double)a.denominatore); return b;}
}

double cosh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double b;
    b=cosh((double)a.numeratore/(double)a.denominatore); return b;}
}

double acosh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double b;
    b=acosh((double)a.numeratore/(double)a.denominatore); return b;}
}

double tanh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double b;
    b=tanh((double)a.numeratore/(double)a.denominatore); return b;}
}

double atanh (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double b;
  b=atanh((double)a.numeratore/(double)a.denominatore);
  return b;}
}

/*funzioni varie*/

double sqrt (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double k, l, o;
  k=sqrt(a.numeratore);
  l=sqrt(a.denominatore);
  o=k/l;
  return o;} }

double log (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else { double g, h, k;
  g=log(a.numeratore);
  h=log(a.denominatore);
  k = g-h;
  return k;}
}

double log10 (razionale a)
{if (a.denominatore == 0 || a.attenzione == true) {return NAN; }
  else {double g, h, k;
  g=log10(a.numeratore);
  h=log10(a.denominatore);
  k = g-h;
  return k;}
}

/*riduzione dei razionali*/

razionale riduzione (razionale a)
{
  int n1, d1; n1 = a.numeratore; d1 = a.denominatore;
  int segno; 
if (n1>0 && d1>0 || n1<0 && d1<0) {segno = 1;}
 else {segno = -1;}
 int n,d; n = fabs(n1); d=fabs(d1);
  int k; 
  if (n<d) {k=n;} 
  else {k=d;} 
  for (int i = 2; i<=k; i++)
   {
     if (n%i==0 && d%i==0) 
       {n/=i; d/=i; i--;}
   } 
   razionale u;
   int n2; n2=n*segno;
  u.numeratore=n2;
  u.denominatore=d;
  return u; 
}

/*operatori di input e output*/

istream&operator >> (istream&is, razionale&c)
{
  int num, den;
  char slash;
  is>>num>>slash>>den;
while (is.fail()||is.eof()||is.bad()||slash != '/'||den==0)
{is.clear(); is.seekg(0,ios::beg);
cout<<"errore, digita di nuovo!"<<endl;
is>>num>>slash>>den;}
 c.numeratore=num; c.denominatore=den; c.attenzione = false;
return is;} 

ostream&operator << (ostream&os, razionale k)
{
  if (k.attenzione == true || k.denominatore == 0) {os<<"impossibile restituire un razionale";}  
  else if (k.denominatore==k.numeratore) {os<<1;}
  else if (k.numeratore==0){os<<0;}
  else { razionale u; u=riduzione(k);
 int a, b; a=u.numeratore; b=u.denominatore;
 if (u.denominatore==1) {os<<u.numeratore;}
 else if (a<0 && b<0 || a>0 && b>0) {os<<fabs(a)<<"/"<<fabs(b);}
 else {os<<"-"<<fabs(a)<<"/"<<fabs(b);} 
}
 return os;}

/*booleani non razionali e razionali <=, >=, ==, !=*/

bool razionale::operator == (razionale a)
{if (a.denominatore == 0 || a.attenzione == true || denominatore == 0 || attenzione == true) {cout<<"Uno degli operandi  e' inutilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
    razionale r,s; r=riduzione(a); s=riduzione(k);   return (r.numeratore==s.numeratore && r.denominatore==s.denominatore)?true:false;}}

bool razionale::operator == (double a)
{if (attenzione == true|| denominatore == 0) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore; double u = (double)k.numeratore/(double)k.denominatore;
    return (u==a)?true:false;}}

bool razionale::operator == (int a)
{if (attenzione == true|| denominatore == 0) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
    razionale r,s,t; double j = (double)a; r=conversione(j); s=riduzione(k); t=riduzione (r);   return (t.numeratore==s.numeratore && t.denominatore==s.denominatore)?true:false;}}

bool operator == (double d, razionale r)
{if (r.denominatore == 0 || r.attenzione == true){cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {double valore=(double)r.numeratore/(double)r.denominatore;
    return(d==valore)?true:false;}}

bool operator == (int d, razionale r)
{if (r.denominatore == 0 || r.attenzione == true){cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {double valore=(double)r.numeratore/(double)r.denominatore;
    return(d==valore)?true:false;}}


bool razionale::operator <= (razionale a)
{if (a.denominatore == 0|| a.attenzione == true || denominatore == 0 || attenzione == true) {cout<<"Uno degli operandi non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
  if (k<a || a==k) {return true;}
  else {return false;}}
}

bool razionale::operator <= (double a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale  e' inutilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
 if (k<a || a==k) {return true;}
 else {return false;}}
}

bool operator <= (double a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale è inutilizzabile"<<endl; return false;}
  else {double valore = (double)j.numeratore/(double)j.denominatore;
  if (a<valore || a==valore) {return true;}
  else {return false;}}}

bool razionale::operator <= (int a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
 if (k<a || a==k) {return true;}
 else {return false;}}
} 

bool operator <= (int a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {double valore = (double)j.numeratore/(double)j.denominatore;
  if (a<valore || a==valore) {return true;}
  else {return false;}}
}


bool razionale::operator >= (razionale a)
{if (a.denominatore == 0 || a.attenzione == true || denominatore == 0 || attenzione == true) {cout<<"Uno degli operandi non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
  if (k>a || a==k) {return true;}
  else {return false;}}}

bool razionale::operator >= (double a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
 if (k>a || a==k) {return true;}
 else {return false;}}}

bool operator >= (double a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
    else {double valore = (double)j.numeratore/(double)j.denominatore;
  if (a>valore || a==valore) {return true;}
  else {return false;}}
  }

bool razionale::operator >= (int a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore = numeratore; k.denominatore=denominatore;
 if (k>a || a==k) {return true;}
 else {return false;}}}

bool operator >= (int a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
    else {double valore = (double)j.numeratore/(double)j.denominatore;
  if (a>valore || a==valore) {return true;}
  else {return false;}}
}

bool razionale::operator != (razionale a)
{if (a.denominatore == 0 || a.attenzione == true || denominatore == 0 || attenzione == true) {cout<<"Uno degli operandi non e' utilizzabile"<<endl; return false;}
  else {
razionale k; k.numeratore=numeratore; k.denominatore=denominatore;
  razionale j,l ; j=riduzione(k); l=riduzione(a);
  if (j.numeratore!=l.numeratore || j.denominatore!=l.denominatore)
    {return true;}
  else {return false;}}}

bool razionale::operator != (double a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale e' inutilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore=numeratore; k.denominatore=denominatore;
  double val = (double)k.numeratore/(double)k.denominatore;
  if (val!=a) {return true;}
  else {return false;}}
}

bool operator != (double a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {double val = (double)j.numeratore/(double)j.denominatore; 
  if (a!=val) {return true;}
  else {return false;}}
}

bool razionale::operator != (int a)
{if (denominatore == 0 || attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else {razionale k; k.numeratore=numeratore; k.denominatore=denominatore;
  double val = (double)k.numeratore/(double)k.denominatore;
  if (val!=a) {return true;}
  else {return false;}}
}

bool operator != (int a, razionale j)
{if (j.denominatore == 0 || j.attenzione == true) {cout<<"Il razionale non e' utilizzabile"<<endl; return false;}
  else { double val = (double)j.numeratore/(double)j.denominatore; 
  if (a!=val) {return true;}
  else {return false;}}
}

/*elevamento a potenza*/

razionale pow (razionale a, razionale b)
{razionale conv;
  if (a.denominatore == 0|| a.attenzione == true || b.denominatore == 0 || b.attenzione == true) 
{conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
  else { double k, l;
   k = (double)a.numeratore/(double)a.denominatore;
  l = (double)b.numeratore/(double)b.denominatore;
  if (k<0 && abs(b.numeratore)%abs(b.denominatore) != 0) {conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
   else {double risultato;
  risultato = pow (k,l); 
  conv = conversione (risultato);}}
  return conv;
}

razionale pow (double a, razionale b)
{ razionale conv;
 if (b.denominatore == 0 || b.attenzione == true) {conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
 else {double l;
  l = (double)b.numeratore/(double)b.denominatore;
  if (a<0 && abs (b.numeratore) % abs (b.denominatore) != 0) {conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
 else {double risultato;
  risultato = pow (a,l);
  conv = conversione (risultato);}}
  return conv;
 }

razionale pow (int a, razionale b)
{  razionale conv;
 if (b.denominatore == 0 || b.attenzione == true) {conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
  else {double l; double u = (double) a;
 l = (double)b.numeratore/(double)b.denominatore;
 if (u<0 && abs (b.numeratore) %abs(b.denominatore) != 0) {conv.numeratore = 0; conv.denominatore = 0; conv.attenzione=true;}
  else {double risultato;
  risultato = pow (u,l);
  conv = conversione (risultato);}}
  return conv;
}

/*MAIN!!*/

int main ()
{ 
  razionale a; razionale b; 
cout<<"Benvenuto/a nel programma di Costanza Benassi e Elisa Bonafe' per l'elaborazione di numeri razionali"<<endl;
 cout<<"Inserisci un razionale (a)"<<endl;
 cin>>a;
 cout<<"Inserisci un razionale (b)"<<endl;
 cin>>b;
 cout<<a<<" + ("<<b<<") = "<<a+b<<endl;
 cout<<a<<" * ("<<b<<") = "<<a*b<<endl;
 cout<<a<<" - ("<<b<<") = "<<a-b<<endl; 
 cout<<a<<" / ("<<b<<") = "<<a/b<<endl;
 cout<<"a^b = ";
 if (((double)a.numeratore/(double)a.denominatore)<0 && abs(b.numeratore)%abs(b.denominatore) != 0 ) {cout<<"la funzione pow necessita di una base maggiore di 0 se l'esponente non e' intero"<<endl;}
 else cout<< pow (a, b) <<endl;
 cout<<"Confrontiamo a e b "<<endl;
 if (a == b) {cout<<"a = b"<<endl;}
 if (a != b) {cout<<"a != b"<<endl;}
 if (a<=b) {cout<<"a <= b"<<endl;}
 if (a >= b) {cout<<"a >= b" <<endl;}
 if (a > b) {cout<<"a > b" <<endl;}
 if (a < b) {cout<<"a < b" <<endl;}
 cout<<"occupiamoci delle funzioni trigonometriche di a..."<<endl;
 cout<<"sin(a) = "<<sin(a)<<endl;
 cout<<"cos(a) = "<<cos(a)<<endl;
 cout<<"tan(a) = "<<tan(a)<<endl;
 cout<<"asin(a) = "<<asin(a)<<endl;
 cout<<"acos(a) = "<<acos(a)<<endl;
 cout<<"atan(a) = "<<atan(a)<<endl;
 cout<<"...e ora di quelle iperboliche!"<<endl;
 cout<<"sinh(a) = "<<sinh(a)<<endl;
 cout<<"cosh(a) = "<<cosh(a)<<endl;
 cout<<"tanh(a) = "<<tanh(a)<<endl;
 cout<<"asinh(a) = "<<asinh(a)<<endl;
 cout<<"acosh(a) = "<<acosh(a)<<endl;
 cout<<"atanh(a) = "<<atanh(a)<<endl;
 cout<<" Prima di passare alle operazioni con i decimali, le ultime funzioni: "<<endl;
 cout<<"La radice quadrata di a e' "<<sqrt(a)<<endl;
 cout<<"Il logaritmo naturale di a e' "<<log(a)<<endl;
 cout<<"Il logaritmo in base dieci di a e' "<<log10(a)<<endl;
 cout<<"E ora, un altro razionale (c)! "<<endl;
 razionale c; double d; 
 cin>>c;
 cout<<"Inserisci anche un numero decimale (d)"<<endl;
 cin>>d;
 cout<<c<<" + ("<<d<<") = "<<c+d<<endl;
 cout<<c<<" * ("<<d<<") = "<<c*d<<endl;
 cout<<c<<" - ("<<d<<") = "<<c-d<<endl; 
 cout<<c<<" / ("<<d<<") = "<<c/d<<endl;
cout<<d<<" / ("<<c<<") = "<<d/c<<endl;
 cout<<"d^c = ";
 if (d<0 && abs (c.numeratore)% abs(c.denominatore) != 0) {cout<<"la funzione pow necessita di una base maggiore di 0 se l'esponente non e' intero"<<endl;} 
 else cout<<pow (d, c) <<endl;
 cout<<"confrontiamo c e d "<<endl;
 if (c == d) {cout<<"c = d"<<endl;}
 if (c != d) {cout<<"c != d"<<endl;}
 if (c<=d) {cout<<"c <= d"<<endl;}
 if (c >= d) {cout<<"c >= d" <<endl;}
 if (c > d) {cout<<"c > d" <<endl;}
 if (c < d) {cout<<"c < d" <<endl;} 
 cout<<"E se ti fosse venuta la curiosita' di sapere la conversione a frazione di d..."<<endl;
 cout<<d<<" = "<<conversione(d)<<endl; 
 cout<<"E per finire..."<<endl;
 int e; razionale f; 
 cout<<"Inserisci un intero (e)"<<endl;
 cin>>e;
 cout<<"E ora, un razionale (f)!"<<endl;
 cin>>f;
cout<<e<<" + ("<<f<<") = "<<e+f<<endl;
 cout<<e<<" * ("<<f<<") = "<<e*f<<endl;
 cout<<e<<" - ("<<f<<") = "<<e-f<<endl; 
 cout<<e<<" / ("<<f<<") = "<<e/f<<endl;
cout<<f<<" / ("<<e<<") = "<<f/e<<endl;
 cout<<"e^f = ";
 if (e<0 && abs(f.numeratore)%abs(f.denominatore) != 0){cout<<"la funzione pow necessita di una base maggiore di 0 se l'esponente non e' intero"<<endl;}
 else cout<<pow (e, f) <<endl;
 cout<<"Confrontiamo f ed e  "<<endl;
 if (f == e) {cout<<"f = e"<<endl;}
 if (f != e) {cout<<"f != e"<<endl;}
 if (f<=e) {cout<<"f <= e"<<endl;}
 if (f >= e) {cout<<"f >= e" <<endl;}
 if (f > e) {cout<<"f > e" <<endl;}
 if (f < e ) {cout<<"f < e" <<endl;}
 cout<<"Questo e'quanto! Arrivederci! ^_^"<<endl;
}
