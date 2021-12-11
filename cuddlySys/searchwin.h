#ifndef SEARCHWIN_H
#define SEARCHWIN_H
#include "petowner.h"
#include "matchmaking.h"
#include "database.h"
#include <QWidget>
#include "computedist.h"

namespace Ui {
class searchWin;
}

class searchWin : public QWidget
{
    Q_OBJECT

public:
    explicit searchWin(QWidget *parent = 0); // constrcutor
    ~searchWin(); // destructor

private slots:
    void on_back_clicked(); // handles back button functionality

    void on_search_2_clicked(); // handles search button

    void on_lucky_clicked(); // handles I'm feeling lucky search button

private:
    Ui::searchWin *ui;
    int computePetScore(UserManager *user, PetManager *pet); // calculates the score of the pets to determine how good of a match they are
};

#endif // SEARCHWIN_H
