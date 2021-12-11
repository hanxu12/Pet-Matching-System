/**
* petownerprefernces.cpp
* The source file for updating prefernces.
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "petownerpref.h"
#include "ui_petownerpref.h"
#include<database.h>

/**
 * @brief PetownerPref constructor
 * @param parent
 */
PetownerPref::PetownerPref(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetownerPref)
{
    ui->setupUi(this);
    ui->Breed->setPlaceholderText("Prefered Pet Breed:");
    //    ui->radius->lineEdit()->setPlaceholderText("Location:");
    //    ui->species->lineEdit()->setPlaceholderText("Species:");
    //    ui->color->lineEdit()->setPlaceholderText("Color:");
    //    ui->age->lineEdit()->setPlaceholderText("Age:");
    //    ui->weight->lineEdit()->setPlaceholderText("Weight:");
    //    ui->s_features->lineEdit()->setPlaceholderText("Special Features:");
}

/**
 * @brief PetownerPref decosntructor
 */
PetownerPref::~PetownerPref()
{
    delete ui;
}

/**
 * @brief Open preference update window and store prefernces
 */
void PetownerPref::on_PB_update_clicked()
{  
    int rescuePref, diseasePref;
    DataBase db("../../cuddlySys/sysDB.db");
    //getting the preference information
    currUser->setUserLocPref(ui->radius->currentText());
    currUser->setUserAgePref(ui->age->currentText());
    currUser->setUserspeciesPref(ui->species->currentText());
    currUser->setUserBreedPref(ui->Breed->text());
    currUser->setUserColorPref(ui->color->currentText());
    currUser->setUserWeightPref(ui->weight->currentText());
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
    currUser->setUserRescuePref(rescuePref);
    currUser->setUserDiseasePref(diseasePref);

    db.insertPerf(currUser);
    this->close();
    Petowner *po = new Petowner();
    po -> show();
}

