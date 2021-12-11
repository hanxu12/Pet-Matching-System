#ifndef VIEWREQUESTS_H
#define VIEWREQUESTS_H
#include "shelterownermain.h"
#include <vector>
#include "petmanager.h"
#include <QWidget>
#include "database.h"
#include "header.h"
#include "viewpetreq.h"
#include "viewuserprofile.h"

namespace Ui {
class viewrequests;
}

class viewrequests : public QWidget
{
    Q_OBJECT

public:
    explicit viewrequests(QWidget *parent = 0);
    ~viewrequests();

private slots:
    void on_back_clicked(); // handles back button
    void on_prev_clicked(); // handles prev page button
    void on_next_clicked(); // handles next page button

    void on_viewpet_clicked(); // handles request to view pet
    void on_viewprofile_clicked(); // handles request to view requestee

    void on_accept_clicked(); // handles acception of request
    void on_reject_clicked(); // handles rejectionof request
    void on_pending_clicked();// hanldes delaying/pending of request

private:
    Ui::viewrequests *ui;
    void initReqVector(); // method to initialize vector to store requests
    std::vector <int> reqVector; // vector to store requests
    void displayCurrReq(int pgno); // displays the request at the start of the vector
    int totalPgs; // number of requests
    int currPg;
};

#endif // VIEWREQUESTS_H
