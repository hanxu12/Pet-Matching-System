/**
* addpet.cpp
* The source file for adding the pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "addpet.h"
#include "ui_addpet.h"

/**
 * @brief A default constructor.
 * It construct a new addPet object.
 */
addPet::addPet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addPet)
{
    ui->setupUi(this);
    ui->LE_petname->setPlaceholderText("Pet's Name");
    ui->LE_breed->setPlaceholderText("Pet's breed");
    ui->LE_age->setPlaceholderText("Pet's age");
    ui->LE_color->setPlaceholderText("Pet's color");
    ui->LE_sid->setPlaceholderText("Belongs to which shelter(shelterID)");
    ui->LE_description->setPlaceholderText("Pet's description");
    ui->LE_weight->setPlaceholderText("Pet's weight");
    ui->LE_gender->setPlaceholderText("Pet's gender");
    ui->LE_imgpath1->setPlaceholderText("Pet's image1 path");
    ui->LE_imgpath2->setPlaceholderText("Pet's image2 path");
    if (currUser->getUid()== 1) { //if admin user
        ui->LE_sid->setVisible(true);
    } else {    //if shelter owner, no need to fill sid
        ui->LE_sid->setVisible(false);
    }
}
    
/**
 * @brief A destructor.
 * It destructs an addPet object.
 */  
addPet::~addPet()
{
    delete ui;
}

/**
 * @brief A function
 * It adds a single pet to the system when the button is clicked.
 */
void addPet::on_PB_createAcc_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    PetManager *tmpPet = new PetManager;
    QString oldimgPath1 = ui->LE_imgpath1->text();
    QString oldimgPath2 = ui->LE_imgpath2->text();
    tmpPet->setPetID(db.getMaxPetID()+1);
    tmpPet->setPetName(ui->LE_petname->text());
    tmpPet->setPetSpecies(ui->species->currentText());
    tmpPet->setPetBreed(ui->LE_breed->text());
    tmpPet->setPetColor(ui->LE_color->text());
    tmpPet->setPetAge(ui->LE_age->text().toInt());
    tmpPet->setPetWeight(ui->LE_weight->text().toInt());
    tmpPet->setPetDescription(ui->LE_description->text());
    tmpPet->setPetGender(ui->LE_gender->text());
    if (currUser->getUid()== 1) { //if admin user
        tmpPet->setPetShelterID(ui->LE_sid->text().toInt());
    } else {
        tmpPet->setPetShelterID(currUser->getUid());
    }
    QString newImgPath1= "petImg/"+ QString::number(db.getMaxPetID()+1) + "_1.jpg";
    QString newImgPath2 = "petImg/" + QString::number(db.getMaxPetID()+1) + "_2.jpg";
    if (QFile::exists(newImgPath1))
    {
        QFile::remove(newImgPath1);
    }
    if (QFile::exists(newImgPath2))
    {
        QFile::remove(newImgPath2);
    }
    QFile::copy(oldimgPath1, newImgPath1);
    QFile::copy(oldimgPath2, newImgPath2);
    tmpPet->setPetImgPath1(newImgPath1);
    tmpPet->setPetImgPath2(newImgPath2);
    if (ui->isRescued->checkState()) {
        tmpPet->setPetRescue(1);
    } else {
        tmpPet->setPetRescue(0);
    }
    if (ui->isDiseased->checkState()) {
        tmpPet->setPetDisease(1);
    } else {
        tmpPet->setPetDisease(0);
    }
    db.addPet(tmpPet);
    delete tmpPet;
    ManagePet *mp = new ManagePet;
    mp->show();
    this->close();
}

/**
 * @brief A pointer
 * It references the ui.
 */
void addPet::on_back_clicked()
{
    ManagePet *mp = new ManagePet;
    mp->show();
    this->close();
}
