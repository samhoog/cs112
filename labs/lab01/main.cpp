/* main.cpp tests the classes in our project.
* Sam Hoogewind (sth6)
* Date: February 9, 2021
* Begun by: Joel Adams, for CS 112 at Calvin University.
*/

int n = readInt(); 
int i,j,k;
for (i=0; i<n; i++) {
    for (j=0; j<3; j++)
        for (k=1; k < n*n; k *= 2)
            cout << "abra";
        for (j=0; j<5; j++)
            cout << “cadab”;
}
for (i=0; i<n; i++)
    cout << "dabra";