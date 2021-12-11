/**
* managepet.cpp
* The source file for managing pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#include "managepet.h"
#include "ui_managepet.h"

/**
 * @brief ManagePet constructor
 */
ManagePet::ManagePet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManagePet)
{
    ui->setupUi(this);
    //if admin
    if (currUser->getUid() == 1) {
        ui->pushButton1->setText("Switch to Users");
    }
    currPtr= 0;
    currPage = 1;
    initPetVector();
    if (petVector.size() == 0) {
        totalPage = 1;
    } else {
        totalPage = ceil((petVector.size())/3.0);
    }
    displayCurrPage();
    ui->image1->setScaledContents(true);
    ui->image2->setScaledContents(true);
    ui->image3->setScaledContents(true);
}

/**
 * @brief ManagePet deconstructor
 */
ManagePet::~ManagePet()
{
    delete ui;
}

/**
 * @brief Import entries from selected csv file.
 * Add pet to database and log name, species, breed, gender, age, sid,
 * weight, description, color, rescue status, disease status, and respective image paths
 */
void ManagePet::on_addBulk_clicked()
{
    QString filter = "CSV File (*.csv) ;; All File (*.*)";
    QString file_name = QFileDialog::getOpenFileName(this, "open a file", "..", filter);
    QFile f(file_name);
    DataBase db("../../cuddlySys/sysDB.db");
    if (!f.open(QIODevice::ReadOnly)){
        QMessageBox::warning(this, "title", "file not open");
    } else{
        //QTextStream in(&file);
        //QString text = in.readAll();
        QTextStream ts (&f);
        if (!QDir("petImg").exists()){
            QDir().mkdir("petImg");
        }
        //Travel through the csv file "excel.csv"
        while(!ts.atEnd()){
            QByteArray line = f.readLine();
            QString tmpStr = QString(line);
            QStringList tmpList = tmpStr.split(QLatin1Char(','));
            //wordList.append(line.split(',').first());
            qDebug() << tmpList.size();
            QString name = QString::fromUtf8(tmpList.at(0).toUtf8());
            QString species = QString::fromUtf8(tmpList.at(1).toUtf8());
            QString breed = QString::fromUtf8(tmpList.at(2).toUtf8());
            QString gender = QString::fromUtf8(tmpList.at(3).toUtf8());
            int age = tmpList.at(4).toInt();
            int sid = tmpList.at(5).toInt();
            int weight = tmpList.at(6).toInt();
            QString description = QString::fromUtf8(tmpList.at(7).toUtf8());
            QString color = QString::fromUtf8(tmpList.at(8).toUtf8());
            int rescue = tmpList.at(9).toInt();
            int disease = tmpList.at(10).toInt();
            QString previmgPath1 = QString::fromUtf8(tmpList.at(11).toUtf8());
            QString previmgPath2 = QString::fromUtf8(tmpList.at(12).trimmed().toUtf8());
            QString newImgPath1= "petImg/"+ QString::number(db.getMaxPetID()+1) + "_1.jpg";
            QString newImgPath2 = "petImg/" + QString::number(db.getMaxPetID()+1) + "_2.jpg";
            PetManager *tmpPet = new PetManager;
            tmpPet->setPetName(name);
            tmpPet->setPetSpecies(species);
            tmpPet->setPetBreed(breed);
            tmpPet->setPetGender(gender);
            tmpPet->setPetAge(age);
            tmpPet->setPetWeight(weight);
            if (currUser->getUid() == 1) { //if admin, set pet belonging according to the dataset
                tmpPet->setPetShelterID(sid);
            } else { //if shelter user, set pet belonging according to his assigned shelterID(sid)
                tmpPet->setPetShelterID(currUser->getUid());
            }
            tmpPet->setPetDescription(description);
            tmpPet->setPetColor(color);
            tmpPet->setPetRescue(rescue);
            tmpPet->setPetDisease(disease);
            tmpPet->setPetImgPath1(newImgPath1);
            tmpPet->setPetImgPath2(newImgPath2);
            if (QFile::exists(newImgPath1))
            {
                QFile::remove(newImgPath1);
            }
            if (QFile::exists(newImgPath2))
            {
                QFile::remove(newImgPath2);
            }
            QFile::copy(previmgPath1, newImgPath1);
            QFile::copy(previmgPath2, newImgPath2);
            db.addPet(tmpPet);
        }
        f.close ();
        this->close();
        ManagePet *mp = new ManagePet;
        mp->show();
    }
}

