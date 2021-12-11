#include "computedist.h"

computeDist::computeDist()
{
    manager = new QNetworkAccessManager();
//    QObject::connect(manager,&QNetworkAccessManager::finished,this,[&](QNetworkReply *reply){
//        QByteArray data = reply->readAll();
//        QString str = QString::fromLatin1(data);
//        QString dist ="-1";
//        QStringList lines = str.split("<TravelDistance>");
//        lines = lines.at(1).split("</TravelDistance>");
//        dist = lines.at(0);
//        reply->deleteLater();
//    });
//    QObject::connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply) {
//        QByteArray data = reply->readAll();
//        qDebug() << data;
//        QString str = QString::fromLatin1(data);
//        dist = "-1";
//        QStringList lines = str.split("<TravelDistance>");
//        lines = lines.at(1).split("</TravelDistance>");
//        dist = lines.at(0);
//        reply->deleteLater();
//        }
//    );
}

/**
 * @brief computeDist::~computeDist destructor for the compute distance class
 */
computeDist::~computeDist(){
    delete manager;
}

/**
 * @brief computeDist::deg2rad
 * @param deg takes a degreee and converts it accordingly
 * @return
 */
double computeDist::deg2rad(double deg) {
    return (deg * M_PI / 180);
}


//return -1.0 meaning distance not applicable
/**
 * @brief computeDist::formula
 * @param originLat the  origin longitude
 * @param originLon the origin latitude
 * @param destLat the destinitntion latitude
 * @param destLon the destination longitude
 * @return  calculates the distance between the two points
 */
double computeDist::formula(double originLat, double originLon, double destLat, double destLon) {
    //edge case;
    if (originLat == 0 || originLon == 0 || destLat == 0 || destLon == 0) {
        return -1.0;
    }
    //double originLatRad, originLonRad, destLatRad, destLonRad, u, v;
    double originLatRad = deg2rad(originLat);
    double originLonRad = deg2rad(originLon);
    double destLatRad = deg2rad(destLat);
    double destLonRad = deg2rad(destLon);
    double u = sin((destLatRad - originLatRad)/2);
    double v = sin((destLonRad - originLonRad)/2);
    //qDebug() << "dist is " << 2.0 * earthRadius * asin(sqrt(u * u + cos(originLatRad) * cos(destLatRad) * v * v));
    return 2.0 * earthRadius * asin(sqrt(u * u + cos(originLatRad) * cos(destLatRad) * v * v));
}

//pid == potential pet owner id
//sid == shelter owner/foster parent id
/**
 * @brief computeDist::distCal
 * @param pid the pet owner id in the database
 * @param sid the shelter owner id
 * @return  the distance between the pet owner and the shelter owner
 */
double computeDist::distCal(int pid, int sid){
    DataBase db("../../cuddlySys/sysDB.db");
    int originZip = db.getZip(pid);
    int destZip = db.getZip(sid);
    qDebug() << "user at zip" << originZip << "shelter at " << destZip;
    qDebug() << "origin lat is " << db.getLat(originZip) << db.getLon(originZip);
    qDebug() << "dest is " << db.getLat(destZip) << db.getLon(destZip);
    return formula(db.getLat(originZip),db.getLon(originZip), db.getLat(destZip), db.getLon(destZip));
}

//initator (Step1:)
//void computeDist::onlineDist(QString origin, QString dest){
//    QString half1= "http://dev.virtualearth.net/REST/V1/Routes/Driving?o=xml&wp.0=";
//    QString point1 = origin+"&wp.1=";
//    QString point2 = dest+"&avoid=minimizeTolls&key=AmU-Oc0KIgfqiKa8ck2guHbOVRwkD6lxJS8v1XiBEMn3np7COrH8MfciblXycdQD";
//    QString url = half1+point1+point2;
//    request.setUrl(QUrl(url));
//    qDebug() << "url is" << url;
//QNetworkReply *reply = manager->get(request);
//    QObject::connect(manager, &QNetworkAccessManager::finished, this, &computeDist::onResult);
//    manager->get(request);
//
//    //return dist;
//}

//(Step2:)
//fetch response
//void computeDist::onResult(QNetworkReply *reply){
//    qDebug() << reply->readAll();
//}








