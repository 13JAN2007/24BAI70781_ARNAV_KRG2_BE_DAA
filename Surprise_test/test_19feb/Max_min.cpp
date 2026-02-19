int maxMin(int k, vector<int> arr) {
   sort(arr.begin(),arr.end());
   auto it1 = arr.begin();
   auto it2 = it1+k-1;
   int diff = *it2-*it1;
   for(int x =0;x<arr.size()-k+1;x++){
       int d = *it2-*it1;
       if(diff>d){
           swap(diff,d);
           
       }
       it1++;
       it2++;
   }
    return diff;
}