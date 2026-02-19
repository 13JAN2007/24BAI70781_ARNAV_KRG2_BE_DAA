int sum_of(long long n,int sum=0){
    int remainder=0;
    while(n>0){
    remainder = n%10;
    sum= sum+remainder;
    n= n/10;
    
    }
    if(sum/10 != 0) return sum_of(sum);  

return sum;           
    
}
int superDigit(string n, int k) {
    long long DigitSum = 0;
    for(auto c:n) DigitSum+=(c-'0');
    DigitSum*=k;

    return sum_of(DigitSum);
}