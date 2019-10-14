#include <cstdio>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <vector>

using namespace std;

int prime_list[] = {2,3,5,7,11,13,17,19,23,29,31};

bool isPrime(int num){
	for(int i=0; i<11; ++i){
		if(num == prime_list[i]) return true;
		if(!(prime_list[i] < num)) return false;
	}
	return false;
}

int main(){
	int num = 0;
	int num_case = 0;
	while(scanf("%d", &num) != EOF){
		vector<int> range_num;
		for(int i=1; i<=num; ++i) range_num.push_back(i);	// generate vector
		//for(auto element : range_num) printf("%d ", element); // print			
		//printf("\n");
		// Generate Permutations
		int wasPrintedCase = 0;
		do {
			int ring_prime = 1;
			if(range_num[0] != 1) break;
			if(!isPrime(range_num[0]+range_num[range_num.size()-1])) continue;
			for(int i=0; i<range_num.size()-1; ++i){
				if(!isPrime(range_num[i]+range_num[i+1])){
					ring_prime = 0;
					break;
				}
			}
			//if(ring_prime) list_ring_prime.push_back(range_num);
			if(ring_prime){
				if(!wasPrintedCase){
					num_case++;
					printf("Case %d:\n",num_case);
					wasPrintedCase = 1;
				}
				for(int i=0; i<range_num.size(); ++i){
		  			if(i == range_num.size()-1) printf("%d", range_num[i]);
		  			else printf("%d ", range_num[i]);
	  			}
	  			printf("\n");
			}
	  	} while ( std::next_permutation(range_num.begin(),range_num.end()) );
	  	printf("\n");
	}
	// 
	
	return 0;
}