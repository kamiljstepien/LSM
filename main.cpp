#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inc/GBM.h"
#include "inc/Random.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    srand(time(NULL));
    Gaussian* gauss  = new GaussianBoxMuller();
    return 0;
}
