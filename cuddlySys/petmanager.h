/**
* petmanager.h
* The header file for management class of pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef PETMANAGER_H
#define PETMANAGER_H
#include <QString>

class PetManager
{
public:
    PetManager();
    void setPetID(int petid);   //petID setter method
    int getPetID(); //petID getter method
    void setPetName(QString name);  //petName setter method
    QString getPetName();   //petName getter method
    void setPetSpecies(QString species);    //petSpecies setter method
    QString getPetSpecies();    //petSpecies getter method
    void setPetBreed(QString breed);    //petBreed setter method
    QString getPetBreed();  //petBreed getter method
    void setPetGender(QString gender);  //petGender setter method
    QString getPetGender(); //petGender getter method
    void setPetAge(int petAge); //petAge setter method
    int getPetAge();    //petAge getter method
    void setPetShelterID(int petShelterID); //petShelterID setter method
    int getPetShelterID();  //petShelterID getter method
    void setPetWeight(int petWeight);   //petWeight setter method
    int getPetWeight(); //petWeight getter method
    void setPetDescription(QString petDescription); //petDescription setter method
    QString getPetDescription();    //petDescription getter method
    void setPetColor(QString petColor); //petColor setter method
    QString getPetColor();  //petColor getter method
    void setPetDisease(int ifDisease);  //petDisease status setter method
    int getPetDisease();    //petDisease status getter method
    void setPetRescue(int ifRescue);    //petRescue status setter method
    int getPetRescue(); //petRescue status getter method
    void setPetImgPath1(QString petImgPath1);   //petImgPath1 setter method
    QString getPetImgPath1();   //petImgPath1 getter method
    void setPetImgPath2(QString petImgPath2);   //petImgPath2 setter method
    QString getPetImgPath2();   //petImgPath2 getter method

private:
    int petID;
    QString petName;
    QString petSpecies;
    QString petBreed;
    QString petGender;
    int petAge;
    int petShelterID;
    int petWeight;
    QString petDescription;
    QString petColor;
    int isDiseased;
    int isRescued;
    QString petImgPath1;
    QString petImgPath2;
};

#endif // PETMANAGER_H
