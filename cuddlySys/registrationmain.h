/**
* registrationmain.h
* The header file for registering a new account.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef REGISTRATIONMAIN_H
#define REGISTRATIONMAIN_H
#include "entry.h"
#include <QWidget>
#include "usermanager.h"
#include "header.h"

class UserManager;

namespace Ui {
class RegistrationMain;
}

class RegistrationMain : public QWidget
{
    Q_OBJECT

public:
    explicit RegistrationMain(QWidget *parent = 0);
    ~RegistrationMain();
    //UserManager *currUser = new UserManager;

private slots:
    void on_PB_back_clicked();  //Close registration interface when button pressed

    void on_PB_createAcc_clicked(); //Checks for existing users, all fields to be filled, then creates account

private:
    Ui::RegistrationMain *ui;
};

#endif // REGISTRATIONMAIN_H
