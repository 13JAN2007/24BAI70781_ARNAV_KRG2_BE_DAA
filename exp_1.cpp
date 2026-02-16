
#include <bits/stdc++.h>
using namespace std;
int maxdepth=0;
int operations=0;
void complexRec(int n,int currentdepth=0) {

    maxdepth=max(maxdepth,currentdepth);
   if (n <= 2) {
       return;
       operations++;
   }


   int p = n;
   while (p > 0) {
       operations++;
       vector<int> temp(n);
       for (int i = 0; i < n; i++) {
           temp[i] = i ^ p;
           operations++;
       }
       p >>= 1;
       //constant work is n*log(n)
   }


   vector<int> small(n);
   for (int i = 0; i < n; i++) {
       operations++;
       small[i] = i * i;
       //constant work is n
   }


   if (n % 3 == 0) {
       reverse(small.begin(), small.end());
       operations++;
       //constant work is n/2
   } else {
       reverse(small.begin(), small.end());
         operations++;
         //constant work is n/2
   }


   complexRec(n / 2, currentdepth + 1);
   complexRec(n / 2, currentdepth + 1);
   complexRec(n / 2, currentdepth + 1);
   //3 calls
   //therefore 3T(n/2)
   //total work done is nlog(n) + n + n/2 = O(nlogn) as n and n/2 will be neglected
   //recurrence relation will be T(n) = 3T(n/2) + O(nlogn)
   //using the formula T(n)=aT(n/2)+f(n)
   //a=3,b=2,f(n)=O(nlog(n))
   //this is case no 1
   //log(3)_2
   //from master theorm time complexity will be O(n^log3_2)=O(n*1.5) ****approx
}
int main() {
   int n = 16; 
   complexRec(n,0);
   cout << "Max Depth: " << maxdepth << endl;
   cout << "Total Operations: " << operations << endl;
   return 0;
}


