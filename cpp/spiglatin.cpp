

std::string pig_it(std::string str)
{
  int itr = str.size();
  int br, lng; //br = break = marks the end of a word, lng is the length of a word
  int st = 0;


  
 for (int i = 0; i < itr; i++ ){ //traverse through string
   
   //if(!((33<=words[i])||(words[i]<=64))){ //check if it is NOT a symbol, punctiation mark etc. using ascii
      if (str[i+1] == ' '){
      br = i; //marks the end of the current word
      lng = br-st; 
      std::string word;
      word = "";
      std::string ret;
      ret = "";
        
     
        
        for(int j = 0, j < lng; j++ ){
          if (lng == 0){
            ret.append(str[br]);
          }else{
            word.append(str[i+j+1]) //adds everything in order except for the first letter
          }
        }
        ret.append(word);
        ret.append(str[st]); //adds 1st letter to the end
        ret.append("ay ");
          
        st = i+2; // i=br + space + next letter
 
      
  
  return ret;
}