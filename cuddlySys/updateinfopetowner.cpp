#include "updateinfopetowner.h"
#include "ui_updateinfopetowner.h"

/**
 * @brief Conscructor for the class
 * @param parent
 */
updateinfopetowner::updateinfopetowner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updateinfopetowner)
{
    ui->setupUi(this);

    // sets placeholder text for the boxes
    ui->LE_name->setPlaceholderText("New Display Name");
    ui->LE_password->setPlaceholderText("New Password");
    ui->LE_bio->setPlaceholderText("New Bio/Description");
    ui->LE_phoneno->setPlaceholderText("New Contact Info");
    ui->LE_breed->setPlaceholderText("New Breed");
    ui->LE_address->setPlaceholderText("New Address");
    ui->LE_zipcode->setPlaceholderText("New Zip Code");
}

/**
 * @brief Destructor for the class
 */
updateinfopetowner::~updateinfopetowner()
{
    delete ui;
}

/**
 * @brief Updates the information displayed
 */
void updateinfopetowner::on_PB_update_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int rescuePref, diseasePref;

    //obtain info
    currUser->setName(ui->LE_name->text());
    currUser->setBio(ui->LE_bio->text());
    currUser->setPassword(ui->LE_password->text());
    currUser->setPhoneNo(ui->LE_phoneno->text());
    currUser->setUserAddress(ui->LE_address->text());
    currUser->setLocation(ui->CB_State->currentText());
    currUser->setUserZipCode(ui->LE_zipcode->text().toInt());
    currUser->setGender(ui->CB_Gender->currentText());

    currUser->setUserLocPref(ui->radius->currentText());
    currUser->setUserColorPref(ui->color->currentText());
    currUser->setUserspeciesPref(ui->species->currentText());
    currUser->setUserAgePref(ui->age->currentText());
    currUser->setUserBreedPref(ui->LE_breed->text());
    currUser->setUserWeightPref(ui->weight->currentText());

    // handles rescued preference
    if (ui->isRescued->checkState()) {
        rescuePref = 1;
    } else {
        rescuePref = 0;
    }

    // hanldes diseased preference
    if (ui->isDiseased->checkState()) {
        diseasePref = 1;
    } else {
        diseasePref = 0;
    }

    currUser->setUserRescuePref(rescuePref);
    currUser->setUserDiseasePref(diseasePref);
    db.updateUser(currUser);

    Petowner *petown = new Petowner();
    petown->show();
    this->close();
}

/**
 * @brief Handles back button functionality
 */
void updateinfopetowner::on_back_clicked()
{
    Petowner *petown = new Petowner();
    petown->show();
    this->close();
}
