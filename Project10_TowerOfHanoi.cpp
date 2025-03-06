// We start with n rings on tower A and we need to transfer them to tower B without using recursion.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> t[3];
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    cout << endl;

    // closerTower and fartherTower is a way to bypass the odd vs even number of disk issue
    // used conditional statement using ? : 
    int closerTower = (n % 2 == 0 ? 2 : 1);
    int fartherTower = (n % 2 == 0 ? 1 : 2);
    int from = 0, to = closerTower, candidate = 1, move = 0;
   

    // Initialize the towers
    for(int i = n + 1; i >= 1; --i)
        t[0].push_back(i);
        t[1].push_back(n+1);
        t[2].push_back(n+1);
    
    //using while loop until we find the solution
    while (t[1].size() < n+1) { 
        cout << "Move #" << ++move << " : Move disk " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;

        // Moving the disk.
        t[to].push_back(t[from].back()); 
        t[from].pop_back();

         // Determining the "from" tower
        if (t[(to+1) % 3].back() < t[(to+2) % 3].back()){  // mod 3 in case the from/to goes more than 3
            from = (to+1) % 3;
        }
        else{
            from = (to+2) % 3;
            candidate = t[from].back(); 
        }                     
        
        // Determining the "to" tower.
        if (t[(from+closerTower) % 3].back() > candidate){  // mod 3 in case the from/to goes more than 3
            to = (from+closerTower) % 3;
        }                  
        else{
            to = (from+fartherTower) % 3;
        }
    }

    return 0;
}
