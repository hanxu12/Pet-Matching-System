#include "adminupdatepetowner.h"
#include "ui_adminupdatepetowner.h"

/**
 * @brief adminUpdatePetOwner::adminUpdatePetOwner
 * default constructor which initialized all the ui elements
 * @param parent
 */
adminUpdatePetOwner::adminUpdatePetOwner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminUpdatePetOwner)
{
    ui->setupUi(this);
    ui->LE_name->setPlaceholderText("New Display Name");
    ui->LE_password->setPlaceholderText("New Password");
    ui->LE_bio->setPlaceholderText("New Bio/Description");
    ui->LE_phoneno->setPlaceholderText("New Contact Info");
    ui->LE_breed->setPlaceholderText("New Breed");
    ui->LE_address->setPlaceholderText("New Address");
    ui->LE_zipcode->setPlaceholderText("New zip code");
}

/**
 * @brief adminUpdatePetOwner::~adminUpdatePetOwner
 * default destructor
 */
adminUpdatePetOwner::~adminUpdatePetOwner()
{
    delete ui;
}

/**
 * @brief adminUpdatePetOwner::on_back_clicked
 * when the button is clickd it takes you back to the mage users page
 */
void adminUpdatePetOwner::on_back_clicked()
{
    ManageUsers *mu = new ManageUsers;
    mu->show();
    this->close();
}

/**
 * @brief adminUpdatePetOwner::on_PB_update_clicked
 * when the button is clicked it reds all the new updates in the ui elements and updates them accordingly for the user
 */
void adminUpdatePetOwner::on_PB_update_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    int rescuePref, diseasePref;
    UserManager *tmpUser = new UserManager;
    //obtain info
    tmpUser->setUid(viewUserID);
    tmpUser->setUserType(db.getGroupType(viewUserID));
    tmpUser->setUsername(db.getUserName(viewUserID));
    tmpUser->setName(ui->LE_name->text());
    tmpUser->setBio(ui->LE_bio->text());
    tmpUser->setPassword(ui->LE_password->text());
    tmpUser->setPhoneNo(ui->LE_phoneno->text());
    tmpUser->setUserAddress(ui->LE_address->text());
    tmpUser->setLocation(ui->CB_State->currentText());
    tmpUser->setUserZipCode(ui->LE_zipcode->text().toInt());
    tmpUser->setGender(ui->CB_Gender->currentText());

    tmpUser->setUserLocPref(ui->radius->currentText());
    tmpUser->setUserColorPref(ui->color->currentText());
    tmpUser->setUserspeciesPref(ui->species->currentText());
    tmpUser->setUserAgePref(ui->age->currentText());
    tmpUser->setUserBreedPref(ui->LE_breed->text());
    tmpUser->setUserWeightPref(ui->weight->currentText());
    if (ui->isRescued->checkState()) {
        rescuePref = 1;
    } else {
        rescuePref = 0;
    }
    if (ui->isDiseased->checkState()) {
        diseasePref = 1;
    } else {
        diseasePref = 0;
    }
    tmpUser->setUserRescuePref(rescuePref);
    tmpUser->setUserDiseasePref(diseasePref);
    db.updateUser(tmpUser);

    ManageUsers *mu = new ManageUsers;
    mu->show();
    this->close();
}

