#ifndef VIEWPETREQ_H
#define VIEWPETREQ_H
#include "header.h"
#include <QWidget>
#include <QPixmap>

namespace Ui {
class viewPetReq;
}

class viewPetReq : public QWidget
{
    Q_OBJECT

public:
    explicit viewPetReq(QWidget *parent = 0);
    ~viewPetReq();

private slots:
    void on_PB_switchImg_clicked(); // handles the flipping of pet profile image

private:
    Ui::viewPetReq *ui;
    int imgID;
    void displayCurrPet(); // displays the pet profile info
};

#endif // VIEWPETREQ_H
