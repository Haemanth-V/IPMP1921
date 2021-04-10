//Question link: https://www.hackerrank.com/challenges/funny-string/problem

// Complete the funnyString function below.
string funnyString(string s) {
   int i=0, j=s.length()-1;
   while(i<j){
       if(abs(s[i]-s[i+1]) != abs(s[j]-s[j-1]))
          return "Not Funny";
        i++;
        j--;
   }
   return "Funny";
}
