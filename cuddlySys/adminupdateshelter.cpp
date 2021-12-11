#include "adminupdateshelter.h"
#include "ui_adminupdateshelter.h"

/**
 * @brief adminUpdateShelter::adminUpdateShelter
 * initilization of all the ui elements
 * @param parent
 */
adminUpdateShelter::adminUpdateShelter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminUpdateShelter)
{
    ui->setupUi(this);
    ui->LE_username->setPlaceholderText("New username");
    ui->LE_password->setPlaceholderText("New password");
    ui->LE_displayname->setPlaceholderText("New Display Name");
    ui->LE_phoneno->setPlaceholderText("New Contact Info");
    ui->LE_address->setPlaceholderText("New Address");
    ui->LE_zipcode->setPlaceholderText("New zip code");
    ui->LE_bio->setPlaceholderText("New Bio/Description");
}

/**
 * @brief adminUpdateShelter::~adminUpdateShelter
 * destructor of the instance of the class
 */
adminUpdateShelter::~adminUpdateShelter()
{
    delete ui;
}

/**
 * @brief adminUpdateShelter::on_PB_update_clicked
 * reads all the information from the ui elemnts and updated the shelter owner/foster parent accordingly
 */
void adminUpdateShelter::on_PB_update_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QString newUsername, newName, newPass, newPhone, newState, newBio, newGender, newAddr;
    int newzip;
    UserManager *tmpUser = new UserManager;
    //obtain info
    newUsername = ui->LE_username->text();
    newPass = ui->LE_password->text();
    newName = ui->LE_displayname->text();
    newPhone = ui->LE_phoneno->text();
    newAddr = ui->LE_address->text();
    newState = ui->CB_State->currentText();
    newzip = ui->LE_zipcode->text().toInt();
    newBio = ui->LE_bio->text();
    newGender = ui->CB_Gender->currentText();

    tmpUser->setUserType(db.getGroupType(viewUserID));
    tmpUser->setUid(viewUserID);
    tmpUser->setUsername(newUsername);
    tmpUser->setName(newName);
    tmpUser->setPassword(newPass);
    tmpUser->setBio(newBio);
    tmpUser->setPhoneNo(newPhone);
    tmpUser->setUserAddress(newAddr);
    tmpUser->setLocation(newState);
    tmpUser->setUserZipCode(newzip);
    tmpUser->setGender(newGender);
    db.updateUser(tmpUser);
    ManageUsers *mu = new ManageUsers;
    mu->show();
    this->close();
}

/**
 * @brief adminUpdateShelter::on_back_clicked
 * when the button is clicked it takes you back to the manageusers page
 */
void adminUpdateShelter::on_back_clicked()
{
    ManageUsers *mu = new ManageUsers;
    mu->show();
    this->close();
}
