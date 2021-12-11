#include "shelterownerstats.h"
#include "ui_shelterownerstats.h"

/**
 * @brief Constructor for the class
 * @param parent
 */
shelterOwnerStats::shelterOwnerStats(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shelterOwnerStats)
{
    ui->setupUi(this);
    displayStats();
}

/**
 * @brief Destructor for the class
 */
shelterOwnerStats::~shelterOwnerStats()
{
    delete ui;
}

/**
 * @brief Displays the statistics on the UI
 */
void shelterOwnerStats::displayStats(){
    DataBase db("../../cuddlySys/sysDB.db");
    ui->totalPets->setText(QString::number(db.countPetsforShelter(currUser->getUid())));
    ui->totalPending->setText(QString::number(db.countAdoptionReqforShelter(currUser->getUid(),1)));
    ui->totalAdopted->setText(QString::number(db.countAdoptionReqforShelter(currUser->getUid(),3)));
    ui->totalRejected->setText(QString::number(db.countAdoptionReqforShelter(currUser->getUid(), 2)));
    ui->percentage->setText(QString::number(db.countAdoptionReqforShelter(currUser->getUid(),3)*100.0/db.countPetsforShelter(currUser->getUid()),'f', 2)+"%");
}
