class Solution {
public:
    double myPow(double x, long long int n) {

        if(n < 0)
        {
            x = 1.0 / x;
            n = -1 * n;
        }
        
        if(n == 0 || x == 1.0)
            return 1.0;
        
        if(n == 1)
            return x;
        
        else if(n % 2 == 0)
        {
            return myPow(x*x, n/2);
        }
        else
        {
            return myPow(x*x, (n-1)/2) * x;
        }

        return 0;

    }
};










/*
double myPow(double x, int n) {
    if (n == 0) {
        return 1.0;
    }

    double temp = myPow(x, n / 2);

    if (n % 2 == 0) {
        return temp * temp;
    } else {
        if (n > 0) {
            return x * temp * temp;
        } else {
            return (temp * temp) / x;
        }
    }
}
*/