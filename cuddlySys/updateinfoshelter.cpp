#include "updateinfoshelter.h"
#include "ui_updateinfoshelter.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
updateinfoshelter::updateinfoshelter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateinfoshelter)
{
    ui->setupUi(this);

    //sets placeholder text for the boxes
    ui->LE_name->setPlaceholderText("New Displayed Name");
    ui->LE_password->setPlaceholderText("New Password");
    ui->LE_bio->setPlaceholderText("New Bio");
    ui->LE_phoneno->setPlaceholderText("New Phone No");
    ui->LE_address->setPlaceholderText("New Address");
    ui->LE_zipcode->setPlaceholderText("New Zip Code");
}

/**
 * @brief Destructor for the class
 */
updateinfoshelter::~updateinfoshelter()
{
    delete ui;
}

/**
 * @brief Updates the information displayed for the user
 */
void updateinfoshelter::on_PB_update_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QString newName, newPass, newPhone, newState, newBio, newGender, newAddr;
    int newzip;

    // obtain info
    newName = ui->LE_name->text();
    newPass = ui->LE_password->text();
    newBio = ui->LE_bio->text();
    newPhone = ui->LE_phoneno->text();
    newAddr = ui->LE_address->text();
    newState = ui->CB_State->currentText();
    newzip = ui->LE_zipcode->text().toInt();
    newGender = ui->CB_Gender->currentText();

    currUser->setName(newName);
    currUser->setPassword(newPass);
    currUser->setBio(newBio);
    currUser->setPhoneNo(newPhone);
    currUser->setUserAddress(newAddr);
    currUser->setLocation(newState);
    currUser->setUserZipCode(newzip);
    currUser->setGender(newGender);
    db.updateUser(currUser);
    ShelterOwnerMain *som = new ShelterOwnerMain();
    som->show();
    this->close();
}

/**
 * @brief Handles back button functionality
 */
void updateinfoshelter::on_back_clicked()
{
    ShelterOwnerMain *som = new ShelterOwnerMain();
    som->show();
    this->close();
}
