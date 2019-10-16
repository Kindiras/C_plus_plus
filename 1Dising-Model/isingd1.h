#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

#define warm 50000 //thermalization steps. 
#define equilibrium 0.1*warm
#define Max_temp 200 //temperature variation.

using namespace std;

 class IsingD1
 {
    public:
       IsingD1(int l,double t,double b);
       ~IsingD1();
      int check_neighbor(int l);
      int thermalization();
      double random_spin();
      int accept_flip(int k);
      double magnetic_spin();
      double energy_spin();
      double average_energy();
      double average_magnetization();
      void save_data();
      double mcmove();
      int random_intergers();
      int accept_events(int s, int y);
      int initialization();
      double specific_heat();
      double get_susceptibility();
      double mag_initial();



    private:
        int L,count_ae;
        int LN, RN; //1D left and right neighbors.
        float T,M,B;
        int *lattice;
        float *Energy;
        float *Magnetization;
        float *Average_E;
        float *Average_M;
        float *Temperatre;
        float *Specific_capacity;
        float *susceptibility;
        
  };

IsingD1::IsingD1(int l, double t, double b) //Constructure in class. it gives the default values. 
    {
    	L=l;
    	T=t;
    	B=b;
    	lattice=new int[L+1];
      Energy=new float [warm+1];
      Magnetization=new float [warm+1];
      Average_E =new float[Max_temp+1];
      Temperatre=new float [Max_temp+1];
      Average_M=new float [Max_temp+1];
      Specific_capacity=new float [Max_temp+1];
      susceptibility = new float [Max_temp+1];
      }

IsingD1::~IsingD1() //destructor (~ for destructor), it will empty to save memory. 
   {
    delete [] lattice;
    delete [] Energy;
    delete [] Magnetization;
    delete [] Average_E;
    delete [] Temperatre;
    delete [] Average_M;
    delete [] Specific_capacity;
    delete [] susceptibility;
    cout<<"emptying all the arrays"<<"\n";
   }


//Below are all the function define. 
   //we can change and reduce the functions to increase the computer computing capability. 
double IsingD1::mag_initial()
     {
        int i;
        for(i=0;i<Max_temp;i++)
          Average_M[i]=0;
        return 0;
      }

int IsingD1::initialization()
    {
      int i,j,k; 
      cout<<"..............initialization.................."<<"\n";
      count_ae=0;
      for(i=0;i<=L;i++)
        {

         lattice[i]=1; //initially all lattic1es are spin up.

        }
       for (j=0;j<=warm;j++)
        {
          Energy[j]=0;Magnetization[j]=0;
        }
           return 0;
    }


double IsingD1::mcmove()
{
  int t;
  mag_initial();
  for (t=0;t<Max_temp;t++)
    {
    srand(time(NULL)); 
    //cout<<"hereeeroafajflafljafjalfjalfjalfjali"<<"\n";
   initialization();
   thermalization();
   Average_E[t]=average_energy();
   Average_M[t]=average_magnetization();
   Temperatre[t]=T;
   Specific_capacity[t]=specific_heat();
   susceptibility[t]=get_susceptibility();
   T=T+0.01;
   cout<<"Temperature: "<<T<<"\n";
     }
   save_data();
  return 0;
 }



int IsingD1::thermalization()
{
    int n,i;
    //choose a lattice randomly for flipping. 
  for (i=0;i<warm;i++)
  {
    n=int (random_spin()*L); 
   if(accept_flip(n)==1)
   {
    Energy[i]=energy_spin();
    Magnetization[i]=magnetic_spin();
    count_ae=count_ae+1;
    }
  }
  return 0;
}

int IsingD1::check_neighbor(int l)
    {
       int LN, RN;
       LN = l-1;
       RN = l+1;

       LN = ( LN < 0 ? L : LN);
       RN = (RN >L ? 0 : RN);
      return (LN+RN);   
    }

//this function returns the value between 0-1.
 double IsingD1::random_spin()
 {
  return double (drand48());
 }

//this function returns the value between 0 and 1 to get the fliping decision. 
int IsingD1::random_intergers()
{
  return (int (rand() % 2));
}

