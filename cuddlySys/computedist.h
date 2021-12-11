#ifndef COMPUTEDIST_H
#define COMPUTEDIST_H
#include <math.h>
#include <cmath>
#include "header.h"
#include "database.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#define earthRadius 6371.0

/**
 * @brief The computeDist class
 *  class to compute the distance between a petowner and the shelter owner which he views a pet form
 */
class computeDist
{
public:
    /**
     * @brief initilization of all methods of the class
     */
    computeDist();
    ~computeDist();
    double formula(double originLat, double originLon, double destLat, double destLon);
    double distCal(int pid, int sid);
    double deg2rad(double deg);
    void onlineDist(QString origin, QString dest);
    void onResult(QNetworkReply *reply);
private:
    /**
     * @brief initilization of all the pointers
     */
    QNetworkAccessManager *manager;
    QNetworkRequest request;
    QString dist;
};

#endif // COMPUTEDIST_H
