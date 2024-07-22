#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N = 1e6+5;
const ld pi = acos(-1);
/***********************************Geometry******************************************/
#define point complex<ld>
//vectors
ld dot(point &z1 , point &z2)
{
    return (conj(z1)*z2).real();
}
//can be used to determine where the point lies w.r.t a line
//determined according to the sign of the cross product
ld cross(point z1 , point z2)
{
    return (conj(z1)*z2).imag();
}
//rotates point around another point with (rad) angle in anti-clockwise direction
point rotate_by(point &p , point about , ld rad)
{
    return (p - about)*exp(point(0,rad))+about;
}
//reflects point p around line defined by 2 points (about1 and about2)
point reflect(point &p, point about1, point about2)
{
    point z = p - about1;
    point w = about2 - about1;
    return conj(z / w) * w + about1;
}
//returns point of intersection between 2 lines
//if there is no intersection -> infinity
point intersect(point a,  point b,  point p, point q)
{
    ld d1 = cross(p - a, b - a);
    ld d2 = cross(q - a, b - a);
    return (d1 * q - d2 * p) / (d1 - d2);
}

////////////////////////////////////////////Circles////////////////////////////////////
struct circle{
    ld x,y,r;
};
//returns intersection area between 2 circles
ld intersection(circle c1, circle c2)
{
    ld dx = c1.x - c2.x;
    ld dy = c2.y - c1.y;
    if(!dx and !dy) //circles are concentric
    {
        if(c1.r == c2.r)
            return pi*c1.r*c1.r;
        else if(c1.r > c2.r)
            return pi*c2.r*c2.r;
        else
            return pi*c1.r*c1.r;
    }
    ld d = sqrtl(dx*dx + dy*dy);
    if(d >= c1.r + c2.r)
        return 0.f;
    else if(d + c2.r <= c1.r)
        return pi*c2.r*c2.r;
    else if(d + c1.r <= c2.r)
        return pi*c1.r*c1.r;
    else
    {
        ld costheta = (c2.r*c2.r + d*d - c1.r*c1.r)/(2.0*c2.r*d);
        ld theta = acosl(costheta);
        ld a1 = -c2.r*c2.r*sinl(theta)*cosl(theta) + theta*c2.r*c2.r;
        costheta = (c1.r*c1.r + d*d - c2.r*c2.r)/(2.0*c1.r*d);
        theta = acosl(costheta);
        ld a2 = -c1.r*c1.r*sinl(theta)*cosl(theta) + theta*c1.r*c1.r;
        return a1+a2;
    }
}

void solve()
{
    point z1 = {2,1},z2 = {5,3};
    cout << dot(z1,z2) << "\n" << cross(z1,z2) << "\n";
    cout << abs(z1) << '\n' << norm(z1) << "\n"; // abs gets magnitude while norm gets magnitude squared
    z1 = rotate_by(z1,{0,0},pi/2);
    cout << z1 << '\n';
    z2 = reflect(z2,{1,1},{2,2});//across the line y = x (inverse :) )
    cout << z2 << '\n';
    cout << intersect({0,0},{-1,1},{0,3},{-3/5.0,0}) << '\n';
    cout << intersect({0,0},{1,1},{0,6},{-6,0}) << '\n';
}

int lattice(int x1 , int y1 , int x2 , int y2)
{
    return __gcd(abs(x1-x2),abs(y1-y2))-1;
}

/*
Notes:
-Measure of an angle of a uniform polygon
(n-2)*180/n (where n is the number of sides)
-Area of circular segment
0.5*r^2*(theta(rad) - sin(theta))
-DON'T FORGET applications on maxima and minima
-DON'T FORGET similarity , ratios , etc..
-Area of parallelogram formed by two vectors A & B = AxB
-Area of triangle formed by two vectors A & B = AxB/2
-perpendicular distance from point (x1,y1) to line AX + BY + C = 0
= abs(Ax1 + By1 + c)/sqrt(A^2 + B^2)
or given point p and direction vector d and point A on the line
= norm(APxd)/norm(d)
*/
