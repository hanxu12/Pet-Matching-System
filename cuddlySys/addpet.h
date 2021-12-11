/**
* addpet.h
* The header file for adding the pets.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef ADDPET_H
#define ADDPET_H
#include "header.h"
#include "petmanager.h"
#include "database.h"
#include "managepet.h"
#include <QWidget>

namespace Ui {
/**
 * @brief AddPet class.
 * It adds a single pet to the system.
 * The admin user and shelter owner/potential pet owner uses this class.
 */    
class addPet;
}

class addPet : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief A default constructor.
     * It construct a new addPet object.
     */
    explicit addPet(QWidget *parent = 0);
    /**
     * @brief A destructor.
     * It destructs an addPet object.
     */    
    ~addPet();

private slots:
    /**
     * @brief A function
     * It adds a single pet to the system when the button is clicked.
     */
    void on_PB_createAcc_clicked();
    /**
     * @brief A function
     * It returns to the previous page when the "back" button is clicked.
     */
    void on_back_clicked();

private:
    /**
     * @brief A pointer
     * It references its ui.
     */
    Ui::addPet *ui;
};

#endif // ADDPET_H
