#include<bits/stdc++.h>
using namespace std;
const int N = 1e7+10;
vector<bool> seive_array(N+1,true);
vector<int> spf(N+1, 0); // smallest prime factor
vector<int> sum_of_divisors(N+1,0);
vector <int> bpf(N+1,1);

// TC  = O(N log log N) its comes from harmonic series
//  also O(N log N) + number of primes up to N  = N/logN
// SC = O(N)
void sieve_of_erotothenus_basic(){
        seive_array[0] = seive_array[1]=false;
        for(int x = 2 ; x <= N ; x++){
                if(seive_array[x]){
                        for(int y = 2*x ; y <=N ; y+=x){
                                seive_array[y] = false;
                        }
                }
        }
}

// optmized version-1
// starting marking x^2 as false
void seive_v_1(){
        seive_array[0] = seive_array[1]=false;
        for(int x = 2 ; x*x <= N ; x++){
                if(seive_array[x]){
                        for(int y = x*x ; y <=N ; y+=x){
                                seive_array[y] = false;
                        }
                }
        }
}

// optmized version-2
// just go for x = 2 to sqrt(N)
void seive_v_2(){
        seive_array[0] = seive_array[1]=false;
        for(int x = 2 ; x *x <=N; x++){
                if(seive_array[x]){
                        for(int y = x*x ; y <=N ; y+=x){
                                seive_array[y] = false;
                        }
                }
        }
}

// optimized version-3
// skip even numbers
void seive_v_3(){
        seive_array[0] = seive_array[1]=false;
        for(int x = 4 ; x <= N ; x+=2){
                seive_array[x] = false;
        }
        for(int x = 3 ; x *x <=N; x+=2){
                if(seive_array[x]){
                        for(int y = x*x ; y <=N ; y+=x){
                                seive_array[y] = false;
                        }
                }
        }
}

// application : smallest prime factor of a number

void spf_of_numbers(){
        spf[0] = spf[1] = 0;
        for(int x = 2 ; x <= N ; x++){
                if(spf[x]!=0)continue; // not prime
                for(int y = 2*x ; y <=N ; y+=x){
                        if(spf[y]==0) spf[y] = x;
                }
        }
}

// application : prime factorization
vector<int> prime_factorization(int k){
        vector<int> pFactors;
        while(spf[k]!=0){
                pFactors.push_back(spf[k]);
                k = k/spf[k];
        }
        if(k>1)pFactors.push_back(k);
        return pFactors;
}

// some of divisors - factors
// TC = O(N log N)
// SC = O(N)
vector<int> sum_of_divisors_of_numbers(){
        for(int x = 1 ; x<=N ;x++){
                for(int y = x ; y <=N ; y+=x){
                        sum_of_divisors[y] += x;
                }
        }
        return sum_of_divisors;
}

// bigggest prime factor of a number
vector<int> bpf_of_numbers(){
        bpf[0] = bpf[1] = 1;
        for(int x = 2 ; x <= N ; x++){
                if(bpf[x]!=1)continue; // not prime
                for(int y = x ; y <=N ; y+=x){
                        bpf[y] = x;
                }
        }
        return bpf;
}


int main(){
        int n;
        cin >>n;
        // sieve_of_erotothenus_basic();
        // seive_v_1();
        // seive_v_2();
        // seive_v_3();
        
        // for(int i = 2 ; i <= n ; i++){
        //         if(seive_array[i]){
        //                 cout << i << " ";
        //         }
        // }

        // -------------

        // spf_of_numbers();
        // vector<int> factors = prime_factorization(n);
        // cout << "Prime factors of " << n << " are : ";
        // for(auto x : factors)cout << x << " ";

        // -------------

        // sum_of_divisors_of_numbers();
        // cout << "Sum of divisors of " << n << " is : " << sum_of_divisors[n] << "\n";

        bpf_of_numbers();
        cout << "Biggest prime factor of " << n << " is : " << bpf[n] << "\n";

        return 0;
}