#include "entry.h"
#include <QApplication>
#include<QDebug>
#include <QSqlDatabase>
#include "usermanager.h"
#include "petmanager.h"
#include "header.h"

double onlineDist;  //online distance calculator variable
int userID;
int viewUserID;
string enterFrom;
UserManager *currUser = new UserManager;
PetManager *currPet = new PetManager;
std::priority_queue<petStruct> pq;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    entry w;
    w.show();

    return a.exec();
    //QObject::connect(login,&entry::succeed_login_S,&login->s,&Petowner::getAndShow);
}
