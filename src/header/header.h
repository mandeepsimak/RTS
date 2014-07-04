/**
 *       \file       header.h
 *
 *       \brief      Base header file
 *
 *       \compiler   g++\n
 *
 *       \author     Mandeep Kaur, simakmandeep@gmail.com
 *       \license    GNU General Public License Version 2\n
 *       \copyright  Copyright (c) 2014, GreatDevelopers\n
 *                   https://github.com/GreatDevelopers
 */


#ifndef  HEADER_H
#define  HEADER_H

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/*
 *  Typedef variables for using vector definiton
 */

//typedef vector<string> STRING_VEC;
typedef vector<vector<string> > STRING_2DVEC;
//typedef vector<vector<vector<string> > > STRING_3DVEC;
//typedef vector<vector<vector<vector<string> > > > STRING_4DVEC;
typedef vector<vector<vector<float> > > FLOAT_3DVEC;
typedef vector<vector<float> > FLOAT_2DVEC;
typedef vector<float> FLOAT_VEC;

#endif   /* #ifndef HEADER_H */

/*
 * Local Variables:
 * tab-width: 4
 * expandtab
 * ex: shiftwidth=4 tabstop=4
 */ 
