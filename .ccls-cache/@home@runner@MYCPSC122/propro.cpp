#include <iostream>
#include <fstream>
#include <string>
void selectionSort(std::vector<std::string>&arr){
  int n =arr.size();
for(int i=0;i<n-1;i++){
  int min_idx=i;
  for(int j=i+1;j<n;j++){
    if(arr[j]<arr[min_idx]){
      if(min_idx!=i)
  