/**
 * @brief Close pet management page and switch to user management
 */
void ManagePet::on_pushButton1_clicked()
{
    if (currUser->getUid()==1){
        ManageUsers *mu = new ManageUsers;
        mu->show();
        this->close();
    }

    else {
        ShelterOwnerMain *newso = new ShelterOwnerMain();
        newso -> show();
        this -> close();
    }
}

/**
 * @brief Logout
 */
void ManagePet::on_pushButton2_clicked()
{
    entry *newentry = new entry();
    newentry -> show();
    this->close();
}

/**
 * @brief Initiate pet management list interface
 */
void ManagePet::initPetVector(){
    DataBase db("../../cuddlySys/sysDB.db");
    int max = db.getMaxPetID();
    int currUid = currUser->getUid();
    if (currUid == 1) { //if admin user, add all pets
        for (int i = 1; i <= max; i++) {
            if (db.petExists(i)) {
                petVector.push_back(i);
            }
        }
    } else { //other user add other pets
        for (int i= 1; i <= max; i++) {
            if (db.petExists(i) && db.getPetSid(i) == currUid){
                petVector.push_back(i);
            }
        }
    }
    while ((petVector.size() == 0) || !(petVector.size() % 3 == 0)){
        petVector.push_back(-1);
    }
    qDebug() << "petVector size is " << petVector.size();
}

/**
 * @brief Show pets on the page with corresponding information.
 * Displays three pets per page.
 */
void ManagePet::displayCurrPage(){
    ui->checkBox1->setChecked(false);
    ui->checkBox2->setChecked(false);
    ui->checkBox3->setChecked(false);
    DataBase db("../../cuddlySys/sysDB.db");
    QPixmap invalidPet("../../cuddlySys/paw.jpg");
    //idx starts from 0, so includes all pets
    int idx = currPtr;
    if (petVector.at(idx)== -1){
        ui->checkBox1->setVisible(false);
        ui->name1->setText("N/A");
        ui->breed1->setText("N/A");
        ui->species1->setText("N/A");
        ui->image1->setPixmap(invalidPet);
    }
    else {
        ui->checkBox1->setVisible(true);
        int petid = petVector.at(idx);
        ui->image1->setPixmap(db.getPetImg1(petid));
        ui->name1->setText(db.getPetName(petid));
        ui->species1->setText(db.getPetSpecies(petid));
        ui->breed1->setText(db.getPetBreed(petid));
    }
    idx += 1;
    if (petVector.at(idx)== -1){
        ui->checkBox2->setVisible(false);
        ui->name2->setText("N/A");
        ui->breed2->setText("N/A");
        ui->species2->setText("N/A");
        ui->image2->setPixmap(invalidPet);
    }
    else {
        ui->checkBox2->setVisible(true);
        int petid = petVector.at(idx);
        ui->image2->setPixmap(db.getPetImg1(petid));
        ui->name2->setText(db.getPetName(petid));
        ui->species2->setText(db.getPetSpecies(petid));
        ui->breed2->setText(db.getPetBreed(petid));
    }
    idx += 1;
    if (petVector.at(idx)== -1){
        ui->checkBox3->setVisible(false);
        ui->name3->setText("N/A");
        ui->breed3->setText("N/A");
        ui->species3->setText("N/A");
        ui->image3->setPixmap(invalidPet);
    }
    else {
        ui->checkBox3->setVisible(true);
        int petid = petVector.at(idx);
        ui->image3->setPixmap(db.getPetImg1(petid));

        ui->name3->setText(db.getPetName(petid));
        ui->species3->setText(db.getPetSpecies(petid));
        ui->breed3->setText(db.getPetBreed(petid));
    }
    ui->page->setText("Page " + QString::number(currPage) + " of " + QString::number(totalPage));
}

