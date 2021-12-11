/**
* entry.h
* The header file for loging in.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef ENTRY_H
#define ENTRY_H

#include <QWidget>
#include "string"
#include "iostream"
#include<QSqlQuery>
#include <QSqlDatabase>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include "manageusers.h"
#include "petowner.h"
#include "shelterownermain.h"
#include "registrationmain.h"
#include "header.h"
#include "database.h"

namespace Ui {
class entry;
}

class entry : public QWidget
{
    Q_OBJECT

public:
    explicit entry(QWidget *parent = 0);
    ~entry();

private slots:
    void on_loginButton_clicked();  //Takes entrered username/password and checks for validity.

    void on_ExitButton_clicked();   //Close program if the exit button is clicked

    void on_PB_register_clicked();  //If user clicks register button, show registration interface

private:
    Ui::entry *ui;
    QString inputUsername;
    //QSqlDatabase mydb;
    //Admin *adm;
    //Petowner *petowner;
};

#endif // ENTRY_H
