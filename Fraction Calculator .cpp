
#include <iostream>
#include <string>

using namespace std;


class Zfraction
{


  public:
   //constructeurs
  Zfraction(int numerateur,int denominateur);
  Zfraction(int numerateur);
  Zfraction();
  //constructeur de copie
  Zfraction(Zfraction const& autre);

  //surcharge interne
  Zfraction& operator+=(Zfraction & b);
  Zfraction& operator*=(Zfraction const& b);
  Zfraction& operator-=(Zfraction & b);
  
  //operator de flux
  friend ostream& operator<<(ostream & flux ,Zfraction const& objet);
   //setter
  void setnumerateur(int num);
  void setdenominateur(int deno);

  void afficher(ostream& flux)const;
  bool estplusgrand(Zfraction const& b)const;
  bool estEgal(Zfraction const& b) const;
  void simplifie();

  Zfraction& inverse();
   int partieEntiere();

  private:
   int m_numerateur;
   int m_denominateur;


};

//fonction
int pgcd(int a, int b);

Zfraction operator+(Zfraction const& a , Zfraction const& b);
Zfraction operator*(Zfraction const& a , Zfraction const& b);
bool operator>(Zfraction const& a , Zfraction const& b);
bool operator==(Zfraction const& a, Zfraction const& b);
Zfraction operator-(Zfraction const& a , Zfraction const& b);
Zfraction operator/(Zfraction const& a , Zfraction const& b);
istream& operator >>(istream & in ,Zfraction &fraction);

 //setter
  void Zfraction::setnumerateur(int num)
  {
      m_numerateur=num;

  }
  void Zfraction::setdenominateur(int deno)
  {
      if(deno != 0)
      {
         m_denominateur=deno;

      }
  }



int main()
{

    Zfraction a(25,4);// Crée une fraction valant 1/5
    Zfraction b(8);
    Zfraction c,d,e,f,g;

    c= a + b;
 cout << a << " + " << b << " = " << c << endl;

  d = a*b;
  cout << a << " *" << b << " = " << d << endl;

   f= a - b;
 cout << a << " -" << b << " = " << f<< endl;

  g= a / b;
 cout << a << " /" << b << " = " << g << endl;

  if(a > b)

        cout << "a est plus grand que b." << endl;

    else if(a==b)

        cout << "a est egal a b." << endl;

    else

        cout << "a est plus petit que b." << endl;

        cout<<endl;

  cout<<"la partie entiere de la fraction a:"<<endl;
  int PE=a.partieEntiere();
  cout<<PE<<endl;


  cout<<"l'inverse de la fraction a:"<<endl;
      e=a.inverse();
  cout << e<<endl;

  cout<<"la fraction a:"<<endl;
  cout<<a<<endl;
  cin>>a;
  cout<< "la nouvelle fraction a est:";
  cout << a;


return 0;

}

 Zfraction::Zfraction(int numerateur,int denominateur):m_numerateur(numerateur),m_denominateur(denominateur)
 {
       simplifie();
 }
 Zfraction::Zfraction(int numerateur):m_numerateur(numerateur),m_denominateur(1)
 {

 }
 Zfraction::Zfraction():m_numerateur(0),m_denominateur(1)
  {

  }

 Zfraction::Zfraction(Zfraction const& autre):m_numerateur(autre.m_numerateur),m_denominateur(autre.m_denominateur)
  {

  }


  bool Zfraction::estplusgrand(Zfraction const& b)const
  {

    if(m_numerateur * b.m_denominateur < m_denominateur * b.m_numerateur)

        return false;
    else
        return true;
  }

 bool operator>(Zfraction const& a , Zfraction const& b)
 {
       return a.estplusgrand(b);
 }

 bool Zfraction::estEgal(Zfraction const& b) const
{
    return (m_numerateur == b.m_numerateur && m_denominateur == b.m_denominateur);

}

bool operator==(Zfraction const& a, Zfraction const& b)
{
   return a.estEgal(b);
}


  Zfraction& Zfraction::operator+=(Zfraction & b)
 {
     if(m_denominateur == b.m_denominateur)
       {
          m_numerateur+=b.m_numerateur;
       }

    else
       {
         m_denominateur= m_denominateur * b.m_denominateur;
         m_numerateur= m_numerateur * b.m_denominateur;

         b.m_denominateur = b.m_denominateur * m_denominateur;
         b.m_numerateur = b.m_numerateur * m_denominateur;

          m_numerateur+=b.m_numerateur;
       }

       simplifie();


   return *this;

}

 Zfraction operator+(Zfraction const& a , Zfraction const& b)
 {
      Zfraction copieA(a),copieB(b);
      copieA+=copieB;

      return copieA;
 }


 Zfraction& Zfraction::operator-=(Zfraction & b)
 {

      if(m_denominateur == b.m_denominateur)
      {
          m_numerateur-=b.m_numerateur;

      }
      else
      {
         m_denominateur= m_denominateur * b.m_denominateur;
         m_numerateur= m_numerateur * b.m_denominateur;

         b.m_denominateur = b.m_denominateur * m_denominateur;
         b.m_numerateur = b.m_numerateur * m_denominateur;


       m_numerateur-=b.m_numerateur;

      }
    simplifie();

    return *this;

 }


Zfraction operator-(Zfraction const& a , Zfraction const& b)
{

    Zfraction copie1(a),copie2(b);
    copie1 -=copie2;
    return copie1;

}

 Zfraction& Zfraction::operator*=(Zfraction const& b)
 {
      m_numerateur *= b.m_numerateur;
      m_denominateur*= b.m_denominateur;

      simplifie();

    return *this;
 }

Zfraction operator*(Zfraction const& a , Zfraction const& b)
 {
       Zfraction copie(a);
       copie*=b;

       return copie;


 }

 Zfraction operator/(Zfraction const& a , Zfraction const& b)
 {
      Zfraction copieb(b);

    Zfraction copiebInvr= copieb.inverse();

         return a * copiebInvr ;

 }


ostream& operator<<(ostream& flux , Zfraction const& objet)
{
   objet.afficher(flux);

   return flux;
}

void Zfraction::afficher(ostream& flux)const
{
    if(m_denominateur ==1)
      {
        flux<<m_numerateur;
      }
    else
      {
        flux<<m_numerateur<<'/'<<m_denominateur ;
      }

}

istream& operator >>(istream & in ,Zfraction &fraction)
{
    int tmp;
    cout<<"entrer un numerateur:";
    in>>tmp;
    fraction.setnumerateur(tmp);
    cout<<"entrer un denominateur:";
    in>>tmp;
    fraction.setdenominateur(tmp);



    return in;
}

void Zfraction::simplifie()
{

    int nombre=pgcd(m_numerateur, m_denominateur); //Calcul du pgcd


    m_numerateur /= nombre;     //Et on simplifie

    m_denominateur /= nombre;

}

int pgcd(int a, int b)
{

    while (b != 0)
    {
        const int t = b;
        b = a%b;
        a=t;
    }
    return a;

}

Zfraction& Zfraction ::inverse()
  {
      int tmp=0;

      tmp=m_numerateur;
      m_numerateur=m_denominateur;
      m_denominateur=tmp;

      return *this;

  }

int Zfraction::partieEntiere()
{
        int partieEn;
        partieEn= m_numerateur / m_denominateur;

        return partieEn;

}
