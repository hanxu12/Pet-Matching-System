#ifndef SHELTEROWNERSTATS_H
#define SHELTEROWNERSTATS_H
#include "database.h"
#include "header.h"
#include <QWidget>

namespace Ui {
class shelterOwnerStats;
}

class shelterOwnerStats : public QWidget
{
    Q_OBJECT

public:
    explicit shelterOwnerStats(QWidget *parent = 0);
    ~shelterOwnerStats();

private:
    Ui::shelterOwnerStats *ui;
    void displayStats(); // displays the stats on the screen
};

#endif // SHELTEROWNERSTATS_H
