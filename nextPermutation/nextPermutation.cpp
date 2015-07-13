#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void nextPermutation(vector<int>& nums) {
	int n = nums.size();
	if(n >= 2){
		int ascend = 0;
		int desend = 0;
		int turn1 = -1;
		int turn2 = -1;

		int last = nums[0];
		turn1 = 0;

		int i = 1;
		while(i<n){
			if(nums[i] == last){
				turn2 = i;
				i++;
			}else if(nums[i] < last){
				turn1 = i - 1;
				desend = i;
				last = nums[i];
				i++;
			}else{
				turn1 = i;
				ascend = i - 1;
				last = nums[i];
				i++;
			}
		}
		if(ascend == 0 && desend == 0){
		}else if(ascend == 0){
			sort(nums.begin(), nums.end());
		}
		else if(desend < ascend){
			nums[ascend] += nums[ascend+1];
			nums[ascend+1] = nums[ascend] - nums[ascend+1];
			nums[ascend] = nums[ascend] - nums[ascend+1];
		}
		else{
			nums[ascend] += nums[ascend+1];
			nums[ascend+1] = nums[ascend] - nums[ascend+1];
			nums[ascend] = nums[ascend] - nums[ascend+1];
			sort(nums.begin() + ascend+1 , nums.end());
		}
	}
}

void main(){
	vector<int> source;
	int work = 1;
	source.push_back(work);
	work = 1;
	source.push_back(work);
	work = 5;
	source.push_back(work);

	nextPermutation(source);

	for(int i = 0; i<source.size(); i++){
		cout<<source[i]<<"\t";
	}

	getchar();
}