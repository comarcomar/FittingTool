// MM
// Modificata estensione del file da .cpp a .hpp
#pragma once

#ifndef _UTILS_
#define _UTILS_


#include "mystuff.h"
#include "data.h"
#include "circle.h"
 


/*
    Generator of pseudo-random numbers
    with standard normal distribution
    based on Box-Muller transformation
    
    "reals" can be replaced by "float", 
    "double", or "long double"; or it 
    can be predefined as one of these types
    
    Input:  none
    Output:  two real values, x and y,
    that are random, independent, and 
    have standard normal distribution 
    (with mean 0 and variance 1)
    
    Call:
    
        RandomNormalPair(x,y);
        
    Uses standard C++ random generator rand()
    
    To reseed the generator rand(), call  
    
        srand ( (unsigned)time(NULL) );
    
    before you start calling this function
    
       Nikolai Chernov, November 2011
*/
void RandomNormalPair(reals& x, reals& y);

//*********************** SimulateArc ******************************

/*
Simulate data points equally spaced along a circular arc with Gaussian noise

input:
a,b         the coordinates of the center of the circle
R           the radius of circle
theta1      first  endpoint of the arc (in radians)
theta2      second endpoint of the arc (in radians)
sigma       noise level (standard deviation of residuals)
*/
void SimulateArc(Data& data, reals a, reals b, reals R, reals theta1, reals theta2, reals sigma);


//********************* SimulateRandom ****************************
/*
Simulate data points with uniform distribution
in the square |x|<Window, |y|<Window

input:
nPoints  the number of data points
*/

void SimulateRandom(Data& data, reals Window);

//****************** Sigma ************************************
//
//   estimate of Sigma = square root of RSS divided by N
//   gives the root-mean-square error of the geometric circle fit

reals Sigma(Data& data, Circle& circle);

//****************** SigmaReduced ************************************
//
//   estimate of Sigma = square root of RSS divided by N
//   gives the root-mean-square error of the geometric circle fit
//
//   uses only the center of the circle (a,b), not the radius
//   the function computes the optimal radius here

reals SigmaReduced(Data& data, Circle& circle);

//****************** SigmaReducedNearLinearCase ****************
//
//   estimate of Sigma = square root of RSS divided by N

reals SigmaReducedNearLinearCase(Data& data, Circle& circle);

//****************** SigmaReducedForCenteredScaled ****************
//
//   estimate of Sigma = square root of RSS divided by N

reals SigmaReducedForCenteredScaled(Data& data, Circle& circle);


//****************** OptimalRadius ******************************
//
//     compute the optimal radius of a circle, given its center (a,b)

reals OptimalRadius(Data& data, Circle& circle);


#endif