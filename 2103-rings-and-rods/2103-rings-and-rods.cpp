class Solution {
public:
  int countPoints(string rings) {

    int rods[10] = {0};
    int len = rings.length();

    for(int i = 0; i < len; i += 2) {

      rods[rings[i + 1] - '0'] |= getColorCode(rings[i]);
    }

    int count = 0;
    for(int colorCodesSum : rods) 
      if(colorCodesSum == 7) ++count;
      
    return count;
  }

private:
  int getColorCode(char color) {

    int code = 0;

    switch(color)
    {
      case 'R':     code = 1; break;
      case 'G':     code = 2; break;
      default:      code = 4;
    }

    return code;
  }
};