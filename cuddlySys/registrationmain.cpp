/**
* registrationmain.cpp
* The source file for registering a new account.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "registrationmain.h"
#include "ui_registrationmain.h"
#include "petownerpref.h"
#include <database.h>

/**
 * @brief RegistrationMain constructor
 * @param parent
 */
RegistrationMain::RegistrationMain(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegistrationMain)
{
    //currUser = new UserManager;
    ui->setupUi(this);
    //ui->CB_AccType->setCurrentIndex(-1);
    //    if (enterFrom == "admin") {
    //        ui->label->setText("Admin Add User");
    //        ui->PB_back->setVisible(false);
    //    }
    ui->LE_username->setPlaceholderText("Username");
    ui->LE_password->setPlaceholderText("Password");
    ui->LE_confirmPass->setPlaceholderText("Confirm Password");
    ui->LE_phoneno->setPlaceholderText("Contact Information");
    ui->LE_name->setPlaceholderText("Display Name");
    ui->LE_bio->setPlaceholderText("Bio/Description");
    ui->LE_address->setPlaceholderText("Address");
    ui->LE_zipcode->setPlaceholderText("Zip Code");
}

/**
 * @brief RegistrationMain deconstructor
 */
RegistrationMain::~RegistrationMain()
{
    delete ui;
}

/**
 * @brief Close registration interface when button pressed
 */
void RegistrationMain::on_PB_back_clicked()
{
    entry *newentry = new entry();
    newentry -> show();
    this->close();
}

/**
 * @brief Checks for existing users, all fields to be filled, then creates account
 */
void RegistrationMain::on_PB_createAcc_clicked()
{
    QString username, pass, rePass, phoneNo, Bio, location, accType, gender, name, address;
    int zip;
    //obtain personal info
    username = ui->LE_username->text();
    pass = ui->LE_password->text();
    rePass = ui->LE_confirmPass->text();
    name = ui->LE_name->text();
    phoneNo = ui->LE_phoneno->text();
    Bio = ui->LE_bio->text();
    accType = ui->CB_AccType->currentText();
    gender = ui->CB_Gender->currentText();
    location = ui->CB_State->currentText();
    zip = ui->LE_zipcode->text().toInt();
    address = ui->LE_address->text();
    DataBase db("../../cuddlySys/sysDB.db");

    qDebug() << QString::compare(pass,rePass,Qt::CaseSensitive) << endl;
    //1. whether the passwords match? (failed register)
    if (QString::compare(pass,rePass,Qt::CaseSensitive) != 0) {  //0 meaning equal
        ui->QL_registerStatus->setText("Passwords do not match!"); //not register
    }
    //2. whether the username already exists? (failed register)
    else if (db.exist(username)) {
        ui->QL_registerStatus->setText("User exists");  //not register
    } else  //(register)
    {
        currUser->setUsername(username);
        currUser->setPassword(pass);
        currUser->setName(name);
        currUser->setBio(Bio);
        currUser->setPhoneNo(phoneNo);
        currUser->setLocation(location);
        currUser->setGender(gender);
        currUser->setUserZipCode(zip);
        userID = db.getMaxUid()+1;
        qDebug() << userID << endl;
        currUser->setUid(userID);
        currUser->setUserAddress(address);
        ui->QL_registerStatus->setText("You may register"); //you may register
        //            if (enterFrom == "admin") {
        //                db.addUser(currUser);
        //                currUser->setUid(1);
        //                this->close();
        //            }
        if (accType == "Potential Pet Owner"){
            currUser->setUserType(3);
            db.addUser(currUser);
            this->close();
            PetownerPref * pref = new PetownerPref();
            pref->show();

        } else if (accType == "Foster Parent") {
            currUser->setUserType(2);
            db.addUser(currUser);
            this->close();
            ShelterOwnerMain *som = new ShelterOwnerMain();
            som -> show();

        } else if (accType == "Shelter Owner") {
            currUser->setUserType(1);
            db.addUser(currUser);
            this->close();
            ShelterOwnerMain *som = new ShelterOwnerMain();
            som -> show();
        }
    }
}

