/**
* adminadduser.h
* The header file for the admin group to add users.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef ADMINADDUSER_H
#define ADMINADDUSER_H
#include "database.h"
#include "header.h"
#include "manageusers.h"
#include "usermanager.h"
#include <QWidget>

namespace Ui {
/**
 * @brief adminAddUser class.
 * It adds a single user to the system.
 * The admin user uses this class.
 */        
class adminAddUser;
}

class adminAddUser : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief A default constructor.
     * It construct a new adminAddUser object.
     */
    explicit adminAddUser(QWidget *parent = 0);
    /**
     * @brief A destructor.
     * It destructs an adminAddUser object.
     */        
    ~adminAddUser();

private slots:
    /**
     * @brief A function
     * It adds a single user to the system when the button is clicked.
     */
    void on_PB_createAcc_clicked();
    /**
     * @brief A function
     * It detects the "potential pet owner" selection, then
     * it displays the potential pet owner preference fields
     * @param index the comboBox's index
     */
    void on_CB_AccType_currentIndexChanged(int index);
    /**
     * @brief A function
     * It returns to the previous interface once "back" button is clicked.
     */
    void on_back_clicked();

private:
    /**
     * @brief A pointer
     * It references its ui.
     */
    Ui::adminAddUser *ui;
    /**
     * @brief A function
     * It switches displays/undisplays the potential pet owner preferences fields 
     * based on the input T/F boolval.
     * @param boolval true (display) or false (hide)
     */
    void switchVisibility(bool boolval);
};

#endif // ADMINADDUSER_H
