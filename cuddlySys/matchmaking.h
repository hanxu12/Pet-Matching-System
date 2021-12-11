/**
* matchmaking.h
* The header file for matchmaking.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef MATCHMAKING_H
#define MATCHMAKING_H
#include "searchwin.h"
#include <QWidget>
#include <QApplication>
#include <QMessageBox>
#include "header.h"
#include <iostream>
#include "database.h"
#include "managepet.h"
#include "computedist.h"
#include <QObject>
#include <QBitArray>

namespace Ui {
class matchmaking;
}

class matchmaking : public QWidget
{
    Q_OBJECT

public:
    explicit matchmaking(QWidget *parent = 0);
    ~matchmaking();

private slots:
    void on_back_clicked(); //Go to previous interface
    void on_PB_switchImg_clicked(); //Switch provided pet image (show next picture of pet)
    void on_neutral_clicked();  //Log pet as neutraled and show next pet
    void on_like_clicked(); //Log pet as liked and show next pet
    void on_dislike_clicked();  //Log pet as disliked and show next pet
    void on_request_clicked();  //Request to adopt and show next pet

private:
    Ui::matchmaking *ui;
    void refreshPet();  //After user decision, display new pet
    void disableMatchMaking();  //Stop showing pets (reach end of catalog)
    int imgID;
    PetManager* mmPet;
};

#endif // MATCHMAKING_H
