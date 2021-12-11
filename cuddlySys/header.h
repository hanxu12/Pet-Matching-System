/**
* header.h
* The header file for matchmaking algorithm.
*
* @author  Team2_1
* @version 2.0
* @since   2021-5-15
*/

#ifndef HEADER_H
#define HEADER_H
#include "usermanager.h"
#include "petmanager.h"
#include <iostream>
#include <string>
#include <queue>

struct petStruct;
class UserManager;
class PetManager;

extern double onlineDist;
extern int userID;
extern int viewUserID;
extern string enterFrom;
extern UserManager *currUser;
extern PetManager *currPet;
extern std::priority_queue<petStruct> pq;

struct petStruct
{
    int petid, petScore;
    bool operator<(const petStruct &o) const
    {
        return petScore < o.petScore;
    }
};

//struct petCompare{
//    bool operator()(const petStruct & p1, const petStruct & p2)
//    {
//        return p1.petScore < p2.petScore;
//    }
//};

#endif // HEADER_H
