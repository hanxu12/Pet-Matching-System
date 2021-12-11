/**
* entry.cpp
* The source file for logging in.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "entry.h"
#include "ui_entry.h"
#include<QSqlQueryModel>
#include<QMessageBox>

/**
 * @brief Entry constructor
 */
entry::entry(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::entry)
{
    ui->setupUi(this);
    ui->Username->setPlaceholderText("Username");   //label field as username
    ui->Password->setPlaceholderText("Password");   //label field as password
}

/**
 * @brief Entry deconstructor
 */
entry::~entry() {
    delete ui;
}

/**
 * @brief Takes entrered username/password and checks for validity.
 * If the username and password are valid, login and navigate
 * to respective dashboard (admin, potential pet owner, shelter/foster parent).
 * If invalid, display login failed status and do not navigate.
 */
void entry::on_loginButton_clicked() {
    QString username = ui->Username->text();    //store entered username
    QString password = ui->Password->text();    //store entered password
    DataBase db("../../cuddlySys/sysDB.db");
    if (db.isValid(username,password))
    {
        // You login a user here
        userID = db.getUserID(username);
        currUser->setUid(userID);
        currUser->setName(db.getName(userID));
        currUser->setUsername(username);
        currUser->setPassword(password);
        currUser->setUserType(db.getGroupType(userID));
        currUser->setPhoneNo(db.getPhoneNo(userID));
        currUser->setLocation(db.getLoc(userID));
        currUser->setGender(db.getGender(userID));
        currUser->setUserZipCode(db.getZip(userID));
        currUser->setUserAddress(db.getUserAddr(userID));
        currUser->setUserspeciesPref(db.getUserSpeciesPref(userID));
        currUser->setUserBreedPref(db.getUserBreedPref(userID));
        currUser->setUserColorPref(db.getUserColorPref(userID));
        currUser->setUserAgePref(db.getUserAgePref(userID));
        currUser->setUserWeightPref(db.getUserWeightPref(userID));
        currUser->setBio(db.getUserBio(userID));
        ui->statuslabel->setText("correct");
        if (db.getGroupType(userID) == 0) {  //if admin
            this->hide();
            ManageUsers *mu = new ManageUsers();
            mu -> show();
        }
        else if ((currUser->getUserType() == 1) || (currUser->getUserType() == 2)) {  //if shelterowner/foster parent
            this->hide();
            ShelterOwnerMain *som = new ShelterOwnerMain();
            som -> show();
        }
        else if (currUser->getUserType() == 3) {  //if potential petowner
            this->hide();
            Petowner *petowner = new Petowner();
            petowner -> show();
        }
        else {
            qDebug() << "user type undfined" << endl;
        }
    }
    else
    {
        qDebug() << "Login failed. Invalid username or password.";
        ui->statuslabel->setText("Status: Login failed. \n Invalid username or password.");
        ui->statuslabel->adjustSize();
        //ui->status->setText("Login failed. Invalid username or password.");
    }
}
/**
 * @brief Close program if the exit button is clicked
 */
void entry::on_ExitButton_clicked()
{
    close();
}

/**
 * @brief If user clicks register button, show registration interface
 */
void entry::on_PB_register_clicked()
{
    enterFrom = "entry";
    RegistrationMain *newRegister = new RegistrationMain();
    newRegister -> show();
    this->close();
}
