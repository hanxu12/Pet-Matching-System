#include "updatepet.h"
#include "ui_updatepet.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
updatePet::updatePet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::updatePet)
{
    ui->setupUi(this);

    // sets placeholder text for the boxes
    ui->LE_petname->setPlaceholderText("Pet Name");
    ui->LE_breed->setPlaceholderText("Pet Breed");
    ui->LE_age->setPlaceholderText("Pet Age");
    ui->LE_color->setPlaceholderText("Pet Color");
    ui->LE_sid->setPlaceholderText("Update shelter(shelterID)");
    ui->LE_description->setPlaceholderText("Pet Description");
    ui->LE_weight->setPlaceholderText("Pet Weight");
    ui->LE_gender->setPlaceholderText("Pet Gender");
    ui->LE_imgpath1->setPlaceholderText("Image 1 path");
    ui->LE_imgpath2->setPlaceholderText("Image 2 path");

    if (currUser->getUid()== 1) { //if admin user
        ui->LE_sid->setVisible(true);
    } else {    //if shelter owner, no need to fill sid
        ui->LE_sid->setVisible(false);
    }
}

/**
 * @brief Destructor for the class
 */
updatePet::~updatePet()
{
    delete ui;
}

/**
 * @brief Handles back button functionality
 */
void updatePet::on_back_clicked()
{
    ManagePet *mp = new ManagePet;
    mp->show();
    this->close();
}

/**
 * @brief Displays the updated information
 */
void updatePet::on_PB_createAcc_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");

    //petid already inside currPet
    currPet->setPetName(ui->LE_petname->text());
    currPet->setPetSpecies(ui->species->currentText());
    currPet->setPetBreed(ui->LE_breed->text());
    currPet->setPetColor(ui->LE_color->text());
    currPet->setPetAge(ui->LE_age->text().toInt());
    currPet->setPetWeight(ui->LE_weight->text().toInt());
    currPet->setPetDescription(ui->LE_description->text());
    currPet->setPetGender(ui->LE_gender->text());

    if (currUser->getUid()== 1) { //if admin user
        currPet->setPetShelterID(ui->LE_sid->text().toInt());
    }

    //overwrite images
    if (QFile::exists(currPet->getPetImgPath1()))
    {
        QFile::remove(currPet->getPetImgPath1());
    }

    if (QFile::exists(currPet->getPetImgPath2()))
    {
        QFile::remove(currPet->getPetImgPath2());
    }

    QFile::copy(ui->LE_imgpath1->text(), currPet->getPetImgPath1());
    QFile::copy(ui->LE_imgpath2->text(), currPet->getPetImgPath2());

    if (ui->isRescued->checkState()) {
        currPet->setPetRescue(1);
    } else {
        currPet->setPetRescue(0);
    }

    if (ui->isDiseased->checkState()) {
        currPet->setPetDisease(1);
    } else {
        currPet->setPetDisease(0);
    }

    db.updatePet(currPet);
    ManagePet *mp = new ManagePet;
    mp->show();
    this->close();
}
