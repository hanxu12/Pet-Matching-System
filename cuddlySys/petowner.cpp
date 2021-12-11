/**
* petowner.cpp
* The source file for pet owner dashboard.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "petowner.h"
#include "ui_petowner.h"

/**
 * @brief Petowner constructor
 * @param parent
 */
Petowner::Petowner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Petowner)
{
    ui->setupUi(this);
    //set up color
    //    QPalette pal = this->palette();

    //    // set black background
    //    pal.setColor(QPalette::Background, Qt::black);
    //    setAutoFillBackground(true);
    //    setPalette(pal);

    ui->name->setText(currUser->getName());
    ui->bio->setText("User Bio: " + currUser->getBio());
    ui->state->setText("Address: \n"+ currUser->getUserAddress() + ", " + currUser->getLocation() + ", " + QString::number(currUser->getUserZipCode()));
    ui->gender->setText("Gender: "+ currUser->getGender());
    ui->contact->setText("Phone: "+ currUser->getPhoneNo());
}

/**
 * @brief Petowner deconstructor
 */
Petowner::~Petowner()
{
    delete ui;
}

/**
 * @brief Logout
 */
void Petowner::on_po_logout_clicked()
{
    entry *newentry = new entry();
    newentry->show();
    this->close();
}

/**
 * @brief Open update info window
 */
void Petowner::on_update_info_clicked()
{
    updateinfopetowner *updatepetowner = new updateinfopetowner();
    updatepetowner->show();
    this->close();
}

/**
 * @brief Open search window
 */
void Petowner::on_find_matches_clicked()
{
    searchWin *searchWindow = new searchWin();
    searchWindow->show();
    this->close();
}

/**
 * @brief Open history window
 */
void Petowner::on_history_clicked()
{
    history *his = new history();
    his->show();
    this->close();
}

/**
 * @brief Open adoptions window
 */
void Petowner::on_adoptions_clicked()
{
        adoptions *adpt = new adoptions();
        adpt->show();
        this->close();

}
