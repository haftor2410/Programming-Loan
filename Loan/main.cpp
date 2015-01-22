#include <iostream>
#include <iomanip>
using namespace std;

class klasi
{
private:
    
    double hofudstoll;
    double vextir;
    int fjoldi_afborgana;
    double manadagreidslur;
    
public:
    klasi();
    klasi(double hof, double vex, int f_afb);
    
    void computeInstalments();
    
};





int main()
{
    double hof;
    double vex;
    int f_afb;
    
    cout << "Sláðu inn upplýsingar fyrir lánið" << endl;
    cout << "Höfuðstóll : ";
    cin >> hof;
    
    cout << "Árlegir vextri (%) : ";
    cin >> vex;
    vex = vex/12;
    
    cout << "Fjöldi afborgana : ";
    cin >> f_afb;
    
    
    klasi loan(hof, vex, f_afb);
   
    loan.computeInstalments();
  
    return 0;
}
klasi::klasi()
{
    
}
klasi::klasi(double hof, double vex, int f_afb)
{
    hofudstoll = hof;
    vextir = vex;
    fjoldi_afborgana = f_afb;
}





void klasi::computeInstalments()
{
    double borgun_a_man = hofudstoll / fjoldi_afborgana;
    
    double vaxtaborgun = 0, total_a_man = 0;
    
    double heildarvextir = 0;
    
    double heildarborgun = 0;
    
    cout << "No.    Principal   Instalments     Interest    Total Payment" << endl;
    cout << "------------------------------------------------------------" << endl;
    for(int i = 0; i < fjoldi_afborgana; i++)
    {
        vaxtaborgun = (vextir / 100) * hofudstoll;
        total_a_man = borgun_a_man + vaxtaborgun;

        cout << " " << (i+1) << "     " << hofudstoll << "     " << borgun_a_man << "      " << vaxtaborgun << "       " << total_a_man << endl;
        
        hofudstoll -= borgun_a_man;
        
        heildarvextir += vaxtaborgun;
        
        heildarborgun += total_a_man;
    }
    cout << "------------------------------------------------------------" << endl;
    cout << "                  " << hofudstoll << "    " << heildarvextir << "     " << heildarborgun << endl;
}