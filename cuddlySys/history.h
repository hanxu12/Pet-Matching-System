/**
* history.h
* The header file for pet view history.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef HISTORY_H
#define HISTORY_H
#include "petowner.h"
#include "petmanager.h"
#include <QMessageBox>
#include <QWidget>
#include <vector>
#include <cmath>
#include "petprofile.h"
#include "header.h"

namespace Ui {
class history;
}

class history : public QWidget
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = 0);
    ~history();

private slots:
    void on_back_clicked(); //Close current interface and go to pet owner interface

    void on_prev_clicked(); //Previous page on pet view history interface

    void on_next_clicked(); //Next page on pet view history interface

    void on_viewprofile_1_clicked();    //Show pet info of first pet on current page

    void on_viewprofile_2_clicked();    //Show pet info of second pet on current page

    void on_viewprofile_3_clicked();    //Show pet info of third pet on current page

private:
    Ui::history *ui;
    std::vector<PetManager *> petHistory;
    void initHistoryVector();   //Initiate pet view history interface
    void displayCurrPage(); //Display user pet view history
    int totalPages;
    int currPage;
    int currPtr;
};

#endif // HISTORY_H
