#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <string>
#include <iostream>
#include <unordered_map>
#include <QString>
#include <QDebug>

using namespace std;

class UserManager
{
public:
    UserManager();

    void setUid(int uidcpy); // updates uid
    int getUid(); // returns uid

    void setUsername(QString usernameCpy); // updates username
    QString getUsername(); // returns username

    void setPassword(QString passwordCpy); // updates password
    QString getPassword(); // returns password

    void setPhoneNo(QString phoneNoCpy); // updates contact info
    QString getPhoneNo(); // returns contact info

    void setLocation(QString locationCpy); // updates location
    QString getLocation(); // returns location

    void setName(QString nameCpy); // updates display name
    QString getName(); // returns display name

    void setGender(QString genderCpy); // updates gender
    QString getGender(); // returns gender

    void setBio(QString bioCpy); // updates description
    QString getBio(); // returns description

    void setUserType(int userTypeCpy); // updates type of user
    int getUserType(); // returns type of user

    void setUserLocPref(QString pref); // updates location preference
    QString getUserLocPref();// returns location preference

    void setUserspeciesPref(QString pref); // updates species preference
    QString getUserspeciesPref(); // returns species preference

    void setUserBreedPref(QString pref); // updates breed preference
    QString getUserBreedPref(); // returns breed preference

    void setUserColorPref(QString pref); // updates color preference
    QString getUserColorPref(); // returns color preference

    void setUserAgePref(QString pref); // updates age preference
    QString getUserAgePref(); // returns age preferenece

    void setUserWeightPref(QString pref); // updates weight preference
    QString getUserWeightPref(); // returns weight preference

    void setUserDiseasePref(int pref); // updates disease preference
    int getUserDiseasePref(); // returns disease preference

    void setUserRescuePref(int pref); // updates rescued preference
    int getUserRescuePref(); // returns rescued preference

    void setUserZipCode(int zip); // updates user zip code
    int  getUserZipCode(); // returns user zip code

    void setUserAddress(QString addr); // updates user address
    QString getUserAddress(); // returns user address

private:
    //void setPref(string key, string value);
    //string returnPref(string key);
    int uid;
    QString username;
    QString password;
    QString phoneNo;
    QString location;
    QString name;
    QString gender;
    QString bio;
    int userType;
    QString locPref;
    QString speciesPref;
    QString breedPref;
    QString colorPref;
    QString agePref;
    QString weightPref;
    QString address;
    int diseasePref;
    int rescuePref;
    int zipcode;
};

#endif // USERMANAGER_H
