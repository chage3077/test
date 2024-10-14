#include"AbstructAdepter.h"
#include"EnglishAdepter.h"
#include"AmericanAdepter.h"
#include"Foreigner.h"
#include"English.h"
#include"American.h"
int main()
{
    Foreigner* foreigner = new American;
    AbstructAdepter* adepter = new AmericanAdepter(foreigner);
    adepter->translateToChinese();
    adepter->transloateToForeign();
    delete foreigner;
    delete adepter;
    cout<<"----------------------------------"<<endl;
    foreigner =new English;
    adepter=new EnglishAdepter(foreigner);
    adepter->translateToChinese();
    adepter->transloateToForeign();
    delete foreigner;
    delete adepter;

    return 0;
}