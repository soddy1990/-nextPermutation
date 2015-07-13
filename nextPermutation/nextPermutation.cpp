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

		bool desended = true;

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
				desended = false;
				i++;
			}
		}
		if(ascend == 0 && desend == 0){
			if(turn1 != 0){
				nums[ascend] += nums[ascend+1];
				nums[ascend+1] = nums[ascend] - nums[ascend+1];
				nums[ascend] = nums[ascend] - nums[ascend+1];
				sort(nums.begin() + ascend+1 , nums.end());
			}

		}else if(desended){
			sort(nums.begin(), nums.end());
		}else if(desend > ascend){
			int second_l = ascend+1;
			int j = ascend+1;
			for(; j<n; j++){
				if(nums[j] > nums[ascend] && nums[j] < nums[second_l]){
					second_l = j;
				}
			}

			nums[ascend] += nums[second_l];
			nums[second_l] = nums[ascend] - nums[second_l];
			nums[ascend] = nums[ascend] - nums[second_l];
			sort(nums.begin()+ascend+1, nums.end());
		}
		else{
			nums[ascend] += nums[ascend+1];
			nums[ascend+1] = nums[ascend] - nums[ascend+1];
			nums[ascend] = nums[ascend] - nums[ascend+1];
		}
	}
}

void main(){
	vector<int> source;
	int work = 5;
	source.push_back(work);
	work = 4;
	source.push_back(work);
	work = 7;
	source.push_back(work);
	work = 5;
	source.push_back(work);
	work = 3;
	source.push_back(work);
	work = 2;
	source.push_back(work);

	nextPermutation(source);

	for(int i = 0; i<source.size(); i++){
		cout<<source[i]<<"\t";
	}

	getchar();
}