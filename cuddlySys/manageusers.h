/**
* manageuser.h
* The header file for managing users.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H
#include <QSqlTableModel>
#include <QWidget>
#include <QFileDialog>
#include <QMessageBox>
#include "entry.h"
#include "database.h"
#include <QFile>
#include <QWidget>
#include <QSqlTableModel>
#include "shelterownermain.h"
#include "petmanager.h"
#include <QString>
#include "managepet.h"
#include "viewuserprofile.h"
#include "header.h"
#include "adminadduser.h"
#include "adminupdatepetowner.h"
#include "adminupdateshelter.h"

namespace Ui {
class ManageUsers;
}

class ManageUsers : public QWidget
{
    Q_OBJECT

public:
    explicit ManageUsers(QWidget *parent = 0);
    ~ManageUsers();
    void displayCurrPage(); //Show users on the page with corresponding information

private slots:
    void on_pushButton_2_clicked(); //Logout
    void on_pushButton_1_clicked(); //Switch to pet management interface
    void on_addBulk_clicked();  //Import entries from selected csv file

    void on_prev_clicked(); //Go to previous page of pets on user management interface

    void on_next_clicked(); //Go to next page of pets on user management interface

    void on_viewSelect_clicked();   //View selected user information
    void on_removeSelect_clicked(); //Remove selected user from system

    void on_addSingle_clicked();    //Add single user to system

    void on_updateSelect_clicked(); //Update information of selected user

private:
    Ui::ManageUsers *ui;
    void initUserVector();  //Initiate user management list interface
    std::vector <int> userVector;

    int totalPage;
    int currPage;
    int currPtr;
    QString displayUserType(int uid);   //Display user group (shelter, potential owner, foster)
};

#endif // MANAGEUSERS_H
