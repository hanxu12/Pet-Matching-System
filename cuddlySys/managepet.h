/**
* managepet.h
* The header file for managing pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef MANAGEPET_H
#define MANAGEPET_H
#include <QFile>
#include <QDir>
#include <QWidget>
#include <QSqlTableModel>
#include "shelterownermain.h"
#include "petmanager.h"
#include <QString>
#include "manageusers.h"
#include "header.h"
#include "petprofile.h"
#include "addpet.h"
#include "updatepet.h"

namespace Ui {
class ManagePet;
}

class ManagePet : public QWidget
{
    Q_OBJECT

public:
    explicit ManagePet(QWidget *parent = 0);
    ~ManagePet();

private slots:
    void on_addBulk_clicked();  //Import entries from selected csv file

    void on_pushButton1_clicked();  //Close pet management page and switch to user management

    void on_pushButton2_clicked();  //Logout

    void on_prev_clicked(); //Go to previous page of pets on pet management interface

    void on_next_clicked(); //Go to next page of pets on pet management interface

    void on_removeSelect_clicked(); //Remove selected pet from catalog

    void on_viewSelect_clicked();   //View information of selected pet

    void on_addSingle_clicked();    //Add a single pet to the catalog

    void on_updateSelect_clicked(); //Update information of selected pet

private:
    Ui::ManagePet *ui;
    void initPetVector();   //Initiate pet management list interface
    std::vector <int> petVector;
    void displayCurrPage(); //Show pets on the page with corresponding information
    int totalPage;
    int currPage;
    int currPtr;
};

#endif // MANAGEPET_H