/**
 * @brief Go to previous page of pets on pet management interface
 */
void ManagePet::on_prev_clicked()
{
    if (currPage > 1) {
        currPage -= 1;
        currPtr = currPtr - 3;
        displayCurrPage();
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the first page!"));
    }
}

/**
 * @brief Go to next page of pets on pet management interface
 */
void ManagePet::on_next_clicked()
{
    if (currPage < totalPage) {
        currPage += 1;
        currPtr = currPtr + 3;
        displayCurrPage();
    } else {
        QMessageBox::information(this, tr("Page Number Warning"),
                                 tr("This is the last page!"));
    }
}

/**
 * @brief Remove selected pet from catalog
 */
void ManagePet::on_removeSelect_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm", "Confirm to delete pet?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {

        if (ui->checkBox1->checkState()) {
            db.deletePet(petVector.at(currPtr));
            petVector.at(currPtr) = -1;
        }
        if (ui->checkBox2->checkState()) {
            db.deletePet(petVector.at(currPtr+1));
            petVector.at(currPtr+1) = -1;
        }
        if (ui->checkBox3->checkState()) {
            db.deletePet(petVector.at(currPtr+2));
            petVector.at(currPtr+2) = -1;
        }
        displayCurrPage();

    }
}

/**
 * @brief View information of selected pet
 */
void ManagePet::on_viewSelect_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    if ((ui->checkBox1->checkState() && ui->checkBox2->checkState()) || (ui->checkBox1->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (!ui->checkBox1->checkState() && !ui->checkBox2->checkState() && !ui->checkBox3->checkState())){
        QMessageBox::information(this, tr("Checkbox Warning"),
                                 tr("You need to check a single checkbox to view the pet profile!"));
    } else{
        if (ui->checkBox1->checkState()) {
            currPet = db.setPet(petVector.at(currPtr));
        }
        else if (ui->checkBox2->checkState()) {
            currPet = db.setPet(petVector.at(currPtr+1));
        }
        else if (ui->checkBox3->checkState()) {
            currPet = db.setPet(petVector.at(currPtr+2));
        }
        enterFrom = "admin";
        petprofile *petprof = new petprofile;
        petprof->show();
    }
}

/**
 * @brief Add a single pet to the catalog
 */
void ManagePet::on_addSingle_clicked()
{
    addPet *addP = new addPet;
    addP->show();
    this->close();
}

/**
 * @brief Update information of selected pet
 */
void ManagePet::on_updateSelect_clicked()
{
    DataBase db("../../cuddlySys/sysDB.db");
    if ((ui->checkBox1->checkState() && ui->checkBox2->checkState()) || (ui->checkBox1->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (ui->checkBox1->checkState() && ui->checkBox2->checkState() && ui->checkBox3->checkState())
            || (!ui->checkBox1->checkState() && !ui->checkBox2->checkState() && !ui->checkBox3->checkState())){
        QMessageBox::information(this, tr("Checkbox Warning"),
                                 tr("You need to check a single checkbox to update a pet!"));
    } else{
        if (ui->checkBox1->checkState()) {
            currPet = db.setPet(petVector.at(currPtr));
        }
        else if (ui->checkBox2->checkState()) {
            currPet = db.setPet(petVector.at(currPtr+1));
        }
        else if (ui->checkBox3->checkState()) {
            currPet = db.setPet(petVector.at(currPtr+2));
        }
        updatePet *updateP = new updatePet;
        updateP->show();
        this->close();
    }
}


