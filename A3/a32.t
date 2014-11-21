#ifndef PARAMETER_T
#define PARAMETER_T
template<typename t>
string getType(T s){
  return "not saved";
}
template<>
string getType<float>(float s){
  return "float";
}
template<>
string getType<int>(int s){
  return "Integer";
}
template<>
string getType<bool>(bool s){
return "boolean";
  
}
template<>
string getType<char>(char s){
  return"char";
}

#endif