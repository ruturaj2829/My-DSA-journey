int secondSmallest(  int n,vector<int>&a ){

    int smallest =a[0];

    int ssmallest = INT_MAX;

    for( int i=1;i<n;i++){

        if(a[i]<smallest){

            ssmallest = smallest;

            smallest = a[i];

        }

        else if( a[i]!=smallest && a[i]<ssmallest){

            ssmallest = a[i];

        }

    }

    return ssmallest;

}

 
int sec(int n, vector<int>& a){
  int p=-1;
   
   
    int max=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]>max)
        {   
            p=max;
            max = a[i];

        } else if (a[i] < max && a[i] > p) {
            p = a[i];
        }
    }

    return p;
    }
vector<int> getSecondOrderElements(int n, vector<int> a) {
    int slargest = sec(n,a);

    int ssmallest = secondSmallest(n,a);

    return {slargest,ssmallest};
}
