#ifndef UPDATEPET_H
#define UPDATEPET_H
#include "managepet.h"
#include "database.h"
#include "header.h"
#include "petmanager.h"
#include <QWidget>
#include <QFile>

namespace Ui {
class updatePet;
}

class updatePet : public QWidget
{
    Q_OBJECT

public:
    explicit updatePet(QWidget *parent = 0);
    ~updatePet();

private slots:
    void on_back_clicked(); // handles back button functionality
    void on_PB_createAcc_clicked(); // updates profile information of the pet

private:
    Ui::updatePet *ui;
};

#endif // UPDATEPET_H
