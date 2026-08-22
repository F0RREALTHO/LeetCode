class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        int cnt = 0;
        while(num>=1000 && cnt!=3){
            ans+="M";cnt++; num-=1000;
        }
        cnt=0;
        if(num>=900){
            ans+="CM";
            num-=900;
        }
        if(num>=500){
            ans+="D";num-=500;
        }
        if(num>=400){
            ans+="CD"; num-=400;
        }
        while(num>=100 && cnt!=3){
            ans+="C";cnt++;num-=100;
        }
        cnt=0;
        if(num>=90){
            ans+="XC";num-=90;
        }
        if(num>=50){
            ans+="L";num-=50;
        }
        if(num>=40){
            ans+="XL"; num-=40;
        }
        while(num>=10 && cnt!=3){
            ans+="X";cnt++;num-=10;
        }
        if(num>=9){
            ans+="IX";num-=9;
        }
        if(num>=5){
            ans+="V";num-=5;
        }
        if(num>=4){
            ans+="IV";num-=4;
        }
        while(num>=1){
            ans+="I"; num-=1;
        }
        return ans;
    }
};