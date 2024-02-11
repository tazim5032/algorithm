//https://www.careercup.com/question?id=5740719907012608
int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B) {

    int n=A.size();

    int total_gas=0,total_cost=0;

    int curr_gas=0,s=0;

    for(int i=0;i<n;i++){

        total_gas+=A[i];

        total_cost+=B[i];

        curr_gas+=A[i]-B[i];

        if(curr_gas<0){

            s=i+1;

            curr_gas=0;
        }
    }

    if(total_gas<total_cost)return -1;
    else return s;
}