int IsingD1::accept_flip(int n)
{
  int x, y, nn,ln,rn;
  float Ha,Hb,dH,r,e,val;
  y= random_intergers();
  x=2*y-1;
  nn = check_neighbor(n);
  ln = (nn==L+1 ? L : (nn/2 -1));
  rn = (nn==L+1 ? 1 : (nn/2 +1));
  ln = (nn==L-1 ? L-1 : (nn/2 -1));
  rn = (nn==L-1 ? 0 : (nn/2 +1));
  Ha = lattice[n]*lattice[ln]+lattice[n]*lattice[rn];
  Hb = lattice[ln]*x+lattice[rn]*x;
  dH = (Hb - Ha);
  val=float (-dH/T);
  e = float (exp(val));
  r = random_spin();
  //cout <<"before lattice"<<lattice[n]<<x<<y<<"\n";
  if (dH <0 || r<e)
    {
      accept_events(n,x);
      return 1;
    }
    else{return 0;}
}

int IsingD1::accept_events(int n, int x)
{
  lattice[n]=x;
  //cout<<count_ae<<"\n";
  //cout<<"accepted";
  //cout <<"AFTER lattice"<<lattice[n]<<x<<"\n";
  return 0;
}

double IsingD1::energy_spin()
{
  int i, Esig=0;
  for (i=0;i<L-1;i++)
  {
   Esig= Esig+lattice[i]*lattice[i+1];
  }
  Esig=Esig+lattice[L]*lattice[0];
  return Esig;
}

double IsingD1::magnetic_spin()
{
  int i, Msig=0;
  for (i=0;i<=L;i++)
  {
  Msig=Msig+lattice[i];
  }
  return Msig;
}

double IsingD1::average_energy()
{
  int i;
  float E_total=0,E_avg=0;
  for (i=equilibrium;i<warm;i++)
    {
      E_total=E_total+Energy[i];
      E_avg=E_total/(count_ae*L);
    }
    return E_avg;
}

double IsingD1::average_magnetization()
{
  int i;
  float M_total=0,M_avg=0;
  for (i=equilibrium;i<warm;i++)
    {
      M_total=M_total+Magnetization[i];
      M_avg=M_total/(count_ae*L);
    }
    //cout<<"magnetization"<<M_avg<<"\n";
    return M_avg;
}

double IsingD1::specific_heat()
{
  float Avgsqr=0; float Avg=0;
  int i;
  for (i=equilibrium;i<warm;i++)
    { Avgsqr=Avgsqr+Energy[i]*Energy[i];
      Avg=Avg+Energy[i];
    }
    return (((Avgsqr/count_ae)-(Avg*Avg/(count_ae*count_ae)))/(T*T*L));
}

double IsingD1::get_susceptibility()
{
  float Avgsqr=0; float Avg=0;
  int i;
  for (i=equilibrium;i<warm;i++)
    { Avgsqr=Avgsqr+Magnetization[i]*Magnetization[i];
      Avg=Avg+Magnetization[i];
    }
    return ((Avgsqr/count_ae-(Avg*Avg/(count_ae*count_ae)))/(T*L));
}

void IsingD1::save_data()
{
  int i;
  FILE *fpt;
  fpt = fopen("results.dat","a");
  {
    fprintf(fpt, "%s\t","Temperature");
    fprintf(fpt, "%s\t","Energy");
    fprintf(fpt, "%s\t","Magnetization");
    fprintf(fpt, "%s\t","specific-Heat");
    fprintf(fpt, "%s\n","susceptibility");
    for (i=0;i<Max_temp;i++)
      {
        fprintf(fpt, "%0.3f\t",Temperatre[i]);
        fprintf(fpt, "%0.3f\t",Average_E[i]);
        fprintf(fpt, "%0.3f\t",Average_M[i]);
        fprintf(fpt, "%0.3f\t",Specific_capacity[i]);
        fprintf(fpt, "%0.3f\n",susceptibility[i]);
       }
   fclose(fpt);
   }
}
