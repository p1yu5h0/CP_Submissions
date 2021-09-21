class Solution {
public:
    unordered_map<string,int> mp;
    bool isScramble(string a, string b){
        //memoized solution
        
        //base conditions
        if(a.size()!=b.size())
            return false;
        // if(a.size()==0 && b.size()==0)
        //     return false;
        if(a.compare(b)==0)
            return true;
        if(a.size()<=1 && b.size()>1)
            return false;

        //checking in map
        string temp = a;
        temp.push_back(' ');
        temp.append(b);
        if(mp.find(temp)!=mp.end())
            return mp[temp];
        
        //recursive code
        int n = a.size();
        bool flag = false;
        for(int i=1;i<=n-1;i++){
            if((isScramble(a.substr(0,i),b.substr(n-i,i))&&(isScramble(a.substr(i,n-i),b.substr(0,n-i))))||
                (isScramble(a.substr(0,i),b.substr(0,i))&&(isScramble(a.substr(i,n-i),b.substr(i,n-i))))){
                flag = true;
                break;
            }
        }
        
        //returning as well as storing in map
        return mp[temp] = flag;
        
    }
};
/*
- we are given 2 strings a and b
- we have to tell that these strings are scramble or not 
- here the meaning of scramble is slight different from the normal scramble 
- they have used a binary tree and are swapping the substrings of it 
- we can do zero or more swapping between the two branches and do the same change in the parent 
- eg.       great 
           /     \
          gr     eat 
         /  \    / \
        g   r   e   at
                   /  \
                  a    t
- in this exampl e we can make changes in gr ie. swap g and r and make them rg 
- and finaly make this change in the great 
- eg.       rgeat 
           /     \
          rg     eat 
         /  \    / \
        r   g   e   at
                   /  \
                  a    t
- hence we can say that great and rgeat are scramble strings of each other 
- we can have multiple scramble strings 
- like rgaet, great, rgeat, great, etc are all scrambled strings 
- now how is it a variation of MCM
- you know in MCM we break a string into two substrings and check them recursively 
- here also we are breaking this problem(string) into two subproblems(substrings), which then break into 2 more
- until the base condition is reached 
- also we dont know where to break, so we are breaking at every i and checking the possibility of scramble str.
- now while breaking we can observe 2 cases ie. one in which swap operation have occured and one in which not occured
- if any of these two conditions are true then the substring is scrambled with the one we compared with
- now lets see the base condition 
- the first one is length of the two strings 
- if the length of the two strings are different, then no matter how many swaps we do, string will not be scrambled
- if length of both the strings are zero then strings are equal and equal strings are always scrambled
- if both the strings are same then we have to stop and return true
- if at some point, length of string one is <=1 and length of string 2 is greater than one then we have to return f
- lets code memoized version
*/
